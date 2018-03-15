#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <poll.h>
#include <stdio.h>

#define null NULL
#define BUFFER_SIZE 1024
#define TIMEOUT 5

typedef struct timeval timeval_t;
typedef struct pollfd pollfd_t;

void using_select(const char*);
void using_poll(const char*);

void read_nothing(char* buffer, const char* id) ;
void read_success(char* buffer, const char* id) ;

int main(int argc, char** argv)
{

    if (argc < 3) {
        printf("You should pass 2 arguments here { select|poll identifier }\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp("poll", argv[1]) == 0)
        using_poll(argv[2]);
    else if (strcmp("select", argv[1]) == 0)
        using_select(argv[2]);
    else {
        printf("You passed wrong first argument.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void using_select(const char* id)
{

    fd_set readfds;
    timeval_t tv;

    while (true) {

        char buf[BUFFER_SIZE];

        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);

        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        printf("Enter command:\n>>");
        fflush(stdout);

        int status = select(STDIN_FILENO + 1, &readfds, null, null, &tv);

        if (status == -1) {
            perror("\nError in select() ");
            exit(EXIT_FAILURE);
        } else if (status == 0) {
            read_nothing(buf, id);
        } else {
            read_success(buf, id);
            break;
        }
    }
}

void using_poll(const char* id) {

    pollfd_t mypoll = { STDIN_FILENO, POLLIN|POLLPRI|POLLERR };

    while (true) {
        char buf[BUFFER_SIZE];

        printf("Enter command:\n>>");
        fflush(stdout);

        int status = poll(&mypoll, 1, TIMEOUT * 1000);

        if (status < 0) {
            perror("\nError in poll() ");
            exit(EXIT_FAILURE);
        } else if (status == 0) {
            read_nothing(buf, id);
        } else {
            read_success(buf, id);
            break;
        }
    }
}

void read_nothing(char* buffer, const char* id) {
    sprintf(buffer, "\nError: %d seconds ends for identifier - %s . Try again.\nPress ENTER to continue.", TIMEOUT, id);
    write(STDERR_FILENO, buffer, strlen(buffer));
    getchar();
}

void read_success(char* buffer, const char* id) {
    ssize_t num_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    buffer[num_bytes] = '\0';

    if (num_bytes < 0) {
        perror("Error on read");
        exit(EXIT_FAILURE);
    }

    printf("\nRead %d bytes for identifier: %s\nText: %s", (int) num_bytes, id, buffer);
}
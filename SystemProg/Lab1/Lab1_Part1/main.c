#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <fcntl.h>
#include <sys/stat.h>

#define error (-1)
#define BUFFER_SIZE 512

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("You should pass 2 arguments here!\n");
        return EXIT_FAILURE;
    }

    const int offset = 'A'-'a';

    int file_to_read_desc = open(argv[1], O_RDONLY, S_IREAD);
    int file_to_write_desc = open(argv[2], O_WRONLY|O_TRUNC, S_IWRITE);

    if (file_to_read_desc == error) {
        perror("Open failed while opening argv[1] file");
        return EXIT_FAILURE;
    }

    if (file_to_write_desc == error) {
        perror("Open failed while opening argv[2] file");
        return EXIT_FAILURE;
    }


    char buffer[BUFFER_SIZE+1];
    ssize_t num;

    while (0 != (num = read(file_to_read_desc, buffer, BUFFER_SIZE))) {

        register int override = 0;


        buffer[num * sizeof(char)] = '\0';

        for (register int i = 0; i < strlen(buffer); ++i) {
            if ('a' <= buffer[i] && buffer[i] <= 'z') {
                ++override;
                buffer[i] += offset;
            }
        }

        printf("%d bytes were overrode.\n", override);

        if (write(file_to_write_desc, buffer, (size_t)num) == -1) {
            perror("Error while writing in file");
            exit(EXIT_FAILURE);
        }
    }

    if (close(file_to_read_desc) == error) {
        perror("Error while closing file toread");
        exit(EXIT_FAILURE);
    }
    if (close(file_to_write_desc) == error) {
        perror("Error while closing file towrite");
        exit(EXIT_FAILURE);
    }

    printf("Program ends.\n");
    return 0;
}
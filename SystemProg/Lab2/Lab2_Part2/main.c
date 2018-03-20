#include <stdio.h>
#include "logger.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>

#define LOG_FILE "../program.log"

int main() {
    int filedes = open(LOG_FILE, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC);
    int fdnull;
    LOG(filedes, INFO, "Program started");
    char msg[2048];
    pid_t pid, newSid;

    switch (pid = fork()) {
        case -1:
            LOG(filedes, ERROR, "Error while fork()");
            exit(EXIT_FAILURE);
        case 0: //CHILD
            newSid = setsid();
            sprintf(msg, "CHILD: I was born! New session ID: %d", newSid);
            LOG(filedes, WARNING, msg);
            if (-1 == chdir("/")) {
                LOG(filedes, ERROR, "CHILD: ERROR while changing working directory");
                exit(EXIT_FAILURE);
            }
            LOG(filedes, INFO, "CHILD: I've changed working directory to \"/\" ");
            LOG(filedes, WARNING, "CHILD: Closing all parent descriptors...");
            close(filedes);

            filedes = open(LOG_FILE, O_WRONLY | O_APPEND);

            close(STDIN_FILENO);
            close(STDOUT_FILENO);
            close(STDERR_FILENO);
            open("/dev/null",O_RDONLY);
            open("/dev/null",O_WRONLY);
            open("/dev/null",O_RDWR);

            LOG(filedes, WARNING, "CHILD-DEAMON: All descriptors redirected to /dev/null ");

            sprintf(msg, "CHILD-DEAMON: PID: %d, GID: %d, SID: %d", getpid(), getgid(), getsid(0));

            LOG(filedes, INFO, msg);

            while (true) {
                sleep(1000);
                time_t t = time(null);
                struct tm tm = *localtime(&t);
                printf("%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            }

        default: //PARENT
            sprintf(msg, "PARENT: Child was born by me with PID: %d", pid);
            LOG(filedes, WARNING,msg);
            LOG(filedes, INFO, "PARENT: Parent is done.");
            exit(EXIT_SUCCESS);
    }

    return 0;
}



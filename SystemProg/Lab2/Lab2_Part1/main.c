#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main() {
    pid_t pid;
    int rv, status;
    switch(pid=fork()) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            printf("\tCHILD: I'm child!\n");
            printf("\tCHILD: My PID  -- %d\n", getpid());
            printf("\tCHILD: My PPID -- %d\n", getppid());
            printf("\tCHILD: My GID: -- %d\n", getgid());
            printf("\tCHILD: My UID: -- %d\n", getuid());
            printf("\tCHILD: My SID: -- %d\n", getsid(0));
            printf("\tCHILD: Input any exit code for me:");
            scanf("%d", &rv);
            printf("\tCHILD: I'm done for now!\n");
            exit(rv);
        default:
            printf("PARENT: I'm parent!\n");
            printf("PARENT: My PID -- %d\n", getpid());
            printf("PARENT: My PPID -- %d\n", getppid());
            printf("PARENT: PID of my CHILD -- %d\n", pid);
            printf("PARENT: My GID: -- %d\n", getgid());
            printf("PARENT: My UID: -- %d\n", getuid());
            printf("PARENT: My SID: -- %d\n", getsid(0));
            printf("PARENT: Wait on exit() in CHILD process...\n");
            wait(&status);
            printf("PARENT: Exit code of my CHILD:%d\n",
                   WEXITSTATUS(status));
            printf("PARENT: EXIT!\n");
    }
    return 0;
}
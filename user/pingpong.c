#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/**
 * @className  pingpong
 * @author  SoraNimi
 * @date 2022/3/9 12:12 AM
 * @version 1.0
 */

int main(int argc, char *argv[]) {
    int pid;
    int fd0[2];
    int fd1[2];
    char *byte = "p";
    if (pipe(fd0) == -1) {
        fprintf(2, "create pipe error");
    }

    if (pipe(fd1) == -1) {
        fprintf(2, "create pipe error");
    }

    pid = fork();
    if (pid < 0) {
        fprintf(2, "fork error");
        // fd[0] → r； fd[1] → w
    } else if (pid == 0) {
        // child process
        close(fd0[1]);
        close(fd1[0]);
        if (read(fd0[0], byte, 1) != 1) {
            fprintf(2, "read error\n");
        }
        fprintf(1, "%d: received ping\n", getpid());
        if (write(fd1[1], byte, 1) != 1) {
            fprintf(2, "write error\n");
        }
        exit(0);
    } else {
        // parent process
        close(fd0[0]);
        close(fd1[1]);
        if (write(fd0[1], byte, 1) != 1) {
            fprintf(2, "write error\n");
        }
        if (read(fd1[0], byte, 1) != 1) {
            fprintf(2, "read error\n");
        }
        fprintf(1, "%d: received pong\n", getpid());
        exit(0);
    }
    exit(0);
}

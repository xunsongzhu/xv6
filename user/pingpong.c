#include<user/ulib.c>
#include<user/printf.c>
#include<user/umalloc.c>
#include <sys/types.h>

/**
 * @className  pingpong 
 * @author  SoraNimi
 * @date 2022/3/9 12:12 AM 
 * @version 1.0
 */

int main(int argc, char *argv[]) {
  pid_t pid;
  int fd0[2];
  int fd1[2];
  char *byte = 'p';
  if (pipe(fd0[2]) == -1) {
	fprintf(2, "create pipe error");
  }

  if (pipe(fd1[2]) == -1) {
	fprintf(2, "create pipe error");
  }



  pid = fork();
  if (pid < 0) {
	fprintf(2, "fork error");
	// fd[0] → r； fd[1] → w
	// child process
  } else if (pid == 0) {
	close(fd0[1]);
	close(fd1[0]);
	read(fd0[0], byte, 1);
	fprintf(1, "%d: received ping\n", getpid());
	write(fd1[1], byte, 1);
	exit(0);
  } else {
	// parent process
	close(fd0[0]);
	close(fd1[1]);
	write(fd0[1], byte, 1);
	read(fd1[0], byte, 1);
	fprintf(1, "%d: received pong\n", getpid());
	exit(0);
  }
}
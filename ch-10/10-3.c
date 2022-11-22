#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


//부모 자식 누가 빠르냐 누가 늦냐는 문제가 되지 않음
//채워지면 알아서 쓴다가 개념인듯?

int main() {
    int fd[2];
    pid_t pid;
    char buf[257];
    int len, status;

    if (pipe(fd) == -1) {
	perror("pipe");
	exit(1);
    }

    switch (pid = fork()) {
	case -1 :
	    perror("fork");
	    exit(1);
	    break;
	case 0 : 
	    close(fd[1]);
	    write(1,"child process:",15);
	    len = read(fd[0], buf, 256);
	    write(1, buf, len);
	    close(fd[0]);
	    break;
	default :
	    close(fd[0]);
	    write(fd[1], "Test Message\n",14);
	    close(fd[1]);
	    waitpid(pid,&status, 0);
	    break;
    }
}


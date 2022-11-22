#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    //FILE* fp;
    char buf[256];
    pid_t pid;
    //fp = popen("date","r"); // process <---- date 
    int fd[2];
    int len, status;
    
    if (pipe(fd) == -1) {
	perror("pipe");
	exit(1);
    }

    if ((pid = fork()) == -1) {
	perror("fork");
	exit(1);
    }

    if (pid == 0) {
	close(fd[0]); //자식은 파이프에 쓰는 역할
        dup2(fd[1],1);	
	execlp("date","date",(char *) NULL);

    }

    else {
	close(fd[1]); //부모는 파이프에서 읽어올것 
	len = read(fd[0], buf, 256);
	write(1, buf, len);
	close(fd[0]);
    }
}

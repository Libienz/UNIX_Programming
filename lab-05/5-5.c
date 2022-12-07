#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int pd[2];
    pid_t pid;
    char str[] = "parent sends Pipe test";
    char buf[BUFSIZ]; //stdio에 BUFSIZ정의되어 있음
    int len, status;

    //파이프 생성
    if (pipe(pd) == -1) {
	perror("pipe");
	exit(1);
    }


    switch (pid = fork()) {
	case -1: //fork failed
	    perror("fork");
	    exit(1);
	    break;

	case 0: //child proc
	   
	    close(pd[1]);//자식 프로세스에서 파이프를 읽기용으로 사용

	    //파이프에서 read하기
	    //pd[0]로 부터 읽는다. 
	    len = read(pd[0], buf, BUFSIZ);
	    if (len ==-1) {
		perror("Read");
		exit(1);
	    }
	    //파이프에서 읽은 내용 출력
	    printf("%d reads %s from the pipe.\n", (int)getpid(), buf);
	    close(pd[0]);
	    break;

	default: //parent proc

	    close(pd[0]);//부모 프로세스에서 파이프를 쓰기용으로 사용
	    //파이프에 write하기
	    //pd[1]에 쓴다.
	    if (write(pd[1], str, strlen(str)) != strlen(str)) {
		perror("write");
		exit(1);
	    }
	    close(pd[1]);
	    printf("%d writes %s to the pipe.\n", (int)getpid(), str);
	    waitpid(pid, &status, 0);
	    break;
    }
}







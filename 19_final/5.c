#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

    //파이프 파일의 읽기 전용 기술자와 쓰기 전용 기술자를 담을 fd 배열
    int fd[2];
    pid_t pid;

    //pipe실행 읽기 전용으로 연 기술자를 fd[0]에, 쓰기 전용으로 연 기술자를 fd[1]에 저장
    if (pipe(fd) == -1) {
	perror("pipe");
	exit(1);
    }


    switch (pid = fork()) {
	case -1: //fork error
	    perror("fork");
	    exit(1);
	    break;
	case 0: //child proc
	    close(0); //stdin 닫는다. 
	    dup(fd[0]); //redirection: 파이프의 읽기 파일이 표준 입력의 역할을 한다
	    close(fd[1]); //파이프의 쓰기 기술자를 닫는다. 자식은 읽는다. 
	    execlp("grep","grep","c", (char *) NULL); //grep c 실행
	    exit(1); //종료
	    break;
	default: //parent proc
	    close(1); //stdout 닫는다.
	    dup(fd[1]); //파이프의 쓰기 기술자가 표준 출력의 역할을 한다.
	    close(fd[0]); // 파이프의 읽기 기술자를 닫는다. 부모는 파이프에 쓴다.
	    execlp("ls","ls","-l",(char *) NULL); //ls -l 수행, 표준 출력에 출력하겠지만 여기선 파이프로 들어간다. 
	    wait(NULL);
	    break;
    }

    return 0;
}


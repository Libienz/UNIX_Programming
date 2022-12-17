#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    
    int fd[2]; //파이프의 기술자 두개를 담을 정수형 배열
    pid_t pid;

    //pipe() 실행 
    //pipe에 대한 읽기 전용 기술자와 쓰기 전용 기술자가 배열에 들어간다.
    //오류면 perror
    if (pipe(fd) == -1) {
	perror("pipe");
	exit(1);
    }

    //fork를 통해 만들어진 자식은 부모의 메모리를 상속함으로 미리 만들어진 파이프 기술자를 공유한다.
    //후에 파이프 기술자중 부모와 자식이 각각 읽고 쓰는 부분을 하나씩 닫아 단방향 파이프 완성
    //부모 자식 프로세스간 통신을 가능하게 한다. 이름없는 파이프
    switch (pid = fork()) {
	case -1: 
	    perror("fork");
	    exit(1);
	    break;
	case 0:
	    close(fd[0]); //파이프의 읽기 기술자 닫기 (단방향 파이프)
	    
	    //자식의 출력이 pipe파일의 쓰는 부분으로 입출력 전환이 되어 있지 않다면 전환한다. 
	    //자식은 앞으로 기술자 1에다가 출력하면 파이프 파일에 쓰게 된다.
	    if (fd[1] != 1) { 
		dup2(fd[1], 1);
		close(fd[1]);
	    }

	    //ls -a 실행: 출력은 파이프 파일에다가 써질 것을 알 수 있음
	    execlp("ls", "ls", "-a", (char *) NULL);
	    exit(1);
	    break;
	default:
	    close(fd[1]); //파이프의 쓰기 기술자 닫기 (단방향 파이프)
	    
	    //부모의 입력이 파이프 파일의 읽는 기술자로 전환되어 있지 않다면 전환한다.
	    //부모는 앞으로 0번 기술자로 부터 읽는 것을 파이프로 부터 읽어온다.
	    if (fd[0] != 0) {
		dup2(fd[0], 0);
		close(fd[0]);
	    }

	    wait(NULL);
	    //grep c 실행: 파이프 파일에서 읽어온 것을 grep c 한다
	    execlp("grep", "grep", "c", (char *) NULL);
	    break;
    }

}



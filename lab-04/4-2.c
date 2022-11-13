#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define FORKNUM 3

int main(void) {

    pid_t pid;

    for (int i = 0; i<FORKNUM; i++) {
	if ((pid = fork()) < 0) { //fork 에러
	    perror("fork");
	    exit(1);
	 }

	if (pid > 0 ) { //부모 프로세스: fork의 반환 값 자식 프로세스의 PID
	    sleep(2);
	}
	
	else { //자식 프로세스: fork의 반환 값 0
	    printf("my pid is %d and ppid is %d\n",(int)getpid(), (int)getppid());
	    exit(0); //이게 없으면 자식 프로세스도 for 문 반복하게 되더라
	}
    }

    return 0;
}



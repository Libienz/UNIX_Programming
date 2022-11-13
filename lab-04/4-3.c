#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
    
    pid_t pid;
    char *a[3];

    if ((pid=fork())<0) { //fork error
	perror("fork");
	exit(1);
    }
    if(pid>0) { //부모: fork의 반환 값 자식의 PID
	printf("Parent %d executes.\n", (int)getpid());
    }
    else {
	printf("Child %d executes.\n",(int)getpid());
	a[0] = "ls";
	a[1] = "-a";
	a[2] = NULL;
	//exec 함수군은 다른 프로그램으로 메모리를 덮어쓴다!
	//이제 child는 새로 덮어쓴 프로그램을 실행

	if(execv("/bin/ls",a) == -1) { //bin/ls 경로의 파일 실행하며 a를 인자로 전달!
	    perror("exec");
	    exit(2);
	}
    }

    return 0;
}


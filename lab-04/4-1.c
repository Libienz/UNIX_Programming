#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;

    printf("Before fork ...\n");

    if ((pid = fork()) < 0) { //fork 에러
	perror("fork");
	exit(1);
    }

    if (pid > 0) { //부모: fork의 반환값은 자식 프로세스의 pid
	//sleep 함수를 통해서 자식이 실행될 동안 부모가 일정시간 멈춰 있을 수 있도록 한다. (getppid를 실행할 때 다른 것으로 찍히지 않기 위해서) 
	sleep(2);
	printf("Parent process has pid = %d ppid = %d\n",(int)getpid(), (int) getppid());
    }
    else //자식: for의 반환값은 0
	printf("Child process has pid = %d ppid = %d\n", (int)getpid(), (int)getppid());
    
    return 0;
}

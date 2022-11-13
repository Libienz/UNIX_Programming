#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (void) {
    
    pid_t pid;
    int i, status;

    if((pid = fork()) < 0) { //fork error
	perror("fork");
	exit(1);
    }
    
    if (pid > 0) { //부모
	printf("Parent %d waits child %d\n",(int)getpid(), (int)pid);
	wait(&status);//자식 프로세스가 종료할 때까지 부모 기다림
	//자식 프로세스가 종료하면 status에 자식의 종료 상태 저장
	printf("Child's exit status = %x\n",status);
	printf("Child's exit status = %d\n",status>>8);
    }
    else { //자식 
	for (i=0; i<5; i++) {
	    printf("Child %d executes.\n",(int)getpid());
	    sleep(1);
	}
	exit(3);
    }

    return 0;
}





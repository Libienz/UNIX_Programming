#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int main(void) {
    pid_t pid;
    char *a[3];
    int status;

    if ((pid = fork()) < 0) { //fork error
	perror("fork");
	exit(1);
    }

    if (pid > 0) { // parent process
	printf("Parent %d is waiting for child process's exiting.\n", (int)getpid());
	wait(&status); //자식이 종료할 때까지 기다린다.
    }
    else { //child process
	printf("Child %d executes.\n", (int)getpid());
	a[0] = "ls"; 
	a[1] = "-a";
	a[2] = NULL;
	if (execv("/bin/ls", a) == -1) { //자식 프로세스를 새로운 프로세스로 덮어씌운다. ls -a
	    perror("exec");
	    exit(2);
	}
    }
    printf("Child gave exit status %d to parent.\n", status >> 8); // 부모 프로세스가 자식프로세스의 종료 상태를 확인한다. 
    //8만큼 shift 해야 원래대로 받아올 수 있음 

    return 0;
}


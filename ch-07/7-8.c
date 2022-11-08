#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {

    int status=0;
    pid_t pid;

    switch(pid = fork()) {

	case -1: //fail to fork
	    perror("fork");
	    exit(1);
	    break;

	case 0: //child
	    printf("-->child process\n");
	    exit(2);
	    break;
	default: //parent process
	    printf("status: %d, %x\n",status, status);
	    printf("child process exit status: %d\n", status >> 8);
	    break;
    }
}


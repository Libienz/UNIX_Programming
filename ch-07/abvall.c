#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE  4096 //... 좀 그러네

int main(void) {

    char buf[BUFSIZE];
    pid_t pid;
    FILE* wfp;
    int rfd;
    int n;
    int ch;
    int wstatus;
    

    if ((pid=fork()) < 0) {
	perror("fork");
	exit(1);
    }


    
    if (pid == 0) { //자식 프로세스
        wfp = fopen("data.txt", "w");
	while((ch=getchar())!= EOF) {
	    putc(ch,wfp);
	}
	fclose(wfp);
	exit(1);
    }


    else { //부모 프로세스
	rfd = open("data.txt", O_RDONLY);
	wait(&wstatus);
	while ((n = read(rfd, buf, BUFSIZE-1)) > 0) {

	    if (write(1, buf,BUFSIZE) != n) perror("Write");
	}
	close(rfd);
    }

}
	


	    
	


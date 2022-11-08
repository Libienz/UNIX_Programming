#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE  4096 

int main(void) {

    char buf[BUFSIZE]; //read할때 사용될 버퍼
    pid_t pid;
    FILE* wfp;
    int rfd; 
    int n; //저수준에서 읽은 바이트수를 담을 변수
    int ch;//getchar로 담아온 char 담을 변수 
    int wstatus;
    

    if ((pid=fork()) < 0) { // fork 에러 
	perror("fork");
	exit(1);
    }


    
    else if (pid == 0) { //자식 프로세스
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
	    buf[BUFSIZE] = '\0';
	    printf("%s",buf);

	   //if (write(1, buf,BUFSIZE) != n) perror("Write");
	}
	close(rfd);
    }

}
	


	    
	


#include <sys/types.h>
#include <signal.h>
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


    /*
       부모 프로세스
       stdin 에서 읽어와 4-6.txt에 쓴다
    */
    if (pid > 0) { //부모

        wfp = fopen("4-6.txt", "w");
	
	if (wfp == NULL) { //fopen 오류
	    perror("fopen: 4-6.txt");
	    exit(1);
	}
	//EOF 마주치기 전까지 getchar 이용 -> stdin으로 부터 읽어옴
	printf("입력 시작\n");
	while((ch=getchar())!= EOF) { 
	    putc(ch,wfp); //읽어온 것을 wfp에 쓴다 (4-6.txt)
	}
	fclose(wfp);
	kill(pid,SIGCONT); //자식에게 시그널 보낸다. 자식은 중지 중
	wait(&wstatus); //부모는 일을 마쳤지만 좀비와 고아 발생 방지를 위해 wait	
    }
    /* 
       자식 프로세스
       4-6.txt에서 읽어와
       stdout에 쓴다
    */

    else { //자식 프로세스

	raise(SIGSTOP); //중지 시그널: SIGCONT 받을 때 까지 일시중지

	//부모로 부터 신호 받고 재개

	rfd = open("4-6.txt", O_RDONLY); 
	if (rfd == -1) { //open error
	    perror("open 4-6.txt");
	    exit(1);
	}

	printf("읽어와서 출력 시작\n");

	while ((n = read(rfd, buf, BUFSIZE-1)) > 0) { //읽어오고
	    buf[BUFSIZE] = '\0';//문자열 처리 하고
	    printf("%s",buf);//stdout에 쓴다
	}
	close(rfd);
    }
    
}
	


	    
	


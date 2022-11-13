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


    /* 
       자식 프로세스
       4-5.txt에서 읽어와
       stdout에 쓴다
    */

    if (pid = 0) { //자식 프로세스

	while (!parent_done); //부모가 종료하지 않았다면 종료까지 무한 루프 
	rfd = open("4-5.txt", O_RDONLY); 
	if (rfd == -1) { //open error
	    perror("open 4-5.txt");
	    exit(1);
	}

	printf("읽어와서 출력 시작\n");

	while ((n = read(rfd, buf, BUFSIZE-1)) > 0) { //읽어오고
	    buf[BUFSIZE] = '\0';//문자열 처리 하고
	    printf("%s",buf);//stdout에 쓴다
	}
	close(rfd);
    }
    
    /*
       부모 프로세스
       stdin 에서 읽어와 4-5.txt에 쓴다
    */
    else  { //부모 프로세스
        wfp = fopen("4-5.txt", "w");
	
	if (wfp == NULL) { //fopen 오류
	    perror("fopen: 4-5.txt");
	    exit(1);
	}
	//EOF 마주치기 전까지 getchar 이용 -> stdin으로 부터 읽어옴
	printf("입력 시작\n");
	while((ch=getchar())!= EOF) { 
	    putc(ch,wfp); //읽어온 것을 wfp에 쓴다 (4-5.txt)
	}
	fclose(wfp);
	exit(1);
    }



}
	


	    
	


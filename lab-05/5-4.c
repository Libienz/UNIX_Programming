#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int pd[2];
    char str[] = "Pipe test";
    char buf[BUFSIZ]; //stdio에 BUFSIZ정의되어 있음
    int len, status;

    //파이프 생성
    if (pipe(pd) == -1) {
	perror("pipe");
	exit(1);
    }


    //파이프에 write하기 
    //pipe함수는 pd[1]을 쓰기 전용으로 열고 pd[0]을 읽기 전용으로 열었음으로 pd[1]에 쓴다.
    if (write(pd[1], str, strlen(str)) != strlen(str)) {
	perror("write");
	exit(1);
    }

    printf("%d writes %s to the pipe.\n", (int)getpid(), str);

    //파이프에서 read하기
    //pd[0]로 부터 읽는다. 
    len = read(pd[0], buf, BUFSIZ);
    if (len ==-1) {
	perror("Read");
	exit(1);
    }

    printf("%d reads %s from the pipe.\n", (int)getpid(), buf);

    //파이프 닫기 
    close(pd[0]);
    close(pd[1]);

    return 0;
}



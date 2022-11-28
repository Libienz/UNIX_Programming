#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    //시스템 콜 이용 파이프 파일 만들기 
    //모드에 파이프 상수 넘기는 이유는 모드에 파일 종류 들어있기 때문
    if (mknod("HAN-FIFO", S_IFIFO | 0644, 0) == -1) { 
	perror("mknod");
	exit(1);
    }

    //라이브러리 함수 이용해서 파이프 파일 만들기
    //mknod와 다르게 다른 특수파일을 만들지 않고 파이프만 만듬
    if (mkfifo("BIT-FIFO", 0644) == -1) {
	perror("mkfifo");
	exit(1);
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE 256

int main(void) {

    int fdin, fdout; //파일 디스크립터 선언
    int n; //read가 반환하는 읽은 바이트 수를 받을 변수
    char buf[SIZE]; //읽은 내용을 담고 쓰기에 사용될 버퍼 

    //open file dummy for read
    fdin = open("dummy",O_RDONLY); 

    if(fdin == -1) { //오류면 오류 메세지 출력
	perror("Open dummy");
	exit(1);
    }
    
    //open file copy for write
    //쓰기모드로 여는데 파일이 존재하지 않는다면 0644 mod로 만들고 (O_CREAT)
    // 존재한다면 모두 지우고 덮어쓴다 (O_TRUNC)
    fdout = open("copy", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fdout == -1) {//오류면 오류 메세지 출력
	perror("Open copy");
	exit(1);
    }

    /*다 읽을 때 까지 반복
	read:  fdin이 가리키는 파일에서 SIZE만큼 읽어와 buf에 담는다
	write: buf에서 SIZE만큼 읽어와 fdout이 가리키는 파일에 쓴다
    */
    while ((n=read(fdin,buf,SIZE)) > 0) { //read는 읽은 바이트 수를 리턴 
	if (write(fdout, buf, SIZE) != n) perror("Write"); //읽어온 만큼 쓰지 못했다면 오류
    }

    if (n == -1) perror("Read"); //read 오류

    //파일 닫기
    close(fdin); 
    close(fdout);

    return 0;
}


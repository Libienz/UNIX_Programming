#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//포트 번호의 역할을 하는 소켓 name
#define SOCKET_NAME "hbsoket" 

int main() {
    char buf[256];
    struct sockaddr_un ser, cli; //소켓에 대한 구조체
    int sd, nsd, len, clen;

    //socket descriptor 생성
    if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
	perror("socket");
	exit(1);
    }

    //소켓 구조체 0으로 채우기
    memset((char *) &ser, 0, sizeof(struct sockaddr_un));
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family) + strlen(ser.sun_path);
    
    //위에서 주소와 소켓 이름등등을 설정한 소켓 구조체와
    //socket descriptor를 bind
    if (bind(sd, (struct sockaddr *) &ser, len)) {
	perror("bind");
	exit(1);
    }

    //백로그 큐의 크기는 5 연결 준비 완료
    if (listen(sd, 5) < 0) {
	perror("listen");
	exit(1);
    }

    //서버는 accept로 기다림
    //연결이 되면 연결된 클라이언트를 위한 새로운 디스크립터 할당 됨
    printf("Waiting...\n");
    if ((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1) {
	perror("accept");
	exit(1);
    }

    if (recv(nsd, buf, sizeof(buf), 0) == -1) {
	perror("recv");
	exit(1);
    }

    printf("Received msg: %s\n", buf);
    close(nsd);
    close(sd);
}





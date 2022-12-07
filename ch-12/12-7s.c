#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000


int main() {

    char buf[256];
    struct sockaddr_in sin, cli; //소켓에 대한 구조체
    int sd, ns, len, clientlen = sizeof(cli);

    //socket descriptor 생성
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	perror("socket");
	exit(1);
    }

    //소켓 구조체 0으로 채우기
    memset((char *) &sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    //포트 번호를 network byte order로 변환하고 구조체에 지정
    //서버 ip주소를 구조체에 지정
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("172.17.97.171");
    
    //위에서 ip주소와 포트번호 등등을 설정한 소켓 구조체와
    //socket descriptor를 bind
    if (bind(sd, (struct sockaddr *) &sin, sizeof(sin))) {
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
    if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
	perror("accept");
	exit(1);
    }

    sprintf(buf, "Your ip address is %s", inet_ntoa(cli.sin_addr));
    if (send(ns, buf, strlen(buf) + 1,0) == -1) {
	perror("send");
	exit(1);
    }

    close(ns);
    close(sd);
}





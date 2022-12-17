#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000
#define SERV_IP "192.168.219.107"

int main(int argc, char *argv[]) {

    int sd;
    char buf[256];
    struct sockaddr_in sin;

    //클라이언트 명령행 인자 concat해서 하나의 문자열로 만들기
    //buf에 서버에 보낼 문자열이 저장된다.
    strcpy(buf,argv[1]);
    for (int i = 2; i < argc; i++) {
	strcpy(buf, strcat(buf," "));
	strcpy(buf, strcat(buf,argv[i]));
    }

    //소켓 주소 구조체 설정
    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr(SERV_IP);

    //소켓 생성
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	perror("socket");
	exit(1);
    }

    //서버에 연결 요청
    if (connect(sd,(struct sockaddr *)&sin, sizeof(sin))) {
	perror("connect");
	exit(1);
    }

    //서버에 명령행으로 받은 문자열 전송
    if (send(sd, buf, sizeof(buf)+1, 0) == -1) {
	perror("send");
	exit(1);
    }

    //서버에게서 처리한 결과물 받는다.
    if (recv(sd, buf, sizeof(buf), 0) == -1) {
	perror("recv");
	exit(1);
    }

    //출력
    printf("From Server : %s\n",buf);


    close(sd);
}







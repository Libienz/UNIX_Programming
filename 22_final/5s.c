#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000
#define SERV_IP "127.0.0.1"

int main() {
    char buf[256];
    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);
    int c; //문자열 뒤집기에서 swap에 쓰일 변수
    int len; //클라이언트가 요청한 문자열의 길이

    //서버 주소 구조체에 소켓의 종류를 AF_INET으로 지정하고 포트 번호와 서버의 IP주소 설정
    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr(SERV_IP);

    //SOCK_STREAM: TCP 사용
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	perror("socket");
	exit(1);
    }
    
    //생성한 소켓을 설정한 IP주소/ 포트번호와 Bind
    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
	perror("bind");
	exit(1);
    }

    //클라이언트의 요청을 받을 준비가 끝났음을 운영체제에 알림
    //한번에 5개 클라이언트가 접속 가능 (큐의 크기가 5)
    if (listen(sd, 5)) {
	perror("listen");
	exit(1);
    }

    //반복 실행 서버
    while(1) {
	//연결 요청 수락하고 
	if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
	    perror("accept");
	    exit(1);
	}

	//클라이언트가 보낸 것을 buf에 담고
	if (recv(ns, buf, sizeof(buf), 0) == -1) {
	    perror("recv");
	    exit(1);
	}

	//문자열 거꾸로 반전하기 
	//swap 이용해서 in place로 해결
	len = strlen(buf);
	for (int i  = 0; i<(len/2); i++) {
	    c = buf[i];
	    buf[i] = buf[len-1-i];
	    buf[len-1-i] = c;
	}
    
	//클라이언트에게 처리된 문자열 전송
	if (send(ns,buf,strlen(buf) +1, 0) == -1) {
	    perror("send");
	    exit(1);
	}

	//client와 연결된 소켓 기술자 닫고 다시 루프로 돌아가 
	//새로운 클라이언트 기다리고 서비스한다.
	close(ns);
    }
    close(sd);

}

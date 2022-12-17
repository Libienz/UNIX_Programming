#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000
#define SERV_IP "192.168.219.107"

//문자열을 받아 대소문자를 반전하는 함수
//반환 값 없이 in place로 문자열을 고친다.
void convert_str(char* s) {
    for (int i  = 0; i<strlen(s); i++) {
	if ( 'a' <=s[i] && s[i] <= 'z' ) {
	   s[i] = s[i] - 'a' + 'A';
	}
	else if ('A' <= s[i] && s[i] <= 'Z') {
	    s[i] = s[i] - 'A' + 'a';
	}
	else continue;
    }
}


int main() {
    char buf[256];
    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);

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

	//대소문자 반전해서
	convert_str(buf);
	//클라이언트에게 보낸다.
	if (send(ns,buf,strlen(buf) +1, 0) == -1) {
	    perror("send");
	    exit(1);
	}

	close(ns);
    }
    close(sd);

}

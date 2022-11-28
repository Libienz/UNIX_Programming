#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//대소문자 반전 함수
void caseReverse(char* msg) {

    for (int i = 0; i<strlen(msg); i++) {
	if (97<= msg[i] && msg[i] <= 122) { //소문자
	    msg[i] =- 32;
	}
	else { //대문자
	    msg[i] += 32;
	}
    }
}

int main() {
    int pd, n;
    char inmsg[80];

    if ((pd = open("./HAN-FIFO", O_RDONLY)) == -1) {
	perror("open");
	exit(1);
    }

    printf("Client ============\n");
    write(1,"From server :", 13);

    while ((n=read(pd,inmsg,80)) > 0)
        caseReverse(inmsg);	
	write(1,inmsg,n);

    if (n==-1) {
	
	perror("read");
	exit(1);
    }

    write(1,"\n",1);
    close(pd);
}


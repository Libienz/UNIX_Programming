#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pd, n;
    char inmsg[80];

    //MYFIFO 읽기 전용으로 열기 
    if ((pd = open("./MYFIFO",O_RDONLY)) == -1) {
	perror("open");
	exit(1);
    }

    //MYFIFO에서 읽어와서 출력하기
    while ((n=read(pd, inmsg, 80)) > 0) 
	printf("%s\n",inmsg);

    if (n==-1) {
	perror("read");
	exit(1);
    }

    close(pd);
}



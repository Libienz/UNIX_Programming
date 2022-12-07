#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pd, n;
    char msg[] = "talker send FIFO test";

    //named pipe MYFIFO를 현재 디렉토리에 생성
    if (mkfifo("./MYFIFO", 0666) == -1) {
	perror("mkfifo");
	exit(1);
    }

    //MYFIFO 쓰기 전용으로 열기 
    if ((pd = open("./MYFIFO", O_WRONLY)) == -1) {
	perror("open");
	exit(1);
    }

    //MYFIFO에 쓰기 
    n = write(pd, msg, strlen(msg) + 1);
    if (n == -1) {
	perror("write");
	exit(1);
    }
    close(pd);

}



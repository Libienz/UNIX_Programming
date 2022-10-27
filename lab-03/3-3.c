#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUF_SIZE 10

int main() {
    int rfd, wfd, n; //읽기 디스크립터와 쓰기 디스크립터 구분
    char buf[BUF_SIZE]; //내용을 날라줄 버퍼

    rfd = open("3-1.txt", O_RDONLY); //읽기 전용으로 열기
    if(rfd == -1) {
        perror("Open 3-1.txt");
        exit(1);
    }

    //쓰기 전용으로 열기
    wfd = open("3-3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open linux.bak");
        exit(1);
    }

    //read는 읽은 바이트 수 반환 읽어올 게 있을 동안 반복
    while ((n = read(rfd, buf, BUF_SIZE)) > 0) {
        if (write(wfd, buf, n) != n) perror("Write");
    }

    if (n == -1) perror("Read");

    close(rfd);
    close(wfd);
}

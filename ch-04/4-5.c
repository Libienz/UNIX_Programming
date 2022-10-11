#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUF_SIZE 10

int main() {
    int rfd, wfd, n;
    char buf[BUF_SIZE];

    rfd = open("linux.txt", O_RDONLY);
    if(rfd == -1) {
        perror("Open linux.txt");
        exit(1);
    }

    wfd = open("linux.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open linux.bak");
        exit(1);
    }

    while ((n = read(rfd, buf, BUF_SIZE)) > 0) {
        if (write(wfd, buf, n) != n) perror("Write");
    }

    if (n == -1) perror("Read");

    close(rfd);
    close(wfd);
}

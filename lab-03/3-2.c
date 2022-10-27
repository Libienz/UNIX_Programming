#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//str이 가리키는 문자열 내용 3-1.txt에 write하는 프로그램
int main(void) {

    int fd;
    int n;

    char str[] = "UNIX SYSTEM PROGRAMMING";

    fd = open("3-1.txt", O_WRONLY); //쓰기전용으로 열기
    if (fd == -1) {
	perror("Open");
	exit(1);
    }

    n = write(fd, str, strlen(str)); //str에서 strlen만큼을 가져와 쓴다
    if (n != strlen(str)) {
	perror("Write");
	exit(2);
    }

    close(fd);

    return 0;
}



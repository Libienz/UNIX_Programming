#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


//3-1.txt 파일 여는 프로그램.
//3-1.txt가 존재하지 않는다면 지정한 모드로 생성
int main(void) {
    int fd;
    mode_t mode;
    // rw r r
    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    //O_CREAT: 파일을 열건데 존재하지 않으면 지정한 mode로 생성
    fd = open("3-1.txt", O_CREAT, mode);
    if (fd == -1) {
	perror("Creat");
	exit(1);
    }
    close(fd);
    return 0;
}

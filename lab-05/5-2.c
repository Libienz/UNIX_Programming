#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    int fd;
    caddr_t addr;
    struct stat statbuf;

    //명령행에서 형식을 맞추지 않았을 경우
    if (argc != 2) {
	fprintf(stderr, "Usage : %s filename\n", argv[0]);
	exit(1);
    }

    //파일의 크기 알아보기 위해 stat함수 사용
    if (stat(argv[1], &statbuf) == -1) {
	    perror("stat");
	    exit(1);
    }

    //파일 열기
    if ((fd = open(argv[1], O_RDWR)) == -1) {
	perror("open");
	exit(1);
    }

    //열린 파일의 내용을 메모리로 매핑
    addr = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0);
    if (addr == MAP_FAILED) {
	perror("mmap");
	exit(1);
    }

    close(fd);
    //addr이 가리키는 주소에 저장된 내용 출력
    printf("%s",addr);
}

	    

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define FNAME "test.txt"

int main(void) {

    int fd;
    caddr_t addr;
    struct stat statbuf;

    //열고자 하는 파일의 사이즈 알아내기 위해서 stat
    if (stat(FNAME, &statbuf) == -1) {
	perror("stat");
	exit(1);
    }

    //파일 연다 메모리에 매핑하기 위한 기술자 얻어내기 위해서
    if ((fd = open(FNAME, O_RDWR)) == -1) {
	perror("open");
	exit(1);
    }

    //fd의 옵셋0부터 st_size만큼 읽어와서 메모리에 매핑 하는데
    //메모리 주소는 내가 지정하지 않음으로 시스템이 적절히 지정해주어야 하고 
    //매핑된 메모리에 대해서 쓰기와 읽기가 가능하며 매핑된 내용은 프로세스간 공유가 가능하당
    addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE,MAP_SHARED,fd,(off_t)0);
    if (addr == MAP_FAILED) {
	perror("mmap");
	exit(1);
    }

    close(fd);

    printf("%s",addr);

    return 0;
}



//mmap을 사용한 wc
//메모리에 가져다 놓고 메모리에서만 읽어서 기존 wc보다 훨씬 빠르다.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

#define IN 1
#define OUT 0


int main(int argc, char *argv[]) {

    int c, nl, nw, nc, state,fd,ind;
    state = OUT;
    caddr_t addr;
    ind = nl = nw = nc = 0;
    struct stat statbuf;

    //perror 생략
    stat(argv[1], &statbuf);
    //perror 생략
    fd = open(argv[1], O_RDWR);
    //perror 생략
    addr = mmap(NULL,statbuf.st_size,PROT_READ|PROT_WRITE, MAP_SHARED, fd,(off_t)0);


    while((c=addr[ind]) != EOF) {
        ++nc;
	++ind;
	if (c == '\n')
	    ++nl;
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = OUT;
	    printf("%d\n",ind);
	}	
	else if (state ==OUT) {
	    state = IN;
	    ++nw;
	}
    }
    printf("%d %d %d\n",nl,nw,nc);
    printf("%d\n",ind);

}    

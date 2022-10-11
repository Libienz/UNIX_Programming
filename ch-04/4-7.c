#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int fd, fd1;
    
    fd = open ("temp.aaa",O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if( fd == -1) {
        perror("Create tmp.aaa");
	exit(1);
    }

    close(1);

    fd1 = dup(fd); //fd1 이 1번 fd로 
    printf("DUP FD=%d\n",fd1); //콘솔에 출력되지 않고 temp.aaa로 ..
    printf("Standard Output Redirection\n");

    close(fd);

}

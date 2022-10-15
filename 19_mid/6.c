#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    
    
    int fd1;
    int fd2;
    int n;
    char buf[10];
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_CREAT | O_WRONLY,0644);
    if (fd1 == -1) {
	perror("fail");
	exit(1);
    }

    while ((n=read(fd1,buf,5))!= 0) {
	write(fd2,buf,5);
    }

    close(fd1);
    close(fd2);
}




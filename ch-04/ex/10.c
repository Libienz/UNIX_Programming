#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 1
int main(void) {

	int n, rfd;
	char buf[SIZE+1];
	rfd = open("data.txt",O_RDONLY);
	if (rfd==-1) perror("open");

	while ((n=read(rfd,buf,SIZE)) >0) {
		buf[n]='\0';
		printf("%s",buf);
		lseek(rfd,1,SEEK_CUR);
	}

	if(n==-1) perror("read");
	return 0;
}




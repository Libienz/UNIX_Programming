#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 3

int main (void) {

	char buf[SIZE+1];
	int n, rfd;
	rfd = open("data.txt",O_RDONLY);
	if (rfd == -1) perror("open");

	while((n=read(rfd,buf,SIZE))>0) {

		buf[n] = '\0';
		printf("%s ",buf);

	}
	if (n==-1) perror("read");
	printf("\n");

	return 0;
}






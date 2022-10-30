#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/times.h>

#define SIZE 256

int main(void) {
	struct tms tbuf;
	times(&tbuf);

	int n, fdin, fdout;
	char buf[SIZE];

	fdin = open("dummy",O_CREAT | O_RDONLY, 0644);
	fdout = open("copy",O_CREAT | O_WRONLY |O_TRUNC, 0644);

	while ((n=read(fdin,buf,SIZE)) > 0 ) {
		if(write(fdout,buf,n)!=n) {
			perror("write");
		}
	}
	if (n == -1) perror("Read");

	close(fdin);
	close(fdout);

	printf("utime: %ld\n",tbuf.tms_utime);
	printf("stime: %ld\n",tbuf.tms_stime);

	return 0;
}





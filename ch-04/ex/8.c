#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

#define SIZE 256

int main(int argc, char* argv[]) {
	DIR* dp;
	char buf[SIZE];
	int n,rfd,wfd;
	rfd = open(argv[2], O_RDONLY);
	if (rfd == -1) {
		perror("open rfd");
	}
	mkdir(argv[1],0755);
	chdir(argv[1]);
	dp = opendir(".");
	wfd = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0622);
	if (wfd == -1) {
		perror("wfd open");
	}

	while((n = read(rfd,buf,SIZE))>0) {
		if(write(wfd,buf,SIZE) == -1) {
			perror("write");
			exit(1);
		}
	}
	if (n==-1) {
		perror("read");
	}

	closedir(dp);
	return 0;
}


	

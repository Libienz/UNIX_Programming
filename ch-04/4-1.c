#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//descryptor 는 인덱스!!
int main(void) {
	int fd;
	mode_t mode;

	mode  = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	
	fd = open("test.txt",0_CREAT,mode);

	if (fd == -1) {
		perror("Creat");
		exit(1);
	}

	close(fd);
}


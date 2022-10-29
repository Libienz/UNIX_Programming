#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	if (mkdir("dir1", 0755) == -1) {
		perror("mkdir");
		exit(1);
	}
	if (mkdir("dir2",0755) == -1) {
		perror("mkdir");
		exit(1);
	}

	rmdir("dir1");
	rename("dir2","hanbit");

	return 0;
}




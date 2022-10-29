#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main (int argc, char* argv[]) {

	struct stat statbuf;
	char* filename;

	for (int i =1; i<argc; i++) {
		filename = argv[i];
		stat(filename, &statbuf);
		printf("kind: %d\n",statbuf.st_mode);
	}

	return 0;
}



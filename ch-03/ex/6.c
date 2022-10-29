#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main (int argc, char* argv[]) {

	char* filename;
	struct stat buf;
	for (int i = 1; i<argc; i++) {
		filename = argv[i];
		stat(filename,&buf);
		printf("size: %ld\n",buf.st_size);
	}
	return 0;
}


	

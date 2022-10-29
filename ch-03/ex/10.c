#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main (void) {

	DIR* dp;
	struct dirent* dent;
	struct stat statbuf;
	char* filename;
	dp = opendir(".");
	
	while ((dent = readdir(dp))) {
		filename = dent->d_name;
		stat(filename, &statbuf);
		printf("name: %s\n",filename);
		printf("Inode: %ld\n",dent->d_ino);
	}

	return 0;
}


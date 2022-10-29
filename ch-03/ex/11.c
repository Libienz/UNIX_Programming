#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main (void) {

	DIR* dp;
	struct dirent* dent;
	struct stat statbuf;
	char* filename;

	dp = opendir(".");

	while((dent = readdir(dp))) {
		filename = dent->d_name;
		stat(filename,&statbuf);
		if((statbuf.st_mode & S_IFMT) == S_IFDIR) {
			printf("%s\n",filename);
		}
	}
	closedir(dp);
	return 0;
}



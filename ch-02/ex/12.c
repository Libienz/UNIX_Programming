#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>

int main() {

	DIR* dp;
	struct dirent* dent;

	dp = opendir(".");
	while ((dent = readdir(dp))) {
		if (dent->d_name == "." || dent->d_name=="..") {
			continue;
		}
		printf("%s\n",dent->d_name);
	}
	closedir(dp);
	return 0;

}




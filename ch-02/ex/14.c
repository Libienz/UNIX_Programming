#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]) {

	DIR* dp;
	struct dirent* dent;

	char* file_name = argv[1];

	dp = opendir(".");
	while ((dent = readdir(dp))) {
		if (strcmp((dent->d_name),file_name) == 0) {
			printf("oo\n");
		}
		
	}

	return 0;
}


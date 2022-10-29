#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(void) {

	DIR *dp;
	struct dirent *dent;
	
	if (mkdir("hanbit",0755)==-1) {
		perror("mkdir");
		exit(1);
	}
	dp = opendir("hanbit");
	if ((dent = readdir(dp)) == NULL) {
		printf("비어있음으로 한빗 지우겠음\n");
		closedir(dp);
		rmdir("hanbit");
	}
	else {
		printf("%s\n",dent->d_name);
	}


	return 0;
}



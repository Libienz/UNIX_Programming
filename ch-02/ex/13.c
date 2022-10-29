#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main(void) {

	DIR* dp;
	struct dirent* dent;

	dp = opendir(".");
	while (dent=readdir(dp)) {
		printf("%s\n",dent->d_name);
	}
	rewinddir(dp);

	seekdir(dp,telldir(dp));
	seekdir(dp,telldir(dp));
	seekdir(dp,telldir(dp));

	dent = readdir(dp);

	printf("\n%s\n",dent->d_name);

	return 0;
}

     	


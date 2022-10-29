#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int mian() {
	char *cwd;

	cwd = getcwd(NULL, BUFSIZ);
	printf("1.Cur Dir: %s\n",cwd);

	return 0;
}


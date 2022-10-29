#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

	char *dirname = argv[1];

	mkdir(dirname,0755);
	chdir(dirname);
	char* cwd = getcwd(NULL,0);
	printf("%s\n",cwd);


	free(cwd);

	return 0;

}



#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(void) {

	mkdir("hanbit",0755);

	char buf[256];

	chdir("hanbit");
	printf("%s\n", getcwd(buf,256));
	return 0;
}


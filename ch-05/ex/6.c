#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	struct utsname uts;
	int n;

	if (uname(&uts) == -1) {
		perror("uname");
		exit(1);
	}

	while((n=getopt(argc,argv,"hs")) != -1) {
		switch(n) {

			case 'h':
				printf("%s\n",uts.machine);
				break;
			case 's':
				printf("%s\n",uts.sysname);
				break;

		}
	}

	return 0;
}






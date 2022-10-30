#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

	int n;

	while((n=getopt(argc,argv,"hl")) != -1) {
		switch(n) {
			case 'h':
				printf("%ld\n",sysconf(_SC_HOST_NAME_MAX));
				break;
			case 'l':
				printf("%ld\n",sysconf(_SC_LOGIN_NAME_MAX));
				break;
		}

	
	}
	return 0;
}

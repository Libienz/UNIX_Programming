#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

	extern char *optarg;
	extern int optind;

	int n;

	while((n=getopt(argc,argv,"pnh")) != -1) {

		switch(n) {
			case 'p':
				printf("Welcome Linux\n");
				break;
			case 'n':
				printf("Nice to meet\n");
				break;
			case 'h':
				printf("option list\n");
				break;
		}

	}


	return 0;
}	

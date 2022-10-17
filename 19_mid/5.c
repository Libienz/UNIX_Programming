#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	extern char* optarg;
	extern int optind;
	int optcnt =0;	
	int res;
	int n;
	int sum=0;
    	int mul=1;
	int optstart;
	while((n=getopt(argc,argv,"a:m:am:"))!= -1) {
		optstart = optind;
		switch(n) {
			case 'a' :
				res=0;
				for (--optind;optind<argc;optind++) {
					res+=atoi(argv[optind]);
				}
				printf("%d\n", res);		
				break;
			case 'm' :
				res=1;
				for (--optind;optind<argc;optind++) {
					res*=atoi(argv[optind]);
				}
				printf("%d\n", res);		
				break;
				
		}
	}
}



#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


int main(void) {
	int opt;
	int flag = 1;

	while (flag==1) {
		printf("choose option\n1: pwd\n2: date\n3:quit\n");
		scanf("%d",&opt);
		switch (opt) {
			case 1: 
				char *cwd;
				cwd = getcwd(NULL,0);
				printf("%s\n",cwd);
				free(cwd);
				break;
			case 2:
				time_t timep;
				time(&timep);
				printf("%s\n",ctime(&timep));
				break;
			case 3:
				flag=0;
				break;
			default:
				printf("wrong opt\n");
				break;
		}
	}
	return 0;
}


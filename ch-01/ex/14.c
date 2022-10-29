#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int fnum = atoi(argv[1]);
	int snum = atoi(argv[2]);
	int sum = 0;
	for (int i = fnum; i<=snum; i++) {
		sum += i;
	}
	
	printf("sum: %d\n",sum);

	return 0;
}



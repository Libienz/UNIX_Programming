#include <stdio.h>

int main(void) {
	int i,j,k;

	i=0;
	j=1;

	while(i<100) {
		printf("%d\n",i);
		k=i+j;
		i=j;
		j=k;
	}
	return 0;
}


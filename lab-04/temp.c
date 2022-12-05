#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    FILE *wfp, *rfp;
    int n;
    int c;

    wfp = fopen("4-5.txt","w");
    while((c = getchar()) != EOF) {
	fputc(c,wfp);
    }

    rfp = fopen("4-5.txt","r");
    while((c = getc(rfp)) != EOF) {
	printf("%c",c);
    }

    fclose(wfp);
    fclose(rfp);

}


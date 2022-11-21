#include <stdio.h>

#define IN 1
#define OUT 0


int main(int argc, char *argv[]) {

    int c, nl, nw, nc, state;
    FILE *fp;
    state = OUT;
    nl = nw = nc = 0;
    fp = fopen(argv[1], "r");


    while((c=fgetc(fp)) != EOF) {
       ++nc;
	if (c == '\n')
	    ++nl;
	if (c == ' ' || c == '\n' || c == '\t')
	    state = OUT;
	else if (state ==OUT) {
	    state = IN;
	    ++nw;
	}
    }
    fclose(fp);
    printf("%d %d %d\n",nl,nw,nc);
}    

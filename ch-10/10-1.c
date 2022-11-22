#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    FILE* fp;
    int a;

    fp = popen("wc -l", "w");
    if (fp == NULL) {
	fprintf(stderr, "popen failed\n");
	exit(1);
    }

    for (a = 0; a<5; a++) {
	sleep(1);
	fprintf(fp,"test line\n"); //중간에 끊긴다고 보기 힘들다!
    }

    pclose(fp);

}


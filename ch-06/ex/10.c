#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct tms buf;
    clock_t ct;

    if (times(&buf)==-1) {
	perror("times");
	exit(1);
    }
    sleep(5);
    for (int i=0; i<99999; i++) {
	printf("a\n");
    }
    ct = sysconf(_SC_CLK_TCK); //초당 몇번?
    printf("clock tck: %ld\n",ct);
    printf("utime: %ld\n",buf.tms_utime);
    printf("stime: %ld\n",buf.tms_stime);

    return 0;


}


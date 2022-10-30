#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int pid = atoi(argv[1]);
    printf("PGID: %d\n",getpgid(pid));
    printf("SID: %d\n",getsid(pid));

    return 0;
}



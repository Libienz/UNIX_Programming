#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void) {

    struct stat statbuf;

    stat("dummy", &statbuf);
    printf("dummy blk_size: %d\n", (int)statbuf.st_blksize);
    stat("copy", &statbuf);
    printf("copy blk_size: %d\n", (int)statbuf.st_blksize);

    return 0;
}


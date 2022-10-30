#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>



int main (void) {

    struct tms buf;
    int fd;
    times(&buf);



    for (int i =0; i<10000000; i++) {
	fd = open("temp.txt",O_RDONLY);
	close(fd);
    }
    printf("utime: %ld\n",buf.tms_cutime);
    printf("stime: %ld\n",buf.tms_cstime);
}


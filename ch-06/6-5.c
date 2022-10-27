#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//times vs time 다른 것!
//실행 되고 얼마의 시간이 흘렀는지 체크하는 프로그램


int main() {
    int i;
    time_t t; 
    struct tms buf;
    clock_t ct, t1, t2;

    ct = sysconf(_SC_CLK_TCK); //이 시스템은 클락 틱을 얼마로 정의하는 가
    printf("Clock tick : %ld\n", ct);

    if ((t1 = times(&buf)) == -1) {
        perror("times 1");
        exit(1);
    }

    for (i = 0; i < 99999999; i++)
        time(&t);
    sleep(1);

    if ((t2 = times(&buf)) == -1) {
        perror("times 2");
        exit(1);
    }

    printf("t1: %ld\n", t1);
    printf("t2: %ld\n", t2);
    printf("utime : %ld\n", buf.tms_utime);
    printf("stime : %ld\n", buf.tms_stime);
    printf("Real time : %.1f sec\n", (double)(t2 - t1) / ct);
    printf("User time : %.1f sec\n", (double)buf.tms_utime / ct);
    printf("System time : %.1f sec\n", (double)buf.tms_stime / ct);
}

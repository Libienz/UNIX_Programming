#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    
    struct sysinfo info;

    sysinfo(&info);
    printf("%ld\n",info.uptime);

    return 0;
}



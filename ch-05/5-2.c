#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("Arg Max : %ld\n",sysconf(_SC_ARG_MAX));
    printf("Clock Tick : %ld\n",sysconf(_SC_CLK_TCK));
    printf("Max Open File : %ld\n",sysconf(_SC_OPEN_MAX));
    printf("Arg Max : %ld\n",sysconf(_SC_LOGIN_NAME_MAX));
}



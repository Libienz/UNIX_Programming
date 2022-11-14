#include <signal.h>
#include <stdio.h>

int main() {
    sigset_t st;

    sigemptyset(&st);

    sigaddset(&st,SIGINT);//2번째
    sigaddset(&st, SIGQUIT);//3번째

    if (sigismember(&st, SIGINT)) 
	printf("설정 되어 있다\n");
    

    printf("비트 패턴: %lx\n",st.__val[0]); 
    //6나오는데 00000110 인 것 볼 수 있음 
    //이렇게 비트패턴을 직접 찍는 것 좋지 못한 방법
    //sigismember로 확인하는 것이 바람직한 방법이다

    return 0;
}

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//뒤에 출력된거 남아있는 거는 상관 없나 ..? 

int main(void) {

    //시그널 집합 선언
    sigset_t new;

    //시그널 집합 초기화하고 SIGINT를 집합에 추가한다.
    sigemptyset(&new);
    sigaddset(&new, SIGINT);
    //시그널 집합을 블로킹 한다. SIGINT가 들어와도 block 
    sigprocmask(SIG_BLOCK, &new, (sigset_t *) NULL);


    short i = 0;

    while(1) {
	if (i<0)
	    i=0;
	printf("%d\r", i++);
    }
    return 0;
}

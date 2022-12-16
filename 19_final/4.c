#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//sig handler
//해당 핸들러는 SIGINT 시그널을 처리하기 위해 만들어짐 
void sig_handler(int signo) {
    printf("\ncatch SIGINT...\n");
    //갔다가 왔을 때 sleep(1) 안하고 바로 루프 첫번째로 넘어가는 건 상관 없나?
}



int main(void) {


    //sigaction 구조체는 시그널 처리를 위한 핸들러 주소,
    //시그널 핸들러가 수행되는 동안 블로킹될 시그널,
    //추가 기능을 설정할 수 있는 플래그로 구성된다.
    struct sigaction act;

    //블로킹 할 것은 없음
    sigemptyset(&act.sa_mask);
    //시그널 기본 처리 방법을 SIG_DFL로 원복
    act.sa_flags = SA_RESETHAND;
    //핸들러 설정 
    act.sa_handler = sig_handler;
    
    //SIGINT라는 시그널 오면 act에 설정한 대로 동작할 것임 
    if (sigaction(SIGINT, &act, (struct sigaction *) NULL) <0 ) {
	perror("sigaction");
	exit(1);
    }

    int i;

    for (i = 0; i< 10; i++) {
	printf("sleep 1 sec...\n");
	sleep(1);
    }

}


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//시그널 호출 횟수를 세는 전역변수
int sigcnt = 0;

//SIGINT 처리하는데 사용될 handler
void sig_handler(int signo) {
    printf("Handler is called %d times(s)\n", ++sigcnt);
}

int main(void) {
    struct sigaction act;

    //블로킹 따로 지정 안함
    //sa_flag가 0임으로 시그널 핸들러를 호출되게 하는 시그널은 블로킹
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = sig_handler;

    //시그널 핸들러를 지정하며 여러 처리과정까지 제어할 수 있는 sigaction
    //SIGINT를 처리하는 핸들러와 flag, mask가 지정된 구조체를 인자로 넘긴다.
    if (sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {
	perror("sigaction");
	exit(1);
    }

    
    while (1) {
	printf("I'm in infinite loop\n");
	sleep(5);
    }
    return 0;
}


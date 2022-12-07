#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


//signal handler
void handler(int signo) {
    psignal(signo, "Received Signal: ");
    sleep(5);
    printf("In Signal Handler, After Sleep\n");
}

int main(void) {

    struct sigaction act;

    //핸들러가 동작중일 떄 블로킹할 시그널 집합
    //아무것도 설정하지 않았지만 sa_flags에 NO_DEFER를 설정하지 않았기에
    //시그널 핸들러를 호출하게 한 시그널은 자동 블로킹 된다.
    sigemptyset(&act.sa_mask);

    act.sa_flags = 0;
    act.sa_handler = handler; //signal 핸들러 설정

    //sigaction함수를 통해 SIGINT 시그널을 받을 경우의 동작 지정 
    if (sigaction(SIGINT, &act, (struct sigaction *) NULL) < 0) {
	perror("sigaction");
	exit(1);
    }

    while(1) {
	fprintf(stderr, "Input SIGINT: ");
	pause();
	fprintf(stderr, "After Signal Handler\n");
    }

    return 0;
    
}


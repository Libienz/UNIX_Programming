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

    //핸들러 가리키는 함수 포인터
    void (*hand)(int);

    //SIGINT를 처리하는 핸들러 지정
    //성공하면 hand에는 시그널 핸들러의 주소가 담겨 있을 것임
    hand = signal(SIGINT, sig_handler);
    if (hand == SIG_ERR) {
	perror("signal");
	exit(1);
    }

    int i;

    for (i = 0; i< 10; i++) {
	printf("sleep 1 sec...\n");
	sleep(1);
    }

}


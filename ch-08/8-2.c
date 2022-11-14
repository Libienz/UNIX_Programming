#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) { //sig handler가 등록 되지 않았다면 디폴트 액션 수행한다 
    printf("Signal Handler signum: %d\n",signo);
    psignal(signo, "Received Signal");
}

int main() {

    void (*hand) (int); //?????

    hand = signal(SIGINT, sig_handler);
    if (hand == SIG_ERR) {
	perror("signal");
	exit(1);
    }

    printf("Wait 1st Ctrl+C... : SIGINT\n");
    pause(); //wait for signal
    printf("After 1st Signal Handler\n");
    printf("Wait 2nd Ctrl+C... : SIGINT\n");
    pause();
    printf("After 2nd Signal Handler\n");

}



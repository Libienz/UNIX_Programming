#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

//kill이 죽이는 것 만은 아니넹
int main() {

    printf("Before SIGCOUNT signal to parent.\n");
    kill(getppid(), SIGCONT); //부모에게 계속하라는 신호 준다 

    printf("Before SIGQUIT signal to me.\n");
    kill(getpid(), SIGQUIT); //코어 덤프하고 끝난다.
    //근데 코어파일이 만들어지지 않음 
    //왜냐하면 ulimit으로 코어가 생성되지 않도록 제한을 걸어놓았기 떄문
    // ulimite -c unlimited 로 제한 없애도 그래도 안생기기는 하네
    //버전마다 차이가 있는 듯 
    printf("After SIGQUIT signal.\n");

}

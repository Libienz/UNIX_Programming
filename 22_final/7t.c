#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM 1500000000

//thread의 계산 결과값 들어올 전역변수 
int t1sum = 0;
int t2sum = 0;

//첫번째 쓰레드의 메인 함수 1부터 NUM/2 까지 덧셈
void *sum1(void *arg) {

    for (int i = 0; i < NUM/2; i++) {
	t1sum += i;
    }
    return NULL;    
}

//두번째 쓰레드의 메인 함수 NUM/2부터 NUM까지 덧셈
void *sum2(void *arg) {
    
    for (int i = NUM/2; i <= NUM; i++) {
	t2sum += i;
    }
    return NULL;
}

int main(void) {

    //생성한 스레드 담을 배열
    pthread_t t[2];
    int r;
    //각 쓰레드의 리턴 값 담을 변수

    //첫번째 쓰레드
    r=pthread_create(&t[0], NULL, sum1, NULL);

    //r에 0이 아닌 값이 담겨 있다면 에러가 발생한 것 
    if (r != 0) {
	perror("thread create:");
	exit(1);
    }

    //두번째 쓰레드
    r = pthread_create(&t[1], NULL, sum2, NULL);
    if (r != 0) {
	perror("thread create:");
	exit(2);
    }

    //쓰레드가 종료되어 제어의 흐름이 합쳐질 때까지 기다린다.
    //waitpid와 유사한 동작
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);


//    printf("%d\n", t1sum + t2sum);

    return 0;
}



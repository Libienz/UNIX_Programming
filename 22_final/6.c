#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 100000000

//여러 쓰레드가 접근 가능한 영역
//mutual exclusion을 보장하기 위해 사용될 mutex 선언
unsigned int s = 0;
pthread_mutex_t mutex;

//thread가 실행할 함수
void *c(void *d) {
    int i;
    for (i = 0; i < N; i++) {
	pthread_mutex_lock(&mutex); //임계 영역 접근 권한을 얻으면 mutex잠그고 임계영역에 들어간다.
	s++;
	pthread_mutex_unlock(&mutex); //다 사용했으면 mutex unlock하고 나온다.
    }
    return NULL;
}

int main(void) {

    //mutual exclusion 보장해줄 mutex init
    pthread_mutex_init(&mutex, NULL); 
    //생성한 스레드 담을 배열
    pthread_t t[2];
    int r;

    //쓰레드 만들기
    //쓰레드의 식별자에 대한 구조체를 t[0]에 담고 
    //쓰레드의 속정 지정은 default (NULL)로 하고
    //쓰레드에서 분기하여 실행할 함수는 c이며 
    //c를 실행할 때 넘겨줄 인자는 없다 (NULL)
    r=pthread_create(&t[0], NULL, c , NULL);

    //r에 0이 아닌 값이 담겨 있다면 에러가 발생한 것 
    if (r != 0) {
	perror("thread create:");
	exit(1);
    }
    //쓰레드 하나 더 만들기
    r = pthread_create(&t[1], NULL, c, NULL);
    if (r != 0) {
	perror("thread create:");
	exit(2);
    }

    //쓰레드가 종료되어 제어의 흐름이 합쳐질 때까지 기다린다.
    //waitpid와 유사한 동작
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    printf("%u\n", s);
    //mutex destroy
    pthread_mutex_destroy(&mutex);

    return 0;
}



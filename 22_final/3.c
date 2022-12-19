#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int shmid, i;
    char *addr1, *addr2;
    char msg[200];

    //key를 IPC_PRIVATE으로 20바이트 크기의 공유 메모리 식별자 생성
    shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644);
    if (shmid == -1) {
	perror("shmget");
	exit(1);
    }


    switch (fork()) {
	case -1: //fork error
	    perror("fork");
	    exit(1);
	    break;
	case 0: //child proc
	    addr1 = (char *)shmat(shmid, (char *)NULL, 0); //공유 메모리 연결
	    printf("=Child %d begins\n",getpid());
	    sprintf(msg, "Message from %d", getpid()); //자식이 보낼 msg 빌드
	    strcpy(addr1, msg); //공유메모리에 자식의 메시지 카피 
	    shmdt((char *) addr1); //공유 메모리 detach (없어지는 것 아님!->분리)
	    printf("=Child %d ends\n", getpid());
	    exit(0);
	    break;
	default: //parent proc
	    wait(0); //자식 기다린다.
	    printf("=Parents %d begins\n",getpid());
	    addr2 = (char *)shmat(shmid, (char *)NULL, 0); //공유 메모리 연결
	    printf("%d gets %s\n",getpid(),addr2); //공유 메모리의 내용 읽어서 출력

	    shmdt((char *)addr2); //공유 메모리 detach
	    shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL); //공유 메모리 제거
	    printf("=Parents %d ends\n",getpid());
	    break;
    }

}



	    

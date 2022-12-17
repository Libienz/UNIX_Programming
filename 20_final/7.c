#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int shmid, i;
    char *shmaddr, *shmaddr2;
    char msg[] = "Message from Child";


    //key를 IPC_PRIVATE으로 20바이트 크기의 공유 메모리 생성
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
	    shmaddr = (char *)shmat(shmid, (char *)NULL, 0); //공유 메모리 연결
	    printf("=Child begins\n");
	    for (int i = 0; i<strlen(msg); i++) //공유 메모리에 메세지 세팅
		shmaddr[i] = msg[i]; 
	    shmdt((char *) shmaddr); //공유 메모리 detach (없어지는 것 아님!->분리)
	    exit(0);
	    break;
	default: //parent proc
	    wait(0); //자식 기다린다.
	    printf("=Parents begins\n");
	    shmaddr2 = (char *)shmat(shmid, (char *)NULL, 0); //공유 메모리 연결
	    printf("%s\n",shmaddr2); //공유 메모리의 내용 읽어서 출력

	    shmdt((char *)shmaddr2); //공유 메모리 detach
	    shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL); //공유 메모리 제거
	    printf("=Parents ends\n");
	    break;
    }

}



	    

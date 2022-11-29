#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int shmid, i;
    char *shmaddr, *shmaddr2;

    //key값 위치에 PRIVATE : 부모 자식 family만 사용가능하게 하겠다.
    shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644);
    if (shmid==-1) {
	perror("shmget");
	exit(1);
    }

    switch(fork()) {
	case -1: 
	    perror("fork");
	    exit(1);
	    break;
	case 0:
	    //attach
	    shmaddr = (char *)shmat(shmid,(char *)NULL, 0);
	    printf("Child proc ==========\n");
	    for (i = 0; i < 10; i++) {
		shmaddr[i] = 'a'+i;
	    }
	    //detach
	    shmdt((char *)shmaddr);
	    exit(0);
	    break;
	default:
	    wait(0);
	    //attach
	    shmaddr2 = (char *)shmat (shmid, (char *) NULL, 0);
	    printf("Parent proc ==========\n");
	    for (i = 0; i< 10; i++)
		printf("%c ",shmaddr2[i]);
	    printf("\n");

	    sleep(5);
	    //detach
	    shmdt((char *)shmaddr2);

	    //destroy
	    shmctl(shmid, IPC_RMID, (struct shmid_ds *) NULL);
	    break;
    }
}





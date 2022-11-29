#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    key_t key;
    int shmid;

    //궁금했던거 알았다
    //shmfile이라는게 없으면 대게 키는 0xfffffffff이런식으로 생김
    key = ftok("shmfile",1);


    //shared memory
    //1024바이트 키값으로 만드는데 없으면 만들고 
    //permission은 0644
    shmid = shmget(key,1024, IPC_CREAT|0644);
    if (shmid == -1) {
	perror("shmget");
	exit(1);
    }

}

#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>


// 큐를 만들었다가 지우는 것을 확인할 수 있음
int main() {
    key_t key;
    int msgid;

    key = ftok("keyfile", 1);
    msgid = msgget(key, IPC_CREAT|0644);
    if (msgid == -1) {
	perror("msgget");
	exit(1);
    }

    printf("Before IPC_RMID\n");
    system("ipcs -q");
    msgctl(msgid, IPC_RMID, (struct msqid_ds *) NULL);
    printf("After IPC_RMID\n");
    system("ipcs -q");

}


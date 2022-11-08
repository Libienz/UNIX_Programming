#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("--> Before exec function\n");

    //exec을 하는 순간 아래의 코드를 나의 명령으로 overwrite 한다
    //fork 이후에 엎어치겠지 보통
    if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
	    perror("execlp");
	    exit(1);
	}

    //아랫놈이 출력 안되는 것을 확인할 수 있음
    printf("--> After exec function\n");

}


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *argv[3];

    printf("Before exec function\n");

    argv[0] = "ls";
    argv[1] = "-a";
    argv[2] = NULL;

    if (execv("/usr/bin/ls", argv) == -1) { // p가 없으니 경로명으로 
	perror("execv");
	exit(1);
    }

    printf("After exec function\n"); //도달하지 않는다 (사실 없어진다 ls로 엎어쳐짐

}

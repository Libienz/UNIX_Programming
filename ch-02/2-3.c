#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 30

//getcwd(매달곳, 버퍼사이즈)

int main() {
    char *cwd;
    char wd1[BUFSIZ];
    char wd2[SIZE];

    getcwd(wd1, BUFSIZ);
    printf("wd1 = %s\n", wd1);
 
    cwd = getcwd(NULL, BUFSIZ);
    printf("cwd1 = %s\n", cwd);
    free(cwd);

    cwd = getcwd(NULL, 0);
    printf("cwd2 = %s\n", cwd);
    free(cwd);

    if(getcwd(wd2, SIZE) == NULL) {
        perror("getcwd");
        exit(1);
    }
}

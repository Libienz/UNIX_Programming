#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

//디렉토리 내용 읽는 프로그램 

int main() {
    DIR *dp;
    struct dirent *dent;

    dp = opendir(".");

    while ((dent = readdir(dp))) {
        printf("Name : %s ", dent->d_name);
        printf("Inode : %d\n", (int)dent->d_ino);
    }

    closedir(dp);
}

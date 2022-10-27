#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    struct stat buf;

    // 1 출력
    stat("password.txt", &buf);
    printf("Link Count before link()=%d\n", (int)buf.st_nlink);	   
    // 하드 링크 생성: 기존파일과 동일한 inode
    // inode에 저장되는 링크 개수 증가
    link("password.txt", "password.ln");

    // 2 출력 
    stat("password.txt", &buf);
    printf("Link Count after link()=%d\n",(int)buf.st_nlink);

    //심벌릭 링크 생성: 기존 파일에 접근할 수 있는 다른 파일 생성
    symlink("password.txt", "password.sln");

    // 2 출력 : symlink는 원본파일의 링크 개수를 증가 X
    stat("password.txt",&buf);
    printf("Link Count of password.txt=%d\n",(int)buf.st_nlink);
    
    // 2 출력 : stat함수에 심벌릭 링크를 넘겨도 원본 파일 정보가 날라옴
    stat("password.sln",&buf);
    printf("Link Count of password.sln=%d\n",(int)buf.st_nlink);
    
    // 1 출력 : 심벌릭 링크 자체의 파일 정보를 검색하기에 1
    lstat("password.sln", &buf);
    printf("Link Count of password.sln itself=%d\n", (int)buf.st_nlink);

    return 0;
}

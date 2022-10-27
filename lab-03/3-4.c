#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

//파일 정보를 검색하는 stat()함수 사용해보는 프로그램
//stat 구조체에 password.txt 파일의 정보를 담고 찍어본다!!
int main(void) {
    struct stat buf;

    stat("password.txt", &buf);//inode의 정보를 buf에 담는다

    printf("Inode = %d\n",(int)buf.st_ino);
    printf("Mode = %o\n",(unsigned int)buf.st_mode);
    printf("Nlink = %o\n",(unsigned int)buf.st_nlink);
    printf("UID = %d\n",(int)buf.st_uid);
    printf("GID = %d\n",(int)buf.st_gid);
    printf("SIZE = %d\n",(int)buf.st_size);
    printf("Atime = %d\n",(int)buf.st_atime);
    printf("Mtime = %d\n",(int)buf.st_mtime);
    printf("Ctime = %d\n",(int)buf.st_ctime);
    printf("Blksize = %d\n",(int)buf.st_blksize);
    printf("Blocks = %d\n",(int)buf.st_blocks);

    return 0;
}


#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    DIR *dp; 
    struct dirent *dent; //후에 readdir()로 인해 디렉터리에 있는 항목의 정보를 가리키게 됨 

    if ((dp = opendir(".")) ==NULL) { //현재 디렉터리 열기
	perror("opendir: .");
	exit(1);
    }
    while ((dent = readdir(dp))) { //디렉토리 읽어서 이름과 아이노드 출력 
	printf("Name : %s ",dent->d_name);
	printf("Inode : %d\n",(int)dent->d_ino);
    }

    closedir(dp);

    return 0;
}

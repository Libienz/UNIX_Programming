#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dp;
    struct dirent *dent; //?? 요거 공부 
    long loc;

			// 디렉토리 스트림과 디렉토리 포인터는 다르드아!!
			// dp가 가리키는 폴더 정보의 내부에 스트림 정보가 있나 ..?
    dp = opendir("."); //현재 디렉터리 열어라

    printf("Start Position : %ld\n", telldir(dp)); //디렉토리 스트림에서 현재 위치 찍어보기
    while ((dent = readdir(dp))) {  // 요 반복문이 빠져나올 수 있는 이유가 멀까 ..? NULL이 리턴되기 때문??
        printf("Read : %s -> ", dent->d_name);
        printf("Cur Position : %ld\n", telldir(dp));
    }

    printf("** Directory Position Rewind **\n");
    rewinddir(dp);
    printf("Cur Position : %ld\n", telldir(dp));

    printf("** Move Directory Pointer **\n");
    readdir(dp);
    loc = telldir(dp);
    seekdir(dp, 10); //옮겨가라 
    printf("after seek Cur Position : %ld\n", telldir(dp)); //하나의 엔트리를 옮겨가고 찍은 것

    dent = readdir(dp);
    printf("Read : %s \n", dent->d_name);

    closedir(dp);
}

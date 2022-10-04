#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *cwd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("1.Current Directory : %s\n", cwd);

    chdir("bit");//그런 디렉토리가 넘어가는 데에 실패했는데도 다음 라인이 수행된다...?
		 //사실 나머지들도 똑같음 성공하면 0 실패하면 -1
		 //그리고 쉘 프로세스에서는 안넘어감
		//와이..? -> 쉘 프로세스에서 2-6이라고 하는 것을 위해 프로세스를 만든다. 
		//즉 프로그램안에서만 잠깐 바꿨다가 돌아온다. 
		//바뀐 상태를 남기고 싶으면 ?? 익스포팅? 이스케이핑? 나중에 배울 기회가 있을 것임 
    cwd = getcwd(NULL, BUFSIZ);
    printf("2.Current Directory : %s\n", cwd);

    free(cwd);
}

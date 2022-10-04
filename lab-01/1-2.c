#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* linux.txt 파일이 존재하는지 여부를 access() 함수로 확인하는 코드  */

int main(void)
{
	//access 함수는 F_OK모드로 사용했을 때 파일의 존재 여부를 확인
	//access 함수가 성공한다면 0, 실패하면 -1을 return 
	if (access("linux.txt", F_OK) == -1) { // access 함수가 실패한다면
		perror("linux.txt"); //오류 메세지를 stderr로 출력! 오류가 발생한 바로 다음에 적절히 호출되어야 함
		exit(1); //에러로 인한 비정상 프로세스 종료임을 운영체제에 알림!
	}
	return 0;
}


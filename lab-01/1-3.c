#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str; //str 문자열 char의 포인터형으로

	
//	str = malloc(sizeof(char) * 20); //str에 char자료형의 20배 크기의 메모리 동적할당
	//str은 이제 할당받은 메모리의 시작주소를 가리킴

	strcpy(str,"Hello"); //str에 "Hello" 문자열을 복사
	printf("%s\n", str); //str 출력

	strcpy(str, "Good morning"); //str에 "Good morning" 문자열을 복사
	printf("%s\n", str); //str 출력

	free(str); //str이 가지고 있던 동적메모리 반환 
	return 0;
}

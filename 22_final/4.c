#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//qsort에 넘길 정렬 기준
//알파벳 순서
int alp_order (const void *s1, const void *s2) {
    return strcmp((char *)s1,(char *)s2);
}

//qsort에 넘길 정렬 기준
//알파벳 역순
int reverse_alp_order(const void *s1, const void *s2) {
    return strcmp((char *)s2, (char *)s1);
}

int main(int argc, char* argv[]) {

    int i;
    //argv를 temp에 후에 복사할 것 argv의 0번째 인자인 경로 제외
    char temp[argc-1][10];

    if (argc ==1) {
	printf("이 프로그램은 명령행 인자가 필요합니다\n");
	return 1;
    }


    printf("Queue Order\n");
    //first in first out 
    //인덱스가 작은 것부터 꺼내면 Queue Order
    for (i=1; i<argc; i++) {
	printf("%s ",argv[i]);

    }

    printf("\n\nStack Order\n");
    //Last in first out 
    //인덱스가 큰 것부터 꺼내면 Stack Order
    for (i=argc-1; i>0; i--) {
	printf("%s ",argv[i]);
    }

    //알파벳순, 알파벳 역순 출력은 qsort 정렬 사용할 것 
    //우선 temp에 argv를 복사해 넣는다.   
    for (i = 1; i<argc; i++) {
	strcpy(temp[i-1],argv[i]);
    }


    //알파벳 순서로 정렬되도록 compare 방법을 qsort에 전달 (alp_order)
    //알파벳 순으로 정렬된 temp배열을 출력한다.
    printf("\n\nAlphabetical order\n");
    qsort(temp, sizeof(temp) / sizeof(temp[0]), sizeof(temp[0]), alp_order);
    for (i = 0; i<argc; i++) {
	printf("%s ",temp[i]);
    }
    
    //알파벳 역순으로 정렬되도록 compare 방법을 qsort에 전달 (reverse_alp_order)
    //알파벳 역순으로 정렬된 temp배열을 출력한다.
    printf("\n\nreverse Alphabetical order\n");
    qsort(temp, sizeof(temp) / sizeof(temp[0]), sizeof(temp[0]), reverse_alp_order);
    for (i = 0; i<argc; i++) {
	printf("%s ",temp[i]);
    }
    printf("\n");

    return 0;
}


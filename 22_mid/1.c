#include <stdio.h>
#include <stdlib.h>

/* 명령행 인자로 공급되는 숫자들을 합하여 출력하는 프로그램 */

int main(int argc, char* argv[]) { //명령행 인자 받을 것임

    int i; //for 반복문에 사용
    double sum=0; //결과 값
    
    //argv에 담겨있는 명령행 인자들을 더하는 과정 
    for (i =1; i<argc; i++) { //argv[0]값은 제외(실행 파일 명이기 때문)
	sum+=atof(argv[i]); //atof: str -> double
    }

    printf("%lf\n", sum); //출력 
    return 0;
}

		

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* 
명령행에서 주어진 옵션에 따라 덧셈 혹은 곱셈을 하는 프로그램

	-a 는 인자들의 덧셈을 출력하도록 하는 옵션
	./1-6 -a 10 20 30 이와 같이 사용했다면 10 + 20 + 30의 결과를 출력하게 된다.
	-m 은 인자들의 곱을 출력하도록 하는 옵션
	./1-6 -m 10 20 30 이와 같이 사용했다면 10 * 20 * 30의 결과를 출력하게 된다. 

명령행 인자를 일일이 -a와 같은지, 혹은 -m과 같은지 비교연산하여  어떠한 옵션이 사용되었는가를 분석할 수도 있지만 getopt함수를 사용하여 옵션처리를 쉽게 할 수 있다. 

getopt()함수의 원형은 다음과 같다
int getopt(int argc, char *const argv[], const char* option);
첫번째 인자와 두번째 인자는 main함수의 argc와 argv를 그대로 전달하고 세 번째의 option에 제공하고자 하는 옵션을 전달함으로써 사용가능하다. 예를 들어 옵션으로 'a'와 'l'을 제공하고자 한다면 option에 "al"을 전달하면 된다. 어떠한 옵션에 인자가 필요하다면 ':'을 추가하면 된다.

getopt()함수는 argv를 살펴보다가 옵션을 발견하면 해당 옵션의 아스키코드값을 반환하며 끝까지 옵션을 발견하지 못한다면 EOF(-1)를 return 한다. 발견한 옵션이 뒤에 인자가 필요하다고 선언된 경우에  인자 중 첫번째는 이미 선언한 optarg에 저장된다. 다만 현재의 코드에서처럼 옵션에 필요한 인자가 여러개인 경우 다음에 처리해야 할 argv 인덱스를 저장하고 있는 외부 변수 optind를 활용하여 argv에 접근, 여러개의 인자를 처리할 수 있다.  
*/


int main(int argc, char *argv[]) {

	int n;
	extern char *optarg; //인자가 필요한 옵션의 인자를 저장하는 외부 변수
	extern int optind; //다음에 처리해야 할 argv의 index를 저장하는 외부 변수

	long r; // 옵션에 따라 덧셈 혹은 곱셈의 결과가 누적될 변수

	while((n = getopt(argc, argv, "a:m:")) != -1) { // 사용가능한 옵션은 -a와 -m
							// 두 옵션 모두 입력인자를 필요로 함을 콜론으로 표현
							// 끝까지 옵션이 발견되지 않는다면 getopt()함수는 -1을 리턴 

		switch (n) {
			case 'a' : //-a 옵션 발견! 
				r=0;
				for (--optind; optind < argc; optind++) //옵션 인자들을 모두 더하기 위해서 optind로 argv 접근! 
									//optind는 getopt가 "-a"를 발견하고 이미 첫번째 옵션 인자를 optarg에 
									//담는 과정을 거쳤기에 두번째 옵션인자를 가리키고 있음   
									//전위 연산--optind를 통해 첫번째 옵션인자부터 연산이 가능하도록 한것!
					r = r + atol(argv[optind]); //누적 덧셈 수행
			break; 
			case 'm' : //-m 옵션 발견!
				r=1;
				for (--optind;  optind < argc; optind++)
					r = r * atol(argv[optind]); //누적 곱셈 수행
			break;
		}

		printf("res = %ld\n", r);// 결과 출력
	}
}

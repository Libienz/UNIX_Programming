#!/bin/bash

#2-5.sh 인자 두개를 더하는 함수 사용하는 프로그램

sum(){ #함수 정의 부분 
	((sum=$1+$2)) # 인자 두개 더하고 sum변수에 대입연산
	return $sum 
}

sum 10 20 #함수 호출 부분
echo the result is $? #마지막 실행된 명령어의 종료 상태(return 값 보임)

exit 0

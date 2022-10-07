#!/bin/bash 

# 2-1.sh: 명령행 인자처리 실습 프로그램

#입력인자 개수 출력
echo number of arguments is $#

#입력인자 모두 출력
echo arguments are $*

#0번째 입력인자 즉 현재 셸 스크립트의 이름 
echo command is $0 

#첫번째 입력인자 출력
echo first argument is $1

#shift n: 인자를 n만큼 shift (왼쪽으로) 
#n을 쓰지 않았다면 default 1로
#shift 명령은 0번째 매개변수에는 영향을 주지 않음 
#명령줄을 벗어나 밀린 인자들은 소멸
shift 

echo number of arguments is $#
echo arguments are $*
echo command is $0
echo first argument is $1

exit 0

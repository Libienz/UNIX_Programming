#!/bin/bash

#2-2.sh: 명령행 인자로 받은 두 숫자 사칙연산 수행하는 프로그램


# 연산결과를 바로 출력하는 형식 $(( ))
echo $1 + $2 = $(($1+$2)) 
echo $1 - $2 = $(($1-$2))
echo $1 '*' $2 = $(($1*$2)) # '*': *을 특수문자로 이해하지 않도록 
echo $1 / $2 = $(($1/$2))

exit 0



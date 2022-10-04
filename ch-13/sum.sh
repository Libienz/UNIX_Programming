#!/usr/bin/bash

# 반복문을 돌며 합계를 계산하는 쉘 프로그램
# $* 이거는 입력인자 명령행에서 받는 것일까?
sum=0

for i in 1 2 3 4
do 
	((sum+=i))
done

echo $sum



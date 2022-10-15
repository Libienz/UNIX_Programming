#!/usr/bin/bash

# 명령행 인자들의 합 구하는 프로그램


sum=0
for num in $*
do
	((sum+=num))
done

echo $sum

	

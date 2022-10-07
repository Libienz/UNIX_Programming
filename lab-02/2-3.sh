#!/bin/bash

#2-3.sh: while 이용 구구단 9단까지 출력하는 프로그램


((front=2)) # 구구단에서 앞의 숫자
((back=1)) # 구구단에서 뒤의 숫자

while (( front<=9 )) #9단까지
do
	while(( back<=9 ))
	do
		echo -n $((front*back)) " " #곱셈 출력 후  뒤에 공백
		(( back+= 1 )) 
	done
	(( back = 1)) #다음 단 시작 위해서 back 1로 
	(( front+=1 ))#다음 단 시작 위해서 front 1증가
	echo #줄바꿈 역할 수행 
done

exit 0			

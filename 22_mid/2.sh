#!/bin/bash
#100보다 작은 피보나치 수열을 차례로 출력하는 프로그램

count=100

i=0 #해당 시점에 출력할 n번째 항
j=1 #n+1번째 항
k=0 #n+2번째 항을 계산하기 위한 변수 (후에 계산되고 n+1번째 항인 j로 밀려남) 
while(( i<100 ))
do
	echo $i #n번째 항 출력

	#출력 했으니 한단계 밀어낸다 
	((k=i+j)) #n+2번째 항을 계산 
	((i=j)) #n+1번째 항은 이제 n번째 항
	((j=k)) #n+2번째 항은 이제 n+1번째 항
done


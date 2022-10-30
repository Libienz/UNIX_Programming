#!/bin/bash
#100보다 작음 피보나치 수열을 구하는 프로그램

count=100

i=0
j=1
k=0
while(( i<100 ))
do
	echo $i
	((k=i+j))
	((i=j))
	((j=k))
done


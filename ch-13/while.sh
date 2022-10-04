#!/usr/bin/bash

# while 실습


count=1
sum=0

while ((count<=100000))
do 
	((sum+=count))
	((count+=1))
done

echo "Sum(1~100000) : $sum"


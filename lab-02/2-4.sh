#!/bin/bash

echo -n "Is is morning?" #-n 옵션은 줄바꿈 생략
read answer #사용자의 답 읽어와서 answer 변수에

case $answer in #answer의 값에 따라 스위치
	y* | Y* ) echo Good morning ;; #answer가 y로 시작하는 경우
	n* | N* ) echo Have a good day ;; #answer가 n으로 시작하는 경우
	*) echo Sorry your answer is not proper ;; #일치하는 값 없을 경우 디폴트
esac 

exit 0

#!/bin/bash

# 메뉴를 생성하는 select문 실습

select cmd in pwd date quit
do 
	case $cmd in # 1,2,3으로는 안되는데 왜지 ?
		pwd) pwd ;;
		date) date ;;
		quit) break ;; # break 머지?? ->
		*) echo wrong number ;; 
	esac
	REPLY=-1 #null -> ???
done 

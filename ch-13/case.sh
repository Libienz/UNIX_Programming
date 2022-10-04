#!/usr/bin/bash
#
# test case
#

echo "Select command : "
read cmd

case $cmd in
	[0-9]) # 0~9 digit 일 때
		date;;
	l|L)
		ls
		;;
	p|P)
		pwd;;

	*)	# 여기가 디폴트!
		echo "select right command."
		;;
esac


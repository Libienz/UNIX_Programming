#include <time.h>
#include <stdio.h>

int main() {

	char* wday[7] = {"일","월","화","수","목","금","토"};
	struct tm *tm;
	time_t timep;

	time(&timep); //timep에 1970부터 흐른 초 저장
	tm = localtime(&timep);
	printf("%d. %d. %d. (%s) %d:%d:%d KST\n", 1900+(tm->tm_year), (tm->tm_mon)+1, tm->tm_mday, wday[tm->tm_wday], tm->tm_hour, tm->tm_min, tm->tm_sec);
	return 0;
}


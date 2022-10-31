#include <time.h>
#include <stdio.h>

int main() {

    //dow: day of week 요일 담는 배열 -> 요일이 숫자로 리턴되기에 적절히 쓰	기 위함임
    char* dow[7] = {"일", "월", "화", "수", "목", "금", "토"};
    struct tm *tm; //local time이 반환하는 객체를 받을 변수 
    time_t timep;

    time(&timep); // 초단위 시간을 timep에 담아준다.
    tm = localtime(&timep); //초 단위 시간을 분해해서 구조체에 담아준다

    //출력 할 때 주의사항 
    //1. tm 구조체의 tm_year는 연도-1900을 담고 있다
    //2. tm 구조체의 tm_mon은 0-11이다. 0이 1월
    //3. tm 구초제의 tm_wday 즉, 요일은 숫자이다. (0~6 : 0이 일요일) 
    printf("%d. %d. %d. (%s) %d:%d:%d KST\n", 1900+(tm->tm_year), tm->tm_mon+1, tm->tm_mday, dow[tm->tm_wday], tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}

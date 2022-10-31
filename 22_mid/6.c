#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define SIZE 5 //학생 수 

/* 저수준으로 읽어들어와 가공하고 입출력하거나 dup통해 redirection하는 등등
   여러 방법이 있겠지만 해당 프로그램은 형식 기반 입력과 출력을 사용하기 위해 고수준의 파일 입출력으로 해결했음을 알림
*/

//후에 있을 정렬을 위해서 학생 구조체를 만듬
typedef struct student_info {
    char name[10];
    int kor_score;
    int math_score;
    int eng_score;
    int sum;
    double ave;
} student_info;


//학생 구조체의 배열을 받아서 정렬한다.  (sum 순으로)
//정렬은 버블 정렬
void mysort(student_info* st_arr) {
    
    student_info tmp;

    for (int i=0; i<SIZE-1; i++) {
	for (int j=i+1; j<SIZE; j++) {
	    if (st_arr[i].sum < st_arr[j].sum) {
		tmp = st_arr[i];
		st_arr[i] = st_arr[j];
		st_arr[j] = tmp;
	    }
	}
    }
}

//학생들의 구조체를 전역  배열로 만듬 
//후에 정렬할 것 
student_info st_arr[SIZE];

int main(void) {

    FILE *rfp,*wfp; 
    int ind = 0; //st_arr에 학생 저장하기 위한 인덱스 
    char name[10];
    int kor_score, math_score, eng_score, sum;
    double ave;
    int n;
    
    //아래 변수는 과목별 평균을 위해
    int k_sum =0;
    int m_sum =0;
    int e_sum =0;



    //읽기로 6.dat 오픈
    if ((rfp = fopen("6.dat", "r")) == NULL) {
	perror("fopen: 6.dat");
	exit(1);
    }

    //쓰기로 6.out 오픈
    if ((wfp = fopen("6.out", "w")) == NULL) {
	perror("fopen 6.out");
	exit(1);
    }

    //6.out 첫줄 scheme 출력
    fprintf(wfp, "     KOR     MATH     ENG     sum     ave\n");




    //파일 읽을 다 읽을 때 까지 서식에 맞추어 읽어오고 변수에 저장  
    while((n=fscanf(rfp," %s %d %d %d ", name, &kor_score, &math_score, &eng_score)) != EOF) {
	
	k_sum+=kor_score;
	m_sum+=math_score;
	e_sum+=eng_score;
	sum = kor_score+math_score + eng_score;
	ave = (double)(sum)/3.0;

	//scope 하나 만들어서 변수가 임시변수 사용
	//여기에 st구조체 만들고 학생 배열에다가 집어넣음 
	{
	    student_info st = {" ", kor_score, math_score, eng_score, sum, ave};
	    strcpy(st.name,name);
	    //printf("name=%s\n",st.name);
	    st_arr[ind] = st;
	    ind++;
	}
    }

    //정렬
    mysort(st_arr);

    //학생 배열 모두 돌면서 서식에 맞추어 출력 
    for (int i=0; i<SIZE; i++) {
	fprintf(wfp, "%s   %d      %d     %d     %d     %.1lf\n",st_arr[i].name, st_arr[i].kor_score, st_arr[i].math_score, st_arr[i].eng_score, st_arr[i].sum, st_arr[i].ave);
    }
   
    //과목별 평균 출력 
    fprintf(wfp, "       %.1lf    %.1lf    %.1lf\n",((double)k_sum/(double)SIZE), (double)m_sum/(double)SIZE, (double)e_sum/(double)SIZE );

    fclose(wfp);
    fclose(rfp);
    return 0;
}

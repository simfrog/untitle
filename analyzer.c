#include<stdio.h>


int main()
{
	char fname[100] = "time.log";
	FILE* fp;
	int min, sec;

	fp = fopen(fname, "r");
	
	if (fp == NULL) {
		printf("Failed to open file\n");
		return 0;
	}

	int a_min=0;
	int a_sec=0;
	int count=0;
	int ar_time=0;
	int m_sec=0;

	while(!feof(fp)) {
		fscanf(fp, "(%d:%d)\n", &min, &sec);
		printf("min = %d, sec = %d\n", min, sec);
		// get min, max, avg access time 
		a_min+=min;
		a_sec+=sec;
		count++;
		sec+=min*60;
		
		if(m_sec<sec)
			m_sec=sec;
	}

	ar_time=((a_min*60)+a_sec)/count;

	printf("평균 접속시간:%d분 %d초\n",ar_time/60,ar_time-((ar_time/60)*60));
	printf("오래 접속시간:%d분,%d초\n",m_sec/60,m_sec-((m_sec/60)*60));
	
	return 0;
}


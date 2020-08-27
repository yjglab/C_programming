#include <stdio.h>
//다섯 학생의 과목 두개 점수의 합계 구하기 프로그램. yjg-lab 
int main(void)
{
	int score[5][2];
	int total[2] = { 0, };
	int i;
	
	for(i = 0; i < 5; i++)
	{
		printf("%d번 학생의 국어, 영어 점수 : ", i + 1);
		scanf("%d %d", &score[i][0], &score[i][1]);
	}
	
	for(i = 0; i < 5; i++)
	{
		total[0] += score[i][0];
		total[1] += score[i][1];
	}
	
	printf("\n\n5명의 국어 점수 합계 : %d\n", total[0]);
	printf("5명의 영어 점수 합계 : %d\n", total[1]);
	
	return 0;
} 

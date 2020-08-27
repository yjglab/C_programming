#include <stdio.h>
//입력한 정수의 개수만큼 합을 구해주는 프로그램입니다. yjg lab
int main(void)
{
	int number, x, i, sum = 0;
	printf("정수의 개수를 입력하세요 : ");
	scanf("%d", &number);
	for(i = 0; i < number; i++)
	{
		printf("정수의 값을 입력하세요 : ");
		scanf("%d", &x);
		sum += x;
	}
	printf("모든 정수의 합은 %d입니다.\n", sum);
	continue;
	return 0;
}

#include <stdio.h>

//100단까지 입력되어 있
int main(void)
{
	int x, i;
	printf("곱셈표를 출력할 수를 입력하세요 : ");
	scanf("%d", &x);
	for(i = 0; i <= 100; i++)
	{
		printf("%d X %d = %d\n", x, i, x * i);
	} 
	return 0;
}

#include <stdio.h>

//구구단 출력기입니다. 100단까지 입력되어 있고 추가 가능합니다. yjg lab
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

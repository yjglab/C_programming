#include <stdio.h>

int main(void)
{
	char z;
	int x, y;
	while(1)
	{
		printf("계산할 수식을 입력하세요 : ");
		scanf("%d %c %d", &x, &z, &y);
		if(z == '+')
		{
			printf("%d %c %d = %d\n", x, z, y, x + y);
		}
		else if(z == '-')
		{
			printf("%d %c %d = %d\n", x, z, y, x - y);
		}
		else if(z == '*')
		{
			printf("%d %c %d = %d\n", x, z, y, x * y);
		}
		else if(z == '/')
		{
			printf("%d %c %d = %d\n", x, z, y, x / y);
		}
		else if(z == '%')
		{
			printf("%d %c %d = %d\n", x, z, y, x % y);
		}
		else
		{
			printf("올바른 수식이 아닙니다.\n");
		}
		getchar();
		printf("계산기를 종료할까요? (O/X) ");
		getchar();
		scanf("%c", &z);
		if(z == 'x' || z == 'X')
		{
			continue;
		}
		else if(z == 'o' || z == 'O')
		{
			break;
		}
		else
		{
			printf("\n");
			continue; 
		}
	}
	return 0; 
}

#include <stdio.h>

// int월 int일 을 입력하면 값이 출력됩니다! yjg.lab
int getDays(int month, int day)
{
	int i, sum = 0;	
	for(i = 1; i < month; i++)
	{
		if(i == 2)
		{
			sum += 28;
		}
		else if(i == 8)
		{
			sum += 31;
		}
		else if(i == 9)
		{
			sum += 30;
		}
		else if(i == 10)
		{
			sum += 31;
		}
		else if(i == 11)
		{
			sum += 30;
		}
		else if(i == 12)
		{
			sum += 31;
		}
		else if(i % 2 == 0)
		{
			sum += 30;
		}
		else
		{
			sum += 31;
		}
	}
	return sum + day;
} 

int main(void)
{
	int month, day;
	scanf("%d월 %d일", &month, &day);
	printf("1월 1일부터 %d월 %d일까지의 합은 %d일입니다.", month, day, getDays(month, day));
}

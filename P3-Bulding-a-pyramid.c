#include <stdio.h>

int main()
{
	int floor;
	printf("쌓으실 층 수를 입력하세요. ");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++)
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
		for (int a = 0; a < i*2+1; a++)
		{
			printf("▲");
		}
		printf("\n");
	}
	return 0;
}
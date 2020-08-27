#include <stdio.h>
#define NUMBER 5

int main(void)
{
	int array[NUMBER];
	int i, oddMax, evenMax;
	oddMax = 0;
	evenMax = 0;
	for(i = 0; i < NUMBER; i++)
	{
		scanf("%d", &array[i]);
		if(array[i] % 2 == 0)
		{
			if(evenMax < array[i])
			{
				evenMax = array[i];
			}
		}
		else
		{
			if(oddMax < array[i])
			{
				oddMax = array[i];
			}
		}

	}
	printf("홀수 최댓값은 %d이며, 짝수 최댓값은 %d입니다.\n", oddMax, evenMax);
	return 0;
}

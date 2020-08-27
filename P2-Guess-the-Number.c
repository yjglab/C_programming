#include <stdio.h>
#include <time.h>

int main()
{
	/*srand(time(NULL));*/
	int N; /*= rand() % 100 + 1;*/
	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &N);
	int answer; // 정답
	int chance = 5; // 기회 5번
	while (1)
	{
		printf("  남은 기회는 %d번입니다.\n", chance--);
		printf("숫자를 맞추어 보세요. [1 ~ 100] : ");
		scanf_s("%d", &answer);

		if (answer > N)
		{
			printf("\nDOWN▼\n\n");
		}
		else if (answer < N)
		{
			printf("\nUP▲\n\n");
		}
		else if (answer == N)
		{
			printf("\n정답!\n\n");
			break;
		}
		else
		{
			printf("숫자를 입력해야 합니다!");
		}

		if (chance == 0)
		{
			printf("기회를 모두 쓰셨네요! 실패했습니다.\n\n");
			break;
		}
	}
	return 0;
}
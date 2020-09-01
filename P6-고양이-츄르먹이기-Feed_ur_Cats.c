#include <stdio.h>
#include <time.h>

// 나도 고양이 있어 by. yjglab

int level;
int hungerIndex[5];
int* ptrcat;

void showCats();
void initData();
void decreaseIndex(long passedTime);
int checkCatsAlive();


int main(void)
{
	//intro
	printf("\n\n──────────────────   고양이 츄르먹이기   ──────────────────\n\n");
	printf("\n\n\t  ... 시작하려면 Enter키를 누르세요 ...\n\n");
	getchar();

	printf("\n\n────────   1: 게임시작  2: 게임방법  3: 게임종료   ─────────\n\n\n");
	int start;
	scanf_s("%d", &start);

	if (start == 1)
	{
		printf("\n\n──────────────────   게임을 시작합니다   ──────────────────\n\n");
	}
	else if (start == 2)
	{
		printf("\n\n──────────────────        게임 방법       ──────────────────\n\n");
		printf("\n\n 당신은 5마리의 고양이를 키우고 있다.\n 밥을 주지 않아 고양이들의 헝거지수가 떨어지고 있다!\n 고양이들에게 츄르를 먹여서 배고파하지 않도록 만들어라!\n 헝거지수가 0이 되면 고양이들은 죽게된다.\n\n\n\n");
		printf("────────────────────────────────────────────────────────────\n\n");
	}
	else if (start == 3)
	{
		printf("\n\n──────────────────   게임을 종료합니다   ───────────────────\n\n");
		exit(0);
	}
	else
	{
		printf(" \n\n 입력 오류 ! (1~3) 숫자만 입력해주세요 !\n");
		exit(0);
	}
	getchar();
	printf("\n\n\n\t  ... 시작하려면 Enter키를 누르세요 ...\n\n\n\n");
	getchar();
	printf("────────────────────────────────────────────────────────────\n\n\n\n\n\n");

	long startTime = 0;
	long totalPassedTime = 0; // 게임 진행시간
	long prvPassedTime = 0; // 마지막으로 먹이 준 시간으로 부터 흐른 시간

	int N; // 몇번 고양이에게 츄르를.
	initData();

	ptrcat = hungerIndex;

	startTime = clock(); 

	while (1)
	{
		showCats();
		printf("어떤 고양이에게 츄르를 줄래? ");
		scanf_s("%d", &N);

		if (N < 1 || N > 5) // 1~5 외 숫자 오류 체크
		{
			printf("\n\n※ 고양이는 1번~ 5번밖에 없어요 ※\n\n\n");
			continue;
		}

		totalPassedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("\n\n\n\n\n\n\n\n │  진행 시간 : %ld초 경과               \n", totalPassedTime);

		prvPassedTime = totalPassedTime - prvPassedTime;
		printf(" │  마지막으로 츄르 먹인 시간 : %ld초 전 \n\n", prvPassedTime);

		decreaseIndex(prvPassedTime); // 헝거지수 감소

		if (ptrcat[N - 1] <= 0) // 고양이 헝거지수가 0이면
		{
			printf("\n\n※ %d번 고양이가 죽었습니다.. ※\n\n\n\n", N);
		}
		else if (ptrcat[N - 1] + 1 < 100)
		{
			printf("%d번 고양이에게 츄르를 먹였습니다\n\n", N);
			ptrcat[N - 1] += 2; // 헝거지수 추가
		}

		if (totalPassedTime / 15 > level - 1) // level 시스템
		{
			level++;
			printf("\n\n\n★ 고양이들이 츄르를 먹고 대사량이 %d000 Kcal에서 %d000 Kcal로 늘었습니다 ★\n            대사량 증가 : 이제 고양이들이 더욱 더 배고파합니다\n\n\n\n\n", level - 1, level);

			if (level == 5)
			{
				printf("\n\n★ 고양이들의 대사량이 5000 Kcal를 달성하여 아주 만족스러워 합니다! ★\n                이제 츄르를 그만줘도 될 것 같습니다\n\n");
				printf("\n\n──────────────────   게임을 종료합니다   ───────────────────\n\n");
				exit(0);
			}

		}

		if (checkCatsAlive() == 0) // 전체 고양이 생존 여부 확인
		{
			printf("\n\n※ 모든 고양이들이 배고파서 죽어버렸습니다.. ※\n\n");
			printf("\n\n──────────────────   게임을 종료합니다   ───────────────────\n\n");
			exit(0);
		}

		prvPassedTime = totalPassedTime;
	}

	return 0;
}

void initData()
{
	level = 1;
	for (int i = 0; i < 5; i++) // 고양이 5마리
	{
		hungerIndex[i] = 100; // 헝거지수 (0 - 100)
	}
}

void showCats() // 고양이 나열 and 현재 헝거지수 알림
{
	printf("고양이  %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5);
	printf("헝거지수");
	for (int i = 0; i < 5; i++)
	{
		printf("  %3d ", hungerIndex[i]);
	}
	printf("\n\n");
}

void decreaseIndex(long passedTime)
{
	for (int i = 0; i < 5; i++)
	{
		hungerIndex[i] -= (level * 2 * (int)passedTime); // 난이도 조절 값
		if (hungerIndex[i] < 0)
		{
			hungerIndex[i] = 0;
		}
	}
}

int checkCatsAlive()
{
	for (int i = 0; i < 5; i++)
	{
		if (hungerIndex[i] > 0)
			return 1; // true -> 계속 진행
	}
	return 0;
}

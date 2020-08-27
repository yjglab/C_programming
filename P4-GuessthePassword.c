#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main()
{
	srand(time(NULL));
	int count = 0;
	
	printf("■비밀번호가 걸린 방에 갖혀버렸다! 문제를 풀어 방을 탈출해!■\n\n\n");
	for (int i = 1; i < 6; i++)
	{	
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);

		/*printf("%d X %d의 값은? ", num1, num2);*/
		showQuestion(i, num1, num2);

		int answer;
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("\n■게임을 종료합니다■\n\n\n\n");
			exit(0);
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
			printf(" 영원히 그 방에서 썩으세요!\n\n");
			break;
		}
	}

	printf("\n\n■당신은 5개의 비밀번호 중 %d개를 맞혔습니다■\n", count);
	return 0;
}

int getRandomNumber(int level)
{
	//level이 증가할수록 *10+5로 난이도 증가. +5은 *0 방지용
	return rand() % (level * 10) + 5;
}
void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n-----%d번째 비밀번호-----\n\n", level);
	printf("\n\t%d X %d는?\n\n", num1, num2);
	printf("------------------------\n");
	printf("\n비밀번호를 입력하세요 (종료하기 : -1) >>");
}
void success()
{
	printf("\n\n 정답입니다! 비밀번호 1개를 해제했습니다.");
}
void fail()
{
	printf("\n\n 오답입니다!");
}
#include <stdio.h>
#include <time.h>


int arrayCard[4][5];
int checkCard[4][5];
char* strCard[10];

void initCardArray();
void initCardName();
void shuffleCard();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
int foundAllCard();
void printCard();
void printQuestion();




int main(void)
{
	//intro
	printf("\n\n─────────   음식 카드 맞추기   ─────────\n\n");
	printf("\n\n  ... 시작하려면 Enter키를 누르세요 ...\n\n");
	getchar();

	printf("\n────────────────────────────────────────\n");
	printf("  1: 게임시작  2: 게임방법  3: 게임종료 ");
	printf("\n────────────────────────────────────────\n\n");
	int start;
	scanf_s("%d", &start);

	if (start == 1)
	{
		printf("\n\n─────────   게임을 시작합니다   ────────\n\n");
	}
	else if (start == 2)
	{
		printf("\n\n────────        게임 방법       ────────\n\n");
		printf("\n\n 10종류의 음식 카드가 2장씩 총 20장이 있습니다.\n 게임을 시작하면 카드들은 모두 뒷면으로 바뀝니다.\n 카드를 2장 골라 같은 그림의 음식 카드를 맞추어보세요.\n\n\n");
		printf("────────────────────────────────────────\n\n");
	}
	else if (start == 3)
	{
		printf("\n\n─────────   게임을 종료합니다   ────────\n\n");
		exit(0);
	}
	else
	{
		printf(" \n\n 입력 오류 ! (1~3) 숫자만 입력해주세요 !\n");
		exit(0);
	}
	getchar();
	printf("\n\n    ... Enter키를 눌러 진행하세요 ...\n\n\n");
	getchar();
	printf("────────────────────────────────────────\n\n\n\n\n\n");

	srand(time(NULL));
	
	initCardArray();
	initCardName();
	shuffleCard();

	int failCount = 0;
	printCard();

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		
		printQuestion();
		printf("\n─────────────────────────────────────────\n");
		printf("\n\n뒤집을 카드 2개의 번호를 입력하세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
			continue;

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		if ((checkCard[firstSelect_x][firstSelect_y] == 0
			&& checkCard[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayCard[firstSelect_x][firstSelect_y]
				== arrayCard[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n\n\n\n\n\n\n\n●성공! [%s] 카드를 찾았습니다!●\n\n", strCard[arrayCard[firstSelect_x][firstSelect_y]]);
			checkCard[firstSelect_x][firstSelect_y] = 1;
			checkCard[secondSelect_x][secondSelect_y] = 1;
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\n▲실패! ");
			printf("고른 카드는 %d번 [%s] 카드와 ", select1, strCard[arrayCard[firstSelect_x][firstSelect_y]]);
			printf("%d번 [%s] 카드입니다▲", select2, strCard[arrayCard[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		if (foundAllCard() == 1)
		{
			printf("\n─────────────────────────────────────────\n");
			printf("\n\n★축하합니다! 모든 카드를 다 찾았습니다!★\n");
			printf("실패 횟수 : %d회\n\n", failCount);
			break;
		}
	}




	return 0;
}

void initCardArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayCard[i][j] = -1;
		}
	}
}

void initCardName()
{
	strCard[0] = "치킨";
	strCard[1] = "보쌈";
	strCard[2] = "족발";
	strCard[3] = "회무침";
	strCard[4] = "막국수";

	strCard[5] = "물갈비";
	strCard[6] = "삼겹살";
	strCard[7] = "튀김";
	strCard[8] = "순대";
	strCard[9] = "떡볶이";

}

void shuffleCard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayCard[x][y] = i;
		}
	}
}

int getEmptyPosition()
{
	while (1)
	{
		int randPos = rand() % 20;

		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayCard[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printCard()
{
	printf("\n아래 카드들의 배열을 기억하세요!\n");
	printf("\n─────────────────────────────────────────\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strCard[arrayCard[i][j]]);
		}
		printf("\n");
	}
	printf("\n─────────────────────────────────────────\n\n");
	printf("다 기억하셨다면 Enter키를 눌러 시작하세요!");
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n");
}

void printQuestion()
{
	printf("\n\n카드를 맞추어보세요!\n\n");
	printf("\n─────────────────────────────────────────\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		for (int j = 0; j < 5; j++)
		{
			if (checkCard[i][j] != 0)
			{
				printf("%8s", strCard[arrayCard[i][j]]);
			}
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllCard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkCard[i][j] == 0)
				return 0;
		}
	}
	return 1;
}
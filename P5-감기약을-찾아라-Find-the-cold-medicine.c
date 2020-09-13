#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	printf("\n\n ■■■■■■    감기약을 찾아라 by.yjglab    ■■■■■■ \n\n\n\n");
	printf("\n\t  ... 시작하려면 Enter키를 누르세요 ...\n");
	getchar();

	printf("\n\n\n ■■■ 게임 시작 : 1  게임 방법 : 2  게임 종료 : 3 ■■■ \n\n\n\n");
	int start;
	scanf_s("%d", &start);

	if (start == 1)
	{
		printf("\n\n\n ■■■■■■■■■  게임을 시작합니다  ■■■■■■■■■\n\n\n\n");
	}
	else if (start == 2)
	{
		printf("\n\n\n ■■■■■■■■■       게임방법      ■■■■■■■■■\n\n\n\n");
		printf(" 1번부터 4번까지 알약이 있다. 이 알약 중 하나는 감기를 낫게하는 특효약이다.\n 힌트를 보고 감기약이 몇번인지 맞혀라! \n\n\n\n");
	}
	else if (start == 3)
	{
		printf("\n\n\n ■■■■■■■■■  게임을 종료합니다  ■■■■■■■■■\n\n");
		exit(0);
	}
	else
	{
		printf(" \n\n 입력 오류 ! (1~3) 숫자만 입력해주세요 !\n");
		exit(0);
	}
	getchar();
	printf("\n\t  ... 시작하려면 Enter키를 누르세요 ...\n\n\n\n");
	getchar();

	int answer;
	int treatment = rand() % 4; // 알약 선택 (0-3)
	int cntShowPill = 0; // 이번 복용에서 먹을 알약 개수
	int prvShowPill = 0; // 이전 복용에서 먹은 알약 개수
	// 서로 보여주는 알약 개수를 다르게 하여 정답률 향상 

	// 총 3번의 알약 복용 기회
	for (int i = 1; i <= 3; i++)
	{
		int pill[4] = { 0, 0, 0, 0 }; //아직 선택되지 않은 알약 4개
		do
		{
			cntShowPill = rand() % 2 + 2; // 보여줄 알약 개수 (0-1, +2 -> 2, 3)
		} while (cntShowPill == prvShowPill); // 이전 복용에서 보여준 알약 개수와 다른 값이 나올때까지 반복
		
		int Included = 0; // 보여줄 알약 중 감기약 포함 여부(1 : 포함, 0 : 미포함)
		printf(" ▶ %d번째 복용 : ", i);
		
		for (int j = 0; j < cntShowPill; j++) // 보여줄 알약 번호 선택
		{
			int randPill = rand() % 4; // 0~3
			
			if (pill[randPill] == 0) // 아직 선택되지 않은 알약이면
			{
				pill[randPill] = 1; // 선택처리
				if (randPill == treatment)
				{
					Included = 1;
				}
			}
			else
			{
				j--; // 이미 선택된 알약이면, 중복이므로 다시 선택
			}
		}
		
		for (int k = 0; k < 4; k++)
		{
			if (pill[k] == 1) // bottle[k] k 인덱스는 위에서 선택된 값들 중 1인지 0인지를 비교
				printf("%d번 ", k + 1); 
		}
		printf("알약을 먹었습니다\n\n");
		
		if (Included == 1)
		{
			printf(" >> 감기 기운이 떨어졌습니다!\n\n");
		}
		else
		{
			printf(" >> 아무런 변화가 없습니다..\n\n");
		}

		printf("\n\n\n\t  ... 계속하려면 Enter키를 누르세요 ...\n\n\n\n");
		getchar();
	
	}

	printf(" Q. 감기약은 몇번 알약일까요? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다! 감기가 완전히 나았습니다!\n");
		printf("\n\n\n ■■■■■■■■■  게임을 종료합니다  ■■■■■■■■■\n\n");
	}
	else if (answer != treatment + 1)
	{
		printf("\n >> 오답입니다! 정답은 %d번 알약입니다\n", treatment + 1);
		printf("\n\n\n ■■■■■■■■■  게임을 종료합니다  ■■■■■■■■■\n\n");
	}
	//else
	return 0;
}

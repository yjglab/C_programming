#include <stdio.h>

int main()
{
	char name[50];
	printf("이름을 입력하세요. ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("나이를 입력하세요. ");
	scanf_s("%d", &age);

	double weight;
	printf("체중을 입력하세요. ");
	scanf_s("%lf", &weight);

	double height;
	printf("키를 입력하세요. ");
	scanf_s("%lf", &height);

	char job[50];
	printf("직업을 입력하세요. ");
	scanf_s("%s", job, sizeof(job));

	//신상정보 출력
	printf("\n\n---인원 정보---\n\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("체중 : %.2lf\n", weight);
	printf(" 키  : %.2lf\n", height);
	printf("직업 : %s\n", job);

	return 0;
}

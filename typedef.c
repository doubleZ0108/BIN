#include <stdio.h>
#include <stdlib.h>

//typedef��һ���÷�, struct��������ֿ�д�ɲ�д
//Stu������;��൱��   struct Student
//pStu������;��൱��  struct Student *
typedef struct Student
{
	char *name;
	int age;
	double score;
}STU,*pSTU;

//typedef�ڶ����÷�, �ȶ�����ṹ��,�������
struct Triangular
{
	int x, y, z;
};
typedef struct Triangular TRI, *pTRI;

int main(void)
{
	STU stu;
	stu.age = 10;
	pSTU pstu = malloc(sizeof*pstu);
	pstu->score = 95.5;

	TRI tri;
	tri.x = 3;
	pTRI ptri = malloc(sizeof*ptri);
	ptri->z = -7;


	free(pstu);
	free(ptri);

	system("pause");
	return 0;
}
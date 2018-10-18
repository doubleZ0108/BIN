#include <stdio.h>
#include <stdlib.h>

//typedef第一种用法, struct后面的名字可写可不写
//Stu这个类型就相当于   struct Student
//pStu这个类型就相当于  struct Student *
typedef struct Student
{
	char *name;
	int age;
	double score;
}STU,*pSTU;

//typedef第二种用法, 先定义完结构体,再起别名
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
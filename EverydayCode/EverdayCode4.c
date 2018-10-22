#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *prior;
	struct NODE *next;
};
struct NODE *CreateLink(int total)
{
	struct NODE *head = malloc(sizeof*head);
	struct NODE *move = head;
	move->next = NULL;

	for (int i = 0; i < total; ++i, move = move->next)
	{
		struct NODE *fresh = malloc(sizeof*fresh);
		fresh->data = i + 1;

		move->next = fresh;
		fresh->next = NULL;
		fresh->prior = move;
	}
	move->next = head->next;
	head->next->prior = move;

	return head;
}

void Josephus()
{
	int total, first, gap;
	printf("请输入总人数: ");
	scanf("%d", &total);
	printf("从第几个人开始报数: ");
	scanf("%d", &first);
	printf("每次从一报到几: ");
	scanf("%d", &gap);

	/*
	注意这一不能把gap对total取余
	想法是好的, 比如一共五个人,每次从1报到8, 感觉很浪费,不如直接每次报到3
	这样的错误在于: 每出列一个人, 总人数就会变少,相应的gap模除的量也要发生变化
	还是老老实实的多循环几次吧orz
	*/
	//gap %= total;

	struct NODE *head = CreateLink(total);
	struct NODE *move = head->next;
	struct NODE *save = NULL;

	for (int i = 1; i < first; ++i)
	{
		move = move->next;
	}

	while (move != move->next)
	{
		for (int i = 1; i < gap; ++i)
		{
			move = move->next;
		}
		save = move;
		move->prior->next = move->next;
		move->next->prior = move->prior;
		move = move->next;

		printf("%d ", save->data);
		free(save);
		save = NULL;

	}
	printf("%d\n", move->data);
	free(move);
	free(head);
	head = move = NULL;
}
int main(void)
{
	Josephus();

	system("pause");
	return 0;
}
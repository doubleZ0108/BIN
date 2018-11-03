/*
链表的设计
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct STU
{
	int num;
};
struct NODE
{
	struct STU data;
	struct NODE *next;
};

struct NODE *CreateLink(void)
{
	struct NODE *head = malloc(sizeof*head);
	if (head == NULL)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}
	struct NODE *move = head;
	move->next = NULL;

	int index;
	printf("你想输入几个结点: ");
	scanf("%d", &index);

	for (int i = 0; i < index; move = move->next, ++i)
	{
		struct NODE *fresh = malloc(sizeof*fresh);
		if (fresh == NULL)
		{
			printf("Memory Alloction Failed!\n");
			exit(-1);
		}

		move->next = fresh;
		fresh->next = NULL;
	}
	return head;
}
void InitLink(const struct NODE *head)
{
	struct NODE *move = head->next;
	
	for (int i = 1; move != NULL; move = move->next, ++i)
	{
		printf("请输入第%d个结点的信息: ", i);
		scanf("%d", &move->data.num);
	}
}
void OutputLink(const struct NODE *head)
{
	struct NODE *move = head->next;

	for (; move != NULL; move = move->next)
	{
		printf("[%d]->", move->data.num);
	}
	printf("[^]\n");
}
void DestroyLink(struct NODE *head)
{
	struct NODE *save;
	while (head)
	{
		save = head;
		head = head->next;
		free(save);
		save = NULL;
	}
	if (head == NULL)
	{
		printf("链表已销毁!\n");
	}
}
int main(void)
{
	struct NODE *head = CreateLink();
	InitLink(head);
	OutputLink(head);
	/*int OpCode;
	while (1)
	{
		printf("请输入你想进行的操作: ");
	}*/

	DestroyLink(head);
	system("pause");
	return 0;
}
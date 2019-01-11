/*
测试数据：
3
2000 1 8
2000 1 11
1974 3 21
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int bool;
#define FRONT 0
#define BACK 1

struct Birthday
{
	int year;
	int month;
	int day;
};
struct NODE
{
	struct Birthday data;
	struct NODE *next;
};

struct NODE *CreateLink(void)
{
	struct NODE *head = malloc(sizeof*head);
	struct NODE *move = head;
	move->next = NULL;

	int index;
	printf("你想输入几个结点：");
	scanf("%d", &index);

	for (int i = 0; i < index; move = move->next, ++i)
	{
		struct NODE *fresh = malloc(sizeof*fresh);

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
		printf("请输入第%d个结点的信息：", i);
		scanf("%d %d %d", &move->data.year, &move->data.month, &move->data.day);
	}
}
void OutputLink(const struct NODE *head)
{
	struct NODE *move = head->next;

	for (; move != NULL; move = move->next)
	{
		printf("[%d-%d-%d]->", move->data.year, move->data.month, move->data.day);
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
	}

	if (!head)
	{
		printf("\n链表已销毁！\n");
	}
}

void ReverseLink(struct NODE **head)
{
	struct NODE *copyhead = (*head)->next;
	(*head)->next = NULL;		//把head先摘下来

	while (copyhead != NULL)
	{
		struct NODE *save = copyhead;
		copyhead = copyhead->next;

		save->next = (*head)->next;		//把save一个个的插到head后面
		(*head)->next = save;
	}

}

void InsertLink(const struct NODE *head, bool flag)
{
	struct NODE *move = (flag == BACK ? head->next : head);

	int index;
	printf("你想插入的位置是：");
	scanf("%d", &index);

	for (int i=1; (flag == BACK ? move : move->next) != NULL; move = move->next, ++i)
	{
		if (i == index)
		{
			struct NODE *fresh = malloc(sizeof*fresh);
			printf("请输入新结点的信息：");
			scanf("%d %d %d", &fresh->data.year, &fresh->data.month, &fresh->data.day);

			fresh->next = move->next;
			move->next = fresh;

			break;
		}
	}
}
void DeleteLink(const struct NODE *head)
{
	struct NODE *move = head;

	int index;
	printf("你想删除第几个结点：");
	scanf("%d", &index);

	for (int i = 1; move->next != NULL; move = move->next, ++i)
	{
		if (i == index)
		{
			struct NODE *save = move->next;
			move->next = save->next;

			free(save);
			save = NULL;

			break;
		}
	}
}

int main(void)
{
	struct NODE *head = CreateLink();

	InitLink(head);
	OutputLink(head);
	
	/*原地倒置*/
	//ReverseLink(&head);
	/*插入新结点*/
	//InsertLink(head, FRONT);
	//OutputLink(head);
	//InsertLink(head, BACK);
	//OutputLink(head);
	/*删除结点*/
	DeleteLink(head);
	OutputLink(head);

	DestroyLink(head);
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
enum{false,true};
#define FRONT 0
#define BACK 1

struct Student
{
	int num;
};
struct NODE
{
	struct Student data;
	struct NODE *next;
};

struct NODE *CreateLink(void)
{
	struct NODE *head = malloc(sizeof*head);
	if (!head)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}
	struct NODE *move = head;
	move->next = NULL;

	int index;
	printf("你想输入几个结点: ");
	scanf("%d", &index);

	for (int i = 0; i < index; ++i, move = move->next)
	{
		struct NODE *fresh = malloc(sizeof*fresh);
		if (!fresh)
		{
			printf("Memory alloction error!\n");
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

	for (int i=1; move != NULL;++i, move = move->next)
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
	while (head != NULL)
	{
		save = head;
		head = head->next;
		free(save);
		save = NULL;
	}

	if (!head)
	{
		printf("链表已经销毁!\n");
	}
}

void InsertLink(const struct NODE *head, bool flag)
{
	struct NODE *move = (flag == FRONT ? head : head->next);

	int index;
	printf("你想在第几个结点之");
	printf(flag == FRONT ? "前" : "后");
	printf("插入: ");
	scanf("%d", &index);

	for (int i=1; (flag == FRONT ? move->next : move) != NULL; ++i,move = move->next)
	{
		if (i == index)
		{
			struct NODE *fresh = malloc(sizeof*fresh);
			if (!fresh)
			{
				printf("Memory alloction error!\n");
				exit(-1);
			}

			printf("请输入插入的新结点信息: ");
			scanf("%d", &fresh->data.num);

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
	printf("你想删除第几个结点: ");
	scanf("%d", &index);

	for (int i = 1; move->next != NULL; move = move->next, ++i)
	{
		if (i == index)
		{
			struct NODE *save = move->next;
			move->next = move->next->next;

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

	//InsertLink(head, FRONT);
	//InsertLink(head, BACK);

	DeleteLink(head);
	OutputLink(head);


	DestroyLink(head);
	system("pause");
	return 0;
}
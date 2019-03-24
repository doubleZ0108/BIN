#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	struct NODE *move = head;
	move->next = NULL;

	int index;
	printf("你想输入几个结点: ");
	scanf("%d", &index);

	for (int i = 0; i < index; ++i, move = move->next)
	{
		struct NODE *fresh = malloc(sizeof*fresh);
		
		move->next = fresh;
		fresh->next = NULL;
	}

	return head;
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
	free(head);

	if (!head)
	{
		printf("链表已销毁!\n");
	}
}

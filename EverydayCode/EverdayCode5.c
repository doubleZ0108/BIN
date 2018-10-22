#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};
struct NODE *CreateLink()
{
	struct NODE *head = malloc(sizeof*head);
	struct NODE *move = head;
	move->next = NULL;

	int total;
	printf("你想输入你个结点: ");
	scanf("%d", &total);

	for (int i = 0; i < total; ++i, move = move->next)
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

	for (int i = 1; move != NULL; move = move->next,++i)
	{
		printf("请输入第%d个结点的信息: ",i);
		scanf("%d", &move->data);
	}
}
void OutputLink(const struct NODE *head)
{
	struct NODE *move = head->next;

	for (; move != NULL; move = move->next)
	{
		printf("[%d]->", move->data);
	}
	printf("[^]\n");
}
void DestroyLink(struct NODE *head)
{
	struct NODE *save = NULL;

	while (head)
	{
		save = head;
		head = head->next;
		free(save);
		save = NULL;
	}
	if (!head)
	{
		printf("链表已销毁!\n");
	}
}

void InsertSort(const struct NODE *head)
{
	struct NODE *turn, *move;
	struct NODE *front = head->next, *back = NULL;

	for (turn = head->next->next; turn != NULL; turn = turn->next)
	{
		for (move = head; move->next != turn; move = move->next)
		{
			if (move->next->data > turn->data)
			{
				back = turn->next;
				turn->next = move->next;
				move->next = turn;
				front->next = back;

				turn = front;

				break;
			}
		}
		front = turn;
	}
}
void QuickSort(struct NODE *head, struct NODE *tail)
{
	struct NODE *key, *move, *front, *back;

	if (head->next == tail || head->next->next == tail) { return; }

	key = head->next;
	move = key->next;
	front = key;
	back = key->next->next;

	while (move != tail)
	{
		if (move->data < key->data)
		{
			move->next = head->next;
			head->next = move;
			front->next = back;

			if (!back) { break; }

			move = back;
			back = back->next;
		}
		else
		{
			if (!back) { break; }
			move = move->next;
			front = front->next;
			back = back->next;
		}
	}

	QuickSort(head, key);
	QuickSort(key, tail);
}
int main(void)
{
	struct NODE *head = CreateLink();
	InitLink(head);
	OutputLink(head);

	InsertSort(head);
	//QuickSort(head, NULL);
	OutputLink(head);

	DestroyLink(head);
	system("pause");
	return 0;
}
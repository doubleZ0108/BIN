#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FRONT 1
#define BACK 0

struct Stu
{
	int num;
};
struct NODE
{
	struct Stu data;
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
		printf("*链表已销毁!\n");
	}
}

void InsertLink(const struct NODE *head, int flag)
{
	struct NODE *move = (flag == FRONT ? head : head->next);

	int index;
	printf("你想在第几个结点"); printf(flag == FRONT ? "前插入: " : "后插入: ");
	scanf("%d", &index);

	for (int i = 1; (flag == FRONT ? move->next : move) != NULL; move = move->next, ++i)
	{
		if (i == index)
		{
			struct NODE *fresh = malloc(sizeof*fresh);
			printf("请输入新结点的信息: ");
			scanf("%d", &fresh->data.num);

			fresh->next = move->next;
			move->next = fresh;

			return;
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
			
			return;
		}
	}

	printf("无第%d个结点\n", index);
}

void BubbleSort(const struct NODE *head)
{
	struct NODE *turn, *move;
	struct NODE *save = NULL;
	struct Stu buf;

	for (turn = head->next; turn->next != NULL; turn = turn->next)
	{
		for (move = head->next; move->next != save; move = move->next)
		{
			if (move->data.num > move->next->data.num)
			{
				buf = move->data;
				move->data = move->next->data;
				move->next->data = buf;
			}
		}
		save = move;
	}
}
void SelectSort(const struct NODE *head)
{
	struct NODE *turn, *move, *max;
	struct Stu buf;

	for (turn = head->next; turn != NULL; turn = turn->next)
	{
		max = turn;
		for (move = turn->next; move != NULL; move = move->next)
		{
			if (move->data.num > max->data.num)
			{
				max = move;
			}
		}
		if (max != turn)
		{
			buf = max->data;
			max->data = turn->data;
			turn->data = buf;
		}
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
			if (move->next->data.num > turn->data.num)
			{
				back = turn->next;
				turn->next = move->next;
				move->next = turn;
				front->next = back;

				turn = front;
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
		if (move->data.num < key->data.num)
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
			back = back->next;
			front = front->next;
		}
	}

	QuickSort(head,key);
	QuickSort(key,tail);
}
int main(void)
{
	struct NODE *head = CreateLink();
	InitLink(head);
	OutputLink(head);

	//InsertLink(head, FRONT);
	//OutputLink(head);
	//InsertLink(head, BACK);
	//OutputLink(head);

	//DeleteLink(head);
	//OutputLink(head);

	//BubbleSort(head);
	//SelectSort(head);
	//InsertSort(head);
	//QuickSort(head, NULL);
	//OutputLink(head);


	DestroyLink(head);

	system("pause");
	return 0;
}
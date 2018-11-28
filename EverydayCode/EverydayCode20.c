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

void BubbleSort(const struct NODE *head)
{
	struct NODE *turn, *move;
	struct NODE *save = NULL;
	struct Student buf;

	for (turn = head->next; turn->next != NULL; turn = turn->next)
	{
		for (move = head; move->next != save; move = move->next)
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
	struct Student buf;

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
	struct NODE *front=head->next, *back = NULL;

	for (turn = head->next->next; turn != NULL; turn = turn->next)
	{
		for (move = head; move->next != turn; move = move->next)
		{
			if (move->next->data.num > turn->data.num)
			{
				//front = turn;			//加这条语句是错误的
				//这里注意, 我们的front是turn的循环开始前更新的,不是在这里更新的
				//front初始化的意义也是在此

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
	struct NODE *key, *move;
	struct NODE *low, *high;

	if (head->next == tail || head->next->next == tail)
	{
		return;
	}

	key = head->next;
	low = key;
	high = key->next->next;
	move = key->next;

	while (move != tail)
	{
		if (move->data.num < key->data.num)
			//把他插到头上去
		{
			move->next = head->next;
			head->next = move;

			low->next = high;
			if (!high) { break; }

			move = high;
			high = high->next;
		}
		else
		{
			if (!high) { break; }
			move = move->next;
			low = low->next;
			high = high->next;
		}
	}

	QuickSort(head, key);
	QuickSort(key, tail);
}

void QuickSort_cover(struct NODE *head, struct NODE *tail)
{
	struct NODE *key, *move, *front, *back;

	if (head->next == tail || head->next->next == tail) { return; }

	key = head->next;
	front = key;
	back = key->next->next;
	move = key->next;

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
			front = front->next;
			back = back->next;
		}
	}

	QuickSort_cover(head, key);
	QuickSort_cover(key, tail);
}
int main(void)
{
	struct NODE *head = CreateLink();
	InitLink(head);
	OutputLink(head);

	//InsertLink(head, FRONT);
	//InsertLink(head, BACK);

	//DeleteLink(head);
	//9 6 9 1 4 2 7 3 8 5


	//BubbleSort(head);
	//SelectSort(head);
	//InsertSort(head);
	//QuickSort(head, NULL);
	//QuickSort_cover(head, NULL);
	OutputLink(head);


	DestroyLink(head);
	system("pause");
	return 0;
}
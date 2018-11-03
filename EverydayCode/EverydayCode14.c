/*
链表的设计
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FRONT 0
#define BACK  1

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

void InsertLink(const struct NODE *head, int flag)
{
	struct NODE *move = (flag == FRONT ? head : head->next);

	int index;
	printf("你想在第几个结点"); printf(flag == FRONT ? "之前插入: " : "之后插入: ");
	scanf("%d", &index);

	for (int i = 1; (flag == FRONT ? move->next : move) != NULL; move = move->next, ++i)
	{
		if (i == index)
		{
			struct NODE *fresh = malloc(sizeof*fresh);
			if (fresh == NULL)
			{
				printf("Memory Alloction Failed!\n");
				exit(-1);
			}
			printf("请输入新结点的信息: ");
			scanf("%d", &fresh->data.num);

			fresh->next = move->next;
			move->next = fresh;

			break;
		}
	}
}
void DeleteLink(const struct NODE *head)
{
	if (head->next == NULL)
	{
		printf("链表为空!\n");
		return;
	}
	else
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

		printf("无该结点!\n");
	}
}

void BubbleSort(const struct NODE *head)
{
	struct NODE *turn, *move;
	struct NODE *save = NULL;
	struct STU buf;

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
	struct STU buf;

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
				//大哥啊,别忘了这要判断的,找到了相应的位置才做插入的
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
	struct NODE *key, *move;
	struct NODE *front, *back;

	if (head->next == tail || head->next->next == tail) { return; }
		//forget1: 这里是和tail比较

	key = head->next;
	move = key->next;
	front = key;	//forget2: 这里是用key赋值
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
			else
			{
				move = move->next;
				front = front->next;
				back = back->next;
			}
		}
	}

	QuickSort(head, key);
	QuickSort(key, tail);
}

int main(void)
{
	struct NODE *head = CreateLink();
	InitLink(head);

	int OpCode;
	while (1)
	{
		printf("请输入你想进行的操作: 1输出链表 2插入 3删除 \
4冒泡排序 5选择排序 6插入排序 7快速排序 0结束操作 ");
			//注意这里printf想用两行写需要在第一行结尾加一个 \, 而且要注意下一行必须顶在最头上写
		scanf("%d", &OpCode);
		if (!OpCode) { break; }

		switch (OpCode)
		{
		case 1: 
		{
			OutputLink(head);
			break;
		}
		case 2:
		{
			int flag;
			printf("你想如何插入: 前插0 后插1 ");
			scanf("%d", &flag);

			InsertLink(head, flag);
			break;
		}
		case 3:
		{
			DeleteLink(head);
			break;
		}
		case 4:
		{
			BubbleSort(head);
			break;
		}
		case 5:
		{
			SelectSort(head);
			break;
		}
		case 6:
		{
			InsertSort(head);
			break;
		}
		case 7:
		{
			QuickSort(head, NULL);
			break;
		}
		default:printf("请重新输入!\n"); break;
		}
	}

	DestroyLink(head);
	system("pause");
	return 0;
}
/*
��������
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
	printf("�������뼸�����: ");
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
		printf("�������%d��������Ϣ: ", i);
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
		printf("����������!\n");
	}
}

void InsertLink(const struct NODE *head, int flag)
{
	struct NODE *move = (flag == FRONT ? head : head->next);

	int index;
	printf("�����ڵڼ������"); printf(flag == FRONT ? "֮ǰ����: " : "֮�����: ");
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
			printf("�������½�����Ϣ: ");
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
		printf("����Ϊ��!\n");
		return;
	}
	else
	{
		struct NODE *move = head;

		int index;
		printf("����ɾ���ڼ������: ");
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

		printf("�޸ý��!\n");
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
				//��簡,��������Ҫ�жϵ�,�ҵ�����Ӧ��λ�ò��������
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
		//forget1: �����Ǻ�tail�Ƚ�

	key = head->next;
	move = key->next;
	front = key;	//forget2: ��������key��ֵ
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
		printf("������������еĲ���: 1������� 2���� 3ɾ�� \
4ð������ 5ѡ������ 6�������� 7�������� 0�������� ");
			//ע������printf��������д��Ҫ�ڵ�һ�н�β��һ�� \, ����Ҫע����һ�б��붥����ͷ��д
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
			printf("������β���: ǰ��0 ���1 ");
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
		default:printf("����������!\n"); break;
		}
	}

	DestroyLink(head);
	system("pause");
	return 0;
}
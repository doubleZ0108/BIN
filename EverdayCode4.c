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
	printf("������������: ");
	scanf("%d", &total);
	printf("�ӵڼ����˿�ʼ����: ");
	scanf("%d", &first);
	printf("ÿ�δ�һ������: ");
	scanf("%d", &gap);

	/*
	ע����һ���ܰ�gap��totalȡ��
	�뷨�Ǻõ�, ����һ�������,ÿ�δ�1����8, �о����˷�,����ֱ��ÿ�α���3
	�����Ĵ�������: ÿ����һ����, �������ͻ����,��Ӧ��gapģ������ҲҪ�����仯
	��������ʵʵ�Ķ�ѭ�����ΰ�orz
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
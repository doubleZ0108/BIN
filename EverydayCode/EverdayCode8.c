#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
	struct NODE *front;
};
struct NODE *CreateCirLink(int total)
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
		fresh->front = move;
	}
	move->next = head->next;
	head->next->front = move;
	return head;
}
void Josephus(struct NODE *head, int total, int first, int gap)
{
	struct NODE *move = head->next;
	struct NODE *save;
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
		move->front->next = move->next;
		move->next->front = move->front;

		move = move->next;		//这句move指向下一个必须在free(save)之前
								//因为save释放掉了, move也就为空了, 他们两个之前指向同一个地方的

		printf("%d ", save->data);
		free(save);
		save = NULL;
	}
	printf("%d", move->data);

	free(move);
	free(head);
	save = head = NULL;
}
int main(void)
{
	int total, first, gap;
	printf("请输入总人数: "); scanf("%d", &total);
	printf("从第几个人开始报数: "); scanf("%d", &first);
	printf("每次从1报到几: "); scanf("%d", &gap);

	struct NODE *head = CreateCirLink(total);
	Josephus(head, total, first, gap);

	system("pause");
	return 0;
}
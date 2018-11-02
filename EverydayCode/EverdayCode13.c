#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum{false,true};
typedef int bool;

struct Stu
{
	int num;
};
struct NODE
{
	struct Stu data;
	struct NODE *next;
};
struct QUEUE
{
	struct NODE *front, *rear;
};

struct QUEUE *CreateQueue(void)
{
	struct QUEUE *queue = malloc(sizeof*queue);
	queue->front = queue->rear = malloc(sizeof*queue->front);

	queue->rear->next = NULL;

	return queue;
}
void OutputQueue(const struct QUEUE *queue)
{
	struct NODE *move = queue->front->next;

	for (; move != NULL; move = move->next)
	{
		printf("_%d_", move->data.num);
	}
	printf("_^_\n");
}
bool isEmpty(struct QUEUE *queue)
{
	return queue->front == queue->rear;
}

void GetFirst(const struct QUEUE *queue)
{
	if (isEmpty(queue))
	{
		printf("����Ϊ��!\n");
	}
	else
	{
		printf("first is %d\n", queue->front->next->data.num);
	}
}
void EnQueue(struct NODE* *rear)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	printf("����������Ϣ: ");
	scanf("%d", &fresh->data.num);

	fresh->next = NULL;
	(*rear)->next = fresh;
	(*rear) = fresh;
}
void DeQueue(struct QUEUE *queue, struct NODE* *front)
{
	if (isEmpty(queue))
	{
		printf("����Ϊ��!\n");
	}
	else
	{
		if (queue->front->next == queue->rear)
		{
			queue->rear = queue->front;
		}
		struct NODE *save = (*front)->next;
		(*front)->next = (*front)->next->next;
		free(save);
		save = NULL;
	}
}

void DestroyQueue(struct QUEUE *queue)
{
	struct NODE *save;
	while (!isEmpty(queue))
	{
		save = queue->front;
		queue->front->next = queue->front->next->next;
		free(save);
		save = NULL;
	}
	free(queue);
	if (isEmpty(queue) && !queue)
	{
		printf("����������!\n");
	}
}

int main(void)
{
	struct QUEUE *queue = CreateQueue();
	int OpNum;

	while (1)
	{
		printf("������������еĲ���: 1��� 2���� 3�Ƿ�Ϊ�� 4ȡ����Ԫ�� 5����������� 0���� ");
		scanf("%d", &OpNum);
		if (!OpNum) { break; }

		switch (OpNum)
		{
		case 1:
		{
			EnQueue(&queue->rear);
			break;
		}
		case 2:
		{
			DeQueue(queue, &queue->front);
			break;
		}
		case 3:
		{
			printf(isEmpty(queue) ? "��\n" : "����\n");
			break;
		}
		case 4:
		{
			GetFirst(queue);
			break;
		}
		case 5:
		{
			OutputQueue(queue);
			break;
		}
		default:printf("����������!\n"); break;
		}
	}

	DestroyQueue(queue);
	system("pause");
	return 0;
}
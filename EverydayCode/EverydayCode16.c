#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int bool;

struct STU
{
	int num;
};
struct NODE
{
	struct STU data;
	struct NODE *next;
};
struct QUEUE
{
	struct NODE *front, *rear;
};

struct QUEUE *CreateQueue(void)
{
	struct QUEUE *queue = malloc(sizeof*queue);
	if (NULL == queue)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}
	queue->front = queue->rear = malloc(sizeof*queue->front);
	if (NULL == queue->front)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

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
bool isEmpty(const struct QUEUE *queue)
{
	return queue->front == queue->rear;
}

void GetFirst(const struct QUEUE *queue)
{
	if (!isEmpty(queue))
	{
		printf("��ͷΪ: %d\n", queue->front->next->data.num);
	}
	else
	{
		printf("����Ϊ��!\n");
	}
}
void EnQueue(struct NODE* *rear)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	if (NULL == fresh)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

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
		struct NODE *save = queue->front->next;
		queue->front->next = queue->front->next->next;
		free(save);
		save = NULL;
	}
}

void DestroyQueue(struct QUEUE *queue)
{
	while (!isEmpty(queue))
	{
		DeQueue(queue, &queue->front);
	}
	free(queue->front);
	free(queue);
	if (isEmpty(queue))
	{
		printf("����������!\n");
	}
}

int main(void)
{
	struct QUEUE *queue = CreateQueue();

	int OpCode;
	while (1)
	{
		printf("������������еĲ���: 1������� 2��� 3���� 4�Ƿ�Ϊ�� 5ȡ��ͷ 0�������� ");
		scanf("%d", &OpCode);
		if (!OpCode) { break; }

		switch (OpCode)
		{
		case 1:
		{
			OutputQueue(queue);
			break;
		}
		case 2:
		{
			EnQueue(&queue->rear);
			break;
		}
		case 3:
		{
			DeQueue(queue, &queue->front);
			break;
		}
		case 4:
		{
			printf(isEmpty(queue) ? "����Ϊ��\n" : "����\n");
			break;
		}
		case 5:
		{
			GetFirst(queue);
			break;
		}
		default:printf("����������\n"); break;
		}
	}

	DestroyQueue(queue);
	system("pause");
	return 0;
}
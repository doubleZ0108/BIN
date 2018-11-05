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
		printf("队头为: %d\n", queue->front->next->data.num);
	}
	else
	{
		printf("队列为空!\n");
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

	printf("请输入结点信息: ");
	scanf("%d", &fresh->data.num);
	fresh->next = NULL;

	(*rear)->next = fresh;
	(*rear) = fresh;
}
void DeQueue(struct QUEUE *queue, struct NODE* *front)
{
	if (isEmpty(queue))
	{
		printf("队列为空!\n");
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
		printf("队列已销毁!\n");
	}
}

int main(void)
{
	struct QUEUE *queue = CreateQueue();

	int OpCode;
	while (1)
	{
		printf("请输入你想进行的操作: 1输出队列 2入队 3出队 4是否为空 5取队头 0结束操作 ");
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
			printf(isEmpty(queue) ? "队列为空\n" : "不空\n");
			break;
		}
		case 5:
		{
			GetFirst(queue);
			break;
		}
		default:printf("请重新输入\n"); break;
		}
	}

	DestroyQueue(queue);
	system("pause");
	return 0;
}
/*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

struct Dot
{
	int x, y;
};
struct NODE
{
	struct Dot data;
	struct NODE *next;
};

struct Queue
{
	struct NODE *front, *rear;
};

bool isEmpty(const struct Queue *queue)
{
	return (queue->front == queue->rear);
}

struct Queue* CreateQueue(void)
{
	struct Queue *queue = malloc(sizeof*queue);
	if (!queue)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}

	queue->front = queue->rear = malloc(sizeof*queue->front);
	if (!queue->front)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}

	queue->rear->next = NULL;

	return queue;
}

void getFirst(const struct Queue *queue)
{
	if (!isEmpty(queue))
	{
		printf("The first element is (%d,%d)\n",
			queue->front->next->data.x, queue->front->next->data.y);
	}
	else
	{
		printf("The queue is empty!\n");
	}
}
void EnQueue(struct Queue *queue)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	if (!fresh)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}
	fresh->next = NULL;
	printf("请输入结点信息: ");
	scanf("%d %d", &fresh->data.x, &fresh->data.y);

	queue->rear->next = fresh;
	queue->rear = fresh;
}
void DeQueue(struct Queue *queue)
{
	if (isEmpty(queue))
	{
		printf("The queue is empty!\n");
	}
	else
	{
		struct NODE *save = queue->front;
		queue->front = queue->front->next;

		free(save);
		save = NULL;
	}
}

void OutputQueue(const struct Queue *queue)
{
	for (struct NODE *move = queue->front->next; move != NULL; move = move->next)
	{
		printf("(%d,%d)->", move->data.x, move->data.y);
	}
	printf("[^]\n");
}
void DestroyQueue(struct Queue *queue)
{
	while (!isEmpty(queue))
	{
		DeQueue(queue);
	}
	free(queue->front);
	queue->front = NULL;
	free(queue);
	queue = NULL;

	printf("队列已销毁!\n");
}

int main(void)
{
	struct Queue *queue = CreateQueue();

	int OpCode;
	while (true)
	{
		printf("请输入你想进行的操作(1入队 2出队 3输出 4取队头 5判空 0终止程序): ");
		scanf("%d", &OpCode);
		if (!OpCode) { break; }

		switch (OpCode)
		{
		case 1:
		{
			EnQueue(queue);
			break;
		}
		case 2:
		{
			DeQueue(queue);
			break;
		}
		case 3:
		{
			OutputQueue(queue);
			break;
		}
		case 4:
		{
			getFirst(queue);
			break;
		}
		case 5:
		{
			printf(isEmpty(queue) ? "空\n" : "不空\n");
			break;
		}
		default:
			break;
		}
	}

	DestroyQueue(queue);
	system("pause");
	return 0;
}
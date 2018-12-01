#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
enum{false,true};

typedef struct Student Student;
typedef struct Queue Queue;

struct Student
{
	int num;
};
struct NODE
{
	Student data;
	struct NODE *next;
};
struct Queue
{
	struct NODE *front;
	struct NODE *rear;
};

Queue *CreateQueue(void)
{
	Queue *queue = malloc(sizeof*queue);
	if (!queue)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

	queue->front = queue->rear = malloc(sizeof*queue->rear);
	if (!queue->rear)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

	queue->rear->next = NULL;

	return queue;
}
bool isEmpty(const Queue *queue)
{
	return queue->front == queue->rear;
}
void showQueue(const Queue *queue)
{
	struct NODE *move = queue->front->next;

	printf("|");
	for (; move != NULL; move = move->next)
	{
		printf("%d ", move->data.num);
	}
	printf("|\n");
}

void GetFirst(const Queue *queue)
{
	if (isEmpty(queue))
	{
		printf("队列为空!\n");
	}
	else
	{
		printf("队列头为: %d\n", queue->front->next->data.num);
	}
}

void EnQueue(struct NODE* *rear)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	if (!fresh)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

	printf("请输入入队结点信息: ");
	scanf("%d", &fresh->data.num);
	fresh->next = NULL;

	(*rear)->next = fresh;
	(*rear) = fresh;
}
void DeQueue(Queue *queue, struct NODE* *front)
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
		struct NODE *save = (*front)->next;
		(*front)->next = (*front)->next->next;

		free(save);
		save = NULL;
	}
}

void DestroyQueue(Queue *queue)
{
	while (!isEmpty(queue))
	{
		DeQueue(queue, &queue->front);
	}

	free(queue->rear);
	free(queue);

	if (!queue)
	{
		printf("队列已销毁!\n");
	}
}
int main(void)
{
	Queue *queue = CreateQueue();
	int OpCode;

	while (1)
	{
		printf("请输入你想进行的操作: 1入队 2出队 3取队头 4输出队列 5判空 0结束操作 ");
		scanf("%d", &OpCode);

		if (!OpCode) { break; }
		switch (OpCode)
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
			GetFirst(queue);
			break;
		}
		case 4:
		{
			showQueue(queue);
			break;
		}
		case 5:
		{
			printf(isEmpty(queue) ? "yes\n" : "no\n");
			break;
		}
		default:break;
		}
	}

	DestroyQueue(queue);
	system("pause");
	return 0;
}
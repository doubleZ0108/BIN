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

struct Stack
{
	struct NODE *top, *bottom;
};

bool isEmpty(const struct Stack *stack)
{
	return (stack->top == stack->bottom);
}

struct Stack *CreateStack(void)
{
	struct Stack *stack = malloc(sizeof*stack);
	if (!stack)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}

	stack->top = stack->bottom = malloc(sizeof*stack->top);
	if (!stack->top)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}

	return stack;
}

void getTop(const struct Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("ջ��!\n");
	}
	else
	{
		printf("The top is (%d,%d)\n", stack->top->data.x, stack->top->data.y);
	}
}

void Push(struct Stack *stack)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	if (!fresh)
	{
		printf("Memory alloction error!\n");
		exit(-1);
	}
	printf("����������Ϣ: ");
	scanf("%d %d", &fresh->data.x, &fresh->data.y);

	fresh->next = stack->top;
	stack->top = fresh;
}
void Pop(struct Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("ջ��!\n");
	}
	else
	{
		struct NODE *save = stack->top;
		stack->top = stack->top->next;

		free(save);
		save = NULL;
	}
}

void OutputStack(const struct Stack *stack)
{
	for (struct NODE *move = stack->top; move != stack->bottom; move = move->next)
	{
		printf("|(%d,%d)|\n", move->data.x, move->data.y);
	}
	printf("_______\n");
}
void DestroyStack(struct Stack *stack)
{
	while (!isEmpty(stack))
	{
		Pop(stack);
	}

	free(stack->top);
	stack->top = NULL;
	free(stack);
	stack = NULL;
}

int main(void)
{
	struct Stack *stack = CreateStack();

	int OpCode;
	while (true)
	{
		printf("������������еĲ���(1ѹջ 2��ջ 3��� 4ȡջ�� 5�п� 0��ֹ����): ");
		scanf("%d", &OpCode);
		if (!OpCode) { break; }

		switch (OpCode)
		{
		case 1:
		{
			Push(stack);
			break;
		}
		case 2:
		{
			Pop(stack);
			break;
		}
		case 3:
		{
			OutputStack(stack);
			break;
		}
		case 4:
		{
			getTop(stack);
			break;
		}
		case 5:
		{
			printf(isEmpty(stack) ? "��\n" : "����\n");
			break;
		}
		default:
			break;
		}
	}

	DestroyStack(stack);
	system("pause");
	return 0;
}
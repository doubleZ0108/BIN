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
struct STACK
{
	struct NODE *top, *bottom;
};

struct STACK *CreateStack(void)
{
	struct STACK *stack = malloc(sizeof*stack);
	if (stack == NULL)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}
	stack->bottom = stack->top = malloc(sizeof*stack->top);
	if (stack->top == NULL)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

	stack->bottom->next = NULL;

	return stack;
}
void OutputStack(const struct STACK *stack)
{
	struct NODE *move = stack->top;

	for (; move != stack->bottom; move = move->next)
	{
		printf("|%d|\n", move->data.num);
	}
	printf("|_|\n");
}
bool isEmpty(const struct STACK *stack)
{
	return stack->top == stack->bottom;
}

void GetTop(const struct STACK *stack)
{
	if (isEmpty(stack))
	{
		printf("栈为空!\n");
	}
	else
	{
		printf("栈顶为 %d\n", stack->top->data.num);
	}
}
void Push(struct NODE* *top)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	if (fresh == NULL)
	{
		printf("Memory Alloction Failed!\n");
		exit(-1);
	}

	printf("请输入结点信息: ");
	scanf("%d", &fresh->data.num);

	fresh->next = (*top);
	(*top) = fresh;
}
void Pop(const struct STACK *stack, struct NODE* *top)
{
	if (isEmpty(stack))
	{
		printf("栈为空!\n");
	}
	else
	{
		struct NODE *save = (*top);
		(*top) = (*top)->next;
		free(save);
		save = NULL;
	}
}

void DestroyStack(struct STACK *stack)
{
	while (!isEmpty(stack))
	{
		Pop(stack, &stack->top);
	}
	free(stack->top);

	if (isEmpty(stack))
	{
		printf("栈已销毁!\n");
	}
}

int main(void)
{
	struct STACK *stack = CreateStack();

	int OpCode;
	while (1)
	{
		printf("请输入你想进行的操作: 1输出栈 2压栈 3出栈 4判断是否为空 5取栈顶元素 0结束操作 ");
		scanf("%d", &OpCode);

		if (!OpCode) { break; }

		switch (OpCode)
		{
		case 1:
		{
			OutputStack(stack);
			break;
		}
		case 2:
		{
			Push(&stack->top);
			break;
		}
		case 3:
		{
			Pop(stack, &stack->top);
			break;
		}
		case 4:
		{
			printf(isEmpty(stack) ? "栈空!\n" : "不空!\n");
			break;
		}
		case 5:
		{
			GetTop(stack);
			break;
		}
		default:printf("请重新输入!\n"); break;
		}
	}

	DestroyStack(stack);
	system("pause");
	return 0;
}
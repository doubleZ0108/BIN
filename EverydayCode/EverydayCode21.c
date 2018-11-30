#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
enum{false,true};

typedef struct Student Student;
typedef struct Stack Stack;
struct Student
{
	int num;
};
struct NODE
{
	struct Student data;
	struct NODE *next;
};
struct Stack
{
	struct NODE *top;
	struct NODE *bottom;
};

Stack *CreateStack(void)
{
	Stack *stack = malloc(sizeof*stack);
	if (!stack)
	{
		printf("Memory alloction failed!\n");
		exit(-1);
	}
	stack->top = stack->bottom = malloc(sizeof*stack->bottom);
	if (!stack->top)
	{
		printf("Memory alloction failed!\n");
		exit(-1);
	}

	stack->bottom->next = NULL;

	return stack;
}
bool isEmpty(const Stack *stack)
{
	return stack->top == stack->bottom;
}

void GetTop(const Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("栈空!\n");
	}
	else
	{
		printf("栈顶元素为: %d\n", stack->top->data.num);
	}
}
void showStack(const Stack *stack)
{
	struct NODE *move = stack->top->next;

	for (; move != NULL; move = move->next)
	{
		printf("|%d|\n", move->data.num);
	}
	printf("|_|\n");
}

void Push(struct NODE* *top)
{
	struct NODE *fresh = malloc(sizeof*fresh);

	printf("请输入入栈结点信息: ");
	scanf("%d", &fresh->data.num);

	fresh->next = (*top);
	(*top)->next = fresh;
}
void Pop(const Stack *stack, struct NODE* *top)
{
	if (isEmpty(stack))
	{
		printf("栈空!\n");
	}
	else
	{
		struct NODE *save = (*top);
		(*top) = (*top)->next;
		free(save);
		save = NULL;
	}
}

void DestroyStack(Stack *stack)
{
	while (!isEmpty(stack))
	{
		Pop(stack, &stack->top);
	}
	free(stack->top);
	free(stack);

	if (!stack)
	{
		printf("栈已销毁!\n");
	}
}
int main(void)
{
	Stack *stack = CreateStack();

	int OpCode;
	while (1)
	{
		printf("请输入你想进行的操作: 1入栈 2出栈 3取栈顶 4输出栈 5判空 0退出 ");
		scanf("%d", &OpCode);

		if (!OpCode) { break; }
		switch (OpCode)
		{
		case 1:
		{
			Push(&stack->top);
			break;
		}
		case 2:
		{
			Pop(stack, &stack->top);
			break;
		}
		case 3:
		{
			GetTop(stack);
			break;
		}
		case 4:
		{
			showStack(stack);
			break;
		}
		case 5:
		{
			printf(isEmpty(stack) ? "yes\n" : "no\n");
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
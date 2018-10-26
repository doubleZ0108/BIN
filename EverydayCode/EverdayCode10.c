#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum{ false,true };
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
struct STACK
{
	struct NODE *top, *bottom;
};

struct STACK *CreateStack()
{
	struct STACK *stack = malloc(sizeof*stack);
	stack->bottom = stack->top = malloc(sizeof*stack->top);
	stack->top->next = NULL;

	return stack;
}
bool isEmpty(const struct STACK* stack)
{
	return stack->bottom == stack->top;
}

void Push(struct NODE* *top)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	printf("�������ջ�����Ϣ: ");
	scanf("%d", &fresh->data.num);

	fresh->next = *top;
	(*top) = fresh;
}
void Pop(const struct STACK *stack, struct NODE* *top)
{
	if (!isEmpty(stack))
	{
		struct NODE *save = *top;
		*top = (*top)->next;
		printf("��ջ��Ԫ����: %d\n", save->data.num);
		free(save);
		save = NULL;
	}
	else
	{
		printf("ջ��!\n");
	}
}

void GetTop(const struct STACK *stack)
{
	if (!isEmpty(stack))
	{
		printf("ջ��Ԫ��Ϊ: %d\n", stack->top->data.num);
	}
	else
	{
		printf("ջ��!\n");
	}
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
void DestroyStack(struct STACK *stack)
{
	while (!isEmpty(stack))
	{
		Pop(stack, &stack->top);
	}
	if (isEmpty(stack))
	{
		free(stack);
		stack = NULL;
		printf("ջ�ѿ�!\n");
	}
}
int main(void)
{
	struct STACK *stack = CreateStack();

	int OperCode = 0;

	while (1)
	{
		printf("������������еĲ���: 1�Ƿ�Ϊ�� 2ѹջ 3��ջ 4ջ��Ԫ�� 5�������ջ 0�������� ");
		scanf("%d", &OperCode);
		if (!OperCode) { break; }

		switch (OperCode)
		{
		case 1:
		{
			printf(isEmpty(stack) ? "true\n" : "false\n");
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
			GetTop(stack);
			break;
		}
		case 5:
		{
			OutputStack(stack);
			break;
		}
		default:printf("����Ƿ�, ����������: "); break;
		}
	}

	DestroyStack(stack);
	system("pause");
	return 0;
}
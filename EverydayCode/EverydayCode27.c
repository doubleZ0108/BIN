///*
//�������ݣ�
//3
//2000 1 8
//2000 1 11
//1974 3 21
//*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//struct Birthday
//{
//	int year;
//	int month;
//	int day;
//};
//struct NODE
//{
//	struct Birthday data;
//	struct NODE *next;
//};
//
//struct NODE *CreateLink(void)
//{
//	struct NODE *head = malloc(sizeof*head);
//	struct NODE *move = head;
//	move->next = NULL;
//
//	int index;
//	printf("�������뼸����㣺");
//	scanf("%d", &index);
//
//	for (int i = 0; i < index; move = move->next, ++i)
//	{
//		struct NODE *fresh = malloc(sizeof*fresh);
//
//		move->next = fresh;
//		fresh->next = NULL;
//	}
//
//	return head;
//}
//void InitLink(const struct NODE *head)
//{
//	struct NODE *move = head->next;
//
//	for (int i = 1; move != NULL; move = move->next, ++i)
//	{
//		printf("�������%d��������Ϣ��", i);
//		scanf("%d %d %d", &move->data.year, &move->data.month, &move->data.day);
//	}
//}
//void OutputLink(const struct NODE *head)
//{
//	struct NODE *move = head->next;
//
//	for (; move != NULL; move = move->next)
//	{
//		printf("[%d-%d-%d]->", move->data.year, move->data.month, move->data.day);
//	}
//	printf("[^]\n");
//}
//void DestroyLink(struct NODE *head)
//{
//	struct NODE *save;
//	while (head)
//	{
//		save = head;
//		head = head->next;
//		free(save);
//	}
//
//	if (!head)
//	{
//		printf("���������٣�\n");
//	}
//}
//
//void ReverseLink(struct NODE **head)
//{
//	struct NODE *copyhead = (*head)->next;
//	(*head)->next = NULL;		//��head��ժ����
//
//	while (copyhead != NULL)
//	{
//		struct NODE *save = copyhead;
//		copyhead = copyhead->next;
//
//		save->next = (*head)->next;		//��saveһ�����Ĳ嵽head����
//		(*head)->next = save;
//	}
//
//}
//
//int main(void)
//{
//	struct NODE *head = CreateLink();
//
//	InitLink(head);
//	OutputLink(head);
//	
//	ReverseLink(&head);
//	OutputLink(head);
//
//	DestroyLink(head);
//	system("pause");
//	return 0;
//}
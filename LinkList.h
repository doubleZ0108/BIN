//
//  LinkList.h
//  LinkList
//  
//  Created by double Z on 2020/02/05 .
//  Copyright © 2019 double Z. All rights reserved.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

/**
 * LinkList
 *
 * 【功能】
 *    - create
 *    - input
 *    - output
 *    - insert
 *    - delete
 *    - modify
 *    - destroy
 *
 *    - find
 *    - bubble sort
 *    - select sort
 *    - insert sort
 *
 * !!!永远不要移动head指针
 */

#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define false 0
#define true 1

struct Data{
    int year;
    int month;
    int day;
};

struct Node{
    struct Data data;
    struct Node* next;
};

bool isEqual(const struct Data* data1, const struct Data* data2){
    if(data1->year==data2->year && data1->month==data2->month && data1->day==data2->day){
        return true;
    }else{
        return false;
    }
}

/**
 * 创建链表
 *  - 询问要创建多少个节点
 *  - 创建带表头的链表
 *
 * @return 链表的表头
 */
struct Node* CreateLinkList(void){
    struct Node* head = malloc(sizeof*head);   //sizeof(struct Node)
    head->next = NULL;
    /* malloc之后一定要判断是否申请内存成功 */
    if(NULL == head){       //head == NULL  or  !head
        printf("Memory Allocation Failed!\n");
        exit(-1);
    }

    int total = 4;
//    printf("你要创建几个节点: ");
//    scanf("%d", &total);

    struct Node* move = head;
    struct Node* fresh = NULL;

    for(int _=0; _<total; ++_, move = move->next){
        fresh = malloc(sizeof*fresh);
        move->next = fresh;
        fresh->next = NULL;
    }

    return head;
}

void InputLinkList(const struct Node* head){
    struct Node* move = head->next;
    for(int i = 1; move != NULL; move = move->next, ++i){
        printf("请输入第%i个节点的信息[年-月-日]: ", i);
        scanf("%d%d%d", &move->data.year, &move->data.month, &move->data.day);
    }
}

void OutputLinkList(const struct Node* head){
    for(struct Node* move = head->next; move!=NULL;move=move->next){
        printf("[%d-%d-%d]->", move->data.year, move->data.month, move->data.day);
    }
    printf("[^]\n");
}

void DestroyLinkList(struct Node* head){    //这里不能用const
    struct Node* save = NULL;
    while(head != NULL){
        save = head;
        head = head->next;
        free(save);
        save = NULL;
    }

    if(NULL == head){
        printf("链表已经销毁!\n");
    }
}

void BackInsertLinkList(const struct Node* head){
    struct Node* move = head->next;

    struct Data index;
    printf("你想在哪个节点后面插入: ");
    scanf("%d%d%d", &index.year, &index.month, &index.day);

    for(; move != NULL; move = move->next){
        if(move->data.year==index.year && move->data.month==index.month && move->data.day==index.day){
            struct Node* fresh = malloc(sizeof*fresh);
            printf("请输入该节点的信息[年-月-日]: ");
            scanf("%d%d%d", &fresh->data.year, &fresh->data.month, &fresh->data.day);

            fresh->next = move->next;
            move->next = fresh;

            break;
        }
    }
}

void FrontInsertLinkList(const struct Node* head){
    struct Node* move = head;   //!!!

    struct Data index;
    printf("你想在哪个节点前面插入: ");
    scanf("%d%d%d", &index.year, &index.month, &index.day);

    for( ;move->next != NULL; move = move->next){
        if(move->next->data.year==index.year && move->next->data.month==index.month && move->next->data.day==index.day){
            struct Node* fresh = malloc(sizeof*fresh);
            printf("请输入该节点的信息[年-月-日]: ");
            scanf("%d%d%d", &fresh->data.year, &fresh->data.month, &fresh->data.day);

            fresh->next = move->next;
            move->next = fresh;

            break;
        }
    }
}

void DeleteLinkList(const struct Node* head){
    struct Node* move = head;

    struct Data index;
    printf("你想在删除哪个节点: ");
    scanf("%d%d%d", &index.year, &index.month, &index.day);

    for( ; move->next != NULL; move = move->next){
        if(move->next->data.year==index.year && move->next->data.month==index.month && move->next->data.day==index.day){
            struct Node* save = move->next;
            move->next = move->next->next;        // save->next
            free(save);
            save = NULL;

            break;      //!!!
        }
    }
}


/* 查找 */
bool FindInList(const struct Node* head, const struct Data* data){
    if(NULL == head){
        return false;
    }else{
        if(isEqual(&head->data, data)){
            return true;
        }else{
            return FindInList(head->next, data);
        }
    }
}


/* 排序 */
void BubbleSort(const struct Node* head){
    struct Node* turn;
    struct Node* move;
    struct Data tmp;
    struct Node* tag = NULL;
    bool isSwap;

    for(turn = head->next; turn != NULL; turn = turn->next){
        isSwap = false;
        for(move = head->next; move->next != tag; move = move->next){       //!!!
            if(move->data.month > move->next->data.month){
                isSwap = true;
                tmp = move->data;
                move->data = move->next->data;
                move->next->data = tmp;
            }
        }
        tag = move;                 //!!!
        if(isSwap == false){
            break;
        }
    }
}

void SelectSort(const struct Node* head){
    struct Node* turn;
    struct Node* move;
    struct Node* min;
    struct Data tmp;

    for(turn = head->next; turn->next != NULL; turn = turn->next){      //!!!
        min = turn;
        for(move = turn->next; move != NULL; move = move->next){
            if(move->data.month < min->data.month){
                min = move;
            }
        }

        if(turn != min){
            tmp = turn->data;
            turn->data = min->data;
            min->data = tmp;
        }
    }
}

void InsertSort(const struct Node* head){
    struct Node* turn;
    struct Node* move;
    struct Node* left = head->next;     //!!!
    struct Node* right;

    for(turn = head->next->next; turn != NULL; turn = turn->next){
        for(move = head; move->next != turn; move = move->next){
            if(move->next->data.month > turn->data.month){
                right = turn->next;     //记录后面的链，防丢失
                turn->next = move->next;    //将该元素的指针指向待插入位置
                move->next = turn;      //将前一个与该元素链接
                left->next = right;     //将该元素的前一个链接到该元素原始的链条后面
                turn = left;        //!!!归位

                break;
            }
        }
        left = turn;
    }
}

#endif //LINKLIST_LINKLIST_H

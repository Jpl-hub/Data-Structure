#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
typedef int LTDataType;
typedef struct ListNode{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* ListInit();
LTNode* ListDestroy(LTNode* phead);
LTNode* BuylistNode(LTDataType x);
void ListPrint(LTNode* phead);
void ListPushBack(LTNode* phead, int x);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, int x);
void ListPopFront(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDataType x);
void ListInsert(LTNode* pos, LTDataType x);
void ListErase(LTNode* pos);
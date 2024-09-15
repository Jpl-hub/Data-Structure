#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode**pphead,SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
//不用传二级
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
void SListInsertAfter(SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** phead, SLTNode* pos);
void SListEraseAfter(SLTNode* pos);

void SListDestroy(SLTNode** phead);
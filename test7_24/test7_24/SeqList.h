#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once

typedef int SLDataType;
#define N 1000
////¾²Ì¬Ë³Ðò±í
//typedef struct sequList {
//	SLDataType arr[N];
//	int size;
//}SL;

//¶¯Ì¬Ë³Ðò±í
typedef struct sequList {
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SequListInit(SL* ps);
void SequListDestory(SL* ps);
void SequListCheckCapacity(SL* ps);
void SequListPushBack(SL* ps, SLDataType x);
void SequListPopBack(SL* ps);
void SequListPushFront(SL* ps, SLDataType x);
void SequListPopFront(SL* ps);
void SequListPrint(SL* ps);

int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
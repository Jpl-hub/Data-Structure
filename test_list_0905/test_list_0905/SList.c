#define  _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
SLTNode* BuyListNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
 }
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;         
	}
	printf("\n");
}
void SListPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode; 
	}
	
	
}
void SListPushFront(SLTNode** phead, SLTDataType x) {
	SLTNode* newnode = BuyListNode(x);
	newnode->data = x;
	newnode->next = *phead;
	*phead = newnode;
}
void SListPopBack(SLTNode** phead) {
	if (*phead == NULL) {
		return;
	}
	if ((*phead)->next == NULL) {
		free(*phead);
		*phead = NULL;
	}
	else{
	SLTNode* prev = NULL;
	SLTNode* tail = *phead;
	while (tail->next != NULL) {
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	prev->next = NULL;
}
}
void SListPopFront(SLTNode** phead) {
	if (*phead == NULL) {
		return;
	}
	SLTNode* cur = *phead;
	*phead = cur->next;
	free(cur);
	cur = NULL;
}
//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
	while (cur!=NULL) {
		if (cur->data == x)return cur;
		cur = cur->next;
	}
	return NULL;
}
//在pos位置之前插入一个节点
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x) {
	SLTNode* newnode = BuyListNode(x);
	if (*phead == pos) {
		newnode->next = *phead;
		*phead = newnode;
	}
	else {
		//找到pos前一个位置
		SLTNode* posPrev = *phead;
		while (posPrev->next != pos) {
			posPrev = posPrev->next;
		}
		newnode->next = posPrev->next;
		posPrev->next = newnode;
	}
}
//在pos位置之后插入一个节点
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
		SLTNode*newnode= BuyListNode(x);
		newnode->next = pos->next;
		pos->next = newnode;
}
//删除pos位置的节点
void SListErase(SLTNode** phead, SLTNode* pos) {
	if (*phead == pos) {
		*phead = pos->next;
	}
	else {
		SLTNode* posPrev = *phead;
		while (posPrev->next != pos) {
			posPrev = posPrev->next;
		}
		posPrev->next = pos->next;
	}
	free(pos);
	pos = NULL;
}
//删除pos位置之后的节点
void SListEraseAfter(SLTNode* pos) {
	assert(pos->next);
	SLTNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
}
//销毁
void SListDestroy(SLTNode** phead) {
	assert(phead);
	SLTNode* cur = *phead;
	SLTNode* next = NULL;
	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	*phead = NULL;
}
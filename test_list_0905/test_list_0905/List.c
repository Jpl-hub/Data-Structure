#define  _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

LTNode* ListInit() {
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
LTNode* BuylistNode(LTDataType x) {
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListPrint(LTNode* phead) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushBack(LTNode* phead, int x) {
	assert(phead);

	//双向循环链表找尾等于头结点的前驱
	LTNode* tail = phead->prev;
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}
void ListPopBack(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
	//ListErase(phead->prev);
}
void ListPushFront(LTNode* phead, int x) {
	assert(phead);
	LTNode* newnode = BuylistNode(x);
	LTNode* next = phead->next;
	newnode->data = x;
	newnode->next = next;
	next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}
void ListPopFront(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	LTNode* cur = phead->next;
	phead->next = cur->next;
	cur->next->prev = phead;
	free(cur);
	cur = NULL;
	//ListErase(phead->next);
}
LTNode* ListFind(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x)return cur;
		cur = cur->next;
	}
	return NULL;
}
//在pos位置之前插入一个节点
void ListInsert(LTNode* pos, LTDataType x) {
	assert(pos);
	LTNode* newnode = BuylistNode(x);
	LTNode* posprev = pos->prev;
	newnode->prev = posprev;
	posprev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除pos位置
void ListErase(LTNode* pos) {
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
	pos = NULL;
}
LTNode* ListDestroy(LTNode* phead){
	assert(phead);
	LTNode* cur = phead->next;
	while (cur->next != phead) {
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
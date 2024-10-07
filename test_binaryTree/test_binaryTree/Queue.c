#define  _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq) {
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL) {
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x) {
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	//if (pq->head == NULL)return;
	QueueNode* cur = pq->head;
	pq->head = cur->next;
	free(cur);
	if (pq->head == NULL)pq->tail = NULL;
}
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
int QueueSize(Queue* pq) {
	int count = 0;
	QueueNode* cur = pq->head;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL;
}
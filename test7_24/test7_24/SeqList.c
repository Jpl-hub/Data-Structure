#define  _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SequListInit(SL*ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SequListCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
void SequListPushBack(SL* ps, SLDataType x)
{
	/*SequListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
void SequListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
}
void SequListDestory(SL* ps) {
	free(ps->a);
	ps->a= NULL;
	ps->size = ps->capacity = 0;
}

void SequListPopBack(SL* ps) {
	assert(ps->size > 0);
	ps->size--;
}
void SequListPushFront(SL* ps, SLDataType x)
{
	//SequListCheckCapacity(ps);
	////Å²¶¯Êý¾Ý
	//int end = ps->size - 1;
	//while (end >= 0) {
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SeqListInsert(ps, 0, x);
}
void SequListPopFront(SL* ps) {
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size) {
		ps->a[begin-1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}
int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x)return i;
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	/*if (pos > ps->size || pos < 0) {
		printf("pos invalid\n");
		return;
	}*/
	assert(pos <= ps->size || pos >= 0);
	SequListCheckCapacity(ps);
	int end = ps->size;
	while (end >=pos+1) {
		ps->a[end] = ps->a[end-1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;   
}
void SeqListErase(SL* ps, int pos) {
	assert(pos < ps->size || pos >= 0);
	int begin = pos+1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

#define  _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
//测试尾插和头插
void TestSList1() {
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
}
//测试尾删和头删
void TestSList2() {
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	//SListPopBack(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

}
//测试查找（兼具修改）
void TestSList3() {
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SLTNode* pos = SListFind(plist, 2);
	int i = 0;
	while (pos) {
		printf("第%d个pos节点%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}
	SListPrint(plist);

	//Find同时还具备修改功能：3-30
	pos = SListFind(plist, 3);
	if (pos) {
		pos->data = 30;
	}
	SListPrint(plist);
}
//测试任意位置插入
void TestSList4() {
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	SLTNode* pos = SListFind(plist, 3);
	if (pos) {
		SListInsert(&plist, pos, 40);
	}
	SListPrint(plist);

}
//综合测试
void TestSList5() {
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	SLTNode* pos1 = SListFind(plist, 3);
	if (pos1) {
		SListInsertAfter(pos1, 40);
	}
	SListPrint(plist);
	SLTNode* pos2 = SListFind(plist, 2);
	if (pos2) {
		SListErase(&plist,pos2);
	}
	SListPrint(plist);
	//销毁
	SListDestroy(&plist);

}
int main() {
	//TestSList1();
	//TestSList2();
	//TestSList3();
	//TestSList4();
	TestSList5();
	return 0;
}
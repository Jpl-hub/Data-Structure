#define  _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1() {
	LTNode* plist =ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPushFront(plist, 0);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListInsert(plist->next, 0);
	ListPrint(plist);

}

void TestList2() {
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPushFront(plist,1);
	ListPushFront(plist,2);
	ListPushFront(plist,3);
	ListPushFront(plist,4);
	ListPrint(plist);
	LTNode* pos = ListFind(plist,2);
	if (pos) {
		ListErase(pos);
	}
	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;
}
int main() {
	//TestList1();
	TestList2();
	return 0;
}
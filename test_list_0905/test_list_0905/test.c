#define  _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
//����β���ͷ��
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
//����βɾ��ͷɾ
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
//���Բ��ң�����޸ģ�
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
		printf("��%d��pos�ڵ�%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}
	SListPrint(plist);

	//Findͬʱ���߱��޸Ĺ��ܣ�3-30
	pos = SListFind(plist, 3);
	if (pos) {
		pos->data = 30;
	}
	SListPrint(plist);
}
//��������λ�ò���
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
//�ۺϲ���
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
	//����
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
#define  _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void TestSeqList1() {
    SL sl;
    SequListInit(&sl);
    SequListPushBack(&sl, 1);
    SequListPushBack(&sl, 2);
    SequListPushBack(&sl, 3);
    SequListPushBack(&sl, 4);
    SequListPrint(&sl);
    SequListPopBack(&sl);
    SequListDestory(&sl);
}
void TestSeqList2() {
    SL sl;    
    SequListInit(&sl);
    SequListPushBack(&sl, 1);
    SequListPushBack(&sl, 2);
    SequListPushBack(&sl, 3);
    SequListPushBack(&sl, 4);
    SequListPushBack(&sl, 5);
    SequListPushFront(&sl, 10);
    SequListPushFront(&sl, 20);
    SequListPushFront(&sl, 30);
    SequListPushFront(&sl, 40);

    SequListPrint(&sl);
    SequListPopFront(&sl);
    SequListPopFront(&sl);
    printf("\n");
    SequListPrint(&sl);
    SequListDestory(&sl);
}
void TestSeqList3() {
    SL sl;    
    SequListInit(&sl);
    SequListPushBack(&sl, 1);
    SequListPushBack(&sl, 2);
    SequListPushBack(&sl, 3);
    SequListPushBack(&sl, 4);
    SequListPushBack(&sl, 5);
    SequListPushFront(&sl, 10);
    SequListPushFront(&sl, 20);
    SequListPushFront(&sl, 30);
    SequListPushFront(&sl, 40);

    SequListPrint(&sl);
    printf("\n");
    SeqListInsert(&sl, 3, 100);
    SequListPrint(&sl);
    SequListDestory(&sl);
}
void menu() {

}
int main() {
    //TestSeqList1();
    //TestSeqList2();
    TestSeqList3();

    return 0;
}
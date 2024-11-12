#define  _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"
#include <stdio.h>

// ���Ժ���
void test() {
    int tablesize = 10;
    HashTable H = CreateTable(tablesize);
    printf("�����˹�ϣ����СΪ %d\n", H->tablesize);

    // ���Բ���Ԫ��
    int keys[] = { 15, 25, 35, 45, 55 };
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        if (Insert(H, keys[i])) {
            printf("�ɹ�����Ԫ�� %d\n", keys[i]);
        }
        else {
            printf("����Ԫ�� %d ʧ��\n", keys[i]);
        }
    }

    // ���Բ���Ԫ��
    int searchKeys[] = { 15, 25, 100 };
    for (int i = 0; i < 3; i++) {
        int pos = Find(H, searchKeys[i]);
        if (H->cells[pos].Info == Legitmate && H->cells[pos].data == searchKeys[i]) {
            printf("�ҵ�Ԫ�� %d ��λ�� %d\n", searchKeys[i], pos);
        }
        else {
            printf("Ԫ�� %d ������\n", searchKeys[i]);
        }
    }

    // ���ٹ�ϣ��
    DestroyTable(H);
    printf("��ϣ��������\n");
}

int main() {
    test();
    return 0;
}

#define  _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"
#include <stdio.h>

// 测试函数
void test() {
    int tablesize = 10;
    HashTable H = CreateTable(tablesize);
    printf("创建了哈希表，大小为 %d\n", H->tablesize);

    // 测试插入元素
    int keys[] = { 15, 25, 35, 45, 55 };
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        if (Insert(H, keys[i])) {
            printf("成功插入元素 %d\n", keys[i]);
        }
        else {
            printf("插入元素 %d 失败\n", keys[i]);
        }
    }

    // 测试查找元素
    int searchKeys[] = { 15, 25, 100 };
    for (int i = 0; i < 3; i++) {
        int pos = Find(H, searchKeys[i]);
        if (H->cells[pos].Info == Legitmate && H->cells[pos].data == searchKeys[i]) {
            printf("找到元素 %d 在位置 %d\n", searchKeys[i], pos);
        }
        else {
            printf("元素 %d 不存在\n", searchKeys[i]);
        }
    }

    // 销毁哈希表
    DestroyTable(H);
    printf("哈希表已销毁\n");
}

int main() {
    test();
    return 0;
}

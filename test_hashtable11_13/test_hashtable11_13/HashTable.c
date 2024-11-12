#define  _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"

// 哈希函数
int f(int x, int size) {
    int SIZE = NextPrime(size);
    return (x % SIZE + SIZE) % SIZE;
}

// 返回大于 N 且不超过 MAXSIZE 的最小素数
int NextPrime(int N) {
    int p = (N % 2) ? N + 2 : N + 1;
    while (p <= MAXSIZE) {
        int is_prime = 1;
        int limit = (int)sqrt(p);
        for (int i = 2; i <= limit; i++) {
            if (p % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) return p;
        p += 2;
    }
    return MAXSIZE;
}

// 创建哈希表
HashTable CreateTable(int tablesize) {
    HashTable H = (HashTable)malloc(sizeof(struct HTNode));
    H->tablesize = NextPrime(tablesize);
    H->cells = (Cell*)malloc(H->tablesize * sizeof(Cell));
    for (int i = 0; i < H->tablesize; i++) {
        H->cells[i].Info = Empty;
    }
    return H;
}

// 查找元素
int Find(HashTable H, ElementType key) {
    int curpos, newpos;
    int cnum = 0;
    newpos = curpos = f(key, H->tablesize);
    while (H->cells[newpos].Info != Empty && H->cells[newpos].data != key) {
        cnum++;
        if (cnum % 2) {
            newpos = curpos + (cnum + 1) * (cnum + 1) / 4;
            if (newpos >= H->tablesize) newpos %= H->tablesize;
        }
        else {
            newpos = curpos - cnum * cnum / 4;
            if (newpos < 0) newpos += H->tablesize;
        }
    }
    return newpos;
}

// 插入元素
bool Insert(HashTable H, ElementType key) {
    int pos = Find(H, key);
    if (H->cells[pos].Info != Legitmate) {
        H->cells[pos].Info = Legitmate;
        H->cells[pos].data = key;
        return true;
    }
    else {
        printf("键值已存在\n");
        return false;
    }
}

// 销毁哈希表
void DestroyTable(HashTable H) {
    if (H != NULL) {
        free(H->cells);
        free(H);
    }
}

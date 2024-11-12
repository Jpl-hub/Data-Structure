#define  _CRT_SECURE_NO_WARNINGS 1
#include "HashTable.h"

// ��ϣ����
int f(int x, int size) {
    int SIZE = NextPrime(size);
    return (x % SIZE + SIZE) % SIZE;
}

// ���ش��� N �Ҳ����� MAXSIZE ����С����
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

// ������ϣ��
HashTable CreateTable(int tablesize) {
    HashTable H = (HashTable)malloc(sizeof(struct HTNode));
    H->tablesize = NextPrime(tablesize);
    H->cells = (Cell*)malloc(H->tablesize * sizeof(Cell));
    for (int i = 0; i < H->tablesize; i++) {
        H->cells[i].Info = Empty;
    }
    return H;
}

// ����Ԫ��
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

// ����Ԫ��
bool Insert(HashTable H, ElementType key) {
    int pos = Find(H, key);
    if (H->cells[pos].Info != Legitmate) {
        H->cells[pos].Info = Legitmate;
        H->cells[pos].data = key;
        return true;
    }
    else {
        printf("��ֵ�Ѵ���\n");
        return false;
    }
}

// ���ٹ�ϣ��
void DestroyTable(HashTable H) {
    if (H != NULL) {
        free(H->cells);
        free(H);
    }
}

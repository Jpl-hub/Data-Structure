#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXSIZE 100000

typedef int ElementType;
typedef enum {
    Legitmate, Empty, Deleted
} EntryType;

typedef struct HashEntry {
    ElementType data;
    EntryType Info; // 单元状态
} Cell;

typedef struct HTNode {
    Cell* cells;
    int tablesize; // 表的最大长度
} *HashTable;

int f(int x, int size);
int NextPrime(int N);
HashTable CreateTable(int tablesize);
int Find(HashTable H, ElementType key);
bool Insert(HashTable H, ElementType key);
void DestroyTable(HashTable H);


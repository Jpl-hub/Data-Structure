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
    EntryType Info; // ��Ԫ״̬
} Cell;

typedef struct HTNode {
    Cell* cells;
    int tablesize; // �����󳤶�
} *HashTable;

int f(int x, int size);
int NextPrime(int N);
HashTable CreateTable(int tablesize);
int Find(HashTable H, ElementType key);
bool Insert(HashTable H, ElementType key);
void DestroyTable(HashTable H);


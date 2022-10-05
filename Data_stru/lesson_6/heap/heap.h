#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
    HPDataType *a;
    int size;
    int capacity;
} HP;

void HeapInit(HP *hp);
void HeapDestroy(HP *hp);
void HeapPush(HP *hp, HPDataType x);
void HeapPop(HP *hp);
void HeapPrint(HP *hp);
void AdjustUp(int *a, int child);
bool HeapEmpty(HP *hp);
int HeapSize(HP *hp);
void HeapSwap(HPDataType *px, *py);
int SearchForBigChild(int *ps, int *pb);
void HeapPrint(HP *hp);
void HeapDestroy(HP *hp);
HPDataType HeapTop(HP *hp);
void HeapSort(int *a, int n);

#ifndef HEPAS_HEAPS_H
#define HEPAS_HEAPS_H

#include "Item.h"
#include "MinHeap.h"
#include "MaxHeap.h"

const int MAX_HEAP_SIZE = 100;

class Heaps {
private:
    int heapsSize;
    MinHeap smallMin;
    MaxHeap smallMax;
    MinHeap bigMin;
    MaxHeap bigMax;
public:
    Heaps();
    ~Heaps();
    void Insert(Item* x);
    void BalanceHeaps();
    void DeleteMax();
    void DeleteMin();
    void Min();
    void Max();
    void Median();
};

#endif //HEPAS_HEAPS_H

#include "MinHeap.h"

MinHeap::MinHeap(int max) {
    data = new Item*[max];
    maxSize = max;
    heapSize = 0;
    allocated = 1;
}

MinHeap::~MinHeap() {
    if (allocated) {
        allocated = 0;
        for (int i = 0; i < heapSize; i++) {
            delete data[i];
        }
        delete[]data;
        data = NULL;
    }
}

int MinHeap::Parent(int node) {
    return (node - 1) / 2;
}

int MinHeap::Left(int node) {
    return (2 * node + 1);
}

int MinHeap::Right(int node) {
    return (2 * node + 2);
}

void MinHeap::swap(Item*& a, Item*& b) {
    Item* temp = a;
    a = b;
    b = temp;
    int tempIndex = a->getIndex();
    a->setIndexInHeap(b->getIndex());
    b->setIndexInHeap(tempIndex);
}

void MinHeap::siftUp(int index) {
    if (index == 0) {
        return;
    }

    int parentIndex = Parent(index);
    if (data[index]->getPriority() < data[parentIndex]->getPriority()) {
        swap(data[index], data[parentIndex]);
        siftUp(parentIndex);
    }
}

void MinHeap::siftDown(int index) {
    int leftChildIndex = Left(index);
    int rightChildIndex = Right(index);
    int smallest = index;

    if (leftChildIndex < heapSize && data[leftChildIndex]->getPriority() < data[smallest]->getPriority()) {
        smallest = leftChildIndex;
    }

    if (rightChildIndex < heapSize && data[rightChildIndex]->getPriority() < data[smallest]->getPriority()) {
        smallest = rightChildIndex;
    }

    if (smallest != index) {
        swap(data[index], data[smallest]);
        siftDown(smallest);
    }
}

void MinHeap::Insert(Item *item) {
    data[heapSize] = item;
    item->setIndexInHeap(heapSize);
    heapSize++;
    siftUp(heapSize - 1);
}

void MinHeap::Min() {
    if (heapSize == 0) {
        std::cout << "wrong input" << std::endl;
        exit(1);
    }
    data[0]->printStr();
}

Item* MinHeap::DeleteMin(bool print) {
    if (heapSize == 0) {
        cout << "wrong input" << endl;
        exit(1);
    }
    heapSize--;
    Item* temp = data[0];
    data[0] = data[heapSize]; // this is the last one
    siftDown(0);
    if(print){
        temp->printStr();
    }
    return temp;
}

void MinHeap::Delete(int index){
    heapSize--;
    int parentIndex = Parent(index);
    data[index] = data[heapSize];
    if (data[index]->getPriority() < data[parentIndex]->getPriority())
        siftUp(index);
    else{
        siftDown(index);
    }
}

int MinHeap::getMinPriority() const{
    return data[0]->getPriority();
}
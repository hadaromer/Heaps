#include "MaxHeap.h"

MaxHeap::MaxHeap(int max) {
    data = new Item*[max];
    maxSize = max;
    heapSize = 0;
    allocated = 1;
}

MaxHeap::~MaxHeap() {
    if (allocated) {
        allocated = 0;
        for (int i = 0; i < heapSize; i++) {
            delete data[i];
        }
        delete[]data;
        data = NULL;
    }
}

int MaxHeap::Parent(int node) {
    return (node - 1) / 2;
}

int MaxHeap::Left(int node) {
    return (2 * node + 1);
}

int MaxHeap::Right(int node) {
    return (2 * node + 2);
}

void MaxHeap::swap(Item*& a, Item*& b) {
    Item* temp = a;
    a = b;
    b = temp;
    int tempIndex = a->getIndex();
    a->setIndexInHeap(b->getIndex());
    b->setIndexInHeap(tempIndex);
}

void MaxHeap::siftUp(int index) {
    if (index == 0) {
        return;
    }

    int parentIndex = Parent(index);
    if (data[index]->getPriority() > data[parentIndex]->getPriority()) {
        swap(data[index], data[parentIndex]);
        siftUp(parentIndex);
    }
}

void MaxHeap::siftDown(int index) {
    int leftChildIndex = Left(index);
    int rightChildIndex = Right(index);
    int largest = index;

    if (leftChildIndex < heapSize && data[leftChildIndex]->getPriority() > data[largest]->getPriority()) {
        largest = leftChildIndex;
    }

    if (rightChildIndex < heapSize && data[rightChildIndex]->getPriority() > data[largest]->getPriority()) {
        largest = rightChildIndex;
    }

    if (largest != index) {
        swap(data[index], data[largest]);
        siftDown(largest);
    }
}

void MaxHeap::Insert(Item *item) {
    data[heapSize] = item;
    item->setIndexInHeap(heapSize);
    heapSize++;
    siftUp(heapSize - 1);
}

void MaxHeap::Max() {
    if (heapSize == 0) {
        std::cout << "wrong input" << std::endl;
        exit(1);
    }
    data[0]->printStr();
}

Item* MaxHeap::DeleteMax(bool print) {
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

void MaxHeap::Delete(int index){
    heapSize--;
    data[index] = data[heapSize];
    int parentIndex = Parent(index);

    if (data[index]->getPriority() > data[parentIndex]->getPriority())
        siftUp(index);
    else{
        siftDown(index);
    }
}

int MaxHeap::getMaxPriority() const{
    return data[0]->getPriority();
}
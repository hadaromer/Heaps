#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

#include "Item.h"

class MaxHeap {
private:
	Item** data;
	int maxSize;
	int heapSize;
	int allocated; // 1 if heap allocated memory
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void swap(Item*& a, Item*& b);
    void siftUp(int index);
    void siftDown(int index);
public:
    MaxHeap(int max);
	~MaxHeap();
	void Max();
	Item* DeleteMax(bool print=true);
    void Delete(int index);
	void Insert(Item* item);
    int getSize() const{return heapSize;};
    int getMaxPriority() const;
};

#endif
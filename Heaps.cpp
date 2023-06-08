#include "Heaps.h"


Item* duplicate(Item* original) { // helper function to duplicate an item
    Item* newItem = new Item(*original);
    newItem->setBrother(original);
    original->setBrother(newItem);
    return newItem;
}

Heaps::Heaps() : heapsSize(0), smallMin(MAX_HEAP_SIZE), smallMax(MAX_HEAP_SIZE), bigMin(MAX_HEAP_SIZE), bigMax(MAX_HEAP_SIZE){};
Heaps::~Heaps(){
    bigMax.~MaxHeap();
    bigMin.~MinHeap();
    smallMax.~MaxHeap();
    smallMin.~MinHeap();
}
void Heaps::Insert(Item* x){
        if(smallMax.getSize() > 0 && smallMax.getMaxPriority() < x->getPriority()){ // if the new item is bigger than median
                Item* brother = duplicate(x);
                bigMax.Insert(x);
                bigMin.Insert(brother);
        }
        else{
            Item* brother = duplicate(x);
            smallMax.Insert(x);
            smallMin.Insert(brother);
        }
    BalanceHeaps();
}

void Heaps::BalanceHeaps(){
    // our goal is to keep |small| = |big| or |small| - 1 = |big|
    if(smallMax.getSize() == bigMax.getSize() || smallMax.getSize() - 1 == bigMax.getSize()) // that's ok
        return;
    if(smallMax.getSize() + 1 == bigMax.getSize()){ // we will move the minimum of big ones to small ones
        Item* minFromBig = bigMin.DeleteMin(false);
        bigMax.Delete(minFromBig->getBrother()->getIndex());
        smallMax.Insert(minFromBig);
        smallMin.Insert(minFromBig->getBrother());
    }
    if(smallMax.getSize() - 2 == bigMax.getSize()){ // we will move the maximum of small ones to big ones
        Item* maxFromSmall = smallMax.DeleteMax(false);
        smallMin.Delete(maxFromSmall->getBrother()->getIndex());
        bigMax.Insert(maxFromSmall);
        bigMin.Insert(maxFromSmall->getBrother());
    }
}

void Heaps::DeleteMax(){
    if(bigMax.getSize()>0) { // if there are no items in big ones we will go to small ones
        Item *toDelete = bigMax.DeleteMax();
        bigMin.Delete(toDelete->getBrother()->getIndex());
        delete toDelete->getBrother();
        delete toDelete;

        BalanceHeaps();
    }
    else{
        DeleteMin();
    }
}

void Heaps::DeleteMin(){
    if (smallMin.getSize() == 0) {
        cout << "wrong input" << endl;
        exit(1);
    }
    Item* toDelete = smallMin.DeleteMin();
    smallMax.Delete(toDelete->getBrother()->getIndex());
    delete toDelete->getBrother();
    delete toDelete;

    BalanceHeaps();
}

void Heaps::Max(){
    if(bigMax.getSize()>0) {
        bigMax.Max();
    }
    else{
        Min();
    }
}
void Heaps::Min(){
    if (smallMin.getSize() == 0) {
        cout << "wrong input" << endl;
        exit(1);
    }
    smallMin.Min();
}

void Heaps::Median(){
    if (smallMax.getSize() == 0) {
        cout << "wrong input" << endl;
        exit(1);
    }
    smallMax.Max();
}
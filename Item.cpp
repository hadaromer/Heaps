#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

int Item::getPriority() const{
    return priority;
}
string Item::getStr() const{
    return str;
}
void Item::printStr() const{
    cout << priority << " " << str << endl;
}
void Item::setBrother(Item* i){
    brother = i;
}
Item* Item::getBrother() const{
    return brother;
}
void Item::setIndexInHeap(int index){
    indexInHeap = index;
}
int Item::getIndex() const{
    return indexInHeap;
}

#ifndef Item_H
#define Item_H

#include <iostream>
#include <string>
using std::string;

class Item {
private:
    int priority;
    string str;
    Item* brother = nullptr;
    int indexInHeap = -1;
public:
    Item(int _priority, string _str) : priority(_priority), str(_str){};
    Item(const Item & other) : str(other.str), priority(other.priority){}; // copy ctor
    Item(){};
    int getPriority() const;
    string getStr() const;
    void printStr() const;
    void setBrother(Item* i);
    Item* getBrother() const;
    void setIndexInHeap(int index);
    int getIndex() const;
};

#endif

#ifndef ACTIVETASKITERATOR_H
#define ACTIVETASKITERATOR_H

#include "Iterator.h"
#include <stack>

class ActiveTaskIterator : public Iterator {
private:
    WorkItem* root;
    std::stack<WorkItem*> traversalStack;
    void findNextLeaf();

public:
    ActiveTaskIterator(WorkItem* rootNode);
    ~ActiveTaskIterator() override;

    void first() override;
    void next() override;
    bool isDone() const override;
    WorkItem* current() const override;
};

#endif
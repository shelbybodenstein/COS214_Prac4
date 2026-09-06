#ifndef COSTREPORTERI_H
#define COSTREPORTERI_H

#include "Iterator.h"
#include <stack>

class CostReportIterator : public Iterator {
private:
    WorkItem* root;
    std::stack<WorkItem*> traversalStack;

public:
    CostReportIterator(WorkItem* rootNode);
    ~CostReportIterator() override;

    void first() override;
    void next() override;
    bool isDone() const override;
    WorkItem* current() const override;
};
#endif
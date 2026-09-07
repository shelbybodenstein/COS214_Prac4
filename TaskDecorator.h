#ifndef TASKDECORATOR_H
#define TASKDECORATOR_H

#include "WorkItem.h"

class TaskDecorator : public WorkItem{

protected:
    WorkItem* wrapped;

public:
    TaskDecorator(WorkItem* wrapped);
    virtual ~TaskDecorator();

    void execute() override;
    std::string getDescription() const override;
    double getCost() const override;
    std::string getStatus() const override;
    Iterator* TaskDecorator::createIterator();

    void add(WorkItem* child);
    void remove(WorkItem* child);
    int getChildCount() const;
    WorkItem* getChildAt(int index) const;

};




#endif
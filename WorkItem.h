#ifndef WORKITEM_H
#define WORKITEM_H

#include <string>

class Iterator; 

class WorkItem {
public:
    virtual ~WorkItem() {}

    virtual void execute() = 0;
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual std::string getStatus() const = 0;

    
    virtual void add(WorkItem* child) {}
    virtual void remove(WorkItem* child) {}
    virtual int getChildCount() const { return 0; }
    virtual WorkItem* getChildAt(int index) const { return nullptr; }

    virtual Iterator* createIterator() = 0;
};

#endif
#ifndef WORKGROUP_H
#define WORKGROUP_H

#include "WorkItem.h"
#include <vector>
#include <string>

class WorkGroup : public WorkItem {
protected:
    std::vector<WorkItem*> children;
    std::string name;
public:
    WorkGroup(std::string name);
    virtual ~WorkGroup();

    // Composite management
    void add(WorkItem* child) override;
    void remove(WorkItem* child) override;
    int getChildCount() const override;
    WorkItem* getChildAt(int index) const override;

    // To be implemented by concrete subclasses (Phase, Room)
    virtual void execute() override = 0;
    virtual std::string getDescription() const override = 0;
    virtual double getCost() const override = 0;
    virtual std::string getStatus() const override = 0;
    virtual Iterator* createIterator() override = 0;
};
#endif
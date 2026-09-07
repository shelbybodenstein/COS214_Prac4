#ifndef TASK_H
#define TASK_H

#include "WorkItem.h"
#include <string>

class Task : public WorkItem {
private:
    std::string name;
    double cost;
    std::string status;

public:
    Task(std::string name, double cost);
    ~Task() override;

    void execute() override;
    std::string getDescription() const override;
    double getCost() const override;
    std::string getStatus() const override;
    Iterator* createIterator() override;
};

#endif
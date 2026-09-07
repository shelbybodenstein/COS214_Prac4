#ifndef TASK_H
#define TASK_H

#include "WorkItem.h"
#include <string>

class TaskState;

class Task : public WorkItem {
private:
    std::string name;
    double baseCost;
    TaskState* state;

public:
    Task(std::string name, double baseCost);

    void execute() override;
    std::string getDescription() const override;
    double getCost() const override;
    std::string getStatus() const override;
    Iterator* createIterator() override;

    bool start();
    bool submitForInspection();
    bool passInspection();
    bool failInspection();

    ~Task();
 
};

#endif
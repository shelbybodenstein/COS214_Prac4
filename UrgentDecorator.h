#ifndef URGENTDECORATOR_H
#define URGENTDECORATOR_H

#include "TaskDecorator.h"

class UrgentDecorator : public TaskDecorator{
public:
    UrgentDecorator(WorkItem* wrapped) : TaskDecorator(wrapped) {}
    
    double getCost() const override;
    std::string getDescription() const override;
};

#endif
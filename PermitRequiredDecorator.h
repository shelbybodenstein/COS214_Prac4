#ifndef PERMITREQUIREDDECORATOR_H
#define PERMITREQUIREDDECORATOR_H

#include "TaskDecorator.h"

class PermitRequiredDecorator : public TaskDecorator {
public:
    PermitRequiredDecorator(WorkItem* wrapped) : TaskDecorator(wrapped) {}
    
    double getCost() const override;
    std::string getDescription() const override;
};

#endif
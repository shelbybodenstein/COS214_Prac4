#ifndef SPECIALISTDECORATOR_H
#define SPECIALISTDECORATOR_H

#include "TaskDecorator.h"

class SpecialistDecorator : public TaskDecorator{
    
public:
    SpecialistDecorator(WorkItem* wrapped) : TaskDecorator(wrapped) {}
    
    double getCost() const override;
    std::string getDescription() const override;
};

#endif
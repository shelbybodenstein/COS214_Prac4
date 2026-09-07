#ifndef SAFETYHAZARDDECORATOR_H
#define SAFETYHAZARDDECORATOR_H

#include "TaskDecorator.h"

class SafetyHazardDecorator : public TaskDecorator{

private:

    void performHazardProtocol() const;

public:
    SafetyHazardDecorator(WorkItem* wrapped) : TaskDecorator(wrapped){}
    
    double getCost() const override;
    std::string getDescription() const override;
    void execute() override;
};

#endif
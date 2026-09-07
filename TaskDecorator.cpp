#include "TaskDecorator.h"



TaskDecorator::TaskDecorator(WorkItem* wrapped){

    this->wrapped = wrapped;
}

void TaskDecorator::execute(){

    wrapped->execute();
}

std::string TaskDecorator::getDescription() const{
 
    return wrapped->getDescription();
}
 
double TaskDecorator::getCost() const{
 
    return wrapped->getCost();
}
 
std::string TaskDecorator::getStatus() const{
 
    return wrapped->getStatus();
}
 
Iterator* TaskDecorator::createIterator(){
 
    return wrapped->createIterator();
}
 

void TaskDecorator::add(WorkItem* child){

    wrapped->add(child);
}

void TaskDecorator::remove(WorkItem* child){

    wrapped->remove(child);
}

int TaskDecorator::getChildCount() const{

    return wrapped->getChildCount();
}

WorkItem* TaskDecorator::getChildAt(int index) const{
    
    return wrapped->getChildAt(index);
}




TaskDecorator::~TaskDecorator(){

    delete wrapped;
}
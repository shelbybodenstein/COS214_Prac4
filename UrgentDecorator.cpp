#include "UrgentDecorator.h"

double UrgentDecorator::getCost() const{

    return TaskDecorator::getCost() + 750.0;
}


std::string UrgentDecorator::getDescription() const{

    return TaskDecorator::getDescription() + "[URGENT]";
}
#include "SpecialistDecorator.h"

double SpecialistDecorator::getCost() const{

    return TaskDecorator::getCost() + 1200.0;
}

std::string SpecialistDecorator::getDescription() const{

    return TaskDecorator::getDescription() + " [SPECIALIST]";
}
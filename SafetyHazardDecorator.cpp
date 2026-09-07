#include "SafetyHazardDecorator.h"
#include <iostream>

double SafetyHazardDecorator::getCost() const{

    return TaskDecorator::getCost() + 600.0;
}

std::string SafetyHazardDecorator::getDescription() const{

    return TaskDecorator::getDescription() + " [SAFETY]";
}

void SafetyHazardDecorator::execute(){
    
    performHazardProtocol();
    
    TaskDecorator::execute();
}

void SafetyHazardDecorator::performHazardProtocol() const{

    std::cout << "  Hazard Protocol - Enforcing strict safety zone and PPE requirements." << std::endl;
}
#include "PermitRequiredDecorator.h"

double PermitRequiredDecorator::getCost() const{
    return TaskDecorator::getCost() + 400.0;
}

std::string PermitRequiredDecorator::getDescription() const{

    std::string baseDesc = TaskDecorator::getDescription() + " [PERMIT";
    

    if (wrapped->getStatus() == "Awaiting Inspection"){
        
        return baseDesc + " PENDING SIGN-OFF]";
    }else{
        
        return baseDesc + " FILED]";
    }
}
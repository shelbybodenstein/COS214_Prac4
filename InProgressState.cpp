#include "InProgressState.h"

#include "AwaitingInspectionState.h"

TaskState* InProgressState::handleSubmitForInspection(){

    return new AwaitingInspectionState();
}


std::string InProgressState::getStatusName() const{

    return "In Progress";
}
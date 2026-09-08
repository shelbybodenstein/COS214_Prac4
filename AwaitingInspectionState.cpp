#include "AwaitingInspectionState.h"
#include "InProgressState.h"
#include "CompleteState.h"

TaskState* AwaitingInspectionState::handlePass(){

    return new CompleteState();
}

TaskState* AwaitingInspectionState::handleFail(){

    return new InProgressState();
}


std::string AwaitingInspectionState::getStatusName() const{

    return "Awaiting Inspection";
}

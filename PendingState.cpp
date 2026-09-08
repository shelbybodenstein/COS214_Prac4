#include "PendingState.h"
#include "InProgressState.h"

TaskState* PendingState::handleStart(){

    return new InProgressState();
}


std::string PendingState::getStatusName() const{

    return "Pending";
}

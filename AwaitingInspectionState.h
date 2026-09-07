#ifndef AWAITINGINSPECTIONSTATE_H
#define AWAITINGINSPECTIONSTATE_H

#include "TaskState.h"

class AwaitingInspectionState : public TaskState{

    public:
    TaskState* handlePass() override;
    TaskState* handleFail() override;

    std::string getStatusName() const override;


};


#endif
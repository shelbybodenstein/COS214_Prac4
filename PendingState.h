#ifndef PENDINGSTATE_H
#define PENDINGSTATE_H

#include "TaskState.h"

class PendingState : public TaskState{

public:
    TaskState* handleStart() override;

    std::string getStatusName() const override;

};


#endif
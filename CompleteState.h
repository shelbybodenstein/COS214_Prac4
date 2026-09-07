#ifndef COMPLETESTATE_H
#define COMPLETESTATE_H

#include "TaskState.h"

class CompleteState : public TaskState{


    public:
    std::string getStatusName() const override;


};


#endif
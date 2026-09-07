#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H

#include "TaskState.h"

class InProgressState : public TaskState{


    public:
    TaskState* handleSubmitForInspection() override;

    std::string getStatusName() const override;


};


#endif
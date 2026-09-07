#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>


class TaskState{

public:
    TaskState* handleStart();
    TaskState* handleSubmitForInspection();
    TaskState* handlePass();
    TaskState* handleFail();

    virtual std::string getStatusName() = 0;

    virtual ~TaskState();

};


#endif
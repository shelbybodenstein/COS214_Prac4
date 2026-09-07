#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>


class TaskState{

public:
    virtual TaskState* handleStart();
    virtual TaskState* handleSubmitForInspection();
    virtual TaskState* handlePass();
    virtual TaskState* handleFail();

    virtual std::string getStatusName() const = 0;

    virtual ~TaskState();

};


#endif
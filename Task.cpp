#include "Task.h"
#include "TaskState.h"
#include "PendingState.h"
#include <iostream>

Task::Task(std::string name, double baseCost) 
    : name(name), baseCost(baseCost), state(new PendingState()){
}

void Task::execute(){

    std::cout << getDescription()  << " | Status: " << getStatus() 
              << " | Cost: R" << getCost() << std::endl;
}

std::string Task::getDescription() const{
    return name;
}

double Task::getCost() const{
    return baseCost;
}

std::string Task::getStatus() const{

    return state->getStatusName();
}

Iterator* Task::createIterator(){
    return nullptr; 
}

Task::~Task(){
    delete state;
}

bool Task::start(){

    TaskState* nextState = state->handleStart();

    if (nextState != state){

        delete state;
        state = nextState;
        return true;
    }

    return false;
}

bool Task::submitForInspection(){

    TaskState* nextState = state->handleSubmitForInspection();

    if (nextState != state){

        delete state;
        state = nextState;
        return true;
    }

    return false;
}

bool Task::passInspection(){

    TaskState* nextState = state->handlePass();

    if (nextState != state){

        delete state;
        state = nextState;
        return true;
    }

    return false;
}

bool Task::failInspection(){

    TaskState* nextState = state->handleFail();

    if (nextState != state){

        delete state;
        state = nextState;
        return true;
    }

    return false;
}
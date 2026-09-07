#include "Task.h"
#include "CostReporterI.h"
#include <iostream>

Task::Task(std::string name, double cost) : name(name), cost(cost), status("Pending") {}
Task::~Task() {}

void Task::execute() {
    std::cout << "  [Task Execution] Executing work item: " << name << " (Cost: R" << cost << ")" << std::endl;
    status = "Completed";
}

std::string Task::getDescription() const {
    return "Leaf Task: " + name;
}

double Task::getCost() const {
    return cost;
}

std::string Task::getStatus() const {
    return status;
}

Iterator* Task::createIterator() {
    return new CostReportIterator(this);
}
#include "Phase.h"
#include "CostReporterI.h"

Phase::Phase(std::string name) : WorkGroup(name) {}
Phase::~Phase() {}

void Phase::execute() {
    for (WorkItem* child : children) {
        if (child != nullptr) {
            child->execute();
        }
    }
}

std::string Phase::getDescription() const {
    return "Phase: " + name;
}

double Phase::getCost() const {
    double totalCost = 0.0;
    for (WorkItem* child : children) {
        if (child != nullptr) {
            totalCost += child->getCost();
        }
    }
    return totalCost;
}

std::string Phase::getStatus() const {
    return "In Progress";
}

Iterator* Phase::createIterator() {
    return new CostReportIterator(this);
}
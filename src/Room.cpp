#include "Room.h"
#include "CostReporterI.h"

Room::Room(std::string name) : WorkGroup(name) {}
Room::~Room() {}

void Room::execute() {
    for (WorkItem* child : children) {
        if (child != nullptr) {
            child->execute();
        }
    }
}

std::string Room::getDescription() const {
    return "Room: " + name;
}

double Room::getCost() const {
    double totalCost = 0.0;
    for (WorkItem* child : children) {
        if (child != nullptr) {
            totalCost += child->getCost();
        }
    }
    return totalCost;
}

std::string Room::getStatus() const {
    return "Active Room";
}

Iterator* Room::createIterator() {
    return new CostReportIterator(this);
}
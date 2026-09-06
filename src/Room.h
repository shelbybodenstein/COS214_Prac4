#ifndef ROOM_H
#define ROOM_H
#include "WorkGroup.h"

class Room : public WorkGroup {
public:
    Room(std::string name);
    ~Room() override;

    void execute() override;
    std::string getDescription() const override;
    double getCost() const override;
    std::string getStatus() const override;
    Iterator* createIterator() override;
};
#endif
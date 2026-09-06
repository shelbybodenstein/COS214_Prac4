#ifndef PHASE_H
#define PHASE_H
#include "WorkGroup.h"

class Phase : public WorkGroup {
public:
    Phase(std::string name);
    ~Phase() override;

    void execute() override;
    std::string getDescription() const override;
    double getCost() const override;
    std::string getStatus() const override;
    Iterator* createIterator() override;
};
#endif
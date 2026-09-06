#include "Workgroup.h"

WorkGroup::WorkGroup(std::string name) : name(name) {}

WorkGroup::~WorkGroup() {
    // Recursive destruction of all children to prevent memory leaks
    for (WorkItem* child : children) {
        delete child;
    }
    children.clear();
}

void WorkGroup::add(WorkItem* child) {
    if (child != nullptr) {
        children.push_back(child);
    }
}

void WorkGroup::remove(WorkItem* child) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == child) {
            children.erase(it);
            break;
        }
    }
}

int WorkGroup::getChildCount() const {
    return children.size();
}

WorkItem* WorkGroup::getChildAt(int index) const {
    if (index >= 0 && index < (int)children.size()) {
        return children[index];
    }
    return nullptr;
}
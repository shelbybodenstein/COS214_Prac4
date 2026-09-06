#include "CostReporterI.h"
#include "WorkItem.h"

CostReportIterator::CostReportIterator(WorkItem* rootNode) : root(rootNode) {
    first();
}

CostReportIterator::~CostReportIterator() {}

void CostReportIterator::first() {
    // Clear any existing items in the stack
    while (!traversalStack.empty()) {
        traversalStack.pop();
    }
    // Start fresh from the root
    if (root != nullptr) {
        traversalStack.push(root);
    }
}

void CostReportIterator::next() {
    if (isDone()) return;

    WorkItem* currentItem = traversalStack.top();
    traversalStack.pop();

    // Push children in reverse order for left-to-right depth-first traversal
    for (int i = currentItem->getChildCount() - 1; i >= 0; --i) {
        WorkItem* child = currentItem->getChildAt(i);
        if (child != nullptr) {
            traversalStack.push(child);
        }
    }
}

bool CostReportIterator::isDone() const {
    return traversalStack.empty();
}

WorkItem* CostReportIterator::current() const {
    if (isDone()) return nullptr;
    return traversalStack.top();
}
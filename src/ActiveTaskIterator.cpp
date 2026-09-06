#include "ActiveTaskIterator.h"
#include "WorkItem.h"

ActiveTaskIterator::ActiveTaskIterator(WorkItem* rootNode) : root(rootNode) {
    first();
}

ActiveTaskIterator::~ActiveTaskIterator() {}

void ActiveTaskIterator::findNextLeaf() {
    while (!traversalStack.empty()) {
        WorkItem* curr = traversalStack.top();
        traversalStack.pop();

        if (curr->getChildCount() == 0) {
            // Found a leaf node! Push it back temporarily so current() can return it.
            traversalStack.push(curr);
            break;
        } else {
            // It's a group; expand children in reverse order for correct DFS order
            for (int i = curr->getChildCount() - 1; i >= 0; --i) {
                WorkItem* child = curr->getChildAt(i);
                if (child != nullptr) {
                    traversalStack.push(child);
                }
            }
        }
    }
}

void ActiveTaskIterator::first() {
    while (!traversalStack.empty()) {
        traversalStack.pop();
    }
    if (root != nullptr) {
        traversalStack.push(root);
        findNextLeaf();
    }
}

void ActiveTaskIterator::next() {
    if (isDone()) return;
    
    // Pop the current leaf we just processed
    traversalStack.pop();
    
    // Find the next leaf in the stack
    findNextLeaf();
}

bool ActiveTaskIterator::isDone() const {
    return traversalStack.empty();
}

WorkItem* ActiveTaskIterator::current() const {
    if (isDone()) return nullptr;
    return traversalStack.top();
}
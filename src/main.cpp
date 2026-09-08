#include <iostream>
#include <iomanip>

#include "Phase.h"
#include "Room.h"
#include "Task.h"
#include "Iterator.h"
#include "ActiveTaskIterator.h"
#include "RushOrderDayScenario.h"
#include "ChangeOrderScenario.h"

// Prints one WorkItem through the common Component interface.
// This helps demonstrate that Tasks, Rooms, Phases and decorated Tasks
// can all be treated uniformly as WorkItem objects.
void printWorkItem(WorkItem* item) {
    if (item == nullptr) {
        return;
    }

    std::cout << "  - " << item->getDescription()
              << " | Cost: R" << item->getCost()
              << " | Status: " << item->getStatus()
              << std::endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "====================================================\n";
    std::cout << "       TASKFORGE - CONSTRUCTION PROJECT DAY         \n";
    std::cout << "====================================================\n";

    // ================================================================
    // 1. BUILD THE COMPOSITE HIERARCHY
    // Client -> Phase -> Room -> Task
    // ================================================================
    Phase* constructionPhase = new Phase("Main Infrastructure Phase");

    Room* serverRoom = new Room("Server Room Build");
    Room* officeRoom = new Room("Executive Office Fitout");

    serverRoom->add(new Task("Install Raised Flooring", 15000.0));
    serverRoom->add(new Task("Run Cat6 Network Cabling", 8500.0));
    serverRoom->add(new Task("Mount Server Racks", 12000.0));

    officeRoom->add(new Task("Drywall Partitioning", 20000.0));
    officeRoom->add(new Task("Carpet Tiling", 7500.0));

    constructionPhase->add(serverRoom);
    constructionPhase->add(officeRoom);

    std::cout << "\n[Morning Project Brief]\n";
    std::cout << "Project: " << constructionPhase->getDescription() << std::endl;
    std::cout << "Starting estimated cost: R"
              << constructionPhase->getCost() << std::endl;

    // ================================================================
    // 2. TWO INDEPENDENT ITERATORS OVER THE SAME RUNTIME STRUCTURE
    // ================================================================
    std::cout << "\n[Independent Site Traversals]\n";
    std::cout << "A cost reporter and a task inspector start traversing "
              << "the same project independently.\n";

    Iterator* costTraversal = constructionPhase->createIterator();
    Iterator* taskTraversal = new ActiveTaskIterator(constructionPhase);

    costTraversal->first();
    taskTraversal->first();

    // Advance only the cost traversal to prove that the second iterator
    // maintains its own independent traversal state.
    std::cout << "\nCost traversal starts at:\n";
    printWorkItem(costTraversal->current());

    costTraversal->next();
    std::cout << "After advancing ONLY the cost traversal:\n";
    printWorkItem(costTraversal->current());

    std::cout << "Task traversal is still independently positioned at:\n";
    printWorkItem(taskTraversal->current());

    // Full depth-first traversal for the cost/reporting workflow.
    std::cout << "\n[Full Project Cost Traversal]\n";
    costTraversal->first();
    while (!costTraversal->isDone()) {
        printWorkItem(costTraversal->current());
        costTraversal->next();
    }

    // Second traversal behaviour: leaf tasks only.
    std::cout << "\n[Task-Only Traversal]\n";
    taskTraversal->first();
    while (!taskTraversal->isDone()) {
        printWorkItem(taskTraversal->current());
        taskTraversal->next();
    }

    // Traversal-modification policy:
    // Existing iterators are discarded before a structural change.
    // Fresh iterators are created afterwards so they reflect the new structure.
    delete costTraversal;
    delete taskTraversal;
    costTraversal = nullptr;
    taskTraversal = nullptr;

    // ================================================================
    // 3. RUSH ORDER DAY: STATE + DECORATOR + STRUCTURAL CHANGE
    // ================================================================
    std::cout << "\n====================================================\n";
    std::cout << "                RUSH ORDER ARRIVES                  \n";
    std::cout << "====================================================\n";

    double serverRoomCostBefore = serverRoom->getCost();

    // This scenario demonstrates:
    // - valid State transitions
    // - invalid State transitions being rejected
    // - a failed-inspection/rework loop
    // - dynamic decoration
    // - stacked Specialist + Urgent decorators
    // - removal and reinsertion into the Composite structure
    runRushOrderDayScenario(serverRoom);

    std::cout << "\nServer room cost before rush order: R"
              << serverRoomCostBefore << std::endl;
    std::cout << "Server room cost after rush order:  R"
              << serverRoom->getCost() << std::endl;
    std::cout << "Updated total project cost:         R"
              << constructionPhase->getCost() << std::endl;

    // The structure changed during the rush-order scenario, so according to
    // our traversal policy we create a NEW iterator instead of reusing an old one.
    std::cout << "\n[Fresh Traversal After Runtime Modification]\n";
    Iterator* refreshedTraversal = constructionPhase->createIterator();

    for (refreshedTraversal->first();
         !refreshedTraversal->isDone();
         refreshedTraversal->next()) {
        printWorkItem(refreshedTraversal->current());
    }

    delete refreshedTraversal;
    refreshedTraversal = nullptr;

    // ================================================================
    // 4. CHANGE ORDER: MODIFY THE COMPOSITE AT RUNTIME
    // ================================================================
    std::cout << "\n====================================================\n";
    std::cout << "                CHANGE ORDER RECEIVED               \n";
    std::cout << "====================================================\n";

    ChangeOrderScenario::run(constructionPhase);

    // Again, a new iterator is created after the structural modification.
    std::cout << "[Project Structure After Change Order]\n";
    Iterator* afterChangeOrder = constructionPhase->createIterator();

    for (afterChangeOrder->first();
         !afterChangeOrder->isDone();
         afterChangeOrder->next()) {
        printWorkItem(afterChangeOrder->current());
    }

    delete afterChangeOrder;
    afterChangeOrder = nullptr;

    // ================================================================
    // 5. CLEANUP / OWNERSHIP
    // ================================================================
    std::cout << "\n[End of Day]\n";
    std::cout << "Final estimated project cost: R"
              << constructionPhase->getCost() << std::endl;

    // constructionPhase owns its children through WorkGroup.
    // WorkGroup recursively deletes Rooms, Tasks and outer decorators.
    // Each TaskDecorator owns and deletes the object it wraps.
    delete constructionPhase;
    constructionPhase = nullptr;

    std::cout << "\n====================================================\n";
    std::cout << "       TASKFORGE COMPLETED AND CLEANED UP            \n";
    std::cout << "====================================================\n";

    return 0;
}

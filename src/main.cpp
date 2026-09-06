#include <iostream>
#include "Phase.h"
#include "Room.h"
#include "Task.h"
#include "CostReporterI.h"
#include "ActiveTaskIterator.h"
#include "ChangeOrderScenario.h"

int main() {
    std::cout << "=========================================" << std::endl;
    std::cout << "     TaskForge: Execution Engine         " << std::endl;
    std::cout << "=========================================" << std::endl;

    // Level 1: Root Phase Composite
    Phase* constructionPhase = new Phase("Main Infrastructure Phase");

    // Level 2: Room Composites inside the Phase
    Room* serverRoom = new Room("Server Room Build");
    Room* officeRoom = new Room("Executive Office Fitout");

    // Level 3: Leaf Tasks inside the Rooms
    serverRoom->add(new Task("Install Raised Flooring", 15000.0));
    serverRoom->add(new Task("Run Cat6 Network Cabling", 8500.0));
    serverRoom->add(new Task("Mount Server Racks", 12000.0));

    officeRoom->add(new Task("Drywall Partitioning", 20000.0));
    officeRoom->add(new Task("Carpet Tiling", 7500.0));

    // Assemble the 3-level hierarchy under the Phase root
    constructionPhase->add(serverRoom);
    constructionPhase->add(officeRoom);

    std::cout << "\n[Hierarchy Summary]" << std::endl;
    std::cout << "Total Estimated Project Cost: R" << constructionPhase->getCost() << std::endl;

    // --- Demonstration 1: CostReportIterator (Full Depth-First Traversal) ---
    std::cout << "\n--- Demonstration 1: CostReportIterator (All Nodes) ---" << std::endl;
    Iterator* costIterator = constructionPhase->createIterator();
    for (costIterator->first(); !costIterator->isDone(); costIterator->next()) {
        WorkItem* item = costIterator->current();
        if (item != nullptr) {
            std::cout << "Visited -> " << item->getDescription() 
                      << " | Cost: R" << item->getCost() 
                      << " | Status: " << item->getStatus() << std::endl;
        }
    }
    delete costIterator;

    // --- Demonstration 2: ActiveTaskIterator (Leaf-Only Filtering Traversal) ---
    std::cout << "\n--- Demonstration 2: ActiveTaskIterator (Leaf Tasks Only) ---" << std::endl;
    Iterator* taskIterator = new ActiveTaskIterator(constructionPhase);
    for (taskIterator->first(); !taskIterator->isDone(); taskIterator->next()) {
        WorkItem* item = taskIterator->current();
        if (item != nullptr) {
            std::cout << "Active Task Found -> " << item->getDescription() 
                      << " (Cost: R" << item->getCost() << ")" << std::endl;
        }
    }
    delete taskIterator;

    // --- Demonstration 3: Runtime Change Order Scenario ---
    // Tests structural modification and checks how the hierarchy updates
    ChangeOrderScenario::run(constructionPhase);

    // --- Cleanup ---
    // Safe polymorphic recursive destruction (handled by WorkGroup destructor)
    delete constructionPhase;

    std::cout << "\n=========================================" << std::endl;
    std::cout << "   TaskForge Execution Completed Cleanly " << std::endl;
    std::cout << "=========================================" << std::endl;

    return 0;
}
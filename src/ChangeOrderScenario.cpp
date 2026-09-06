#include "ChangeOrderScenario.h"
#include "Room.h"
#include <iostream>

void ChangeOrderScenario::run(WorkItem* projectRoot) {
    std::cout << "\n--- Executing Scenario 1: Change Order (Structural Modification) ---" << std::endl;
    std::cout << "Original project root cost before change: " << projectRoot->getCost() << std::endl;

    // Dynamically add a new Room as a change order during execution
    Room* extraRoom = new Room("Emergency Repair Bay");
    projectRoot->add(extraRoom);

    std::cout << "Added 'Emergency Repair Bay' mid-execution." << std::endl;
    std::cout << "Updated project root cost: " << projectRoot->getCost() << std::endl;
    std::cout << "--- Scenario 1 Completed Successfully ---\n" << std::endl;
}
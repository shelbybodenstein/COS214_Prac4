#include "RushOrderDayScenario.h"
#include "Task.h"
#include "SpecialistDecorator.h"
#include "UrgentDecorator.h"
#include <iostream>

void runRushOrderDayScenario(WorkItem* targetRoom) {
    std::cout << "\nStarting Rush Order Day Scenario" << std::endl;

    Task* floorTiling = new Task("Tile the bathroom floor", 900.0);
    Task* fixtureInstall = new Task("Install bathroom fixtures", 1400.0);

    targetRoom->add(floorTiling);
    targetRoom->add(fixtureInstall);

    std::cout << "\n[Step 1] Starting floor tiling" << std::endl;

    if (floorTiling->start()){

        std::cout << "   -> Success. Status: " << floorTiling->getStatus() << std::endl;
    }

    std::cout << "[Step 2] Submitting floor tiling for inspection" << std::endl;

    if (floorTiling->submitForInspection()){

        std::cout << "   -> Success. Status: " << floorTiling->getStatus() << std::endl;
    }

    std::cout << "[Step 3] Failing inspection (triggering rework loop)" << std::endl;
    if (floorTiling->failInspection()){

        std::cout << "   -> Success. Status: " << floorTiling->getStatus() << std::endl;
    }

    std::cout << "[Step 4] Re-submitting for inspection" << std::endl;
    if (floorTiling->submitForInspection()){

        std::cout << "   -> Success. Status: " << floorTiling->getStatus() << std::endl;
    }

    std::cout << "[Step 5] Passing inspection" << std::endl;
    if (floorTiling->passInspection()){

        std::cout << "   -> Success. Status: " << floorTiling->getStatus() << std::endl;
    }

    std::cout << "[Step 6] Attempting to restart completed task (Terminal-state rejection)" << std::endl;
    if (!floorTiling->start()){

        std::cout << "   -> Rejected: Task is already Completed. State unchanged." << std::endl;
    }

    std::cout << "\n[Step 7] Attempting to pass inspection on a Pending task (Skip-ahead rejection)" << std::endl;
    if (!fixtureInstall->passInspection()){
        
        std::cout << "   -> Rejected: cannot pass inspection on a Pending task — nothing changed." << std::endl;
    }

    std::cout << "\n[Step 8] Decorating fixtureInstall for Rush Order" << std::endl;

    targetRoom->remove(fixtureInstall);

    WorkItem* decorated = new SpecialistDecorator(fixtureInstall);
    decorated = new UrgentDecorator(decorated);

    targetRoom->add(decorated);

    std::cout << "   -> New Description: " << decorated->getDescription() << std::endl;
    std::cout << "   -> New Cost: R" << decorated->getCost() << std::endl;

    std::cout << "\nScenario Complete" << std::endl;
}
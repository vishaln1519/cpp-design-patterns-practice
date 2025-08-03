#include "builder_pattern.hpp"
#include <memory>
#include <iostream>

namespace cb = car_builder;

int main() {

    
    cb::Orchestrator fordOrchestrator(std::make_unique<cb::FordBuilder>());
    auto fordCar = fordOrchestrator.createCar();
    fordCar->show();

    std::cout << "------------------\n";

    cb::Orchestrator vwOrchestrator(std::make_unique<cb::VWBuilder>());
    auto vwCar = vwOrchestrator.createCar();
    vwCar->show();

    return 0;
}
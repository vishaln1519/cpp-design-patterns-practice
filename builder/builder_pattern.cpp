#include "builder_pattern.hpp"

namespace cb = car_builder;

// ---------------- Car ----------------
void cb::Car::setType(const std::string& type) 
{
     this->type = type; 
}
void cb::Car::setEngine(const std::string& engine) 
{ 
    this->engine = engine; 
}
void cb::Car::setWheels(const std::string& wheels) 
{
     this->wheels = wheels; 
}

void cb::Car::show() const 
{
    std::cout << "Car Type: " << type
              << "\nEngine: " << engine
              << "\nWheels: " << wheels << std::endl;
}

// ---------------- CarBuilder ----------------

std::unique_ptr<cb::Car> cb::CarBuilder::getCar()
{
    return std::move(car);
}

// ---------------- Ford Builder ----------------
cb::FordBuilder::FordBuilder()
{
    car = std::make_unique<Car>();
    car->setType("Ford");
}

void cb::FordBuilder::buildEngine()
{
   car->setEngine("Ford EcoBoost Engine");
}

void cb::FordBuilder::buildWheels()
{
   car->setWheels("Ford Alloy Wheels");
}

// ---------------- VW Builder ----------------

cb::VWBuilder::VWBuilder()
{
    car = std::make_unique<Car>();
    car->setType("VW");
}

void cb::VWBuilder::buildEngine()
{
    car->setEngine("VW TSI Engine");
}

void cb::VWBuilder::buildWheels()
{
    car->setWheels("VW Sport Wheels");
}

// ---------------- Orchestrator ----------------
std::unique_ptr<cb::Car> cb::Orchestrator::createCar()
{
    carBuilder->buildEngine();
    carBuilder->buildWheels();
    return carBuilder->getCar();
}

cb::Orchestrator::Orchestrator(std::unique_ptr<cb::CarBuilder> builder)
    : carBuilder(std::move(builder)) {}

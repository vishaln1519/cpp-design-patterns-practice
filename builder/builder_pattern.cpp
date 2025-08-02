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



int main()
{
    
}
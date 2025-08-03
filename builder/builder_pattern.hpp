
#include <iostream>
#include <memory>

namespace car_builder
{

    class Car 
    {
        public:
            void setType(const std::string &type);
            void setEngine(const std::string &engine);
            void setWheels(const std::string &wheels);
            void show() const;

        private:
            std::string type;
            std::string engine;
            std::string wheels;
        
    };

    //CarBuilder Interface 
    class CarBuilder
    {
        public:
            virtual void buildEngine() = 0;
            virtual void buildWheels() = 0;
            std::unique_ptr<Car> getCar();

        protected:
            std::unique_ptr<Car> car;
    };

    // Concrete Builder : Ford 
    class FordBuilder :public CarBuilder
    {
        public:
            FordBuilder();
            void buildEngine() override;
            void buildWheels() override;
    };

    // Concrete Builder : VW
    class VWBuilder :public CarBuilder
    {
        public:
        VWBuilder();
        void buildEngine() override;
        void buildWheels() override;
    };

    // Orchestrator

    class Orchestrator
    {
        public:
            Orchestrator(std::unique_ptr<CarBuilder> builder);
            std::unique_ptr<Car> createCar();

        private:
            std::unique_ptr<CarBuilder> carBuilder;
    }; 



}
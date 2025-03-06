//
// Created by Andreea on 4/22/2024.
//
#include<fstream>
#include "RentalAgency.h"
RentalAgency::~RentalAgency() {
    for( auto vehicle: inventory)
        delete vehicle;
}

void RentalAgency::addVehicle(Vehicle *vehicle) {
    inventory.push_back(vehicle);
}

void RentalAgency::displayAllVehicles() const {
    std::cout<<" display all vehicles:"<<std::endl;
    for( auto vehicle: inventory)
        std::cout<<*vehicle;
}

void RentalAgency::displayAllAvailableVehicles(const std::string &vehicleType) const {
    std::cout<<" availables vehicles: "<<vehicleType<<std::endl;
    for( auto vehicle: inventory){
        if(vehicleType=="car" && dynamic_cast<Car*>(vehicle))
            std::cout<<*vehicle;
        else if(vehicleType=="bike" && dynamic_cast<Bike*>(vehicle))
            std::cout<<*vehicle;
    }
    /*std::cout<<" availables vehicles: "<<vehicleType<<std::endl;
    if(vehicleType=="car")
        for(auto vehicle: inventory)
            if(vehicle->type())
                std::cout<<*vehicle<<std::endl;

            else{
                for(auto vehicle: inventory)
                    if(!vehicle->type())
                        std::cout<<*vehicle<<std::endl;
            }*/
}

std::ostream &operator<<(std::ostream os, const RentalAgency *rental) {
    rental->displayAllVehicles();
    return os;
}

double RentalAgency::calculateRentalChange(const string &model, int days) const {
    for( auto vehicle : inventory){
        if(vehicle->getModel()==model){
            return vehicle->getDailyRate()*days;
        }
    }
    throw std::invalid_argument{"vehicle model invalid "};
}

void RentalAgency::saveInventoryToFile(std::string &filename)  {
    std::ofstream file{filename};
    if(!file.is_open()){
        throw std::runtime_error("Unable to open the file.");
    }
    for(auto vehicle:inventory){
        file<<vehicle->getModel()<<","<<vehicle->getYear()<<","<<vehicle->getDailyRate()<<std::endl;
    }
    file.close();
    std::cout<<"inventory saved to "<<filename<<std::endl;
}



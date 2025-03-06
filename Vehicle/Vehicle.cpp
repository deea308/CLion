//
// Created by Andreea on 4/22/2024.
//

#include "Vehicle.h"
Vehicle::Vehicle(const string &m, int y, double dR) {
    model=m; year=y; dailyRate=dR;
    setDailyRate(dailyRate);
}

double Vehicle::getDailyRate() const {
    return dailyRate;
}

void Vehicle::setDailyRate(double rate) {
    if(rate<10)
        throw std::invalid_argument{" Invalid daily rate! "};
    else
        dailyRate=rate;
}
std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle){
    os<<"Model: "<<vehicle.model<<" Year: "<<vehicle.year<<" Rate: "<<vehicle.dailyRate<<std::endl;
    return os;
}
void Vehicle::display() const{
    std::cout<<"Model: "<<model<<" Year: "<<year<<" Rate: "<<dailyRate<<std::endl;
}

string Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

Car::~Car() {}

Bike::~Bike() {}

Car::Car(const string& m, int y, double dR, int s, std::string fT): Vehicle(m,y,dR) {
    seats=s;
    fuelType=fT;
}

void Car::setSeats(int seat) {
    if(seat>10)
        throw  std::runtime_error{"invalid number of seats!"};
}
void Car::display() const{
    Vehicle::display();
    std::cout<<"No. seats: "<<seats<<" Fuel type: "<<fuelType<<std::endl;
}

bool Car::type() const {
    return true;
}

Bike::Bike(const string& m, int y, double dR, string bT): Vehicle(m,y,dR) {
    bikeType=bT;
}

void Bike::display() const {
    Vehicle::display();
    std::cout<<" Bike type: "<<bikeType<<std::endl;
}

bool Bike::type() const {
    return false;
}

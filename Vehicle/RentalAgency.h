//
// Created by Andreea on 4/22/2024.
//

#ifndef VEHICLE_RENTALAGENCY_H
#define VEHICLE_RENTALAGENCY_H
#include "Vehicle.h"
#include<vector>

class RentalAgency {
private:
    std::vector<Vehicle*> inventory;
public:
    RentalAgency()=default;
    ~RentalAgency();
    void addVehicle(Vehicle* vehicle);
    void displayAllVehicles() const;
    void displayAllAvailableVehicles(const std::string &vehicleType) const;
    friend std::ostream& operator<<(std::ostream os, const RentalAgency* rental);
    double calculateRentalChange(const std::string &model, int days) const;
    void saveInventoryToFile(std::string &filename);
};


#endif //VEHICLE_RENTALAGENCY_H

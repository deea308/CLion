//
// Created by Andreea on 4/22/2024.
//

#ifndef VEHICLE_VEHICLE_H
#define VEHICLE_VEHICLE_H
#include<iostream>
#include<string>
using std::string;

class Vehicle {
protected:
    string model;
    int year;
    double dailyRate;
public:
    Vehicle(const string& m, int y, double dR);
    void setDailyRate(double rate);
    double getDailyRate() const;
    string getModel() const;
    int getYear() const;
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
    virtual bool type() const=0;
    virtual void display() const=0;
};

class Car: public Vehicle{
private:
    int seats;
    string fuelType;
public:
    Car(const string& m, int y, double dR, int s, string fT);
    void setSeats(int seat);
    void display() const override;
    bool type() const override;
    ~Car();
};

class Bike: public Vehicle{
private:
    string bikeType;
public:
    Bike(const string& m, int y, double dR, string bT);
    bool type() const override;
    void display() const override;
    ~Bike();
};
#endif //VEHICLE_VEHICLE_H

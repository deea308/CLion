#include <iostream>
#include "RentalAgency.h"
#include "Vehicle.h"
#include<vector>
#include<stdexcept>

void menu(){
   std::cout<<"\nMenu:\n"
            <<"1. Display all vehicles\n"
            <<"2. Add a new vehicle\n"
            <<"3. Display available vehicles of a type(car or bike)\n"
            <<"4. Calculate rental charge for a vehical\n"
            <<"5. Write the agency's vehicle inventory in a text file\n"
            <<"6. Exit\n"
            <<" Enter your choice: ";
}


int main() {
    RentalAgency agency;
    try {
        Car c("Ford",2014,50,5,"Gasoline");
        agency.addVehicle(new Car("Ford",2014,50,5,"Gasoline"));
        agency.addVehicle(new Car("Opel",2011,40,5,"Diesel"));
        agency.addVehicle(new Car("Tesla",2023,90,4,"Electric"));
        agency.addVehicle(new Bike("Mountain Bike",2023,20,"Mountain"));
        int choice;
        do{
            menu();
            std::cin>>choice;
            if(choice==1)
                agency.displayAllVehicles();
            else if(choice==2){
                std::string type, model,fuelType,bikeType;
                int year, seats;
                double dailyRate;
                std::cout<<"Enter vehicle type(Car or Bike): ";
                std::cin>>type;
                std::cout<<"Enter the model: ";
                std::cin>>model;
                std::cout << "Enter year: ";
                std::cin >> year;

                std::cout << "Enter daily rate: ";
                std::cin >> dailyRate;
                std::cout<<std::endl;
                if(type=="Car")
                {
                    std::cout << "Enter number of seats: ";
                    std::cin >> seats;

                    std::cout << "Enter fuel type: ";
                    std::cin >> fuelType;
                    agency.addVehicle(new Car(model,year,dailyRate,seats,fuelType));
                }
                else{
                    std::cout << "Enter bike type: ";
                    std::cin >> bikeType;
                    agency.addVehicle(new Bike(model,year,dailyRate,bikeType));
                }
            } else if(choice==3){
                std::string type;
                std::cout<<"Enter vehicle type(Car or Bike): ";
                std::cin>>type;
                agency.displayAllAvailableVehicles(type);
            } else if(choice==4){
                std::string type;
                std::string model;
                std::cout<<"Choose a vehicle type(Car or Bike): ";
                std::cin>>type;
                if(type=="Car"){
                    std::cout<<"Choose a Car model: ";
                    std::cin>>model;
                }else {
                    std::cout<<"Choose a Bike model: ";
                    std::cin>>model;
                }
                int days;
                std::cout << "Enter number of days: ";
                std::cin >> days;
                try{
                    double charge=agency.calculateRentalChange(model,days);
                    std::cout<<"rental charge for "<<type<<" "<<model<<" for "<<days<<" days:$ "<<charge<<std::endl;
                }catch(const std::invalid_argument& e){
                    std::cout<<e.what()<<std::endl;
                }
            }else if(choice==5){
                    std::string filename;
                    std::cout<<"enter filename to save: ";
                    std::cin>>filename;
                    try {
                        agency.saveInventoryToFile(filename);
                    } catch (const std::runtime_error &e) {
                        std::cerr << e.what() << std::endl;
                    }
                    break;
            }else if(choice==6){
                std::cout << "Exiting...\n";
                break;
            }
        }while(choice!=6);
    }catch(const std::invalid_argument& e){
        std::cout<< "invalid argument"<<e.what()<<std::endl;
    }catch(const std::exception& e){
        std::cout<<"error:"<<e.what()<<std::endl;
    }

    return 0;
}


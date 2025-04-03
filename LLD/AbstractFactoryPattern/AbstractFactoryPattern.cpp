#include<bits/stdc++.h>
using namespace std;

class vehicle{
    public:
        virtual void vehicleName() = 0;
        virtual void numberOfWheels() = 0;
        virtual void numberOfSeats() = 0;
        virtual void loadCapacity() = 0;
        virtual ~vehicle() {}
};

class hatchback : public vehicle{
    public:
        void vehicleName() override{
            cout<<"Vehicle Name: Tata Nexon"<<endl;
        }

        void numberOfWheels() override{
            cout<<"Number of Wheels: 4"<<endl;
        }

        void numberOfSeats() override{
            cout<<"Number of Seats: 4"<<endl;
        }

        void loadCapacity() override{
            cout<<"Load Capacity: 50KG"<<endl;
        }
};

class suv : public vehicle{
    public:
        void vehicleName() override{
            cout<<"Vehicle Name: Fortuner"<<endl;
        }

        void numberOfWheels() override{
            cout<<"Number of Wheels: 4"<<endl;
        }

        void numberOfSeats() override{
            cout<<"Number of Seats: 7"<<endl;
        }

        void loadCapacity() override{
            cout<<"Load Capacity: 100KG"<<endl;
        }
};

class miniTruck : public vehicle{
    public:
        void vehicleName() override{
            cout<<"Vehicle Name: Tata Ace"<<endl;
        }

        void numberOfWheels() override{
            cout<<"Number of Wheels: 4"<<endl;
        }

        void numberOfSeats() override{
            cout<<"Number of Seats: 2"<<endl;
        }

        void loadCapacity() override{
            cout<<"Load Capacity: 500KG"<<endl;
        }
};

class dumper : public vehicle{
    public:
        void vehicleName() override{
            cout<<"Vehicle Name: Scania Dumper"<<endl;
        }

        void numberOfWheels() override{
            cout<<"Number of Wheels: 12"<<endl;
        }

        void numberOfSeats() override{
            cout<<"Number of Seats: 2"<<endl;
        }

        void loadCapacity() override{
            cout<<"Load Capacity: 5000KG"<<endl;
        }
};

class factoryVehicle{
    public:
        virtual vehicle* getObjectSmall() = 0;
        virtual vehicle* getObjectLarge() = 0;
        virtual ~factoryVehicle() {}
};

class carFactory : public factoryVehicle{
    public:
        vehicle* getObjectSmall() override{
            return new hatchback();
        }
        vehicle* getObjectLarge() override{
            return new suv();
        }
};

class truckFactory : public factoryVehicle{
    public:
        vehicle* getObjectSmall() override{
            return new miniTruck();
        }
        vehicle* getObjectLarge() override{
            return new dumper();
        }
};

class factoryDecider{
    public:
        factoryVehicle* getFactory(string factory){
            if(factory == "carFactory"){
                return new carFactory();
            }else{
                return new truckFactory();
            }
        }
};

int main(){
    factoryDecider factoryDecider;
    factoryVehicle* factory1 = factoryDecider.getFactory("carFactory");
    factoryVehicle* factory2 = factoryDecider.getFactory("truckFactory");
    vehicle* veh1 = factory1->getObjectSmall();
    vehicle* veh2 = factory2->getObjectLarge();
    vehicle* veh3 = factory1->getObjectLarge();
    vehicle* veh4 = factory2->getObjectSmall();

    vector<vehicle*> vehiclesList = {veh1, veh2, veh3, veh4};
    for(auto* veh: vehiclesList){
        veh->vehicleName();
        veh->numberOfSeats();
        veh->numberOfWheels();
        veh->loadCapacity();
        cout<<endl<<endl;
    }

    for(auto* veh: vehiclesList){
        delete veh;
    }
    delete factory1;
    delete factory2;

    return 0;
}

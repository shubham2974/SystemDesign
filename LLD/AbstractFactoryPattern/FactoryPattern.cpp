#include<bits/stdc++.h>
using namespace std;

class vehicle{
    public:
        virtual void numberOfWheels() = 0;
        virtual void vehicleName() = 0;
        virtual ~vehicle() {};
};

class car : public vehicle {
    public:
        void numberOfWheels() override {
            cout<<"No of Wheels : 4"<<endl;
        }

        void vehicleName() override {
            cout<<"Vehicle Name : Fortuner"<<endl; 
        }
};

class truck : public vehicle {
    public: 
        void numberOfWheels() override {
            cout<<"No of Wheels : 12"<<endl;
        }

        void vehicleName() override {
            cout<<"Vehicle Name : Tata Truck"<<endl;
        }
};

class factoryVehicle {
    public: 
    vehicle* getObject(string vehicle){
        if(vehicle == "car"){
            return new car();
        }else{
            return new truck();
        }
    }
};

int main(){
    factoryVehicle* factory = new factoryVehicle();
    vehicle* veh1 = factory->getObject("car");
    vehicle* veh2 = factory->getObject("truck");
    veh1->numberOfWheels();
    veh1->vehicleName();
    veh2->numberOfWheels();
    veh2->vehicleName();

    delete factory;
    delete veh1;
    delete veh2;
    return 0;

}
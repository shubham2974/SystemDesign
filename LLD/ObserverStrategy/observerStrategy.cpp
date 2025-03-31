#include<bits/stdc++.h>
using namespace std;

class displayInterface{
    public:
        virtual void update() = 0;
};

class observableInterface{
    public:
        virtual void add(displayInterface* obj) = 0;
        virtual void remove(displayInterface* obj) = 0;
        virtual void notify() = 0;
        virtual void setData(int newTemp) = 0;
        virtual int getData() = 0;  // Must return an int
};


class wsObserver : public observableInterface{
    public:
        static int currTemp;
        vector<displayInterface*> observerList;
        
        void add(displayInterface* obj) override{
            observerList.push_back(obj);
        }

        void remove(displayInterface* obj) override{
            // This function will remove the element from the list
        }
        
        void notify() override{
            for(const auto& observer: observerList){
                observer->update();
            }
        }
        
        void setData(int newTemp){
            if(currTemp != newTemp){
                currTemp = newTemp;
                notify();
            }
        }

        int getData(){
            return currTemp;
        }
    };
    
class stocksObserver : public observableInterface{
    public:
        static int stockPrice;
        vector<displayInterface*> observerList;
        
        void add(displayInterface* obj) override{
            observerList.push_back(obj);
        }
        
        void remove(displayInterface* obj) override{
            // This function will remove the element from the list
        }
        
        void notify() override{
            for(const auto& observer: observerList){
                observer->update();
            }
        }
        
        void setData(int newStockPrice){
            if(stockPrice != newStockPrice){
                stockPrice = stockPrice + newStockPrice;
                notify();
            }
        }
        
        int getData(){
            return stockPrice;
        }
};
    
class mobileDisplay : public displayInterface{
    public:
        observableInterface* obj;
        mobileDisplay(observableInterface* obj){
            this->obj = obj;
        }
        
        void update() override{
            display();
        }
    private:
        void display(){
            int value = obj->getData();
            if(dynamic_cast<wsObserver*>(obj)){
                cout<<"Current Temperature: "<<value<<endl;
            }else{
                cout<<"Current Stock Value: "<<value<<endl;
            }
            cout<<"Interface: Mobile"<<endl;
        }
};
    
class tvDisplay : public displayInterface{
    public:
        observableInterface* obj;
        tvDisplay(observableInterface* obj){
            this->obj = obj;
        }
    
        void update() override{
            display();
        }
    private: 
        void display(){
            int value = obj->getData();
            if(dynamic_cast<wsObserver*>(obj)){
                cout<<"Current Temperature: "<<value<<endl;
            }else{
                cout<<"Current Stock Value: "<<value<<endl;
            }
            cout<<"Interface: Television"<<endl;
        }
};
    
int wsObserver::currTemp = 0;
int stocksObserver::stockPrice = 0;

int main(){
    observableInterface* weather = new wsObserver();
    observableInterface* stocks = new stocksObserver();

    // Weather Subscribers
    displayInterface* user1 = new mobileDisplay(weather);
    displayInterface* user2 = new tvDisplay(weather);
    displayInterface* user3 = new tvDisplay(weather);
    displayInterface* user4 = new mobileDisplay(weather);

    weather->add(user1);
    weather->add(user2);
    weather->add(user3);
    weather->add(user4);

    // Stocks price Subscribers
    displayInterface* st_user1 = new tvDisplay(stocks);
    displayInterface* st_user2 = new tvDisplay(stocks);
    displayInterface* st_user3 = new mobileDisplay(stocks);

    stocks->add(st_user1);
    stocks->add(st_user2);
    stocks->add(st_user3);


    // Live Frequencies
    weather->setData(20);
    cout<<endl<<endl;
    stocks->setData(40);
    cout<<endl<<endl;
    weather->setData(50);

    cout<<endl<<endl;
    stocks->setData(-20);
    cout<<endl<<endl;
    weather->setData(50);
    cout<<endl<<endl;
    stocks->setData(70);
    cout<<endl<<endl;

    delete user1;
    delete user2;
    delete user3;
    delete user4;
    delete weather;
    delete st_user1;
    delete st_user2;
    delete st_user3;
    delete stocks;

    return 0;
}
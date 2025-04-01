#include <bits/stdc++.h>
using namespace std;

class basePizza {
    public:
        virtual ~basePizza() {}  // Virtual destructor is needed for correct deletion of derived class *ptr variable
        virtual int cost() = 0;
        virtual string getOrder() = 0;
};

class thinCrust : public basePizza {
    public:
        int cost() override {
            return 100;
        }

        string getOrder() override {
            return "thinCrust_";
        }
};

class margherita : public basePizza {
    public:
        int cost() override {
            return 150;
        }

        string getOrder() override {
            return "Margherita_";
        }
};

class cheeseBurst : public basePizza {
    public:
        int cost() override {
            return 200;
        }

        string getOrder() override {
            return "CheeseBurst_";
        }
};

class addOns : public basePizza {
    public:
        basePizza* base;
        addOns(basePizza* base) : base(base) {}
        virtual ~addOns() { delete base; }  // Destructor to free memory
};

class italian : public addOns {
    public:
        italian(basePizza* base) : addOns(base) {}
        int cost() override {
            return base->cost() + 50;
        }

        string getOrder() override{
            return base->getOrder() + "Italian_";
        }
};

class mexican : public addOns {
    public:
        mexican(basePizza* base) : addOns(base) {}
        int cost() override {
            return base->cost() + 80;
        }

        string getOrder() override{
            return base->getOrder() + "Mexican_";
        }
};

class mozzarella : public addOns {
    public:
        mozzarella(basePizza* base) : addOns(base) {}
        int cost() override {
            return base->cost() + 90;
        }

        string getOrder() override{
            return base->getOrder() + "Mozzarella_";
        }
};

class paneer : public addOns {
    public:
        paneer(basePizza* base) : addOns(base) {}
        int cost() override {
            return base->cost() + 100;
        }

        string getOrder() override{
            return base->getOrder() + "Paneer_";;
        }
};

class chicken : public addOns {
    public:
        chicken(basePizza* base) : addOns(base) {}
        int cost() override {
            return base->cost() + 150;
        }

        string getOrder() override{
            return base->getOrder() + "Chicken_";
        }
};

int main() {
    basePizza* pizza1 = new mozzarella(new chicken(new cheeseBurst()));
    cout << "Price: " << pizza1->cost() << endl;
    cout << "Order: " << pizza1->getOrder()<< endl << endl;
    delete pizza1;  // Proper deletion

    basePizza* pizza2 = new paneer(new italian(new thinCrust()));
    cout << "Price: " << pizza2->cost() << endl;
    cout << "Order: " << pizza2->getOrder()<< endl << endl;
    delete pizza2;  // Proper deletion

    return 0;
}

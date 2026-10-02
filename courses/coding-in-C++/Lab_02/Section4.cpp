#include <iostream>
#include <cstdint>

class DrinkBuilder{
    private:
    std::string name= "";
    int sugar=0;
    int temperature=0;
    bool withmilk = false;
    static constexpr int DEFAULT_TEMP =20;

    public: 
    DrinkBuilder &setName(const std::string& name){
        this->name= name;
        return *this;
    }

    DrinkBuilder &setSugar(int Sugar){
        this->sugar = Sugar;
        return *this;
    }
    DrinkBuilder &setTemperature(int temp){
        temp= temperature;
        return *this;
    }
    DrinkBuilder &setWithMilk(bool withMilk){
        this->withmilk= withMilk;
        return *this;
    }
    DrinkBuilder &print(){
        std::cout<< "Drink: "<<name<<"\n";
        std::cout<< "Sugar: "<<sugar<<"\n";
        std::cout<< "Temperature: "<<temperature<<"\n";
        std::cout<< "With Milk: "<<withmilk<<"\n";
        return *this;
    }
};

int main(){
    DrinkBuilder builder;
    builder.setName("Tea")
       .setSugar(2)
       .setTemperature(65)
       .setWithMilk(true)
       .print();

    return 0;
}
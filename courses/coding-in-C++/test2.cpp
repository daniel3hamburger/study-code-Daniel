#include <iostream>
class Smartdevice{
    protected:
    std::string name;
    double base_power_consumption;
    bool is_on;
    public:
    Smartdevice(std::string name, double base_power_consumption, bool is_on)
    :name(name),base_power_consumption(base_power_consumption),is_on(is_on){}
    virtual ~Smartdevice(){
        std::cout<<"Destructor Smartdevice";
    }

    void togglePower(){
        is_on= true;
    }

    virtual double calculateCurrentConsumption() const=0;

    virtual void printDetails() const;

};

class Smartlight:public Smartdevice{
    private:
    int brightness;

    public:
    Smartlight(std::string name, double base_power_consumption, bool is_on, int brightness)
    :Smartdevice(name,base_power_consumption,is_on), brightness(brightness){}
    double calculateCurrentConsumption()const override{
        return base_power_consumption*(brightness/100);
    }

};

class Smartheater:public Smartdevice{
    private:
    double target_temperature;

    public:
    Smartheater(std::string name, double base_power_consumption, bool is_on, double target_temperature):
    Smartdevice( name,  base_power_consumption,  is_on), target_temperature(target_temperature){}
    double calculateCurrentConsumption()const override{
        if (target_temperature> 22)
        {
            return base_power_consumption*1.5;
        }
        return base_power_consumption;
    }
};

class smarthome{
    private:
    int capacity;
    int count;
    int array[];

    public:
    void addDevice(Smartdevice& device){
        
    }

    double calculateTotalConsumption()const {

    }

    void generateReport(){

    }
};   
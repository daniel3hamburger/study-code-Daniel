#include <iostream>
#include <stdexcept>
class SensorFailureError: public std::exception{
    private:
    std::string message;
    public:
    SensorFailureError(const std::string& msg):message(msg){}
    virtual const char* what() const noexcept override{
        return message.c_str();
    }
};

class Sensor{
    private:
    std::string name;
    double current_value;
    double Min_Value=1;
    double Max_Value= 100;

    public:
    void add_sensor(std::string name, double current_value, double Min_Value, double Max_Value){

        if (name.empty()) {
            throw std::invalid_argument("Parameter Failure, name Empty");
        }
        if (Min_Value == 0.0 && Max_Value == 0.0) {
            throw std::invalid_argument("Parameter Failure, Min Max");
        }

        this->current_value = current_value;
        this->name = name;
        this->Min_Value = Min_Value;
        this->Max_Value = Max_Value;
        
        std::cout << "All Parameters are valid !\n";
    }
    void update_value(double Value){
        if (Value>Max_Value||Value< Min_Value)
        {
            throw std::out_of_range ("Out of Range");
        }
        
        current_value= Value;
    }

    double getValue(){
        return current_value;
    }
    void print_info(){
        std::cout<<"Name: " << name <<std::endl;
        std::cout<<"Value: "<< current_value<<std::endl;
        std::cout<<"Min Value "<< Min_Value<<std::endl;
        std::cout<<"Max Value "<<Max_Value<<std::endl;
        }

    void simulate_failure(){
        throw SensorFailureError("Attention, sensor Failure");
    }

};

int main(){
    Sensor s1;
    Sensor s2;
    try
    {
        s1.add_sensor("Temp",80,0,100);
        s1.update_value(20);
        s1.print_info();
        //s1.simulate_failure();
        s2.add_sensor("Test",90,0,100);
        s2.update_value(60);
        s2.print_info();
    }
    catch(const std::invalid_argument& e){
        std::cerr << e.what() << '\n';
    }
    catch(const std::out_of_range& e){
        std::cerr <<e.what()<<std::endl;
    }
    catch(const SensorFailureError& e){
        std::cerr <<e.what()<<std::endl;
    }
    return 0;
}
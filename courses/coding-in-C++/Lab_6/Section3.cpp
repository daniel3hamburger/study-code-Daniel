#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Device {
private:
    std::string name;
    std::string type;
    bool power;

public:
    Device(std::string name, std::string type, bool power = false) 
        : name(name), type(type), power(power) {}
    
    void turn_on() {
        power = true;
    }
    void turn_off() {
        power = false;
    }
    
    void print_info() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Power: " << power << std::endl; 
    }
    
    std::string getName() {
        return name;
    }

    ~Device() {
        std::cout << "Device '" << name << "' is destroyed\n";
    }
};

class Room {
protected:
    std::string room_name;
    std::vector<std::unique_ptr<Device>> list;
    std::vector<std::shared_ptr<Device>> list_shared;

public:
    Room(const std::string &room) : room_name(room) {}
    
    ~Room() {
        std::cout << "Destructor Room " << room_name << "\n";
    }
    
    void add_device(std::unique_ptr<Device> device) {
        list.push_back(std::move(device));
        std::cout << "Device added to " << room_name << std::endl;
    }

    void add_shared_device(std::shared_ptr<Device> device) {
        list_shared.push_back(std::move(device));
        std::cout << "Device added to " << room_name << std::endl;
    }
    void remove_devices_by_name(std::string name) {
        
    }

    void print_devices() {
        std::cout << "In Room: " << room_name << " there are following devices:\n"; 
        for(const auto& dev : list) {
            dev->print_info();
            std::cout << "-----------------\n";
        }
    }

       void print_shared_devices() {
        std::cout << "In Room: " << room_name << " there are following devices:\n"; 
        for(const auto& dev : list_shared) {
            dev->print_info();
            std::cout << "-----------------\n";
        }
    }
};

class SharedDevice: public Device{
    private:
    const int ip_adress;
    bool network_status;
    public:
    SharedDevice(std::string name, std::string type, int ip, bool power = false) 
    : Device(name, type, power), ip_adress(ip), network_status(false) {}
    void connect_to_network(){
        network_status= true;
        std::cout<<"Connected\n";
    }
   void  disconnect_from_network(){
        network_status= false;
        std::cout<<"Disconnected\n";
    }
   void print_network_info(){

    }
};


int main() {
    Room Room1("Wohnzimmer");
    Room Room2("Zimmer");
    Room1.add_device(std::make_unique<Device>("TV", "Unterhaltung"));
    Room1.add_device(std::make_unique<Device>("Lampe", "Beleuchtung"));

    Room1.print_devices();
    auto p5= std::make_shared<SharedDevice>("music device","music",123);
    Room1.add_shared_device(p5);
    Room2.add_shared_device(p5);
    Room1.print_shared_devices();
    Room2.print_shared_devices();
    return 0;
}
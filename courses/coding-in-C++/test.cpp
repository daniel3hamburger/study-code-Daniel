#include <iostream>

class Location3D{
    private:
    double x;
    double y;
    int z;
    public:
    Location3D(double x, double y, int z): x(x), y(y), z(z){}
    Location3D(double x, double y, int z): x(x),y(y),z(z){}
        Location3D operator+=(const Location3D& v){
            return Location3D(x+v.x, y+v.y, z+v.z);
        }

        bool operator==(const Location3D& v1, const Location3D& v2){
            return true;
        }

        Location3D operator<<(){
            std::cout<<"[X: "<< x <<" Y: "<< y <<" Z: "<< z<<"]\n";
        }
};

class Ireporttable{
    public:
    virtual void sendReport() const =0;
};

class SmartDevice: public Ireporttable{
    protected:
    std::string name;

    public:
    SmartDevice(std::string name): name(name){}
    virtual void triggerAction() const =0;
    virtual ~SmartDevice(){
        std::cout<<"Smartdevice destroyed\n";
    }
};

class Thermostat: public SmartDevice{
    private:
    double currentTemerparture;

    public:
    Thermostat(std::string name, double currenttemp):SmartDevice(name), currentTemerparture(currenttemp){}
    void triggerAction() const override{
        if (currentTemerparture<20){
            std::cout<<"Heizung an\n";
        }
    }

    void sendReport()const override{
        std::cout<< "Name: "<< name<< std::endl;
        std::cout<<"Temp: "<< currentTemerparture<< std::endl;
    }
};

class Motionsensor:public SmartDevice{
    private:
    bool motiondetected;

    public:
    Motionsensor(std::string name, bool motiondetected): SmartDevice(name), motiondetected(motiondetected){}
    void triggerAction()const override{
        if (motiondetected==true){
            std::cout<<"Alarm Bewegeung erkannt\n";
        }
    }

    void sendReport()const override{
        std::cout<< "Name: "<< name<< std::endl;
        std::cout<<"Motion: "<< motiondetected<< std::endl;  
    }
};

int main(){
    const int Size =3;
    SmartDevice* hub[Size];

    hub[0] = new Thermostat("Wohnzimmer_Heizung", 18.5);
    hub[1] = new Motionsensor("Flur_Bewegung", true);
    hub[2] = new Thermostat("Schlafzimmer_Heizung", 22.0);

    for (int i = 0; i < Size; i++) {
    delete hub[i]; 
    }

    return 0;
}
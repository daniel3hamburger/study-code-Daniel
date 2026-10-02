#include <iostream>

class Display
{
public:
    void show_temperature(float value)
    {
        std::cout << "Display: " << value << " C\n";
    }
};

class Logger
{
public:
    void log_temperature(float value)
    {
        std::cout << "Logger: " << value << " C\n";
    }
};
class Alarm{
    public:
    void alarm(float value) {
        if (value>30){
            std::cout<<"Alarm temp over 30\n";
        }
    }
};
class TemperatureSensor
{
private:
    float temperature = 0.0f;

    Display display;
    Logger logger;
    Alarm alarm;

public:
    void set_temperature(float value)
    {
        temperature = value;

        // directly coupled to other classes
        display.show_temperature(temperature);
        logger.log_temperature(temperature);
        alarm.alarm(temperature);
    }
};

int main()
{
    TemperatureSensor sensor;

    sensor.set_temperature(33.5f);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
class IReportable {
public:
    virtual ~IReportable() = default;
    virtual void printReport() const = 0;
};


class Product : public IReportable {
protected:
    int id;
    std::string name;
    double weight;
    double temperature;
    double voltage;
    bool visual_defect;

public:
    Product(int id, std::string name, double weight, double temperature, double voltage, bool visual_defect);

    double getWeight() const;
    double getTemperature() const;
    double getVoltage() const;
    bool hasVisualDefect() const;

    const std::string& getName() const;

    void printReport() const override;
};

class CombustionEngine : public Product {
public:
    CombustionEngine(int id, std::string name, double weight, double temperature, bool visual_defect);
};

class ElectricEngine : public Product {
public:
    ElectricEngine(int id, std::string name,double weight, double temperature, double voltage, bool visual_defect);
};

class Inspection : public IReportable {
protected:
    std::string typeName;
    int total_performed = 0;
    int total_passed = 0;
    bool last_result = false;

public:
    Inspection(std::string type);
    virtual bool perform(const Product& p) = 0;

    void printReport() const override;
    bool lastPassed() const;
    double successRate() const;
};

class WeightInspection : public Inspection {
private:
    double optimal;
    double tolerance;

public:
    WeightInspection(double optimal = 10.0, double tolerance = 0.9);
    bool perform(const Product& p) override;
};

class VisualInspection : public Inspection {
public:
    VisualInspection();
    bool perform(const Product& p) override;
};

class TemperatureInspection : public Inspection {
private:
    double minT;
    double maxT;

public:
    TemperatureInspection(double minT = 20.0, double maxT = 100.0);
    bool perform(const Product& p) override;
};


void runPipeline(Product& p, std::vector<Inspection*>& inspections);

#include "Section4.hpp"


Product::Product(int id_, std::string name_,double weight_, double temperature_, double voltage_, bool visual_defect_)
    : id(id_), name(std::string(name_)), weight(weight_),temperature(temperature_), voltage(voltage_),visual_defect(visual_defect_) {}

double Product::getWeight() const { return weight; }
double Product::getTemperature() const { return temperature; }
double Product::getVoltage() const { return voltage; }
bool Product::hasVisualDefect() const { return visual_defect; }
const std::string& Product::getName() const { return name; }

void Product::printReport() const {
    std::cout << "Product: " << name << "\n";
}

CombustionEngine::CombustionEngine(int id, std::string name,
                                   double weight, double temperature,
                                   bool visual_defect)
    : Product(id, name, weight, temperature, 0.0, visual_defect) {}

ElectricEngine::ElectricEngine(int id, std::string name,
                               double weight, double temperature,
                               double voltage, bool visual_defect)
    : Product(id, name, weight, temperature, voltage, visual_defect) {}


Inspection::Inspection(std::string type)
    : typeName(std::move(type)) {}

void Inspection::printReport() const {
    std::cout << "- " << typeName << ": "
              << (last_result ? "PASS" : "FAIL") << "\n";
}

bool Inspection::lastPassed() const { return last_result; }

double Inspection::successRate() const {
    return total_performed == 0
        ? 0.0
        : (100.0 * total_passed / total_performed);
}

WeightInspection::WeightInspection(double optimal_, double tolerance_)
    : Inspection("Weight Check"), optimal(optimal_), tolerance(tolerance_) {}

bool WeightInspection::perform(const Product& p) {
    double w = p.getWeight();
    last_result = (w >= optimal - tolerance && w <= optimal + tolerance);

    total_performed++;
    if (last_result) total_passed++;

    return last_result;
}

VisualInspection::VisualInspection()
    : Inspection("Visual Inspection") {}

bool VisualInspection::perform(const Product& p) {
    last_result = !p.hasVisualDefect();

    total_performed++;
    if (last_result) total_passed++;

    return last_result;
}


TemperatureInspection::TemperatureInspection(double minT_, double maxT_)
    : Inspection("Temperature Test"), minT(minT_), maxT(maxT_) {}

bool TemperatureInspection::perform(const Product& p) {
    double t = p.getTemperature();
    last_result = (t >= minT && t <= maxT);

    total_performed++;
    if (last_result) total_passed++;

    return last_result;
}


void runPipeline(Product& p, std::vector<Inspection*>& inspections) {
    p.printReport();

    bool allPass = true;

    for (auto* ins : inspections) {
        bool ok = ins->perform(p);
        ins->printReport();
        allPass = allPass && ok;
    }

    std::cout << "Final Result: "
              << (allPass ? "ACCEPTED" : "REJECTED")
              << "\n\n";
}

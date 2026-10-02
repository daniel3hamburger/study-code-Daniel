#include "Section4.hpp"

int main() {
    CombustionEngine combustion(1, "Combustion Motor", 10.0, 25.0, false);
    ElectricEngine electric(2, "Electric Motor", 9.5, 30.0, 48.0, true);

    WeightInspection w1;
    TemperatureInspection t1;
    VisualInspection v1;

    w1.perform(combustion);
    t1.perform(combustion);
    v1.perform(combustion);
    combustion.printReport();
    w1.printReport();
    t1.printReport();
    v1.printReport();
    std::cout << "Final Result: "<< ((w1.lastPassed() && t1.lastPassed() && v1.lastPassed()) ? "ACCEPTED" : "REJECTED")<< "\n";

    WeightInspection w2;
    TemperatureInspection t2;
    VisualInspection v2;

    w2.perform(electric);
    t2.perform(electric);
    v2.perform(electric);
    electric.printReport();
    w2.printReport();
    t2.printReport();
    v2.printReport();
    std::cout << "Final Result: "<< ((w2.lastPassed() && t2.lastPassed() && v2.lastPassed()) ? "ACCEPTED" : "REJECTED")<< "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>

#include "bugHunt_vehicle.hpp"
#include "bugHunt_assistance_system.hpp"

int main()
{
    auto ego_vehicle = std::make_shared<Vehicle>("Vector X1");

    auto front_sensor = std::make_shared<DistanceSensor>("front", 25.0);
    auto rear_sensor  = std::make_shared<DistanceSensor>("rear", 1.2);
    auto left_sensor  = std::make_shared<DistanceSensor>("left", 0.8);
    auto right_sensor = std::make_shared<DistanceSensor>("right", 3.0);

    std::vector<std::unique_ptr<AssistanceFeature>> assistance_container;

    assistance_container.push_back(std::make_unique<EmergencyBrakeSystem>(10.0));
    assistance_container.push_back(std::make_unique<AdaptiveCruiseControl>(80.0, 15.0));
    assistance_container.push_back(std::make_unique<LaneKeepingAssist>(0.4, 5.0));

    ParkingAssistant parking_assistant(1.5);
    parking_assistant.add_sensor(rear_sensor);
    parking_assistant.add_sensor(left_sensor);
    parking_assistant.add_sensor(right_sensor);

    std::cout << "--- Initial vehicle status ---\n";
    ego_vehicle->print_status();

    std::cout << "--- Accelerating vehicle ---\n";
    ego_vehicle->accelerate(50.0);
    ego_vehicle->print_status();


    std::cout << "--- Testing Assistance Systems (Polymorphic Loop) ---\n";
    front_sensor->set_distance(12.0);
    ego_vehicle->update_lane_offset(0.7);

    for (const auto& system : assistance_container)
    {
        system->evaluate(ego_vehicle, front_sensor);
    }
    ego_vehicle->print_status();


    std::cout << "--- Parking assistant test ---\n";
    parking_assistant.print_warnings();


    std::cout << "--- Manual braking test ---\n";
    ego_vehicle->brake(100.0);
    ego_vehicle->print_status();

    return 0;
}
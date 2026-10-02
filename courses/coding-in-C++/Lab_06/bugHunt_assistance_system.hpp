#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "bugHunt_vehicle.hpp"
class AdaptiveCruiseControl;
class DistanceSensor
{
private:
    std::string position;
    bool active;
    double measured_distance_m;
public:
 

    DistanceSensor(const std::string &sensor_position,
                   double initial_distance_m);

    void set_distance(double distance_m);
    void activate();
    void deactivate();

    double get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    bool operator<(const std::shared_ptr<DistanceSensor> other) const;
    bool is_exactly_at_warning_distance(double warning_distance) const;

    void print_info() const;
};

class AssistanceFeature{
    protected:
    std::vector<std::unique_ptr<AssistanceFeature>> container;
    public:
    virtual void evaluate(std::shared_ptr<Vehicle> vehicle, const std::shared_ptr<DistanceSensor> front_sensor)=0;
    void print_name();
    virtual ~AssistanceFeature();
    void addcontainer();
};

class EmergencyBrakeSystem: public AssistanceFeature
{
private:
    double critical_distance_m;

public:
    EmergencyBrakeSystem(double critical_distance);

    void evaluate(std::shared_ptr<Vehicle> vehicle, const std::shared_ptr<DistanceSensor> front_sensor) override;
};

class LaneKeepingAssist: public AssistanceFeature
{
private:
    double max_allowed_offset_m;
    double correction_angle;

public:
    LaneKeepingAssist(double max_offset, double correction);

    void evaluate(std::shared_ptr<Vehicle> vehicle, const std::shared_ptr<DistanceSensor> front_sensor) override;
};

class AdaptiveCruiseControl : public AssistanceFeature
{
protected:
    double target_speed_kmh;
    double minimum_distance_m;
    friend class EmergencyBrakeSystem;

public:
    AdaptiveCruiseControl(double target_speed,
                          double minimum_distance);

    void evaluate(std::shared_ptr<Vehicle> vehicle, const std::shared_ptr<DistanceSensor> front_sensor)override;
};

class ParkingAssistant
{
private:
    std::vector<std::shared_ptr<DistanceSensor>> sensors;
    double warning_distance_m;

public:
    ParkingAssistant(double warning_distance);

    void add_sensor(std::shared_ptr<DistanceSensor> sensor);
    void print_warnings() const;
};


#endif
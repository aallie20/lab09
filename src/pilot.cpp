#include "pilot.h"

#include <iostream>

Pilot::Pilot(std::string name, int skill)
  : name_(name),
    skill_(skill),
    fatigue_(0),
    missions_(0) {
    

    if (name_.empty()) {
        name_ = "Unamed";
        }

    if (skill_ < 1) {
        skill_ = 1;
        }
        else if (skill_ > 100) {
            skill_ = 100;
            }
}

bool Pilot::set_name(const std::string& name){
    if(name.empty()) {
        return false;
        }

        name_ = name;
        return true;
        }

const std::string& Pilot::name() const {
    return name_;
    }

int Pilot::skill() const {
    return skill_;
    }

int Pilot::fatigue() const {
    return fatigue_;
    }

int Pilot::missions() const {
    return missions_;
    }

void Pilot::change_skill(int amount) {
    skill_ += amount;
    
    if(skill_ < 1) {
        skill_ = 1;
        } else if (skill_ > 100) {
            skill_ = 100;
            }
}

void Pilot::rest() {
    fatigue_ -= 30;
    if (fatigue_ < 0) {
        fatigue_ = 0;
    }
}

bool Pilot::fly_mission() {
    if (fatigue_ > 80) {
        return false;
    }
    fatigue_ += 20;
    missions_ += 1;
    return true;
}

void Pilot::print() const {
    std::cout << name_ << " | skill " << skill_ << " | fatigue "
              << fatigue_ << " | missions " << missions_ << '\n';
}

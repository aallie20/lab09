#ifndef HANGAR_PILOT_H
#define HANGAR_PILOT_H

#include <string>

/// A mech pilot. This is the STARTER version: every field is public, so any code
/// anywhere can set a pilot's skill to -40 or give them an empty name.
/// Your job is to fix that. See README.md for the checkpoints.
class Pilot {
public:
    Pilot(std::string name, int skill);
       
    const std::string& name() const;
    int skill() const;                    ///< 1 (rookie) to 100 (ace)
    int fatigue() const;    ///< 0 (rested) to 100 (exhausted)
    int missions() const;   ///< missions flown, 0 or more
    
    void rest();
    bool fly_mission();
    void print() const;
    
    void change_skill(int amount);

private:
    std::string name_;
    int skill_;
    int fatigue_;
    int missions_;
};

/// Lowers fatigue by 30. Fatigue never drops below 0.

/// A pilot with fatigue above 80 is too tired to fly: return false and change nothing.
/// Otherwise add 20 fatigue, add 1 mission, and return true.

/// Prints one line:  name | skill N | fatigue N | missions N

#endif

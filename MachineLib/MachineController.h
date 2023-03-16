/**
 * @file MachineController.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINECONTROLLER_H
#define CANADIANEXPERIENCE_MACHINECONTROLLER_H

//#include "MachineBase.h"
class Component;
class MachineBase;
class Motor;

/**
 * Class for the controller of the machine
 *
 * This class takes in the machine base class
 * and controller the components to move
 */
class MachineController{
private:
    ///Time the machine starts to move
    double mStartTime;

    /// Vector of all components in this machine
    std::vector<std::shared_ptr<Component>> mComponents;

    /// The base of this machine
    MachineBase *mMachineBase = nullptr;

    /// Vector of all motors in this machine
    std::vector<std::shared_ptr<Motor>> mMotors;

public:
    /**
    * Default Constructor
    * @param id id of the machine
    */
    MachineController(int id);

    /**
    * Set the start time of the machine
    * @param time start time of the machine
    */
    void SetCurrentTime(double time) {mStartTime = time;}

    /** Gets the machines current time
    * @return The current time of this machine
    */
    double GetCurrentTime() {return mStartTime;}

    /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    void SetLocation(wxPoint location);

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    * @param x passed in x position to draw at
    * @param y passed in y position to draw at
    */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
    * Adds a new component to the machine
    * @param component component to add
    */
    void AddComponent(std::shared_ptr<Component> component);

    /**
    * Adds a new motor to the machine
    * @param motor motor to add
    */
    void AddMotor(std::shared_ptr<Motor> motor);

};

#endif //CANADIANEXPERIENCE_MACHINECONTROLLER_H

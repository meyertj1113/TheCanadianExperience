/**
 * @file Motor.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "RotationSource.h"

/**
 * Class for motors in our machine
 *
 * Aa motor is a machine part that interacts with rotation
 * sinks to move other components, as well as being the only
 * origin source for movement
 */
class Motor : public Component{
private:
    /// Polygon object to include the second piece of motor
    Polygon mPolygon;

    /// Machine controller for the motor to source its time
    MachineController *mMachineController = nullptr;

    /// Current time of the machine
    double mTime;

    /// Rotation source for this component
    RotationSource mSource;

    /// Current rotation of the motor
    double mRotation;

public:
    ///Constructor disabled
    Motor() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    */
    Motor(const std::wstring& name, const std::wstring& ImagesDirectory);

    /// Destructor
    ~Motor() override = default;

    /** Copy constructor disabled */
    Motor(const Motor &) = delete;

    /** Assignment operator disabled */
    void operator=(const Motor &) = delete;

    /**
    * Draw the component at the currently specified location
    * @param graphics Graphics object to render to
    * @param x passed in x position to draw at
    * @param y passed in y position to draw at
    */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /** Sets the current time
    * @param time current time
    */
    void SetTime(double time);

    /** Sets the machine controller
    * @param controller the machine controller moving this motor
    */
    void SetMotorController(MachineController *controller);

    /** Sets the current rotation
    * @param rotation current rotation
    */
    void SetCurrentRotation(double rotation) {mRotation = rotation;}

    /** Gets the current rotation
    * @return current rotation
    */
    double GetCurrentRotation() {return mRotation;}

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }
};

#endif //CANADIANEXPERIENCE_MOTOR_H

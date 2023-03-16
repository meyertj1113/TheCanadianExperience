/**
 * @file RotationSink.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

#include "RotationSource.h"
#include "Component.h"

/**
 * Class for rotation sinks in our machine
 *
 * A rotation sink is a sink component that rotates with
 * its given rotation source
 */
class RotationSink {
private:
    /// Current rotation of this sink
    double mRotation;

    /// Current speed of the sink
    double mSpeed = 1;

    /// Current phase of the sink
    double mPhase = 0;

    /// Source of this sink
    RotationSource *mSource = nullptr;

    /// The type of component that this source is
    Component *mComponent = nullptr;

public:
    /// Default Constructor
    RotationSink();

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSink &) = delete;

    /** Update the rotation of the sink
    * @param rotation Position to set the sinks to
    */
    void Update(double rotation);

    /** Sets the source of this sink
    * @param source Source of this sink
    */
    void SetSource(RotationSource *source) {mSource = source;}

    /** Sets the component of this sink
    * @param component component of this sink
    */
    void SetComponent(Component* component) {mComponent = component;}

    /** Gets the component of this sink
    * @return component of this sink
    */
    Component* GetComponent() {return mComponent;}

    /** Sets the speed of this sink
    * @param speed speed of this sink
    */
    void SetSpeed(double speed) {mSpeed = speed;}

    /** Sets the phase of this sink
    * @param phase phase of this sink
    */
    void SetPhase(double phase) {mPhase = phase;}
};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H

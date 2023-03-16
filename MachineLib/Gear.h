/**
 * @file Gear.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

/**
 * Class for gears in our machine
 *
 * A gear is a machine part that interacts with rotation sinks
 * as well as drives other gears
 */
class Gear : public Component{
private:
    /// Rotation sink for this component
    RotationSink mSink;

    /// Rotation source for this component
    RotationSource mSource;

    /// Current length of this component
    double mRotation;

    /// Amount of teeth this gear has
    int mNumTeeth;

public:
    ///Constructor disabled
    Gear() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    * @param radius radius of the gear
    * @param numTeeth number of teeth this gear has
    */
    Gear(const std::wstring& name, const std::wstring& ImagesDirectory, double radius, int numTeeth);

    /// Destructor
    ~Gear() override = default;

    /** Copy constructor disabled */
    Gear(const Gear &) = delete;

    /** Assignment operator disabled */
    void operator=(const Gear &) = delete;

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSink *GetSink() { return &mSink; }

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }

    /** Sets the rotation of this rod
    * @param rotation rotation of this rod
    */
    void SetRotation(double rotation) override;

    /** Drives another gear using data from this gear
    * @param gear gear to be driven
    * @param phase phase of the gear
    */
    void Drive(std::shared_ptr<Gear> gear, double phase);
};


#endif //CANADIANEXPERIENCE_GEAR_H

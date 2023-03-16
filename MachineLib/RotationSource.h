/**
 * @file RotationSource.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

class RotationSink;

/**
 * Class for rotation sources in our machine
 *
 * A rotation source is a source component that makes
 * a rotation sink rotate along with it
 */
class RotationSource {
private:
    /// Current speed of the rotation source
    double mSpeed;

    /// Current rotation of the rotation source;
    double mRotation;

    /// Vector of all sinks this source has
    std::vector<RotationSink*> mSinks;

public:
    /// Default Constructor
    RotationSource();

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource &) = delete;

    /** Update all sinks this source has
    * @param rotation Position to set the sinks to
    */
    void UpdateSinks(double rotation);

    /** Add a sink to this source
    * @param sink Sink being added
    */
    void AddSink(RotationSink* sink);

    /** Update the rotation of the sink
    * @param rotation rotation to set the sinks to
    */
    void SetRotation(double rotation);
};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H

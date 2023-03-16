/**
 * @file Arm.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "RotationSink.h"
#include "TranslationSource.h"

/**
 * Class for arms in our machine
 *
 * Aa arm is a machine part that interacts with rotation and
 * transition sinks to move other components
 */
class Arm : public Component{
private:
    /// Rotation sink for this component
    RotationSink mSink;

    /// Rotation source for this object
    TranslationSource mSource;

    /// Length of this arm
    int mLength;

public:
    ///Constructor disabled
    Arm() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    * @param length Length of rod
    */
    Arm(const std::wstring& name, const std::wstring& ImagesDirectory, int length);

    /// Destructor
    ~Arm() override = default;

    /** Copy constructor disabled */
    Arm(const Arm &) = delete;

    /** Assignment operator disabled */
    void operator=(const Arm &) = delete;

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSink *GetSink() { return &mSink; }

    /// Get a pointer to the source object
    /// \return Pointer to TranslationSource object
    TranslationSource *GetSource() { return &mSource; }

    /**
    * Draw the component at the currently specified location
    * @param graphics Graphics object to render to
    * @param x passed in x position to draw at
    * @param y passed in y position to draw at
    */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
};

#endif //CANADIANEXPERIENCE_ARM_H

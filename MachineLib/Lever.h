/**
 * @file Lever.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RodSink.h"
#include "TranslationSource.h"
#include "RotationSource.h"

/**
 * Class for levers in our machine
 *
 * A lever is a machine part that is moved by a translation sink
 * and is able to both move objet and rotate objects
 */
class Lever : public Component, Translator{
private:
    /// Rotation sink for this component
    RodSink mRodSink;

    /// Translation source for this component
    TranslationSource mTranslationSource;

    /// Rotation source for this component
    RotationSource mRotationSource;

    /// Current origin of this component
    wxPoint mOrigin;

    /// Current length of this component
    int mLength;

    /// Current length of this component
    double mRotation;

public:
    ///Constructor disabled
    Lever() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    * @param length Length of rod
    * @param origin origin of rod
    */
    Lever(const std::wstring& name, const std::wstring& ImagesDirectory, int length, wxPoint origin);

    /// Destructor
    ~Lever() override = default;

    /** Copy constructor disabled */
    Lever(const Lever &) = delete;

    /** Assignment operator disabled */
    void operator=(const Lever &) = delete;

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RodSink *GetSink() { return &mRodSink; }

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    TranslationSource *GetTranslationSource() { return &mTranslationSource; }

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSource *GetRotationSource() { return &mRotationSource; }

    /**
    * Negotiate with a rod to come up with a mutual rotation solution
    * @param rod
    */
    void Negotiate(Rod *rod) override;

    /**
    * Draw the component at the currently specified location
    * @param graphics Graphics object to render to
    * @param x passed in x position to draw at
    * @param y passed in y position to draw at
    */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /** Sets the rotation of this rod
    * @param rotation rotation of this rod
    */
    void SetRotation(double rotation) override;
};

#endif //CANADIANEXPERIENCE_LEVER_H

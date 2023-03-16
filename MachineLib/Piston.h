/**
 * @file Piston.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"
#include "RodSink.h"

/**
 * Class for pistons in our machine
 *
 * Aa piston is a machine part that has no sinks but can
 * be negotiated with by a lever
 */
class Piston : public Component, Translator{
private:
    /// Rotation sink for this component
    RodSink mRodSink;

    /// Origin point of the position
    wxPoint mOrigin;

public:
    ///Constructor disabled
    Piston() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    * @param origin origin of rod
    */
    Piston(const std::wstring& name, const std::wstring& ImagesDirectory, wxPoint origin);

    /// Destructor
    ~Piston() override = default;

    /** Copy constructor disabled */
    Piston(const Piston &) = delete;

    /** Assignment operator disabled */
    void operator=(const Piston &) = delete;

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RodSink *GetSink() { return &mRodSink; }

    /**
    * Negotiate with a rod to come up with a mutual rotation solution
    * @param rod
    */
    void Negotiate(Rod *rod) override;
};

#endif //CANADIANEXPERIENCE_PISTON_H

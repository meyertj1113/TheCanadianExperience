/**
 * @file RodSink.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H

#include "Translator.h"
#include "Component.h"
#include "Rod.h"

/**
 * Class for rod sinks in our machine
 *
 * A rod sink is a sink component that passed a rod
 * into another object to be able to negotiate with it
 */
class RodSink : public Translator {
private:
    /// Pointer to the translator
    Translator *mNegotiator = nullptr;

    /// The type of component that this source is
    Component *mComponent = nullptr;

    /// Source of this sink
    Rod *mRodSource = nullptr;

public:
    ///Default contructor
    RodSink();

    /// Copy constructor (disabled)
    RodSink(const RodSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RodSink &) = delete;

    /** Sets the component of this sink
    * @param component component of this sink
    */
    void SetComponent(Component* component) {mComponent = component;}

    /** Sets the negotiator of this sink
    * @param negotiator negotiator of this sink
    */
    void SetNegotiator(Translator* negotiator) {mNegotiator = negotiator;}

    /**
    * Negotiate with a rod to come up with a mutual rotation solution
    * @param rod
    */
    void Negotiate(Rod *rod) override;
};

#endif //CANADIANEXPERIENCE_RODSINK_H

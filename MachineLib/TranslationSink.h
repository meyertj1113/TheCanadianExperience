/**
 * @file TranslationSink.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_TRANSLATIONSINK_H
#define CANADIANEXPERIENCE_TRANSLATIONSINK_H

#include "TranslationSource.h"
#include "Component.h"

/**
 * Class for translation sinks in our machine
 *
 * A translation sink is a sink component that translates with
 * its given translation source
 */
class TranslationSink {
private:
    /// Current position of this sink
    wxPoint mPosition;

    /// Source of this sink
    TranslationSource *mSource = nullptr;

    /// The type of component that this source is
    Component *mComponent = nullptr;

public:
    /// Default Constructor
    TranslationSink();

    /// Copy constructor (disabled)
    TranslationSink(const TranslationSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const TranslationSink &) = delete;

    /** Update the position of the sink
    * @param position Position to set the sinks to
    */
    void Update(wxPoint position);

    /** Sets the source of this sink
    * @param source Source of this sink
    */
    void SetSource(TranslationSource *source) {mSource = source;}

    /** Sets the component of this sink
    * @param component component of this sink
    */
    void SetComponent(Component* component) {mComponent = component;}

    /** Gets the component of this sink
    * @return component of this sink
    */
    Component* GetComponent() {return mComponent;}
};

#endif //CANADIANEXPERIENCE_TRANSLATIONSINK_H

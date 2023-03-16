/**
 * @file TranslationSource.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_TRANSLATIONSOURCE_H
#define CANADIANEXPERIENCE_TRANSLATIONSOURCE_H

class TranslationSink;

/**
 * Class for translation sources in our machine
 *
 * A translation source is a source component that makes
 * a translation sink translate along with it
 */
class TranslationSource {
private:
    /// Current position of this source
    wxPoint mPosition;

    /// Vector of all sinks this source has
    std::vector<TranslationSink*> mSinks;

public:
    /// Default Constructor
    TranslationSource();

    /// Copy constructor (disabled)
    TranslationSource(const TranslationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const TranslationSource &) = delete;

    /** Update all sinks this source has
    * @param position Position to set the sinks to
    */
    void UpdateSinks(wxPoint position);

    /** Add a sink to this source
    * @param sink Sink being added
    */
    void AddSink(TranslationSink* sink);

    /** Update the position of the sink
    * @param position Position to set the sinks to
    */
    void SetTranslation(wxPoint position);
};

#endif //CANADIANEXPERIENCE_TRANSLATIONSOURCE_H

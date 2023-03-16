/**
 * @file Rod.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "TranslationSink.h"
class TranslationSource;
class RodSink;

/**
 * Class for rods in our machine
 *
 * A rod is a machine part that is a translation sink,
 * as well as the source for piston and lever movement
 */
class Rod : public Component{
private:
    /// Rotation sink for this component
    TranslationSink mSink;

    /// Rotation sink for this component
    RodSink *mRodSink = nullptr;

    /// Length of rod
    int mLength;

    /// Current rotation of rod
    double mRotation;

    /// Current origin of rod
    wxPoint mOrigin;

public:
    ///Constructor disabled
    Rod() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    * @param length Length of rod
    * @param origin origin of rod
    */
    Rod(const std::wstring& name, const std::wstring& ImagesDirectory, int length, wxPoint origin);

    /// Destructor
    ~Rod() override = default;

    /** Copy constructor disabled */
    Rod(const Rod &) = delete;

    /** Assignment operator disabled */
    void operator=(const Rod &) = delete;

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    TranslationSink *GetSink() { return &mSink; }

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RodSink *GetRodSink() { return mRodSink; }

    /** Sets this rods ability to be a RodSink and negotiate
    * @param rod sink of this rod
    */
    void SetRodSink(RodSink *rod) {mRodSink = rod;}

    /** Sets the position of this rod
     * @param position position of this rod
     */
    void SetLocation(wxPoint position);

    /** Gets the length of this rod
    * @return length of this rod
    */
    int GetLength() {return mLength;}

    /** Gets the origin of this rod
    * @return origin of this rod
    */
    wxPoint GetOrigin() {return mOrigin;}

    /** Sets the rotation of this rod
     * @param rotation rotation of this rod
     */
    void SetRotation(double rotation) override;
};

#endif //CANADIANEXPERIENCE_ROD_H

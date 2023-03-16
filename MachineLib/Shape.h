/**
 * @file Shape.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "RotationSink.h"

/**
 * Class for shapes in our machine
 *
 * A shape is a machine part is able to be rotated by
 * rotation sources
 */
class Shape : public Component{
private:
    /// Rotation sink for this component
    RotationSink mSink;

public:
    ///Constructor disabled
    Shape() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    */
    Shape(const std::wstring& name, const std::wstring& ImagesDirectory);

    /// Destructor
    ~Shape() override = default;

    /** Copy constructor disabled */
    Shape(const Shape &) = delete;

    /** Assignment operator disabled */
    void operator=(const Shape &) = delete;

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSink *GetSink() { return &mSink; }
};

#endif //CANADIANEXPERIENCE_SHAPE_H

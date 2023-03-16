/**
 * @file Component.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"
class MachineController;

/**
 * Class for components in our machine
 *
 * A component is a machine part that interacts in some
 * way with another component
 */
class Component : public Polygon {
private:
    /// Current position of this component
    wxPoint mPosition = wxPoint(0,0);

    /// Origin point of this component
    wxPoint mOrigin;

    /// Controller of this component
    MachineController *mMachineController = nullptr;

public:
    ///Constructor disabled
    Component() = delete;

    /**
    * Default Constructor
    * @param name name of component
    * @param ImagesDirectory Image directory of component
    */
    Component(const std::wstring& name, const std::wstring &ImagesDirectory);

    /// Destructor
    ~Component() override = default;

    /** Copy constructor disabled */
    Component(const Component &) = delete;

    /** Assignment operator disabled */
    void operator=(const Component &) = delete;

    /**
    * Draw the component at the currently specified location
    * @param graphics Graphics object to render to
    * @param x passed in x position to draw at
    * @param y passed in y position to draw at
    */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    virtual /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    void SetLocation(wxPoint location) {mPosition = location;}

    virtual /**
    * Set the position for the root of the machine
    * @return The x,y location to place the machine
    */
    wxPoint GetLocation() {return mPosition;}

    /**
    * Set the origin for the root of the machine
    * @param origin The x,y location to place the machine
    */
    void SetOrigin(wxPoint origin) {mOrigin = origin;}

    /**
    * Set the controller of the component
    * @param controller The controller of this component
    */
    void SetController(MachineController *controller);
    };

#endif //CANADIANEXPERIENCE_COMPONENT_H

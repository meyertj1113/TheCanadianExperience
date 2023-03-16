/**
 * @file MachineBase.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEBASE_H
#define CANADIANEXPERIENCE_MACHINEBASE_H

#include "Machine.h"
class MachineController;

/**
 * Class for the base of the machine
 *
 * This class takes in the base machine class
 * and add in member functions and variables
 */
class MachineBase : public Machine {
private:
    ///Current location of the machine
    wxPoint mLocation = wxPoint(0,0);

    ///Current frame the machine is on
    int mFrame;

    ///Current speed of the machine
    double mSpeed = 1;

    ///Current framerate of the machine
    double mFrameRate = 30;

    ///The unique ID to the current machine
    int mMachineID = 1;

    ///The time that the current machine is at
    double mTime = 0;

    /// This machine base's controller
    std::shared_ptr<MachineController> mMachineController = nullptr;

    /// Image directory to get machine images from
    std::wstring mImagesDirectory;

public:
    /** Constructor
    * @param name The machines name
    * @param ImagesDirectory The image directory for this machine
    */
    MachineBase(std::wstring& name, std::wstring &ImagesDirectory);

    /// Destructor
    ~MachineBase() override = default;

    /** Copy constructor disabled */
    MachineBase(const MachineBase &) = delete;

    /** Assignment operator disabled */
    void operator=(const MachineBase &) = delete;

    /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    void SetLocation(wxPoint location) override;

    /**
     * Get the location of hte machine
     * @return Location x,y in pixels as a point
     */
    wxPoint GetLocation() override;

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    void SetMachineFrame(int frame) override;

    /**
     * Set the expected frame rate in frames per second
     * @param rate Frame rate in frames per second
     */
    void SetFrameRate(double rate) override;

    /**
    * Set  the bend angleGetM
    * @param speed Speed from 0 to 1, where 1 is full speed
    */
    void SetSpeed(double speed) override;

    /**
    * Set the machine number
    * @param machine An integer number. Each number makes a different machine
    */
    void SetMachineNumber(int machine) final;

    /**
     * Get the current machine number
     * @return Machine number integer
     */
    int GetMachineNumber() override;

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    double GetMachineTime() override;

};

#endif //CANADIANEXPERIENCE_MACHINEBASE_H

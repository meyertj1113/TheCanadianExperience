/**
 * @file MachineDrawable.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include "Drawable.h"
#include "Picture.h"
#include <machine-api.h>

/**
 * A drawable that displays a machine
 */
class MachineDrawable : public Drawable{
private:
    /// Pointer to the picture being used
    std::shared_ptr<Picture> mPicture = nullptr;

    /// Pointer a machine object initialized as machine 1
    std::shared_ptr<Machine> mMachine1 = nullptr;

    /// Pointer a machine object initialized as machine 2
    std::shared_ptr<Machine> mMachine2 = nullptr;

    /// The center of the image
    wxPoint mCenter = wxPoint(0, 0);

    /// The start frame for machine 1
    int mMachine1StartFrame = 0;

    /// The start frame for machine 2
    int mMachine2StartFrame = 0;

    /// The ID for machine 1
    int mMachine1ID = 1;

    /// The ID for machine 2
    int mMachine2ID = 2;

public:
    MachineDrawable(const std::wstring& name, const std::wstring& filename, std::shared_ptr<Picture> mPicture);

    /**
     * Set the center to rotate around
     * @param center New center
     */
    void SetCenter(wxPoint center) { mCenter = center; }

    /**
     * Get the center to rotate around
     * @return Center
     */
    wxPoint GetCenter() const { return mCenter; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(wxPoint pos) override;

    void ShowDialogBox(wxWindow *parent, int machineNum);

    /**
    * Set the start frame value
    * @param frame frame to start on
    */
    void SetMachine1StartFrame(int frame) {mMachine1StartFrame = frame;}

    /**
    * Set the start frame value
    * @param frame frame to start on
    */
    void SetMachine2StartFrame(int frame) {mMachine2StartFrame = frame;}

    void Save(wxXmlNode* root);

    void Load(wxXmlNode* root);

    void Clear();
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H

/**
 * @file MachineDrawable.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "MachineDrawable.h"

/** Constructor
 * @param name The drawable name
 * @param filename The filename for the image
 * @param picture The picture object that this machine is on */
MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring &filename, std::shared_ptr<Picture> picture) :
        Drawable(name), mPicture(picture)
{
    MachineFactory factory(filename);
    std::shared_ptr<Machine> machine1 = factory.CreateMachine();
    mMachine1 = machine1;
    mMachine1->SetMachineNumber(1);

    std::shared_ptr<Machine> machine2 = factory.CreateMachine();
    mMachine2 = machine2;
    mMachine2->SetMachineNumber(2);

}

/**
 * Draw the image drawable
 * @param graphics Graphics context to draw on
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int curFrame; // current frame variable for math
    // machine 1
    mMachine1->SetMachineNumber(mMachine1ID);
    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(.5, .5);
    mMachine1->SetLocation(wxPoint(300,1100));
    curFrame = mPicture->GetTimeline()->GetCurrentFrame() - mMachine1StartFrame;
    if (curFrame < 0) {curFrame = 0;}
    mMachine1->SetMachineFrame(curFrame);
    mMachine1->DrawMachine(graphics);
    graphics->PopState();

    // machine 2
    mMachine2->SetMachineNumber(mMachine2ID);
    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(.5, .5);
    mMachine2->SetLocation(wxPoint(1600,1100));
    curFrame = mPicture->GetTimeline()->GetCurrentFrame() - mMachine2StartFrame;
    if (curFrame < 0) {curFrame = 0;}
    mMachine2->SetMachineFrame(curFrame);
    mMachine2->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Test to see if we clicked on the image.
 * @param pos Position to test
 * @return True if clicked on
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}

/**
 * Handle an Machine>Properties... menu option
 * @param window The window to display in
 * @param machineNum The machine number to display
 */
void MachineDrawable::ShowDialogBox(wxWindow *window, int machineNum)
{
    if(machineNum == 1)
    {
        MachineDialog dlg(window, mMachine1);
        if (dlg.ShowModal() == wxID_OK)
        {
            mMachine1ID = mMachine1->GetMachineNumber();
            mPicture->UpdateObservers();
        }
    }
    else if (machineNum == 2)
    {
        MachineDialog dlg(window, mMachine2);
        if (dlg.ShowModal() == wxID_OK)
        {
            mMachine2ID = mMachine2->GetMachineNumber();
            mPicture->UpdateObservers();
        }
    }
}

/**
 * Save the timeline animation to XML
 * @param root Xml node to save to
 */
void MachineDrawable::Save(wxXmlNode* root)
{
    root->AddAttribute(L"machine1startframe", wxString::Format(wxT("%i"), mMachine1StartFrame));
    root->AddAttribute(L"machine2startframe", wxString::Format(wxT("%i"), mMachine2StartFrame));
    root->AddAttribute(L"machine1id", wxString::Format(wxT("%i"), mMachine1ID));
    root->AddAttribute(L"machine2id", wxString::Format(wxT("%i"), mMachine2ID));
}

/**
* Load a timeline animation from XML
* @param root XML node to load from
*/
void MachineDrawable::Load(wxXmlNode* root)
{
    // Once we know it is open, clear the existing data
    Clear();

    // Get the attributes
    mMachine1StartFrame = wxAtoi(root->GetAttribute(L"machine1startframe", L"0"));
    mMachine2StartFrame = wxAtoi(root->GetAttribute(L"machine2startframe", L"0"));
    mMachine1ID = wxAtoi(root->GetAttribute(L"machine1id", L"1"));
    mMachine2ID = wxAtoi(root->GetAttribute(L"machine2id", L"2"));
}

/**
 * Clear all keyframes
 */
void MachineDrawable::Clear()
{
    // Reset the current time and restore to defaults.
    mMachine1StartFrame = 0;
    mMachine2StartFrame = 0;
    mMachine1ID = 1;
    mMachine2ID = 2;
}
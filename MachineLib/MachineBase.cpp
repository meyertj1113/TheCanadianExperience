/**
 * @file MachineBase.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "MachineBase.h"
#include "MachineStandin.h"
#include "OwensMachineFactory.h"
#include "CustomMachineFactory.h"

using namespace std;

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";

MachineBase::MachineBase(std::wstring &name, std::wstring &ImagesDirectory) : Machine()
{
    mImagesDirectory = ImagesDirectory;
    SetMachineNumber(1);
}

void MachineBase::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachineController->Draw(graphics, mLocation.x, mLocation.y);
}

void MachineBase::SetLocation(wxPoint location)
{
    mLocation = location;
}

wxPoint MachineBase::GetLocation()
{
    return mLocation;
}

void MachineBase::SetMachineFrame(int frame)
{
    mTime = frame / mFrameRate * mSpeed;
    mMachineController->SetCurrentTime(mTime);
}

void MachineBase::SetFrameRate(double rate)
{
    mFrameRate = rate;
}

void MachineBase::SetSpeed(double speed)
{
    mSpeed = speed;
}

void MachineBase::SetMachineNumber(int machine)
{
    if(machine == 1)
    {
        OwensMachineFactory factory(mImagesDirectory);
        mMachineController = factory.CreateMachine();
    }
    else if (machine == 2)
    {
        CustomMachineFactory factory(mImagesDirectory);
        mMachineController = factory.CreateMachine();
    }
    mMachineID = machine;
}

int MachineBase::GetMachineNumber()
{
    return mMachineID;
}

double MachineBase::GetMachineTime()
{
    return mTime;
}

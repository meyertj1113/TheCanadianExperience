/**
 * @file Motor.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Motor.h"
#include "MachineController.h"

Motor::Motor(const std::wstring& name, const std::wstring& ImagesDirectory)
        :Component(name, ImagesDirectory)
{
    Polygon::SetImage(ImagesDirectory + L"/motor2.png");
    mPolygon.SetImage(ImagesDirectory + L"/shaft.png");

    double angle;
    int wid = 30;
    int rad = wid/2;

    for (int i = 1; i < 30; i++)
    {
        angle = double(i) / 30 * M_PI * 2;
        mPolygon.AddPoint(rad * cos(angle),
                rad * sin(angle));
    }

    mPolygon.AddPoint(0.0, rad * sin(angle));
    mPolygon.AddPoint(0.0, -rad * sin(angle));

}

void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    mSource.SetRotation(mMachineController->GetCurrentTime());
    SetCurrentRotation(mMachineController->GetCurrentTime());
    mPolygon.SetRotation(mMachineController->GetCurrentTime());
    DrawPolygon(graphics, x, y);
    mPolygon.DrawPolygon(graphics, x, y-90);
}

void Motor::SetMotorController(MachineController *controller)
{
    mMachineController = controller;
}

void Motor::SetTime(double time)
{
    mTime = time;
}


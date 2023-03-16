/**
 * @file MachineController.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "MachineController.h"
#include "Component.h"
#include "Motor.h"

MachineController::MachineController(int id)
{

}

void MachineController::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics, x, y);
    }
}

void MachineController::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetController(this);
}

void MachineController::AddMotor(std::shared_ptr<Motor> motor)
{
    mMotors.push_back(motor);
    motor->SetMotorController(this);
    motor->SetTime(mStartTime);
}

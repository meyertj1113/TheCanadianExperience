/**
 * @file Component.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Component.h"

Component::Component(const std::wstring& name, const std::wstring& ImagesDirectory)
{

}

void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, x+mPosition.x, y+mPosition.y);
}

void Component::SetController(MachineController *controller)
{
    mMachineController = controller;
}

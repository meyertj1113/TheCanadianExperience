/**
 * @file Arm.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Arm.h"

Arm::Arm(const std::wstring& name, const std::wstring& ImagesDirectory, int length)
        :Component(name, ImagesDirectory)
{
    Polygon::SetImage(ImagesDirectory);
    mSink.SetComponent(this);
    mLength = length;

    Polygon::Rectangle(-10, 10, mLength+20, 20);
}

void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    double X = GetLocation().x + mLength * cos(GetRotation() * M_PI * 2);
    double Y = GetLocation().y + mLength * sin(GetRotation() * M_PI * 2);
    mSource.SetTranslation(wxPoint(X,Y));
    Component::Draw(graphics, x, y);
}


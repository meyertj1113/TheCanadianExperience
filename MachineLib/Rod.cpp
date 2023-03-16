/**
 * @file Rod.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Rod.h"
#include "RodSink.h"

Rod::Rod(const std::wstring& name, const std::wstring& ImagesDirectory, int length, wxPoint origin)
        :Component(name, ImagesDirectory)
{
    Polygon::SetColor(wxColour(52,52,53));
    mSink.SetComponent(this);

    mLength = length;
    Polygon::Rectangle(0,2 ,mLength, 4);
    Component::SetLocation(origin);

}

void Rod::SetLocation(wxPoint position)
{
    Component::SetLocation(position);
    mOrigin = position;
    if (mRodSink != nullptr)
    {
        mRodSink->Negotiate(this);
    }
}

void Rod::SetRotation(double rotation)
{
    mRotation = rotation;
    Polygon::SetRotation(rotation);
}

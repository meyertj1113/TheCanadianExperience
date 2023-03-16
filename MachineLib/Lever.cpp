/**
 * @file Lever.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Lever.h"
#include <math.h>

Lever::Lever(const std::wstring& name, const std::wstring& ImagesDirectory, int length, wxPoint origin)
        :Component(name, ImagesDirectory)
{
    Polygon::SetImage(ImagesDirectory);
    mOrigin = origin;
    mLength = length;

    Component::SetLocation(mOrigin);
    Polygon::AddPoint(-mLength/2 - 10, 20);
    Polygon::AddPoint(-mLength/2 - 10, -20);
    Polygon::AddPoint(mLength/2 + 10, -20);
    Polygon::AddPoint(mLength/2 + 10, 20);

    mRodSink.SetComponent(this);
    mRodSink.SetNegotiator(this);
}

void Lever::Negotiate(Rod* rod)
{
    int a = mLength / 2;
    int b = rod->GetLength();
    double c = sqrt(pow((mOrigin.y-rod->GetOrigin().y),2) +
            pow((mOrigin.x-rod->GetOrigin().x),2));
    double delta = atan2(-(mOrigin.y-rod->GetOrigin().y),(mOrigin.x-rod->GetOrigin().x));
    double alpha = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2*b*c));
    double theta = delta - alpha; /// Rod Rotation Rad
    wxPoint leverEnd = wxPoint(rod->GetOrigin().x+b*
            cos(-theta), rod->GetOrigin().y+b*sin(-theta));
    double phi = atan2(leverEnd.y - mOrigin.y, leverEnd.x - mOrigin.x); ///Lever Rotation Rad

    double rodRotation = -theta / (2*M_PI);
    double leverRotation = phi / (2*M_PI);

    mRotation = leverRotation;

    mRotationSource.SetRotation(mRotation);
    rod->SetRotation(rodRotation);
    Polygon::SetRotation(leverRotation);
}

void Lever::SetRotation(double rotation)
{
    mRotationSource.SetRotation(rotation);
    Polygon::SetRotation(rotation);
}

void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    double X = GetLocation().x - mLength/2 * cos(GetRotation() * M_PI * 2);
    double Y = GetLocation().y - mLength/2 * sin(GetRotation() * M_PI * 2);
    mTranslationSource.SetTranslation(wxPoint(X,Y));
    Component::Draw(graphics, x, y);
}
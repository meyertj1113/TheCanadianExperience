/**
 * @file Piston.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Piston.h"
#include <math.h>

Piston::Piston(const std::wstring& name, const std::wstring& ImagesDirectory, wxPoint origin)
        :Component(name, ImagesDirectory)
{
    Polygon::SetImage(ImagesDirectory);
    mOrigin = origin;

    //Component::SetLocation(mOrigin);
    Polygon::AddPoint(-25, 100);
    Polygon::AddPoint(-25, -7);
    Polygon::AddPoint(25, -7);
    Polygon::AddPoint(25, 100);

    mRodSink.SetComponent(this);
    mRodSink.SetNegotiator(this);
}

void Piston::Negotiate(Rod* rod)
{
    double alpha = asin((mOrigin.x-rod->GetOrigin().x)/double(rod->GetLength()));
    double beta = M_PI/2 - alpha;
    double b = rod->GetOrigin().y + (sin(beta) * rod->GetLength());

    double rodRotation = beta / (2*M_PI);

    rod->SetRotation(rodRotation);

    Component::SetLocation(wxPoint(mOrigin.x,b));
}


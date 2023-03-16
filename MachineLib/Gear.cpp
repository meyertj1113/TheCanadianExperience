/**
 * @file Gear.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Gear.h"

const double PI2 = M_PI * 2;     ///< PI * 2 constant
const double ToothDepth = 10;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down

Gear::Gear(const std::wstring& name, const std::wstring& ImagesDirectory, double radius, int numTeeth)
        :Component(name, ImagesDirectory)
{
    Polygon::SetImage(ImagesDirectory);
    mSink.SetComponent(this);
    mNumTeeth = numTeeth;

    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(mNumTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(mNumTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(mNumTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(mNumTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(mNumTeeth) * PI2;

        Polygon::AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        Polygon::AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        Polygon::AddPoint(radius * cos(angle3), radius * sin(angle3));
        Polygon::AddPoint(radius * cos(angle4), radius * sin(angle4));
        Polygon::AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
}

void Gear::SetRotation(double rotation)
{
    mSource.SetRotation(rotation);
    Polygon::SetRotation(rotation);
}

void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();

    mSource.AddSink(sink);
    sink->SetSpeed(-(double)mNumTeeth / (double)gear->mNumTeeth);
    sink->SetPhase(phase);
}
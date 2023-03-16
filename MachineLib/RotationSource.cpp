/**
 * @file RotationSource.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "RotationSource.h"
#include "RotationSink.h"

RotationSource::RotationSource()
{

}

void RotationSource::UpdateSinks(double rotation)
{
    for (auto sink : mSinks)
    {
        sink->Update(rotation);
    }
}

void RotationSource::AddSink(RotationSink* sink)
{
    mSinks.push_back(sink);
    sink->SetSource(this);
}

void RotationSource::SetRotation(double rotation)
{
    mRotation = rotation;
    UpdateSinks(rotation);
}

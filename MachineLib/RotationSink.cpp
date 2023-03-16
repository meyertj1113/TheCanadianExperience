/**
 * @file RotationSink.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "RotationSink.h"

RotationSink::RotationSink()
{

}

void RotationSink::Update(double rotation)
{
    mRotation = rotation;
    GetComponent()->SetRotation(rotation * mSpeed + mPhase);
}
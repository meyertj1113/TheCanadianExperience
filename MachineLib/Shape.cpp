/**
 * @file Shape.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "Shape.h"


Shape::Shape(const std::wstring& name, const std::wstring& ImagesDirectory)
    :Component(name, ImagesDirectory)
{
    Polygon::SetImage(ImagesDirectory);
    mSink.SetComponent(this);
}
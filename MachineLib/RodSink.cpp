/**
 * @file RodSink.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "RodSink.h"
#include "TranslationSink.h"

void RodSink::Negotiate(Rod* rod)
{
    mRodSource = rod;
    mNegotiator->Negotiate(rod);
}

RodSink::RodSink()
{

}

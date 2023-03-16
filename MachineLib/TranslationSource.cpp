/**
 * @file TranslationSource.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "TranslationSource.h"
#include "TranslationSink.h"

TranslationSource::TranslationSource()
{

}

void TranslationSource::UpdateSinks(wxPoint position)
{
    for (auto sink : mSinks)
    {
        sink->Update(position);
    }
}

void TranslationSource::AddSink(TranslationSink* sink)
{
    mSinks.push_back(sink);
    sink->SetSource(this);
}

void TranslationSource::SetTranslation(wxPoint position)
{
    mPosition = position;
    UpdateSinks(position);
}


/**
 * @file TranslationSink.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "TranslationSink.h"

TranslationSink::TranslationSink()
{

}

void TranslationSink::Update(wxPoint position)
{
    mPosition = position;
    GetComponent()->SetLocation(position);
}

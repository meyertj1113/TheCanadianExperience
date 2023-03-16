/**
 * @file OwensMachineFactory.cpp
 * @author TJ Meyer
 */

#include "OwensMachineFactory.h"

#include "pch.h"
#include "OwensMachineFactory.h"
#include "MachineController.h"
#include "Machine.h"
#include "MachineBase.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"
#include "Piston.h"

#include <math.h>
using namespace std;

/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
OwensMachineFactory::OwensMachineFactory(std::wstring imagesDir) : mImagesDir(imagesDir)
{

}

/**
 * Create a machine object
 *
 * @return Object of type MachineController
 */
std::shared_ptr<MachineController> OwensMachineFactory::CreateMachine()
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<MachineController>(1);

    // The base
    auto base = make_shared<Shape>(wstring(L"Base"), wstring(mImagesDir + L"/base.png"));
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);

    // The column
    auto column = make_shared<Shape>(wstring(L"Column"), wstring(mImagesDir + L"/column.png"));
    wid = 50;
    column->Rectangle(-wid/2, -40, wid, 250);

    // The cylinder
    auto cylinder = make_shared<Shape>(wstring(L"Cylinder"), wstring(mImagesDir + L"/cylinder.png"));
    wid = 75;
    cylinder->Rectangle(-wid/2 -150, -40, wid, 150);

    // The flag 2 (out of fear)
    auto flag2 = make_shared<Shape>(wstring(L"Flag"), wstring(mImagesDir + L"/flag.png"));
    flag2->AddPoint(-50, 0);
    flag2->AddPoint(-50, -100);
    flag2->AddPoint(5, -100);
    flag2->AddPoint(5, 0);
    flag2->SetLocation(wxPoint(0,-260));

    // The motor
    auto motor = make_shared<Motor>(wstring(L"Motor"), wstring(mImagesDir));
    wid = 100;
    motor->Rectangle(-wid/2 + 100, -40, wid, 100);

    // Gear 1
    auto gear1 = make_shared<Gear>(wstring(L"Gear1"),
            wstring(mImagesDir + L"/iron.png"),
            25, 10);
    gear1->SetLocation(wxPoint(101,-90));

    // Gear 2
    auto gear2 = make_shared<Gear>(wstring(L"Gear2"),
            wstring(mImagesDir + L"/hammered-copper.png"),
            50, 16);
    gear2->SetLocation(wxPoint(170,-90));

    // Arm
    auto arm = make_shared<Arm>(wstring(L"Arm"),
            wstring(mImagesDir + L"/arm1.png"), 60);
    arm->SetLocation(wxPoint(170,-90));

    // Rod 1
    auto rod1 = make_shared<Rod>(wstring(L"Rod1"),
            wstring(mImagesDir + L"/rust.png"),
            175, wxPoint(0, -200));

    // Rod 2
    auto rod2 = make_shared<Rod>(wstring(L"Rod2"),
            wstring(mImagesDir + L"/rust.png"),
            50, wxPoint(0, -300));

    // Lever
    auto lever = make_shared<Lever>(wstring(L"Lever"),
            wstring(mImagesDir + L"/lever.png"),
            300, wxPoint(0, -260));

    // Piston
    auto piston = make_shared<Piston>(wstring(L"Piston"),
            wstring(mImagesDir + L"/piston.png"),
            wxPoint(-150, 900));

    motor->GetSource()->AddSink(gear1->GetSink());
    gear1->Drive(gear2, 1);
    gear2->GetSource()->AddSink(arm->GetSink());
    arm->GetSource()->AddSink(rod1->GetSink());
    rod1->SetRodSink(lever->GetSink());
    lever->GetTranslationSource()->AddSink(rod2->GetSink());
    lever->GetRotationSource()->AddSink(flag2->GetSink());
    rod2->SetRodSink(piston->GetSink());

    machine->AddComponent(base);
    machine->AddComponent(motor);
    machine->AddMotor(motor);
    machine->AddComponent(gear1);
    machine->AddComponent(gear2);
    machine->AddComponent(arm);
    machine->AddComponent(lever);
    machine->AddComponent(flag2);
    machine->AddComponent(rod1);
    machine->AddComponent(piston);
    machine->AddComponent(rod2);
    machine->AddComponent(cylinder);
    machine->AddComponent(column);

    return machine;
}

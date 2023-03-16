/**
 * @file CustomMachineFactory.cpp
 * @author TJ Meyer
 */

#include "pch.h"
#include "pch.h"
#include "CustomMachineFactory.h"
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

using namespace std;
/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
CustomMachineFactory::CustomMachineFactory(std::wstring imagesDir) : mImagesDir(imagesDir)
{

}

/**
 * Create a machine object
 *
 * @return Object of type Machine
 */
std::shared_ptr<MachineController> CustomMachineFactory::CreateMachine()
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

    // The flag
    auto flag = make_shared<Shape>(wstring(L"Flag"), wstring(mImagesDir + L"/flag.png"));
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetLocation(wxPoint(0,-90));

    // Gear 1
    auto gear1 = make_shared<Gear>(wstring(L"Gear1"),
            wstring(mImagesDir + L"/hammered-copper.png"),
            50, 16);
    gear1->SetLocation(wxPoint(0,-90));

    // Gear 2
    auto gear2 = make_shared<Gear>(wstring(L"Gear2"),
            wstring(mImagesDir + L"/iron.png"),
            50, 16);
    gear2->SetLocation(wxPoint(90,-90));

    // Gear 3
    auto gear3 = make_shared<Gear>(wstring(L"Gear3"),
            wstring(mImagesDir + L"/hammered-copper.png"),
            100, 32);
    gear3->SetLocation(wxPoint(200,-175));

    // Gear 4
    auto gear4 = make_shared<Gear>(wstring(L"Gear4"),
            wstring(mImagesDir + L"/iron.png"),
            50, 16);
    gear4->SetLocation(wxPoint(90,-260));

    // Arm
    auto arm = make_shared<Arm>(wstring(L"Arm"), wstring(mImagesDir + L"/arm1.png"), 100);
    arm->SetLocation(wxPoint(90,-260));

    // Rod 1
    auto rod1 = make_shared<Rod>(wstring(L"Rod1"),
            wstring(mImagesDir + L"/rust.png"),
            200, wxPoint(0, -200));

    // Rod 2
    auto rod2 = make_shared<Rod>(wstring(L"Rod2"),
            wstring(mImagesDir + L"/rust.png"),
            100, wxPoint(0, -300));

    // Lever
    auto lever = make_shared<Lever>(wstring(L"Lever"),
            wstring(mImagesDir + L"/lever.png"),
            300, wxPoint(-100, -400));

    // Piston
    auto piston = make_shared<Piston>(wstring(L"Piston"),
            wstring(mImagesDir + L"/piston.png"),
            wxPoint(-200, -90));

    //The msu-flag
    auto msuflag = make_shared<Shape>(wstring(L"MSUFlag"), wstring(mImagesDir + L"/msu-flag.png"));
    msuflag->AddPoint(0, 0);
    msuflag->AddPoint(0, -100);
    msuflag->AddPoint(50, -100);
    msuflag->AddPoint(50, 0);
    msuflag->SetLocation(wxPoint(-100,-400));

    // The motor
    auto motor = make_shared<Motor>(wstring(L"Motor"), wstring(mImagesDir));
    wid = 100;
    motor->Rectangle(-wid/2, -40, wid, 100);

    motor->GetSource()->AddSink(flag->GetSink());
    motor->GetSource()->AddSink(gear1->GetSink());
    gear1->Drive(gear2, 1);
    gear2->Drive(gear3, 1);
    gear3->Drive(gear4, 1);
    gear4->GetSource()->AddSink(arm->GetSink());
    arm->GetSource()->AddSink(rod1->GetSink());
    rod1->SetRodSink(lever->GetSink());
    lever->GetTranslationSource()->AddSink(rod2->GetSink());
    lever->GetRotationSource()->AddSink(msuflag->GetSink());
    rod2->SetRodSink(piston->GetSink());

    machine->AddComponent(base);
    machine->AddComponent(motor);
    machine->AddMotor(motor);
    machine->AddComponent(flag);
    machine->AddComponent(gear1);
    machine->AddComponent(gear2);
    machine->AddComponent(gear3);
    machine->AddComponent(gear4);
    machine->AddComponent(arm);
    machine->AddComponent(msuflag);
    machine->AddComponent(lever);
    machine->AddComponent(rod1);
    machine->AddComponent(piston);
    machine->AddComponent(rod2);

    return machine;
}
/**
 * @file CustomMachineFactory.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CUSTOMMACHINEFACTORY_H
#define CANADIANEXPERIENCE_CUSTOMMACHINEFACTORY_H

#include <memory>
#include "MachineController.h"

class Machine;

/**
 * Machine factory class. Creates Machine objects
 */
class CustomMachineFactory {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    CustomMachineFactory(std::wstring imagesDir);

    std::shared_ptr<MachineController> CreateMachine();
};
#endif //CANADIANEXPERIENCE_CUSTOMMACHINEFACTORY_H

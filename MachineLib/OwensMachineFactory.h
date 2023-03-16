/**
 * @file OwensMachineFactory.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_OWENSMACHINEFACTORY_H
#define CANADIANEXPERIENCE_OWENSMACHINEFACTORY_H
#include <memory>
#include "MachineController.h"

class Machine;

/**
 * Machine factory class. Creates Machine objects
 */
class OwensMachineFactory {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    OwensMachineFactory(std::wstring imagesDir);

    std::shared_ptr<MachineController> CreateMachine();
};

#endif //CANADIANEXPERIENCE_OWENSMACHINEFACTORY_H

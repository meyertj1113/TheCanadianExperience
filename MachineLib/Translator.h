/**
 * @file Translator.h
 * @author TJ Meyer
 *
 *
 */

#ifndef CANADIANEXPERIENCE_TRANSLATOR_H
#define CANADIANEXPERIENCE_TRANSLATOR_H

class Rod;

/**
 * Negotiator interface for rod/piston and rod/lever negotiations
 */
class Translator {
public:
    /**
     * Negotiate with a rod to come up with a mutual rotation solution
     * @param rod
     */
    virtual void Negotiate(Rod *rod) = 0;
};

#endif //CANADIANEXPERIENCE_TRANSLATOR_H

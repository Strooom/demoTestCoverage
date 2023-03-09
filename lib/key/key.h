// #############################################################################
// ### Author(s) : Pascal Roobrouck - @strooom                               ###
// ### License : https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode ###
// #############################################################################

#pragma once
#include <stdint.h>

class key {
  public:
    static uint8_t toUpperCase(uint8_t aCharacter);                  // convert a character to upper case
    static bool isHexCharacter(uint8_t aCharacter);                  // check if a character is a valid hex character, ie. 0-9 or A-F - assuming upper case
    static uint8_t valueFromHexCharacter(uint8_t aCharacter);        // convert a hex character to a value, ie. 'A' -> 10
    static uint8_t hexCharacterFromValue(uint8_t aValue);            // convert a value to a hex character, ie. 10 -> 'A'

  private:
};

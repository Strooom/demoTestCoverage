
#include "key.h"

uint8_t key::toUpperCase(uint8_t aCharacter) {
    if (aCharacter >= 'a' && aCharacter <= 'z') {
        aCharacter = aCharacter - 'a' + 'A';
    }
    return aCharacter;
}

bool key::isHexCharacter(uint8_t aCharacter) {
    return ((aCharacter >= 'A' && aCharacter <= 'F') || (aCharacter >= '0' && aCharacter <= '9'));
}

uint8_t key::valueFromHexCharacter(uint8_t aCharacter) {
    if (aCharacter >= '0' && aCharacter <= '9') {
        return aCharacter - '0';
    }
    if (aCharacter >= 'A' && aCharacter <= 'F') {
        return aCharacter - 'A' + 10;
    }
    return 0;        // in case the character is not a hex character, return 0 as value
}

uint8_t key::hexCharacterFromValue(uint8_t aValue) {
    if (aValue <= 9) {
        return aValue + '0';
    } else if (aValue <= 15) {
        return aValue - 10 + 'A';
    } else
        return '?';
}

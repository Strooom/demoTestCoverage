#include <unity.h>
#include "key.h"

void setUp(void) {}           // before test
void tearDown(void) {}        // after test

void test_toUpperCase() {
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('A'), key::toUpperCase(static_cast<uint8_t>('a')));
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('A'), key::toUpperCase(static_cast<uint8_t>('A')));
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('0'), key::toUpperCase(static_cast<uint8_t>('0')));
}

void test_isHexCharacter() {
    TEST_ASSERT_TRUE(key::isHexCharacter(static_cast<uint8_t>('0')));
    TEST_ASSERT_TRUE(key::isHexCharacter(static_cast<uint8_t>('9')));
    TEST_ASSERT_TRUE(key::isHexCharacter(static_cast<uint8_t>('A')));
    TEST_ASSERT_TRUE(key::isHexCharacter(static_cast<uint8_t>('F')));
    TEST_ASSERT_FALSE(key::isHexCharacter(static_cast<uint8_t>('-')));
    TEST_ASSERT_FALSE(key::isHexCharacter(static_cast<uint8_t>('O')));
    TEST_ASSERT_FALSE(key::isHexCharacter(static_cast<uint8_t>('a')));        // we assume uppercase, so lowercase should fail...
}

void test_valueFromHexCharacter() {
    TEST_ASSERT_EQUAL_UINT8(0U, key::valueFromHexCharacter(static_cast<uint8_t>('0')));
    TEST_ASSERT_EQUAL_UINT8(9U, key::valueFromHexCharacter(static_cast<uint8_t>('9')));
    TEST_ASSERT_EQUAL_UINT8(10U, key::valueFromHexCharacter(static_cast<uint8_t>('A')));
    TEST_ASSERT_EQUAL_UINT8(15U, key::valueFromHexCharacter(static_cast<uint8_t>('F')));
}

void test_hexCharacterFromValue() {
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('0'), key::hexCharacterFromValue(0U));
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('9'), key::hexCharacterFromValue(9U));
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('A'), key::hexCharacterFromValue(10U));
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('F'), key::hexCharacterFromValue(15U));
    TEST_ASSERT_EQUAL_UINT8(static_cast<uint8_t>('?'), key::hexCharacterFromValue(16U));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_toUpperCase);
    RUN_TEST(test_isHexCharacter);
    RUN_TEST(test_valueFromHexCharacter);
    //RUN_TEST(test_hexCharacterFromValue);
    UNITY_END();
}
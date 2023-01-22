/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UnicodeCodePointTests.hpp"
#include "Ishiko/Text/UnicodeCodePoint.hpp"

using namespace Ishiko;

UnicodeCodePointTests::UnicodeCodePointTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "UnicodeCodePoint tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void UnicodeCodePointTests::ConstructorTest1(Test& test)
{
    UnicodeCodePoint cp;

    ISHIKO_TEST_PASS();
}

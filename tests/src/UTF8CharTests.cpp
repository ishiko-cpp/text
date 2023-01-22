/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UTF8CharTests.hpp"
#include "Ishiko/Text/UTF8Char.hpp"

using namespace Ishiko;

UTF8CharTests::UTF8CharTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "UTF8Char tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void UTF8CharTests::ConstructorTest1(Test& test)
{
    UTF8Char c{'a'};

    ISHIKO_TEST_PASS();
}

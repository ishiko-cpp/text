/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UTF8StringTests.hpp"
#include "Ishiko/Text/UTF8String.hpp"

using namespace Ishiko;

UTF8StringTests::UTF8StringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "UTF8String tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void UTF8StringTests::ConstructorTest1(Test& test)
{
    UTF8String str;

    ISHIKO_TEST_PASS();
}

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "TruncatedStringTests.hpp"
#include "Ishiko/Text/TruncatedString.hpp"

using namespace Ishiko;

TruncatedStringTests::TruncatedStringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TruncatedString tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void TruncatedStringTests::ConstructorTest1(Test& test)
{
    TruncatedString string;

    ISHIKO_TEST_PASS();
}

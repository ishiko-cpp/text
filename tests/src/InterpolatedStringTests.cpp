/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "InterpolatedStringTests.hpp"

using namespace Ishiko;

InterpolatedStringTests::InterpolatedStringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "InterpolatedString tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void InterpolatedStringTests::ConstructorTest1(Test& test)
{
}

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "InterpolatedStringTests.hpp"
#include "Ishiko/Text/InterpolatedString.hpp"
#include <Ishiko/Errors.hpp>

using namespace Ishiko;

InterpolatedStringTests::InterpolatedStringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "InterpolatedString tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
    append<HeapAllocationErrorsTest>("expand test 1", ExpandTest1);
    append<HeapAllocationErrorsTest>("expand test 2", ExpandTest2);
}

void InterpolatedStringTests::ConstructorTest1(Test& test)
{
    InterpolatedString string;

    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ConstructorTest2(Test& test)
{
    InterpolatedString string("text");

    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest1(Test& test)
{
    InterpolatedString string;

    std::map<std::string, std::string> map;
    InterpolatedString::MapCallbacks callbacks(map);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString, "");
    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest2(Test& test)
{
    InterpolatedString string("text");

    std::map<std::string, std::string> map;
    InterpolatedString::MapCallbacks callbacks(map);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString, "text");
    ISHIKO_TEST_PASS();
}

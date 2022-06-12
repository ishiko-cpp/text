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
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
    append<HeapAllocationErrorsTest>("Constructor test 3", ConstructorTest3);
}

void TruncatedStringTests::ConstructorTest1(Test& test)
{
    TruncatedString string(20);

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 20);
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::ConstructorTest2(Test& test)
{
    TruncatedString string("A string", 8);

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "A string");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::ConstructorTest3(Test& test)
{
    TruncatedString string("A very long string", 8);

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "A ver...");
    ISHIKO_TEST_PASS();
}

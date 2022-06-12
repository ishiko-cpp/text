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
    append<HeapAllocationErrorsTest>("append test 1", AppendTest1);
    append<HeapAllocationErrorsTest>("append test 2", AppendTest2);
    append<HeapAllocationErrorsTest>("append test 3", AppendTest3);
    append<HeapAllocationErrorsTest>("append test 4", AppendTest4);
    append<HeapAllocationErrorsTest>("append test 5", AppendTest5);
    append<HeapAllocationErrorsTest>("append test 6", AppendTest6);
    append<HeapAllocationErrorsTest>("append test 7", AppendTest7);
}

void TruncatedStringTests::ConstructorTest1(Test& test)
{
    TruncatedString string(20);

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 20);
    ISHIKO_TEST_FAIL_IF(string.isTruncated());
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::ConstructorTest2(Test& test)
{
    TruncatedString string("A string", 8);

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 8);
    ISHIKO_TEST_FAIL_IF(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "A string");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::ConstructorTest3(Test& test)
{
    TruncatedString string("A very long string", 8);

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 8);
    ISHIKO_TEST_FAIL_IF_NOT(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "A ver...");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest1(Test& test)
{
    TruncatedString string(20);

    string.append("text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 4);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 20);
    ISHIKO_TEST_FAIL_IF(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "text");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest2(Test& test)
{
    TruncatedString string("some ", 20);

    string.append("more text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 14);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 20);
    ISHIKO_TEST_FAIL_IF(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "some more text");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest3(Test& test)
{
    TruncatedString string("some ", 14);

    string.append("more text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 14);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 14);
    ISHIKO_TEST_FAIL_IF(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "some more text");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest4(Test& test)
{
    TruncatedString string("some ", 13);

    string.append("more text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 13);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 13);
    ISHIKO_TEST_FAIL_IF_NOT(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "some more ...");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest5(Test& test)
{
    TruncatedString string("some ", 8);

    string.append("more text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 8);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 8);
    ISHIKO_TEST_FAIL_IF_NOT(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "some ...");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest6(Test& test)
{
    TruncatedString string("some ", 7);

    string.append("text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 7);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 7);
    ISHIKO_TEST_FAIL_IF_NOT(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "some...");
    ISHIKO_TEST_PASS();
}

void TruncatedStringTests::AppendTest7(Test& test)
{
    TruncatedString string("some ", 5);

    string.append("text");

    ISHIKO_TEST_FAIL_IF_NEQ(string.size(), 5);
    ISHIKO_TEST_FAIL_IF_NEQ(string.maxSize(), 5);
    ISHIKO_TEST_FAIL_IF_NOT(string.isTruncated());
    ISHIKO_TEST_FAIL_IF_NEQ(string.asString(), "so...");
    ISHIKO_TEST_PASS();
}

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
    append<HeapAllocationErrorsTest>("expand test 3", ExpandTest3);
    append<HeapAllocationErrorsTest>("expand test 4", ExpandTest4);
    append<HeapAllocationErrorsTest>("expand test 5", ExpandTest5);
    append<HeapAllocationErrorsTest>("expand test 6", ExpandTest6);
    append<HeapAllocationErrorsTest>("expand test 7", ExpandTest7);
    append<HeapAllocationErrorsTest>("expand test 8", ExpandTest8);
    append<HeapAllocationErrorsTest>("expand error test 1", ExpandErrorTest1);
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
    InterpolatedString::MapCallbacks callbacks(map, false);

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
    InterpolatedString::MapCallbacks callbacks(map, false);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString, "text");
    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest3(Test& test)
{
    InterpolatedString string("${var1}");

    std::map<std::string, std::string> map1;
    map1["var1"] = "value1";
    InterpolatedString::MapCallbacks callbacks1(map1, false);

    Error error;
    std::string expandedString1 = string.expand(callbacks1, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString1, "value1");

    std::map<std::string, std::string> map2;
    map2["var1"] = "";
    InterpolatedString::MapCallbacks callbacks2(map2, false);

    std::string expandedString2 = string.expand(callbacks2, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString2, "");

    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest4(Test& test)
{
    InterpolatedString string("prefix${var1}");

    std::map<std::string, std::string> map1;
    map1["var1"] = "value1";
    InterpolatedString::MapCallbacks callbacks1(map1, false);

    Error error;
    std::string expandedString1 = string.expand(callbacks1, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString1, "prefixvalue1");

    std::map<std::string, std::string> map2;
    map2["var1"] = "";
    InterpolatedString::MapCallbacks callbacks2(map2, false);

    std::string expandedString2 = string.expand(callbacks2, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString2, "prefix");

    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest5(Test& test)
{
    InterpolatedString string("${var1}suffix");

    std::map<std::string, std::string> map1;
    map1["var1"] = "value1";
    InterpolatedString::MapCallbacks callbacks1(map1, false);

    Error error;
    std::string expandedString1 = string.expand(callbacks1, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString1, "value1suffix");

    std::map<std::string, std::string> map2;
    map2["var1"] = "";
    InterpolatedString::MapCallbacks callbacks2(map2, false);

    std::string expandedString2 = string.expand(callbacks2, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString2, "suffix");

    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest6(Test& test)
{
    InterpolatedString string("${var1}${var2}");

    std::map<std::string, std::string> map;
    map["var1"] = "value1";
    map["var2"] = "value2";
    InterpolatedString::MapCallbacks callbacks(map, false);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString, "value1value2");
    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest7(Test& test)
{
    InterpolatedString string("start${var1}middle${var2}end");

    std::map<std::string, std::string> map;
    map["var1"] = "value1";
    map["var2"] = "value2";
    InterpolatedString::MapCallbacks callbacks(map, false);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString, "startvalue1middlevalue2end");
    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandTest8(Test& test)
{
    InterpolatedString string("start${var1}middle${var2}end");

    std::map<std::string, std::string> map;
    map["var1"] = "value1";
    InterpolatedString::MapCallbacks callbacks(map, true);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(expandedString, "startvalue1middleend");
    ISHIKO_TEST_PASS();
}

void InterpolatedStringTests::ExpandErrorTest1(Test& test)
{
    InterpolatedString string("${var1}");

    std::map<std::string, std::string> map;
    InterpolatedString::MapCallbacks callbacks(map, false);

    Error error;
    std::string expandedString = string.expand(callbacks, error);

    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_PASS();
}

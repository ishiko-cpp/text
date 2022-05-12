/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "CStringTests.hpp"
#include <Ishiko/Text/CString.hpp>

using namespace Ishiko;

CStringTests::CStringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CString tests", context)
{
    append<HeapAllocationErrorsTest>("Duplicate test 1", DuplicateTest1);
    append<HeapAllocationErrorsTest>("Substring test 1", SubstringTest1);
    append<HeapAllocationErrorsTest>("Substring test 2", SubstringTest2);
    append<HeapAllocationErrorsTest>("Find test 1", FindTest1);
    append<HeapAllocationErrorsTest>("StartsWith test 1", StartsWithTest1);
}

void CStringTests::DuplicateTest1(Test& test)
{
    char* str = CString::Duplicate("string");

    ISHIKO_TEST_FAIL_IF_STR_NEQ(str, "string");

    delete[] str;

    ISHIKO_TEST_PASS();
}

void CStringTests::SubstringTest1(Test& test)
{
    const char* str = "string";

    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 0), "string");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 1), "tring");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 5), "g");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 6), "");
    ISHIKO_TEST_PASS();
}

void CStringTests::SubstringTest2(Test& test)
{
    const char* str = "string";

    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 0, 1), "s");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 0, 2), "st");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 0, 5), "strin");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 0, 6), "string");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 1, 1), "");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 1, 2), "t");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 1, 5), "trin");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 1, 6), "tring");
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Substring(str, 6, 6), "");
    ISHIKO_TEST_PASS();
}

void CStringTests::FindTest1(Test& test)
{
    const char* str = "string";

    ISHIKO_TEST_FAIL_IF_NEQ(CString::Find(str, "s"), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Find(str, "string"), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Find(str, "t"), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Find(str, "g"), 5);
    ISHIKO_TEST_FAIL_IF_NEQ(CString::Find(str, "k"), std::string::npos);
    ISHIKO_TEST_PASS();
}

void CStringTests::StartsWithTest1(Test& test)
{
    const char* str = "string";

    ISHIKO_TEST_FAIL_IF_NOT(CString::StartsWith(str, "s"));
    ISHIKO_TEST_FAIL_IF_NOT(CString::StartsWith(str, "string"));
    ISHIKO_TEST_FAIL_IF(CString::StartsWith(str, "t"));
    ISHIKO_TEST_PASS();
}

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
}

void CStringTests::DuplicateTest1(Test& test)
{
    char* str = CString::Duplicate("string");

    ISHIKO_TEST_FAIL_IF_STR_NEQ(str, "string");

    delete[] str;

    ISHIKO_TEST_PASS();
}

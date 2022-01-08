/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "CStringTests.hpp"
#include <Ishiko/Text/CString.hpp>

using namespace Ishiko::Tests;
using namespace Ishiko::Text;

CStringTests::CStringTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "CString tests", environment)
{
    append<HeapAllocationErrorsTest>("Duplicate test 1", DuplicateTest1);
}

void CStringTests::DuplicateTest1(Test& test)
{
    char* str = CString::Duplicate("string");

    ISHIKO_FAIL_IF_STR_NEQ(str, "string");

    delete[] str;

    ISHIKO_PASS();
}

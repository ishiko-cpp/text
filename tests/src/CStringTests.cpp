/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "CStringTests.h"
#include "Ishiko/Text/CString.h"

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

    ISHTF_FAIL_IF_STR_NEQ(str, "string");

    delete[] str;

    ISHTF_PASS();
}

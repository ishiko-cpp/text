/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#include "CStringTests.h"
#include "Ishiko/Text/CString.h"

using namespace Ishiko::Tests;

CStringTests::CStringTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "CString tests", environment)
{
    append<HeapAllocationErrorsTest>("Duplicate test 1", DuplicateTest1);
}

void CStringTests::DuplicateTest1(Test& test)
{
    char* str = Ishiko::CString::Duplicate("string");

    ISHTF_FAIL_IF_STR_NEQ(str, "string");

    delete[] str;

    ISHTF_PASS();
}

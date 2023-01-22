/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UnicodeCodePointTests.hpp"
#include "Ishiko/Text/UnicodeCodePoint.hpp"

using namespace Ishiko;

UnicodeCodePointTests::UnicodeCodePointTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "UnicodeCodePoint tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("isASCIIDigit test 1", IsASCIIDigitTest1);
}

void UnicodeCodePointTests::ConstructorTest1(Test& test)
{
    UnicodeCodePoint cp{'a'};

    ISHIKO_TEST_PASS();
}

void UnicodeCodePointTests::IsASCIIDigitTest1(Test& test)
{
    UnicodeCodePoint cp_1{'a'};
    UnicodeCodePoint cp_2{'0'};
    UnicodeCodePoint cp_3{'5'};
    UnicodeCodePoint cp_4{'9'};

    ISHIKO_TEST_FAIL_IF(cp_1.isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NOT(cp_2.isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NOT(cp_3.isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NOT(cp_4.isASCIIDigit());
    ISHIKO_TEST_PASS();
}

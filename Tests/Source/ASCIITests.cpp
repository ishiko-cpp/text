/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#include "ASCIITests.h"
#include "Ishiko/Text/ASCII.h"

using namespace Ishiko::Tests;
using namespace Ishiko::Text;

ASCIITests::ASCIITests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "ASCII tests", environment)
{
    append<HeapAllocationErrorsTest>("ToLowerCase test 1", ToLowerCaseTest1);
    append<HeapAllocationErrorsTest>("ToUpperCase test 1", ToUpperCaseTest1);
}

void ASCIITests::ToLowerCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToLowerCase(str);

    ISHTF_FAIL_IF_NEQ(str, "hello world!");
    ISHTF_PASS();
}

void ASCIITests::ToUpperCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToUpperCase(str);

    ISHTF_FAIL_IF_NEQ(str, "HELLO WORLD!");
    ISHTF_PASS();
}

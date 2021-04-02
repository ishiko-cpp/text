/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TEST_TEXT_ASCIITESTS_H_
#define _ISHIKO_TEST_TEXT_ASCIITESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class ASCIITests : public Ishiko::Tests::TestSequence
{
public:
    ASCIITests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ToLowerCaseTest1(Ishiko::Tests::Test& test);
    static void ToUpperCaseTest1(Ishiko::Tests::Test& test);
};

#endif

/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TEST_TEXT_CSTRINGTESTS_H_
#define _ISHIKO_TEST_TEXT_CSTRINGTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class CStringTests : public Ishiko::Tests::TestSequence
{
public:
    CStringTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void DuplicateTest1(Ishiko::Tests::Test& test);
};

#endif

/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TEXT_TESTS_CSTRINGTESTS_H_
#define _ISHIKO_TEXT_TESTS_CSTRINGTESTS_H_

#include <Ishiko/Tests/Core.h>

class CStringTests : public Ishiko::Tests::TestSequence
{
public:
    CStringTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void DuplicateTest1(Ishiko::Tests::Test& test);
};

#endif

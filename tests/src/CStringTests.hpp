/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_TESTS_CSTRINGTESTS_HPP_
#define _ISHIKO_CPP_TEXT_TESTS_CSTRINGTESTS_HPP_

#include <Ishiko/Tests/Core.hpp>

class CStringTests : public Ishiko::Tests::TestSequence
{
public:
    CStringTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void DuplicateTest1(Ishiko::Tests::Test& test);
};

#endif

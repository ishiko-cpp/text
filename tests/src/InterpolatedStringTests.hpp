/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_TESTS_INTERPOLATEDSTRINGTESTS_HPP_
#define _ISHIKO_CPP_TEXT_TESTS_INTERPOLATEDSTRINGTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class InterpolatedStringTests : public Ishiko::TestSequence
{
public:
    InterpolatedStringTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif

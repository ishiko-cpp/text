/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_TESTS_TRUNCATEDSTRINGTESTS_HPP_
#define _ISHIKO_CPP_TEXT_TESTS_TRUNCATEDSTRINGTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class TruncatedStringTests : public Ishiko::TestSequence
{
public:
    TruncatedStringTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
    static void ConstructorTest3(Ishiko::Test& test);
};

#endif

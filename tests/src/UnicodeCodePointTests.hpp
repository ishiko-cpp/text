/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TEXT_TESTS_UNICODECODEPOINTTESTS_HPP
#define GUARD_ISHIKO_CPP_TEXT_TESTS_UNICODECODEPOINTTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class UnicodeCodePointTests : public Ishiko::TestSequence
{
public:
    UnicodeCodePointTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void IsASCIIDigitTest1(Ishiko::Test& test);
};

#endif

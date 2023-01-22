/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TEXT_TESTS_UTF8STRINGTESTS_HPP
#define GUARD_ISHIKO_CPP_TEXT_TESTS_UTF8STRINGTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class UTF8StringTests : public Ishiko::TestSequence
{
public:
    UTF8StringTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
    static void ConstructorTest3(Ishiko::Test& test);
    static void ConstIteratorTest1(Ishiko::Test& test);
    static void ConstIteratorTest2(Ishiko::Test& test);
    static void ConstIteratorTest3(Ishiko::Test& test);
    static void ConstIteratorTest4(Ishiko::Test& test);
    static void SubstrTest1(Ishiko::Test& test);
};

#endif

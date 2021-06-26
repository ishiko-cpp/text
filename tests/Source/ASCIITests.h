/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TEXT_TESTS_ASCIITESTS_H_
#define _ISHIKO_TEXT_TESTS_ASCIITESTS_H_

#include <Ishiko/Tests/Core.h>

class ASCIITests : public Ishiko::Tests::TestSequence
{
public:
    ASCIITests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void SplitTest1(Ishiko::Tests::Test& test);
    static void SplitTest2(Ishiko::Tests::Test& test);
    static void SplitTest3(Ishiko::Tests::Test& test);
    static void SplitTest4(Ishiko::Tests::Test& test);
    static void SplitTest5(Ishiko::Tests::Test& test);
    static void SplitTest6(Ishiko::Tests::Test& test);
    static void SplitTest7(Ishiko::Tests::Test& test);
    static void SplitTest8(Ishiko::Tests::Test& test);
    static void SplitTest9(Ishiko::Tests::Test& test);
    static void SplitTest10(Ishiko::Tests::Test& test);
    static void SplitTest11(Ishiko::Tests::Test& test);
    static void GetLinesTest1(Ishiko::Tests::Test& test);
    static void GetLinesTest2(Ishiko::Tests::Test& test);
    static void GetLinesTest3(Ishiko::Tests::Test& test);
    static void GetLinesTest4(Ishiko::Tests::Test& test);
    static void GetLinesTest5(Ishiko::Tests::Test& test);
    static void GetLinesTest6(Ishiko::Tests::Test& test);
    static void GetLinesTest7(Ishiko::Tests::Test& test);
    static void GetLinesTest8(Ishiko::Tests::Test& test);
    static void GetLinesTest9(Ishiko::Tests::Test& test);
    static void GetLinesTest10(Ishiko::Tests::Test& test);
    static void GetLinesTest11(Ishiko::Tests::Test& test);
    static void GetLinesTest12(Ishiko::Tests::Test& test);
    static void GetLinesTest13(Ishiko::Tests::Test& test);
    static void ToLowerCaseTest1(Ishiko::Tests::Test& test);
    static void ToUpperCaseTest1(Ishiko::Tests::Test& test);
    static void TrimTest1(Ishiko::Tests::Test& test);
    static void TrimTest2(Ishiko::Tests::Test& test);
    static void TrimTest3(Ishiko::Tests::Test& test);
    static void TrimTest4(Ishiko::Tests::Test& test);
    static void TrimTest5(Ishiko::Tests::Test& test);
    static void TrimTest6(Ishiko::Tests::Test& test);
    static void TrimTest7(Ishiko::Tests::Test& test);
    static void TrimTest8(Ishiko::Tests::Test& test);
    static void TrimTest9(Ishiko::Tests::Test& test);
    static void TrimTest10(Ishiko::Tests::Test& test);
    static void TrimTest11(Ishiko::Tests::Test& test);
};

#endif

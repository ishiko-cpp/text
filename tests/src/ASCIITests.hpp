/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_TESTS_ASCIITESTS_HPP_
#define _ISHIKO_CPP_TEXT_TESTS_ASCIITESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class ASCIITests : public Ishiko::TestSequence
{
public:
    ASCIITests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void IsAlphaTest1(Ishiko::Test& test);
    static void IsAlphaTest2(Ishiko::Test& test);
    static void IsNumericTest1(Ishiko::Test& test);
    static void IsNumericTest2(Ishiko::Test& test);
    static void IsAlphanumericTest1(Ishiko::Test& test);
    static void IsAlphanumericTest2(Ishiko::Test& test);
    static void IsWhitespaceTest1(Ishiko::Test& test);
    static void IsWhitespaceTest2(Ishiko::Test& test);
    static void SplitTest1(Ishiko::Test& test);
    static void SplitTest2(Ishiko::Test& test);
    static void SplitTest3(Ishiko::Test& test);
    static void SplitTest4(Ishiko::Test& test);
    static void SplitTest5(Ishiko::Test& test);
    static void SplitTest6(Ishiko::Test& test);
    static void SplitTest7(Ishiko::Test& test);
    static void SplitTest8(Ishiko::Test& test);
    static void SplitTest9(Ishiko::Test& test);
    static void SplitTest10(Ishiko::Test& test);
    static void SplitTest11(Ishiko::Test& test);
    static void SplitTest12(Ishiko::Test& test);
    static void SplitTest13(Ishiko::Test& test);
    static void SplitTest14(Ishiko::Test& test);
    static void GetLinesTest1(Ishiko::Test& test);
    static void GetLinesTest2(Ishiko::Test& test);
    static void GetLinesTest3(Ishiko::Test& test);
    static void GetLinesTest4(Ishiko::Test& test);
    static void GetLinesTest5(Ishiko::Test& test);
    static void GetLinesTest6(Ishiko::Test& test);
    static void GetLinesTest7(Ishiko::Test& test);
    static void GetLinesTest8(Ishiko::Test& test);
    static void GetLinesTest9(Ishiko::Test& test);
    static void GetLinesTest10(Ishiko::Test& test);
    static void GetLinesTest11(Ishiko::Test& test);
    static void GetLinesTest12(Ishiko::Test& test);
    static void GetLinesTest13(Ishiko::Test& test);
    static void ToLowerCaseTest1(Ishiko::Test& test);
    static void ToUpperCaseTest1(Ishiko::Test& test);
    static void TrimTest1(Ishiko::Test& test);
    static void TrimTest2(Ishiko::Test& test);
    static void TrimTest3(Ishiko::Test& test);
    static void TrimTest4(Ishiko::Test& test);
    static void TrimTest5(Ishiko::Test& test);
    static void TrimTest6(Ishiko::Test& test);
    static void TrimTest7(Ishiko::Test& test);
    static void TrimTest8(Ishiko::Test& test);
    static void TrimTest9(Ishiko::Test& test);
    static void TrimTest10(Ishiko::Test& test);
    static void TrimTest11(Ishiko::Test& test);
    static void RemovePrefixTest1(Ishiko::Test& test);
    static void RemovePrefixTest2(Ishiko::Test& test);
    static void RemovePrefixTest3(Ishiko::Test& test);
    static void RemovePrefixTest4(Ishiko::Test& test);
    static void RemovePrefixTest5(Ishiko::Test& test);
    static void RemoveSuffixTest1(Ishiko::Test& test);
    static void RemoveSuffixTest2(Ishiko::Test& test);
    static void RemoveSuffixTest3(Ishiko::Test& test);
    static void RemoveSuffixTest4(Ishiko::Test& test);
    static void RemoveSuffixTest5(Ishiko::Test& test);
    static void ToHexStringTest1(Ishiko::Test& test);
    static void ToHexStringTest2(Ishiko::Test& test);
    static void ConvertInt8Test1(Ishiko::Test& test);
    static void ConvertInt8Test2(Ishiko::Test& test);
    static void ConvertInt8Test3(Ishiko::Test& test);
    static void ConvertUint8Test1(Ishiko::Test& test);
    static void ConvertUint8Test2(Ishiko::Test& test);
    static void ConvertInt16Test1(Ishiko::Test& test);
    static void ConvertInt16Test2(Ishiko::Test& test);
    static void ConvertInt16Test3(Ishiko::Test& test);
    static void ConvertUint16Test1(Ishiko::Test& test);
    static void ConvertUint16Test2(Ishiko::Test& test);
    static void ConvertUint16Test3(Ishiko::Test& test);
    static void ConvertUint16Test4(Ishiko::Test& test);
    static void ConvertUint64Test1(Ishiko::Test& test);
    static void ConvertUint64Test2(Ishiko::Test& test);
    static void ConvertUint64Test3(Ishiko::Test& test);
    static void ConvertUint64Test4(Ishiko::Test& test);
};

#endif

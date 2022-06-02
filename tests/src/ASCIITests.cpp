/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCIITests.hpp"
#include <Ishiko/Text/ASCII.hpp>

using namespace Ishiko;

ASCIITests::ASCIITests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "ASCII tests", context)
{
    append<HeapAllocationErrorsTest>("IsAlpha test 1", IsAlphaTest1);
    append<HeapAllocationErrorsTest>("IsAlpha test 2", IsAlphaTest2);
    append<HeapAllocationErrorsTest>("IsNumeric test 1", IsNumericTest1);
    append<HeapAllocationErrorsTest>("IsNumeric test 2", IsNumericTest2);
    append<HeapAllocationErrorsTest>("IsAlphanumeric test 1", IsAlphanumericTest1);
    append<HeapAllocationErrorsTest>("IsAlphanumeric test 2", IsAlphanumericTest2);
    append<HeapAllocationErrorsTest>("IsWhitespace test 1", IsWhitespaceTest1);
    append<HeapAllocationErrorsTest>("IsWhitespace test 2", IsWhitespaceTest2);
    append<HeapAllocationErrorsTest>("Split test 1", SplitTest1);
    append<HeapAllocationErrorsTest>("Split test 2", SplitTest2);
    append<HeapAllocationErrorsTest>("Split test 3", SplitTest3);
    append<HeapAllocationErrorsTest>("Split test 4", SplitTest4);
    append<HeapAllocationErrorsTest>("Split test 5", SplitTest5);
    append<HeapAllocationErrorsTest>("Split test 6", SplitTest6);
    append<HeapAllocationErrorsTest>("Split test 7", SplitTest7);
    append<HeapAllocationErrorsTest>("Split test 8", SplitTest8);
    append<HeapAllocationErrorsTest>("Split test 9", SplitTest9);
    append<HeapAllocationErrorsTest>("Split test 10", SplitTest10);
    append<HeapAllocationErrorsTest>("Split test 11", SplitTest11);
    append<HeapAllocationErrorsTest>("Split test 12", SplitTest12);
    append<HeapAllocationErrorsTest>("Split test 13", SplitTest13);
    append<HeapAllocationErrorsTest>("Split test 14", SplitTest14);
    append<HeapAllocationErrorsTest>("GetLines test 1", GetLinesTest1);
    append<HeapAllocationErrorsTest>("GetLines test 2", GetLinesTest2);
    append<HeapAllocationErrorsTest>("GetLines test 3", GetLinesTest3);
    append<HeapAllocationErrorsTest>("GetLines test 4", GetLinesTest4);
    append<HeapAllocationErrorsTest>("GetLines test 5", GetLinesTest5);
    append<HeapAllocationErrorsTest>("GetLines test 6", GetLinesTest6);
    append<HeapAllocationErrorsTest>("GetLines test 7", GetLinesTest7);
    append<HeapAllocationErrorsTest>("GetLines test 8", GetLinesTest8);
    append<HeapAllocationErrorsTest>("GetLines test 9", GetLinesTest9);
    append<HeapAllocationErrorsTest>("GetLines test 10", GetLinesTest10);
    append<HeapAllocationErrorsTest>("GetLines test 11", GetLinesTest11);
    append<HeapAllocationErrorsTest>("GetLines test 12", GetLinesTest12);
    append<HeapAllocationErrorsTest>("GetLines test 13", GetLinesTest13);
    append<HeapAllocationErrorsTest>("ToLowerCase test 1", ToLowerCaseTest1);
    append<HeapAllocationErrorsTest>("ToUpperCase test 1", ToUpperCaseTest1);
    append<HeapAllocationErrorsTest>("Trim test 1", TrimTest1);
    append<HeapAllocationErrorsTest>("Trim test 2", TrimTest2);
    append<HeapAllocationErrorsTest>("Trim test 3", TrimTest3);
    append<HeapAllocationErrorsTest>("Trim test 4", TrimTest4);
    append<HeapAllocationErrorsTest>("Trim test 5", TrimTest5);
    append<HeapAllocationErrorsTest>("Trim test 6", TrimTest6);
    append<HeapAllocationErrorsTest>("Trim test 7", TrimTest7);
    append<HeapAllocationErrorsTest>("Trim test 8", TrimTest8);
    append<HeapAllocationErrorsTest>("Trim test 9", TrimTest9);
    append<HeapAllocationErrorsTest>("Trim test 10", TrimTest10);
    append<HeapAllocationErrorsTest>("Trim test 11", TrimTest11);
    append<HeapAllocationErrorsTest>("RemovePrefix test 1", RemovePrefixTest1);
    append<HeapAllocationErrorsTest>("RemovePrefix test 2", RemovePrefixTest2);
    append<HeapAllocationErrorsTest>("RemovePrefix test 3", RemovePrefixTest3);
    append<HeapAllocationErrorsTest>("RemovePrefix test 4", RemovePrefixTest4);
    append<HeapAllocationErrorsTest>("RemovePrefix test 5", RemovePrefixTest5);
    append<HeapAllocationErrorsTest>("RemoveSuffix test 1", RemoveSuffixTest1);
    append<HeapAllocationErrorsTest>("RemoveSuffix test 2", RemoveSuffixTest2);
    append<HeapAllocationErrorsTest>("RemoveSuffix test 3", RemoveSuffixTest3);
    append<HeapAllocationErrorsTest>("RemoveSuffix test 4", RemoveSuffixTest4);
    append<HeapAllocationErrorsTest>("RemoveSuffix test 5", RemoveSuffixTest5);
    append<HeapAllocationErrorsTest>("Convert to int8_t test 1", ConvertInt8Test1);
    append<HeapAllocationErrorsTest>("Convert to int8_t test 2", ConvertInt8Test2);
    append<HeapAllocationErrorsTest>("Convert to int8_t test 3", ConvertInt8Test3);
    append<HeapAllocationErrorsTest>("Convert to uint8_t test 1", ConvertUint8Test1);
    append<HeapAllocationErrorsTest>("Convert to uint8_t test 2", ConvertUint8Test2);
    append<HeapAllocationErrorsTest>("Convert to int16_t test 1", ConvertInt16Test1);
    append<HeapAllocationErrorsTest>("Convert to int16_t test 2", ConvertInt16Test2);
    append<HeapAllocationErrorsTest>("Convert to int16_t test 3", ConvertInt16Test3);
    append<HeapAllocationErrorsTest>("Convert to uint16_t test 1", ConvertUint16Test1);
    append<HeapAllocationErrorsTest>("Convert to uint16_t test 2", ConvertUint16Test2);
    append<HeapAllocationErrorsTest>("Convert to uint64_t test 1", ConvertUint64Test1);
    append<HeapAllocationErrorsTest>("Convert to uint64_t test 2", ConvertUint64Test2);
    append<HeapAllocationErrorsTest>("Convert to uint64_t test 3", ConvertUint64Test3);
    append<HeapAllocationErrorsTest>("Convert to uint64_t test 4", ConvertUint64Test4);
}

void ASCIITests::IsAlphaTest1(Test& test)
{
    bool alpha1 = ASCII::IsAlpha('a');
    bool alpha2 = ASCII::IsAlpha('d');
    bool alpha3 = ASCII::IsAlpha('z');

    ISHIKO_TEST_FAIL_IF_NOT(alpha1);
    ISHIKO_TEST_FAIL_IF_NOT(alpha2);
    ISHIKO_TEST_FAIL_IF_NOT(alpha3);

    bool alpha4 = ASCII::IsAlpha('A');
    bool alpha5 = ASCII::IsAlpha('D');
    bool alpha6 = ASCII::IsAlpha('Z');

    ISHIKO_TEST_FAIL_IF_NOT(alpha4);
    ISHIKO_TEST_FAIL_IF_NOT(alpha5);
    ISHIKO_TEST_FAIL_IF_NOT(alpha6);

    ISHIKO_TEST_PASS();
}

void ASCIITests::IsAlphaTest2(Test& test)
{
    bool alpha1 = ASCII::IsAlpha(0);
    bool alpha2 = ASCII::IsAlpha('\r');
    bool alpha3 = ASCII::IsAlpha('!');
    bool alpha4 = ASCII::IsAlpha('.');

    ISHIKO_TEST_FAIL_IF(alpha1);
    ISHIKO_TEST_FAIL_IF(alpha2);
    ISHIKO_TEST_FAIL_IF(alpha3);
    ISHIKO_TEST_FAIL_IF(alpha4);

    ISHIKO_TEST_PASS();
}

void ASCIITests::IsNumericTest1(Test& test)
{
    bool num1 = ASCII::IsNumeric('0');
    bool num2 = ASCII::IsNumeric('4');
    bool num3 = ASCII::IsNumeric('9');

    ISHIKO_TEST_FAIL_IF_NOT(num1);
    ISHIKO_TEST_FAIL_IF_NOT(num2);
    ISHIKO_TEST_FAIL_IF_NOT(num3);
    ISHIKO_TEST_PASS();
}

void ASCIITests::IsNumericTest2(Test& test)
{
    bool num1 = ASCII::IsNumeric(0);
    bool num2 = ASCII::IsNumeric('a');
    bool num3 = ASCII::IsNumeric('.');

    ISHIKO_TEST_FAIL_IF(num1);
    ISHIKO_TEST_FAIL_IF(num2);
    ISHIKO_TEST_FAIL_IF(num3);
    ISHIKO_TEST_PASS();
}

void ASCIITests::IsAlphanumericTest1(Test& test)
{
    bool alphanum1 = ASCII::IsAlphanumeric('a');
    bool alphanum2 = ASCII::IsAlphanumeric('d');
    bool alphanum3 = ASCII::IsAlphanumeric('z');

    ISHIKO_TEST_FAIL_IF_NOT(alphanum1);
    ISHIKO_TEST_FAIL_IF_NOT(alphanum2);
    ISHIKO_TEST_FAIL_IF_NOT(alphanum3);

    bool alphanum4 = ASCII::IsAlphanumeric('a');
    bool alphanum5 = ASCII::IsAlphanumeric('d');
    bool alphanum6 = ASCII::IsAlphanumeric('z');

    ISHIKO_TEST_FAIL_IF_NOT(alphanum4);
    ISHIKO_TEST_FAIL_IF_NOT(alphanum5);
    ISHIKO_TEST_FAIL_IF_NOT(alphanum6);

    bool alphanum7 = ASCII::IsAlphanumeric('0');
    bool alphanum8 = ASCII::IsAlphanumeric('4');
    bool alphanum9 = ASCII::IsAlphanumeric('9');

    ISHIKO_TEST_FAIL_IF_NOT(alphanum7);
    ISHIKO_TEST_FAIL_IF_NOT(alphanum8);
    ISHIKO_TEST_FAIL_IF_NOT(alphanum9);

    ISHIKO_TEST_PASS();
}

void ASCIITests::IsAlphanumericTest2(Test& test)
{
    bool alphanum1 = ASCII::IsAlphanumeric(0);
    bool alphanum2 = ASCII::IsAlphanumeric('.');
    bool alphanum3 = ASCII::IsAlphanumeric('!');
    bool alphanum4 = ASCII::IsAlphanumeric(' ');

    ISHIKO_TEST_FAIL_IF(alphanum1);
    ISHIKO_TEST_FAIL_IF(alphanum2);
    ISHIKO_TEST_FAIL_IF(alphanum3);
    ISHIKO_TEST_FAIL_IF(alphanum4);

    ISHIKO_TEST_PASS();
}

void ASCIITests::IsWhitespaceTest1(Test& test)
{
    bool ws1 = ASCII::IsWhitespace(' ');
    bool ws2 = ASCII::IsWhitespace('\r');
    bool ws3 = ASCII::IsWhitespace('\n');
    bool ws4 = ASCII::IsWhitespace('\t');
    bool ws5 = ASCII::IsWhitespace('\v');

    ISHIKO_TEST_FAIL_IF_NOT(ws1);
    ISHIKO_TEST_FAIL_IF_NOT(ws2);
    ISHIKO_TEST_FAIL_IF_NOT(ws3);
    ISHIKO_TEST_FAIL_IF_NOT(ws4);
    ISHIKO_TEST_FAIL_IF_NOT(ws5);

    ISHIKO_TEST_PASS();
}

void ASCIITests::IsWhitespaceTest2(Test& test)
{
    bool ws1 = ASCII::IsWhitespace(0);
    bool ws2 = ASCII::IsWhitespace('a');
    bool ws3 = ASCII::IsWhitespace('.');

    ISHIKO_TEST_FAIL_IF(ws1);
    ISHIKO_TEST_FAIL_IF(ws2);
    ISHIKO_TEST_FAIL_IF(ws3);
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest1(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens.size(), 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest2(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest3(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("abc", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "abc" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest4(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one two", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest5(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one two three", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two", "three" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest6(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" ", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens.size(), 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest7(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("   ", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens.size(), 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest8(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a ", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest9(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a   ", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest10(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" a ", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest11(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" one  two   three ", ' ', true);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two", "three" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest12(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(",one", ',', false);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "", "one" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest13(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one,", ',', false);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::SplitTest14(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(",one,,two,,,three,", ',', false);

    ISHIKO_TEST_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "", "one", "", "two", "", "", "three", "" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest1(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("");

    ISHIKO_TEST_FAIL_IF_NEQ(lines.size(), 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest2(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest3(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a sentence");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a sentence" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest4(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\r\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest5(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest6(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\r\n\r\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "", "" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest7(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\n\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "", "" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest8(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a sentence\r\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a sentence" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest9(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a sentence\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a sentence" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest10(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\r\nanother line");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest11(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\nanother line");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest12(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\r\nanother line\r\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::GetLinesTest13(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\nanother line\n");

    ISHIKO_TEST_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHIKO_TEST_PASS();
}

void ASCIITests::ToLowerCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToLowerCase(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "hello world!");
    ISHIKO_TEST_PASS();
}

void ASCIITests::ToUpperCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToUpperCase(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "HELLO WORLD!");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest1(Test& test)
{
    std::string str = "";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest2(Test& test)
{
    std::string str = "a";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest3(Test& test)
{
    std::string str = "abc";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "abc");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest4(Test& test)
{
    std::string str = " ";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest5(Test& test)
{
    std::string str = "   ";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest6(Test& test)
{
    std::string str = " a";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest7(Test& test)
{
    std::string str = "   a";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest8(Test& test)
{
    std::string str = "a ";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest9(Test& test)
{
    std::string str = "a   ";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest10(Test& test)
{
    std::string str = " a ";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::TrimTest11(Test& test)
{
    std::string str = "  a   ";

    ASCII::Trim(str);

    ISHIKO_TEST_FAIL_IF_NEQ(str, "a");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemovePrefixTest1(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemovePrefix("ab", str);

    ISHIKO_TEST_FAIL_IF_NOT(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "cdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemovePrefixTest2(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemovePrefix("bcd", str);

    ISHIKO_TEST_FAIL_IF(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemovePrefixTest3(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemovePrefix("", str);

    ISHIKO_TEST_FAIL_IF_NOT(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemovePrefixTest4(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemovePrefix("abcdef", str);

    ISHIKO_TEST_FAIL_IF_NOT(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemovePrefixTest5(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemovePrefix("abcdefg", str);

    ISHIKO_TEST_FAIL_IF(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemoveSuffixTest1(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemoveSuffix("ef", str);

    ISHIKO_TEST_FAIL_IF_NOT(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcd");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemoveSuffixTest2(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemoveSuffix("cde", str);

    ISHIKO_TEST_FAIL_IF(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemoveSuffixTest3(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemoveSuffix("", str);

    ISHIKO_TEST_FAIL_IF_NOT(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemoveSuffixTest4(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemoveSuffix("abcdef", str);

    ISHIKO_TEST_FAIL_IF_NOT(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "");
    ISHIKO_TEST_PASS();
}

void ASCIITests::RemoveSuffixTest5(Test& test)
{
    std::string str = "abcdef";

    bool removed = ASCII::RemoveSuffix("abcdefg", str);

    ISHIKO_TEST_FAIL_IF(removed);
    ISHIKO_TEST_FAIL_IF_NEQ(str, "abcdef");
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertInt8Test1(Test& test)
{
    Error error;
    std::string number = "0";
    int8_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertInt8Test2(Test& test)
{
    Error error;
    std::string number = "127";
    int8_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 127);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertInt8Test3(Test& test)
{
    Error error;
    std::string number = "-128";
    int8_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, -128);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint8Test1(Test& test)
{
    Error error;
    std::string number = "0";
    uint8_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint8Test2(Test& test)
{
    Error error;
    std::string number = "255";
    uint8_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 255);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertInt16Test1(Test& test)
{
    Error error;
    std::string number = "0";
    int16_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertInt16Test2(Test& test)
{
    Error error;
    std::string number = "32767";
    int16_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 32767);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertInt16Test3(Test& test)
{
    Error error;
    std::string number = "-32768";
    int16_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, -32768);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint16Test1(Test& test)
{
    Error error;
    std::string number = "0";
    uint16_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint16Test2(Test& test)
{
    Error error;
    std::string number = "65535";
    uint16_t n = 0;
    ASCII::Convert(number.begin(), number.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 65535);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint64Test1(Test& test)
{
    std::string number = "0";
    boost::string_view numberView(number);
    uint64_t n = 0;
    ASCII::Convert(numberView.begin(), numberView.end(), n);

    ISHIKO_TEST_FAIL_IF_NEQ(n, 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint64Test2(Test& test)
{
    std::string number = "18446744073709551615";
    boost::string_view numberView(number);
    uint64_t n = 0;
    ASCII::Convert(numberView.begin(), numberView.end(), n);

    ISHIKO_TEST_FAIL_IF_NEQ(n, 18446744073709551615ull);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint64Test3(Test& test)
{
    Error error;
    std::string number = "0";
    boost::string_view numberView(number);
    uint64_t n = 0;
    ASCII::Convert(numberView.begin(), numberView.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 0);
    ISHIKO_TEST_PASS();
}

void ASCIITests::ConvertUint64Test4(Test& test)
{
    Error error;
    std::string number = "18446744073709551615";
    boost::string_view numberView(number);
    uint64_t n = 0;
    ASCII::Convert(numberView.begin(), numberView.end(), n, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(n, 18446744073709551615ull);
    ISHIKO_TEST_PASS();
}

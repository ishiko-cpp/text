/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCIITests.h"
#include "Ishiko/Text/ASCII.h"

using namespace Ishiko::Tests;
using namespace Ishiko::Text;

ASCIITests::ASCIITests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "ASCII tests", environment)
{
    append<HeapAllocationErrorsTest>("IsAlpha test 1", IsAlphaTest1);
    append<HeapAllocationErrorsTest>("IsAlpha test 2", IsAlphaTest2);
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
}

void ASCIITests::IsAlphaTest1(Test& test)
{
    bool alpha1 = ASCII::IsAlpha('a');
    bool alpha2 = ASCII::IsAlpha('d');
    bool alpha3 = ASCII::IsAlpha('z');

    ISHTF_FAIL_IF_NOT(alpha1);
    ISHTF_FAIL_IF_NOT(alpha2);
    ISHTF_FAIL_IF_NOT(alpha3);

    bool alpha4 = ASCII::IsAlpha('A');
    bool alpha5 = ASCII::IsAlpha('D');
    bool alpha6 = ASCII::IsAlpha('Z');

    ISHTF_FAIL_IF_NOT(alpha4);
    ISHTF_FAIL_IF_NOT(alpha5);
    ISHTF_FAIL_IF_NOT(alpha6);

    ISHTF_PASS();
}

void ASCIITests::IsAlphaTest2(Test& test)
{
    bool alpha1 = ASCII::IsAlpha(0);
    bool alpha2 = ASCII::IsAlpha('\r');
    bool alpha3 = ASCII::IsAlpha('!');
    bool alpha4 = ASCII::IsAlpha('.');

    ISHTF_FAIL_IF(alpha1);
    ISHTF_FAIL_IF(alpha2);
    ISHTF_FAIL_IF(alpha3);
    ISHTF_FAIL_IF(alpha4);

    ISHTF_PASS();
}

void ASCIITests::IsWhitespaceTest1(Test& test)
{
    bool ws1 = ASCII::IsWhitespace(' ');
    bool ws2 = ASCII::IsWhitespace('\r');
    bool ws3 = ASCII::IsWhitespace('\n');
    bool ws4 = ASCII::IsWhitespace('\t');
    bool ws5 = ASCII::IsWhitespace('\v');

    ISHTF_FAIL_IF_NOT(ws1);
    ISHTF_FAIL_IF_NOT(ws2);
    ISHTF_FAIL_IF_NOT(ws3);
    ISHTF_FAIL_IF_NOT(ws4);
    ISHTF_FAIL_IF_NOT(ws5);

    ISHTF_PASS();
}

void ASCIITests::IsWhitespaceTest2(Test& test)
{
    bool ws1 = ASCII::IsWhitespace(0);
    bool ws2 = ASCII::IsWhitespace('a');
    bool ws3 = ASCII::IsWhitespace('.');

    ISHTF_FAIL_IF(ws1);
    ISHTF_FAIL_IF(ws2);
    ISHTF_FAIL_IF(ws3);

    ISHTF_PASS();
}

void ASCIITests::SplitTest1(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("");

    ISHTF_FAIL_IF_NEQ(tokens.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::SplitTest2(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest3(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("abc");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "abc" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest4(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one two");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest5(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one two three");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two", "three" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest6(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" ");

    ISHTF_FAIL_IF_NEQ(tokens.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::SplitTest7(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("   ");

    ISHTF_FAIL_IF_NEQ(tokens.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::SplitTest8(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest9(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a   ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest10(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" a ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest11(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" one  two   three ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two", "three" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest1(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("");

    ISHTF_FAIL_IF_NEQ(lines.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest2(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest3(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a sentence");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a sentence" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest4(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\r\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest5(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest6(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\r\n\r\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "", "" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest7(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("\n\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "", "" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest8(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a sentence\r\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a sentence" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest9(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("a sentence\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "a sentence" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest10(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\r\nanother line");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest11(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\nanother line");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest12(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\r\nanother line\r\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHTF_PASS();
}

void ASCIITests::GetLinesTest13(Test& test)
{
    std::vector<std::string> lines = ASCII::GetLines("one line\nanother line\n");

    ISHTF_FAIL_IF_NEQ(lines, std::vector<std::string>({ "one line", "another line" }));
    ISHTF_PASS();
}

void ASCIITests::ToLowerCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToLowerCase(str);

    ISHTF_FAIL_IF_NEQ(str, "hello world!");
    ISHTF_PASS();
}

void ASCIITests::ToUpperCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToUpperCase(str);

    ISHTF_FAIL_IF_NEQ(str, "HELLO WORLD!");
    ISHTF_PASS();
}

void ASCIITests::TrimTest1(Test& test)
{
    std::string str = "";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "");
    ISHTF_PASS();
}

void ASCIITests::TrimTest2(Test& test)
{
    std::string str = "a";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest3(Test& test)
{
    std::string str = "abc";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "abc");
    ISHTF_PASS();
}

void ASCIITests::TrimTest4(Test& test)
{
    std::string str = " ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "");
    ISHTF_PASS();
}

void ASCIITests::TrimTest5(Test& test)
{
    std::string str = "   ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "");
    ISHTF_PASS();
}

void ASCIITests::TrimTest6(Test& test)
{
    std::string str = " a";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest7(Test& test)
{
    std::string str = "   a";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest8(Test& test)
{
    std::string str = "a ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest9(Test& test)
{
    std::string str = "a   ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest10(Test& test)
{
    std::string str = " a ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest11(Test& test)
{
    std::string str = "  a   ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

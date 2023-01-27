/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UTF8StringTests.hpp"
#include "Ishiko/Text/UTF8String.hpp"

using namespace Ishiko;

UTF8StringTests::UTF8StringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "UTF8String tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
    append<HeapAllocationErrorsTest>("Constructor test 3", ConstructorTest3);
    append<HeapAllocationErrorsTest>("Constructor test 4", ConstructorTest4);
    append<HeapAllocationErrorsTest>("Constructor test 5", ConstructorTest5);
    append<HeapAllocationErrorsTest>("ConstIterator test 1", ConstIteratorTest1);
    append<HeapAllocationErrorsTest>("ConstIterator test 2", ConstIteratorTest2);
    append<HeapAllocationErrorsTest>("ConstIterator test 3", ConstIteratorTest3);
    append<HeapAllocationErrorsTest>("ConstIterator test 4", ConstIteratorTest4);
    append<HeapAllocationErrorsTest>("ConstIterator test 5", ConstIteratorTest5);
    append<HeapAllocationErrorsTest>("substr test 1", SubstrTest1);
}

void UTF8StringTests::ConstructorTest1(Test& test)
{
    UTF8String str;

    ISHIKO_TEST_FAIL_IF_NEQ(str.size(), 0);
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstructorTest2(Test& test)
{
    UTF8String str{"ASCII string"};

    ISHIKO_TEST_FAIL_IF_NEQ(str.size(), 12);
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstructorTest3(Test& test)
{
    UTF8String str{"\xC2\xA3" "123.45"};

    ISHIKO_TEST_FAIL_IF_NEQ(str.size(), 7);
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstructorTest4(Test& test)
{
    UTF8String str{"\xE2\x82\xAC" "123.45"};

    ISHIKO_TEST_FAIL_IF_NEQ(str.size(), 7);
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstructorTest5(Test& test)
{
    UTF8String str{"\xF0\x90\x8D\x88" "123.45"};

    ISHIKO_TEST_FAIL_IF_NEQ(str.size(), 7);
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstIteratorTest1(Test& test)
{
    UTF8String str;

    ISHIKO_TEST_FAIL_IF_NEQ(str.cbegin(), str.cend());
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstIteratorTest2(Test& test)
{
    UTF8String str{"a"};

    UTF8String::ConstIterator it = str.cbegin();

    ISHIKO_TEST_FAIL_IF_NEQ(*it, 'a');
    ISHIKO_TEST_FAIL_IF_NEQ(++it, str.cend());
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstIteratorTest3(Test& test)
{
    UTF8String str{"\xC2\xA3" "123.45"};

    UTF8String::ConstIterator it = str.cbegin();

    ISHIKO_TEST_FAIL_IF_NEQ(*it, 0xA3);
    ISHIKO_TEST_FAIL_IF(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '1');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '2');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '3');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '.');
    ISHIKO_TEST_FAIL_IF(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '4');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '5');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(++it, str.cend());
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstIteratorTest4(Test& test)
{
    UTF8String str{"\xE2\x82\xAC" "123.45"};

    UTF8String::ConstIterator it = str.cbegin();

    ISHIKO_TEST_FAIL_IF_NEQ(*it, 0x20AC);
    ISHIKO_TEST_FAIL_IF(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '1');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '2');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '3');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '.');
    ISHIKO_TEST_FAIL_IF(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '4');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '5');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(++it, str.cend());
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::ConstIteratorTest5(Test& test)
{
    UTF8String str{"\xF0\x90\x8D\x88" "123.45"};

    UTF8String::ConstIterator it = str.cbegin();

    ISHIKO_TEST_FAIL_IF_NEQ(*it, 0x10348);
    ISHIKO_TEST_FAIL_IF(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '1');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '2');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '3');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '.');
    ISHIKO_TEST_FAIL_IF(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '4');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(*(++it), '5');
    ISHIKO_TEST_FAIL_IF_NOT(it->isASCIIDigit());
    ISHIKO_TEST_FAIL_IF_NEQ(++it, str.cend());
    ISHIKO_TEST_PASS();
}

void UTF8StringTests::SubstrTest1(Test& test)
{
    UTF8String str{"ASCII string"};

    UTF8String substr = str.substr(str.cbegin(), str.cbegin() + 5);

    ISHIKO_TEST_FAIL_IF_NEQ(substr, "ASCII");
    ISHIKO_TEST_PASS();
}

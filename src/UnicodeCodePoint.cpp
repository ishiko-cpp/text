/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UnicodeCodePoint.hpp"

using namespace Ishiko;

UnicodeCodePoint::UnicodeCodePoint(uint32_t value)
    : m_value{value}
{
}

bool UnicodeCodePoint::isASCIIDigit() const
{
    return ((0x30 <= m_value) && (m_value <= 0x39));
}

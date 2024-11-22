// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "UnicodeCodePoint.hpp"

using namespace Ishiko;

UnicodeCodePoint::UnicodeCodePoint()
    : m_value{0}
{
}

UnicodeCodePoint::UnicodeCodePoint(uint32_t value)
    : m_value{value}
{
}

UnicodeCodePoint& UnicodeCodePoint::operator=(UnicodeCodePoint code_point)
{
    m_value = code_point.m_value;
    return *this;
}

bool UnicodeCodePoint::isASCIIDigit() const
{
    return ((0x30 <= m_value) && (m_value <= 0x39));
}

bool UnicodeCodePoint::operator==(UnicodeCodePoint code_point) const
{
    return (m_value == code_point.m_value);
}

bool UnicodeCodePoint::operator!=(UnicodeCodePoint code_point) const
{
    return (m_value != code_point.m_value);
}

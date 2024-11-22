// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "UTF8Char.hpp"

using namespace Ishiko;

UTF8Char::UTF8Char()
{
}

UTF8Char::UTF8Char(UnicodeCodePoint code_point)
    : UnicodeCodePoint(code_point)
{
}

UTF8Char& UTF8Char::operator=(UnicodeCodePoint code_point)
{
    UnicodeCodePoint::operator=(code_point);
    return *this;
}

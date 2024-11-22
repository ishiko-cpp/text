// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TEXT_UTF8CHAR_HPP
#define GUARD_ISHIKO_CPP_TEXT_UTF8CHAR_HPP

#include "UnicodeCodePoint.hpp"

namespace Ishiko
{
    class UTF8Char : public UnicodeCodePoint
    {
    public:
        UTF8Char();
        UTF8Char(UnicodeCodePoint code_point);

        UTF8Char& operator=(UnicodeCodePoint code_point);
    };
}

#endif

/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TEXT_UTF8CHAR_HPP
#define GUARD_ISHIKO_CPP_TEXT_UTF8CHAR_HPP

#include "UnicodeCodePoint.hpp"

namespace Ishiko
{
    class UTF8Char : public UnicodeCodePoint
    {
    public:
        UTF8Char(UnicodeCodePoint code_point);
    };
}

#endif

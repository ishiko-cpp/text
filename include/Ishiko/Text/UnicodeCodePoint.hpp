/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TEXT_UNICODECODEPOINT_HPP
#define GUARD_ISHIKO_CPP_TEXT_UNICODECODEPOINT_HPP

#include <cstdint>

namespace Ishiko
{
    class UnicodeCodePoint
    {
    public:
        UnicodeCodePoint();
        UnicodeCodePoint(uint32_t value);

        UnicodeCodePoint& operator=(UnicodeCodePoint code_point);

        bool isASCIIDigit() const;

        bool operator==(UnicodeCodePoint code_point) const;
        bool operator!=(UnicodeCodePoint code_point) const;

    private:
        uint32_t m_value;
    };
}

#endif

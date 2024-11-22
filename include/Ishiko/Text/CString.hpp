// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TEXT_CSTRING_HPP
#define GUARD_ISHIKO_CPP_TEXT_CSTRING_HPP

#include <string>

namespace Ishiko
{
    class CString
    {
    public:
        static char* Duplicate(const char* str);
        static std::string Substring(const char* str, size_t begin);
        static std::string Substring(const char* str, size_t begin, size_t end);
        static size_t Find(const char* str, const char* substring);
        static bool StartsWith(const char* str, const char* prefix);
        static bool EndsWith(const char* str, const char* suffix);
    };
}

#endif

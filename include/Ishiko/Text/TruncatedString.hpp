// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TEXT_TRUNCATEDSTRING_HPP
#define GUARD_ISHIKO_CPP_TEXT_TRUNCATEDSTRING_HPP

#include <string>

namespace Ishiko
{

class TruncatedString
{
public:
    TruncatedString(size_t maxSize);
    TruncatedString(const std::string& str, size_t maxSize);

    size_t size() const noexcept;
    size_t maxSize() const noexcept;
    bool isTruncated() const noexcept;

    void append(const std::string& str);

    const std::string& asString() const noexcept;

private:
    std::string m_string;
    size_t m_maxSize;
    std::string m_ellipsis;
    bool m_hasEllipsis;
};

}

#endif

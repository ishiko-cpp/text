/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_TRUNCATEDSTRING_HPP_
#define _ISHIKO_CPP_TEXT_TRUNCATEDSTRING_HPP_

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

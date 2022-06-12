/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "TruncatedString.hpp"

using namespace Ishiko;

// TODO: truncation should take into account UTF-8

TruncatedString::TruncatedString(size_t maxSize)
    : m_maxSize(maxSize), m_ellipsis("...")
{
}

TruncatedString::TruncatedString(const std::string& str, size_t maxSize)
    : m_maxSize(maxSize), m_ellipsis("...")
{
    // TODO: error if ellipsis > maxSize
    if (str.size() <= m_maxSize)
    {
        m_string = str;
    }
    else
    {
        m_string.reserve(m_maxSize);
        m_string.append(str.substr(0, (m_maxSize - m_ellipsis.size())));
        m_string.append(m_ellipsis);
    }
}

size_t TruncatedString::size() const noexcept
{
    return m_string.size();
}

size_t TruncatedString::maxSize() const noexcept
{
    return m_maxSize;
}

const std::string& TruncatedString::asString() const noexcept
{
    return m_string;
}

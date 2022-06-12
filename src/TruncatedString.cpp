/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "TruncatedString.hpp"

using namespace Ishiko;

// TODO: truncation should take into account UTF-8

TruncatedString::TruncatedString(size_t maxSize)
    : m_maxSize(maxSize), m_ellipsis("..."), m_hasEllipsis(false)
{
}

TruncatedString::TruncatedString(const std::string& str, size_t maxSize)
    : m_maxSize(maxSize), m_ellipsis("...")
{
    // TODO: error if ellipsis > maxSize
    if (str.size() <= m_maxSize)
    {
        m_string = str;
        m_hasEllipsis = false;
    }
    else
    {
        m_string.reserve(m_maxSize);
        m_string.append(str.substr(0, (m_maxSize - m_ellipsis.size())));
        m_string.append(m_ellipsis);
        m_hasEllipsis = true;
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

bool TruncatedString::isTruncated() const noexcept
{
    return m_hasEllipsis;
}

void TruncatedString::append(const std::string& str)
{
    if (m_hasEllipsis)
    {
        // The current contents already exceed the maximum. We could reclaim some space from the ellipsis but that
        // should be a user decision.
        return;
    }
    
    if ((m_string.size() + str.size()) <= m_maxSize)
    {
        m_string.append(str);
    }
    else
    {
        size_t remainingSize = (m_maxSize - m_string.size());
        if (remainingSize <= m_ellipsis.size())
        {
            // We can end up in a situation where we can truncate the original contents because we now need some of its
            // for the ellipsis
            size_t eraseCount = (m_ellipsis.size() - remainingSize);
            m_string.replace((m_string.end() - eraseCount), m_string.end(), m_ellipsis);
        }
        else
        {
            m_string.append(str.substr(0, (remainingSize - m_ellipsis.size())));
            m_string.append(m_ellipsis);
        }
        m_hasEllipsis = true;
    }
}

const std::string& TruncatedString::asString() const noexcept
{
    return m_string;
}

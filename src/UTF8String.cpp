/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UTF8String.hpp"

using namespace Ishiko;

UTF8String::ConstIterator::ConstIterator(std::string::const_iterator it)
    : m_it{it}
{
}

UTF8Char UTF8String::ConstIterator::operator*() const
{
    char c = *m_it;
    if ((c & 0x80) == 0)
    {
        m_item = *m_it;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        m_item = ((c & 0x1F) << 6) + (*(m_it + 1) & 0x3F);
    }
    else if ((c & 0xF0) == 0xE0)
    {
        m_item = ((c & 0x1F) << 12) + ((*(m_it + 1) & 0x3F) << 6) + (*(m_it + 2) & 0x3F);
    }
    else if ((c & 0xF8) == 0xF0)
    {
        m_item =
            ((c & 0x07) << 18) + ((*(m_it + 1) & 0x3F) << 12) + ((*(m_it + 2) & 0x3F) << 6) + (*(m_it + 3) & 0x3F);
    }
    return m_item;
}

const UTF8Char* UTF8String::ConstIterator::operator->() const
{
    char c = *m_it;
    if ((c & 0x80) == 0)
    {
        m_item = *m_it;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        m_item = ((c & 0x1F) << 6) + (*(m_it + 1) & 0x3F);
    }
    else if ((c & 0xF0) == 0xE0)
    {
        m_item = ((c & 0x1F) << 12) + ((*(m_it + 1) & 0x3F) << 6) + (*(m_it + 2) & 0x3F);
    }
    else if ((c & 0xF8) == 0xF0)
    {
        m_item =
            ((c & 0x07) << 18) + ((*(m_it + 1) & 0x3F) << 12) + ((*(m_it + 2) & 0x3F) << 6) + (*(m_it + 3) & 0x3F);
    }
    return &m_item;
}

UTF8String::ConstIterator& UTF8String::ConstIterator::operator++()
{
    char c = *m_it;
    if ((c & 0x80) == 0)
    {
        ++m_it;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        m_it += 2;
    }
    else if ((c & 0xF0) == 0xE0)
    {
        m_it += 3;
    }
    else if ((c & 0xF8) == 0xF0)
    {
        m_it += 4;
    }
    return *this;
}

UTF8String::ConstIterator UTF8String::ConstIterator::operator+(size_t n) const
{
    ConstIterator result{*this};
    while (n != 0)
    {
        ++result;
        --n;
    }
    return result;
}

bool UTF8String::ConstIterator::operator!=(const ConstIterator& other) const
{
    return (m_it != other.m_it);
}

UTF8String::UTF8String()
    : m_size{0}
{
}

UTF8String::UTF8String(const char* str)
    : UTF8String(std::string(str))
{
}

UTF8String::UTF8String(std::string str)
    : m_data{std::move(str)}, m_size{0}
{
    // TODO: verify there are no unterminated characters
    for (char c : m_data)
    {
        if ((c & 0x80) == 0)
        {
            ++m_size;
        }
        else if ((c & 0xE0) == 0xC0)
        {
            ++m_size;
        }
        else if ((c & 0xF0) == 0xE0)
        {
            ++m_size;
        }
        else if ((c & 0xF8) == 0xF0)
        {
            ++m_size;
        }
    }
}

size_t UTF8String::size() const
{
    return m_size;
}

UTF8String::ConstIterator UTF8String::cbegin() const
{
    return ConstIterator(m_data.cbegin());
}

UTF8String::ConstIterator UTF8String::cend() const
{
    return ConstIterator(m_data.cend());
}

bool UTF8String::operator!=(const UTF8String& other) const
{
    return (m_data != other.m_data);
}

UTF8String UTF8String::substr(ConstIterator begin, ConstIterator end) const
{
    UTF8String result;
    result.m_data = std::string(begin.m_it, end.m_it);
    return result;
}

std::string UTF8String::toString() const
{
    return m_data;
}

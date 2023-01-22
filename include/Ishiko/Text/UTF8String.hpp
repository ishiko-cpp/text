/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TEXT_UTF8STRING_HPP
#define GUARD_ISHIKO_CPP_TEXT_UTF8STRING_HPP

#include "UTF8Char.hpp"
#include <iterator>
#include <string>

namespace Ishiko
{
    class UTF8String
    {
    public:
        struct ConstIterator
        {
            friend class UTF8String;

        public:
            ConstIterator(std::string::const_iterator it);

            UTF8Char operator*() const;
            const UTF8Char* operator->() const;

            ConstIterator& operator++();
            ConstIterator operator+(size_t n) const;

            bool operator!=(const ConstIterator& other) const;

        private:
            std::string::const_iterator m_it;
            mutable UTF8Char m_item;
        };

        UTF8String();
        UTF8String(const char* str);
        UTF8String(std::string str);

        size_t size() const;

        ConstIterator cbegin() const;
        ConstIterator cend() const;

        bool operator!=(const UTF8String& other) const;

        UTF8String substr(ConstIterator begin, ConstIterator end) const;

    private:
        size_t m_size;
        std::string m_data;
    };
}

#endif

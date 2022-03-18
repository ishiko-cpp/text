/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCII.hpp"
#include "ErrorCategory.hpp"

using namespace std;

namespace Ishiko
{

bool ASCII::IsAlpha(char c)
{
    return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

bool ASCII::IsNumeric(char c)
{
    return ((c >= '0') && (c <= '9'));
}

bool ASCII::IsAlphanumeric(char c)
{
    return (IsAlpha(c) || IsNumeric(c));
}

bool ASCII::IsWhitespace(char c)
{
    return ((c == ' ') || (c == '\r') || (c == '\n') || (c == '\t') || (c == '\v'));
}

vector<string> ASCII::GetLines(const std::string& str)
{
    vector<string> result;

    string::const_iterator it = str.begin();
    string::const_iterator end = str.end();
    string::const_iterator previousIt = it;
    while (it != end)
    {
        if ((*it != '\r') && (*it != '\n'))
        {
            ++it;
        }
        else
        {
            result.emplace_back(previousIt, it);
            if (*it == '\r')
            {
                ++it;
                if ((it != end) && (*it == '\n'))
                {
                    ++it;
                }
            }
            else
            {
                // TODO: do I need a variant where I keep the separator?
                //result.emplace_back(1, *it);
                ++it;
            }
            previousIt = it;
        }
    }
    if (previousIt != it)
    {
        result.emplace_back(previousIt, it);
    }

    return result;
}

vector<string> ASCII::Split(const std::string& str, char separator, bool conflateAdjacentSeparators)
{
    vector<string> result;

    string::const_iterator it = str.begin();
    string::const_iterator end = str.end();
    string::const_iterator previousIt = it;
    while (it != end)
    {
        if (*it != separator)
        {
            ++it;
        }
        else
        {
            if (!conflateAdjacentSeparators || (previousIt != it))
            {
                result.emplace_back(previousIt, it);
            }
            // TODO: do I need a variant where I keep the separator?
            //result.emplace_back(1, *it);
            ++it;
            previousIt = it;
        }
    }
    if (!conflateAdjacentSeparators || (previousIt != it))
    {
        result.emplace_back(previousIt, it);
    }
    
    return result;
}

void ASCII::ToLowerCase(string& str)
{
    for (char& c : str)
    {
        if ((c >= 'A') && (c <= 'Z'))
        {
            c = 'a' + c - 'A';
        }
    }
}

void ASCII::ToUpperCase(string& str)
{
    for (char& c : str)
    {
        if ((c >= 'a') && (c <= 'z'))
        {
            c = 'A' + c - 'a';
        }
    }
}

void ASCII::Trim(string& str)
{
    if (!str.empty())
    {
        string::const_iterator begin = str.begin();
        string::const_iterator it = str.begin();
        string::const_iterator end = str.end();
        while ((it != end) && (*it == ' '))
        {
            ++it;
        }
        string::const_iterator startIt = it;
        it = end;
        while ((it != startIt) && (*(it - 1) == ' '))
        {
            --it;
        }
        str.erase(it, end);
        str.erase(begin, startIt);
    }
}

void ASCII::Convert(string::const_iterator begin, string::const_iterator end, char& c, Error& error)
{
    if (begin == end)
    {
        // TODO: better error
        Fail(error, TextErrorCategory::Value::generic);
        return;
    }

    bool negative = false;
    if (*begin == '+')
    {
        ++begin;
        if (begin == end)
        {
            // TODO: better error
            Fail(error, TextErrorCategory::Value::generic);
            return;
        }
    }
    else if (*begin == '-')
    {
        negative = true;
        ++begin;
        if (begin == end)
        {
            // TODO: better error
            Fail(error, TextErrorCategory::Value::generic);
            return;
        }
    }
    int result = 0;
    while ((begin != end) && (result < 128))
    {
        char c = *begin;
        if (!IsNumeric(c))
        {
            // TODO: better error
            Fail(error, TextErrorCategory::Value::generic);
            return;
        }
        result = ((10 * result) + (c - '0'));
        ++begin;
    }
    if (negative)
    {
        result = -result;
    }
    if ((result <= -129) || (result >= 128))
    {
        // TODO: better error
        Fail(error, TextErrorCategory::Value::generic);
        return;
    }
    c = static_cast<unsigned char>(result);
}

void ASCII::Convert(string::const_iterator begin, string::const_iterator end, unsigned char& c, Error& error)
{
    if (begin == end)
    {
        // TODO: better error
        Fail(error, TextErrorCategory::Value::generic);
        return;
    }

    if (*begin == '+')
    {
        ++begin;
        if (begin == end)
        {
            // TODO: better error
            Fail(error, TextErrorCategory::Value::generic);
            return;
        }
    }
    else if (*begin == '-')
    {
        // TODO: better error
        Fail(error, TextErrorCategory::Value::generic);
        return;
    }
    unsigned int result = 0;
    while ((begin != end) && (result < 256))
    {
        char c = *begin;
        if (!IsNumeric(c))
        {
            // TODO: better error
            Fail(error, TextErrorCategory::Value::generic);
            return;
        }
        result = ((10 * result) + (c - '0'));
        ++begin;
    }
    if (result >= 256)
    {
        // TODO: better error
        Fail(error, TextErrorCategory::Value::generic);
        return;
    }
    c = static_cast<unsigned char>(result);
}

}

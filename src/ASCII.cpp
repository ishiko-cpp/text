/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCII.hpp"

using namespace std;

namespace Ishiko
{
namespace Text
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

}
}

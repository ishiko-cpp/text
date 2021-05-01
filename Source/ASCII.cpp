/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#include "ASCII.h"

namespace Ishiko
{
namespace Text
{

std::vector<std::string> ASCII::GetLines(const std::string& str)
{
    std::vector<std::string> result;

    std::string::const_iterator it = str.begin();
    std::string::const_iterator end = str.end();
    std::string::const_iterator previousIt = it;
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

std::vector<std::string> ASCII::Split(const std::string& str)
{
    std::vector<std::string> result;

    std::string::const_iterator it = str.begin();
    std::string::const_iterator end = str.end();
    std::string::const_iterator previousIt = it;
    while (it != end)
    {
        if (*it != ' ')
        {
            ++it;
        }
        else
        {
            if (previousIt != it)
            {
                result.emplace_back(previousIt, it);
            }
            // TODO: do I need a variant where I keep the separator?
            //result.emplace_back(1, *it);
            ++it;
            previousIt = it;
        }
    }
    if (previousIt != it)
    {
        result.emplace_back(previousIt, it);
    }
    
    return result;
}

void ASCII::ToLowerCase(std::string& str)
{
    for (char& c : str)
    {
        if ((c >= 'A') && (c <= 'Z'))
        {
            c = 'a' + c - 'A';
        }
    }
}

void ASCII::ToUpperCase(std::string& str)
{
    for (char& c : str)
    {
        if ((c >= 'a') && (c <= 'z'))
        {
            c = 'A' + c - 'a';
        }
    }
}

void ASCII::Trim(std::string& str)
{
    if (!str.empty())
    {
        std::string::const_iterator begin = str.begin();
        std::string::const_iterator it = str.begin();
        std::string::const_iterator end = str.end();
        while ((it != end) && (*it == ' '))
        {
            ++it;
        }
        std::string::const_iterator startIt = it;
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

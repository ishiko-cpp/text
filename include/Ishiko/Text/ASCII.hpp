/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_ASCII_HPP_
#define _ISHIKO_CPP_TEXT_ASCII_HPP_

#include <Ishiko/Errors.hpp>
#include <Ishiko/Memory.hpp>
#include <boost/utility/string_view.hpp>
#include <ios>
#include <string>
#include <vector>

namespace Ishiko
{

class ASCII
{
public:
    static const char* LineEnding;

    static bool IsAlpha(char c) noexcept;
    static bool IsNumeric(char c) noexcept;
    static bool IsAlphanumeric(char c) noexcept;
    static bool IsHexDigit(char c) noexcept;
    static bool IsWhitespace(char c) noexcept;

    static std::vector<std::string> GetLines(const std::string& str);
    static std::vector<std::string> Split(const std::string& str, char separator, bool conflateAdjacentSeparators);
    static void ToLowerCase(std::string& str);
    static void ToUpperCase(std::string& str);
    // TODO: at the moment this only trims spaces and not other whitespace characters,
    // allow to pass list of characters that can be trimmed, also allow to trim front or back
    static void Trim(std::string& str);
    // TODO: this removes the prefix if it matches the start of the string, does nothing otherwise. Returns true if
    // prefix was found and removed.
    static bool RemovePrefix(const std::string& prefix, std::string& str) noexcept;
    static bool RemoveSuffix(const std::string& suffix, std::string& str) noexcept;

    // TODO: should have uppercase and lowercase options, always lower case for now
    static std::string ToHexString(Byte byte);
    static std::string ToHexString(uint16_t number);
    static std::string ToHexString(const Byte* bytes, size_t count);

    // TODO: all these conversion functions assume base 10
    static void Convert(const std::string& str, int8_t& number, Error& error) noexcept;
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, int8_t& number,
        Error& error) noexcept;
    static void Convert(const std::string& str, uint8_t& number, Error& error) noexcept;
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, uint8_t& number,
        Error& error) noexcept;
    static void Convert(const std::string& str, int16_t& number, Error& error) noexcept;
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, int16_t& number,
        Error& error) noexcept;
    static void Convert(const std::string& str, std::ios_base::fmtflags base, uint16_t& number, Error& error) noexcept;
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end,
        std::ios_base::fmtflags base, uint16_t& number, Error& error) noexcept;
    static void Convert(const std::string& str, uint64_t& number);
    static void Convert(const std::string& str, uint64_t& number, Error& error) noexcept;
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, uint64_t& number);
    static void Convert(std::string::const_iterator begin, std::string::const_iterator end, uint64_t& number,
        Error& error) noexcept;
    static void Convert(boost::string_view::const_iterator begin, boost::string_view::const_iterator end,
        uint64_t& number);
    static void Convert(boost::string_view::const_iterator begin, boost::string_view::const_iterator end,
        uint64_t& number, Error& error) noexcept;
};

}

#endif

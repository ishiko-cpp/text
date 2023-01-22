/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "UTF8Char.hpp"

using namespace Ishiko;

UTF8Char::UTF8Char(UnicodeCodePoint code_point)
    : UnicodeCodePoint(code_point)
{
}

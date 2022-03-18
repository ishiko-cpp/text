/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "TextErrorCategory.hpp"

namespace Ishiko
{

const TextErrorCategory& TextErrorCategory::Get() noexcept
{
    static TextErrorCategory theCategory;
    return theCategory;
}

const char* ErrorCategory::name() const noexcept
{
    return "Ishiko::TextErrorCategory";
}

void Fail(Error& error, TextErrorCategory::Value value) noexcept
{
    error.fail(static_cast<int>(value), TextErrorCategory::Get());
}

}

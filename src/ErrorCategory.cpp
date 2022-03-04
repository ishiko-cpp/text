/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ErrorCategory.hpp"

namespace Ishiko
{
namespace Text
{

const ErrorCategory& ErrorCategory::Get() noexcept
{
    static ErrorCategory theCategory;
    return theCategory;
}

const char* ErrorCategory::name() const noexcept
{
    return "Ishiko::Text::ErrorCategory";
}

void Fail(Error& error, ErrorCategory::Value value) noexcept
{
    error.fail(static_cast<int>(value), ErrorCategory::Get());
}

}
}

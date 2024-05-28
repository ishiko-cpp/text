/*
    Copyright (c) 2022-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "TextErrorCategory.hpp"

using namespace Ishiko;

const TextErrorCategory& TextErrorCategory::Get() noexcept
{
    static TextErrorCategory theCategory;
    return theCategory;
}

const char* TextErrorCategory::name() const noexcept
{
    return "Ishiko::TextErrorCategory";
}

const char* TextErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic:
        return "generic error";

    default:
        return "unknown value";
    }
}

void Ishiko::Throw(TextErrorCategory::Value value, const char* file, int line)
{
    throw Exception(static_cast<int>(value), TextErrorCategory::Get(), file, line);
}

void Ishiko::Fail(TextErrorCategory::Value value, Error& error) noexcept
{
    error.fail(TextErrorCategory::Get(), static_cast<int>(value));
}

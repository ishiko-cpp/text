/*
    Copyright (c) 2022-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TEXT_TEXTERRORCATEGORY_HPP
#define GUARD_ISHIKO_CPP_TEXT_TEXTERRORCATEGORY_HPP

#include <Ishiko/Errors.hpp>

namespace Ishiko
{

class TextErrorCategory : public ErrorCategory
{
public:
    enum class Value
    {
        generic = -1
    };

    static const TextErrorCategory& Get() noexcept;

    const char* name() const noexcept override;
    const char* message(int ev, char* buffer, size_t len) const noexcept override;

private:
    TextErrorCategory() noexcept = default;
};

void Throw(TextErrorCategory::Value value, const char* file, int line);
void Fail(TextErrorCategory::Value value, Error& error) noexcept;

}

#endif

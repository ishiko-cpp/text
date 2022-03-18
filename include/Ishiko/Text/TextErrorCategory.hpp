/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_TEXTERRORCATEGORY_HPP_
#define _ISHIKO_CPP_TEXT_TEXTERRORCATEGORY_HPP_

#include <Ishiko/Errors.hpp>

namespace Ishiko
{

class TextErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum class Value
    {
        generic = -1
    };

    static const TextErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    TextErrorCategory() noexcept = default;
};

void Fail(Error& error, TextErrorCategory::Value value) noexcept;

}

#endif

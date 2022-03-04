/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TEXT_ERRORCATEGORY_HPP_
#define _ISHIKO_CPP_TEXT_ERRORCATEGORY_HPP_

#include <Ishiko/Errors.hpp>

namespace Ishiko
{
namespace Text
{

class ErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum class Value
    {
        generic = -1
    };

    static const ErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    ErrorCategory() noexcept = default;
};

void Fail(Error& error, ErrorCategory::Value value) noexcept;

}
}

#endif

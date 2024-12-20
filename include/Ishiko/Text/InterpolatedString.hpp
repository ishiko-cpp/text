// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TEXT_INTERPOLATEDSTRING_HPP
#define GUARD_ISHIKO_CPP_TEXT_INTERPOLATEDSTRING_HPP

#include <boost/utility/string_view.hpp>
#include <Ishiko/Errors.hpp>
#include <map>
#include <string>

namespace Ishiko
{
    // TODO: these strings follow the bash syntax, do I need to support other types?
    class InterpolatedString
    {
    public:
        class Callbacks
        {
        public:
            virtual ~Callbacks() = default;

            // TODO: it is up to the callback to decide whether to return an error when a variable is not found or not.
            virtual void expand(boost::string_view variable, std::string& result, Error& error) const = 0;
        };

        class MapCallbacks : public Callbacks
        {
        public:
            MapCallbacks(const std::map<std::string, std::string>& map, bool allowMissing);

            void expand(boost::string_view variable, std::string& result, Error& error) const override;

        private:
            const std::map<std::string, std::string>& m_map;
            bool m_allowMissing;
        };

        InterpolatedString();
        InterpolatedString(const char* str);
        InterpolatedString(std::string str);

        std::string expand(const Callbacks& callbacks) const;
        std::string expand(const Callbacks& callbacks, Error& error) const;

    private:
        std::string m_string;
    };
}

#endif

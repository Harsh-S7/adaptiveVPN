#pragma once

#include <string>
#include <string_view>

#include "../escape_sequence.hpp"
#include "../export_command/export_command.hpp"
#include "../type_check.hpp"
#include "../utility.hpp"

namespace cpp_dump
{

    namespace _detail
    {

        inline std::string export_string(std::string_view value,
                                         const std::string&,
                                         std::size_t,
                                         std::size_t,
                                         bool fail_on_newline,
                                         const export_command&)
        {
            if (has_newline(value))
            {
                if (fail_on_newline)
                    return "\n";

                return "\n" + es::character(std::string(1, '`').append(value))
                    + es::character(R"(`)");
            }

            if (value.find(R"(")") == std::string::npos)
                return es::character(std::string(1, '"').append(value))
                    + es::character(R"(")");

            return es::character(std::string(1, '`').append(value))
                + es::character(R"(`)");
        }

    }  // namespace _detail

}  // namespace cpp_dump

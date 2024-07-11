#pragma once

#include <string>

#include "../export_command/export_command.hpp"

namespace cpp_dump
{

    namespace _detail
    {

        template<typename T>
        std::string export_var(const T&,
                               const std::string&,
                               std::size_t,
                               std::size_t,
                               bool,
                               const export_command&);

    }  // namespace _detail

}  // namespace cpp_dump

#pragma once

#include <string>
#include <type_traits>
#include <typeinfo>

#if defined(__GNUC__)
#    include <cxxabi.h>
#endif

#include "../../export_command/export_command.hpp"
#include "../export_object_common.hpp"

namespace cpp_dump
{

    namespace _detail
    {

        template<typename T>
        inline auto export_type_info(const T& type_info,
                                     const std::string& indent,
                                     std::size_t last_line_length,
                                     std::size_t current_depth,
                                     bool fail_on_newline,
                                     const export_command&)
            -> std::enable_if_t<is_type_info<T>, std::string>
        {
            std::string type_name = es::identifier("std") + es::op("::")
                + es::identifier(std::is_same_v<T, std::type_info> ? "type_info"
                                                                   : "type_index");

#if defined(__GNUC__)
            int status       = 0;
            std::string name = abi::__cxa_demangle(type_info.name(), 0, 0, &status);
#else
            std::string name = type_info.name();
#endif

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON1_1;
            [[maybe_unused]] auto _dummy_1 = next_depth;
            [[maybe_unused]] auto _dummy_2 = is_first = false;

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON1_3;

            if (shift_indent)
                output += "\n" + new_indent;

            output += es::member("name") + es::op("()= ");
            output +=
                es::identifier(R"(")") + es::class_name(name) + es::identifier(R"(")");

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON2;
        }

    }  // namespace _detail

}  // namespace cpp_dump

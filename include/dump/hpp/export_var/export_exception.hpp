#pragma once

#include <string>
#include <type_traits>

#include "../escape_sequence.hpp"
#include "../export_command/export_command.hpp"
#include "../type_check.hpp"
#include "./export_object_common.hpp"

namespace cpp_dump
{

    namespace _detail
    {

        template<typename T>
        inline auto export_exception(const T& exception,
                                     const std::string& indent,
                                     std::size_t last_line_length,
                                     std::size_t current_depth,
                                     bool fail_on_newline,
                                     const export_command& command)
            -> std::enable_if_t<is_exception<T>, std::string>
        {
            std::string type_name = es::class_name(get_typename<T>());

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON1;

            append_output(es::member("what") + es::op("()"), exception.what());

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON2;
        }

    }  // namespace _detail

}  // namespace cpp_dump

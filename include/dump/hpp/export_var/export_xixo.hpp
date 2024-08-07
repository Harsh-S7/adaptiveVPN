#pragma once

#include <queue>
#include <stack>
#include <string>

#include "../escape_sequence.hpp"
#include "../export_command/export_command.hpp"
#include "./export_object_common.hpp"

namespace cpp_dump
{

    namespace _detail
    {

        template<typename... Args>
        inline std::string export_xixo(const std::queue<Args...>& queue,
                                       const std::string& indent,
                                       std::size_t last_line_length,
                                       std::size_t current_depth,
                                       bool fail_on_newline,
                                       const export_command& command)
        {
            std::string type_name =
                es::identifier("std") + es::op("::") + es::identifier("queue");

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON1;

            if (!queue.empty())
            {
                append_output(es::member("front") + es::op("()"), queue.front());
                if (queue.size() >= 2)
                    append_output(es::member("back") + es::op("()"), queue.back());
            }
            append_output(es::member("size") + es::op("()"), queue.size());

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON2;
        }

        template<typename... Args>
        inline std::string export_xixo(const std::priority_queue<Args...>& pq,
                                       const std::string& indent,
                                       std::size_t last_line_length,
                                       std::size_t current_depth,
                                       bool fail_on_newline,
                                       const export_command& command)
        {
            std::string type_name =
                es::identifier("std") + es::op("::") + es::identifier("priority_queue");

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON1;

            if (!pq.empty())
                append_output(es::member("top") + es::op("()"), pq.top());
            append_output(es::member("size") + es::op("()"), pq.size());

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON2;
        }

        template<typename... Args>
        inline std::string export_xixo(const std::stack<Args...>& stack,
                                       const std::string& indent,
                                       std::size_t last_line_length,
                                       std::size_t current_depth,
                                       bool fail_on_newline,
                                       const export_command& command)
        {
            std::string type_name =
                es::identifier("std") + es::op("::") + es::identifier("stack");

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON1;

            if (!stack.empty())
                append_output(es::member("top") + es::op("()"), stack.top());
            append_output(es::member("size") + es::op("()"), stack.size());

            _p_CPP_DUMP_DEFINE_EXPORT_OBJECT_COMMON2;
        }

    }  // namespace _detail

}  // namespace cpp_dump

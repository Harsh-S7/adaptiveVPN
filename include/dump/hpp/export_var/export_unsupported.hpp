#pragma once

#include <string>

#include "../escape_sequence.hpp"

namespace cpp_dump
{

    namespace _detail
    {

        inline std::string export_unsupported()
        {
            return es::unsupported("Unsupported Type");
        }

    }  // namespace _detail

}  // namespace cpp_dump

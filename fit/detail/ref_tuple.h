/*=============================================================================
    Copyright (c) 2012 Paul Fultz II
    ref_tuple.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef FIT_GUARD_FUNCTION_REF_TUPLE_H
#define FIT_GUARD_FUNCTION_REF_TUPLE_H

#include <tuple>

namespace fit {
namespace detail {

template<class T>
struct remove_rvalue_reference
{
    typedef T type;
};

template<class T>
struct remove_rvalue_reference<T&&>
{
    typedef T type;
};

template<class... Ts>
constexpr auto make_ref_tuple(Ts&&... x)
{
    return std::tuple<typename remove_rvalue_reference<Ts>::type...>(std::forward<Ts>(x)...);
}
}
}

#endif
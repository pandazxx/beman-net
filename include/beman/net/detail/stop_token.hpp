// include/beman/net/detail/stop_token.hpp                          -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_NET_DETAIL_STOP_TOKEN
#define INCLUDED_BEMAN_NET_DETAIL_STOP_TOKEN

#include <beman/execution26/stop_token.hpp>

// ----------------------------------------------------------------------------

namespace beman::net::detail::ex
{
    using ::beman::execution26::never_stop_token;
    using ::beman::execution26::inplace_stop_source;
    using ::beman::execution26::inplace_stop_token;
    using ::beman::execution26::stop_callback_for_t;
    using ::beman::execution26::detail::stoppable_callback_for;
}

// ----------------------------------------------------------------------------

#endif

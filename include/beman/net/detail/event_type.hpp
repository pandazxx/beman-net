// include/beman/net/detail/event_type.hpp                            -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_INCLUDE_BEMAN_NET_DETAIL_EVENT_TYPE
#define INCLUDED_INCLUDE_BEMAN_NET_DETAIL_EVENT_TYPE

#include <cinttypes>

// ----------------------------------------------------------------------------

namespace beman::net {
enum class event_type { none = 0x00, in = 0x01, out = 0x02, in_out = 0x03 };
constexpr ::beman::net::event_type operator&(::beman::net::event_type e0, ::beman::net::event_type e1) {
    return ::beman::net::event_type(::std::uint8_t(e0) & ::std::uint8_t(e1));
}
} // namespace beman::net
// ----------------------------------------------------------------------------

#endif

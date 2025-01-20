// include/beman/net/detail/socket_category.hpp                     -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_NET_DETAIL_SOCKET_CATEGORY
#define INCLUDED_BEMAN_NET_DETAIL_SOCKET_CATEGORY

#include <system_error>

// ----------------------------------------------------------------------------

namespace beman::net
{
    enum class socket_errc: int;
    auto socket_category() noexcept -> ::std::error_category const&;
}

// ----------------------------------------------------------------------------

enum class beman::net::socket_errc: int
{
    already_open = 1,
    not_found
};

auto beman::net::socket_category() noexcept -> ::std::error_category const&
{
    struct category
        : ::std::error_category
    {
        auto name() const noexcept -> char const* override final { return "socket"; }
        auto message(int error) const -> ::std::string override final
        {
            switch (::beman::net::socket_errc(error))
            {
            default: return "none";
            case ::beman::net::socket_errc::already_open: return "already open";
            case ::beman::net::socket_errc::not_found: return "not found";
            }
        }
    };
    static const category rc{};
    return rc;
}


// ----------------------------------------------------------------------------

#endif

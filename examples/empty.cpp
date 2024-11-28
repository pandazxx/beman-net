// examples/http-server.cpp                                           -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <beman/net29/net.hpp>
#include <beman/execution26/execution.hpp>
#include "demo_algorithm.hpp"
#include "demo_error.hpp"
#include "demo_scope.hpp"
#include "demo_task.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string_view>
#include <unordered_map>

namespace ex  = beman::execution26;
namespace net = beman::net29;
using namespace std::chrono_literals;

// ----------------------------------------------------------------------------

std::unordered_map<std::string, std::string> files{
    {"/", "examples/data/index.html"},
    {"/favicon.ico", "examples/data/favicon.ico"},
    {"/logo.png", "examples/data/logo.png"},
};

struct sender {
    using sender_concept = ex::sender_t;
    using completion_signatures =
        ex::completion_signatures<ex::set_value_t(int)>;
    
    struct state {
        using operation_state_concept = ex::operation_state_t;
        void start() & noexcept {}
    };

    state connect(auto&&) { return {}; }
};

static_assert(ex::operation_state<sender::state>);
static_assert(ex::sender<sender>);
static_assert(ex::sender_in<sender>);

struct receiver {
    using receiver_concept = ex::receiver_t;
    void set_value(auto&&...) && noexcept {}
    void set_error(auto&&)  && noexcept {}
    void set_stopped() && noexcept {}
};

static_assert(ex::receiver<receiver>);

auto main() -> int
{
    auto s{demo::when_any(sender{})};
    using t = demo::detail::make_type_list<beman::execution26::completion_signatures<beman::execution26::set_value_t (int)>>;
    static_assert(std::same_as<t, t>);
    std::move(s).connect(receiver{});
    ex::connect(std::move(s), receiver{});
    static_assert(ex::sender<decltype(s)>);
    static_assert(ex::sender_in<decltype(s)>);
    ex::sync_wait(std::move(s));
}

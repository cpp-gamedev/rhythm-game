#pragma once
#include <chrono>

using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;
using Timespan = std::chrono::milliseconds;

namespace timeutils
{
TimePoint now();
Timespan delta(TimePoint const& from, TimePoint const& to = now());
} // namespace timeutils
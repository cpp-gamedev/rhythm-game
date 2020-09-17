#include "timeutils.hpp"

TimePoint timeutils::now()
{
	return Clock::now();
}

Timespan timeutils::delta(TimePoint const& from, TimePoint const& to)
{
	return std::chrono::duration_cast<Timespan>(to - from);
}
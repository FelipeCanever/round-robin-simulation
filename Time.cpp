#include "Time.hpp"

#include <stdexcept>
using std::invalid_argument;

namespace roundRobin
{
	Time::Time(T const value):
		_value{this->validate(value)}
	{}

	Time::Time():
		Time{0}
	{}

	Time::operator T() const
	{
		return this->_value;
	}

	auto operator += (Time& a, Time b) -> Time&
	{
		a._value += b._value;
		return a;
	}

	auto operator -= (Time& a, Time b) -> Time&
	{
		a._value -= b._value;
		return a;
	}

	auto operator << (std::ostream& ostream, Time time) -> std::ostream&
	{
		return ostream << time._value;
	}

	auto operator >> (std::istream& istream, Time& time) -> std::istream&
	{
		auto value = Time::T{};
		istream >> value;
		time = value;

		return istream;
	}

	auto Time::validate(T const value) -> T
	{
		if (value < 0)
			throw invalid_argument{"A time must be positive."};

		return value;
	}
}
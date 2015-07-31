#include "Timespan.h"

struct Timespan::TimespanImpl {
    int hours_;
    int minutes_;
    int seconds_;
};

Timespan::~Timespan()
{
}

Timespan::Timespan()
: pImpl(new TimespanImpl) {
}

Timespan::Timespan(Timespan const& other) {}
Timespan& Timespan::operator=(Timespan const&) { return *this; }
void Timespan::set(int hours, int minutes, int seconds) {
    pImpl->hours_ = hours;
    pImpl->seconds_ = seconds;
    pImpl->minutes_ = minutes;
}

int Timespan::hours() const { return pImpl->hours_; }
int Timespan::minutes() const { return pImpl->minutes_; }
int Timespan::seconds() const { return pImpl->seconds_; }
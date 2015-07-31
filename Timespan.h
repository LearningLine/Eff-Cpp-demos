#ifndef __NetApp20150727__Timespan__
#define __NetApp20150727__Timespan__

#include <iostream>
#include <memory>

class Timespan
{
    struct TimespanImpl;
    std::unique_ptr<TimespanImpl> pImpl;
public:
    
    Timespan();
    Timespan(Timespan const&);
    ~Timespan();
    Timespan& operator=(Timespan const&);
    
    void set(int hours, int minutes, int seconds);
    void set(int ticks);
    
    int hours() const;
    int minutes() const;
    int seconds() const;
    int ticks() const;
};


#endif /* defined(__NetApp20150727__Timespan__) */

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    explicit Timer() : start{Clock::now()}
    {}

    double peek() {
        using Sec = std::chrono::duration<double>;
        Sec elapsed {std::chrono::duration_cast<Sec>(Clock::now() - start)};
        return elapsed.count();
    }

private:
    using Clock = std::chrono::high_resolution_clock;
    const Clock::time_point start;
};

#endif

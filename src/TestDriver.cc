#include "TestDriver.h"
#include <cassert>
#include <iostream>
#include "Timer.h"

void TestDriver::test(median_t median) {
    Timer t;
    median(filter, x, y);
    time = t.peek();
}

void TestDriver::report(const char* descr1, const char* descr2, unsigned seed) const {
    std::cout.precision(5);
    std::cout
        << descr1 << "\t"
        << filter.half << "\t"
        << filter.blocks << "\t"
        << descr2 << "\t"
        << seed << "\t"
        << std::fixed
        << time << std::endl;
}

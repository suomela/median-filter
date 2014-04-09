#ifndef TESTDRIVER_H
#define TESTDRIVER_H

#include "MedianAlgorithm.h"

class TestDriver {
public:
    Vector x;
    Vector y;
    const MedianFilter filter;
    double time;

    TestDriver(MedianFilter f) :
        x(f.n),
        y(f.result),
        filter {f}
    {}

    // Applies algorithm "median".
    // Reads input from "x".
    // Stores output in "y".
    // Running time in seconds is stored in "time".
    void test(median_t median);

    void report(const char* descr1, const char* descr2, unsigned seed) const;
};

#endif

#ifndef MEDIANALGORITHM_H
#define MEDIANALGORITHM_H

#include "Median.h"

using median_t = void (*)(MedianFilter f, const Vector& x, Vector& y);

struct MedianAlgorithm {
    median_t alg;
    const char *name;
};

extern const unsigned n_median_algorithms;
extern const MedianAlgorithm median_algorithms[];

#endif

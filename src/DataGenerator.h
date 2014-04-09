#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include "Element.h"

using generator_t = void (*)(Vector& x, unsigned seed);

struct DataGenerator {
    generator_t gen;
    const char *name;
    bool randomised;
};

extern const unsigned n_generators;
extern const DataGenerator generators[];

#endif

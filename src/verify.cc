#include <iostream>
#include "DataGenerator.h"
#include "TestDriver.h"
#include "MedianAlgorithm.h"
#include "Util.h"

static void check(const Vector& y, const Vector& z) {
    assert(y.size() == z.size());
    for (size_t i {0}; i < y.size(); ++i) {
        assert(y[i] == z[i]);
    }
}

static void verify(MedianFilter filter, unsigned igen) {
    TestDriver t {filter};
    const DataGenerator& gen = generators[igen];
    unsigned seed = gen.randomised ? 1 : 0;
    gen.gen(t.x, seed);
    Vector z(filter.result);
    for (unsigned ialg {0}; ialg < n_median_algorithms; ++ialg) {
        const MedianAlgorithm& alg = median_algorithms[ialg];
        t.test(alg.alg);
        t.report(alg.name, gen.name, seed);
        if (ialg == 0) {
            std::copy(t.y.begin(), t.y.end(), z.begin());
        } else {
            check(t.y, z);
        }
    }
}

static bool arg_parse(int argc, const char **argv, unsigned &scale) {
    if (argc > 2) {
        std::cerr << "usage: " << argv[0] << " [SCALE]" << std::endl;
        return false;
    }
    if (argc == 2) {
        if (!parse_uint(argv[1], scale, 1, 1000, "SCALE")) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char **argv) {
    unsigned scale {1};
    if (!arg_parse(argc, argv, scale)) {
        return EXIT_FAILURE;
    }
    for (unsigned gen {0}; gen < n_generators; ++gen) {
        verify(MedianFilter(10000, 1 * scale), gen);
        verify(MedianFilter(1000, 10 * scale), gen);
        verify(MedianFilter(100, 100 * scale), gen);
        verify(MedianFilter(10, 1000 * scale), gen);
        verify(MedianFilter(1, 10000 * scale), gen);
    }
}

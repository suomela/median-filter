#include <climits>
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

static void verify(MedianFilter filter, unsigned igen, unsigned nalg) {
    TestDriver t {filter};
    const DataGenerator& gen = generators[igen];
    unsigned seed = gen.randomised ? 1 : 0;
    gen.gen(t.x, seed);
    Vector z(filter.result);
    for (unsigned ialg {0}; ialg < nalg; ++ialg) {
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

static bool arg_parse(int argc, const char **argv, unsigned &scale, bool &skipmove) {
    if (argc > 3) {
        std::cerr << "usage: " << argv[0] << " [SCALE] [SKIP-MOVE]" << std::endl;
        return false;
    }
    if (argc > 2) {
        skipmove = true;
    }
    if (argc > 1) {
        if (!parse_uint(argv[1], scale, 1, UINT_MAX, "SCALE")) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char **argv) {
    unsigned scale {1};
    bool skipmove {false};
    if (!arg_parse(argc, argv, scale, skipmove)) {
        return EXIT_FAILURE;
    }
    unsigned nalg {skipmove ? n_median_algorithms - 1 : n_median_algorithms};
    for (unsigned gen {0}; gen < n_generators; ++gen) {
        unsigned h {1};
        unsigned b {10000 * scale};
        while (b >= 1) {
            verify(MedianFilter(h, b), gen, nalg);
            h *= 10;
            b /= 10;
        }
    }
}

#include <climits>
#include <iostream>
#include "DataGenerator.h"
#include "TestDriver.h"
#include "MedianAlgorithm.h"
#include "Util.h"

struct Params {
    unsigned half;
    unsigned blocks;
    unsigned alg;
    unsigned gen;
    unsigned seed;
};

static bool arg_parse(int argc, const char **argv, Params& p) {
    if (argc != 6) {
        std::cerr << "invalid arguments" << std::endl;
        std::cout << "\nusage: " << argv[0] << " HALF-WINDOW BLOCKS ALGORITHM GENERATOR SEED\n";
        std::cout << "\nALGORITHM:\n";
        for (unsigned i {0}; i < n_median_algorithms; ++i) {
            std::cout << " " << i << " " << median_algorithms[i].name << "\n";
        }
        std::cout << "\nGENERATOR:\n";
        for (unsigned i {0}; i < n_generators; ++i) {
            std::cout << " " << i << " " << generators[i].name << "\n";
        }
        std::cout << std::endl;
        return false;
    }
    if (!parse_uint(argv[1], p.half,   1, UINT_MAX,                "HALF-WINDOW") ||
        !parse_uint(argv[2], p.blocks, 1, UINT_MAX,                "BLOCKS") ||
        !parse_uint(argv[3], p.alg,    0, n_median_algorithms - 1, "ALGORITHM") ||
        !parse_uint(argv[4], p.gen,    0, n_generators - 1,        "WINDOW") ||
        !parse_uint(argv[5], p.seed,   0, UINT_MAX,                "SEED")) {
        return false;
    }
    return true;
}

int main(int argc, const char **argv) {
    Params p {3,1,0,0,0};
    if (!arg_parse(argc, argv, p)) {
        return EXIT_FAILURE;
    }
    TestDriver t {MedianFilter(p.half, p.blocks)};
    const DataGenerator& gen = generators[p.gen];
    const MedianAlgorithm& alg = median_algorithms[p.alg];
    if (!gen.randomised) {
        p.seed = 0;
    }
    gen.gen(t.x, p.seed);
    t.test(alg.alg);
    t.report(alg.name, gen.name, p.seed);
}

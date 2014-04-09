#include "DataGenerator.h"
#include <cassert>
#include <random>
#include <stdexcept>

using Rng = std::mt19937_64;

static void asc(Vector& x, unsigned seed) {
    for (size_t i {0}; i < x.size(); ++i) {
        x[i] = static_cast<elem_t>(i);
    }
}

static void desc(Vector& x, unsigned seed) {
    for (size_t i {0}; i < x.size(); ++i) {
        x[i] = static_cast<elem_t>(x.size() - i);
    }
}

static void r_asc(Vector& x, unsigned seed) {
    Rng rng {seed};
    std::uniform_int_distribution<elem_t> noise(0, 9999);
    for (size_t i {0}; i < x.size(); ++i) {
        x[i] = static_cast<elem_t>(i) + noise(rng);
    }
}

static void r_desc(Vector& x, unsigned seed) {
    Rng rng {seed};
    std::uniform_int_distribution<elem_t> noise(0, 9999);
    for (size_t i {0}; i < x.size(); ++i) {
        x[i] = static_cast<elem_t>(x.size() - i) + noise(rng);
    }
}

static void r_large(Vector& x, unsigned seed) {
    Rng rng {seed};
    assert(rng.min() == 0);
    assert(rng.max() >= std::numeric_limits<elem_t>::max());
    for (size_t i {0}; i < x.size(); ++i) {
        x[i] = static_cast<elem_t>(rng());
    }
}

static void r_small(Vector& x, unsigned seed) {
    Rng rng {seed};
    std::uniform_int_distribution<elem_t> noise(0, 9999);
    for (size_t i {0}; i < x.size(); ++i) {
        x[i] = noise(rng);
    }
}

static void r_block(Vector& x, unsigned seed) {
    Rng rng {seed};
    std::bernoulli_distribution p(0.0001);
    std::uniform_int_distribution<elem_t> noise(0, 9999);
    std::uniform_int_distribution<elem_t> base(0, std::numeric_limits<elem_t>::max() / 2);
    elem_t b {0};
    for (size_t i {0}; i < x.size(); ++i) {
        if (i == 0 || p(rng)) {
            b = base(rng);
        }
        x[i] = b + noise(rng);
    }
}

const unsigned n_generators = 7;

const DataGenerator generators[n_generators] {
    { asc,      "asc",      false },
    { desc,     "desc",     false },
    { r_asc,    "r-asc",    true  },
    { r_desc,   "r-desc",   true  },
    { r_large,  "r-large",  true  },
    { r_small,  "r-small",  true  },
    { r_block,  "r-block",  true  },
};

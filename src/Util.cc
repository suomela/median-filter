#include "Util.h"
#include <iostream>

bool parse_uint(const char *s, unsigned &target, unsigned min, unsigned max, const char *descr) {
    long x {std::strtol(s, NULL, 10)};
    if (x < min || x > max) {
        std::cerr << descr << " must be between " << min << " and " << max << std::endl;
        return false;
    } else {
        target = static_cast<unsigned>(x);
        return true;
    }
}

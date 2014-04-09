#include "MoveMedian.h"
#include <algorithm>

// Inspired by Octave "signal" package, medfilt1 function

class MoveMedian {
public:
    explicit MoveMedian(MedianFilter f) :
        filter {f},
        buf(f.k)
    {}

    void run(const Vector& x, Vector& y) {
        init(x);
        y[0] = buf[filter.half];
        for (unsigned i {filter.k}; i < filter.n; ++i) {
            del_add(x[i - filter.k], x[i]);
            y[i - filter.k + 1] = buf[filter.half];
        }
    }

private:
    void init(const Vector& x) {
        std::copy(&x[0], &x[filter.k], buf.begin());
        std::sort(buf.begin(), buf.end());
    }

    inline void del_add(elem_t a, elem_t b) {
        if (a < b) {
            auto p = std::lower_bound(buf.begin(), buf.end(), a);
            auto q = std::lower_bound(p + 1, buf.end(), b);
            std::copy(p + 1, q, p);
            *(q - 1) = b;
        } else if (a > b) {
            auto p = std::lower_bound(buf.begin(), buf.end(), a);
            auto q = std::upper_bound(buf.begin(), p, b);
            std::copy_backward(q, p, p + 1);
            *q = b;
        }
    }

    const MedianFilter filter;
    Vector buf;
};


void move_median(MedianFilter f, const Vector& x, Vector& y) {
    MoveMedian m(f);
    m.run(x, y);
}

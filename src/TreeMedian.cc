#include "TreeMedian.h"
#include <algorithm>
#include <set>

class TreeMedian {
public:
    explicit TreeMedian(MedianFilter f) :
        filter {f}
    {}

    void run(const Vector& x, Vector& y) {
        init(x);
        y[0] = median;
        for (unsigned i {filter.k}; i < filter.n; ++i) {
            add(x[i]);
            del(x[i - filter.k]);
            balance();
            assert(large.size() == filter.half);
            assert(large.size() == filter.half);
            assert(median <= *large.rbegin());
            assert(median >= *small.begin());
            y[i - filter.k + 1] = median;
        }
    }

private:
    using Mset = std::multiset<elem_t>;

    inline static void ms_add(Mset &s, elem_t v) {
        s.insert(v);
    }

    inline static void ms_del(Mset &s, elem_t v) {
        s.erase(s.find(v));
    }

    inline static elem_t ms_del_min(Mset &s) {
        auto p = s.cbegin();
        elem_t v {*p};
        s.erase(p);
        return v;
    }

    inline static elem_t ms_del_max(Mset &s) {
        auto p = s.cend();
        --p;
        elem_t v {*p};
        s.erase(p);
        return v;
    }

    void init(const Vector& x) {
        Vector head(&x[0], &x[filter.k]);
        std::sort(head.begin(), head.end());
        median = head[filter.half];
        small.insert(&head[0], &head[filter.half]);
        large.insert(&head[filter.half + 1], &head[filter.k]);
    }

    inline void add(elem_t e) {
        ms_add(e > median ? large : small, e);
    }

    inline void del(elem_t e) {
        if (e == median) {
            median = ms_del_min(large);
        } else {
            ms_del(e > median ? large : small, e);
        }
    }

    inline void balance() {
        if (large.size() < small.size()) {
            ms_add(large, median);
            median = ms_del_max(small);
        } else if (large.size() > small.size()) {
            ms_add(small, median);
            median = ms_del_min(large);
        }
    }

    const MedianFilter filter;
    elem_t median;
    Mset small;
    Mset large;
};


void tree_median(MedianFilter f, const Vector& x, Vector& y) {
    TreeMedian m(f);
    m.run(x, y);
}

#include "SortMedian.h"
#include <algorithm>
#include <limits>

struct Part {
private:
    constexpr static unsigned NONE {std::numeric_limits<unsigned>::max()};

    struct Links {
        unsigned prev;
        unsigned next;
    };

    struct Elem {
        elem_t data;
        unsigned rank;
        Links history;
        Links cur;
    };

public:
    // Always points to data or tail (never head)
    unsigned med;
    // Elements before med
    unsigned small;
    // Elements at or after med
    unsigned large;

    explicit Part(MedianFilter f) :
        filter {f},
        elem(f.k + 2),
        sorted(f.k)
    {}

    void init(const Vector& x, unsigned part) {
        elem[head()].data = 0;
        elem[tail()].data = std::numeric_limits<elem_t>::max();
        for (unsigned i {0}; i < filter.k; ++i) {
            elem_t e {x[filter.k * part + i]};
            elem[i].data = e;
            sorted[i] = std::make_pair(e, i);
        }
        std::sort(sorted.begin(), sorted.end());
        init_links();
        med = sorted[filter.half].second;
        small = filter.half;
        large = filter.half + 1;
    }

    void unwind() {
        for (unsigned j {0}; j < filter.k; ++j) {
            unsigned i {filter.k - 1 - j};
            Links a = elem[i].cur;
            elem[i].history = a;
            elem[a.prev].cur.next = a.next;
            elem[a.next].cur.prev = a.prev;
        }
        med = tail();
        small = 0;
        large = 0;
    }

    inline void del(unsigned i) {
        Links l = elem[i].cur;
        elem[l.prev].cur.next = l.next;
        elem[l.next].cur.prev = l.prev;
        if (elem[i].rank < elem[med].rank) {
            --small;
        } else {
            if (i == med) {
                med = l.next;
            }
            if (small > 0) {
                med = elem[med].cur.prev;
                --small;
            } else {
                --large;
            }
        }
    }

    inline void add(unsigned i) {
        Links l = elem[i].history;
        elem[l.prev].cur.next = i;
        elem[l.next].cur.prev = i;
        elem[i].cur = l;
        if (elem[i].rank < elem[med].rank) {
            med = elem[med].cur.prev;
        }
        ++large;
    }

    inline void advance() {
        med = elem[med].cur.next;
        ++small;
        --large;
    }

    inline elem_t peek() const {
        return elem[med].data;
    }

    inline bool at_end() const {
        return large == 0;
    }

    inline elem_t midpoint() const {
        return sorted[filter.half].first;
    }

private:
    void init_links() {
        unsigned a {head()};
        elem[head()].cur.prev = NONE;
        elem[head()].rank = NONE;
        for (unsigned i {0}; i < filter.k; ++i) {
            unsigned b {sorted[i].second};
            elem[a].cur.next = b;
            elem[b].cur.prev = a;
            elem[b].rank = i;
            a = b;
        }
        elem[a].cur.next = tail();
        elem[tail()].cur.prev = a;
        elem[tail()].cur.next = NONE;
        elem[tail()].rank = filter.k;
    }

    inline unsigned head() const {
        return filter.k;
    }

    inline unsigned tail() const {
        return filter.k + 1;
    }

    inline unsigned listsize() const {
        return filter.k + 2;
    }

    MedianFilter filter;
    std::vector<Elem> elem;
    std::vector<std::pair<elem_t, unsigned>> sorted;
};


class SortMedian {
public:
    explicit SortMedian(MedianFilter f) :
        filter {f},
        a {f},
        b {f}
    {}

    void run(const Vector& x, Vector& y) {
        b.init(x, 0);
        y[0] = b.midpoint();
        for (unsigned part {1}; part < filter.blocks; ++part) {
            std::swap(a, b);
            b.init(x, part);
            b.unwind();
            run_part(y, part);
        }
    }

private:
    void run_part(Vector& y, unsigned part) {
        for (unsigned i {0}; i < filter.k; ++i) {
            a.del(i);
            b.add(i);
            assert(a.small + b.small <= filter.half);
            balance();
            assert(a.small + b.small == filter.half);
            elem_t median {std::min(a.peek(), b.peek())};
            y[(part - 1) * filter.k + i + 1] = median;
        }
        assert(a.small == 0);
        assert(a.large == 0);
        assert(b.small == filter.half);
        assert(b.large == filter.half + 1);
    }

    inline void balance() {
        if (a.small + b.small < filter.half) {
            if (a_next()) {
                a.advance();
            } else {
                b.advance();
            }
        }
    }

    inline bool a_next() const {
        if (b.at_end()) {
            return true;
        } else if (a.at_end()) {
            return false;
        } else {
            return a.peek() <= b.peek();
        }
    }

    const MedianFilter filter;
    Part a;
    Part b;
};


void sort_median(MedianFilter f, const Vector& x, Vector& y) {
    SortMedian m(f);
    m.run(x, y);
}

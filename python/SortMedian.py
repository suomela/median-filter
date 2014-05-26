def create_array(n):
    return [None] * n

def sort_block(alpha):
    pairs = [(alpha[i], i) for i in range(len(alpha))]
    return [i for v,i in sorted(pairs)]


class Block:
    def __init__(self, h, alpha):
        assert 2 * h + 1 == len(alpha)
        self.k = len(alpha)
        self.alpha = alpha
        self.pi = sort_block(alpha)
        self.prev = create_array(self.k + 1)
        self.next = create_array(self.k + 1)
        self.tail = self.k
        self.init_links()
        self.m = self.pi[h]
        self.s = h

    def init_links(self):
        # Use permutation pi to construct a doubly linked list.
        # There is an additional element at index k, which
        # serves as the head and the tail of the list.
        p = self.tail
        for i in range(self.k):
            q = self.pi[i]
            self.next[p] = q
            self.prev[q] = p
            p = q
        self.next[p] = self.tail
        self.prev[self.tail] = p

    def unwind(self):
        # Delete all elements from the list.
        for i in range(self.k-1, -1, -1):
            self.next[self.prev[i]] = self.next[i]
            self.prev[self.next[i]] = self.prev[i]
        self.m = self.tail
        self.s = 0

    def delete(self, i):
        # Delete one element.
        # Guarantee: s decreases by one (unless already zero).
        self.next[self.prev[i]] = self.next[i]
        self.prev[self.next[i]] = self.prev[i]
        if self.is_small(i):
            # We deleted a small element.
            self.s -= 1
        else:
            # We deleted a large element (or m itself).
            if self.m == i:
                # Make sure that m is still well-defined.
                self.m = self.next[self.m]
            if self.s > 0:
                # Move m so that we can decrease s.
                self.m = self.prev[self.m]
                self.s -= 1

    def undelete(self, i):
        # Put back one element.
        # Guarantee: s does not change.
        self.next[self.prev[i]] = i
        self.prev[self.next[i]] = i
        if self.is_small(i):
            # We deleted a small element.
            # Move m so that s is still correct.
            self.m = self.prev[self.m]

    def advance(self):
        # Increase s by one.
        self.m = self.next[self.m]
        self.s += 1

    def at_end(self):
        return self.m == self.tail

    def peek(self):
        return float('Inf') if self.at_end() else self.alpha[self.m]

    def get_pair(self, i):
        return (self.alpha[i], i)

    def is_small(self, i):
        return self.at_end() or self.get_pair(i) < self.get_pair(self.m)


def sort_median(h, b, x):
    k = 2 * h + 1
    L2 = Block(h, x[0:k])
    y = []
    y.append(L2.peek())
    for j in range(1, b):
        L1 = L2
        L2 = Block(h, x[j*k:(j+1)*k])
        L2.unwind()
        assert L1.s == h
        assert L2.s == 0
        for i in range(k):
            L1.delete(i)
            L2.undelete(i)
            assert L1.s + L2.s <= h
            if L1.s + L2.s < h:
                if L1.peek() <= L2.peek():
                    L1.advance()
                else:
                    L2.advance()
            assert L1.s + L2.s == h
            y.append(min(L1.peek(), L2.peek()))
        assert L1.s == 0
        assert L2.s == h
    return y

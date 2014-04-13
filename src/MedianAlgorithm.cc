#include "MedianAlgorithm.h"
#include "TreeMedian.h"
#include "HeapMedian.h"
#include "SortMedian.h"
#include "MoveMedian.h"

const unsigned n_median_algorithms = 4;

const MedianAlgorithm median_algorithms[n_median_algorithms] {
    { sort_median, "sort" },
    { heap_median, "heap" },
    { tree_median, "tree" },
    { move_median, "move" },
};

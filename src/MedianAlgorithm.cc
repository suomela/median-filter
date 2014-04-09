#include "MedianAlgorithm.h"
#include "TreeMedian.h"
#include "SortMedian.h"
#include "MoveMedian.h"

const unsigned n_median_algorithms = 3;

const MedianAlgorithm median_algorithms[n_median_algorithms] {
    { sort_median, "sort" },
    { tree_median, "tree" },
    { move_median, "move" },
};

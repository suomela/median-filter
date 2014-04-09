#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>

#ifdef ELEMENT_LONG
using elem_t = unsigned long;
#else
using elem_t = unsigned;
#endif

using Vector = std::vector<elem_t>;

#endif

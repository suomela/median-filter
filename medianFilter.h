#ifndef SIMPLE_H
#define SIMPLE_H

#include "Mediator.h"

void filter( double* array, int n, int filterSize );
void filter( long* array, int n, int filterSize );
void filterEachRow( double* array, int m, int n, int filterSize );
void filterEachRow( long* array, int m, int n, int filterSize );

#endif
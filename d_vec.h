/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2013 Alessandro Andrioni

******************************************************************************/

#ifndef D_VEC_H
#define D_VEC_H

#undef ulong /* interferes with system includes */
#include <stdlib.h>
#include <stdio.h>
#define ulong mp_limb_t

#include <math.h>
#include <float.h>
#include "flint.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* Basic manipulation */

double * _d_vec_init(slong len);
void _d_vec_clear(double * vec, slong len);
void _d_vec_set(double * vec1, const double * vec2, slong len2);
int _d_vec_equal(const double * vec1, const double * vec2, slong len);
int _d_vec_is_zero(const double * vec, slong len);
void _d_vec_swap(double * vec1, double * vec2, slong len2);
void _d_vec_zero(double * vec, slong len);
void _d_vec_neg(double * vec1, const double * vec2, slong len2);

/*  Randomisation */

void _d_vec_randtest(double * f, flint_rand_t state, slong len);

/* Input and output */

int _d_vec_fprint(FILE * file, const double * vec, slong len);

static __inline__
int _d_vec_print(const double * vec, slong len)
{
    return _d_vec_fprint(stdout, vec, len);
}

/* Addition */

void _d_vec_add(double * res, const double * vec1,
                                            const double * vec2, slong len2);

void _d_vec_sub(double * res, const double * vec1,
                                            const double * vec2, slong len2);

#ifdef __cplusplus
}
#endif

#endif
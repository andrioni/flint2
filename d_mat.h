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

#ifndef D_MAT_H
#define D_MAT_H

#undef ulong /* interferes with system includes */
#include <stdlib.h>
#include <stdio.h>
#define ulong mp_limb_t

#include <math.h>
#include <float.h>
#include "flint.h"
#include "d_vec.h"

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct
{
    double * entries;
    slong r;
    slong c;
    double ** rows;
} d_mat_struct;

typedef d_mat_struct d_mat_t[1];

/* Basic manipulation ***/

#define d_mat_entry(mat, i, j) ((mat)->rows[i] + (j))
#define d_mat_nrows(mat) ((mat)->r)
#define d_mat_ncols(mat) ((mat)->c)

void d_mat_init(d_mat_t mat, slong rows, slong cols);
void d_mat_init_set(d_mat_t mat, const d_mat_t src);
void d_mat_swap(d_mat_t mat1, d_mat_t mat2);
void d_mat_set(d_mat_t mat1, const d_mat_t mat2);
void d_mat_clear(d_mat_t mat);

#ifdef __cplusplus
}
#endif

#endif

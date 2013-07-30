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

    Copyright (C) 2010 William Hart
    Copyright (C) 2013 Alessandro Andrioni

******************************************************************************/

#ifndef MFPR_MAT_H
#define MPFR_MAT_H

#include <gmp.h>
#include <mpfr.h> 
#include "mpfr_vec.h"
#include "d_mat.h"
#include "fmpz_mat.h"
#include "fmpq_mat.h"

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct
{
    mpfr * entries;
    slong r;
    slong c;
    mpfr_prec_t prec;
    mpfr ** rows;
} mpfr_mat_struct;

/* fmpz_mat_t allows reference-like semantics for fmpz_mat_struct */
typedef mpfr_mat_struct mpfr_mat_t[1];

/* Basic manipulation */

#define mpfr_mat_entry(mat, i, j) ((mat)->rows[i] + (j))
#define mpfr_mat_nrows(mat) ((mat)->r)
#define mpfr_mat_ncols(mat) ((mat)->c)

void mpfr_mat_init(mpfr_mat_t mat, slong rows, slong cols, mpfr_prec_t prec);

void mpfr_mat_init_set(mpfr_mat_t mat, const mpfr_mat_t src, mpfr_prec_t prec);

void mpfr_mat_swap(mpfr_mat_t mat1, mpfr_mat_t mat2);

void mpfr_mat_set(mpfr_mat_t mat1, const mpfr_mat_t mat2);

void mpfr_mat_clear(mpfr_mat_t mat);

void mpfr_mat_zero(mpfr_mat_t mat);

void mpfr_mat_one(mpfr_mat_t mat);

/* Conversions */

void mpfr_mat_set_d_mat(mpfr_mat_t rop, const d_mat_t op);

void mpfr_mat_set_fmpz_mat(mpfr_mat_t rop, const fmpz_mat_t op);

void mpfr_mat_set_fmpq_mat(mpfr_mat_t rop, const fmpq_mat_t op);

/* Comparison */

int mpfr_mat_equal(const mpfr_mat_t mat1, const mpfr_mat_t mat2);

int mpfr_mat_approx(const mpfr_mat_t mat1, const mpfr_mat_t mat2,
                                            mpfr_prec_t prec, double tol);

int mpfr_mat_is_zero(const mpfr_mat_t mat);

/* Random matrices */

void mpfr_mat_randtest(mpfr_mat_t mat, flint_rand_t state);

/* Transpose */

void mpfr_mat_transpose(mpfr_mat_t rop, const mpfr_mat_t op);

/* Addition and subtraction */

void mpfr_mat_add(mpfr_mat_t rop, const mpfr_mat_t op1, const mpfr_mat_t op2);

void mpfr_mat_sub(mpfr_mat_t rop, const mpfr_mat_t op1, const mpfr_mat_t op2);

void mpfr_mat_neg(mpfr_mat_t rop, const mpfr_mat_t op);

#ifdef __cplusplus
}
#endif

#endif


/*============================================================================

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

===============================================================================*/
/******************************************************************************

 Copyright (C) 2010 William Hart
 Copyright (C) 2013 Alessandro Andrioni
 
******************************************************************************/

#ifndef MFPR_VEC_H
#define MPFR_VEC_H

#undef ulong /* interferes with system includes */
#include <stdlib.h>
#include <stdio.h>
#define ulong mp_limb_t

#include <gmp.h>
#include <mpfr.h>
#include "fmpz.h"
#include "fmpq.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* Basic manipulation */

mpfr * _mpfr_vec_init(slong length, mpfr_prec_t prec);

void _mpfr_vec_clear(mpfr * vec, slong length);

void _mpfr_vec_set(mpfr * vec1, const mpfr * vec2, slong length);

int _mpfr_vec_equal(const mpfr * vec1, const mpfr * vec2, slong length);

int _mpfr_vec_approx(const mpfr * vec1, const mpfr * vec2, slong length,
                                            mpfr_prec_t prec, double tol);

void _mpfr_vec_zero(mpfr * vec, slong length);

void _mpfr_vec_one(mpfr * vec, slong length);

void _mpfr_vec_neg(mpfr * vec1, const mpfr * vec2, slong length);

int _mpfr_vec_is_zero(const mpfr * vec, slong length);

void _mpfr_vec_swap(mpfr * vec1, mpfr * vec2, slong length);

/* Conversions */

void _mpfr_vec_set_d_vec(mpfr * vec1, const double * vec2, slong length);

void _mpfr_vec_set_fmpz_vec(mpfr * vec1, const fmpz * vec2, slong length);

void _mpfr_vec_set_fmpq_vec(mpfr * vec1, const fmpq * vec2, slong length);

/* Randomisation */

void _mpfr_vec_randtest(mpfr * vec1, flint_rand_t state, slong length);

/* Input and output */

int _mpfr_vec_fprint(FILE * file, const mpfr * vec, slong length,
                                            mpfr_prec_t prec);

static __inline__
int _mpfr_vec_print(const mpfr * vec, slong length, mpfr_prec_t prec)
{
    return _mpfr_vec_fprint(stdout, vec, length, prec);
}

/* Addition */

void _mpfr_vec_add(mpfr * res, const mpfr * vec1, const mpfr * vec2, 
                                            slong length);

void _mpfr_vec_sub(mpfr * res, const mpfr * vec1, const mpfr * vec2, 
                                            slong length);

/* Vector sum and product */

void _mpfr_vec_sum(mpfr_t res, const mpfr * vec, slong length);

void _mpfr_vec_prod(mpfr_t res, const mpfr * vec, slong length);

/* Inner product and norm */

void _mpfr_vec_dot(mpfr_t res, const mpfr * vec1, const mpfr * vec2,
                                            slong length);

void _mpfr_vec_norm(mpfr_t res, const mpfr * vec, slong length);

/* Scalar operations */

void _mpfr_vec_scalar_mul_2exp(mpfr * res, const mpfr * vec, 
                                            slong length, mpfr_prec_t exp);

void _mpfr_vec_scalar_mul_fmpz(mpfr * res, const mpfr * vec,
                                            slong length, fmpz_t c);

void _mpfr_vec_scalar_mul_mpfr(mpfr * res, const mpfr * vec,
                                            slong length, mpfr_t c);

void _mpfr_vec_scalar_mul_si(mpfr * res, const mpfr * vec,
                                            slong length, slong c);

void _mpfr_vec_scalar_mul_ui(mpfr * res, const mpfr * vec,
                                            slong length, ulong c);

void _mpfr_vec_scalar_mul_d(mpfr * res, const mpfr * vec,
                                            slong length, double c);

void _mpfr_vec_scalar_div_fmpz(mpfr * res, const mpfr * vec,
                                            slong length, fmpz_t c);

void _mpfr_vec_scalar_div_mpfr(mpfr * res, const mpfr * vec,
                                            slong length, mpfr_t c);

void _mpfr_vec_scalar_div_si(mpfr * res, const mpfr * vec,
                                            slong length, slong c);

void _mpfr_vec_scalar_div_ui(mpfr * res, const mpfr * vec,
                                            slong length, ulong c);

void _mpfr_vec_scalar_div_d(mpfr * res, const mpfr * vec,
                                            slong length, double c);

void _mpfr_vec_scalar_addmul_fmpz(mpfr * res, const mpfr * vec,
                                            slong length, fmpz_t c);

void _mpfr_vec_scalar_addmul_mpfr(mpfr * res, const mpfr * vec,
                                            slong length, mpfr_t c);

void _mpfr_vec_scalar_addmul_si(mpfr * res, const mpfr * vec,
                                            slong length, slong c);

void _mpfr_vec_scalar_addmul_ui(mpfr * res, const mpfr * vec,
                                            slong length, ulong c);

void _mpfr_vec_scalar_addmul_d(mpfr * res, const mpfr * vec,
                                            slong length, double c);

void _mpfr_vec_scalar_submul_fmpz(mpfr * res, const mpfr * vec,
                                            slong length, fmpz_t c);

void _mpfr_vec_scalar_submul_mpfr(mpfr * res, const mpfr * vec,
                                            slong length, mpfr_t c);

void _mpfr_vec_scalar_submul_si(mpfr * res, const mpfr * vec,
                                            slong length, slong c);

void _mpfr_vec_scalar_submul_ui(mpfr * res, const mpfr * vec,
                                            slong length, ulong c);

void _mpfr_vec_scalar_submul_d(mpfr * res, const mpfr * vec,
                                            slong length, double c);


#ifdef __cplusplus
}
#endif

#endif

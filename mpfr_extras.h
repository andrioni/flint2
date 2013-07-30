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

#ifndef MPFR_EXTRAS_H
#define MPFR_EXTRAS_H

#include <gmp.h>
#include <mpfr.h> 
#include "flint.h"
#include "fmpz.h"

#ifdef __cplusplus
 extern "C" {
#endif

int mpfr_approx_p(const mpfr_t op1, const mpfr_t op2, mpfr_prec_t prec,
                                                double tol);

/*int mpfr_set_fmpz(mpfr_t rop, const fmpz_t op, mpfr_rnd_t rnd);*/

#ifdef __cplusplus
}
#endif

#endif

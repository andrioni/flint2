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

#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>
#include "flint.h"
#include "mpfr_vec.h"

int
mpfr_approx_p(const mpfr_t op1, const mpfr_t op2, mpfr_prec_t prec, double tol)
{
    if (op1 == op2)
        return 1;
    else if (mpfr_equal_p(op1, op2))
        return 1;
    else
    {
        slong ret = 1;
        mpfr_t a, b, tmp, eps;
        mpfr_inits2(prec, a, b, tmp, eps, (mpfr_ptr) 0);

        mpfr_abs(a, op1, MPFR_RNDN);
        mpfr_abs(b, op2, MPFR_RNDN);
        mpfr_set_ui(eps, 1, MPFR_RNDN);
        mpfr_div_2si(eps, eps, prec - 1, MPFR_RNDN);
        mpfr_add(tmp, a, b, MPFR_RNDN);
        mpfr_mul(eps, eps, tmp, MPFR_RNDN);
        mpfr_mul_d(eps, eps, tol, MPFR_RNDN);
        mpfr_sub(tmp, a, b, MPFR_RNDN);
        mpfr_abs(tmp, tmp, MPFR_RNDN);

        if (mpfr_greater_p(tmp, eps))
            ret = 0;

        mpfr_clears(a, b, tmp, eps, (mpfr_ptr) 0);
        return ret;
    }
}

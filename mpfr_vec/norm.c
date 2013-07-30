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

******************************************************************************/

#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>
#include "flint.h"
#include "mpfr_vec.h"

void
_mpfr_vec_norm(mpfr_t res, const mpfr * vec, slong length)
{
    if (length <= 1)
    {
        if (length == 1)
            mpfr_abs(res, vec, MPFR_RNDN);
        else
            mpfr_set_ui(res, 0, MPFR_RNDN);
    }
    else
    {
        slong i;
        mpfr_prec_t prec = mpfr_get_prec(res);
        mpfr_t scale, ssq, absv, tmp;

        mpfr_inits2(prec, scale, ssq, absv, tmp, (mpfr_ptr) 0);

        mpfr_set_ui(scale, 0, MPFR_RNDN);
        mpfr_set_ui(ssq, 1, MPFR_RNDN);

        for (i = 0; i < length; i++)
        {
            if (!mpfr_zero_p(vec + i))
            {
                mpfr_abs(absv, vec + i, MPFR_RNDN);
                if (mpfr_less_p(scale, absv))
                {
                    mpfr_div(tmp, scale, absv, MPFR_RNDN);
                    mpfr_mul(ssq, ssq, tmp, MPFR_RNDN);
                    mpfr_mul(ssq, ssq, tmp, MPFR_RNDN);
                    mpfr_add_ui(ssq, ssq, 1, MPFR_RNDN);
                    mpfr_set(scale, absv, MPFR_RNDN);
                }
                else
                {
                    mpfr_div(tmp, absv, scale, MPFR_RNDN);
                    mpfr_mul(tmp, tmp, tmp, MPFR_RNDN);
                    mpfr_add(ssq, ssq, tmp, MPFR_RNDN);
                }
            }
        }

        mpfr_sqrt(ssq, ssq, MPFR_RNDN);
        mpfr_mul(res, scale, ssq, MPFR_RNDN);
    
        mpfr_clears(scale, ssq, absv, tmp, (mpfr_ptr) 0);
    }
}

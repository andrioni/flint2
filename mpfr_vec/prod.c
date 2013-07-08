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

void
_mpfr_vec_prod(mpfr_t res, const mpfr * vec, slong length)
{
    if (length <= 1)
    {
        if (length == 1)
            mpfr_set(res, vec, MPFR_RNDN);
        else
            mpfr_set_ui(res, 1, MPFR_RNDN);
    }
    else if (length <= 3)
    {
        slong i;

        mpfr_mul(res, vec, vec + 1, MPFR_RNDN);
        for (i = 2; i < length; i++)
            mpfr_mul(res, res, vec + i, MPFR_RNDN);
    }
    else
    {
        slong m = length / 2;
        mpfr_t tmp;
        mpfr_init2(tmp, mpfr_get_prec(res));
        _mpfr_vec_prod(res, vec, m);
        _mpfr_vec_prod(tmp, vec + m, length - m);
        mpfr_mul(res, res, tmp, MPFR_RNDN);
        mpfr_clear(tmp);
    }
}

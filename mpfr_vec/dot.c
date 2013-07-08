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
_mpfr_vec_dot(mpfr_t res, const mpfr * vec1, const mpfr * vec2, slong length)
{
    slong i;
    mpfr_t tmp;
    mpfr_init(tmp);

    mpfr_mul(res, vec1, vec2, MPFR_RNDN);
    for (i = 1; i < length; i++)
    {
        mpfr_mul(tmp, vec1 + i, vec2 + i, MPFR_RNDN);
        mpfr_add(res, res, tmp, MPFR_RNDN);
    }

    mpfr_clear(tmp);
}

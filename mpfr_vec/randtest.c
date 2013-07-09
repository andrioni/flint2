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
#include "ulong_extras.h"

void
_mpfr_vec_randtest(mpfr * vec, flint_rand_t state, slong length)
{
    slong i, sparseness;

    if (n_randint(state, 2))
    {
        for (i = 0; i < length; i++)
            mpfr_urandomb(vec + i, state->gmp_state);
    }
    else
    {
        sparseness = 1 + n_randint(state, FLINT_MAX(2, length));

        for (i = 0; i < length; i++)
        {
            if (n_randint(state, sparseness))
                mpfr_set_ui(vec + i, 0, MPFR_RNDN);
            else
                mpfr_urandomb(vec + i, state->gmp_state);
        }
    }
}

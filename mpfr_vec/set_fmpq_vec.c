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
#include "fmpq.h"
#include "mpfr_vec.h"

void
_mpfr_vec_set_fmpq_vec(mpfr * vec1, const fmpq * vec2, slong length)
{
    slong i;
    for (i = 0; i < length; i++)
        fmpq_get_mpfr(vec1 + i, vec2 + i, MPFR_RNDN);
}

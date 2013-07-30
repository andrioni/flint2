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
/****************************************************************************

   Copyright (C) 2013 Alessandro Andrioni
   
*****************************************************************************/

#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>
#include "flint.h"
#include "fmpz.h"
#include "mpfr_vec.h"

void
_mpfr_vec_scalar_mul_fmpz(mpfr * res, const mpfr * vec, slong length, fmpz_t c)
{
    slong i;
    __mpz_struct *z;

    for (i = 0; i < length; i++)
    {
        z = _fmpz_promote_val(c);
        mpfr_mul_z(res + i, vec + i, z, MPFR_RNDN);
        _fmpz_demote_val(c);
    }
}

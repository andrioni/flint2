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

#include <stdio.h>
#include "flint.h"
#include "mpfr_vec.h"

int
_mpfr_vec_fprint(FILE * file, const mpfr * vec, slong length, mpfr_prec_t prec)
{
    int r;
    slong i;

    r = fprintf(file, "%li", length);
    if ((length > 0) && (r > 0))
    {
        r = fputc(' ', file);
        for (i = 0; (i < length) && (r > 0); i++)
        {
            r = fputc(' ', file);
            if (r > 0)
                r = mpfr_fprintf(file, "%.*Rf", prec, vec + i);
        }
    }

    return r;
}

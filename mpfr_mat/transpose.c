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
#include "mpfr_mat.h"

void
mpfr_mat_transpose(mpfr_mat_t rop, const mpfr_mat_t op)
{
    slong i, j;

    if (rop->r != op->c || rop->c != op->r)
    {
        printf("Exception (mpfr_mat_transpose). Incompatible dimensions.\n");
        abort();
    }

    if (rop->r == 0 || rop->c == 0)
        return;

    if (op == rop)  /* In-place, guaranteed to be square */
    {
        mpfr_t tmp;
        mpfr_prec_t prec = mpfr_get_prec(mpfr_mat_entry(rop, 0, 0));
        mpfr_init2(tmp, prec);

        for (i = 0; i < op->r - 1; i++)
            for (j = i + 1; j < op->c; j++)
            {
                mpfr_set(tmp, mpfr_mat_entry(op, i, j), MPFR_RNDN);
                mpfr_set(mpfr_mat_entry(op, i, j), mpfr_mat_entry(op, j, i), MPFR_RNDN);
                mpfr_set(mpfr_mat_entry(op, j, i), tmp, MPFR_RNDN);
            }

        mpfr_clear(tmp);
    }
    else  /* Not aliased; general case */
    {
        for (i = 0; i < rop->r; i++)
            for (j = 0; j < rop->c; j++)
                mpfr_set(mpfr_mat_entry(rop, i, j), mpfr_mat_entry(op, j, i), MPFR_RNDN);
    }
}

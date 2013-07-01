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

#include "d_mat.h"

void
d_mat_mul(d_mat_t C, const d_mat_t A, const d_mat_t B)
{
    slong m, n, d, i, j, k;

    m = A->r;
    n = A->c;
    d = B->c;

    if (C == A || C == B)
    {
        d_mat_t t;
        d_mat_init(t, m, d);
        d_mat_mul(t, A, B);
        d_mat_swap(C, t);
        d_mat_clear(t);
        return;
    }

    /* For now, only the classical version */
    if (n == 0)
    {
        d_mat_zero(C);
        return;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < d; j++)
        {
            d_mat_entry(C, i, j) = d_mat_entry(A, i, 0) * d_mat_entry(B, 0, j);

            for (k = 1; k < n; k++)
            {
                d_mat_entry(C, i, j) += d_mat_entry(A, i, k) *
                                        d_mat_entry(B, k, j);
            }
        }
    }
}

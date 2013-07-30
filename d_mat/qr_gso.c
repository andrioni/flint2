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
d_mat_qr_gso(d_mat_t Q, d_mat_t R, const d_mat_t A)
{
    slong i, j;

    if (Q->c < 1)
        return;

    if (Q != A)
        d_mat_set(Q, A);

    d_mat_transpose(Q, Q);

    if (R == A)
    {
        printf("R should be different from A\n");
        abort();
    }

    d_mat_zero(R);

    for (i = 0; i < Q->r; i++)
    {
        d_mat_entry(R, i, i) = _d_vec_norm(Q->rows[i], Q->c);
        _d_vec_scalar_div_d(Q->rows[i], Q->rows[i], Q->c, d_mat_entry(R, i, i));
        for (j = i + 1; j < Q->r; j++)
        {
            d_mat_entry(R, i, j) = _d_vec_dot(Q->rows[i], Q->rows[j], Q->c);
            _d_vec_scalar_submul_d(Q->rows[j], Q->rows[i], Q->c, d_mat_entry(R, i, j));
        }
    }

    d_mat_transpose(Q, Q);
}

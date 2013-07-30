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
d_mat_gram_schmidt(d_mat_t B, const d_mat_t A)
{
    slong i, j;
    double inn;

    if (B->c < 1)
        return;

    if (B != A)
        d_mat_set(B, A);

    for (i = 0; i < B->r; i++)
    {
        _d_vec_normalise(B->rows[i], B->rows[i], B->c);
        for (j = i + 1; j < B->r; j++)
        {
            inn = _d_vec_dot(B->rows[i], B->rows[j], B->c);
            _d_vec_scalar_submul_d(B->rows[j], B->rows[i], B->c, inn);
        }
    }
}

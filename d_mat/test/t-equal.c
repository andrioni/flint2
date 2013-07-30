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

#include <stdio.h>
#include <stdlib.h>
#include "flint.h"
#include "d_mat.h"
#include "ulong_extras.h"

int
main(void)
{
    int i;
    flint_rand_t state;

    printf("equal....");
    fflush(stdout);

    flint_randinit(state);

    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        d_mat_t A, B, C, D, E;
        slong m, n, j;

        m = n_randint(state, 20);
        n = n_randint(state, 20);

        d_mat_init(A, m, n);
        d_mat_init(B, m, n);
        d_mat_init(C, m, n);
        d_mat_init(D, m+1, n);
        d_mat_init(E, m, n+1);

        if (d_mat_equal(A, D) || d_mat_equal(A, E))
        {
            printf("FAIL: different dimensions should not be equal\n");
            abort();
        }

        d_mat_randtest(A, state);
        d_mat_set(B, A);

        if (!d_mat_equal(A, B))
        {
            printf("FAIL: copied matrices should be equal\n");
            abort();
        }

        if (m && n)
        {
            j = n_randint(state, m*n);
            (*(A->entries + j))++;

            if (d_mat_equal(A, B))
            {
                printf("FAIL: modified matrices should not be equal\n");
                abort();
            }
        }

        d_mat_clear(A);
        d_mat_clear(B);
        d_mat_clear(C);
        d_mat_clear(D);
        d_mat_clear(E);
    }

    flint_randclear(state);
    printf("PASS\n");
    return 0;
}
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
#include <stdlib.h>
#include "flint.h"
#include "d_mat.h"
#include "double_extras.h"
#include "ulong_extras.h"

int
main(void)
{
    slong m, n, rep;
    flint_rand_t state;

    printf("add/sub/neg....");
    fflush(stdout);

    flint_randinit(state);

    for (rep = 0; rep < 1000 * flint_test_multiplier(); rep++)
    {
        d_mat_t A;
        d_mat_t B;
        d_mat_t C;

        m = n_randint(state, 20);
        n = n_randint(state, 20);

        d_mat_init(A, m, n);
        d_mat_init(B, m, n);
        d_mat_init(C, m, n);

        d_mat_randtest(A, state);
        d_mat_randtest(B, state);

        d_mat_neg(C, A);
        d_mat_add(A, A, B);
        d_mat_sub(A, A, B);
        d_mat_neg(A, A);

        if (!d_mat_approx(A, C, 1L))
        {
            printf("FAIL: matrices not equal!\n");
            abort();
        }

        d_mat_clear(A);
        d_mat_clear(B);
        d_mat_clear(C);
    }

    flint_randclear(state);
    printf("PASS\n");
    return 0;
}

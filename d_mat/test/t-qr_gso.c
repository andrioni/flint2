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
#include "d_vec.h"
#include "d_mat.h"
#include "ulong_extras.h"

int main(void)
{
    d_mat_t A, B, C, Q, R, QR;
    slong i;
    flint_rand_t state;

    printf("gso_qr....");
    fflush(stdout);

    flint_randinit(state);

    for (i = 0; i < 100 * flint_test_multiplier(); i++)
    {
        slong m;

        m = n_randint(state, 5);

        d_mat_init(A, m, m);
        d_mat_init(Q, m, m);
        d_mat_init(R, m, m);
        d_mat_init(QR, m, m);

        d_mat_randtest(A, state);

        d_mat_qr_gso(Q, R, A);
        d_mat_mul(QR, Q, R);

        if (!d_mat_approx(QR, A, 1.0))
        {
            printf("FAIL: aliasing failed\n");
            d_mat_print_pretty(QR);
            printf("\n");
            d_mat_print_pretty(Q);
            printf("\n");
            d_mat_print_pretty(R);
            printf("\n");
            d_mat_print_pretty(A);
            printf("\n");
            abort();
        }

        d_mat_clear(A);
        d_mat_clear(Q);
        d_mat_clear(R);
    }

    /* Test product by identity matrices */
    for (i = 0; i < 100 * flint_test_multiplier(); i++)
    {
        slong m;

        m = n_randint(state, 50);

        d_mat_init(A, m, m);
        d_mat_init(B, m, m);
        d_mat_init(C, m, m);

        d_mat_randtest(A, state);
        d_mat_one(B);

        d_mat_mul(C, A, B);
        d_mat_mul(A, B, A);

        if (!d_mat_equal(A, C))
        {
            printf("FAIL: product by identity failed\n");
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

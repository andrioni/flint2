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
#include "double_extras.h"
#include "ulong_extras.h"

int
main(void)
{
    int i, result;
    flint_rand_t state;

    printf("prod....");
    fflush(stdout);

    flint_randinit(state);

    for (i = 0; i < 100000 * flint_test_multiplier(); i++)
    {
        double *a, *b;
        double x, y, z;

        slong len1 = n_randint(state, 100);
        slong len2 = n_randint(state, 100);

        a = _d_vec_init(len1 + len2);
        b = a + len1;

        _d_vec_randtest(a, state, len1 + len2);

        x = _d_vec_prod(a, len1);
        y = _d_vec_prod(b, len2);
        x = x * y;
        z = _d_vec_prod(a, len1 + len2);

        /* Slightly overstated tolerance */
        result = (x - z <= D_EPS * 10 * (x + z));
        if (!result)
        {
            printf("FAIL:\n");
            _d_vec_print(a, len1), printf("\n\n");
            _d_vec_print(b, len2), printf("\n\n");
            printf("%.20f\n\n", x);
            printf("%.20f\n\n", z);
            abort();
        }

        _d_vec_clear(a, len1 + len2);
    }

    flint_randclear(state);
    printf("PASS\n");
    return 0;
}

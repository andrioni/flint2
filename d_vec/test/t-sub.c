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
#include "ulong_extras.h"

int
main(void)
{
    int i, result;
    flint_rand_t state;

    printf("sub....");
    fflush(stdout);

    flint_randinit(state);

    /* Check aliasing of a and c */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        double *a, *b, *c;
        slong len = n_randint(state, 100);

        a = _d_vec_init(len);
        b = _d_vec_init(len);
        c = _d_vec_init(len);
        _d_vec_randtest(a, state, len);
        _d_vec_randtest(b, state, len);

        _d_vec_sub(c, a, b, len);
        _d_vec_sub(a, a, b, len);

        result = (_d_vec_equal(a, c, len));
        if (!result)
        {
            printf("FAIL:\n");
            _d_vec_print(a, len), printf("\n\n");
            _d_vec_print(c, len), printf("\n\n");
            abort();
        }

        _d_vec_clear(a, len);
        _d_vec_clear(b, len);
        _d_vec_clear(c, len);
    }

    /* Check aliasing of b and c */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        double *a, *b, *c;
        slong len = n_randint(state, 100);

        a = _d_vec_init(len);
        b = _d_vec_init(len);
        c = _d_vec_init(len);
        _d_vec_randtest(a, state, len);
        _d_vec_randtest(b, state, len);

        _d_vec_sub(c, a, b, len);
        _d_vec_sub(b, a, b, len);

        result = (_d_vec_equal(b, c, len));
        if (!result)
        {
            printf("FAIL:\n");
            _d_vec_print(b, len), printf("\n\n");
            _d_vec_print(c, len), printf("\n\n");
            abort();
        }

        _d_vec_clear(a, len);
        _d_vec_clear(b, len);
        _d_vec_clear(c, len);
    }

    /* Check a - a = 0 */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        double *a, *b;
        slong len = n_randint(state, 100);

        a = _d_vec_init(len);
        b = _d_vec_init(len);
        _d_vec_randtest(a, state, len);

        _d_vec_sub(b, a, a, len);

        result = (_d_vec_is_zero(b, len));
        if (!result)
        {
            printf("FAIL:\n");
            _d_vec_print(a, len), printf("\n\n");
            _d_vec_print(b, len), printf("\n\n");
            abort();
        }

        _d_vec_clear(a, len);
        _d_vec_clear(b, len);
    }


    flint_randclear(state);
    printf("PASS\n");
    return 0;
}

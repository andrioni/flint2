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
#include <gmp.h>
#include <mpfr.h>
#include "flint.h"
#include "mpfr_vec.h"
#include "ulong_extras.h"
#include "mpfr_extras.h"

int
main(void)
{
    int i, result;
    flint_rand_t state;

    printf("dot....");
    fflush(stdout);

    flint_randinit(state);
    _flint_rand_init_gmp(state);

    /* Check if a . 1 = sum(a) */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        mpfr *a, *b;
        mpfr_t x, y;

        slong length = n_randint(state, 100) + 1;
        mpfr_prec_t prec = n_randint(state, 200) + MPFR_PREC_MIN;

        a = _mpfr_vec_init(length, prec);
        b = _mpfr_vec_init(length, prec);
        mpfr_inits2(prec, x, y, (mpfr_ptr) 0);

        _mpfr_vec_randtest(a, state, length);
        _mpfr_vec_one(b, length);

        _mpfr_vec_sum(x, a, length);
        _mpfr_vec_dot(y, a, b, length);

        result = (mpfr_approx_p(x, y, prec, 10.0));
        if (!result)
        {
            printf("FAIL:\n");
            _mpfr_vec_print(a, length, 10), printf("\n\n");
            mpfr_printf("%Pu\n\n", prec);
            mpfr_printf("sum %.128Rf\n\n", x);
            mpfr_printf("dot %.128Rf\n\n", y);
            abort();
        }

        _mpfr_vec_clear(a, length);
        _mpfr_vec_clear(b, length);
        mpfr_clears(x, y, (mpfr_ptr) 0);
    }

    flint_randclear(state);

    printf("PASS\n");
    return 0;
}

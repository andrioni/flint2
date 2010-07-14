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

    Copyright (C) 2009 William Hart
    Copyright (C) 2010 Sebastian Pancratz

******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"
#include "fmpz.h"

int
main(void)
{
    int result;
    printf("get_str....");
    fflush(stdout);

    fmpz_randinit();

    for (ulong i = 0; i < 100000UL; i++)
    {
        fmpz_t a;
        mpz_t b;
        int base;
        int j;
        char * str1, * str2;

        fmpz_init(a);
        mpz_init(b);
        fmpz_randtest(a, 200);
        base = (int) (n_randint(61) + 2);

        fmpz_get_mpz(b, a);

        str1 = fmpz_get_str(NULL, base, a);
        str2 = mpz_get_str(NULL, base, b);
        result = strlen(str1) == strlen(str2);
        if (result)
        {
            for (j = 0; result && j < strlen(str1); j++)
                if (str1[j] != str2[j])
                    result = 0;
        }

        if (!result)
        {
            printf("FAIL\n");
            gmp_printf("b = %Zd\n", b);
            printf("base = %d\n", base);
            printf("str1 = %s\n, str2 = %s\n", str1, str2);
            abort();
        }

        fmpz_clear(a);
        mpz_clear(b);
    }

    fmpz_randclear();

    _fmpz_cleanup();
    printf("PASS\n");
    return 0;
}
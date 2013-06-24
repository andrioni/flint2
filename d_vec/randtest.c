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
#include "double_extras.h"
#include "ulong_extras.h"
#include "d_vec.h"

void
_d_vec_randtest(double * f, flint_rand_t state, 
                   slong len)
{
    slong i, sparseness;

    if (n_randint(state, 2))
    {
        for (i = 0; i < len; i++)
            *(f + i) = d_randtest(state);
    }
    else
    {
        sparseness = 1 + n_randint(state, FLINT_MAX(2, len));

        for (i = 0; i < len; i++)
        {
            if (n_randint(state, sparseness))
                *(f + i) = 0.0;
            else
                *(f + i) = d_randtest(state);
        }
    }
}

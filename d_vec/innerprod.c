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

#include "flint.h"
#include "d_vec.h"

double
_d_vec_innerprod(const double * vec1, const double * vec2, slong len)
{
    if (len <= 1)
    {
        if (len == 1)
            return *vec1 * *vec2;
        else
            return 0L;
    }
    else
    {
        slong i;
        double res;

        res = *vec1 * *vec2 + *(vec1 + 1) * *(vec2 + 1);

        for (i = 2; i < len; i++)
            res += *(vec1 + i) * *(vec2 + i);

        return res;
    }
}

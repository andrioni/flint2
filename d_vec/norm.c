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
_d_vec_norm(const double * vec, slong len)
{
    if (len <= 1)
    {
        if (len == 1)
            return fabs(*vec);
        else
            return 0L;
    }
    else
    {
        slong i;
        double res, scale, ssq, absv;

        scale = 0L;
        ssq = 1L;
        for (i = 0; i < len; i++)
        {
            if (vec[i] != 0L)
            {
                absv = fabs(vec[i]);
                if (scale < absv)
                {
                    ssq = 1L + ssq * (scale/absv)*(scale/absv);
                    scale = absv;
                }
                else
                {
                    ssq = ssq + (absv/scale)*(absv/scale);
                }
            }
        }
        res = scale * sqrt(ssq);
        return res;
    }
}

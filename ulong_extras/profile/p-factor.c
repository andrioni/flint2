/*============================================================================

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

===============================================================================*/
/******************************************************************************

 (C) 2009 William Hart

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "profiler.h"
#include "flint.h"
#include "ulong_extras.h"

#define ITERS 1000

typedef struct
{
   ulong * composites;
   mp_bitcnt_t bits;
} fac_one_line_t;

void sample(void * arg, ulong count)
{
   fac_one_line_t * params = (fac_one_line_t *) arg;
   ulong res;
   mp_bitcnt_t bits = params->bits;
   ulong primes = (1L<<(bits/3))/10 + 1;
   n_factor_t factors;
   
   for (ulong i = 0; i < count; i++)
   {
      prof_start();
      for (ulong j = 0; j < ITERS; j++)
	  {
		  n_factor_init(&factors);
	      n_factor(&factors, params->composites[j & 1023], 0);
		  if ((factors.num == 0) || (factors.num == 1 && factors.exp[0] < 2))
			  printf("Error %ld\n", params->composites[j & 1023]);
	  }
	  prof_stop();
   }
}

void fill_array(ulong * ret, mp_bitcnt_t bits)
{
   ulong n;
   n_factor_t factors;
  
   ulong primes = (1<<(bits/3))/10 + 1;
   
   for (ulong i = 0; i < 1024; i++)
   {
	  do 
	  {
		 n_factor_init(&factors);
	     n = n_randbits(bits);
	  } while (n_is_probabprime(n) || (n_factor_trial(&factors, n, primes) != n));
	  ret[i] = n;
   }
      
}

int main(void)
{
   double min, max;
   fac_one_line_t params;
   
   params.composites = malloc(1024*sizeof(ulong));

   printf("factor_one_line:\n");
   
   for (ulong i = 4; i <= 64; i++)
   {
      fill_array(params.composites, i);
      params.bits = i;
	  prof_repeat(&min, &max, sample, &params);
      printf("bits = %ld, time is %.3f us\n", 
		  i, max/(double)ITERS);
   }

   free(params.composites);

   return 0;
}
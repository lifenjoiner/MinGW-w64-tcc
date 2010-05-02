/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
   Contributed by Danny Smith
   2005-01-04
*/

#include <math.h>
#include <complex.h>

/* csin (x + I * y) = sin (x) * cosh (y)
    + I * (cos (x) * sinh (y)) */ 

long double complex csinl (long double complex Z)
{
  long double complex Res;
  __real__ Res = sinl (__real__ Z) * coshl ( __imag__ Z);
  __imag__ Res = cosl (__real__ Z) * sinhl ( __imag__ Z);
  return Res;
}


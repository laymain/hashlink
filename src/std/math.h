/*
 * Copyright (C)2005-2016 Haxe Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef MATH_H
#define MATH_H

#include <hl.h>

HL_PRIM double hl_nan();
HL_PRIM double hl_math_abs( double a );
HL_PRIM bool hl_math_isnan( double a );
HL_PRIM bool hl_math_isfinite( double a );
HL_PRIM double hl_math_fceil( double d );
HL_PRIM double hl_math_fround( double d );
HL_PRIM double hl_math_ffloor( double d );
HL_PRIM int hl_math_round( double d );
HL_PRIM int hl_math_ceil( double d );
HL_PRIM int hl_math_floor( double d );
HL_PRIM double hl_math_cos( double a );
HL_PRIM double hl_math_sin( double a );
HL_PRIM double hl_math_tan( double a );
HL_PRIM double hl_math_acos( double a );
HL_PRIM double hl_math_asin( double a );
HL_PRIM double hl_math_atan( double a );
HL_PRIM double hl_math_atan2( double a, double b );
HL_PRIM double hl_math_pow( double a, double b );
HL_PRIM double hl_math_log( double a );
HL_PRIM double hl_math_exp( double a );
HL_PRIM double hl_math_sqrt( double a );

DECLARE_PRIM(nan);
DECLARE_PRIM(math_abs);
DECLARE_PRIM(math_isnan);
DECLARE_PRIM(math_isfinite);
DECLARE_PRIM(math_fceil);
DECLARE_PRIM(math_fround);
DECLARE_PRIM(math_ffloor);
DECLARE_PRIM(math_round);
DECLARE_PRIM(math_ceil);
DECLARE_PRIM(math_floor);
DECLARE_PRIM(math_cos);
DECLARE_PRIM(math_sin);
DECLARE_PRIM(math_tan);
DECLARE_PRIM(math_acos);
DECLARE_PRIM(math_asin);
DECLARE_PRIM(math_atan);
DECLARE_PRIM(math_atan2);
DECLARE_PRIM(math_pow);
DECLARE_PRIM(math_log);
DECLARE_PRIM(math_exp);
DECLARE_PRIM(math_sqrt);

#endif

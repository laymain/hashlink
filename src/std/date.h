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
#ifndef DATE_H
#define DATE_H

#include <hl.h>

HL_PRIM int hl_date_now();
HL_PRIM vbyte *hl_date_to_string( int date, int *len );
HL_PRIM double hl_date_get_time( int date );
HL_PRIM int hl_date_from_time( double time );
HL_PRIM int hl_date_from_string( vbyte *b, int len );
HL_PRIM int hl_date_new( int y, int mo, int d, int h, int m, int s );
HL_PRIM void hl_date_get_inf( int date, int *y, int *mo, int *day, int *h, int *m, int *s, int *wday );
HL_PRIM void hl_date_get_utc_inf( int date, int *y, int *mo, int *day, int *h, int *m, int *s, int *wday );

DECLARE_PRIM(date_now);
DECLARE_PRIM(date_to_string);
DECLARE_PRIM(date_get_time);
DECLARE_PRIM(date_from_time);
DECLARE_PRIM(date_from_string);
DECLARE_PRIM(date_new);
DECLARE_PRIM(date_get_inf);
DECLARE_PRIM(date_get_utc_inf);

#endif

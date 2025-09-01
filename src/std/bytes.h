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
#ifndef BYTES_H
#define BYTES_H

#include <hl.h>

HL_PRIM vbyte *hl_alloc_bytes( int size );
HL_PRIM vbyte *hl_copy_bytes( const vbyte *ptr, int size );
HL_PRIM void hl_bytes_blit( char *dst, int dpos, char *src, int spos, int len );
HL_PRIM int hl_bytes_compare( vbyte *a, int apos, vbyte *b, int bpos, int len );
HL_PRIM int hl_bytes_compare16( vbyte *a, vbyte *b, int len );
HL_PRIM int hl_bytes_find( vbyte *where, int pos, int len, vbyte *which, int wpos, int wlen );
HL_PRIM int hl_bytes_rfind( vbyte *where, int len, vbyte *which, int wlen );
HL_PRIM void hl_bytes_fill( vbyte *bytes, int pos, int len, int value );
HL_PRIM void hl_bsort_i32( vbyte *bytes, int pos, int len, vclosure *cmp );
HL_PRIM void hl_bsort_f64( vbyte *bytes, int pos, int len, vclosure *cmp );
HL_PRIM double hl_parse_float( vbyte *bytes, int pos, int len );
HL_PRIM vdynamic *hl_parse_int( vbyte *bytes, int pos, int len );
HL_PRIM vbyte *hl_bytes_offset( vbyte *src, int offset );
HL_PRIM int hl_bytes_subtract( vbyte *a, vbyte *b );
HL_PRIM int_val hl_bytes_address64( vbyte *a );
HL_PRIM int hl_bytes_address( vbyte *a, int *high );
HL_PRIM vbyte *hl_bytes_from_address( int low, int high );
HL_PRIM vbyte *hl_bytes_from_address64( int_val v );
HL_PRIM int hl_string_compare( vbyte *a, vbyte *b, int len );

DECLARE_PRIM(alloc_bytes);
DECLARE_PRIM(bytes_blit);
DECLARE_PRIM(bytes_compare);
DECLARE_PRIM(bytes_compare16);
DECLARE_PRIM(string_compare);
DECLARE_PRIM(bytes_find);
DECLARE_PRIM(bytes_rfind);
DECLARE_PRIM(bytes_fill);
DECLARE_PRIM(parse_float);
DECLARE_PRIM(parse_int);
DECLARE_PRIM(bsort_i32);
DECLARE_PRIM(bsort_f64);
DECLARE_PRIM(bytes_offset);
DECLARE_PRIM(bytes_subtract);
DECLARE_PRIM(bytes_address);
DECLARE_PRIM(bytes_from_address);
DECLARE_PRIM(bytes_address64);
DECLARE_PRIM(bytes_from_address64);

#endif

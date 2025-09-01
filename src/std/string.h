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
#ifndef STRING_H
#define STRING_H

#include <hl.h>

HL_PRIM vbyte *hl_itos( int i, int *len );
HL_PRIM vbyte *hl_ftos( double d, int *len );
HL_PRIM vbyte *hl_value_to_string( vdynamic *d, int *len );
HL_PRIM int hl_ucs2length( vbyte *str, int pos );
HL_PRIM int hl_utf8_length( const vbyte *s, int pos );
HL_PRIM int hl_from_utf8( uchar *out, int outLen, const char *str );
HL_PRIM uchar *hl_to_utf16( const char *str );
HL_PRIM vbyte* hl_utf8_to_utf16( vbyte *str, int pos, int *size );
HL_PRIM vbyte* hl_ucs2_upper( vbyte *str, int pos, int len );
HL_PRIM vbyte* hl_ucs2_lower( vbyte *str, int pos, int len );
HL_PRIM vbyte *hl_utf16_to_utf8( vbyte *str, int len, int *size );
HL_PRIM char *hl_to_utf8( const uchar *bytes );
HL_PRIM vbyte *hl_url_encode( vbyte *str, int *len );
HL_PRIM vbyte *hl_url_decode( vbyte *str, int *len );

DECLARE_PRIM(itos);
DECLARE_PRIM(ftos);
DECLARE_PRIM(value_to_string);
DECLARE_PRIM(ucs2length);
DECLARE_PRIM(utf8_to_utf16);
DECLARE_PRIM(utf16_to_utf8);
DECLARE_PRIM(ucs2_upper);
DECLARE_PRIM(ucs2_lower);
DECLARE_PRIM(url_encode);
DECLARE_PRIM(url_decode);

#endif

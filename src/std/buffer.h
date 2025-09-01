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
#ifndef BUFFER_H
#define BUFFER_H

#include <hl.h>

typedef struct _stringitem {
	uchar *str;
	int size;
	int len;
	struct _stringitem *next;
} * stringitem;

struct hl_buffer {
	int totlen;
	int blen;
	stringitem data;
};

HL_PRIM hl_buffer *hl_alloc_buffer();
HL_PRIM void hl_buffer_str_sub( hl_buffer *b, const uchar *s, int len );
HL_PRIM void hl_buffer_str( hl_buffer *b, const uchar *s );
HL_PRIM void hl_buffer_cstr( hl_buffer *b, const char *s );
HL_PRIM void hl_buffer_char( hl_buffer *b, uchar c );
HL_PRIM uchar *hl_buffer_content( hl_buffer *b, int *len );
HL_PRIM void hl_buffer_val( hl_buffer *b, vdynamic *v );
HL_PRIM uchar *hl_to_string( vdynamic *v );

#endif

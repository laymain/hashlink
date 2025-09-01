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
#ifndef REGEXP_H
#define REGEXP_H

#include <hl.h>
#define PCRE2_STATIC
#include <pcre2.h>

typedef struct _ereg ereg;

struct _ereg {
	void (*finalize)( ereg * );
	/* The compiled regex code */
	pcre2_code *regex;
	/* Pointer to the allocated memory for match data */
	pcre2_match_data *match_data;
	/* Number of capture groups */
	int n_groups;
	/* Whether the last string was matched successfully */
	bool matched;
};

HL_PRIM ereg *hl_regexp_new_options( vbyte *str, vbyte *opts );
HL_PRIM int hl_regexp_matched_pos( ereg *e, int m, int *len );
HL_PRIM int hl_regexp_matched_num( ereg *e );
HL_PRIM bool hl_regexp_match( ereg *e, vbyte *s, int pos, int len );

DECLARE_PRIM(regexp_new_options);
DECLARE_PRIM(regexp_matched_pos);
DECLARE_PRIM(regexp_matched_num);
DECLARE_PRIM(regexp_match);

#endif

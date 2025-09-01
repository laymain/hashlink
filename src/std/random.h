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
#ifndef RANDOM_H
#define RANDOM_H

#include <hl.h>

#define NSEEDS	25

typedef struct _rnd rnd;

struct _rnd {
	unsigned long seeds[NSEEDS];
	unsigned long cur;
};

HL_PRIM rnd *hl_rnd_alloc();
HL_PRIM void hl_rnd_set_seed( rnd *r, int s );
HL_PRIM rnd *hl_rnd_init_system();
HL_PRIM unsigned int hl_rnd_int( rnd *r );
HL_PRIM double hl_rnd_float( rnd *r );

DECLARE_PRIM(rnd_alloc);
DECLARE_PRIM(rnd_init_system);
DECLARE_PRIM(rnd_set_seed);
DECLARE_PRIM(rnd_int);
DECLARE_PRIM(rnd_float);

#endif

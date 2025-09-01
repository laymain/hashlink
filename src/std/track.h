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
#ifndef TRACK_H
#define TRACK_H

#include <hl.h>

HL_PRIM void hl_track_init();
HL_PRIM void hl_track_lock( bool lock );
HL_PRIM int hl_track_count( int *depth );
HL_PRIM int hl_track_entry( int id, hl_type **t, int *count, int *info, varray *stack );
HL_PRIM int hl_track_get_bits( bool thread );
HL_PRIM void hl_track_set_depth( int d );
HL_PRIM void hl_track_set_bits( int flags, bool thread );
HL_PRIM void hl_track_reset();

DECLARE_PRIM(track_init);
DECLARE_PRIM(track_count);
DECLARE_PRIM(track_entry);
DECLARE_PRIM(track_lock);
DECLARE_PRIM(track_set_depth);
DECLARE_PRIM(track_get_bits);
DECLARE_PRIM(track_set_bits);
DECLARE_PRIM(track_reset);

#endif

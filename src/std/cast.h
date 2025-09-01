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
#ifndef CAST_H
#define CAST_H

#include <hl.h>

HL_PRIM vdynamic *hl_make_dyn( void *data, hl_type *t );
HL_PRIM int hl_dyn_casti( void *data, hl_type *t, hl_type *to );
HL_PRIM int64 hl_dyn_casti64( void *data, hl_type *t );
HL_PRIM void *hl_dyn_castp( void *data, hl_type *t, hl_type *to );
HL_PRIM double hl_dyn_castd( void *data, hl_type *t );
HL_PRIM float hl_dyn_castf( void *data, hl_type *t );
HL_PRIM int hl_ptr_compare( vdynamic *a, vdynamic *b );
HL_PRIM int hl_dyn_compare( vdynamic *a, vdynamic *b );
HL_PRIM void hl_write_dyn( void *data, hl_type *t, vdynamic *v, bool is_tmp );
HL_PRIM vdynamic* hl_value_cast( vdynamic *v, hl_type *t );
HL_PRIM bool hl_type_safe_cast( hl_type *a, hl_type *b );
HL_PRIM vdynamic *hl_dyn_op( int op, vdynamic *a, vdynamic *b );

DECLARE_PRIM(dyn_compare);
DECLARE_PRIM(value_cast);
DECLARE_PRIM(type_safe_cast);
DECLARE_PRIM(dyn_op);
DECLARE_PRIM(ptr_compare);

#endif

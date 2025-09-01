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
#ifndef TYPES_H
#define TYPES_H

#include <hl.h>

HL_PRIM hl_type hlt_array = { HARRAY };
HL_PRIM hl_type hlt_bytes = { HBYTES };
HL_PRIM hl_type hlt_dynobj = { HDYNOBJ };
HL_PRIM hl_type hlt_dyn = { HDYN };
HL_PRIM hl_type hlt_i32 = { HI32 };
HL_PRIM hl_type hlt_i64 = { HI64 };
HL_PRIM hl_type hlt_f32 = { HF32 };
HL_PRIM hl_type hlt_f64 = { HF64 };
HL_PRIM hl_type hlt_void = { HVOID };
HL_PRIM hl_type hlt_bool = { HBOOL };
HL_PRIM hl_type hlt_abstract = { HABSTRACT, {USTR("<abstract>")} };

HL_PRIM int hl_type_size( hl_type *t );
HL_PRIM int hl_pad_struct( int size, hl_type *t );
HL_PRIM bool hl_same_type( hl_type *a, hl_type *b );
HL_PRIM bool hl_is_dynamic( hl_type *t );
HL_PRIM bool hl_safe_cast( hl_type *t, hl_type *to );
HL_PRIM const uchar *hl_type_str( hl_type *t );
HL_PRIM vbyte* hl_type_name( hl_type *t );
HL_PRIM int hl_mark_size( int data_size );
HL_PRIM void hl_init_enum( hl_type *et, hl_module_context *m );
HL_PRIM varray* hl_type_enum_fields( hl_type *t );
HL_PRIM varray* hl_type_enum_values( hl_type *t );
HL_PRIM int hl_type_args_count( hl_type *t );
HL_PRIM varray *hl_type_instance_fields( hl_type *t );
HL_PRIM hl_type *hl_type_super( hl_type *t );
HL_PRIM vdynamic *hl_type_get_global( hl_type *t );
HL_PRIM bool hl_type_set_global( hl_type *t, vdynamic *v );
HL_PRIM bool hl_type_enum_eq( venum *a, venum *b );
HL_PRIM venum *hl_alloc_enum( hl_type *t, int index );
HL_PRIM venum *hl_alloc_enum_dyn( hl_type *t, int index, varray *args, int nargs );
HL_PRIM varray *hl_enum_parameters( venum *e );
HL_PRIM uchar *hl_guid_str( int64 guid, uchar buf[14] );
HL_PRIM void hl_register_guid_name( int64 guid, vbyte *name );
HL_PRIM vdynamic *hl_mem_compact( vdynamic *d, varray *exclude, int flags, int *outCount );

DECLARE_PRIM(type_str);
DECLARE_PRIM(type_name);
DECLARE_PRIM(type_args_count);
DECLARE_PRIM(type_instance_fields);
DECLARE_PRIM(type_super);
DECLARE_PRIM(type_get_global);
DECLARE_PRIM(type_enum_fields);
DECLARE_PRIM(type_enum_values);
DECLARE_PRIM(type_enum_eq);
DECLARE_PRIM(alloc_enum_dyn);
DECLARE_PRIM(enum_parameters);
DECLARE_PRIM(type_set_global);
DECLARE_PRIM(register_guid_name);
DECLARE_PRIM(mem_compact);

#endif

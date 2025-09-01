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
#ifndef OBJ_H
#define OBJ_H

#include <hl.h>

HL_PRIM hl_field_lookup *hl_lookup_insert( hl_field_lookup *l, int size, int hash, hl_type *t, int index );
HL_PRIM hl_field_lookup *hl_lookup_find( hl_field_lookup *l, int size, int hash );
HL_PRIM int hl_hash( vbyte *b );
HL_PRIM int hl_hash_utf8( const char *name );
HL_PRIM int hl_hash_gen( const uchar *name, bool cache_name );
HL_PRIM vbyte *hl_field_name( int hash );
HL_PRIM void hl_cache_free();
HL_PRIM hl_obj_field *hl_obj_field_fetch( hl_type *t, int fid );
HL_PRIM int hl_mark_size( int data_size );
HL_PRIM hl_runtime_obj *hl_get_obj_rt( hl_type *ot );
HL_PRIM int hl_dyn_geti( vdynamic *d, int hfield, hl_type *t );
HL_PRIM int64 hl_dyn_geti64( vdynamic *d, int hfield );
HL_PRIM float hl_dyn_getf( vdynamic *d, int hfield );
HL_PRIM double hl_dyn_getd( vdynamic *d, int hfield );
HL_PRIM void *hl_dyn_getp( vdynamic *d, int hfield, hl_type *t );
HL_PRIM void hl_dyn_seti( vdynamic *d, int hfield, hl_type *t, int value );
HL_PRIM void hl_dyn_seti64( vdynamic *d, int hfield, int64 value );
HL_PRIM void hl_dyn_setf( vdynamic *d, int hfield, float value );
HL_PRIM void hl_dyn_setd( vdynamic *d, int hfield, double value );
HL_PRIM void hl_dyn_setp( vdynamic *d, int hfield, hl_type *t, void *value );
HL_PRIM vdynamic *hl_obj_get_field( vdynamic *obj, int hfield );
HL_PRIM void hl_obj_set_field( vdynamic *obj, int hfield, vdynamic *v );
HL_PRIM bool hl_obj_has_field( vdynamic *obj, int hfield );
HL_PRIM bool hl_obj_delete_field( vdynamic *obj, int hfield );
HL_PRIM varray *hl_obj_fields( vdynamic *obj );
HL_PRIM vdynamic *hl_obj_copy( vdynamic *obj );
HL_PRIM vdynamic *hl_get_virtual_value( vdynamic *v );

DECLARE_PRIM(alloc_obj);
DECLARE_PRIM(obj_get_field);
DECLARE_PRIM(obj_set_field);
DECLARE_PRIM(obj_has_field);
DECLARE_PRIM(obj_delete_field);
DECLARE_PRIM(obj_fields);
DECLARE_PRIM(obj_copy);
DECLARE_PRIM(get_virtual_value);
DECLARE_PRIM(hash);
DECLARE_PRIM(field_name);

#endif

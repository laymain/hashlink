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
#ifndef FUN_H
#define FUN_H

#include <hl.h>

HL_PRIM vclosure *hl_alloc_closure_void(hl_type *t, void *fvalue);
HL_PRIM vclosure *hl_alloc_closure_ptr(hl_type *fullt, void *fvalue, void *v);
HL_PRIM vdynamic *hl_no_closure(vdynamic *c);
HL_PRIM vdynamic *hl_make_closure(vdynamic *c, vdynamic *v);
HL_PRIM vdynamic *hl_get_closure_value(vdynamic *c);
HL_PRIM bool hl_fun_compare(vdynamic *a, vdynamic *b);
HL_PRIM void hl_setup_callbacks2(void *c, void *w, int flags);
HL_PRIM void hl_setup_callbacks(void *c, void *w);
HL_PRIM vdynamic *hl_call_method(vdynamic *c, varray *args);
HL_PRIM vdynamic *hl_dyn_call(vclosure *c, vdynamic **args, int nargs);
HL_PRIM void *hl_wrapper_call(void *_c, void **args, vdynamic *ret);
HL_PRIM void *hl_dyn_call_obj(vdynamic *o, hl_type *ft, int hfield, void **args, vdynamic *ret);
HL_PRIM vclosure *hl_make_fun_wrapper(vclosure *v, hl_type *to);
HL_PRIM vdynamic *hl_make_var_args(vclosure *c);
HL_PRIM void hl_prim_not_loaded();
HL_PRIM bool hl_is_prim_loaded(vdynamic *f);
HL_PRIM vdynamic *hl_dyn_call_safe(vclosure *c, vdynamic **args, int nargs, bool *isException);

DECLARE_PRIM(no_closure);
DECLARE_PRIM(make_closure);
DECLARE_PRIM(get_closure_value);
DECLARE_PRIM(fun_compare);
DECLARE_PRIM(make_var_args);
DECLARE_PRIM(call_method);
DECLARE_PRIM(is_prim_loaded);

#endif

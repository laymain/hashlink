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
#ifndef ERROR_H
#define ERROR_H

#include <hl.h>

HL_PRIM void *hl_fatal_error( const char *msg, const char *file, int line );
HL_PRIM uchar *hl_resolve_symbol( void *addr, uchar *out, int *outSize );
HL_PRIM void hl_setup_longjump( void *j );
HL_PRIM void hl_setup_exception( void *resolve_symbol, void *capture_stack );
HL_PRIM void hl_set_error_handler( vclosure *d );
HL_PRIM void hl_throw( vdynamic *v );
HL_PRIM void hl_null_access();
HL_PRIM void hl_throw_buffer( hl_buffer *b );
HL_PRIM void hl_dump_stack();
HL_PRIM varray *hl_exception_stack();
HL_PRIM int hl_exception_stack_raw( varray *arr );
HL_PRIM int hl_call_stack_raw( varray *arr );
HL_PRIM void hl_rethrow( vdynamic *v );
HL_PRIM vdynamic *hl_alloc_strbytes( const uchar *fmt, ... );
HL_PRIM void hl_fatal_fmt( const char *file, int line, const char *fmt, ...);
HL_PRIM HL_NO_OPT void hl_breakpoint();
HL_PRIM bool hl_detect_debugger();
HL_PRIM HL_NO_OPT void hl_assert();

DECLARE_PRIM(exception_stack);
DECLARE_PRIM(exception_stack_raw);
DECLARE_PRIM(call_stack_raw);
DECLARE_PRIM(set_error_handler);
DECLARE_PRIM(breakpoint);
DECLARE_PRIM(resolve_symbol);

#endif

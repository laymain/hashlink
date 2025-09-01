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
#ifndef FILE_H
#define FILE_H

#include <hl.h>

typedef struct _hl_fdesc hl_fdesc;
struct _hl_fdesc {
	void (*finalize)( hl_fdesc * );
	FILE *f;
#	ifdef HL_WIN_DESKTOP
	bool is_std;
#	endif
};

HL_PRIM hl_fdesc *hl_file_open( vbyte *name, int mode, bool binary );
HL_PRIM bool hl_file_is_locked( vbyte *name );
HL_PRIM void hl_file_close( hl_fdesc *f );
HL_PRIM int hl_file_write( hl_fdesc *f, vbyte *buf, int pos, int len );
HL_PRIM int hl_file_read( hl_fdesc *f, vbyte *buf, int pos, int len );
HL_PRIM bool hl_file_write_char( hl_fdesc *f, int c );
HL_PRIM int hl_file_read_char( hl_fdesc *f );
HL_PRIM bool hl_file_seek( hl_fdesc *f, int pos, int kind );
HL_PRIM int hl_file_tell( hl_fdesc *f );
HL_PRIM bool hl_file_seek2( hl_fdesc *f, double pos, int kind );
HL_PRIM double hl_file_tell2( hl_fdesc *f );
HL_PRIM bool hl_file_eof( hl_fdesc *f );
HL_PRIM int hl_file_error_code();
HL_PRIM bool hl_file_flush( hl_fdesc *f );
HL_PRIM hl_fdesc *hl_file_std();
HL_PRIM vbyte *hl_file_contents( vbyte *name, int *size );

DECLARE_PRIM(file_open);
DECLARE_PRIM(file_close);
DECLARE_PRIM(file_write);
DECLARE_PRIM(file_read);
DECLARE_PRIM(file_write_char);
DECLARE_PRIM(file_read_char);
DECLARE_PRIM(file_seek);
DECLARE_PRIM(file_tell);
DECLARE_PRIM(file_seek2);
DECLARE_PRIM(file_tell2);
DECLARE_PRIM(file_eof);
DECLARE_PRIM(file_flush);
DECLARE_PRIM(file_stdin);
DECLARE_PRIM(file_stdout);
DECLARE_PRIM(file_stderr);
DECLARE_PRIM(file_contents);
DECLARE_PRIM(file_is_locked);
DECLARE_PRIM(file_error_code);

#endif

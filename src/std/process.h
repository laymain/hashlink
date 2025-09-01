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
#ifndef PROCESS_H
#define PROCESS_H

#include <hl.h>

typedef struct _vprocess vprocess;

struct _vprocess {
	void (*finalize)( vprocess * );
#ifdef HL_WIN
	HANDLE oread;
	HANDLE eread;
	HANDLE iwrite;
	PROCESS_INFORMATION pinf;
#else
	int oread;
	int eread;
	int iwrite;
	int pid;
#endif
};

HL_PRIM vprocess *hl_process_run( vbyte *cmd, varray *vargs, bool detached );
HL_PRIM int hl_process_stdout_read( vprocess *p, vbyte *str, int pos, int len );
HL_PRIM int hl_process_stderr_read( vprocess *p, vbyte *str, int pos, int len );
HL_PRIM int hl_process_stdin_write( vprocess *p, vbyte *str, int pos, int len );
HL_PRIM bool hl_process_stdin_close( vprocess *p );
HL_PRIM int hl_process_exit( vprocess *p, bool *running );
HL_PRIM int hl_process_pid( vprocess *p );
HL_PRIM void hl_process_close( vprocess *p );
HL_PRIM void hl_process_kill( vprocess *p );

DECLARE_PRIM(process_run);
DECLARE_PRIM(process_stdout_read);
DECLARE_PRIM(process_stderr_read);
DECLARE_PRIM(process_stdin_close);
DECLARE_PRIM(process_stdin_write);
DECLARE_PRIM(process_exit);
DECLARE_PRIM(process_pid);
DECLARE_PRIM(process_close);
DECLARE_PRIM(process_kill);

#endif

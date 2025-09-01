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
#ifndef THREAD_H
#define THREAD_H

#include <hl.h>

typedef struct _hl_semaphore hl_semaphore;
typedef struct _hl_condition hl_condition;

#if !defined(HL_THREADS)

struct _hl_mutex {
	void (*free)( hl_mutex * );
	void *_unused;
};

struct _hl_semaphore {
  void (*free)(hl_semaphore *);
};

struct _hl_condition {
  void (*free)(hl_condition *);
};

struct _hl_tls {
	void (*free)( hl_tls * );
	void *value;
};

#elif defined(HL_WIN)

struct _hl_mutex {
	void (*free)( hl_mutex * );
	CRITICAL_SECTION cs;
	bool is_gc;
};

struct _hl_semaphore {
	void (*free)(hl_semaphore *);
	HANDLE sem;
};

struct _hl_condition {
	void (*free)(hl_condition *);
	CRITICAL_SECTION cs;
	CONDITION_VARIABLE cond;
};

struct _hl_tls {
	void (*free)( hl_tls * );
	DWORD tid;
	bool gc;
};

#else

#	include <pthread.h>
#	include <unistd.h>
#	include <sys/syscall.h>
#	include <sys/time.h>

#ifdef __APPLE__
#include <dispatch/dispatch.h>
#else
#include <semaphore.h>
#endif

struct _hl_mutex {
	void (*free)( hl_mutex * );
	pthread_mutex_t lock;
	bool is_gc;
};

struct _hl_semaphore {
	void (*free)(hl_semaphore *);
#	ifdef __APPLE__
	dispatch_semaphore_t sem;
#	else
	sem_t sem;
#endif
};

struct _hl_condition {
	void (*free)(hl_condition *);
	pthread_mutex_t mutex;
	pthread_cond_t cond;
};

struct _hl_tls {
	void (*free)( hl_tls * );
	pthread_key_t key;
	bool gc;
};

#endif

typedef struct _tqueue {
	vdynamic *msg;
	struct _tqueue *next;
} tqueue;

struct _hl_deque;
typedef struct _hl_deque hl_deque;

struct _hl_deque {
	void (*free)( hl_deque * );
	tqueue *first;
	tqueue *last;
#ifdef HL_THREADS
#	ifdef HL_WIN
	CRITICAL_SECTION lock;
	HANDLE wait;
#	else
	pthread_mutex_t lock;
	pthread_cond_t wait;
#	endif
#endif
};

struct _hl_lock;
typedef struct _hl_lock hl_lock;

struct _hl_lock {
	void (*free)( hl_lock * );
#if !defined(HL_THREADS)
	int counter;
#elif defined(HL_WIN)
	HANDLE wait;
#else
	pthread_mutex_t lock;
	pthread_cond_t wait;
	int counter;
#endif
};

HL_PRIM hl_mutex *hl_mutex_alloc( bool gc_thread );
HL_PRIM void hl_mutex_acquire( hl_mutex *l );
HL_PRIM bool hl_mutex_try_acquire( hl_mutex *l );
HL_PRIM void hl_mutex_release( hl_mutex *l );
HL_PRIM void hl_mutex_free( hl_mutex *l );
HL_PRIM hl_semaphore *hl_semaphore_alloc(int value);
HL_PRIM void hl_semaphore_acquire(hl_semaphore *sem);
HL_PRIM bool hl_semaphore_try_acquire(hl_semaphore *sem, vdynamic *timeout);
HL_PRIM void hl_semaphore_release(hl_semaphore *sem);
HL_PRIM void hl_semaphore_free(hl_semaphore *sem);
HL_PRIM hl_condition *hl_condition_alloc();
HL_PRIM void hl_condition_acquire(hl_condition *cond);
HL_PRIM bool hl_condition_try_acquire(hl_condition *cond);
HL_PRIM void hl_condition_release(hl_condition *cond);
HL_PRIM void hl_condition_wait(hl_condition *cond);
HL_PRIM bool hl_condition_timed_wait(hl_condition *cond, double timeout);
HL_PRIM void hl_condition_signal(hl_condition *cond);
HL_PRIM void hl_condition_broadcast(hl_condition *cond);
HL_PRIM void hl_condition_free(hl_condition *cond);
HL_PRIM hl_tls *hl_tls_alloc( bool gc_value );
HL_PRIM void hl_tls_free( hl_tls *l );
HL_PRIM void hl_tls_set( hl_tls *l, void *v );
HL_PRIM void *hl_tls_get( hl_tls *l );
HL_PRIM hl_deque *hl_deque_alloc();
HL_PRIM void hl_deque_add( hl_deque *q, vdynamic *msg );
HL_PRIM void hl_deque_push( hl_deque *q, vdynamic *msg );
HL_PRIM vdynamic *hl_deque_pop( hl_deque *q, bool block );
HL_PRIM hl_lock *hl_lock_create();
HL_PRIM void hl_lock_release( hl_lock *l );
HL_PRIM bool hl_lock_wait( hl_lock *l, vdynamic *timeout );
HL_PRIM hl_thread *hl_thread_current();
HL_PRIM void hl_thread_yield();
HL_PRIM int hl_thread_id();
HL_PRIM hl_thread *hl_thread_start( void *callback, void *param, bool withGC );
HL_PRIM hl_thread *hl_thread_create( vclosure *c );
HL_PRIM int hl_get_thread_id( hl_thread *t );
HL_PRIM void hl_thread_set_name( hl_thread *t, const char *name );
HL_PRIM vbyte *hl_thread_get_name( hl_thread *t );
HL_PRIM int hl_atomic_add32(int *a, int b);
HL_PRIM int hl_atomic_sub32(int *a, int b);
HL_PRIM int hl_atomic_and32(int *a, int b);
HL_PRIM int hl_atomic_or32(int *a, int b);
HL_PRIM int hl_atomic_xor32(int *a, int b);
HL_PRIM int hl_atomic_compare_exchange32(int *a, int expected, int replacement);
HL_PRIM void *hl_atomic_compare_exchange_ptr(void **a, void *expected, void *replacement);
HL_PRIM int hl_atomic_exchange32(int *a, int replacement);
HL_PRIM void *hl_atomic_exchange_ptr(void **a, void *replacement);
HL_PRIM int hl_atomic_load32(int *a);
HL_PRIM void *hl_atomic_load_ptr(void **a);
HL_PRIM int hl_atomic_store32(int *a, int value);
HL_PRIM void *hl_atomic_store_ptr(void **a, void *value);

DECLARE_PRIM(mutex_alloc);
DECLARE_PRIM(mutex_acquire);
DECLARE_PRIM(mutex_try_acquire);
DECLARE_PRIM(mutex_release);
DECLARE_PRIM(mutex_free);
DECLARE_PRIM(semaphore_alloc);
DECLARE_PRIM(semaphore_acquire);
DECLARE_PRIM(semaphore_try_acquire);
DECLARE_PRIM(semaphore_release);
DECLARE_PRIM(semaphore_free);
DECLARE_PRIM(condition_alloc)
DECLARE_PRIM(condition_acquire)
DECLARE_PRIM(condition_try_acquire)
DECLARE_PRIM(condition_release)
DECLARE_PRIM(condition_wait)
DECLARE_PRIM(condition_timed_wait)
DECLARE_PRIM(condition_signal)
DECLARE_PRIM(condition_broadcast)
DECLARE_PRIM(tls_alloc);
DECLARE_PRIM(tls_get);
DECLARE_PRIM(tls_set);
DECLARE_PRIM(deque_alloc);
DECLARE_PRIM(deque_add);
DECLARE_PRIM(deque_push);
DECLARE_PRIM(deque_pop);
DECLARE_PRIM(lock_create);
DECLARE_PRIM(lock_release);
DECLARE_PRIM(lock_wait);
DECLARE_PRIM(thread_current);
DECLARE_PRIM(thread_create);
DECLARE_PRIM(thread_set_name);
DECLARE_PRIM(thread_get_name);
DECLARE_PRIM(atomic_add32)
DECLARE_PRIM(atomic_sub32)
DECLARE_PRIM(atomic_and32)
DECLARE_PRIM(atomic_or32)
DECLARE_PRIM(atomic_xor32)
DECLARE_PRIM(atomic_compare_exchange32)
DECLARE_PRIM(atomic_compare_exchange_ptr)
DECLARE_PRIM(atomic_exchange32)
DECLARE_PRIM(atomic_exchange_ptr)
DECLARE_PRIM(atomic_load32)
DECLARE_PRIM(atomic_load_ptr)
DECLARE_PRIM(atomic_store32)
DECLARE_PRIM(atomic_store_ptr)

#endif

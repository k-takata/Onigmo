#ifndef _STDLIB_H
#define _STDLIB_H

typedef unsigned long size_t;
typedef unsigned long uintptr_t;
typedef unsigned int uint32_t;

#define NULL ((void*)0)

void* malloc(size_t n);
void free(void* p);
void *realloc(void *ptr, size_t size);
void *alloca(size_t size);

#endif

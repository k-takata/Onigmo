#include <stdlib.h>
#include <string.h>

extern unsigned char __heap_base;

unsigned int bump_pointer = (unsigned int)&__heap_base;

// IT LEAKS BY DESIGN; adapted from: https://surma.dev/things/c-to-webassembly/
void* malloc(size_t n) {
  unsigned int r = bump_pointer;
  bump_pointer += 4 + ((n|3)+1);
  size_t *ptr = (size_t *)r;
  *ptr = n;
  return (void *)(ptr + 1);
}

void free(void* p) {
  // lol
}

void *realloc(void *ptr, size_t size) {
  unsigned int cursize = *(int *)(ptr - 4);
  void *newptr = malloc(size);
  memcpy(newptr, ptr, cursize);
  return newptr;
}

//// Adapted from: https://github.com/WebAssembly/wasi-libc / musl

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;
	for (; n; n--) *d++ = *s++;
	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;
  return memcpy(d, s, n);
}

void *memset(void *dest, int c, size_t n)
{
	unsigned char *s = dest;
  for (; n; n--, s++) *s = c;
  return dest;
}

int memcmp(const void *vl, const void *vr, size_t n)
{
	const unsigned char *l=vl, *r=vr;
	for (; n && *l == *r; n--, l++, r++);
	return n ? *l-*r : 0;
}

size_t strlen(const char *s)
{
	const char *a = s;
  for (; *s; s++);
	return s-a;
}

int strncmp(const char *_l, const char *_r, size_t n)
{
	const unsigned char *l=(void *)_l, *r=(void *)_r;
	if (!n--) return 0;
	for (; *l && *r && n && *l == *r ; l++, r++, n--);
	return *l - *r;
}

// Copied from a man page
char *strncpy(char *dest, const char *src, size_t n)
{
  size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];
  for ( ; i < n; i++)
    dest[i] = '\0';

  return dest;
}

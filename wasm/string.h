#ifndef _STRING_H
#define _STRING_H

void *memcpy(void *restrict dest, const void *restrict src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *dest, int c, size_t n);
int memcmp(const void *vl, const void *vr, size_t n);
size_t strlen(const char *s);
int strncmp(const char *_l, const char *_r, size_t n);
char *strncpy(char *dest, const char *src, size_t n);

#endif

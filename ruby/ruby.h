#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include "config.h"
#define RTEST(v)	1
#define rb_raise(a,b,...)
#define rb_warn(a,b)
#define rb_compile_warn(a,b,c,d)
#define rb_thread_check_ints()

#define MEMZERO(p,type,n) memset((p), 0, sizeof(type)*(n))
#define MEMCPY(p1,p2,type,n) memcpy((p1), (p2), sizeof(type)*(n))
#define MEMMOVE(p1,p2,type,n) memmove((p1), (p2), sizeof(type)*(n))
#define MEMCMP(p1,p2,type,n) memcmp((p1), (p2), sizeof(type)*(n))

#define TOLOWER		tolower
//#define STRNCASECMP	_strnicmp
#define ALLOCA_N(t, s)	alloca(sizeof(t)*(s))

enum ruby_special_consts {
    RUBY_SPECIAL_SHIFT  = 8
};

#include "ruby/st.h"

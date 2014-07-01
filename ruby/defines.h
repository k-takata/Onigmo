#ifndef RUBY_DEFINES_H
#define RUBY_DEFINES_H

#define RUBY

#ifndef RUBY_SYMBOL_EXPORT_BEGIN
# define RUBY_SYMBOL_EXPORT_BEGIN /* begin */
# define RUBY_SYMBOL_EXPORT_END   /* end */
#endif

#define xmalloc malloc
#define xcalloc calloc
#define xrealloc realloc
#define xfree(x) free(x)

#endif

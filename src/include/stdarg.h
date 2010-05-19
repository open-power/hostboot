#ifndef __STDARG_H
#define __STDARG_H

#define va_list 	__builtin_va_list
#define va_start(a,b)	__builtin_va_start(a,b)
#define va_arg(a,b) 	__builtin_va_arg(a,b)
#define va_end(a)	__builtin_va_end(a)
#define va_copy(a,b)	__builtin_va_copy(a,b)

#endif

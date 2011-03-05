#ifndef __STDINT_H
#define __STDINT_H

#include <stddef.h>

typedef char 			int8_t;
typedef short int 		int16_t;
typedef int			int32_t;
typedef long int		int64_t;

typedef unsigned char 		uint8_t;
typedef unsigned short int 	uint16_t;
typedef unsigned int	 	uint32_t;
typedef unsigned long int 	uint64_t;

typedef uint64_t 		size_t;
typedef int64_t 		ssize_t;

#define UINT8_MAX	(255U)
#define UINT16_MAX	(65535U)
#define UINT32_MAX	(4294967295U)
#define UINT64_MAX	(18446744073709551615U)

#endif

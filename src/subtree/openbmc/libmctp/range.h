#ifndef _RANGE_H
#define _RANGE_H

#define MIN(a, b)                                                              \
	({                                                                     \
		typeof(a) _a = a;                                              \
		typeof(b) _b = b;                                              \
		_a < _b ? _a : _b;                                             \
	})

#define MAX(a, b)                                                              \
	({                                                                     \
		typeof(a) _a = a;                                              \
		typeof(b) _b = b;                                              \
		_a > _b ? _a : _b;                                             \
	})

#endif

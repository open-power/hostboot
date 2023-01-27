#ifndef _RANGE_H
#define _RANGE_H

#ifndef typeof
#define typeof __typeof__
#endif

#ifndef MIN
#define MIN(a, b)                                                              \
	({                                                                     \
		__typeof__(a) _a = a;                                          \
		__typeof__(b) _b = b;                                          \
		_a < _b ? _a : _b;                                             \
	})
#endif

#ifndef MAX
#define MAX(a, b)                                                              \
	({                                                                     \
		__typeof__(a) _a = a;                                          \
		__typeof__(b) _b = b;                                          \
		_a > _b ? _a : _b;                                             \
	})
#endif

#endif

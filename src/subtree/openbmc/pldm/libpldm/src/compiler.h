/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef PLDM_COMPILER_H
#define PLDM_COMPILER_H

#ifndef __has_attribute
#error The libpldm implementation requires __has_attribute
#endif

#include <assert.h>

static struct {
	static_assert(__has_attribute(always_inline),
		      "`always_inline` attribute is required");
	static_assert(__has_attribute(nonnull),
		      "`nonnull` attribute is required");
	static_assert(__has_attribute(unused),
		      "`unused` attribute is required");
	static_assert(__has_attribute(warn_unused_result),
		      "`warn_unused_result` attribute is required");
	int compliance;
} pldm_required_attributes __attribute__((unused));

#define LIBPLDM_CC_ALWAYS_INLINE      __attribute__((always_inline)) static inline
#define LIBPLDM_CC_NONNULL	      __attribute__((nonnull))
#define LIBPLDM_CC_NONNULL_ARGS(...)  __attribute__((nonnull(__VA_ARGS__)))
#define LIBPLDM_CC_UNUSED	      __attribute__((unused))
#define LIBPLDM_CC_WARN_UNUSED_RESULT __attribute__((warn_unused_result))

// NOLINTBEGIN(bugprone-macro-parentheses)
/**
 * Require that the given object is of the specified type.
 *
 * If the object is not of the required type then a diagnostic will be emitted.
 *
 * If you are reading this documentation due to hitting a compilation error
 * passing through the macro, then you have a type error in your code that must
 * be fixed. Despite the compiler output, the error is _not_ that some array
 * is negatively sized, the array is negatively sized _because_ you have a type
 * error.
 *
 * How this works:
 *
 * If the type of @p obj is not equivalent to the provided type @p type then
 * we force the compiler to evaluate sizeof on a negatively-sized array. The
 * C standard requires that the integer constant expression that specifies
 * the array length must be greater than zero. Failure to meet this constraint
 * generally terminates compilation of the translation unit as any other result
 * cannot be handled in a sensible way. The array size is derived to an integer
 * constant expression from a type eqivalence evaluated using _Generic()
 * allowing us to stay within the language standard. The default generic
 * association, representing a type mismatch, yields -1.
 *
 * pldm_require_obj_type() was introduced into the libpldm implementation to
 * enable use of the pldm_msgbuf_extract*() APIs for objects that may or may not
 * reside in a packed struct. See src/msgbuf.h for more details.
 *
 * @param obj The name of the object to evaluate
 * @param type The required type of @p obj
 *
 * @return The expression either yields 1, or compilation is terminated
 */
#define pldm_require_obj_type(obj, type)                                       \
	((void)(sizeof(                                                        \
		struct { char buf[_Generic((obj), type: 1, default: -1)]; })))
// NOLINTEND(bugprone-macro-parentheses)

#endif

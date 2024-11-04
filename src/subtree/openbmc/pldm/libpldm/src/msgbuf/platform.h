/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef PLDM_MSGBUF_PLATFORM_H
#define PLDM_MSGBUF_PLATFORM_H

#include "../compiler.h"
#include "../msgbuf.h"
#include <libpldm/base.h>
#include <libpldm/platform.h>

LIBPLDM_CC_NONNULL
LIBPLDM_CC_ALWAYS_INLINE int
pldm_msgbuf_extract_value_pdr_hdr(struct pldm_msgbuf *ctx,
				  struct pldm_value_pdr_hdr *hdr, size_t lower,
				  size_t upper)
{
	int rc;

	pldm_msgbuf_extract(ctx, hdr->record_handle);
	pldm_msgbuf_extract(ctx, hdr->version);
	pldm_msgbuf_extract(ctx, hdr->type);
	pldm_msgbuf_extract(ctx, hdr->record_change_num);
	rc = pldm_msgbuf_extract(ctx, hdr->length);
	if (rc) {
		return rc;
	}

	if (hdr->length + sizeof(*ctx) < lower) {
		return -EOVERFLOW;
	}

	if (hdr->length > upper) {
		return -EOVERFLOW;
	}

	return 0;
}

LIBPLDM_CC_ALWAYS_INLINE int
pldm_msgbuf_extract_sensor_data(struct pldm_msgbuf *ctx,
				enum pldm_sensor_readings_data_type tag,
				union_sensor_data_size *dst)
{
	switch (tag) {
	case PLDM_SENSOR_DATA_SIZE_UINT8:
		return pldm_msgbuf_extract(ctx, dst->value_u8);
	case PLDM_SENSOR_DATA_SIZE_SINT8:
		return pldm_msgbuf_extract(ctx, dst->value_s8);
	case PLDM_SENSOR_DATA_SIZE_UINT16:
		return pldm_msgbuf_extract(ctx, dst->value_u16);
	case PLDM_SENSOR_DATA_SIZE_SINT16:
		return pldm_msgbuf_extract(ctx, dst->value_s16);
	case PLDM_SENSOR_DATA_SIZE_UINT32:
		return pldm_msgbuf_extract(ctx, dst->value_u32);
	case PLDM_SENSOR_DATA_SIZE_SINT32:
		return pldm_msgbuf_extract(ctx, dst->value_s32);
	}

	return -PLDM_ERROR_INVALID_DATA;
}

/*
 * This API is bad, but it's because the caller's APIs are also bad. They should
 * have used the approach used by callers of pldm_msgbuf_extract_sensor_data()
 * above
 */
LIBPLDM_CC_ALWAYS_INLINE int
pldm_msgbuf_extract_sensor_value(struct pldm_msgbuf *ctx,
				 enum pldm_sensor_readings_data_type tag,
				 void *val)
{
	switch (tag) {
	case PLDM_SENSOR_DATA_SIZE_UINT8:
		return pldm__msgbuf_extract_uint8(ctx, val);
	case PLDM_SENSOR_DATA_SIZE_SINT8:
		return pldm__msgbuf_extract_int8(ctx, val);
	case PLDM_SENSOR_DATA_SIZE_UINT16:
		return pldm__msgbuf_extract_uint16(ctx, val);
	case PLDM_SENSOR_DATA_SIZE_SINT16:
		return pldm__msgbuf_extract_int16(ctx, val);
	case PLDM_SENSOR_DATA_SIZE_UINT32:
		return pldm__msgbuf_extract_uint32(ctx, val);
	case PLDM_SENSOR_DATA_SIZE_SINT32:
		return pldm__msgbuf_extract_int32(ctx, val);
	}

	return -PLDM_ERROR_INVALID_DATA;
}

#define pldm_msgbuf_extract_range_field_format(ctx, tag, dst)                  \
	pldm_msgbuf_extract_typecheck(union_range_field_format,                \
				      pldm__msgbuf_extract_range_field_format, \
				      dst, ctx, tag, (void *)&(dst))
LIBPLDM_CC_ALWAYS_INLINE int pldm__msgbuf_extract_range_field_format(
	struct pldm_msgbuf *ctx, enum pldm_range_field_format tag, void *rff)
{
	switch (tag) {
	case PLDM_RANGE_FIELD_FORMAT_UINT8:
		return pldm__msgbuf_extract_uint8(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_u8));
	case PLDM_RANGE_FIELD_FORMAT_SINT8:
		return pldm__msgbuf_extract_int8(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_s8));
	case PLDM_RANGE_FIELD_FORMAT_UINT16:
		return pldm__msgbuf_extract_uint16(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_u16));
	case PLDM_RANGE_FIELD_FORMAT_SINT16:
		return pldm__msgbuf_extract_int16(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_s16));
	case PLDM_RANGE_FIELD_FORMAT_UINT32:
		return pldm__msgbuf_extract_uint32(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_u32));
	case PLDM_RANGE_FIELD_FORMAT_SINT32:
		return pldm__msgbuf_extract_int32(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_s32));
	case PLDM_RANGE_FIELD_FORMAT_REAL32:
		return pldm__msgbuf_extract_real32(
			ctx, ((char *)rff) + offsetof(union_range_field_format,
						      value_f32));
	}

	return -PLDM_ERROR_INVALID_DATA;
}

/* This API is bad, but it's because the caller's APIs are also bad */
LIBPLDM_CC_ALWAYS_INLINE int
pldm_msgbuf_extract_effecter_value(struct pldm_msgbuf *ctx,
				   enum pldm_effecter_data_size tag, void *dst)
{
	switch (tag) {
	case PLDM_EFFECTER_DATA_SIZE_UINT8:
		return pldm__msgbuf_extract_uint8(ctx, dst);
	case PLDM_EFFECTER_DATA_SIZE_SINT8:
		return pldm__msgbuf_extract_int8(ctx, dst);
	case PLDM_EFFECTER_DATA_SIZE_UINT16:
		return pldm__msgbuf_extract_uint16(ctx, dst);
	case PLDM_EFFECTER_DATA_SIZE_SINT16:
		return pldm__msgbuf_extract_int16(ctx, dst);
	case PLDM_EFFECTER_DATA_SIZE_UINT32:
		return pldm__msgbuf_extract_uint32(ctx, dst);
	case PLDM_EFFECTER_DATA_SIZE_SINT32:
		return pldm__msgbuf_extract_int32(ctx, dst);
	}

	return -PLDM_ERROR_INVALID_DATA;
}

#define pldm_msgbuf_extract_effecter_data(ctx, tag, dst)                       \
	pldm_msgbuf_extract_typecheck(union_effecter_data_size,                \
				      pldm__msgbuf_extract_range_field_format, \
				      dst, ctx, tag, (void *)&(dst))
LIBPLDM_CC_ALWAYS_INLINE int
pldm__msgbuf_extract_effecter_data(struct pldm_msgbuf *ctx,
				   enum pldm_effecter_data_size tag, void *ed)
{
	switch (tag) {
	case PLDM_EFFECTER_DATA_SIZE_UINT8:
		return pldm__msgbuf_extract_uint8(
			ctx, ((char *)ed) + offsetof(union_effecter_data_size,
						     value_u8));
	case PLDM_EFFECTER_DATA_SIZE_SINT8:
		return pldm__msgbuf_extract_int8(
			ctx, ((char *)ed) + offsetof(union_effecter_data_size,
						     value_s8));
	case PLDM_EFFECTER_DATA_SIZE_UINT16:
		return pldm__msgbuf_extract_uint16(
			ctx, ((char *)ed) + offsetof(union_effecter_data_size,
						     value_u16));
	case PLDM_EFFECTER_DATA_SIZE_SINT16:
		return pldm__msgbuf_extract_int16(
			ctx, ((char *)ed) + offsetof(union_effecter_data_size,
						     value_s16));
	case PLDM_EFFECTER_DATA_SIZE_UINT32:
		return pldm__msgbuf_extract_uint32(
			ctx, ((char *)ed) + offsetof(union_effecter_data_size,
						     value_u32));
	case PLDM_EFFECTER_DATA_SIZE_SINT32:
		return pldm__msgbuf_extract_int32(
			ctx, ((char *)ed) + offsetof(union_effecter_data_size,
						     value_s32));
	}

	return -PLDM_ERROR_INVALID_DATA;
}

#ifdef __cplusplus
#include <type_traits>

template <typename T>
static inline int pldm_msgbuf_typecheck_range_field_format(
	struct pldm_msgbuf *ctx, enum pldm_range_field_format tag, void *_rff)
{
	static_assert(std::is_same<union_range_field_format, T>::value);
	return pldm__msgbuf_extract_range_field_format(ctx, tag, _rff);
}
#endif

#endif

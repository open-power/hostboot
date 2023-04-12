#include <endian.h>

#include <cfloat>

#include <gtest/gtest.h>

/* We're exercising the implementation so disable the asserts for now */
#ifndef NDEBUG
#define NDEBUG 1
#endif

/*
 * Fix up C11's _Static_assert() vs C++'s static_assert().
 *
 * Can we please have nice things for once.
 */
#ifdef __cplusplus
// NOLINTNEXTLINE(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)
#define _Static_assert(...) static_assert(__VA_ARGS__)
#endif

#include "msgbuf.h"

TEST(msgbuf, init_bad_ctx)
{
    EXPECT_NE(pldm_msgbuf_init(NULL, 0, NULL, 0), PLDM_SUCCESS);
}

TEST(msgbuf, init_bad_minsize)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    EXPECT_NE(pldm_msgbuf_init(ctx, sizeof(buf) + 1U, buf, sizeof(buf)),
              PLDM_SUCCESS);
}

TEST(msgbuf, init_bad_buf)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    EXPECT_NE(pldm_msgbuf_init(ctx, 0, NULL, 0), PLDM_SUCCESS);
}

TEST(msgbuf, init_bad_len)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    EXPECT_NE(pldm_msgbuf_init(ctx, sizeof(buf), buf, SIZE_MAX), PLDM_SUCCESS);
}

TEST(msgbuf, init_overflow)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    // This is an intrinsic part of the test.
    // NOLINTNEXTLINE(performance-no-int-to-ptr)
    uint8_t* buf = (uint8_t*)SIZE_MAX;

    EXPECT_NE(pldm_msgbuf_init(ctx, 0, buf, 2), PLDM_SUCCESS);
}

TEST(msgbuf, init_success)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    EXPECT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
}

TEST(msgbuf, destroy_none)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, destroy_exact)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, 0xa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, destroy_over)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    ASSERT_EQ(pldm_msgbuf_extract_uint8(ctx, &val), PLDM_SUCCESS);
    ASSERT_EQ(val, 0xa5);
    EXPECT_NE(pldm_msgbuf_extract_uint8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, destroy_under)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[2] = {0x5a, 0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, 0x5a);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_one_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, 0xa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_uint8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, extract_one_int8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t buf[1] = {-1};
    int8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_int8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, -1);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_int8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t buf[1] = {};
    int8_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_int8(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, extract_one_uint16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t buf[1] = {htole16(0x5aa5)};
    uint16_t val = {};

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, 0x5aa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_uint16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t buf[1] = {};
    uint16_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_uint16(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, extract_one_int16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t buf[1] = {(int16_t)(htole16((uint16_t)INT16_MIN))};
    int16_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_int16(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, INT16_MIN);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_int16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t buf[1] = {};
    int16_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_int16(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, extract_one_uint32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {htole32(0x5a00ffa5)};
    uint32_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_uint32(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, 0x5a00ffa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_uint32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {};
    uint32_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_uint32(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, extract_one_int32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t buf[1] = {(int32_t)(htole32((uint32_t)(INT32_MIN)))};
    int32_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_int32(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, INT32_MIN);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_int32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t buf[1] = {};
    int32_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_int32(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

TEST(msgbuf, extract_one_real32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {};
    uint32_t xform;
    real32_t val;

    val = FLT_MAX;
    memcpy(&xform, &val, sizeof(val));
    buf[0] = htole32(xform);
    val = 0;

    ASSERT_EQ(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)),
              PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_extract_real32(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(val, FLT_MAX);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_SUCCESS);
}

TEST(msgbuf, extract_over_real32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    real32_t buf[1] = {};
    real32_t val;

    ASSERT_EQ(pldm_msgbuf_init(ctx, 0, buf, 0), PLDM_SUCCESS);
    EXPECT_NE(pldm_msgbuf_extract_real32(ctx, &val), PLDM_SUCCESS);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), PLDM_ERROR_INVALID_LENGTH);
}

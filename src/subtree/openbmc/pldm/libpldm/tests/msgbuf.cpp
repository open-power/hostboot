#include <endian.h>
#include <libpldm/utils.h>

#include <cfloat>

#include <gtest/gtest.h>

/* We're exercising the implementation so disable the asserts for now */
#ifndef NDEBUG
#define NDEBUG 1
#endif

#include "msgbuf.h"

TEST(msgbuf, init_bad_minsize)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    EXPECT_NE(pldm_msgbuf_init_errno(ctx, sizeof(buf) + 1U, buf, sizeof(buf)),
              0);
}

TEST(msgbuf, init_bad_len)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    EXPECT_NE(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, SIZE_MAX), 0);
}

TEST(msgbuf, init_overflow)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    // NOLINTNEXTLINE(performance-no-int-to-ptr)
    void* buf = (void*)UINTPTR_MAX;

    EXPECT_NE(pldm_msgbuf_init_errno(ctx, 0, buf, 2), 0);
}

TEST(msgbuf, init_success)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    EXPECT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
}

TEST(msgbuf, destroy_none)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, destroy_exact)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(val, 0xa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, destroy_over)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    ASSERT_EQ(pldm_msgbuf_extract_uint8(ctx, val), 0);
    ASSERT_EQ(val, 0xa5);
    EXPECT_NE(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, destroy_under)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[2] = {0x5a, 0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(val, 0x5a);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_one_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(val, 0xa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_over_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint8_t buf[1] = {};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_one_int8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t buf[1] = {-1};
    int8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_int8(ctx, val), 0);
    EXPECT_EQ(val, -1);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_over_int8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t buf[1] = {};
    int8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_int8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_int8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint8_t buf[1] = {};
    int8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_extract_int8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_one_uint16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t buf[1] = {htole16(0x5aa5)};
    uint16_t val = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctx, val), 0);
    EXPECT_EQ(val, 0x5aa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_under_uint16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint16_t buf[1] = {};
    uint16_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_extract_uint16(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_over_uint16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t buf[1] = {};
    uint16_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_uint16(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_one_int16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t buf[1] = {(int16_t)(htole16((uint16_t)INT16_MIN))};
    int16_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_int16(ctx, val), 0);
    EXPECT_EQ(val, INT16_MIN);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_over_int16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t buf[1] = {};
    int16_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_int16(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_int16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    int16_t buf[1] = {};
    int16_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_extract_int16(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_one_uint32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {htole32(0x5a00ffa5)};
    uint32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint32(ctx, val), 0);
    EXPECT_EQ(val, 0x5a00ffa5);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_over_uint32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {};
    uint32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_uint32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_uint32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint32_t buf[1] = {};
    uint32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_extract_uint32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_one_int32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t buf[1] = {(int32_t)(htole32((uint32_t)(INT32_MIN)))};
    int32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_int32(ctx, val), 0);
    EXPECT_EQ(val, INT32_MIN);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_over_int32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t buf[1] = {};
    int32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_int32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_int32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    int32_t buf[1] = {};
    int32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_extract_int32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
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

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_real32(ctx, val), 0);
    EXPECT_EQ(val, FLT_MAX);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_over_real32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    real32_t buf[1] = {};
    real32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_NE(pldm_msgbuf_extract_real32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_real32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    real32_t buf[1] = {};
    real32_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_extract_real32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_array_uint8_buf0_req0)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t arr[1];

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_EQ(pldm_msgbuf_extract_array_uint8(ctx, 0, arr, 0), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_array_uint8_buf1_req1)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t arr[1];

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_extract_array_uint8(ctx, sizeof(arr), arr, sizeof(arr)), 0);
    EXPECT_EQ(arr[0], 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_array_uint8_buf1_req2)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t arr[2];

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_NE(
        pldm_msgbuf_extract_array_uint8(ctx, sizeof(arr), arr, sizeof(arr)), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_array_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t arr[1];

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_extract_array_uint8(ctx, 1, arr, 1), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_array_char_buf0_req0)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    char buf[1] = {'\0'};
    char arr[1] = {'1'};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    EXPECT_EQ(pldm_msgbuf_extract_array_char(ctx, 0, arr, 0), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_array_char_buf1_req1)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    char buf[1] = {'\0'};
    char arr[1] = {'1'};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_extract_array_char(ctx, sizeof(arr), arr, sizeof(arr)), 0);
    EXPECT_EQ(arr[0], '\0');
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, extract_array_char_buf1_req2)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    char buf[1] = {'\0'};
    char arr[2] = {'1', '2'};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_NE(
        pldm_msgbuf_extract_array_char(ctx, sizeof(arr), arr, sizeof(arr)), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, extract_under_array_char)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    char buf[1] = {'\0'};
    char arr[1] = {'1'};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_extract_array_char(ctx, 1, arr, 1), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, consumed_under)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_destroy_consumed(ctx), -EBADMSG);
}

TEST(msgbuf, consumed_exact)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t val;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy_consumed(ctx), 0);
}

TEST(msgbuf, consumed_over)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {};
    uint8_t valid;
    uint8_t invalid;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctx, valid), 0);
    EXPECT_NE(pldm_msgbuf_extract_uint8(ctx, invalid), 0);
    EXPECT_EQ(pldm_msgbuf_destroy_consumed(ctx), -EBADMSG);
}

TEST(msgbuf, pldm_msgbuf_insert_int32_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t src = -12345;
    int32_t checkVal = 0;
    uint8_t buf[sizeof(int32_t)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_int32(ctx, src), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_int32(ctxExtract, checkVal), 0);

    EXPECT_EQ(src, checkVal);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_int32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    int32_t buf[1] = {};
    int32_t val = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_int32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_uint32_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t src = 0xf1223344;
    uint32_t checkVal = 0;
    uint8_t buf[sizeof(uint32_t)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_uint32(ctx, src), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint32(ctxExtract, checkVal), 0);

    EXPECT_EQ(src, checkVal);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_uint32)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint32_t buf[1] = {};
    uint32_t val = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_uint32(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_uint16_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t src = 0xf344;
    uint16_t checkVal = 0;
    uint8_t buf[sizeof(uint16_t)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(uint16_t)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_uint16(ctx, src), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, checkVal), 0);

    EXPECT_EQ(src, checkVal);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_uint16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint16_t buf[1] = {};
    uint16_t val = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_uint16(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_int16_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t src = -12;
    int16_t checkVal = 0;
    uint8_t buf[sizeof(int16_t)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(uint16_t)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_int16(ctx, src), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_int16(ctxExtract, checkVal), 0);

    EXPECT_EQ(src, checkVal);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_int16)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    int16_t buf[1] = {};
    int16_t val = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_int16(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_uint8_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src = 0xf4;
    uint8_t checkVal = 0;
    uint8_t buf[sizeof(uint8_t)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_uint8(ctx, src), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctxExtract, checkVal), 0);

    EXPECT_EQ(src, checkVal);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint8_t buf[1] = {};
    uint8_t val = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_uint8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_int8_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t src = -4;
    int8_t checkVal = 0;
    uint8_t buf[sizeof(int8_t)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_int8(ctx, src), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_int8(ctxExtract, checkVal), 0);

    EXPECT_EQ(src, checkVal);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_int8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    int8_t buf[1] = {};
    int8_t val = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_int8(ctx, val), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_array_uint8_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src[6] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77};
    uint8_t buf[6] = {};
    uint8_t retBuff[6] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_insert_array_uint8(ctx, sizeof(src), src, sizeof(src)), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_array_uint8(ctxExtract, sizeof(retBuff),
                                              retBuff, sizeof(retBuff)),
              0);

    EXPECT_EQ(memcmp(src, retBuff, sizeof(retBuff)), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_array_uint8)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint8_t buf[1] = {};
    uint8_t val[1] = {0};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(
        pldm_msgbuf_insert_array_uint8(ctx, sizeof(val), val, sizeof(val)), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_insert_array_char_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    char src[6] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77};
    char buf[6] = {};
    char retBuff[6] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_insert_array_char(ctx, sizeof(src), src, sizeof(src)),
              0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_array_char(ctxExtract, sizeof(retBuff),
                                             retBuff, sizeof(retBuff)),
              0);

    EXPECT_EQ(memcmp(src, retBuff, sizeof(retBuff)), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, insert_under_array_char)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    char buf[1] = {};
    char val[1] = {0};

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN + sizeof(val) - 1;
    EXPECT_NE(pldm_msgbuf_insert_array_char(ctx, sizeof(val), val, sizeof(val)),
              0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_span_required_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src[6] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77};
    uint8_t buf[6] = {0};
    const size_t required = 4;
    uint8_t expectData[required] = {0x44, 0x55, 0x66, 0x77};
    uint16_t testVal;
    uint8_t* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_insert_array_uint8(ctx, sizeof(src), src, sizeof(src)), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(pldm_msgbuf_span_required(ctxExtract, required, (void**)&retBuff),
              0);

    EXPECT_EQ(memcmp(expectData, retBuff, required), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, pldm_msgbuf_span_required_bad)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src[6] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77};
    uint8_t buf[6] = {0};
    const size_t required = 4;
    uint16_t testVal;
    [[maybe_unused]] uint8_t* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_insert_array_uint8(ctx, sizeof(src), src, sizeof(src)), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(pldm_msgbuf_span_required(ctxExtract, required, NULL), 0);

    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, span_required_under)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;

    uint8_t buf[1] = {};
    void* cursor = nullptr;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, 0), 0);
    ctx->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_span_required(ctx, 1, &cursor), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_span_string_ascii_good)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[9] = {0x11, 0x22, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x00, 0x77};
    constexpr size_t required = 6;
    const char expectData[required] = {0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x00};
    uint16_t testVal;
    uint8_t testVal1;
    char* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&retBuff, NULL),
              0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctxExtract, testVal1), 0);
    EXPECT_EQ(0x77, testVal1);

    EXPECT_EQ(required, strlen(retBuff) + 1);
    EXPECT_EQ(strncmp(expectData, retBuff, strlen(retBuff) + 1), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_ascii_good_with_length)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[9] = {0x11, 0x22, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x00, 0x77};
    constexpr size_t required = 6;
    const char expectData[required] = {0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x00};
    uint16_t testVal;
    uint8_t testVal1;
    char* retBuff = NULL;
    size_t length;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(
        pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&retBuff, &length),
        0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctxExtract, testVal1), 0);
    EXPECT_EQ(0x77, testVal1);

    EXPECT_EQ(required, strlen(retBuff) + 1);
    EXPECT_EQ(length, strlen(retBuff) + 1);
    EXPECT_EQ(required, length);
    EXPECT_EQ(strncmp(expectData, retBuff, strlen(retBuff) + 1), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_ascii_allow_null_args)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[8] = {0x11, 0x22, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x00};
    uint16_t testVal;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(pldm_msgbuf_span_string_ascii(ctxExtract, NULL, NULL), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_ascii_bad_no_terminator)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[8] = {0x11, 0x22, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x77};
    uint16_t testVal;
    char* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&retBuff, NULL),
              -EOVERFLOW);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_span_string_ascii_under)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    uint8_t src[1] = {};
    char* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, 0), 0);
    ctxExtract->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&retBuff, NULL),
              0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), -EOVERFLOW);
}

static size_t str16len(char16_t* startptr)
{
    char16_t* endptr = startptr;
    while (*endptr)
    {
        endptr++;
    }
    return endptr - startptr;
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_good)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[] __attribute__((aligned(alignof(char16_t)))) = {
        0x11, 0x22, 0x11, 0x68, 0x22, 0x65, 0x33, 0x6c,
        0x44, 0x6c, 0x55, 0x6f, 0x00, 0x00, 0x34, 0x12};
    const char expectData[] = {0x11, 0x68, 0x22, 0x65, 0x33, 0x6c,
                               0x44, 0x6c, 0x55, 0x6f, 0x00, 0x00};
    uint16_t testVal;
    uint16_t testVal1;
    void* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);

    ASSERT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&retBuff, NULL),
              0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal1), 0);
    EXPECT_EQ(0x1234, testVal1);

    ASSERT_EQ(0, (uintptr_t)retBuff & (alignof(char16_t) - 1));
    EXPECT_EQ(6, str16len((char16_t*)retBuff) + 1);
    EXPECT_EQ(0, memcmp(expectData, retBuff, sizeof(expectData)));
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_good2)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[24] = {0x11, 0x22, 0x11, 0x68, 0x22, 0x65, 0x33, 0x6c,
                       0x44, 0x6c, 0x55, 0x6f, 0x00, 0x00, 0x34, 0x12,
                       0x44, 0x6c, 0x55, 0x6f, 0x00, 0x00, 0x34, 0x12};
    constexpr size_t required = 6;
    const char16_t expectData[required] = {0x6811, 0x6522, 0x6c33,
                                           0x6c44, 0x6f55, 0x0000};
    const char16_t expectData1[3] = {0x6c44, 0x6f55, 0x0000};
    uint16_t testVal;
    uint16_t testVal1;
    char* retBuff = NULL;
    char* retBuff1 = NULL;
    size_t length = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);

    EXPECT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&retBuff, NULL),
              0);

    ASSERT_EQ(0, (uintptr_t)retBuff & (alignof(char16_t) - 1));
    EXPECT_EQ(6, str16len((char16_t*)retBuff) + 1);
    EXPECT_EQ(memcmp(expectData, retBuff,
                     sizeof(char16_t) * (str16len((char16_t*)retBuff) + 1)),
              0);

    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal1), 0);
    EXPECT_EQ(0x1234, testVal1);

    EXPECT_EQ(
        pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&retBuff1, &length),
        0);

    EXPECT_EQ(0, length % 2);
    EXPECT_EQ(memcmp(expectData1, retBuff1, length), 0);

    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal1), 0);
    EXPECT_EQ(0x1234, testVal1);

    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_allow_null_args)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[14] = {0x11, 0x22, 0x11, 0x68, 0x22, 0x65, 0x33,
                       0x6c, 0x44, 0x6c, 0x55, 0x6f, 0x00, 0x00};
    uint16_t testVal;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, NULL, NULL), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_bad_no_terminator)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[14] = {0x11, 0x22, 0x11, 0x68, 0x22, 0x65, 0x33,
                       0x6c, 0x44, 0x6c, 0x55, 0x6f, 0x66, 0x77};
    uint16_t testVal;
    char16_t* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&retBuff, NULL),
              -EOVERFLOW);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_bad_odd_size)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[] = {0x11, 0x22, 0x11, 0x68, 0x22, 0x65, 0x33,
                     0x6c, 0x44, 0x6c, 0x55, 0x00, 0x00};
    uint16_t testVal;
    char16_t* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(0x2211, testVal);
    EXPECT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&retBuff, NULL),
              -EOVERFLOW);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_mix)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;
    uint8_t src[36] = {0x2,  0x65, 0x6e, 0x00, // Language Tag "en"
                       0x00, 0x53, 0x00, 0x30, 0x00, 0x53, 0x00,
                       0x58, 0x00, 0x00,                   // Entity Name "S0S"
                       0x66, 0x6e, 0x00,                   // Language Tag "en"
                       0x00, 0x53, 0x00, 0x31, 0x00, 0x00, // Entity Name "S1"
                       0x67, 0x6e, 0x00,                   // Language Tag "en"
                       0x00, 0x52, 0x00, 0x52, 0x00, 0x33, 0x00,
                       0x00, // Entity Name "RR3"
                       0x77, 0x88};
    uint8_t name_count;
    uint16_t test_val;
    char* tag = NULL;
    char* name = NULL;
    char* tag1 = NULL;
    char* name1 = NULL;
    char* tag2 = NULL;
    char* name2 = NULL;
    const char expectTag0[3] = {0x65, 0x6e, 0x00};
    const char expectTag1[3] = {0x66, 0x6e, 0x00};
    const char expectTag2[3] = {0x67, 0x6e, 0x00};

    const char16_t expectName0[5] = {0x5300, 0x3000, 0x5300, 0x5800, 0x0000};
    const char16_t expectName1[3] = {0x5300, 0x3100, 0x0000};
    const char16_t expectName2[4] = {0x5200, 0x5200, 0x3300, 0x0000};
    size_t length = 0;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, sizeof(src)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint8(ctxExtract, name_count), 0);
    EXPECT_EQ(0x2, name_count);

    EXPECT_EQ(pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&tag, NULL), 0);
    EXPECT_EQ(strncmp(expectTag0, tag, strlen(tag) + 1), 0);

    EXPECT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&name, NULL),
              0);
    ASSERT_EQ(0, (uintptr_t)name & (alignof(char16_t) - 1));
    EXPECT_EQ(5, str16len((char16_t*)name) + 1);
    EXPECT_EQ(memcmp(expectName0, name,
                     sizeof(char16_t) * (str16len((char16_t*)name) + 1)),
              0);

    EXPECT_EQ(pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&tag1, &length),
              0);
    EXPECT_EQ(strncmp(expectTag1, tag1, length), 0);
    EXPECT_EQ(
        pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&name1, &length), 0);
    EXPECT_EQ(0, length % 2);
    EXPECT_EQ(memcmp(expectName1, name1, length), 0);

    EXPECT_EQ(pldm_msgbuf_span_string_ascii(ctxExtract, (void**)&tag2, NULL),
              0);
    EXPECT_EQ(strncmp(expectTag2, tag2, strlen(tag2) + 1), 0);
    EXPECT_EQ(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&name2, NULL),
              0);
    ASSERT_EQ(0, (uintptr_t)name2 & (alignof(char16_t) - 1));
    EXPECT_EQ(4, str16len((char16_t*)name2) + 1);
    EXPECT_EQ(memcmp(expectName2, name2,
                     sizeof(char16_t) * (str16len((char16_t*)name2) + 1)),
              0);

    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, test_val), 0);
    EXPECT_EQ(0x8877, test_val);

    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
}

TEST(msgbuf, pldm_msgbuf_span_string_utf16_under)
{
    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    uint8_t src[1] = {};
    char* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, src, 0), 0);
    ctxExtract->remaining = INTMAX_MIN;
    EXPECT_NE(pldm_msgbuf_span_string_utf16(ctxExtract, (void**)&retBuff, NULL),
              0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_span_remaining_good)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src[8] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
    uint8_t buf[8] = {0};
    uint16_t testVal;
    uint8_t expectData[6] = {0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
    size_t remaining;
    uint8_t* retBuff = NULL;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_insert_array_uint8(ctx, sizeof(src), src, sizeof(src)), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);
    EXPECT_EQ(
        pldm_msgbuf_span_remaining(ctxExtract, (void**)&retBuff, &remaining),
        0);

    EXPECT_EQ(remaining, sizeof(expectData));
    EXPECT_EQ(memcmp(expectData, retBuff, remaining), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, pldm_msgbuf_span_remaining_bad)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src[8] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
    uint8_t buf[8] = {0};
    uint16_t testVal;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(
        pldm_msgbuf_insert_array_uint8(ctx, sizeof(src), src, sizeof(src)), 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    ASSERT_EQ(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(ctxExtract, testVal), 0);

    EXPECT_EQ(pldm_msgbuf_destroy(ctxExtract), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(ctx), 0);
}

TEST(msgbuf, pldm_msgbuf_copy_good)
{
    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    uint16_t buf[1] = {htole16(0x5aa5)};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, sizeof(buf), buf, sizeof(buf)), 0);

    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;
    uint16_t checkVal = 0;
    uint8_t buf1[sizeof(buf)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(dst, sizeof(buf1), buf1, sizeof(buf1)), 0);
    EXPECT_EQ(pldm_msgbuf_copy(dst, src, buf[0], name), 0);

    ASSERT_EQ(pldm_msgbuf_init_errno(dst, sizeof(buf1), buf1, sizeof(buf1)), 0);
    EXPECT_EQ(pldm_msgbuf_extract_uint16(dst, checkVal), 0);

    EXPECT_EQ(pldm_msgbuf_destroy(src), 0);
    EXPECT_EQ(pldm_msgbuf_destroy(dst), 0);

    EXPECT_EQ(buf[0], checkVal);
}

TEST(msgbuf, pldm_msgbuf_copy_bad)
{
    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;
    uint8_t buf[1] = {sizeof(uint8_t)};
    uint8_t buf1[1] = {sizeof(uint16_t)};
    uint16_t value = 8;

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, buf, sizeof(buf)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf1, sizeof(buf1)), 0);
    EXPECT_EQ(pldm_msgbuf_copy(dst, src, value, name), -EOVERFLOW);

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, buf1, sizeof(buf1)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy(dst, src, value, name), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_copy_string_ascii_exact)
{
    const char msg[] = "this is a message";

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_ascii(dst, src), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(src), 0);
    EXPECT_EQ(0, memcmp(msg, buf, sizeof(buf)));
}

TEST(msgbuf, pldm_msgbuf_copy_string_ascii_dst_exceeds_src)
{
    const char msg[] = "this is a message";

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg) + 1] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_ascii(dst, src), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(src), 0);
    EXPECT_EQ(0, memcmp(buf, msg, sizeof(msg)));
}

TEST(msgbuf, pldm_msgbuf_copy_string_ascii_src_exceeds_dst)
{
    const char msg[] = "this is a message";

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg) - 1] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_ascii(dst, src), -EOVERFLOW);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), -EOVERFLOW);
    ASSERT_EQ(pldm_msgbuf_destroy(src), 0);
}

TEST(msgbuf, pldm_msgbuf_copy_string_ascii_unterminated_src)
{
    const char msg[] = {'a'};

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_ascii(dst, src), -EOVERFLOW);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(src), -EOVERFLOW);
}

TEST(msgbuf, pldm_msgbuf_copy_utf16_exact)
{
    const char16_t msg[] = u"this is a message";

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_utf16(dst, src), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(src), 0);
    EXPECT_EQ(0, memcmp(buf, msg, sizeof(msg)));
}

TEST(msgbuf, pldm_msgbuf_copy_utf16_dst_exceeds_src)
{
    const char16_t msg[] = u"this is a message";

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg) + 1] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_utf16(dst, src), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(src), 0);
    EXPECT_EQ(0, memcmp(buf, msg, sizeof(msg)));
}

TEST(msgbuf, pldm_msgbuf_copy_utf16_src_exceeds_dst)
{
    const char16_t msg[] = u"this is a message";

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg) - 1] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_utf16(dst, src), -EOVERFLOW);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), -EOVERFLOW);
    ASSERT_EQ(pldm_msgbuf_destroy(src), 0);
}

TEST(msgbuf, pldm_msgbuf_copy_utf16_unterminated_src)
{
    const char16_t msg[] = {u'a'};

    struct pldm_msgbuf _src;
    struct pldm_msgbuf* src = &_src;
    struct pldm_msgbuf _dst;
    struct pldm_msgbuf* dst = &_dst;

    char buf[sizeof(msg)] = {};

    ASSERT_EQ(pldm_msgbuf_init_errno(src, 0, msg, sizeof(msg)), 0);
    ASSERT_EQ(pldm_msgbuf_init_errno(dst, 0, buf, sizeof(buf)), 0);
    EXPECT_EQ(pldm_msgbuf_copy_string_utf16(dst, src), -EOVERFLOW);
    ASSERT_EQ(pldm_msgbuf_destroy(dst), 0);
    ASSERT_EQ(pldm_msgbuf_destroy(src), -EOVERFLOW);
}

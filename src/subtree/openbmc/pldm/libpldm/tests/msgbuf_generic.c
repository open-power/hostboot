/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
/* Test pldm_msgbuf_extract() separately because we can't do _Generic() in C++
 * code, i.e. gtest */

#include <endian.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

/* We're exercising the implementation so disable the asserts for now */
#ifndef NDEBUG
#define NDEBUG 1
#endif
#include "msgbuf.h"

/* Given we disabled asserts above, set up our own expectation framework */
#define expect(cond) __expect(__func__, __LINE__, (cond))
#define __expect(fn, line, cond)                                               \
    do                                                                         \
    {                                                                          \
        if (!(cond))                                                           \
        {                                                                      \
            fprintf(stderr, "%s:%d: failed expectation: %s\n", fn, line,       \
                    #cond);                                                    \
            exit(EXIT_FAILURE);                                                \
        }                                                                      \
    } while (0)

static void test_msgbuf_extract_generic_uint8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t buf[1] = {0xa5};
    uint8_t val;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == 0xa5);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_generic_int8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t buf[1] = {-1};
    int8_t val;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == -1);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_generic_uint16(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t buf[1] = {0x5aa5};
    uint16_t val;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == 0x5aa5);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_generic_int16(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t buf[1] = {(int16_t)(htole16((uint16_t)INT16_MIN))};
    int16_t val;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == INT16_MIN);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_generic_uint32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {0x5a00ffa5};
    uint32_t val;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == 0x5a00ffa5);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_generic_int32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t buf[1] = {(int32_t)(htole32((uint32_t)INT32_MIN))};
    int32_t val;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == INT32_MIN);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_generic_real32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1];
    uint32_t xform;
    real32_t val;

    val = FLT_MAX;
    memcpy(&xform, &val, sizeof(val));
    buf[0] = htole32(xform);
    val = 0;

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctx, val) == 0);
    expect(val == FLT_MAX);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_extract_array_generic_uint8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {0};
    uint8_t arr[1];

    expect(pldm_msgbuf_init_errno(ctx, sizeof(buf), buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract_array(ctx, 1, arr, 1) == 0);
    expect(arr[0] == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_generic_int32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t src = -12345;
    int32_t checkVal = 0;
    uint8_t buf[sizeof(int32_t)] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_insert(ctx, src) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctxExtract, checkVal) == 0);

    expect(src == checkVal);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_generic_uint32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t src = 0xf1223344;
    uint32_t checkVal = 0;
    uint8_t buf[sizeof(uint32_t)] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_insert(ctx, src) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctxExtract, checkVal) == 0);

    expect(src == checkVal);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_generic_uint16(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t src = 0xf344;
    uint16_t checkVal = 0;
    uint8_t buf[sizeof(uint16_t)] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(uint16_t)) == 0);
    expect(pldm_msgbuf_insert(ctx, src) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctxExtract, checkVal) == 0);

    expect(src == checkVal);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_generic_int16(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t src = -12;
    int16_t checkVal = 0;
    uint8_t buf[sizeof(int16_t)] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(uint16_t)) == 0);
    expect(pldm_msgbuf_insert(ctx, src) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctxExtract, checkVal) == 0);

    expect(src == checkVal);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_generic_uint8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src = 0xf4;
    uint8_t checkVal = 0;
    uint8_t buf[sizeof(uint8_t)] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_insert(ctx, src) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctxExtract, checkVal) == 0);

    expect(src == checkVal);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_generic_int8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t src = -4;
    int8_t checkVal = 0;
    uint8_t buf[sizeof(int8_t)] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_insert(ctx, src) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract(ctxExtract, checkVal) == 0);

    expect(src == checkVal);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

static void test_msgbuf_insert_array_generic_uint8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint8_t src[6] = {0x11, 0x22, 0x44, 0x55, 0x66, 0x77};
    uint8_t buf[6] = {0};
    uint8_t retBuff[6] = {0};

    expect(pldm_msgbuf_init_errno(ctx, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_insert_array(ctx, sizeof(src), src, sizeof(src)) == 0);

    struct pldm_msgbuf _ctxExtract;
    struct pldm_msgbuf* ctxExtract = &_ctxExtract;

    expect(pldm_msgbuf_init_errno(ctxExtract, 0, buf, sizeof(buf)) == 0);
    expect(pldm_msgbuf_extract_array(ctxExtract, sizeof(retBuff), retBuff,
                                     sizeof(retBuff)) == 0);

    expect(memcmp(src, retBuff, sizeof(retBuff)) == 0);
    expect(pldm_msgbuf_destroy(ctxExtract) == 0);
    expect(pldm_msgbuf_destroy(ctx) == 0);
}

typedef void (*testfn)(void);

static const testfn tests[] = {test_msgbuf_extract_generic_uint8,
                               test_msgbuf_extract_generic_int8,
                               test_msgbuf_extract_generic_uint16,
                               test_msgbuf_extract_generic_int16,
                               test_msgbuf_extract_generic_uint32,
                               test_msgbuf_extract_generic_int32,
                               test_msgbuf_extract_generic_real32,
                               test_msgbuf_extract_array_generic_uint8,
                               test_msgbuf_insert_generic_uint8,
                               test_msgbuf_insert_generic_int8,
                               test_msgbuf_insert_generic_uint16,
                               test_msgbuf_insert_generic_int16,
                               test_msgbuf_insert_generic_uint32,
                               test_msgbuf_insert_generic_int32,
                               test_msgbuf_insert_array_generic_uint8,
                               NULL};

int main(void)
{
    testfn const* testp = &tests[0];

    while (*testp)
    {
        (*testp)();
        testp++;
    }

    return 0;
}

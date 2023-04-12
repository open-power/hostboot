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

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == 0xa5);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
}

static void test_msgbuf_extract_generic_int8(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int8_t buf[1] = {-1};
    int8_t val;

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == -1);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
}

static void test_msgbuf_extract_generic_uint16(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint16_t buf[1] = {0x5aa5};
    uint16_t val;

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == 0x5aa5);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
}

static void test_msgbuf_extract_generic_int16(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int16_t buf[1] = {(int16_t)(htole16((uint16_t)INT16_MIN))};
    int16_t val;

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == INT16_MIN);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
}

static void test_msgbuf_extract_generic_uint32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    uint32_t buf[1] = {0x5a00ffa5};
    uint32_t val;

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == 0x5a00ffa5);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
}

static void test_msgbuf_extract_generic_int32(void)
{
    struct pldm_msgbuf _ctx;
    struct pldm_msgbuf* ctx = &_ctx;
    int32_t buf[1] = {(int32_t)(htole32((uint32_t)INT32_MIN))};
    int32_t val;

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == INT32_MIN);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
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

    expect(pldm_msgbuf_init(ctx, sizeof(buf), buf, sizeof(buf)) ==
           PLDM_SUCCESS);
    expect(pldm_msgbuf_extract(ctx, &val) == PLDM_SUCCESS);
    expect(val == FLT_MAX);
    expect(pldm_msgbuf_destroy(ctx) == PLDM_SUCCESS);
}

typedef void (*testfn)(void);

static const testfn tests[] = {
    test_msgbuf_extract_generic_uint8,  test_msgbuf_extract_generic_int8,
    test_msgbuf_extract_generic_uint16, test_msgbuf_extract_generic_int16,
    test_msgbuf_extract_generic_uint32, test_msgbuf_extract_generic_int32,
    test_msgbuf_extract_generic_real32, NULL};

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

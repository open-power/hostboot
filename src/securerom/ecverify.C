/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/ecverify.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** ECDSA verification on fixed curve/s (currently, on NIST P-521)
 *  The code below works for a compile-time constant curve, and requires
 *  a single bignumber pair (public key) to specify a key
 *
 *  Knowledge of our environment allows the following simplifications:
 *    - modular operations are always mod P
 *    - there (multiple) unused bits in the most significant word of bignums
 *  Further assumptions:
 *    - bignumber indices fit 7 bits (8-bit counter sufficient for double bn's)
 *  Search for "P521", which flags curve dependencies.
 */


#define __STDC_FORMAT_MACROS 1     /* add 64-bit printf modifiers  */
#include <stdio.h>
#include <string.h>
#include <stdint.h>                /* uint_fast8_t, uintN_t        */
#include "inttypes.H"          /* PRIx64 used to format bn_t's */

/**
 *  Define __LITTLE_ENDIAN or __BIG_ENDIAN for target.
 */
#if defined __BIG_ENDIAN__ || defined _BIG_ENDIAN
    #define __BIG_ENDIAN
    #undef __LITTLE_ENDIAN
#else
    #undef __BIG_ENDIAN
    #define __LITTLE_ENDIAN
#endif

#include <securerom/ecverify.H>

#define  EC_PRIMEBITS  521    /* P521 */

#define  EC_STACKTRACE  1       /* debug only; currently, glibc      */
#define  NO_EC_DOUBLE_XY 1      /* do not implement ec_double_xy */

typedef uint64_t     bn_t;
typedef uint32_t     hbn_t;         /* half-bignumber */
typedef uint_fast8_t bnindex_t;

#define  BN_FMT  "%016" PRIx64       /* PRIx64 from inttypes.h */

#if !defined(__LITTLE_ENDIAN) && !defined(__BIG_ENDIAN)
#error "Please define target endianness (__LITTLE_ENDIAN or __BIG_ENDIAN)"
#endif

#if defined(__LITTLE_ENDIAN) && defined(__BIG_ENDIAN)
#error "Please define one target endianness (__LITTLE_ENDIAN or __BIG_ENDIAN)"
#endif


#define  BN_BITS   (8*sizeof(bn_t))
#define  HBN_BITS  (8*sizeof(hbn_t))

#define  EC_PRIMEBYTES  ((EC_PRIMEBITS +7) /8)

#define  BN_MAXBIT  (((bn_t) 1) << (BN_BITS -1))

#define  BITS2BN(bits) (((bits) +BN_BITS -1) / BN_BITS)

// we only deal with big numbers of fixed size
#define  NWORDS   BITS2BN( EC_PRIMEBITS )
#define  BNBYTES  (NWORDS*sizeof(bn_t))

#define  BN_MSW(p)     ((p)[0])
#define  BN_LSW(p)     ((p)[ NWORDS-1 ])
#define  bn_is_odd(p)  (1 & BN_LSW(p))


#ifndef BN_POWER64_CPY
#define  BN_COPY(dst, src)  memcpy((dst), (src), NWORDS*sizeof(bn_t))
#else
static void __attribute__((noinline)) BN_COPY (bn_t *dst, const bn_t *src)
{
    size_t i;
    for(i=0;i<NWORDS;i++)
    {
        *dst++ = *src++;
    }
}
#endif

#ifdef BN_POWER64_DBG
static void __attribute__((noinline)) BN_DUMP (int i, bn_t *top)
{
    asm volatile ("nop" : : "r" (i), "r" (top));
}
static void BN_EXIT (void)
{
    asm volatile("b .Check_Stop");
}
#else
#define BN_DUMP(_i,_bn) ((void)0)
#define BN_EXIT()       ((void)0)
#endif


#if defined(EC_DEBUG)
static void bn_print  (const char *msg, const bn_t *m) ;
static void bn_dprint (const char *msg, const bn_t *m) ;
#else
#define bn_print(msg, m)   ((void) 0)
#define bn_dprint(msg, m)  ((void) 0)
#endif

#if !defined(NDEBUG)
#define  EC_ASSERT(cond)     assert(cond)
#define  EC_DEVASSERT(cond)  assert(cond)
#else
#define  EC_ASSERT(cond)     ((void) 0)  // removed '((void) cond)' which still did the cond test
#define  EC_DEVASSERT(cond)  ((void) 0)  // removed '((void) cond)' which still did the cond test
#endif

static bn_t bn_sub    (bn_t *a, const bn_t *b) ;
static void bn_add    (bn_t *a, const bn_t *b) ;
static void bn_mul    (bn_t *r, const bn_t *a, const bn_t *b) ;
static void bn_modadd (bn_t *a, const bn_t *b) ;
static void bn_modsub (bn_t *a, const bn_t *b) ;

static int bn_cmp (const bn_t a[NWORDS], const bn_t b[NWORDS]) ;

// P521: a==-3, fixed curve parameter
static int ec_double (bn_t *x, bn_t *y, bn_t *z) ;


//============================================  prime-specific functions  ====
// this section contains all prime/order-specific functionality
// if we ever need to support other curves, #ifdef their equivalent functions
//
// this code is limited to p = 2^521 -1 (P-521) and its order

#define  BN_PRIME_MSW        0x1ff
#define  BN_PRIME_MSW_MASK   0x1ff    /* equal, as coincidence, for P521 */
#define  BN_PRIME_MSW_BITS   (EC_PRIMEBITS % BN_BITS)


typedef struct {
    bn_t ec_prime[ NWORDS ];
    bn_t ec_order[ NWORDS ];
    bn_t prime_px[ NWORDS ];
    bn_t prime_py[ NWORDS ];
    bn_t ec_order_qn[ NWORDS ];
} consts_t;

extern "C"
const consts_t consts = {
//const bn_t ec_prime[ NWORDS ] =
    {
        BN_PRIME_MSW,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
    },

//const bn_t ec_order[ NWORDS ] =
    {
        0x00000000000001ffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xffffffffffffffffLL,
        0xfffffffffffffffaLL,
        0x51868783bf2f966bLL,
        0x7fcc0148f709a5d0LL,
        0x3bb5c9b8899c47aeLL,
        0xbb6fb71e91386409LL,
    },

//const bn_t prime_px[ NWORDS ] = {
    {
        0x00000000000000c6LL,
        0x858e06b70404e9cdLL,
        0x9e3ecb662395b442LL,
        0x9c648139053fb521LL,
        0xf828af606b4d3dbaLL,
        0xa14b5e77efe75928LL,
        0xfe1dc127a2ffa8deLL,
        0x3348b3c1856a429bLL,
        0xf97e7e31c2e5bd66LL,
    },

//const bn_t prime_py[ NWORDS ] = {
    {
        0x0000000000000118LL,
        0x39296a789a3bc004LL,
        0x5c8a5fb42c7d1bd9LL,
        0x98f54449579b4468LL,
        0x17afbd17273e662cLL,
        0x97ee72995ef42640LL,
        0xc550b9013fad0761LL,
        0x353c7086a272c240LL,
        0x88be94769fd16650LL,
    },

//--------------------------  mod mul by order (n)  -------
// MS 521 bits of Q/N, fractional part
//
// static const bn_t ec_order_qn[ NWORDS ] =
    {
                         0LL,
                         0LL,
                         0LL,
                         0LL,
        0x0000000000000005LL,
        0xae79787c40d06994LL,
        0x8033feb708f65a2fLL,
        0xc44a36477663b851LL,
        0x449048e16ec79bf6LL,
    }
} ;

inline const consts_t* __attribute__((pure)) consts_p()
{

#ifdef EMULATE_HW
    return &consts;
#else
    consts_t* result_consts_p;
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
        "sub  %0,2,%0 \n\t" // because subi does not work
        "addi %0,%0,(consts-0x8000)@l" : "=r" (result_consts_p) );
    return result_consts_p;
#endif
}

#define  bn_ge_prime(val)  (bn_cmp((val), consts_p()->ec_prime) >= 0)
#define  bn_ge_order(val)  (bn_cmp((val), consts_p()->ec_order) >= 0)

// P521: MSW has unused bits
#define BN_MSW_UNUSED_BITS  (BN_BITS - BN_PRIME_MSW_BITS)
#define BN_MSW_UNUSED_BYTES ((BN_MSW_UNUSED_BITS +7) >>3)
#define BN_MSW_UNUSED_MASK  ((((bn_t) 1) << BN_MSW_UNUSED_BITS) -1)

// not general-purpose shl: we only need to shift products (2*NWORDS)
// to two EC_PRIMEBITS, with BN_MSW_UNUSED_BITS
//
// acc contains MSW of lower half
//
static bn_t bn_shl (bn_t *a, bn_t acc)
{
    bnindex_t i = NWORDS;
    bn_t cf = 0;

    EC_ASSERT(NULL != a);
    EC_ASSERT(0 == a[0]);

    a += NWORDS;

    while (0<i--)
    {
        cf = *(--a);
        *a <<= BN_MSW_UNUSED_BITS;
        *a |= BN_MSW_UNUSED_MASK & (acc >> BN_PRIME_MSW_BITS);
        acc = cf;
    }

    return cf;
}


//=========================================================  diagnostics  ====
#if defined(EC_DEBUG)

static void bn_printn (const char *msg, const bn_t *m, bnindex_t i)
{
    EC_ASSERT(NULL != m);

    if (NULL != msg)
    {
        printf("%s", msg);
    }

    while (0 < i--)
    {
#if defined(EC_DEBUG_WORDS)
        if (i<NWORDS-1)
        {
            printf(".");
        }
#endif

        printf(BN_FMT, *(m++));
    }

    printf("\n");
}

static void bn_print (const char *msg, const bn_t *m)
{
    bn_printn(msg, m, NWORDS);
}

static void bn_dprint (const char *msg, const bn_t *m)
{
    bn_printn(msg, m, NWORDS+NWORDS);
}

#endif   /* defined(EC_DEBUG) */

//==============================================  modular multiplication  ====
// this section should be routed to hardware, when it becomes available

#ifndef BN_POWER64_CLR
#define  bn_clear(n)   memset((n), 0, BNBYTES)
#define  bn_dclear(n)  memset((n), 0, 2*BNBYTES)
#else
#define  bn_clear(n)   bn_clr((n), NWORDS)
#define  bn_dclear(n)  bn_clr((n), 2*NWORDS)
static void __attribute__((noinline)) bn_clr (bn_t *dst, size_t s)
{
    size_t i;
    dst--;
    for(i=0;i<s;i++)
    {
        *(++dst) = 0LL;
    }
}
#endif

#ifndef BN_POWER64_MUL
// high bn_t of a*b
// XXX use inline asm if possible; Intel code is enormous
// XXX alternatively, replace with hbn_t-by-hbn_t-blocked multiplication
//
static bn_t bn_dmul (bn_t a, bn_t b)
{
#ifdef EC_POWER64_ASM
    bn_t t;
    asm("mulhdu   %0,%1,%2" : "=r" (t) : "r" (a), "r" (b) );
    return t;
#else
    hbn_t ah, al, bh, bl;
    bn_t t;

    al = a;
    ah = (hbn_t) (a >> HBN_BITS);
    bl = b;
    bh = (hbn_t) (b >> HBN_BITS);

    a = ((bn_t) ah) * bh;         // collects high word
    b = ((bn_t) al) * bl;         // collects low  word

    t = ((bn_t) ah) * bl;
    a += t >> HBN_BITS;
    t <<= HBN_BITS;
    if (b+t < t)
    {
        ++a;
    }
    b += t;

    t = ((bn_t) al) * bh;
    a += t >> HBN_BITS;
    t <<= HBN_BITS;
    if (b+t < t)
    {
        ++a;
    }
    return a;
#endif
}

/** multiply (a,NWORDS) by (b,NWORDS) into (r,2*NWORDS)
 *  we collect 2-word multiples, and carries across columns in two
 *  arrays:
 *
 *  products
 *      a[0].b[0]  a[1].b[0]  a[2].b[0]
 *                 a[0].b[1]  a[1].b[1]
 *                            a[0].b[2]
 *  carry in column to:
 *      carry[0]   carry[1]   carry[2]...
 *
 *  delaying carry-collection simplifies multiply loop
 */
// XXX split to half-words' array; get rid of bn_dmul()
//
static void bn_mul (bn_t *r, const bn_t *a, const bn_t *b)
{
    unsigned char cf[ NWORDS+NWORDS ];     /* carry collector */
    bnindex_t i, j;
    bn_t ph, pl;                           /* product high,low words */

    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    bn_dclear(r);
    memset(cf, 0, sizeof(cf));

    for (j=0; j<NWORDS; ++j)
    {
        for (i=0; i<NWORDS; ++i)
        {
            ph = bn_dmul(a[i], b[j]);
            pl = a[i] * b[j];

#ifdef EC_POWER64_ASM
            asm("addc    %0,%2,%4\n"
                "addze   %1,%3"
                : "=r" (r[i+j]), "=r" (cf[i+j])
                : "0" (r[i+j]), "1" (cf[i+j]), "r" (ph)
                );
            asm("addc    %0,%2,%4\n"
                "addze   %1,%3"
                : "=r" (r[i+j+1]), "=r" (cf[i+j+1])
                : "0" (r[i+j+1]), "1" (cf[i+j+1]), "r" (pl)
                );
#else
            r[i+j] += ph;
            if (r[i+j] < ph)
            {
                EC_ASSERT(i+j>0);    // MSW can't carry to left
                (cf[i+j-1])++;
            }

            r[i+j+1] += pl;
            if (r[i+j+1] < pl)
            {
                (cf[i+j])++;
            }
#endif
        }
    }

    // propagate carries (LS to MS)
#ifdef EC_POWER64_ASM
    i=NWORDS+NWORDS-2;
    asm("addc    %0,%1,%2"
        : "=r" (r[i])
        : "0" (r[i]), "r" (cf[i+1])
        );
    for ( ; 0<i; )
    {
        --i;
        asm("adde    %0,%1,%2"
            : "=r" (r[i])
            : "0" (r[i]), "r" (cf[i+1])
            );
#else
    for (i=NWORDS+NWORDS; 0<i; )
    {
        if (cf[--i])
        {
            r[i] += cf[i];
            if (r[i] < cf[i])
            {
                EC_ASSERT(0 < i);
                cf[i-1]++;
            }
        }
#endif
    }
}
#else
static void bn_mul (bn_t *r, const bn_t *a, const bn_t *b)
{
    bnindex_t i, j;
    bn_t ph, pl, th, tb;                           /* product high,low words */

    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    bn_dclear(r);

    r += NWORDS;
    b += NWORDS;
    for (j=0; j<NWORDS; j++)
    {
        th = 0LL;
        tb = *(--b);
        r += NWORDS;
        a += NWORDS;
        for (i=0; i<NWORDS; i++)
        {
            asm("mulld   %0,%1,%2"         //pl = *(--a) * tb
                : "=r" (pl)
                : "r" (*(--a)), "r" (tb)
                );
            asm("mulhdu  %0,%1,%2"         //ph = *a * tb
                : "=r" (ph)
                : "r" (*a), "r" (tb)
                );
            asm("addc    %1,%5,%4\n"       //pl += *(--r)
                "addze   %2,%6\n"          //ph += ca
                "addc    %0,%5,%7\n"       //*r = pl + th
                "addze   %3,%6"            //th = ph + ca
                : "=r" (*r), "=r" (pl), "=r" (ph), "=r" (th)
                : "0" (*(--r)), "1" (pl), "2" (ph), "3" (th)
                );
        }
        *(--r) = th;
    }
}
#endif

#ifdef EC_POWER64_ALG
#ifdef BN_POWER64_SQR
static void bn_sqr (bn_t *r, const bn_t *a)
{
    bnindex_t i, j;
    const bn_t *b;                           /* product high,low words */
    bn_t *c, ph, pl, ta, t0, t1, t2;         /* product high,low words */

    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != a);

    bn_dclear(r);

    r += 2*NWORDS;
    a += NWORDS;
    for (j=0; j<NWORDS-1; j++)
    {
        ta = *(--a);
        c = r;
        b = a;
        asm("mulld   %0,%2,%2\n"        //pl = ta * ta
            "mulhdu  %1,%2,%2"          //ph = ta * ta
            : "=r" (pl), "=r" (ph)
            : "r" (ta)
            );
        asm("addc    %0,%2,%4\n"        //*r = *(--r) + pl
            "addze   %1,%3"             //t0 = ph + ca
            : "=r" (*c), "=r" (t0)
            : "0" (*(--c)), "r" (ph), "r" (pl)
            );
        t1 = 0L;
        for (i=j+1; i<NWORDS; i++)
        {
            t2 = 0L;
            asm("mulld   %0,%1,%2"         //pl = *(--b) * ta
                : "=r" (pl)
                : "r" (*(--b)), "r" (ta)
                );
            asm("mulhdu  %0,%1,%2"         //ph = *b * ta
                : "=r" (ph)
                : "r" (*b), "r" (ta)
                );
            asm("addc    %1,%7,%7\n"      //pl += pl
                "adde    %2,%8,%8\n"      //ph += ph + ca
                "addze   %5,%11\n"        //t2 += ca
                "addc    %1,%7,%9\n"      //pl += t0
                "adde    %2,%8,%10\n"     //ph += t1 + ca
                "addze   %5,%11\n"        //t2 += ca
                "addc    %0,%6,%7\n"      //*r = *(--r) + pl
                "addze   %3,%8\n"         //t0 = ph + ca
                "addze   %4,%11"          //t1 = t2 + ca
                : "=r" (*c), "=r" (pl), "=r" (ph), "=r" (t0), "=r" (t1), "=r" (t2)
                : "0" (*(--c)), "1" (pl), "2" (ph), "3" (t0), "4" (t1), "5" (t2)
                );
        }
        asm("addc    %0,%2,%4\n"        //*r = *(--r) + t0
            "addze   %1,%3"             //t1 += ca
            : "=r" (*c), "=r" (t1)
            : "0" (*(--c)), "1" (t1), "r" (t0)
            );
        *(--c) = t1;
        r -= 2;
    }
    ta = *(--a);
    asm("mulld   %0,%2,%2\n"          //pl = ta * ta
        "mulhdu  %1,%2,%2"            //ph = ta * ta
        : "=r" (pl), "=r" (ph)
        : "r" (ta)
        );
    asm("addc    %0,%2,%4\n"          //*r = *(--r) + pl
        "addze   %1,%3"               //ph += ca
        : "=r" (*r), "=r" (ph)
        : "0" (*(--r)), "1" (ph), "r" (pl)
        );
    *(--r) += ph;
}
#endif
#endif

//----------------  mod mul by generator prime (p)  -------
// we only need to reduce with two moduluses, ec_prime or ec_order
// ec_prime has special form
//
// multiply to (prod,2*NWORDS), then reduce
// we use specific primes, with specific (faster) mod reductions


// a is double-length bignumber, i.e., 2*NWORDS
// always produced by a modular product, i.e., <=2*EC_PRIMEBITS total
//
// P521: specific form
// destroys LS bignumber of (a,2*NWORDS)
//
#ifndef EC_POWER64_RED
static void bn_modred_p521 (bn_t *r, bn_t *a)
{
    bn_t *al;
    bn_t *rc = r;

    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != a);
    EC_ASSERT((const bn_t *) r != a);

    al = a+NWORDS;

    // P521: product is 1042 bits, MSW of double-width bignum always 0
    //
    EC_ASSERT(0 == a[0]);

    BN_COPY(rc, a);
    bn_shl(rc, *al);

    *al &= BN_PRIME_MSW_MASK;

    if (bn_cmp(rc, consts_p()->ec_prime) >= 0)
    {
        bn_sub(rc, consts_p()->ec_prime); // XXX can this happen? (mod-based input)
    }

    if (bn_cmp(al, consts_p()->ec_prime) >= 0)
       bn_sub(al, consts_p()->ec_prime);
    {
        EC_ASSERT(!bn_ge_prime(al));         // al must have bitlen <= ec_prime
    }

    bn_add(rc, al);
    if (bn_cmp(rc, consts_p()->ec_prime) >= 0)
    {
        bn_sub(rc, consts_p()->ec_prime);
    }
}
#else
#ifdef BN_POWER64_SQR
static void __attribute__((noinline)) bn_modred_fast (bn_t *r, bn_t *a)
#else
static void bn_modred_fast (bn_t *r, bn_t *a)
#endif
{
    bn_t *ah = a + NWORDS;
    bn_t *al = a + 2*NWORDS;
    bn_t t0 = (*(a+1) >> 18) + (*ah >> 9);
    bn_t t1, t2, t3=0;
    size_t i;
    r += NWORDS;
    for (i=0; i<NWORDS-2; i++) {
        t1 = *(--ah) << 55;
        t2 = *ah >> 9;
        asm("addc    %3,%7,%5\n"   //t3 = *(--al) + t0;
            "addze   %2,%6\n"      //t2 += ca;
            "addc    %0,%4,%8\n"   //*(--r) = t3 + t1;
            "addze   %1,%6"        //t0 = t2 + ca;
            : "=r" (*(--r)), "=r" (t0), "=r" (t2), "=r" (t3)
            : "3" (t3), "1" (t0), "2" (t2), "r" (*(--al)), "r" (t1)
            );
    }
    t1 = *(--ah) << 55;
    t2 = (*ah >> 9)&BN_PRIME_MSW_MASK;
    asm("addc    %3,%7,%5\n"     //t3 = *(--al) + t0;
        "addze   %2,%6\n"        //t2 += ca;
        "addc    %0,%4,%8\n"     //*(--r) = t3 + t1;
        "addze   %1,%6"          //t0 = t2 + ca;
        : "=r" (*(--r)), "=r" (t0), "=r" (t2), "=r" (t3)
        : "3" (t3), "1" (t0), "2" (t2), "r" (*(--al)), "r" (t1)
        );
    *(--r) = (*(--al)&BN_PRIME_MSW_MASK) + t0;
}

static void __attribute__((noinline)) bn_modred_slow (bn_t *r)
{
    size_t i;
    if (*r > BN_PRIME_MSW_MASK)
    {
        bn_t t0 = *r >> 9;
        *r &= BN_PRIME_MSW_MASK;
        r += NWORDS;
        asm("addc    %0,%1,%2"
            : "=r" (*r)
            : "0" (*(--r)), "r" (t0)
            );
        for (i=0; i<NWORDS-1; i++)
        {
            asm("addze   %0,%1"
                : "=r" (*r)
                : "0" (*(--r))
                );
        }
    }
    if (bn_ge_prime(r))
    {
        bn_sub(r, consts_p()->ec_prime);
    }
}
#endif

static void bn_modmul_prime (bn_t *a, const bn_t *b)
{
    bn_t prod[ NWORDS+NWORDS ];

    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    bn_mul(prod, a, b);
#ifdef EC_POWER64_RED
    bn_modred_fast(a, prod);  // accepts upto 46 extra bits => outputs at most 1 extra bit (522)
#else
    bn_modred_p521(a, prod);
#endif
}

#ifdef EC_POWER64_ALG
static void bn_modsqr_prime (bn_t *a)
{
#ifdef BN_POWER64_SQR
    bn_t prod[ NWORDS+NWORDS ];

    EC_ASSERT(NULL != a);

    bn_sqr(prod, a);
#ifdef EC_POWER64_RED
    bn_modred_fast(a, prod);  // accepts upto 46 extra bits => outputs at most 1 extra bit (522)
#else
    bn_modred_p521(a, prod);
#endif
#else
    bn_modmul_prime(a, a);
#endif
}
#endif

// mod reduce 2*NWORDS to NWORDS through approximate division
//
// input (a,2*NWORDS) <= N^2 -2*N +1
//
// N = 2^521 -Q                  (Q is approx 2^260)
// A = AH * 2^521 + AL           (AH < 2^251)
// A/N = (AH*R + AL)/N = AH + (AH*Q + AL) /N ~ AH + (AH*Q /N)
// AH*Q /N =~ AH* floor(Q/N)
//
// dividend may be two too low:
//   1. we neglect AL/N, which may add add one (AL<N)
//   2. we truncate the multiplication, possibly ignoring one carry from below
// so, keep subtracting N until result <N; up to twice is enough
//
// r,a must not overlap
//
static void bn_modred_p521_order (bn_t *r, const bn_t *a)
{
    bn_t dbl[ NWORDS+NWORDS ];

    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != a);
    EC_ASSERT((const bn_t *) r != a);
    // XXX full overlap check

    // P521: product is 1042 bits, MSW of double-width bignum always 0
    //
    EC_ASSERT(0 == a[0]);

    BN_COPY(r, a);
    bn_shl(r, a[NWORDS]);

    bn_mul(dbl, r, consts_p()->ec_order_qn);
    bn_shl(dbl, dbl[NWORDS]);            // MS 521 bits of product
    bn_add(r, dbl);

    bn_mul(dbl, r, consts_p()->ec_order);            // N * floor(A / N)
    EC_ASSERT(bn_cmp(dbl, a) <= 0);
    EC_ASSERT(bn_cmp(dbl+NWORDS, a+NWORDS) <= 0);

    BN_COPY(r, a+NWORDS);
    bn_sub(r, dbl+NWORDS);               // A - (N * floor(A/N))

    if (bn_cmp(r, consts_p()->ec_order) >= 0)
    {
        bn_sub(r, consts_p()->ec_order);
    }

    if (bn_cmp(r, consts_p()->ec_order) >= 0)
    {
        bn_sub(r, consts_p()->ec_order);       // XXX can this still be 2+ over?
    }

    EC_ASSERT(bn_cmp(r, consts_p()->ec_order) < 0);
}


static void bn_modmul_order (bn_t *a, const bn_t *b)
{
    bn_t prod[ NWORDS+NWORDS ];

    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    bn_mul(prod, a, b);
    bn_modred_p521_order(a, prod);
}


// negative,0,positive for a<b, a==b, a>b
//
#if defined(__BIG_ENDIAN) && !defined(BN_POWER64_CMP)

static int bn_cmp (const bn_t *a, const bn_t *b)
{
    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    return memcmp(a, b, sizeof(bn_t)*NWORDS);
}

#else /*  defined(__BIG_ENDIAN) */

static int __attribute__((noinline)) bn_cmp (const bn_t *a, const bn_t *b)
{
    bnindex_t i;

    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    for (i=0; i<NWORDS; ++i)
    {
        if (a[i] != b[i])
        {
            return 1 - ((a[i] < b[i]) <<1);
        }
    }

    return 0;
}

#endif          /*  defined(__BIG_ENDIAN) */

//removed:
//static const bn_t bn_zero[ NWORDS ];

// mn: how many words to skip (least significant ones)
//
static int bn_is_zero (const bn_t *m, unsigned int mn)
{
    EC_ASSERT(NULL != m);
    EC_ASSERT(mn < NWORDS);

    const unsigned char *p2 = (const unsigned char *) m;
    size_t n=sizeof(bn_t)*(NWORDS-mn);

    while (n-- > 0)
    {
        if (0 != *p2)
        {
            return !(0 - *p2);
        }
        p2 += 1;
    }

    return !0;
}


static void __attribute__((noinline)) bn_add (bn_t *a, const bn_t *b)
{
    bn_t aw, cf = 0;           /* aw: copy of current word to allow a==b */
    bnindex_t i = NWORDS;

    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    a += NWORDS-1;
    b += NWORDS-1;

    while (0 < i--)
    {
        aw = *a;
        if (cf)
        {
            cf = (0 == ++aw);
        }
        aw += *b;
        cf |= (aw < *(b--));
        *(a--) = aw;
    }
}


// a,b < prime
// never with order as base
//
static void bn_modadd (bn_t *a, const bn_t *b)
{
    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);
    //EC_ASSERT(!bn_ge_prime(a));
    //EC_ASSERT(!bn_ge_prime(b));

    bn_add(a, b);         // P521: can not generate carry (unused MSW bits)
                          //       other curves need to handle this carry

#ifndef EC_POWER64_RED
    if (bn_ge_prime(a))
    {
        bn_sub(a, consts_p()->ec_prime);
    }
#endif
}


// never with order as base
static bn_t bn_sub (bn_t *a, const bn_t *b)
{
    bnindex_t i = NWORDS;
    bn_t bw, cf = 0;

    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);

    a += NWORDS-1;
    b += NWORDS-1;

    while (0 < i--) {
        if (cf)
        {
            cf = (0 == (*a)--);
        }
        bw = *b;
        cf |= (*a < *(b--));
        *(a--) -= bw;
    }

    return cf;
}

// never modular-subtracting with ec_order[], only with ec_prime[]
// therefore, implicit modulus
//
static void bn_modsub (bn_t *a, const bn_t *b)
{
    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != b);
    EC_ASSERT(!bn_ge_prime(b));

    if (bn_sub(a, b))
    {
        bn_add(a, consts_p()->ec_prime);
    }
}

// only rn LS words are touched
//
static void bn_shl_n (bn_t r[NWORDS], unsigned int rn, unsigned int bits)
{
    bn_t cf = 0, cfin;

    EC_DEVASSERT(NULL != r);
    EC_ASSERT(rn <= NWORDS);

    r += NWORDS-rn;

    if (bits >= BN_BITS) // unlikely, most modinv shift is <5 bits
    {
        cfin = bits / BN_BITS;    // whole words

        memmove(r, r+cfin, (NWORDS-cfin)*sizeof(bn_t));
#ifndef BN_POWER64_CLR
        memset(r+NWORDS-cfin, 0, cfin*sizeof(bn_t));
#else
        bn_clr(r+NWORDS-cfin, cfin);
#endif

        bits %= BN_BITS;
    }

    if (bits)
    {
        r += rn-1;
        while (0<rn--)
        {
            cfin = cf;
            cf = (*r >> (BN_BITS - bits));
            *r <<= bits;
            *r |=  cfin;
            --r;
        }
    }
}

static unsigned int bn_bits (const bn_t *a)
{
    unsigned int full = 8*BNBYTES;
    bnindex_t i;
    bn_t an;

    for (i=0; i<NWORDS; ++i)
    {
        full -= BN_BITS;
        an = a[i];

        if (!an)
        {
            continue;
        }

        while (an > 0xff)
        {
            full += 8;
            an >>= 8;
        }

        while (an)
        {
            ++full;
            an >>= 1;
        }
        return full;
    }
    return 0;
}

// XXX route to bnt_msbit
//
#define  bn_is_negative(p)  (0x1000 & (*(p)))

// inv stores S during run
//
static int bn_modinv(bn_t *inv, const bn_t *a, const bn_t *n)
{
    bn_t r[ NWORDS ], s[ NWORDS ],  u[ NWORDS ], v[ NWORDS ],
                     ss[ NWORDS ], vs[ NWORDS ];   // shifted S,V
    unsigned int shl, ub, vb;                      // shift amount; bitcount
    bn_t *pr = r, *ps = s, *pu = u, *pv = v, *pt;

    EC_ASSERT(NULL != inv);
    EC_ASSERT(NULL != a);
    EC_ASSERT(NULL != n);
    EC_ASSERT(bn_cmp(a,n) < 0);
    EC_ASSERT(!bn_is_zero(a,0));

    bn_clear(r);
    bn_clear(s);
    BN_LSW(s) = 1;

    BN_COPY(u, n);
    BN_COPY(v, a);

    // ub = bn_bits(u);
    ub = EC_PRIMEBITS;    // P521: only ec_prime or ec_order possible
    vb = bn_bits(v);

    while (1 < vb)
    {
        EC_ASSERT(ub >= vb);
        shl = ub-vb;

        BN_COPY(vs, pv);
        BN_COPY(ss, ps);
        if (shl)
        {
            bn_shl_n(vs, NWORDS, shl);
            bn_shl_n(ss, NWORDS, shl);
        }

        if (bn_is_negative(pv) == bn_is_negative(pu))
        {
            bn_sub(pu, vs);
            bn_sub(pr, ss);
        }
        else
        {
            bn_add(pu, vs);
            bn_add(pr, ss);
        }

        if (bn_is_negative(pu))
        {
            bn_clear(ss);
            bn_sub(ss, pu);
            ub = bn_bits(ss);
        }
        else
        {
            ub = bn_bits(pu);
        }

        if (ub < vb)
        {
            shl = ub;       // shl,ss used as swap-scratch
            ub  = vb;
            vb  = shl;

            pt = pu;
            pu = pv;
            pv = pt;

            pt = ps;
            ps = pr;
            pr = pt;
        }
    }

    if (bn_is_negative(pv))
    {
        BN_COPY(ss, ps);
        bn_clear(ps);
        bn_sub(ps, ss);
    }

    if (bn_is_negative(ps))
    {
        bn_add(ps, n);
    }

    if (bn_cmp(ps, n) >= 0)
    {
        bn_sub(ps, n);
    }

    BN_COPY(inv, ps);

    return 1;
}

#if defined(__BIG_ENDIAN)

static void bn_read_pt(bn_t *r, const unsigned char *data)
{
    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != data);

    r[0] = 0;
    memmove(((unsigned char *) r) +BNBYTES-EC_PRIMEBYTES,
            data, EC_PRIMEBYTES);
}

// P521: hash does not have unused MS words
//
static void bn_read_hash(bn_t *r, const unsigned char *data)
{
    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != data);

    r[0] = 0;
    memmove(((unsigned char *) r) +BNBYTES-EC_HASHBYTES,
            data, EC_HASHBYTES);
}

#else

static void bn_read(bn_t *r, const unsigned char *data, size_t dlen)
{
    bnindex_t i, whole = dlen / sizeof(bn_t),
                   rem = dlen % sizeof(bn_t);
    bn_t acc = 0;

    EC_ASSERT(NULL != r);
    EC_ASSERT(NULL != data);
    EC_ASSERT(dlen <= EC_PRIMEBYTES);

    acc = whole + (!!rem);
    if (acc < NWORDS) // unused MS words
    {
        acc = NWORDS - acc;
#ifndef BN_POWER64_CLR
        memset(r, 0, acc*sizeof(bn_t));
#else
        bn_clr(r, acc);
#endif
        r += acc;
    }

    acc = 0;
    if (rem)
    {
        ++whole;
    }
    else
    {
        rem = sizeof(bn_t);
    }

    while (0 < whole--)
    {
        for (i=0; i<rem; ++i)
        {
            acc = (acc <<8) + *(data++);
        }
        *(r++) = acc;
        acc = 0;
        rem = sizeof(bn_t);
    }
}

static void bn_read_pt(bn_t *r, const unsigned char *data)
{
    return bn_read(r, data, EC_PRIMEBYTES);
}

static void bn_read_hash(bn_t *r, const unsigned char *data)
{
    return bn_read(r, data, EC_HASHBYTES);
}

#endif    /* defined(__BIG_ENDIAN) */

//=======================================================  EC primitives  ====
/* (0,0) is our infinity, since it's not a curve point */
#define  ec_is_infinity(px, py, pz)  \
         (bn_is_zero((px), 0) && bn_is_zero((py), 0))

#define  ec_set_infinity(p)  bn_clear(p)

// (x) is transformed back to affine from projective (X*Z)
//
static void ec_projective2affine (bn_t *x, const bn_t *z)
{
    bn_t zinv[ NWORDS ];

    EC_ASSERT(NULL != x);
    EC_ASSERT(NULL != z);

    EC_ASSERT(!bn_ge_prime(x));
    EC_ASSERT(!bn_ge_prime(z));

    bn_modinv(zinv, z, consts_p()->ec_prime);
    bn_modmul_prime(x, zinv);
#ifdef EC_POWER64_RED
    bn_modred_slow(x);
#endif
}

// returns 1 if result is at infinity, 0 otherwise
//
static int ec_add (bn_t *x1,       bn_t *y1,       bn_t *z1,
             const bn_t *x2, const bn_t *y2, const bn_t *z2)
{
    bn_t a[ NWORDS ], b[ NWORDS ], c[ NWORDS ],
         bs[ NWORDS ],                     // B^2
         t1[ NWORDS ], t2[ NWORDS ];       // XXX minimize these
    int inf1, inf2;

    EC_ASSERT(NULL != x1);
    EC_ASSERT(NULL != y1);
    EC_ASSERT(NULL != z1);
    EC_ASSERT(NULL != x2);
    EC_ASSERT(NULL != y2);
    EC_ASSERT(NULL != z2);
    EC_ASSERT(!bn_ge_prime(x1));
    EC_ASSERT(!bn_ge_prime(y1));
    EC_ASSERT(!bn_ge_prime(z1));
    EC_ASSERT(!bn_ge_prime(x2));
    EC_ASSERT(!bn_ge_prime(y2));
    EC_ASSERT(!bn_ge_prime(z2));

    inf1 = ec_is_infinity(x1, y1, z1);
    inf2 = ec_is_infinity(x2, y2, z2);

    if (inf2)
    {
        return inf1;
    }

    if (inf1)
    {
        BN_COPY(x1, x2);
        BN_COPY(y1, y2);
        BN_COPY(z1, z2);
        return 0;          // (x1,y1,z1) not infinity (checked above)
    }

    if (!bn_cmp(x1, x2) && !bn_cmp(y1, y2))
    {
        return ec_double(x1, y1, z1);
    }

#ifdef EC_POWER64_ALG
    BN_COPY(t1, y1);
    bn_modmul_prime(t1, z2);    // t1 = y1 * z2
    BN_COPY(a, y2);
    bn_modmul_prime(a, z1);     // A = y2 * z1 - y1 * z2
#ifdef EC_POWER64_RED
    bn_modred_slow(t1);
#endif
    bn_modsub(a, t1);
    bn_modmul_prime(x1, z2);    // x1 := x1 * z2     orig x1 no longer used
    BN_COPY(b, x2);
    bn_modmul_prime(b, z1);
#ifdef EC_POWER64_RED
    bn_modred_slow(x1);
#endif
    bn_modsub(b, x1);           // B = x2 * z1 - x1 * z2

    BN_COPY(bs, b);
    bn_modsqr_prime(bs);        // B^2

    BN_COPY(c, a);
    bn_modsqr_prime(c);
    bn_modmul_prime(z1, z2);    // z1 = z1 * z2
    bn_modmul_prime(c, z1);     // c = A^2 * z1 * z2

    bn_modmul_prime(x1, bs);    // x1 = B^2 * x1 * z2
    BN_COPY(t2, b);
    bn_modmul_prime(t2, bs);    // t2 = B^3
#ifdef EC_POWER64_RED
    bn_modred_slow(t2);
    bn_modred_slow(x1);
#endif
    bn_modsub(c, t2);
    bn_modsub(c, x1);           // C = A^2 * z1 * z2 - B^3
    bn_modsub(c, x1);           //     - 2 B^2 * x1 * z1

    bn_modmul_prime(z1, t2);    // z1 * z2 * B^3
#ifdef EC_POWER64_RED
    bn_modred_slow(z1);
    bn_modred_slow(c);
#endif

    bn_modmul_prime(t1, t2);    // (B^3 * y1 * z2)
    // A(B 2 X1 Z2 ? C)
    bn_modsub(x1, c);
    bn_modmul_prime(x1, a);     // A * (B^2 * x1 * z2 - C)
#ifdef EC_POWER64_RED
    bn_modred_slow(x1);
    bn_modred_slow(t1);
#endif
    bn_modsub(x1, t1);          // Y = A * (B^2 * x1 * z2 - C) - (B^3 * y1 * z2)
    BN_COPY(y1, x1);

    BN_COPY(x1, b);
    bn_modmul_prime(x1, c);     // X = B * C
#ifdef EC_POWER64_RED
    bn_modred_slow(x1);
#endif

#else // !EC_POWER64_ALG
    BN_COPY(t1, y1);
    bn_modmul_prime(t1, z2);    // t1 = y1 * z2
    BN_COPY(a, y2);
    bn_modmul_prime(a, z1);     // A = y2 * z1 - y1 * z2
    bn_modsub(a, t1);

    bn_modmul_prime(x1, z2);    // x1 := x1 * z2     orig x1 no longer used
    BN_COPY(b, x2);
    bn_modmul_prime(b, z1);
    bn_modsub(b, x1);           // B = x2 * z1 - x1 * z2

    BN_COPY(bs, b);
    bn_modmul_prime(bs, bs);    // B^2

    BN_COPY(c, a);
    bn_modmul_prime(c, c);
    bn_modmul_prime(c, z1);
    bn_modmul_prime(c, z2);

    BN_COPY(t2, b);
    bn_modadd(t2, x1);
    bn_modadd(t2, x1);
    bn_modmul_prime(t2, bs);
    bn_modsub(c, t2);           // C = A^2 * z1 * z2 - B^3
                                //     - 2 B^2 * x1 * z1

    bn_modmul_prime(z1, z2);
    bn_modmul_prime(z1, b);
    bn_modmul_prime(z1, bs);    // z1 * z2 * B^3

    bn_modmul_prime(t1, b);
    bn_modmul_prime(t1, bs);    // (B^3 * y1 * z2)
    // A(B 2 X1 Z2 ? C)
    bn_modmul_prime(x1, bs);    // (B^2 * x1 * z2)
    bn_modsub(x1, c);
    bn_modmul_prime(x1, a);     // A *  (B^2 * x1 * z2 - C)
    bn_modsub(x1, t1);
    BN_COPY(y1, x1);            // Y =

    BN_COPY(x1, b);
    bn_modmul_prime(x1, c);     // X = B * C
#endif

    return 0;
}

// (x,y,z) in projective coordinates
// P521: curve has a==-3
//
// return 1 if point in infinity
//
static int ec_double (bn_t *x, bn_t *y, bn_t *z)
{
    bn_t a[ NWORDS ], b[ NWORDS ], c[ NWORDS ], d[ NWORDS ], t[ NWORDS ];

    EC_ASSERT(NULL != x);
    EC_ASSERT(NULL != y);
    EC_ASSERT(NULL != z);
    EC_ASSERT(!bn_ge_prime(x));
    EC_ASSERT(!bn_ge_prime(y));
    EC_ASSERT(!bn_ge_prime(z));

#ifdef EC_POWER64_ALG
    BN_COPY(a, x);
    BN_COPY(d, x);

    bn_modadd(a, z);
    bn_modsub(d, z);
    bn_modmul_prime(a, d);    // x^2 - z^2
    BN_COPY(d, a);
    bn_modadd(a, a);
    bn_modadd(a, d);          // A = 3 * (x^2 - z^2)
                              // P521: generally, A = 3 * x^2 - a * z^2

    BN_COPY(b, z);
    bn_modmul_prime(b, y);    // B = y * z

    BN_COPY(c, x);
    bn_modmul_prime(y, b);    // y = y * B
    bn_modmul_prime(c, y);    // C = x * y * B

    BN_COPY(z, b);
    bn_modsqr_prime(z);
    bn_modmul_prime(z, b);
    bn_modadd(z, z);
    bn_modadd(z, z);
    bn_modadd(z, z);          // Z = 8 * B^3
#ifdef EC_POWER64_RED
    bn_modred_slow(z);
#endif

    BN_COPY(t, c);
    bn_modadd(t, t);
    bn_modadd(t, t);
    bn_modadd(t, t);
    BN_COPY(d, a);
    bn_modsqr_prime(d);
#ifdef EC_POWER64_RED
    bn_modred_slow(t);
#endif
    bn_modsub(d, t);          // D = A^2 - 8*C

    BN_COPY(x, b);
    bn_modmul_prime(x, d);
    bn_modadd(x, x);          // X = 2 * B * D
#ifdef EC_POWER64_RED
    bn_modred_slow(x);
    bn_modred_slow(d);
#endif

    bn_modadd(c, c);
    bn_modadd(c, c);
    bn_modsub(c, d);
    bn_modmul_prime(a, c);    // (A * (4*C - D))

    bn_modsqr_prime(y);       // (y * B)^2
    bn_modadd(y, y);
    bn_modadd(y, y);
    bn_modadd(y, y);          // (8 * y^2 * B^2)
#ifdef EC_POWER64_RED
    bn_modred_slow(a);
    bn_modred_slow(y);
#endif
    bn_modsub(a, y);
    BN_COPY(y, a);            // Y = A * (4*C - D) - 8 * y^2 * B^2

#else // !EC_POWER64_ALG
    BN_COPY(a, x);
    BN_COPY(d, z);

    bn_modmul_prime(a, x);
    bn_modmul_prime(d, z);
    bn_modsub(a, d);
    BN_COPY(d, a);
    bn_modadd(a, a);
    bn_modadd(a, d);          // A = 3 * (x^2 - z^2)
                              // P521: generally, A = 3 * x^2 - a * z^2

    BN_COPY(b, z);
    bn_modmul_prime(b, y);    // B = y * z

    BN_COPY(c, y);
    bn_modmul_prime(c, b);
    bn_modmul_prime(c, x);    // C = x * y * B

    BN_COPY(z, b);
    bn_modmul_prime(z, b);
    bn_modmul_prime(z, b);
    bn_modadd(z, z);
    bn_modadd(z, z);
    bn_modadd(z, z);          // Z = 8 * B^3

    BN_COPY(t, c);
    bn_modadd(t, t);
    bn_modadd(t, t);
    bn_modadd(t, t);
    BN_COPY(d, a);
    bn_modmul_prime(d, a);
    bn_modsub(d, t);          // D = A^2 - 8*C

    BN_COPY(x, b);
    bn_modmul_prime(x, d);
    bn_modadd(x, x);          // X = 2 * B * D

    bn_modadd(c, c);
    bn_modadd(c, c);
    bn_modsub(c, d);
    bn_modmul_prime(a, c);    // (A * (4*C - D))

    bn_modmul_prime(y, b);
    bn_modmul_prime(y, y);
    bn_modadd(y, y);
    bn_modadd(y, y);
    bn_modadd(y, y);          // (8 * y^2 * B^2)
    bn_modsub(a, y);
    BN_COPY(y, a);            // Y = A * (4*C - D) - 8 * y^2 * B^2
#endif

    return 0;
}



// (x,y) in affine coordinates; z is output only
// returns (x,y,z) in projective coordinates
//
// we roll (x,y), updating (qx,qy) if necessary
// finally, (x,y) := (qx,qy)
//
// LIMIT: processes up to EC_PRIMEBITS in coefficient
// z and k must not overlap
//
static int ec_multiply (bn_t *x, bn_t *y, bn_t *z, const bn_t *k)
{
    bn_t px[ NWORDS ], py[ NWORDS ], pz[ NWORDS ];
    unsigned int i;
    bn_t mask = 1;

    EC_ASSERT(NULL != x);
    EC_ASSERT(NULL != y);
    EC_ASSERT(NULL != k);
    EC_ASSERT(!bn_ge_prime(x));
    EC_ASSERT(!bn_ge_prime(y));

    i=bn_bits(k);
    k += NWORDS-1;

    BN_COPY(px, x);
    BN_COPY(py, y);
    bn_clear(x);
    bn_clear(y);

    bn_clear(z);
    BN_LSW(z) = 1;       // (x,y)   -> (x, y, 1)  in projective coordinates
    BN_COPY(pz, z);      // (px,py) -> (px,py,1)

    BN_DUMP(i,x);
    BN_DUMP(i,y);
    BN_DUMP(i,z);
    BN_DUMP(i,px);
    BN_DUMP(i,py);
    BN_DUMP(i,pz);
    while (0 < i--)
    {
        if (mask & *k)
        {
            ec_add(x, y, z, px, py, pz);
        }

        if (0 < i)
        {
            ec_double(px, py, pz);
        }

        BN_DUMP(i,x);
        BN_DUMP(i,y);
        BN_DUMP(i,z);
        BN_DUMP(i,px);
        BN_DUMP(i,py);
        BN_DUMP(i,pz);
        mask <<= 1;
        if (!mask)
        {
            --k;
            mask = 1;
        }
    }
        BN_EXIT();

    return 0;
}


//=====================================================  public function  ====
asm(".globl .L.ec_verify");
int ec_verify (const unsigned char *publicpt,    /* 2*EC_COORDBYTES */
               const unsigned char *hash,        /*   EC_HASHBYTES  */
               const unsigned char *signature)   /* 2*EC_COORDBYTES */
{
    bn_t r[ NWORDS ],  s[ NWORDS ],  e[ NWORDS ],
    px[ NWORDS ], py[ NWORDS ], pz[ NWORDS ],
    u1[ NWORDS ], u2[ NWORDS ];

    if ((NULL == publicpt) || (NULL == signature) || (NULL == hash))
    {
        return -1;
    }

    bn_read_pt  (r,  signature);
    bn_read_pt  (s,  signature +EC_COORDBYTES);
    bn_read_hash(e,  hash);
    bn_read_pt  (px, publicpt);
    bn_read_pt  (py, publicpt +EC_COORDBYTES);

    if (bn_ge_order(r)  || bn_ge_order(s)  ||
        bn_is_zero(s,0) || bn_is_zero(r,0))
    {
        return 0;                // assume user messed with signature
    }

    if (bn_ge_prime(px)  || bn_ge_prime(py)  ||
        bn_is_zero(px,0) || bn_is_zero(py,0))
    {
        return -1;               // admin fault; should not happen
    }

    bn_modinv(u1, s, consts_p()->ec_order);      // s no longer needed (NLN)
    BN_COPY(u2, r);
    bn_modmul_order(u2, u1);
    bn_modmul_order(u1, e);          // e NLN

    // reuse (e,s) for base multiplication
    BN_COPY(e, consts_p()->prime_px);            // (e,s) <- (base point)
    BN_COPY(s, consts_p()->prime_py);

    ec_multiply(px, py, pz, u2);     // (px,py,pz) = u2 * (px,py);  u2 NLN
    ec_multiply(e,  s,  u2, u1);     // (s, e, u2) = u1 * (gx,gy);  u1 NLN

    if (ec_add(px, py, pz, e, s, u2))  // u1 * base + u2 * public
    {
        return 0;                  // reached infinity (SNH with sig)
    }

    ec_projective2affine(px, pz);

    if (bn_ge_order(px))
    {
        bn_sub(px, consts_p()->ec_order);    // px mod order
    }

    return (! bn_cmp(r, px));
}


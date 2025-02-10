/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/contrib/v3_mlca/qsc/crystals/polyvec-include.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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
/* Copyright (c) 2000-2001, Aaron D. Gifford                              */
/* All rights reserved.                                                   */
/*                                                                        */
/* Redistribution and use in source and binary forms, with or without     */
/* modification, are permitted provided that the following conditions     */
/* are met:                                                               */
/* 1. Redistributions of source code must retain the above copyright      */
/*    notice, this list of conditions and the following disclaimer.       */
/* 2. Redistributions in binary form must reproduce the above copyright   */
/*    notice, this list of conditions and the following disclaimer in     */
/*    the documentation and/or other materials provided with the          */
/*    distribution.                                                       */
/* 3. Neither the name of the copyright holder nor the names of           */
/*    contributors may be used to endorse or promote products derived     */
/*    from this software without specific prior written permission.       */
/*                                                                        */
/* THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS''   */
/* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  */
/* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A            */
/* PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR    */
/* CONTRIBUTOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,         */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
/* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  */
/* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
/*                                                                        */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// SPDX-License-Identifier: Apache-2.0

/* generated code follows, please do not modify */

#if !defined(NO_CRYSTALS_SIG)    /* Dilithium */
typedef struct {
	poly vec[ 4 ];
} polyvec4 ;


typedef struct {
	poly vec[ 5 ];
} polyvec5 ;


typedef struct {
	poly vec[ 6 ];
} polyvec6 ;


typedef struct {
	poly vec[ 7 ];
} polyvec7 ;


typedef struct {
	poly vec[ 8 ];
} polyvec8 ;


/*------------------------------------*/
static void 
polyvec4_freeze(polyvec4 *pv)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		poly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec4_add(polyvec4 *r, const polyvec4 *u, const polyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		poly_add(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec4_ntt(polyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		poly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
polyvec4_chknorm(const polyvec4 *v, uint32_t bound)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		if (poly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
polyvec5_freeze(polyvec5 *pv)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		poly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_add(polyvec5 *r, const polyvec5 *u, const polyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		poly_add(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_ntt(polyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		poly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
polyvec5_chknorm(const polyvec5 *v, uint32_t bound)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		if (poly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
polyvec6_freeze(polyvec6 *pv)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		poly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_add(polyvec6 *r, const polyvec6 *u, const polyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		poly_add(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_ntt(polyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		poly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
polyvec6_chknorm(const polyvec6 *v, uint32_t bound)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		if (poly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
polyvec7_freeze(polyvec7 *pv)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		poly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec7_add(polyvec7 *r, const polyvec7 *u, const polyvec7 *v)
{
	unsigned int k;

	for (k = 0; k < 7; ++k) {
		poly_add(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec7_ntt(polyvec7 *v)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		poly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
polyvec7_chknorm(const polyvec7 *v, uint32_t bound)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		if (poly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
polyvec8_freeze(polyvec8 *pv)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		poly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_add(polyvec8 *r, const polyvec8 *u, const polyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		poly_add(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_ntt(polyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		poly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
polyvec8_chknorm(const polyvec8 *v, uint32_t bound)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		if (poly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
expand_matrix_5x4(polyvec_max mat[ 5 ], const unsigned char rho[ DIL_SEEDBYTES ])
{
	unsigned int k, l;

	for (k = 0; k < 5; ++k) {
		for (l = 0; l < 4; ++l) {
			poly_uniform(&( mat[k].vec[l] ), rho, (k <<8) +l);
		}
	}
}


/*------------------------------------*/
static unsigned int 
polyvec5_make_hint(polyvec5 *h,
             const polyvec5 *v0,
             const polyvec5 *v1)
{
	unsigned int i, nr = 0;

	for (i = 0; i < 5; ++i) {
		nr += poly_make_hint(&(  h->vec[i] ),
		                     &( v0->vec[i] ),
		                     &( v1->vec[i] ));
	}

	return nr;
}


/*------------------------------------*/
static void 
polyvec5_use_hint(polyvec5 *r,
            const polyvec5 *u,
            const polyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		poly_use_hint(&( r->vec[k] ),
		              &( u->vec[k] ),
		              &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_decompose(polyvec5 *v1,
                   polyvec5 *v0,
             const polyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		poly_decompose(&( v1->vec[k] ),
		               &( v0->vec[k] ),
		               &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_power2round(polyvec5 *v1,
                     polyvec5 *v0,
               const polyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		poly_power2round(&( v1->vec[k] ),
		                 &( v0->vec[k] ),
		                 &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_shiftl(polyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		poly_shiftl(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_sub(polyvec5 *r, const polyvec5 *u, const polyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		poly_sub(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_reduce(polyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		poly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_csubq(polyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		poly_csubq(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec5_invntt_tomont(polyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		poly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
pack_pk5(unsigned char pk [ DIL_PUB5x4_BYTES ],
   const unsigned char rho[ DIL_SEEDBYTES ],
        const polyvec5 *t1)
{
	unsigned int k;

	memmove(pk, rho, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 5; ++k) {
		polyt1_pack(pk +k *DIL_R2_POLYT1_PACKEDBYTES, &(t1->vec[k]));
	}
}


/*------------------------------------*/
static void 
unpack_pk5(unsigned char rho[ DIL_SEEDBYTES ],
                polyvec5 *t1,
     const unsigned char pk[ DIL_PUB5x4_BYTES ])
{
	unsigned int k;

	memmove(rho, pk, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 5; ++k) {
		polyt1_unpack(&(t1->vec[k]), pk +k *DIL_R2_POLYT1_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
pack_prv5(unsigned char prv[ DIL_PRV5x4_BYTES ],
    const unsigned char rho[ DIL_SEEDBYTES ],
    const unsigned char key[ DIL_SEEDBYTES ],
    const unsigned char tr [ DIL_CRHBYTES ],
         const polyvec4 *s1,
         const polyvec5 *s2,
         const polyvec5 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_CRHBYTES);
	prv += DIL_CRHBYTES;

	for (i = 0; i < 4; ++i) {
		polyeta_pack(prv +i *DIL_POLYETA5x4_PACKEDBYTES,
		             &(s1->vec[i]), 5 /* eta(K=5) */);
	}
	prv += 4 * DIL_POLYETA5x4_PACKEDBYTES;  /*L*/

	for (i = 0; i < 5; ++i) {
		polyeta_pack(prv +i *DIL_POLYETA5x4_PACKEDBYTES,
		             &(s2->vec[i]), 5 /* eta(k=5) */);
	}
	prv += 5 * DIL_POLYETA5x4_PACKEDBYTES;  /*K*/

	for (i = 0; i < 5; ++i) {
		polyt0_pack(prv +i *DIL_R2_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}


/*------------------------------------*/
static void 
unpack_prv5(unsigned char rho[ DIL_SEEDBYTES ],
            unsigned char key[ DIL_SEEDBYTES ],
            unsigned char tr [ DIL_CRHBYTES ],
                 polyvec4 *s1,
                 polyvec5 *s2,
                 polyvec5 *t0,
      const unsigned char prv[ DIL_PRV5x4_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_CRHBYTES);
	prv += DIL_CRHBYTES;

	for (i = 0; i < 4; ++i) {
		polyeta_unpack(&( s1->vec[i] ),
		               prv +i *DIL_POLYETA5x4_PACKEDBYTES, 5);
	}
	prv += 4 * DIL_POLYETA5x4_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 5; ++i) {
		polyeta_unpack(&( s2->vec[i] ),
		               prv +i *DIL_POLYETA5x4_PACKEDBYTES, 5);
	}
	prv += 5 * DIL_POLYETA5x4_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 5; ++i) {
		polyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R2_POLYT0_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
polyvec4_pointwise_acc_montgomery(poly *w,
                        const polyvec4 *u,
                        const polyvec4 *v)
{
	unsigned int i;
	poly tmp;

	poly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 4; ++i) {
		poly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		poly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
expand_matrix_6x5(polyvec_max mat[ 6 ], const unsigned char rho[ DIL_SEEDBYTES ])
{
	unsigned int k, l;

	for (k = 0; k < 6; ++k) {
		for (l = 0; l < 5; ++l) {
			poly_uniform(&( mat[k].vec[l] ), rho, (k <<8) +l);
		}
	}
}


/*------------------------------------*/
static unsigned int 
polyvec6_make_hint(polyvec6 *h,
             const polyvec6 *v0,
             const polyvec6 *v1)
{
	unsigned int i, nr = 0;

	for (i = 0; i < 6; ++i) {
		nr += poly_make_hint(&(  h->vec[i] ),
		                     &( v0->vec[i] ),
		                     &( v1->vec[i] ));
	}

	return nr;
}


/*------------------------------------*/
static void 
polyvec6_use_hint(polyvec6 *r,
            const polyvec6 *u,
            const polyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		poly_use_hint(&( r->vec[k] ),
		              &( u->vec[k] ),
		              &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_decompose(polyvec6 *v1,
                   polyvec6 *v0,
             const polyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		poly_decompose(&( v1->vec[k] ),
		               &( v0->vec[k] ),
		               &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_power2round(polyvec6 *v1,
                     polyvec6 *v0,
               const polyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		poly_power2round(&( v1->vec[k] ),
		                 &( v0->vec[k] ),
		                 &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_shiftl(polyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		poly_shiftl(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_sub(polyvec6 *r, const polyvec6 *u, const polyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		poly_sub(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_reduce(polyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		poly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_csubq(polyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		poly_csubq(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec6_invntt_tomont(polyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		poly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
pack_pk6(unsigned char pk [ DIL_PUB6x5_BYTES ],
   const unsigned char rho[ DIL_SEEDBYTES ],
        const polyvec6 *t1)
{
	unsigned int k;

	memmove(pk, rho, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 6; ++k) {
		polyt1_pack(pk +k *DIL_R2_POLYT1_PACKEDBYTES, &(t1->vec[k]));
	}
}


/*------------------------------------*/
static void 
unpack_pk6(unsigned char rho[ DIL_SEEDBYTES ],
                polyvec6 *t1,
     const unsigned char pk[ DIL_PUB6x5_BYTES ])
{
	unsigned int k;

	memmove(rho, pk, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 6; ++k) {
		polyt1_unpack(&(t1->vec[k]), pk +k *DIL_R2_POLYT1_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
pack_prv6(unsigned char prv[ DIL_PRV6x5_BYTES ],
    const unsigned char rho[ DIL_SEEDBYTES ],
    const unsigned char key[ DIL_SEEDBYTES ],
    const unsigned char tr [ DIL_CRHBYTES ],
         const polyvec5 *s1,
         const polyvec6 *s2,
         const polyvec6 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_CRHBYTES);
	prv += DIL_CRHBYTES;

	for (i = 0; i < 5; ++i) {
		polyeta_pack(prv +i *DIL_POLYETA6x5_PACKEDBYTES,
		             &(s1->vec[i]), 3 /* eta(K=6) */);
	}
	prv += 5 * DIL_POLYETA6x5_PACKEDBYTES;  /*L*/

	for (i = 0; i < 6; ++i) {
		polyeta_pack(prv +i *DIL_POLYETA6x5_PACKEDBYTES,
		             &(s2->vec[i]), 3 /* eta(k=6) */);
	}
	prv += 6 * DIL_POLYETA6x5_PACKEDBYTES;  /*K*/

	for (i = 0; i < 6; ++i) {
		polyt0_pack(prv +i *DIL_R2_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}


/*------------------------------------*/
static void 
unpack_prv6(unsigned char rho[ DIL_SEEDBYTES ],
            unsigned char key[ DIL_SEEDBYTES ],
            unsigned char tr [ DIL_CRHBYTES ],
                 polyvec5 *s1,
                 polyvec6 *s2,
                 polyvec6 *t0,
      const unsigned char prv[ DIL_PRV6x5_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_CRHBYTES);
	prv += DIL_CRHBYTES;

	for (i = 0; i < 5; ++i) {
		polyeta_unpack(&( s1->vec[i] ),
		               prv +i *DIL_POLYETA6x5_PACKEDBYTES, 3);
	}
	prv += 5 * DIL_POLYETA6x5_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 6; ++i) {
		polyeta_unpack(&( s2->vec[i] ),
		               prv +i *DIL_POLYETA6x5_PACKEDBYTES, 3);
	}
	prv += 6 * DIL_POLYETA6x5_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 6; ++i) {
		polyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R2_POLYT0_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
polyvec5_pointwise_acc_montgomery(poly *w,
                        const polyvec5 *u,
                        const polyvec5 *v)
{
	unsigned int i;
	poly tmp;

	poly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 5; ++i) {
		poly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		poly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
expand_matrix_8x7(polyvec_max mat[ 8 ], const unsigned char rho[ DIL_SEEDBYTES ])
{
	unsigned int k, l;

	for (k = 0; k < 8; ++k) {
		for (l = 0; l < 7; ++l) {
			poly_uniform(&( mat[k].vec[l] ), rho, (k <<8) +l);
		}
	}
}


/*------------------------------------*/
static unsigned int 
polyvec8_make_hint(polyvec8 *h,
             const polyvec8 *v0,
             const polyvec8 *v1)
{
	unsigned int i, nr = 0;

	for (i = 0; i < 8; ++i) {
		nr += poly_make_hint(&(  h->vec[i] ),
		                     &( v0->vec[i] ),
		                     &( v1->vec[i] ));
	}

	return nr;
}


/*------------------------------------*/
static void 
polyvec8_use_hint(polyvec8 *r,
            const polyvec8 *u,
            const polyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		poly_use_hint(&( r->vec[k] ),
		              &( u->vec[k] ),
		              &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_decompose(polyvec8 *v1,
                   polyvec8 *v0,
             const polyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		poly_decompose(&( v1->vec[k] ),
		               &( v0->vec[k] ),
		               &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_power2round(polyvec8 *v1,
                     polyvec8 *v0,
               const polyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		poly_power2round(&( v1->vec[k] ),
		                 &( v0->vec[k] ),
		                 &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_shiftl(polyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		poly_shiftl(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_sub(polyvec8 *r, const polyvec8 *u, const polyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		poly_sub(&( r->vec[k] ),
		         &( u->vec[k] ),
		         &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_reduce(polyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		poly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_csubq(polyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		poly_csubq(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
polyvec8_invntt_tomont(polyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		poly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
pack_pk8(unsigned char pk [ DIL_PUB8x7_BYTES ],
   const unsigned char rho[ DIL_SEEDBYTES ],
        const polyvec8 *t1)
{
	unsigned int k;

	memmove(pk, rho, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 8; ++k) {
		polyt1_pack(pk +k *DIL_R2_POLYT1_PACKEDBYTES, &(t1->vec[k]));
	}
}


/*------------------------------------*/
static void 
unpack_pk8(unsigned char rho[ DIL_SEEDBYTES ],
                polyvec8 *t1,
     const unsigned char pk[ DIL_PUB8x7_BYTES ])
{
	unsigned int k;

	memmove(rho, pk, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 8; ++k) {
		polyt1_unpack(&(t1->vec[k]), pk +k *DIL_R2_POLYT1_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
pack_prv8(unsigned char prv[ DIL_PRV8x7_BYTES ],
    const unsigned char rho[ DIL_SEEDBYTES ],
    const unsigned char key[ DIL_SEEDBYTES ],
    const unsigned char tr [ DIL_CRHBYTES ],
         const polyvec7 *s1,
         const polyvec8 *s2,
         const polyvec8 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_CRHBYTES);
	prv += DIL_CRHBYTES;

	for (i = 0; i < 7; ++i) {
		polyeta_pack(prv +i *DIL_POLYETA8x7_PACKEDBYTES,
		             &(s1->vec[i]), 2 /* eta(K=8) */);
	}
	prv += 7 * DIL_POLYETA8x7_PACKEDBYTES;  /*L*/

	for (i = 0; i < 8; ++i) {
		polyeta_pack(prv +i *DIL_POLYETA8x7_PACKEDBYTES,
		             &(s2->vec[i]), 2 /* eta(k=8) */);
	}
	prv += 8 * DIL_POLYETA8x7_PACKEDBYTES;  /*K*/

	for (i = 0; i < 8; ++i) {
		polyt0_pack(prv +i *DIL_R2_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}


/*------------------------------------*/
static void 
unpack_prv8(unsigned char rho[ DIL_SEEDBYTES ],
            unsigned char key[ DIL_SEEDBYTES ],
            unsigned char tr [ DIL_CRHBYTES ],
                 polyvec7 *s1,
                 polyvec8 *s2,
                 polyvec8 *t0,
      const unsigned char prv[ DIL_PRV8x7_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_CRHBYTES);
	prv += DIL_CRHBYTES;

	for (i = 0; i < 7; ++i) {
		polyeta_unpack(&( s1->vec[i] ),
		               prv +i *DIL_POLYETA8x7_PACKEDBYTES, 2);
	}
	prv += 7 * DIL_POLYETA8x7_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 8; ++i) {
		polyeta_unpack(&( s2->vec[i] ),
		               prv +i *DIL_POLYETA8x7_PACKEDBYTES, 2);
	}
	prv += 8 * DIL_POLYETA8x7_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 8; ++i) {
		polyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R2_POLYT0_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
polyvec7_pointwise_acc_montgomery(poly *w,
                        const polyvec7 *u,
                        const polyvec7 *v)
{
	unsigned int i;
	poly tmp;

	poly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 7; ++i) {
		poly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		poly_add(w, w, &tmp);
	}
}


#if 1 || defined(DILITHIUM_ROUND3)
typedef struct {
	spoly vec[ 4 ];
} spolyvec4 ;


typedef struct {
	spoly vec[ 5 ];
} spolyvec5 ;


typedef struct {
	spoly vec[ 6 ];
} spolyvec6 ;


typedef struct {
	spoly vec[ 7 ];
} spolyvec7 ;


typedef struct {
	spoly vec[ 8 ];
} spolyvec8 ;


/*------------------------------------*/
static void 
spolyvec4_freeze(spolyvec4 *pv)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		spoly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_add(spolyvec4 *r, const spolyvec4 *u, const spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_ntt(spolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		spoly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
spolyvec4_chknorm(const spolyvec4 *v, int32_t bound)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		if (spoly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
spolyvec4_reduce(spolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		spoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_uniform_eta(spolyvec4 *v,
            const unsigned char seed[ DIL_SEEDBYTES ],
                       uint16_t nonce,
                   unsigned int eta)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		spoly_uniform_eta(&( v->vec[i] ), seed, nonce++, eta);
	}
}


/*------------------------------------*/
static void 
spolyvec4_invntt_tomont(spolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		spoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_pointwise_poly_montgomery(spolyvec4 *r,
                                  const spoly *a,
                              const spolyvec4 *v)
{
	unsigned int n;

	for (n = 0; n < 4; ++n) {
		spoly_pointwise_montgomery(&(r->vec[n]), a, &(v->vec[n]));
	}
}


/*------------------------------------*/
static void 
spolyvec4_pointwise_acc_montgomery(spoly *w,
                         const spolyvec4 *u,
                         const spolyvec4 *v)
{
	unsigned int i;
	spoly tmp;

	spoly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 4; ++i) {
		spoly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		spoly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
spolyvec5_freeze(spolyvec5 *pv)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		spoly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec5_add(spolyvec5 *r, const spolyvec5 *u, const spolyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 5; ++k) {
		spoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec5_ntt(spolyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		spoly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
spolyvec5_chknorm(const spolyvec5 *v, int32_t bound)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		if (spoly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
spolyvec5_reduce(spolyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		spoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec5_uniform_eta(spolyvec5 *v,
            const unsigned char seed[ DIL_SEEDBYTES ],
                       uint16_t nonce,
                   unsigned int eta)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		spoly_uniform_eta(&( v->vec[i] ), seed, nonce++, eta);
	}
}


/*------------------------------------*/
static void 
spolyvec5_invntt_tomont(spolyvec5 *v)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		spoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec5_pointwise_poly_montgomery(spolyvec5 *r,
                                  const spoly *a,
                              const spolyvec5 *v)
{
	unsigned int n;

	for (n = 0; n < 5; ++n) {
		spoly_pointwise_montgomery(&(r->vec[n]), a, &(v->vec[n]));
	}
}


/*------------------------------------*/
static void 
spolyvec5_pointwise_acc_montgomery(spoly *w,
                         const spolyvec5 *u,
                         const spolyvec5 *v)
{
	unsigned int i;
	spoly tmp;

	spoly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 5; ++i) {
		spoly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		spoly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
spolyvec6_freeze(spolyvec6 *pv)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		spoly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_add(spolyvec6 *r, const spolyvec6 *u, const spolyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_ntt(spolyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		spoly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
spolyvec6_chknorm(const spolyvec6 *v, int32_t bound)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		if (spoly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
spolyvec6_reduce(spolyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		spoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_uniform_eta(spolyvec6 *v,
            const unsigned char seed[ DIL_SEEDBYTES ],
                       uint16_t nonce,
                   unsigned int eta)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		spoly_uniform_eta(&( v->vec[i] ), seed, nonce++, eta);
	}
}


/*------------------------------------*/
static void 
spolyvec6_invntt_tomont(spolyvec6 *v)
{
	unsigned int i;

	for (i = 0; i < 6; ++i) {
		spoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_pointwise_poly_montgomery(spolyvec6 *r,
                                  const spoly *a,
                              const spolyvec6 *v)
{
	unsigned int n;

	for (n = 0; n < 6; ++n) {
		spoly_pointwise_montgomery(&(r->vec[n]), a, &(v->vec[n]));
	}
}


/*------------------------------------*/
static void 
spolyvec6_pointwise_acc_montgomery(spoly *w,
                         const spolyvec6 *u,
                         const spolyvec6 *v)
{
	unsigned int i;
	spoly tmp;

	spoly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 6; ++i) {
		spoly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		spoly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
spolyvec7_freeze(spolyvec7 *pv)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		spoly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec7_add(spolyvec7 *r, const spolyvec7 *u, const spolyvec7 *v)
{
	unsigned int k;

	for (k = 0; k < 7; ++k) {
		spoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec7_ntt(spolyvec7 *v)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		spoly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
spolyvec7_chknorm(const spolyvec7 *v, int32_t bound)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		if (spoly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
spolyvec7_reduce(spolyvec7 *v)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		spoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec7_uniform_eta(spolyvec7 *v,
            const unsigned char seed[ DIL_SEEDBYTES ],
                       uint16_t nonce,
                   unsigned int eta)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		spoly_uniform_eta(&( v->vec[i] ), seed, nonce++, eta);
	}
}


/*------------------------------------*/
static void 
spolyvec7_invntt_tomont(spolyvec7 *v)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		spoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec7_pointwise_poly_montgomery(spolyvec7 *r,
                                  const spoly *a,
                              const spolyvec7 *v)
{
	unsigned int n;

	for (n = 0; n < 7; ++n) {
		spoly_pointwise_montgomery(&(r->vec[n]), a, &(v->vec[n]));
	}
}


/*------------------------------------*/
static void 
spolyvec7_pointwise_acc_montgomery(spoly *w,
                         const spolyvec7 *u,
                         const spolyvec7 *v)
{
	unsigned int i;
	spoly tmp;

	spoly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 7; ++i) {
		spoly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		spoly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
spolyvec8_freeze(spolyvec8 *pv)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		spoly_freeze(&( pv->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_add(spolyvec8 *r, const spolyvec8 *u, const spolyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_ntt(spolyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		spoly_ntt256(&( v->vec[i] ));
	}
}


/*------------------------------------*/
ATTR_PURE__ static unsigned int 
spolyvec8_chknorm(const spolyvec8 *v, int32_t bound)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		if (spoly_chknorm(&( v->vec[i] ), bound))
			return 1;
	}

	return 0;
}


/*------------------------------------*/
static void 
spolyvec8_reduce(spolyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		spoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_uniform_eta(spolyvec8 *v,
            const unsigned char seed[ DIL_SEEDBYTES ],
                       uint16_t nonce,
                   unsigned int eta)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		spoly_uniform_eta(&( v->vec[i] ), seed, nonce++, eta);
	}
}


/*------------------------------------*/
static void 
spolyvec8_invntt_tomont(spolyvec8 *v)
{
	unsigned int i;

	for (i = 0; i < 8; ++i) {
		spoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_pointwise_poly_montgomery(spolyvec8 *r,
                                  const spoly *a,
                              const spolyvec8 *v)
{
	unsigned int n;

	for (n = 0; n < 8; ++n) {
		spoly_pointwise_montgomery(&(r->vec[n]), a, &(v->vec[n]));
	}
}


/*------------------------------------*/
static void 
spolyvec8_pointwise_acc_montgomery(spoly *w,
                         const spolyvec8 *u,
                         const spolyvec8 *v)
{
	unsigned int i;
	spoly tmp;

	spoly_pointwise_montgomery(w, &(u->vec[0]), &(v->vec[0]));

	for (i = 1; i < 8; ++i) {
		spoly_pointwise_montgomery(&tmp, &(u->vec[i]), &(v->vec[i]));
		spoly_add(w, w, &tmp);
	}
}


/*------------------------------------*/
static void 
expand_smatrix_4x4(spolyvec_max mat[ 4 ], const unsigned char rho[ DIL_SEEDBYTES ])
{
	unsigned int k, l;

	for (k = 0; k < 4; ++k) {
		for (l = 0; l < 4; ++l) {
			spoly_uniform(&( mat[k].vec[l] ), rho, (k <<8) +l);
		}
	}
}


/*------------------------------------*/
static void 
spolyvec4x4_matrix_pointwise_montgomery(spolyvec4 *t,
                               const spolyvec_max *mat,  /* use x4 */
                                  const spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spolyvec4_pointwise_acc_montgomery(&(t->vec[k]), 
		               (const spolyvec4 *) &(mat[k]), v) ;
	}
}


/*------------------------------------*/
static void 
spack_prv4(unsigned char prv[ DIL_R3_PRV4x4_BYTES ],
     const unsigned char rho[ DIL_SEEDBYTES ],
     const unsigned char key[ DIL_SEEDBYTES ],
     const unsigned char tr [ DIL_SEEDBYTES ],
         const spolyvec4 *s1,
         const spolyvec4 *s2,
         const spolyvec4 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	for (i = 0; i < 4; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES,
		              &(s1->vec[i]), 2 /* eta(K=4) */);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*L*/

	for (i = 0; i < 4; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES,
		              &(s2->vec[i]), 2 /* eta(k=4) */);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*K*/

	for (i = 0; i < 4; ++i) {
		spolyt0_pack(prv +i *DIL_R3_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}

/*------------------------------------*/
static void 
ml_spack_prv4(unsigned char prv[ DIL_MLDSA_PRV4x4_BYTES ],
     const unsigned char rho[ DIL_SEEDBYTES ],
     const unsigned char key[ DIL_SEEDBYTES ],
     const unsigned char tr [ DIL_MLDSA_TRBYTES ],
         const spolyvec4 *s1,
         const spolyvec4 *s2,
         const spolyvec4 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_MLDSA_TRBYTES);
	prv += DIL_MLDSA_TRBYTES;

	for (i = 0; i < 4; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES,
		              &(s1->vec[i]), 2 /* eta(K=4) */);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*L*/

	for (i = 0; i < 4; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES,
		              &(s2->vec[i]), 2 /* eta(k=4) */);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*K*/

	for (i = 0; i < 4; ++i) {
		spolyt0_pack(prv +i *DIL_R3_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}


/*------------------------------------*/
static void 
sunpack_prv4(unsigned char rho[ DIL_SEEDBYTES ],
             unsigned char key[ DIL_SEEDBYTES ],
             unsigned char tr [ DIL_SEEDBYTES ],
                 spolyvec4 *s1,
                 spolyvec4 *s2,
                 spolyvec4 *t0,
       const unsigned char prv[ DIL_R3_PRV4x4_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	for (i = 0; i < 4; ++i) {
		spolyeta_unpack(&( s1->vec[i] ),
		                prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES, 2);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 4; ++i) {
		spolyeta_unpack(&( s2->vec[i] ),
		                prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES, 2);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 4; ++i) {
		spolyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R3_POLYT0_PACKEDBYTES);
	}
}

static void 
ml_sunpack_prv4(unsigned char rho[ DIL_SEEDBYTES ],
             unsigned char key[ DIL_SEEDBYTES ],
             unsigned char tr [ DIL_MLDSA_TRBYTES ],
                 spolyvec4 *s1,
                 spolyvec4 *s2,
                 spolyvec4 *t0,
       const unsigned char prv[ DIL_MLDSA_PRV4x4_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_MLDSA_TRBYTES);
	prv += DIL_MLDSA_TRBYTES;

	for (i = 0; i < 4; ++i) {
		spolyeta_unpack(&( s1->vec[i] ),
		                prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES, 2);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 4; ++i) {
		spolyeta_unpack(&( s2->vec[i] ),
		                prv +i *DIL_R3_POLYETA4x4_PACKEDBYTES, 2);
	}
	prv += 4 * DIL_R3_POLYETA4x4_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 4; ++i) {
		spolyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R3_POLYT0_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
expand_smatrix_6x5(spolyvec_max mat[ 6 ], const unsigned char rho[ DIL_SEEDBYTES ])
{
	unsigned int k, l;

	for (k = 0; k < 6; ++k) {
		for (l = 0; l < 5; ++l) {
			spoly_uniform(&( mat[k].vec[l] ), rho, (k <<8) +l);
		}
	}
}


/*------------------------------------*/
static void 
spolyvec6x5_matrix_pointwise_montgomery(spolyvec6 *t,
                               const spolyvec_max *mat,  /* use x6 */
                                  const spolyvec5 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spolyvec5_pointwise_acc_montgomery(&(t->vec[k]), 
		               (const spolyvec5 *) &(mat[k]), v) ;
	}
}


/*------------------------------------*/
static void 
spack_prv6(unsigned char prv[ DIL_R3_PRV6x5_BYTES ],
     const unsigned char rho[ DIL_SEEDBYTES ],
     const unsigned char key[ DIL_SEEDBYTES ],
     const unsigned char tr [ DIL_SEEDBYTES ],
         const spolyvec5 *s1,
         const spolyvec6 *s2,
         const spolyvec6 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	for (i = 0; i < 5; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES,
		              &(s1->vec[i]), 4 /* eta(K=6) */);
	}
	prv += 5 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*L*/

	for (i = 0; i < 6; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES,
		              &(s2->vec[i]), 4 /* eta(k=6) */);
	}
	prv += 6 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*K*/

	for (i = 0; i < 6; ++i) {
		spolyt0_pack(prv +i *DIL_R3_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}

static void 
ml_spack_prv6(unsigned char prv[ DIL_MLDSA_PRV6x5_BYTES ],
     const unsigned char rho[ DIL_SEEDBYTES ],
     const unsigned char key[ DIL_SEEDBYTES ],
     const unsigned char tr [ DIL_MLDSA_TRBYTES ],
         const spolyvec5 *s1,
         const spolyvec6 *s2,
         const spolyvec6 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_MLDSA_TRBYTES);
	prv += DIL_MLDSA_TRBYTES;

	for (i = 0; i < 5; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES,
		              &(s1->vec[i]), 4 /* eta(K=6) */);
	}
	prv += 5 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*L*/

	for (i = 0; i < 6; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES,
		              &(s2->vec[i]), 4 /* eta(k=6) */);
	}
	prv += 6 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*K*/

	for (i = 0; i < 6; ++i) {
		spolyt0_pack(prv +i *DIL_R3_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}


/*------------------------------------*/
static void 
sunpack_prv6(unsigned char rho[ DIL_SEEDBYTES ],
             unsigned char key[ DIL_SEEDBYTES ],
             unsigned char tr [ DIL_SEEDBYTES ],
                 spolyvec5 *s1,
                 spolyvec6 *s2,
                 spolyvec6 *t0,
       const unsigned char prv[ DIL_R3_PRV6x5_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	for (i = 0; i < 5; ++i) {
		spolyeta_unpack(&( s1->vec[i] ),
		                prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES, 4);
	}
	prv += 5 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 6; ++i) {
		spolyeta_unpack(&( s2->vec[i] ),
		                prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES, 4);
	}
	prv += 6 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 6; ++i) {
		spolyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R3_POLYT0_PACKEDBYTES);
	}
}

static void 
ml_sunpack_prv6(unsigned char rho[ DIL_SEEDBYTES ],
             unsigned char key[ DIL_SEEDBYTES ],
             unsigned char tr [ DIL_MLDSA_TRBYTES ],
                 spolyvec5 *s1,
                 spolyvec6 *s2,
                 spolyvec6 *t0,
       const unsigned char prv[ DIL_MLDSA_PRV6x5_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_MLDSA_TRBYTES);
	prv += DIL_MLDSA_TRBYTES;

	for (i = 0; i < 5; ++i) {
		spolyeta_unpack(&( s1->vec[i] ),
		                prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES, 4);
	}
	prv += 5 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 6; ++i) {
		spolyeta_unpack(&( s2->vec[i] ),
		                prv +i *DIL_R3_POLYETA6x5_PACKEDBYTES, 4);
	}
	prv += 6 * DIL_R3_POLYETA6x5_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 6; ++i) {
		spolyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R3_POLYT0_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
expand_smatrix_8x7(spolyvec_max mat[ 8 ], const unsigned char rho[ DIL_SEEDBYTES ])
{
	unsigned int k, l;

	for (k = 0; k < 8; ++k) {
		for (l = 0; l < 7; ++l) {
			spoly_uniform(&( mat[k].vec[l] ), rho, (k <<8) +l);
		}
	}
}


/*------------------------------------*/
static void 
spolyvec8x7_matrix_pointwise_montgomery(spolyvec8 *t,
                               const spolyvec_max *mat,  /* use x8 */
                                  const spolyvec7 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spolyvec7_pointwise_acc_montgomery(&(t->vec[k]), 
		               (const spolyvec7 *) &(mat[k]), v) ;
	}
}


/*------------------------------------*/
static void 
spack_prv8(unsigned char prv[ DIL_R3_PRV8x7_BYTES ],
     const unsigned char rho[ DIL_SEEDBYTES ],
     const unsigned char key[ DIL_SEEDBYTES ],
     const unsigned char tr [ DIL_SEEDBYTES ],
         const spolyvec7 *s1,
         const spolyvec8 *s2,
         const spolyvec8 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	for (i = 0; i < 7; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES,
		              &(s1->vec[i]), 2 /* eta(K=8) */);
	}
	prv += 7 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*L*/

	for (i = 0; i < 8; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES,
		              &(s2->vec[i]), 2 /* eta(k=8) */);
	}
	prv += 8 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*K*/

	for (i = 0; i < 8; ++i) {
		spolyt0_pack(prv +i *DIL_R3_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}

static void 
ml_spack_prv8(unsigned char prv[ DIL_MLDSA_PRV8x7_BYTES ],
     const unsigned char rho[ DIL_SEEDBYTES ],
     const unsigned char key[ DIL_SEEDBYTES ],
     const unsigned char tr [ DIL_MLDSA_TRBYTES ],
         const spolyvec7 *s1,
         const spolyvec8 *s2,
         const spolyvec8 *t0)
{
	unsigned int i;

	memmove(prv, rho, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, key, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(prv, tr,  DIL_MLDSA_TRBYTES);
	prv += DIL_MLDSA_TRBYTES;

	for (i = 0; i < 7; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES,
		              &(s1->vec[i]), 2 /* eta(K=8) */);
	}
	prv += 7 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*L*/

	for (i = 0; i < 8; ++i) {
		spolyeta_pack(prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES,
		              &(s2->vec[i]), 2 /* eta(k=8) */);
	}
	prv += 8 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*K*/

	for (i = 0; i < 8; ++i) {
		spolyt0_pack(prv +i *DIL_R3_POLYT0_PACKEDBYTES, &(t0->vec[i]));
	}
}


/*------------------------------------*/
static void 
sunpack_prv8(unsigned char rho[ DIL_SEEDBYTES ],
             unsigned char key[ DIL_SEEDBYTES ],
             unsigned char tr [ DIL_SEEDBYTES ],
                 spolyvec7 *s1,
                 spolyvec8 *s2,
                 spolyvec8 *t0,
       const unsigned char prv[ DIL_R3_PRV8x7_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	for (i = 0; i < 7; ++i) {
		spolyeta_unpack(&( s1->vec[i] ),
		                prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES, 2);
	}
	prv += 7 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 8; ++i) {
		spolyeta_unpack(&( s2->vec[i] ),
		                prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES, 2);
	}
	prv += 8 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 8; ++i) {
		spolyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R3_POLYT0_PACKEDBYTES);
	}
}

static void 
ml_sunpack_prv8(unsigned char rho[ DIL_SEEDBYTES ],
             unsigned char key[ DIL_SEEDBYTES ],
             unsigned char tr [ DIL_MLDSA_TRBYTES ],
                 spolyvec7 *s1,
                 spolyvec8 *s2,
                 spolyvec8 *t0,
       const unsigned char prv[ DIL_MLDSA_PRV8x7_BYTES ])
{
	unsigned int i;

	memmove(rho, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(key, prv, DIL_SEEDBYTES);
	prv += DIL_SEEDBYTES;

	memmove(tr, prv,  DIL_MLDSA_TRBYTES);
	prv += DIL_MLDSA_TRBYTES;

	for (i = 0; i < 7; ++i) {
		spolyeta_unpack(&( s1->vec[i] ),
		                prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES, 2);
	}
	prv += 7 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*L*/
	
	for (i = 0; i < 8; ++i) {
		spolyeta_unpack(&( s2->vec[i] ),
		                prv +i *DIL_R3_POLYETA8x7_PACKEDBYTES, 2);
	}
	prv += 8 * DIL_R3_POLYETA8x7_PACKEDBYTES;  /*K*/
	
	for (i = 0; i < 8; ++i) {
		spolyt0_unpack(&( t0->vec[i] ), prv +i *DIL_R3_POLYT0_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
spolyvec4_caddq(spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_caddq(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_sub(spolyvec4 *r, const spolyvec4 *u, const spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_sub(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_shiftl(spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_shiftl(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static unsigned int 
spolyvec4_make_hint(spolyvec4 *h,
              const spolyvec4 *v0,
              const spolyvec4 *v1,
                 unsigned int dil_k)
{
	unsigned int i, nr = 0;

	for (i = 0; i < 4; ++i) {
		nr += spoly_make_hint(&(  h->vec[i] ),
		                      &( v0->vec[i] ),
		                      &( v1->vec[i] ), dil_k);
	}

	return nr;
}


/*------------------------------------*/
static void 
spolyvec4_use_hint(spolyvec4 *r,
             const spolyvec4 *u,
             const spolyvec4 *v,
                unsigned int dil_k)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_use_hint(&( r->vec[k] ),
		               &( u->vec[k] ),
		               &( v->vec[k] ), dil_k);
	}
}


/*------------------------------------*/
static void 
spolyvec4_power2round(spolyvec4 *v1,
                      spolyvec4 *v0,
                const spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_power2round(&( v1->vec[k] ),
		                  &( v0->vec[k] ),
		                  &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec4_decompose(spolyvec4 *v1,
                    spolyvec4 *v0,
              const spolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spoly_decompose(&( v1->vec[k] ),
		                &( v0->vec[k] ),
		                &(  v->vec[k] ),
		                4);
	}
}


/*------------------------------------*/
static void 
spolyvec4_pack_w1(unsigned char r[768], const spolyvec4 *w1)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		spolyw1_pack(&(r[ k*192 ]), &(w1->vec[ k ]), 4 /*K*/);
	}
}


/*------------------------------------*/
static void 
spack_pk4(unsigned char pk [ DIL_R3_PUB4x4_BYTES ],
    const unsigned char rho[ DIL_SEEDBYTES ],
        const spolyvec4 *t1)
{
	unsigned int k;

	memmove(pk, rho, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 4; ++k) {
		spolyt1_pack(pk +k *DIL_R3_POLYT1_PACKEDBYTES, &(t1->vec[k]));
	}
}


/*------------------------------------*/
static void 
sunpack_pk4(unsigned char rho[ DIL_SEEDBYTES ],
                spolyvec4 *t1,
      const unsigned char pk[ DIL_R3_PUB4x4_BYTES ])
{
	unsigned int k;

	memmove(rho, pk, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 4; ++k) {
		spolyt1_unpack(&(t1->vec[k]), pk +k *DIL_R3_POLYT1_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
spolyvec6_caddq(spolyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_caddq(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_sub(spolyvec6 *r, const spolyvec6 *u, const spolyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_sub(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_shiftl(spolyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_shiftl(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static unsigned int 
spolyvec6_make_hint(spolyvec6 *h,
              const spolyvec6 *v0,
              const spolyvec6 *v1,
                 unsigned int dil_k)
{
	unsigned int i, nr = 0;

	for (i = 0; i < 6; ++i) {
		nr += spoly_make_hint(&(  h->vec[i] ),
		                      &( v0->vec[i] ),
		                      &( v1->vec[i] ), dil_k);
	}

	return nr;
}


/*------------------------------------*/
static void 
spolyvec6_use_hint(spolyvec6 *r,
             const spolyvec6 *u,
             const spolyvec6 *v,
                unsigned int dil_k)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_use_hint(&( r->vec[k] ),
		               &( u->vec[k] ),
		               &( v->vec[k] ), dil_k);
	}
}


/*------------------------------------*/
static void 
spolyvec6_power2round(spolyvec6 *v1,
                      spolyvec6 *v0,
                const spolyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_power2round(&( v1->vec[k] ),
		                  &( v0->vec[k] ),
		                  &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec6_decompose(spolyvec6 *v1,
                    spolyvec6 *v0,
              const spolyvec6 *v)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spoly_decompose(&( v1->vec[k] ),
		                &( v0->vec[k] ),
		                &(  v->vec[k] ),
		                6);
	}
}


/*------------------------------------*/
static void 
spolyvec6_pack_w1(unsigned char r[768], const spolyvec6 *w1)
{
	unsigned int k;

	for (k = 0; k < 6; ++k) {
		spolyw1_pack(&(r[ k*128 ]), &(w1->vec[ k ]), 6 /*K*/);
	}
}


/*------------------------------------*/
static void 
spack_pk6(unsigned char pk [ DIL_R3_PUB6x5_BYTES ],
    const unsigned char rho[ DIL_SEEDBYTES ],
        const spolyvec6 *t1)
{
	unsigned int k;

	memmove(pk, rho, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 6; ++k) {
		spolyt1_pack(pk +k *DIL_R3_POLYT1_PACKEDBYTES, &(t1->vec[k]));
	}
}


/*------------------------------------*/
static void 
sunpack_pk6(unsigned char rho[ DIL_SEEDBYTES ],
                spolyvec6 *t1,
      const unsigned char pk[ DIL_R3_PUB6x5_BYTES ])
{
	unsigned int k;

	memmove(rho, pk, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 6; ++k) {
		spolyt1_unpack(&(t1->vec[k]), pk +k *DIL_R3_POLYT1_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
spolyvec8_caddq(spolyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_caddq(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_sub(spolyvec8 *r, const spolyvec8 *u, const spolyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_sub(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_shiftl(spolyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_shiftl(&( v->vec[k] ));
	}
}


/*------------------------------------*/
static unsigned int 
spolyvec8_make_hint(spolyvec8 *h,
              const spolyvec8 *v0,
              const spolyvec8 *v1,
                 unsigned int dil_k)
{
	unsigned int i, nr = 0;

	for (i = 0; i < 8; ++i) {
		nr += spoly_make_hint(&(  h->vec[i] ),
		                      &( v0->vec[i] ),
		                      &( v1->vec[i] ), dil_k);
	}

	return nr;
}


/*------------------------------------*/
static void 
spolyvec8_use_hint(spolyvec8 *r,
             const spolyvec8 *u,
             const spolyvec8 *v,
                unsigned int dil_k)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_use_hint(&( r->vec[k] ),
		               &( u->vec[k] ),
		               &( v->vec[k] ), dil_k);
	}
}


/*------------------------------------*/
static void 
spolyvec8_power2round(spolyvec8 *v1,
                      spolyvec8 *v0,
                const spolyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_power2round(&( v1->vec[k] ),
		                  &( v0->vec[k] ),
		                  &(  v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
spolyvec8_decompose(spolyvec8 *v1,
                    spolyvec8 *v0,
              const spolyvec8 *v)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spoly_decompose(&( v1->vec[k] ),
		                &( v0->vec[k] ),
		                &(  v->vec[k] ),
		                8);
	}
}


/*------------------------------------*/
static void 
spolyvec8_pack_w1(unsigned char r[1024], const spolyvec8 *w1)
{
	unsigned int k;

	for (k = 0; k < 8; ++k) {
		spolyw1_pack(&(r[ k*128 ]), &(w1->vec[ k ]), 8 /*K*/);
	}
}


/*------------------------------------*/
static void 
spack_pk8(unsigned char pk [ DIL_R3_PUB8x7_BYTES ],
    const unsigned char rho[ DIL_SEEDBYTES ],
        const spolyvec8 *t1)
{
	unsigned int k;

	memmove(pk, rho, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 8; ++k) {
		spolyt1_pack(pk +k *DIL_R3_POLYT1_PACKEDBYTES, &(t1->vec[k]));
	}
}


/*------------------------------------*/
static void 
sunpack_pk8(unsigned char rho[ DIL_SEEDBYTES ],
                spolyvec8 *t1,
      const unsigned char pk[ DIL_R3_PUB8x7_BYTES ])
{
	unsigned int k;

	memmove(rho, pk, DIL_SEEDBYTES);
	pk += DIL_SEEDBYTES;

	for (k = 0; k < 8; ++k) {
		spolyt1_unpack(&(t1->vec[k]), pk +k *DIL_R3_POLYT1_PACKEDBYTES);
	}
}


/*------------------------------------*/
static void 
spolyvec4_uniform_gamma1(spolyvec4 *v,
               const unsigned char seed[ DIL_SEEDBYTES ],
                          uint16_t nonce,
                      unsigned int dil_k)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		spoly_uniform_gamma1(&( v->vec[i] ), seed, 4 *nonce +i, dil_k);
	}
}


/*------------------------------------*/
static void 
spolyvec5_uniform_gamma1(spolyvec5 *v,
               const unsigned char seed[ DIL_SEEDBYTES ],
                          uint16_t nonce,
                      unsigned int dil_k)
{
	unsigned int i;

	for (i = 0; i < 5; ++i) {
		spoly_uniform_gamma1(&( v->vec[i] ), seed, 5 *nonce +i, dil_k);
	}
}


/*------------------------------------*/
static void 
spolyvec7_uniform_gamma1(spolyvec7 *v,
               const unsigned char seed[ DIL_SEEDBYTES ],
                          uint16_t nonce,
                      unsigned int dil_k)
{
	unsigned int i;

	for (i = 0; i < 7; ++i) {
		spoly_uniform_gamma1(&( v->vec[i] ), seed, 7 *nonce +i, dil_k);
	}
}


#endif    /* /delimiter: round 3 Dilithium */
#endif    /* Dilithium */

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX)    /* Kyber */
typedef struct {
	kpoly vec[ 3 ];
} kpolyvec3 ;


typedef struct {
	kpoly vec[ 4 ];
} kpolyvec4 ;


/*------------------------------------*/
static void 
kpolyvec3_tobytes(unsigned char wire[ 1152 ],
                      kpolyvec3 *a)
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		kpoly_tobytes(wire +k *KYB_POLYBYTES, &(a->vec[k]));
	}
}

static void 
r3_kpolyvec3_tobytes(unsigned char wire[ 1152 ],
                      kpolyvec3 *a)
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		r3_kpoly_tobytes(wire +k *KYB_POLYBYTES, &(a->vec[k]));
	}
}


/*------------------------------------*/
static void 
kpolyvec3_frombytes(kpolyvec3 *r, const unsigned char wire[ 1152 /* 3 *384 */ ])
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		kpoly_frombytes(&(r->vec[ k ]), wire +k * KYB_POLYBYTES);
	}
}

static void 
r3_kpolyvec3_frombytes(kpolyvec3 *r, const unsigned char wire[ 1152 /* 3 *384 */ ])
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		r3_kpoly_frombytes(&(r->vec[ k ]), wire +k * KYB_POLYBYTES);
	}
}


/*------------------------------------*/
static void 
kpack_pk3(unsigned char wire[ 1184 /* 3 *384 +32 */ ],
              kpolyvec3 *pk,
    const unsigned char seed[ KYB_SYMBYTES ])
{
	kpolyvec3_tobytes(wire, pk);

	memmove(wire +1152, seed, KYB_SYMBYTES);
}

static void 
r3_kpack_pk3(unsigned char wire[ 1184 /* 3 *384 +32 */ ],
              kpolyvec3 *pk,
    const unsigned char seed[ KYB_SYMBYTES ])
{
	r3_kpolyvec3_tobytes(wire, pk);

	memmove(wire +1152, seed, KYB_SYMBYTES);
}

static int
mlkem_pack_check_pk3(const kpolyvec3 *pk,
    const uint8_t wire[KYB_PUB3_BYTES])
{
	uint8_t diff = 0;
	unsigned int k, i;
	uint16_t     t0, t1;
	const kpoly* a;
	const uint8_t *r = wire;

	for (k = 0; k < 3; ++k) {
		a = &(pk->vec[k]);
		for ( i = 0; i < KYB_N / 2; i++ ) {
        	// map to positive standard representatives
        	t0 = a->coeffs[2 * i];
        	t0 += ((int16_t)t0 >> 15) & KYB_Q;
        	t1 = a->coeffs[2 * i + 1];
        	t1 += ((int16_t)t1 >> 15) & KYB_Q;

        	diff |= *r++ ^ (uint8_t) (t0 >> 0);
        	diff |= *r++ ^ (uint8_t) ((t0 >> 8) | (t1 << 4));
        	diff |= *r++ ^ (uint8_t) (t1 >> 4);
    	}
	}

    return (-(uint64_t)diff) >> 63;
}

/*------------------------------------*/
static void 
kunpack_pk3(kpolyvec3 *pk,
              unsigned char seed[ KYB_SYMBYTES ],
        const unsigned char wire[ 1184 /* 3 *384 +32 */ ])
{
	kpolyvec3_frombytes(pk, wire);

	memmove(seed, wire +1152, KYB_SYMBYTES);
}

static void 
r3_kunpack_pk3(kpolyvec3 *pk,
              unsigned char seed[ KYB_SYMBYTES ],
        const unsigned char wire[ 1184 /* 3 *384 +32 */ ])
{
	r3_kpolyvec3_frombytes(pk, wire);

	memmove(seed, wire +1152, KYB_SYMBYTES);
}


/*------------------------------------*/
static void 
kpack_sk3(unsigned char wire[ 1152 /* 3 *384 */ ],
             kpolyvec3 *sk)
{
	kpolyvec3_tobytes(wire, sk);
}

static void 
r3_kpack_sk3(unsigned char wire[ 1152 /* 3 *384 */ ],
             kpolyvec3 *sk)
{
	r3_kpolyvec3_tobytes(wire, sk);
}


/*------------------------------------*/
static void 
kunpack_sk3(kpolyvec3 *sk, const unsigned char wire[ 1152 /* 3 *384 */ ])
{
	kpolyvec3_frombytes(sk, wire);
}

static void 
r3_kunpack_sk3(kpolyvec3 *sk, const unsigned char wire[ 1152 /* 3 *384 */ ])
{
	r3_kpolyvec3_frombytes(sk, wire);
}


/*------------------------------------*/
static void 
kpack_ciphertext3(unsigned char wire[ 1088 /* 3 *320 +128 */ ],
                     kpolyvec3 *b,
                         kpoly *v)
{
	kpolyvec_compress(wire, 960, (kpolyvec_max *) b, 3);

	kpoly_compress(wire +960, 128, v);
}

static void 
r3_kpack_ciphertext3(unsigned char wire[ 1088 /* 3 *320 +128 */ ],
                     kpolyvec3 *b,
                         kpoly *v)
{
	r3_kpolyvec_compress(wire, 960, (kpolyvec_max *) b, 3);

	r3_kpoly_compress(wire +960, 128, v);
}


/*------------------------------------*/
static void 
kunpack_ciphertext3(kpolyvec3 *b,
                        kpoly *v,
          const unsigned char wire[ 1088 /* 3 *320 +128 */ ])
{
	kpolyvec_decompress((kpolyvec_max *) b, 3, wire, 960);

	kpoly_decompress(v, wire +960, 128);
}

static void 
r3_kunpack_ciphertext3(kpolyvec3 *b,
                        kpoly *v,
          const unsigned char wire[ 1088 /* 3 *320 +128 */ ])
{
	r3_kpolyvec_decompress((kpolyvec_max *) b, 3, wire, 960);

	r3_kpoly_decompress(v, wire +960, 128);
}


/*------------------------------------*/
static void 
kpolyvec3_ntt(kpolyvec3 *r)
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		kpoly_ntt(&( r->vec[k] ));
	}
}

static void 
r3_kpolyvec3_ntt(kpolyvec3 *r)
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		r3_kpoly_ntt(&( r->vec[k] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec3_invntt_tomont(kpolyvec3 *v)
{
	unsigned int i;

	for (i = 0; i < 3; ++i) {
		kpoly_invntt_tomont(&( v->vec[i] ));
	}
}

static void 
r3_kpolyvec3_invntt_tomont(kpolyvec3 *v)
{
	unsigned int i;

	for (i = 0; i < 3; ++i) {
		r3_kpoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec3_csubq(kpolyvec3 *v)
{
	unsigned int i;

	for (i = 0; i < 3; ++i) {
		kpoly_csubq(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec3_add(kpolyvec3 *r, const kpolyvec3 *u, const kpolyvec3 *v)
{
	unsigned int k;

	for (k = 0; k < 3; ++k) {
		kpoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec3_reduce(kpolyvec3 *v)
{
	unsigned int i;

	for (i = 0; i < 3; ++i) {
		kpoly_reduce(&( v->vec[i] ));
	}
}

static void 
r3_kpolyvec3_reduce(kpolyvec3 *v)
{
	unsigned int i;

	for (i = 0; i < 3; ++i) {
		r3_kpoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec3_pointwise_acc_montgomery(kpoly *r,
                         const kpolyvec3 *a,
                         const kpolyvec3 *b)
{
	unsigned int k;
	kpoly tmp;

	kpoly_basemul_montgomery(r, &(a->vec[0]), &(b->vec[0]));

	for (k = 1; k < 3; ++k) {
		kpoly_basemul_montgomery(&tmp, &(a->vec[k]), &(b->vec[k]));
		kpoly_add(r, r, &tmp);
	}

	kpoly_reduce(r);
}

static void 
r3_kpolyvec3_basemul_acc_montgomery(kpoly *r,
                         const kpolyvec3 *a,
                         const kpolyvec3 *b)
{
	unsigned int k;
	kpoly tmp;

	r3_kpoly_basemul_montgomery(r, &(a->vec[0]), &(b->vec[0]));

	for (k = 1; k < 3; ++k) {
		r3_kpoly_basemul_montgomery(&tmp, &(a->vec[k]), &(b->vec[k]));
		kpoly_add(r, r, &tmp);
	}

	r3_kpoly_reduce(r);
}


/*------------------------------------*/
static void 
kpolyvec4_tobytes(unsigned char wire[ 1536 ],
                      kpolyvec4 *a)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		kpoly_tobytes(wire +k *KYB_POLYBYTES, &(a->vec[k]));
	}
}

static void 
r3_kpolyvec4_tobytes(unsigned char wire[ 1536 ],
                      kpolyvec4 *a)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		r3_kpoly_tobytes(wire +k *KYB_POLYBYTES, &(a->vec[k]));
	}
}


/*------------------------------------*/
static void 
kpolyvec4_frombytes(kpolyvec4 *r, const unsigned char wire[ 1536 /* 4 *384 */ ])
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		kpoly_frombytes(&(r->vec[ k ]), wire +k * KYB_POLYBYTES);
	}
}

static void 
r3_kpolyvec4_frombytes(kpolyvec4 *r, const unsigned char wire[ 1536 /* 4 *384 */ ])
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		r3_kpoly_frombytes(&(r->vec[ k ]), wire +k * KYB_POLYBYTES);
	}
}


/*------------------------------------*/
static void 
kpack_pk4(unsigned char wire[ 1568 /* 4 *384 +32 */ ],
              kpolyvec4 *pk,
    const unsigned char seed[ KYB_SYMBYTES ])
{
	kpolyvec4_tobytes(wire, pk);

	memmove(wire +1536, seed, KYB_SYMBYTES);
}

static void 
r3_kpack_pk4(unsigned char wire[ 1568 /* 4 *384 +32 */ ],
              kpolyvec4 *pk,
    const unsigned char seed[ KYB_SYMBYTES ])
{
	r3_kpolyvec4_tobytes(wire, pk);

	memmove(wire +1536, seed, KYB_SYMBYTES);
}

static int
mlkem_pack_check_pk4(const kpolyvec4 *pk,
    const uint8_t wire[KYB_PUB4_BYTES])
{
	uint8_t diff = 0;
	unsigned int k, i;
	uint16_t     t0, t1;
	const kpoly* a;
	const uint8_t *r = wire;

	for (k = 0; k < 4; ++k) {
		a = &(pk->vec[k]);
		for ( i = 0; i < KYB_N / 2; i++ ) {
        	// map to positive standard representatives
        	t0 = a->coeffs[2 * i];
        	t0 += ((int16_t)t0 >> 15) & KYB_Q;
        	t1 = a->coeffs[2 * i + 1];
        	t1 += ((int16_t)t1 >> 15) & KYB_Q;

        	diff |= *r++ ^ (uint8_t) (t0 >> 0);
        	diff |= *r++ ^ (uint8_t) ((t0 >> 8) | (t1 << 4));
        	diff |= *r++ ^ (uint8_t) (t1 >> 4);
    	}
	}

	return (-(uint64_t)diff) >> 63;
}


/*------------------------------------*/
static void 
kunpack_pk4(kpolyvec4 *pk,
              unsigned char seed[ KYB_SYMBYTES ],
        const unsigned char wire[ 1568 /* 4 *384 +32 */ ])
{
	kpolyvec4_frombytes(pk, wire);

	memmove(seed, wire +1536, KYB_SYMBYTES);
}

static void 
r3_kunpack_pk4(kpolyvec4 *pk,
              unsigned char seed[ KYB_SYMBYTES ],
        const unsigned char wire[ 1568 /* 4 *384 +32 */ ])
{
	r3_kpolyvec4_frombytes(pk, wire);

	memmove(seed, wire +1536, KYB_SYMBYTES);
}


/*------------------------------------*/
static void 
kpack_sk4(unsigned char wire[ 1536 /* 4 *384 */ ],
             kpolyvec4 *sk)
{
	kpolyvec4_tobytes(wire, sk);
}

static void 
r3_kpack_sk4(unsigned char wire[ 1536 /* 4 *384 */ ],
             kpolyvec4 *sk)
{
	r3_kpolyvec4_tobytes(wire, sk);
}


/*------------------------------------*/
static void 
kunpack_sk4(kpolyvec4 *sk, const unsigned char wire[ 1536 /* 4 *384 */ ])
{
	kpolyvec4_frombytes(sk, wire);
}

static void 
r3_kunpack_sk4(kpolyvec4 *sk, const unsigned char wire[ 1536 /* 4 *384 */ ])
{
	r3_kpolyvec4_frombytes(sk, wire);
}


/*------------------------------------*/
static void 
kpack_ciphertext4(unsigned char wire[ 1568 /* 4 *352 +160 */ ],
                     kpolyvec4 *b,
                         kpoly *v)
{
	kpolyvec_compress(wire, 1408, (kpolyvec_max *) b, 4);

	kpoly_compress(wire +1408, 160, v);
}

static void 
r3_kpack_ciphertext4(unsigned char wire[ 1568 /* 4 *352 +160 */ ],
                     kpolyvec4 *b,
                         kpoly *v)
{
	r3_kpolyvec_compress(wire, 1408, (kpolyvec_max *) b, 4);

	r3_kpoly_compress(wire +1408, 160, v);
}


/*------------------------------------*/
static void 
kunpack_ciphertext4(kpolyvec4 *b,
                        kpoly *v,
          const unsigned char wire[ 1568 /* 4 *352 +160 */ ])
{
	kpolyvec_decompress((kpolyvec_max *) b, 4, wire, 1408);

	kpoly_decompress(v, wire +1408, 160);
}

static void 
r3_kunpack_ciphertext4(kpolyvec4 *b,
                        kpoly *v,
          const unsigned char wire[ 1568 /* 4 *352 +160 */ ])
{
	r3_kpolyvec_decompress((kpolyvec_max *) b, 4, wire, 1408);

	r3_kpoly_decompress(v, wire +1408, 160);
}


/*------------------------------------*/
static void 
kpolyvec4_ntt(kpolyvec4 *r)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		kpoly_ntt(&( r->vec[k] ));
	}
}

static void 
r3_kpolyvec4_ntt(kpolyvec4 *r)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		r3_kpoly_ntt(&( r->vec[k] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec4_invntt_tomont(kpolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		kpoly_invntt_tomont(&( v->vec[i] ));
	}
}

static void 
r3_kpolyvec4_invntt_tomont(kpolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		r3_kpoly_invntt_tomont(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec4_csubq(kpolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		kpoly_csubq(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec4_add(kpolyvec4 *r, const kpolyvec4 *u, const kpolyvec4 *v)
{
	unsigned int k;

	for (k = 0; k < 4; ++k) {
		kpoly_add(&( r->vec[k] ),
		          &( u->vec[k] ),
		          &( v->vec[k] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec4_reduce(kpolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		kpoly_reduce(&( v->vec[i] ));
	}
}

static void 
r3_kpolyvec4_reduce(kpolyvec4 *v)
{
	unsigned int i;

	for (i = 0; i < 4; ++i) {
		r3_kpoly_reduce(&( v->vec[i] ));
	}
}


/*------------------------------------*/
static void 
kpolyvec4_pointwise_acc_montgomery(kpoly *r,
                         const kpolyvec4 *a,
                         const kpolyvec4 *b)
{
	unsigned int k;
	kpoly tmp;

	kpoly_basemul_montgomery(r, &(a->vec[0]), &(b->vec[0]));

	for (k = 1; k < 4; ++k) {
		kpoly_basemul_montgomery(&tmp, &(a->vec[k]), &(b->vec[k]));
		kpoly_add(r, r, &tmp);
	}

	kpoly_reduce(r);
}

static void 
r3_kpolyvec4_basemul_acc_montgomery(kpoly *r,
                         const kpolyvec4 *a,
                         const kpolyvec4 *b)
{
	unsigned int k;
	kpoly tmp;

	r3_kpoly_basemul_montgomery(r, &(a->vec[0]), &(b->vec[0]));

	for (k = 1; k < 4; ++k) {
		r3_kpoly_basemul_montgomery(&tmp, &(a->vec[k]), &(b->vec[k]));
		kpoly_add(r, r, &tmp);
	}

	r3_kpoly_reduce(r);
}


#endif    /* Kyber */
/* /generated code */

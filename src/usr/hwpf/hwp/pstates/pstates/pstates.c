/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstates.c $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: pstates.c,v 1.9 2015/06/01 19:02:17 stillgs Exp $

/// \file pstates.c
/// \brief Pstate routines required by OCC product firmware

#include "ssx.h"
#include "pgp_common.h"
#include "pstates.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Validate a VRM11 VID code
///
/// \param vid A VRM11 VID
///
/// \retval 0 The VID is valid
///
/// \retval -VID11_UNDERFLOW The Vid code is a low 'power off' VID (0 or 1)
///
/// \retval -VID11_OVERFLOW The Vid code is a high 'power off' VID (0xfe or 0xff)

int
vid11_validate(Vid11 vid)
{
    int rc;

    if (vid < VID11_MIN) {

        rc = -VID11_UNDERFLOW;

    } else if (vid > VID11_MAX) {

        rc = -VID11_OVERFLOW;

    } else {

        rc = 0;

    }

    return rc;
}


/// Bias a Pstate with saturation
///
/// \param pstate The initial Pstate to bias
///
/// \param bias The signed bias amount
///
/// \param biased_pstate The final biased Pstate
///
/// This API adds a signed bias to the \a pstate and returns the saturated sum
/// as \a biased_pstate.  Any application that biases Pstates should use this
/// API rather than simple addition/subtraction.
///
/// The following return codes are not considered errors:
///
/// \retval 0 Success
///
/// \retval -PSTATE_OVERFLOW The biased Pstate saturated at PSTATE_MAX.
///
/// \retval -PSTATE_UNDERFLOW The biased Pstate saturated at PSTATE_MIN.

int
bias_pstate(Pstate pstate, int bias, Pstate* biased_pstate)
{
    int rc, int_pstate;

    int_pstate = (int)pstate + bias;
    if (int_pstate != (Pstate)int_pstate) {
    if (bias < 0) {
        *biased_pstate = PSTATE_MIN;
            rc = -PSTATE_UNDERFLOW;
    } else {
        *biased_pstate = PSTATE_MAX;
            rc = -PSTATE_OVERFLOW;
    }
    } else {
    *biased_pstate = int_pstate;
    rc = 0;
    }

    return rc;
}


/// Bias a DPLL frequency code with saturation and bounds checking
///
/// \param fcode The initial frequency code to bias
///
/// \param bias The signed bias amount
///
/// \param biased_fcode The final biased frequency code
///
/// This API adds a signed bias to the \a fcode and returns the saturated and
/// bounded sum as \a biased_fcode.  Any application that biases frequency
/// codes should use this API rather than simple addition/subtraction.
///
/// The following return codes are not considered errors:
///
/// \retval 0 Success
///
/// \retval -DPLL_OVERFLOW The biased frequency code saturated at DPLL_MAX.
///
/// \retval -DPLL_UNDERFLOW The biased frequency code saturated at DPLL_MIN.

int
bias_frequency(DpllCode fcode, int bias, DpllCode* biased_fcode)
{
    int rc;
    unsigned uint_fcode;

    uint_fcode = (unsigned)fcode + bias;
    if (uint_fcode != (DpllCode)uint_fcode) {
    if (bias < 0) {
        *biased_fcode = DPLL_MIN;
            rc = -DPLL_UNDERFLOW;
    } else {
        *biased_fcode = DPLL_MAX;
            rc = -DPLL_OVERFLOW;
    }
    } else if (uint_fcode < DPLL_MIN) {
        *biased_fcode = DPLL_MIN;
        rc = -DPLL_UNDERFLOW;
    } else {
    *biased_fcode = uint_fcode;
    rc = 0;
    }

    return rc;
}


/// Bias a VRM11 VID code with saturation and bounds checking
///
/// \param vid The initial vid code to bias
///
/// \param bias The signed bias amount
///
/// \param biased_vid The final biased VID code
///
/// This API adds a signed bias to the \a vid and returns the saturated and
/// bounded sum as \a biased_vid.  Any application that biases VID codes
/// should use this API rather than simple addition/subtraction.
///
/// The following return codes are not considered errors:
///
/// \retval 0 Success
///
/// \retval -VID11_OVERFLOW The biased VID code saturated at VID11_MAX.
///
/// \retval -VID11_UNDERFLOW The biased VID code saturated at VID11__MIN.

int
bias_vid11(Vid11 vid, int bias, Vid11* biased_vid)
{
    int rc;
    unsigned uint_vid;

    uint_vid = (unsigned)vid + bias;
    if (uint_vid != (DpllCode)uint_vid) {
    if (bias < 0) {
        *biased_vid = VID11_MIN;
            rc = -VID11_UNDERFLOW;
    } else {
        *biased_vid = VID11_MAX;
            rc = -VID11_OVERFLOW;
    }
    } else {

        rc = vid11_validate(uint_vid);
    *biased_vid = uint_vid;

    }

    return rc;
}


/// Retrieve an entry from the Global Pstate Table abstraction
///
/// \param gpst An initialized GlobalPstateTable structure.
///
/// \param pstate The Pstate index of the entry to fetch
///
/// \param bias This is a signed bias. The entry searched is the \a pstate +
/// \a bias entry.
///
/// \param entry A pointer to a gpst_entry_t to hold the returned data.
///
/// This routine functions similar to PMC harwdare.  When a Pstate is
/// requested the index is first biased (under/over-volted) and clipped to the
/// defined bounds, then the Pstate entry is returned.
///
/// The following return codes are not considered errors:
///
/// \retval 0 Success
///
/// \retval -GPST_PSTATE_CLIPPED_HIGH The requested Pstate does not exist in
/// the table. The maximum Pstate entry in the table has been returned.
///
/// \retval -GPST_PSTATE_CLIPPED_LOW The requested Pstate does not exist in
/// the table. The minimum Pstate entry in the table has been returned.
///
/// The following return codes are considered errors:
///
/// \retval -GPST_INVALID_OBJECT The Global Pstate Table is either null (0) or
/// otherwise invalid.

int
gpst_entry(const GlobalPstateTable *gpst,
           const Pstate pstate,
           int bias,
           gpst_entry_t *entry)
{
    int rc, index;
    Pstate biased_pstate;

    if (gpst == 0) {
        return -GPST_INVALID_OBJECT;
    }

    rc = bias_pstate(pstate, bias, &biased_pstate);

    if ((rc == -PSTATE_UNDERFLOW) || (pstate < gpst_pmin(gpst))) {

    rc = -GPST_PSTATE_CLIPPED_LOW;
    index = 0;

    } else if ((rc == -PSTATE_OVERFLOW) || (pstate > gpst_pmax(gpst))) {

    rc = -GPST_PSTATE_CLIPPED_HIGH;
    index = gpst->entries - 1;

    } else {

    rc = 0;
    index = pstate - gpst_pmin(gpst);

    }

    *entry = gpst->pstate[index];

    return rc;
}


/// Translate a Vdd VID code to the closest Pstate in a Global Pstate table.
///
/// \param gpst The GlobalPstateTable to search
///
/// \param vdd A VID code representing an external VDD voltage
///
/// \param pstate The Pstate most closely matching the \a vid.
///
/// \param entry The GlobalPstateTable entry of the returned \a pstate.
///
/// This routine assumes that Pstate voltages increase monotonically from
/// lower to higher Pstates.  The algorithm operates from lowest to highest
/// voltage, scanning until the Pstate voltage is >= the VID voltage.  Thus
/// the algorithm effectively rounds up voltage (unless clipped at the highest
/// Pstate).
///
/// The following return codes are not considered errors:
///
/// \retval 0 Success
///
/// \retval -GPST_PSTATE_CLIPPED_HIGH The requested voltage does not exist in
/// the table. The highest legal Pstate is returned.
///
/// \retval -GPST_PSTATE_CLIPPED_LOW The requested voltage does not exist in
/// the table.  The lowest legal Pstate in the table is returned.
///
/// The following return codes are considered errors:
///
/// \retval -VRM_INVALID_VOLTAGE The \a vid is invalid.
///
/// \retval -GPST_INVALID_OBJECT The \a gpst argument is NULL (0).

// Recall that VID codes _decrease_ as voltage _increases_

#ifdef _BIG_ENDIAN

#define revle16(x) x
#define revle32(x) x
#define revle64(x) x

#else

uint16_t revle16(uint16_t i_x);
uint32_t revle32(uint32_t i_x);
uint64_t revle64(uint64_t i_x);

#endif

int
gpst_vdd2pstate(const GlobalPstateTable* gpst,
                const Vid11 vdd,
                Pstate* pstate,
                gpst_entry_t* entry)
{
    size_t i;
    int rc;
    gpst_entry_t         entry_rev;       // jwy
  

    if (gpst == 0) {
         return -GPST_INVALID_OBJECT;
    }

    do {
        rc =vid11_validate(vdd);
        if (rc) break;

        // Search for the Pstate that contains (close to) the requested
        // voltage, then handle special cases.

        for (i = 0; i < gpst->entries; i++) {
            entry_rev.value = revle64(gpst->pstate[i].value);       // jwy

            if (entry_rev.fields.evid_vdd <= vdd) {                 // jwy
                break;
            }
        }

        if (i == gpst->entries) {

            *pstate = gpst_pmax(gpst);
            *entry = gpst->pstate[i - 1];
            rc = -GPST_PSTATE_CLIPPED_HIGH;

        } else if ((i == 0) && (entry_rev.fields.evid_vdd < vdd)) {

            *pstate = gpst_pmin(gpst);
            *entry = gpst->pstate[0];
            rc = -GPST_PSTATE_CLIPPED_LOW;

        } else {

            rc = bias_pstate(gpst_pmin(gpst), i, pstate);
            if (rc) break;

            *entry = gpst->pstate[i];
        }
    } while (0);
    return rc;
}

int freq2pState (const GlobalPstateTable* gpst, 
                 const uint32_t freq_khz,
                 Pstate* pstate) 
{
  int rc = 0;
  int32_t pstate32 = 0;
  
  // ----------------------------------
  // compute pstate for given frequency
  // ----------------------------------  
  pstate32 = ((int32_t)((freq_khz - revle32(gpst->pstate0_frequency_khz)))) / (int32_t)revle32(gpst->frequency_step_khz);
  *pstate    = (Pstate)pstate32;
  
  // ------------------------------
  // perform pstate bounds checking
  // ------------------------------
  if (pstate32 < PSTATE_MIN)
     rc = -PSTATE_LT_PSTATE_MIN;
    
  if (pstate32 > PSTATE_MAX)
     rc = -PSTATE_GT_PSTATE_MAX;  
 
  return rc;
}



int pstate_minmax_chk (const GlobalPstateTable* gpst, 
                       Pstate* pstate) 
{
  int rc = 0;
  
   // if pstate is greater than pmax, generate an error
   if (*pstate > gpst_pmax(gpst))
     rc = -GPST_PSTATE_GT_GPST_PMAX;                                                                                               
   
   // if pstate is less than than pmin, clip pstate to pmin
   if (*pstate < gpst_pmin(gpst) )                                                                       
     *pstate = gpst_pmin(gpst);                                      
 
  return rc;
}

#ifdef __cplusplus
} // end extern C
#endif

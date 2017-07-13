/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ring_identification.C $ */
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
#ifdef WIN32
    #include "win32_stdint.h"
    #include "p9_ring_identification.H"
#else
    #ifdef __sun
        #include <sys/int_types.h>
        #include "p9_ring_identification.H"
    #else
        #include <p9_ring_identification.H>
    #endif
#endif

const RingIdList RING_ID_LIST_PDG[] =
{
    /* ringName           ringId  chipletId  vpdKeyword    */
    /*                            min   max                 */
    {"perv_gptr",            perv_gptr, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"perv_time",            perv_time, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"occ_gptr",              occ_gptr, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"occ_time",              occ_time, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"perv_ana_gptr",    perv_ana_gptr, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"perv_pll_gptr",    perv_pll_gptr, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n0_gptr",                n0_gptr, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n0_time",                n0_time, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n0_nx_gptr",          n0_nx_gptr, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n0_nx_time",          n0_nx_time, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n0_cxa0_gptr",      n0_cxa0_gptr, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n0_cxa0_time",      n0_cxa0_time, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_gptr",                n1_gptr, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n1_time",                n1_time, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_ioo0_gptr",      n1_ioo0_gptr, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n1_ioo0_time",      n1_ioo0_time, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_ioo1_gptr",      n1_ioo1_gptr, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n1_ioo1_time",      n1_ioo1_time, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_mcs23_gptr",    n1_mcs23_gptr, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n1_mcs23_time",    n1_mcs23_time, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n2_gptr",                n2_gptr, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n2_time",                n2_time, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n2_cxa1_gptr",      n2_cxa1_gptr, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n2_cxa1_time",      n2_cxa1_time, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n2_psi_gptr",        n2_psi_gptr, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n3_gptr",                n3_gptr, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n3_time",                n3_time, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n3_mcs01_gptr",    n3_mcs01_gptr, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n3_mcs01_time",    n3_mcs01_time, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n3_np_gptr",          n3_np_gptr, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"n3_np_time",          n3_np_time, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_gptr",                xb_gptr, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"xb_time",                xb_time, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_io0_gptr",        xb_io0_gptr, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"xb_io0_time",        xb_io0_time, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_io1_gptr",        xb_io1_gptr, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"xb_io1_time",        xb_io1_time, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_io2_gptr",        xb_io2_gptr, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"xb_io2_time",        xb_io2_time, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_pll_gptr",        xb_pll_gptr, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"mc_gptr",                mc_gptr, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"mc_time",                mc_time, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"mc_iom01_gptr",    mc_iom01_gptr, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"mc_iom23_gptr",    mc_iom23_gptr, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"mc_pll_gptr",        mc_pll_gptr, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob0_gptr",              ob0_gptr, 0x09, 0x09, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob0_time",              ob0_time, 0x09, 0x09, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob0_pll_gptr",      ob0_pll_gptr, 0x09, 0x09, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob1_gptr",              ob1_gptr, 0x0A, 0x0A, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob1_time",              ob1_time, 0x0A, 0x0A, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob1_pll_gptr",      ob1_pll_gptr, 0x0A, 0x0A, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob2_gptr",              ob2_gptr, 0x0B, 0x0B, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob2_time",              ob2_time, 0x0B, 0x0B, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob2_pll_gptr",      ob2_pll_gptr, 0x0B, 0x0B, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob3_gptr",              ob3_gptr, 0x0C, 0x0C, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"ob3_time",              ob3_time, 0x0C, 0x0C, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob3_pll_gptr",      ob3_pll_gptr, 0x0C, 0x0C, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"pci0_gptr",            pci0_gptr, 0x0D, 0x0D, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"pci0_time",            pci0_time, 0x0D, 0x0D, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"pci0_pll_gptr",    pci0_pll_gptr, 0x0D, 0x0D, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"pci1_gptr",            pci1_gptr, 0x0E, 0x0E, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"pci1_time",            pci1_time, 0x0E, 0x0E, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"pci1_pll_gptr",    pci1_pll_gptr, 0x0E, 0x0E, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"pci2_gptr",            pci2_gptr, 0x0F, 0x0F, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"pci2_time",            pci2_time, 0x0F, 0x0F, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"pci2_pll_gptr",    pci2_pll_gptr, 0x0F, 0x0F, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_NEST},
    {"eq_gptr",                eq_gptr, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EQ},
    {"eq_time",                eq_time, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EQ},
    {"ex_l3_gptr",          ex_l3_gptr, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EX},
    {"ex_l3_time",          ex_l3_time, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EX},
    {"ex_l2_gptr",          ex_l2_gptr, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EX},
    {"ex_l2_time",          ex_l2_time, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EX},
    {"ex_l3_refr_gptr", ex_l3_refr_gptr, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EX},
    {"eq_ana_gptr",        eq_ana_gptr, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EQ},
    {"eq_dpll_gptr",      eq_dpll_gptr, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EQ},
    {"ec_gptr",                ec_gptr, 0x20, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR_EC},
    {"ec_time",                ec_time, 0x20, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EC},
};

const RingIdList RING_ID_LIST_PDR[] =
{
    /* ringName           ringId  chipletId  vpdKeyword    */
    /*                            min   max                 */
    {"perv_repr",          perv_repr, 0x01, 0x01, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"occ_repr",            occ_repr, 0x01, 0x01, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n0_repr",              n0_repr, 0x02, 0x02, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n0_nx_repr",        n0_nx_repr, 0x02, 0x02, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n0_cxa0_repr",    n0_cxa0_repr, 0x02, 0x02, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_repr",              n1_repr, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_ioo0_repr",    n1_ioo0_repr, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_ioo1_repr",    n1_ioo1_repr, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_mcs23_repr",  n1_mcs23_repr, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n2_repr",              n2_repr, 0x04, 0x04, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n2_cxa1_repr",    n2_cxa1_repr, 0x04, 0x04, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n3_repr",              n3_repr, 0x05, 0x05, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n3_mcs01_repr",  n3_mcs01_repr, 0x05, 0x05, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n3_np_repr",        n3_np_repr, 0x05, 0x05, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_repr",              xb_repr, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_io0_repr",      xb_io0_repr, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_io1_repr",      xb_io1_repr, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_io2_repr",      xb_io2_repr, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"mc_repr",              mc_repr, 0x07, 0x08, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob0_repr",            ob0_repr, 0x09, 0x09, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob1_repr",            ob1_repr, 0x0A, 0x0A, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob2_repr",            ob2_repr, 0x0B, 0x0B, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob3_repr",            ob3_repr, 0x0C, 0x0C, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"pci0_repr",          pci0_repr, 0x0D, 0x0D, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"pci1_repr",          pci1_repr, 0x0E, 0x0E, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"pci2_repr",          pci2_repr, 0x0F, 0x0F, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"eq_repr",              eq_repr, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EQ_INS},
    {"ex_l3_refr_time", ex_l3_refr_time, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ex_l3_repr",        ex_l3_repr, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ex_l2_repr",        ex_l2_repr, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ex_l3_refr_repr", ex_l3_refr_repr, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ec_repr",              ec_repr, 0x20, 0x37, VPD_KEYWORD_PDR, VPD_RING_CLASS_EC_INS},
};

const VPDRingList ALL_VPD_RINGS[NUM_OF_VPD_TYPES] =
{
    {RING_ID_LIST_PDG,  (sizeof(RING_ID_LIST_PDG) / sizeof(RING_ID_LIST_PDG[0]))},
    {RING_ID_LIST_PDR,  (sizeof(RING_ID_LIST_PDR) / sizeof(RING_ID_LIST_PDR[0]))},

};
#if defined(WIN32) || defined(__sun)
const uint32_t RING_ID_LIST_PG_SIZE = sizeof(RING_ID_LIST_PDG) / sizeof(
        RING_ID_LIST_PDG[0]);
const uint32_t RING_ID_LIST_PR_SIZE = sizeof(RING_ID_LIST_PDR) / sizeof(
        RING_ID_LIST_PDR[0]);
#endif

const uint32_t RING_ID_LIST_CORE_SIZE = 4;


//@TODO: This function will be used in RTC158106 (VPD insertion ordering).
// get_vpd_ring_list_entry() retrieves the MVPD list entry based on either a ringName
//   or a ringId.  If both are supplied, only the ringName is used. If ringName==NULL,
//   then the ringId is used. A pointer to the RingIdList is returned.
/*
int get_vpd_ring_list_entry(const char* i_ringName,
                            const uint8_t i_ringId,
                            RingIdList** i_ringIdList)
{
    int rc = 0, NOT_FOUND = 1, FOUND = 0;
    uint8_t iVpdType;
    uint8_t iRing;
    RingIdList* ring_id_list = NULL;
    uint8_t ring_id_list_size;

    rc = NOT_FOUND;

    for (iVpdType = 0; iVpdType < NUM_OF_VPD_TYPES; iVpdType++)
    {
        if (iVpdType == 0)
        {
            ring_id_list = (RingIdList*)RING_ID_LIST_PG;
            ring_id_list_size = (uint32_t)RING_ID_LIST_PG_SIZE;
        }
        else
        {
            ring_id_list = (RingIdList*)RING_ID_LIST_PR;
            ring_id_list_size = (uint32_t)RING_ID_LIST_PR_SIZE;
        }

        // Search the MVPD reference lists for either a:
        // - ringName match with or w/o _image in the name, or
        // - ringId match.
        if (i_ringName)
        {
            // Search for ringName match.
            for (iRing = 0; iRing < ring_id_list_size; iRing++)
            {
                if ( strcmp((ring_id_list + iRing)->ringName,   i_ringName) == 0  )
                {
                    *i_ringIdList = ring_id_list + iRing;
                    return FOUND;
                }
            }
        }
        else
        {
            // Search for ringId match (since ringName was not supplied).
            for (iRing = 0; iRing < ring_id_list_size; iRing++)
            {
                if ((ring_id_list + iRing)->ringId == i_ringId)
                {
                    *i_ringIdList = ring_id_list + iRing;
                    return FOUND;
                }
            }
        }

    }

    return rc;
}
*/




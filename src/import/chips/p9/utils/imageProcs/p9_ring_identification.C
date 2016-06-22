/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ring_identification.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <p9_ring_identification.H>

const RingIdList RING_ID_LIST_PDG[] =
{
    /* ringName           ringId  chipletId  vpdKeyword    */
    /*                            min   max                 */
    {"perv_gptr",             1, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"perv_time",             2, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"occ_gptr",              4, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"occ_time",              5, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"perv_ana_gptr",         7, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"perv_pll_gptr",         8, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"perv_pibnet_gptr",     16, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"perv_pibnet_time",     17, 0x01, 0x01, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n0_gptr",              22, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n0_time",              23, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n0_nx_gptr",           25, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n0_nx_time",           26, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n0_cxa0_gptr",         28, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n0_cxa0_time",         29, 0x02, 0x02, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_gptr",              34, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n1_time",              35, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_ioo0_gptr",         37, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n1_ioo0_time",         38, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_ioo1_gptr",         40, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n1_ioo1_time",         41, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n1_mcs23_gptr",        43, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n1_mcs23_time",        44, 0x03, 0x03, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n2_gptr",              50, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n2_time",              51, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n2_cxa1_gptr",         53, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n2_cxa1_time",         54, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n2_psi_gptr",          56, 0x04, 0x04, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n3_gptr",              63, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n3_time",              64, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n3_mcs01_gptr",        66, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n3_mcs01_time",        67, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"n3_np_gptr",           69, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"n3_np_time",           70, 0x05, 0x05, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_gptr",              76, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"xb_time",              77, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_io0_gptr",          79, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"xb_io0_time",          80, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_io1_gptr",          82, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"xb_io1_time",          83, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_io2_gptr",          85, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"xb_io2_time",          86, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"xb_pll_gptr",          87, 0x06, 0x06, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"mc_gptr",              97, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  //0x07, 0x08: multicast group 2
    {"mc_time",              98, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},  //0x07, 0x08: multicast group 2
    {"mc_iom01_gptr",       100, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  //0x07, 0x08: multicast group 2
    {"mc_iom23_gptr",       103, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  //0x07, 0x08: multicast group 2
    {"mc_pll_gptr",         105, 0x07, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  //0x07, 0x08: multicast group 2
    {"ob0_gptr",            119, 0x09, 0x09, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob0_time",            120, 0x09, 0x09, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob0_pll_gptr",        121, 0x09, 0x09, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob1_gptr",            128, 0x0A, 0x0A, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob1_time",            129, 0x0A, 0x0A, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob1_pll_gptr",        130, 0x0A, 0x0A, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob2_gptr",            137, 0x0B, 0x0B, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob2_time",            138, 0x0B, 0x0B, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob2_pll_gptr",        139, 0x0B, 0x0B, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob3_gptr",            146, 0x0C, 0x0C, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"ob3_time",            147, 0x0C, 0x0C, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"ob3_pll_gptr",        148, 0x0C, 0x0C, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"pci0_gptr",           155, 0x0D, 0x0D, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"pci0_time",           156, 0x0D, 0x0D, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"pci0_pll_gptr",       158, 0x0D, 0x0D, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"pci1_gptr",           161, 0x0E, 0x0E, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"pci1_time",           162, 0x0E, 0x0E, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"pci1_pll_gptr",       164, 0x0E, 0x0E, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"pci2_gptr",           167, 0x0F, 0x0F, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"pci2_time",           168, 0x0F, 0x0F, VPD_KEYWORD_PDG, VPD_RING_CLASS_NEST},
    {"pci2_pll_gptr",       170, 0x0F, 0x0F, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},
    {"eq_gptr",             173, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x10,x15: multicast group 4
    {"eq_time",             174, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EQ},  // x10,x15: multicast group 4
    {"ex_l3_gptr",          177, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x10,x1B: multicast groups 5 and 6
    {"ex_l3_time",          178, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EX},  // x10,x1B: multicast groups 5 and 6
    {"ex_l2_gptr",          181, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x10,x1B: multicast groups 5 and 6
    {"ex_l2_time",          182, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EX},  // x10,x1B: multicast groups 5 and 6
    {"ex_l3_refr_gptr",     184, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x10,x1B: multicast groups 5 and 6
    {"eq_ana_gptr",         187, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x10,x15: multicast group 4
    {"eq_dpll_gptr",        189, 0x10, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x10,x15: multicast group 4
    {"ec_gptr",             225, 0x20, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_GPTR},  // x20,x37: multicast group 1
    {"ec_time",             226, 0x20, 0xFF, VPD_KEYWORD_PDG, VPD_RING_CLASS_EC},  // x20,x37: multicast group 1
};

const RingIdList RING_ID_LIST_PDR[] =
{
    /* ringName           ringId  chipletId  vpdKeyword    */
    /*                            min   max                 */
    {"perv_repr",            18, 0x01, 0x01, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"occ_repr",             19, 0x01, 0x01, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"perv_pibnet_repr",     20, 0x01, 0x01, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n0_repr",              30, 0x02, 0x02, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n0_nx_repr",           31, 0x02, 0x02, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n0_cxa0_repr",         32, 0x02, 0x02, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_repr",              45, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_ioo0_repr",         46, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_ioo1_repr",         47, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n1_mcs23_repr",        48, 0x03, 0x03, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n2_repr",              58, 0x04, 0x04, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n2_cxa1_repr",         59, 0x04, 0x04, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n3_repr",              71, 0x05, 0x05, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n3_mcs01_repr",        72, 0x05, 0x05, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"n3_np_repr",           73, 0x05, 0x05, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_repr",              90, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_io0_repr",          91, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_io1_repr",          92, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"xb_io2_repr",          93, 0x06, 0x06, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"mc_repr",             113, 0x07, 0x08, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob0_repr",            124, 0x09, 0x09, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob1_repr",            133, 0x0A, 0x0A, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob2_repr",            142, 0x0B, 0x0B, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"ob3_repr",            151, 0x0C, 0x0C, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"pci0_repr",           159, 0x0D, 0x0D, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"pci1_repr",           165, 0x0E, 0x0E, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"pci2_repr",           171, 0x0F, 0x0F, VPD_KEYWORD_PDR, VPD_RING_CLASS_NEST},
    {"eq_repr",             220, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EQ_INS},
    {"ex_l3_refr_time",     185, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ex_l3_repr",          221, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ex_l2_repr",          222, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ex_l3_refr_repr",     223, 0x10, 0x15, VPD_KEYWORD_PDR, VPD_RING_CLASS_EX_INS},
    {"ec_repr",             228, 0x20, 0x37, VPD_KEYWORD_PDR, VPD_RING_CLASS_EC_INS},
};

const VPDRingList ALL_VPD_RINGS[NUM_OF_VPD_TYPES] =
{
    {RING_ID_LIST_PDG,  (sizeof(RING_ID_LIST_PDG) / sizeof(RING_ID_LIST_PDG[0]))},
    {RING_ID_LIST_PDR,  (sizeof(RING_ID_LIST_PDR) / sizeof(RING_ID_LIST_PDR[0]))},

};

const uint32_t RING_ID_LIST_CORE_SIZE = 4;


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




/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/imageProcs/p9_ring_identification.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <p9_ring_identification.H>

const RingIdList RING_ID_LIST_PG[] =
{
    /* ringName           ringId  chipletId  mvpdKeyword    */
    /*                            min   max                 */
    {"perv_gptr",          0x01, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"perv_time",          0x02, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"occ_gptr",           0x04, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"occ_time",           0x05, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"perv_ana_gptr",      0x07, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"perv_pll_gptr",      0x08, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"perv_pibnet_gptr",   0x10, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"perv_pibnet_time",   0x11, 0x01, 0x01, VPD_KEYWORD_PDG},
    {"n0_gptr",            0x16, 0x02, 0x02, VPD_KEYWORD_PDG},
    {"n0_time",            0x17, 0x02, 0x02, VPD_KEYWORD_PDG},
    {"n0_nx_gptr",         0x19, 0x02, 0x02, VPD_KEYWORD_PDG},
    {"n0_nx_time",         0x1A, 0x02, 0x02, VPD_KEYWORD_PDG},
    {"n0_cxa0_gptr",       0x1C, 0x02, 0x02, VPD_KEYWORD_PDG},
    {"n0_cxa0_time",       0x1D, 0x02, 0x02, VPD_KEYWORD_PDG},
    {"n1_gptr",            0x22, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_time",            0x23, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_ioo0_gptr",       0x25, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_ioo0_time",       0x26, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_ioo1_gptr",       0x28, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_ioo1_time",       0x29, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_mcs23_gptr",      0x2B, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n1_mcs23_time",      0x2C, 0x03, 0x03, VPD_KEYWORD_PDG},
    {"n2_gptr",            0x32, 0x04, 0x04, VPD_KEYWORD_PDG},
    {"n2_time",            0x33, 0x04, 0x04, VPD_KEYWORD_PDG},
    {"n2_cxa1_gptr",       0x35, 0x04, 0x04, VPD_KEYWORD_PDG},
    {"n2_cxa1_time",       0x36, 0x04, 0x04, VPD_KEYWORD_PDG},
    {"n2_psi_gptr",        0x38, 0x04, 0x04, VPD_KEYWORD_PDG},
    {"n3_gptr",            0x3F, 0x05, 0x05, VPD_KEYWORD_PDG},
    {"n3_time",            0x40, 0x05, 0x05, VPD_KEYWORD_PDG},
    {"n3_mcs01_gptr",      0x42, 0x05, 0x05, VPD_KEYWORD_PDG},
    {"n3_mcs01_time",      0x43, 0x05, 0x05, VPD_KEYWORD_PDG},
    {"n3_np_gptr",         0x45, 0x05, 0x05, VPD_KEYWORD_PDG},
    {"n3_np_time",         0x46, 0x05, 0x05, VPD_KEYWORD_PDG},
    {"xb_gptr",            0x4C, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_time",            0x4D, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_io0_gptr",        0x4F, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_io0_time",        0x50, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_io1_gptr",        0x52, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_io1_time",        0x53, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_io2_gptr",        0x55, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_io2_time",        0x56, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"xb_pll_gptr",        0x57, 0x06, 0x06, VPD_KEYWORD_PDG},
    {"mc_gptr",            0x66, 0x07, 0xFF, VPD_KEYWORD_PDG},  //0x07, 0x08: multicast group 2
    {"mc_time",            0x67, 0x07, 0xFF, VPD_KEYWORD_PDG},  //0x07, 0x08: multicast group 2
    {"mc_iom01_gptr",      0x69, 0x07, 0xFF, VPD_KEYWORD_PDG},  //0x07, 0x08: multicast group 2
    {"mc_iom23_gptr",      0x6C, 0x07, 0xFF, VPD_KEYWORD_PDG},  //0x07, 0x08: multicast group 2
    {"mc_pll_gptr",        0x6E, 0x07, 0xFF, VPD_KEYWORD_PDG},  //0x07, 0x08: multicast group 2
    {"ob0_gptr",           0x7C, 0x09, 0x09, VPD_KEYWORD_PDG},
    {"ob0_time",           0x7D, 0x09, 0x09, VPD_KEYWORD_PDG},
    {"ob0_pll_gptr",       0x7E, 0x09, 0x09, VPD_KEYWORD_PDG},
    {"ob1_gptr",           0x8A, 0x0A, 0x0A, VPD_KEYWORD_PDG},
    {"ob1_time",           0x8B, 0x0A, 0x0A, VPD_KEYWORD_PDG},
    {"ob1_pll_gptr",       0x8C, 0x0A, 0x0A, VPD_KEYWORD_PDG},
    {"ob2_gptr",           0x98, 0x0B, 0x0B, VPD_KEYWORD_PDG},
    {"ob2_time",           0x99, 0x0B, 0x0B, VPD_KEYWORD_PDG},
    {"ob2_pll_gptr",       0x9A, 0x0B, 0x0B, VPD_KEYWORD_PDG},
    {"ob3_gptr",           0xA6, 0x0C, 0x0C, VPD_KEYWORD_PDG},
    {"ob3_time",           0xA7, 0x0C, 0x0C, VPD_KEYWORD_PDG},
    {"ob3_pll_gptr",       0xA8, 0x0C, 0x0C, VPD_KEYWORD_PDG},
    {"pci0_gptr",          0xB4, 0x0D, 0x0D, VPD_KEYWORD_PDG},
    {"pci0_time",          0xB5, 0x0D, 0x0D, VPD_KEYWORD_PDG},
    {"pci0_pll_gptr",      0xB7, 0x0D, 0x0D, VPD_KEYWORD_PDG},
    {"pci1_gptr",          0xBA, 0x0E, 0x0E, VPD_KEYWORD_PDG},
    {"pci1_time",          0xBB, 0x0E, 0x0E, VPD_KEYWORD_PDG},
    {"pci1_pll_gptr",      0xBD, 0x0E, 0x0E, VPD_KEYWORD_PDG},
    {"pci2_gptr",          0xC0, 0x0F, 0x0F, VPD_KEYWORD_PDG},
    {"pci2_time",          0xC1, 0x0F, 0x0F, VPD_KEYWORD_PDG},
    {"pci2_pll_gptr",      0xC3, 0x0F, 0x0F, VPD_KEYWORD_PDG},
    {"eq_gptr",            0xC6, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x15: multicast group 4
    {"eq_time",            0xC7, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x15: multicast group 4
    {"ex_l3_gptr",         0xCA, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x1B: multicast groups 5 and 6
    {"ex_l3_time",         0xCB, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x1B: multicast groups 5 and 6
    {"ex_l2_gptr",         0xCE, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x1B: multicast groups 5 and 6
    {"ex_l2_time",         0xCF, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x1B: multicast groups 5 and 6
    {"ex_l3_refr_gptr",    0xD1, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x1B: multicast groups 5 and 6
    {"ex_l3_refr_time",    0xD2, 0x10, 0x15, VPD_KEYWORD_PDG},
    {"eq_ana_gptr",        0xD4, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x15: multicast group 4
    {"eq_dpll_gptr",       0xD6, 0x10, 0xFF, VPD_KEYWORD_PDG},  // x10,x15: multicast group 4
    {"ec_gptr",            0xDF, 0x20, 0xFF, VPD_KEYWORD_PDG},  // x20,x37: multicast group 1
    {"ec_time",            0xE0, 0x20, 0xFF, VPD_KEYWORD_PDG},  // x20,x37: multicast group 1
};

const RingIdList RING_ID_LIST_PR[] =
{
    /* ringName           ringId  chipletId  mvpdKeyword    */
    /*                            min   max                 */
    {"perv_repr",          0x12, 0x01, 0x01, VPD_KEYWORD_PDR},
    {"occ_repr",           0x13, 0x01, 0x01, VPD_KEYWORD_PDR},
    {"perv_pibnet_repr",   0x14, 0x01, 0x01, VPD_KEYWORD_PDR},
    {"n0_repr",            0x1E, 0x02, 0x02, VPD_KEYWORD_PDR},
    {"n0_nx_repr",         0x1F, 0x02, 0x02, VPD_KEYWORD_PDR},
    {"n0_cxa0_repr",       0x20, 0x02, 0x02, VPD_KEYWORD_PDR},
    {"n1_repr",            0x2D, 0x03, 0x03, VPD_KEYWORD_PDR},
    {"n1_ioo0_repr",       0x2E, 0x03, 0x03, VPD_KEYWORD_PDR},
    {"n1_ioo1_repr",       0x2F, 0x03, 0x03, VPD_KEYWORD_PDR},
    {"n1_mcs23_repr",      0x30, 0x03, 0x03, VPD_KEYWORD_PDR},
    {"n2_repr",            0x3A, 0x04, 0x04, VPD_KEYWORD_PDR},
    {"n2_cxa1_repr",       0x3B, 0x04, 0x04, VPD_KEYWORD_PDR},
    {"n3_repr",            0x47, 0x05, 0x05, VPD_KEYWORD_PDR},
    {"n3_mcs01_repr",      0x48, 0x05, 0x05, VPD_KEYWORD_PDR},
    {"n3_np_repr",         0x49, 0x05, 0x05, VPD_KEYWORD_PDR},
    {"xb_repr",            0x5F, 0x06, 0x06, VPD_KEYWORD_PDR},
    {"xb_io0_repr",        0x60, 0x06, 0x06, VPD_KEYWORD_PDR},
    {"xb_io1_repr",        0x61, 0x06, 0x06, VPD_KEYWORD_PDR},
    {"xb_io2_repr",        0x62, 0x06, 0x06, VPD_KEYWORD_PDR},
    {"mc_repr",            0x76, 0x07, 0x08, VPD_KEYWORD_PDR},
    {"ob0_repr",           0x86, 0x09, 0x09, VPD_KEYWORD_PDR},
    {"ob1_repr",           0x94, 0x0A, 0x0A, VPD_KEYWORD_PDR},
    {"ob2_repr",           0xA2, 0x0B, 0x0B, VPD_KEYWORD_PDR},
    {"ob3_repr",           0xB0, 0x0C, 0x0C, VPD_KEYWORD_PDR},
    {"pci0_repr",          0xB8, 0x0D, 0x0D, VPD_KEYWORD_PDR},
    {"pci1_repr",          0xBE, 0x0E, 0x0E, VPD_KEYWORD_PDR},
    {"pci2_repr",          0xC4, 0x0F, 0x0F, VPD_KEYWORD_PDR},
    {"eq_repr",            0xDA, 0x10, 0x15, VPD_KEYWORD_PDR},
    {"ex_l3_repr",         0xDB, 0x10, 0x1B, VPD_KEYWORD_PDR},
    {"ex_l2_repr",         0xDC, 0x10, 0x1B, VPD_KEYWORD_PDR},
    {"ex_l3_refr_repr",    0xDD, 0x10, 0x1B, VPD_KEYWORD_PDR},
    {"ec_repr",            0xE2, 0x20, 0x37, VPD_KEYWORD_PDR},
};

const uint32_t RING_ID_LIST_PG_SIZE = sizeof(RING_ID_LIST_PG) / sizeof(
        RING_ID_LIST_PG[0]);
const uint32_t RING_ID_LIST_PR_SIZE = sizeof(RING_ID_LIST_PR) / sizeof(
        RING_ID_LIST_PR[0]);
const uint32_t RING_ID_LIST_CORE_SIZE = 4;


// get_vpd_ring_list_entry() retrieves the MVPD list entry based on either a ringName
//   or a ringId.  If both are supplied, only the ringName is used. If ringName==NULL,
//   then the ringId is used. A pointer to the RingIdList is returned.
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





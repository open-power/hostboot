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
    /* ringName       ringId  chipletId    ringNameImg            mvpdKeyword    wc */
    /*                        min   max                                               */
    {"ab_gptr_ab",     0xA0, 0x08, 0x08, "ab_gptr_ab_ring",     VPD_KEYWORD_PDG, 0},
    {"ab_gptr_ioa",    0xA1, 0x08, 0x08, "ab_gptr_ioa_ring",    VPD_KEYWORD_PDG, 0},
    {"ab_gptr_perv",   0xA2, 0x08, 0x08, "ab_gptr_perv_ring",   VPD_KEYWORD_PDG, 0},
    {"ab_gptr_pll",    0xA3, 0x08, 0x08, "ab_gptr_pll_ring",    VPD_KEYWORD_PDG, 0},
    {"ab_time",        0xA4, 0x08, 0x08, "ab_time_ring",        VPD_KEYWORD_PDG, 0},
    {"ex_gptr_core",   0xA5, 0xFF, 0xFF, "ex_gptr_core_ring",   VPD_KEYWORD_PDG, 0},   //Chip specific
    {"ex_gptr_dpll",   0xA6, 0xFF, 0xFF, "ex_gptr_dpll_ring",   VPD_KEYWORD_PDG, 0},   //Chip specific
    {"ex_gptr_l2",     0xA7, 0xFF, 0xFF, "ex_gptr_l2_ring",     VPD_KEYWORD_PDG, 0},     //Chip specific
    {"ex_gptr_l3",     0xA8, 0xFF, 0xFF, "ex_gptr_l3_ring",     VPD_KEYWORD_PDG, 0},     //Chip specific
    {"ex_gptr_l3refr", 0xA9, 0xFF, 0xFF, "ex_gptr_l3refr_ring", VPD_KEYWORD_PDG, 0}, //Chip specific
    {"ex_gptr_perv",   0xAA, 0xFF, 0xFF, "ex_gptr_perv_ring",   VPD_KEYWORD_PDG, 0},   //Chip specific
    {"ex_time_core",   0xAB, 0x10, 0x1F, "ex_time_core_ring",   VPD_KEYWORD_PDG, 0},   //Chiplet specfc
    {"ex_time_eco",    0xAC, 0x10, 0x1F, "ex_time_eco_ring",    VPD_KEYWORD_PDG, 0},    //Chiplet specfc
    {"pb_gptr_dmipll", 0xAD, 0x02, 0x02, "pb_gptr_dmipll_ring", VPD_KEYWORD_PDG, 0},
    {"pb_gptr_mcr",    0xAE, 0x02, 0x02, "pb_gptr_mcr_ring",    VPD_KEYWORD_PDG, 0},
    {"pb_gptr_nest",   0xAF, 0x02, 0x02, "pb_gptr_nest_ring",   VPD_KEYWORD_PDG, 0},
    {"pb_gptr_nx",     0xB0, 0x02, 0x02, "pb_gptr_nx_ring",     VPD_KEYWORD_PDG, 0},
    {"pb_gptr_pcis",   0xB1, 0x02, 0x02, "pb_gptr_pcis_ring",   VPD_KEYWORD_PDG, 0},
    {"pb_gptr_perv",   0xB2, 0x02, 0x02, "pb_gptr_perv_ring",   VPD_KEYWORD_PDG, 0},
    {"pb_time",        0xB3, 0x02, 0x02, "pb_time_ring",        VPD_KEYWORD_PDG, 0},
    {"pb_time_mcr",    0xB4, 0x02, 0x02, "pb_time_mcr_ring",    VPD_KEYWORD_PDG, 0},
    {"pb_time_nx",     0xB5, 0x02, 0x02, "pb_time_nx_ring",     VPD_KEYWORD_PDG, 0},
    {"pci_gptr_iopci", 0xB6, 0x09, 0x09, "pci_gptr_iopci_ring", VPD_KEYWORD_PDG, 0},
    {"pci_gptr_pbf",   0xB7, 0x09, 0x09, "pci_gptr_pbf_ring",   VPD_KEYWORD_PDG, 0},
    {"pci_gptr_pci0",  0xB8, 0x09, 0x09, "pci_gptr_pci0_ring",  VPD_KEYWORD_PDG, 0},
    {"pci_gptr_pci1",  0xB9, 0x09, 0x09, "pci_gptr_pci1_ring",  VPD_KEYWORD_PDG, 0},
    {"pci_gptr_pci2",  0xBA, 0x09, 0x09, "pci_gptr_pci2_ring",  VPD_KEYWORD_PDG, 0},
    {"pci_gptr_perv",  0xBB, 0x09, 0x09, "pci_gptr_perv_ring",  VPD_KEYWORD_PDG, 0},
    {"pci_gptr_pll",   0xBC, 0x09, 0x09, "pci_gptr_pll_ring",   VPD_KEYWORD_PDG, 0},
    {"pci_time",       0xBD, 0x09, 0x09, "pci_time_ring",       VPD_KEYWORD_PDG, 0},
    {"perv_gptr_net",  0xBE, 0x00, 0x00, "perv_gptr_net_ring",  VPD_KEYWORD_PDG, 0},
    {"perv_gptr_occ",  0xBF, 0x00, 0x00, "perv_gptr_occ_ring",  VPD_KEYWORD_PDG, 0},
    {"perv_gptr_perv", 0xC0, 0x00, 0x00, "perv_gptr_perv_ring", VPD_KEYWORD_PDG, 0},
    {"perv_gptr_pib",  0xC1, 0x00, 0x00, "perv_gptr_pib_ring",  VPD_KEYWORD_PDG, 0},
    {"perv_gptr_pll",  0xC2, 0x00, 0x00, "perv_gptr_pll_ring",  VPD_KEYWORD_PDG, 0},
    {"perv_time",      0xC3, 0x00, 0x00, "perv_time_ring",      VPD_KEYWORD_PDG, 0},
    {"xb_gptr_iopci",  0xC4, 0x04, 0x04, "xb_gptr_iopci_ring",  VPD_KEYWORD_PDG, 0},
    {"xb_gptr_iox",    0xC5, 0x04, 0x04, "xb_gptr_iox_ring",    VPD_KEYWORD_PDG, 0},
    {"xb_gptr_pben",   0xC6, 0x04, 0x04, "xb_gptr_pben_ring",   VPD_KEYWORD_PDG, 0},
    {"xb_gptr_perv",   0xC7, 0x04, 0x04, "xb_gptr_perv_ring",   VPD_KEYWORD_PDG, 0},
    {"xb_time",        0xC8, 0x04, 0x04, "xb_time_ring",        VPD_KEYWORD_PDG, 0},
    {"pb_gptr_mcl",    0xC9, 0x02, 0x02, "pb_gptr_mcl_ring",    VPD_KEYWORD_PDG, 0},
    {"pb_time_mcl",    0xCA, 0x02, 0x02, "pb_time_mcl_ring",    VPD_KEYWORD_PDG, 0},
};

const RingIdList RING_ID_LIST_PR[] =
{
    /*   ringName      ringId chipIdMin chipIdMax     ringNameImg        mvpdKeyword   */
    {"ab_repr",        0xE0, 0x08, 0x08, "ab_repr_ring",        VPD_KEYWORD_PDR, 0},
    {"ex_repr_core",   0xE1, 0x10, 0x1F, "ex_repr_core_ring",   VPD_KEYWORD_PDR, 1},
    {"ex_repr_eco",    0xE2, 0x10, 0x1F, "ex_repr_eco_ring",    VPD_KEYWORD_PDR, 1},
    {"pb_repr",        0xE3, 0x02, 0x02, "pb_repr_ring",        VPD_KEYWORD_PDR, 0},
    {"pb_repr_mcr",    0xE4, 0x02, 0x02, "pb_repr_mcr_ring",    VPD_KEYWORD_PDR, 0},
    {"pb_repr_nx",     0xE5, 0x02, 0x02, "pb_repr_nx_ring",     VPD_KEYWORD_PDR, 0},
    {"pci_repr",       0xE6, 0x09, 0x09, "pci_repr_ring",       VPD_KEYWORD_PDR, 0},
    {"perv_repr",      0xE7, 0x00, 0x00, "perv_repr_ring",      VPD_KEYWORD_PDR, 0},
    {"perv_repr_net",  0xE8, 0x00, 0x00, "perv_repr_net_ring",  VPD_KEYWORD_PDR, 0},
    {"perv_repr_pib",  0xE9, 0x00, 0x00, "perv_repr_pib_ring",  VPD_KEYWORD_PDR, 0},
    {"xb_repr",        0xEA, 0x04, 0x04, "xb_repr_ring",        VPD_KEYWORD_PDR, 0},
    {"pb_repr_mcl",    0xEB, 0x02, 0x02, "pb_repr_mcl_ring",    VPD_KEYWORD_PDR, 0},
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
                if ( strcmp((ring_id_list + iRing)->ringName,   i_ringName) == 0  ||
                     strcmp((ring_id_list + iRing)->ringNameImg, i_ringName) == 0 )
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





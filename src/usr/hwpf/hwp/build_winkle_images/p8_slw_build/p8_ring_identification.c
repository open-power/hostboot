/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_ring_identification.c $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p8_ring_identification.c,v 1.12 2012/12/16 02:06:13 cmolsen Exp $
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2012                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! *** IBM Confidential ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE :       p8_ring_identification                                      */
/* *! DESCRIPTION : Global static #G & #R ringID vs ringName.                   */
/* *! OWNER NAME :  Michael Olsen            Email: cmolsen@us.ibm.com          */
//
/*------------------------------------------------------------------------------*/
#include <p8_ring_identification.H>

const RingIdList RING_ID_LIST_PG[] = {
  /*   ringName      ringId chipIdMin chipIdMax     ringNameImg        mvpdKeyword  */
	{ "ab_gptr_ab",     0xA0,    0x08,    0x08,   "ab_gptr_ab_ring",     VPD_KEYWORD_PDG },
	{ "ab_gptr_ioa",    0xA1,    0x08,    0x08,   "ab_gptr_ioa_ring",    VPD_KEYWORD_PDG },
	{ "ab_gptr_perv",   0xA2,    0x08,    0x08,   "ab_gptr_perv_ring",   VPD_KEYWORD_PDG },
	{ "ab_gptr_pll",    0xA3,    0x08,    0x08,   "ab_gptr_pll_ring",    VPD_KEYWORD_PDG },
	{ "ab_time",        0xA4,    0x08,    0x08,   "ab_time_ring",        VPD_KEYWORD_PDG },
	{ "ex_gptr_core",   0xA5,    0xFF,    0xFF,   "ex_gptr_core_ring",   VPD_KEYWORD_PDG },   //Chip specific
	{ "ex_gptr_dpll",   0xA6,    0xFF,    0xFF,   "ex_gptr_dpll_ring",   VPD_KEYWORD_PDG },   //Chip specific
	{ "ex_gptr_l2",     0xA7,    0xFF,    0xFF,   "ex_gptr_l2_ring",     VPD_KEYWORD_PDG },     //Chip specific
	{ "ex_gptr_l3",     0xA8,    0xFF,    0xFF,   "ex_gptr_l3_ring",     VPD_KEYWORD_PDG },     //Chip specific
	{ "ex_gptr_l3refr", 0xA9,    0xFF,    0xFF,   "ex_gptr_l3refr_ring", VPD_KEYWORD_PDG }, //Chip specific
	{ "ex_gptr_perv",   0xAA,    0xFF,    0xFF,   "ex_gptr_perv_ring",   VPD_KEYWORD_PDG },   //Chip specific
	{ "ex_time_core",   0xAB,    0x10,    0x1F,   "ex_time_core_ring",   VPD_KEYWORD_PDG },   //Chiplet specfc
	{ "ex_time_eco",    0xAC,    0x10,    0x1F,   "ex_time_eco_ring",    VPD_KEYWORD_PDG },    //Chiplet specfc
	{ "pb_gptr_dmipll", 0xAD,    0x02,    0x02,   "pb_gptr_dmipll_ring", VPD_KEYWORD_PDG },
	{ "pb_gptr_mcl",    0xAE,    0x02,    0x02,   "pb_gptr_mcl_ring",    VPD_KEYWORD_PDG },
	{ "pb_gptr_mcr",    0xAF,    0x02,    0x02,   "pb_gptr_mcr_ring",    VPD_KEYWORD_PDG },
	{ "pb_gptr_nest",   0xB0,    0x02,    0x02,   "pb_gptr_nest_ring",   VPD_KEYWORD_PDG },
	{ "pb_gptr_nx",     0xB1,    0x02,    0x02,   "pb_gptr_nx_ring",     VPD_KEYWORD_PDG },
	{ "pb_gptr_pcis",   0xB2,    0x02,    0x02,   "pb_gptr_pcis_ring",   VPD_KEYWORD_PDG },
	{ "pb_gptr_perv",   0xB3,    0x02,    0x02,   "pb_gptr_perv_ring",   VPD_KEYWORD_PDG },
	{ "pb_time",        0xB4,    0x02,    0x02,   "pb_time_ring",        VPD_KEYWORD_PDG },
	{ "pb_time_mcl",    0xB5,    0x02,    0x02,   "pb_time_mcl_ring",    VPD_KEYWORD_PDG },
	{ "pb_time_mcr",    0xB5,    0x02,    0x02,   "pb_time_mcr_ring",    VPD_KEYWORD_PDG },
	{ "pb_time_nx",     0xB6,    0x02,    0x02,   "pb_time_nx_ring",     VPD_KEYWORD_PDG },
	{ "pci_gptr_iopci", 0xB7,    0x09,    0x09,   "pci_gptr_iopci_ring", VPD_KEYWORD_PDG },
	{ "pci_gptr_pbf",   0xB8,    0x09,    0x09,   "pci_gptr_pbf_ring",   VPD_KEYWORD_PDG },
	{ "pci_gptr_pci0",  0xB9,    0x09,    0x09,   "pci_gptr_pci0_ring",  VPD_KEYWORD_PDG },
	{ "pci_gptr_pci1",  0xBA,    0x09,    0x09,   "pci_gptr_pci1_ring",  VPD_KEYWORD_PDG },
	{ "pci_gptr_pci2",  0xBB,    0x09,    0x09,   "pci_gptr_pci2_ring",  VPD_KEYWORD_PDG },
	{ "pci_gptr_perv",  0xBC,    0x09,    0x09,   "pci_gptr_perv_ring",  VPD_KEYWORD_PDG },
	{ "pci_gptr_pll",   0xBD,    0x09,    0x09,   "pci_gptr_pll_ring",   VPD_KEYWORD_PDG },
	{ "pci_time",       0xBE,    0x09,    0x09,   "pci_time_ring",       VPD_KEYWORD_PDG },
	{ "perv_gptr_net",  0xBF,    0x00,    0x00,   "perv_gptr_net_ring",  VPD_KEYWORD_PDG },
	{ "perv_gptr_occ",  0xC0,    0x00,    0x00,   "perv_gptr_occ_ring",  VPD_KEYWORD_PDG },
	{ "perv_gptr_perv", 0xC1,    0x00,    0x00,   "perv_gptr_perv_ring", VPD_KEYWORD_PDG },
	{ "perv_gptr_pib",  0xC2,    0x00,    0x00,   "perv_gptr_pib_ring",  VPD_KEYWORD_PDG },
	{ "perv_gptr_pll",  0xC3,    0x00,    0x00,   "perv_gptr_pll_ring",  VPD_KEYWORD_PDG },
	{ "perv_time",      0xC4,    0x00,    0x00,   "perv_time_ring",      VPD_KEYWORD_PDG },
	{ "xb_gptr_iox",    0xC5,    0x04,    0x04,   "xb_gptr_iox_ring",    VPD_KEYWORD_PDG },
	{ "xb_gptr_iopci",  0xC6,    0x04,    0x04,   "xb_gptr_iopci_ring",  VPD_KEYWORD_PDG },
	{ "xb_gptr_pben",   0xC7,    0x04,    0x04,   "xb_gptr_pben_ring",   VPD_KEYWORD_PDG },
	{ "xb_gptr_perv",   0xC8,    0x04,    0x04,   "xb_gptr_perv_ring",   VPD_KEYWORD_PDG },
	{ "xb_time",        0xC9,    0x04,    0x04,   "xb_time_ring",        VPD_KEYWORD_PDG },
};

const RingIdList RING_ID_LIST_PR[] = {
  /*   ringName      ringId chipIdMin chipIdMax     ringNameImg        mvpdKeyword   */
  { "ab_repr",        0xE0,    0x08,     0x08,   "ab_repr_ring",       VPD_KEYWORD_PDR },
  { "ex_repr_core",   0xE1,    0x10,     0x1F,   "ex_repr_core_ring",  VPD_KEYWORD_PDR },
  { "ex_repr_eco",    0xE2,    0x10,     0x1F,   "ex_repr_eco_ring",   VPD_KEYWORD_PDR },
  { "pb_repr",        0xE3,    0x02,     0x02,   "pb_repr_ring",       VPD_KEYWORD_PDR },
  { "pb_repr_mcl",    0xE4,    0x02,     0x02,   "pb_repr_mcl_ring",   VPD_KEYWORD_PDR },
  { "pb_repr_mcr",    0xE5,    0x02,     0x02,   "pb_repr_mcr_ring",   VPD_KEYWORD_PDR },
  { "pb_repr_nx",     0xE6,    0x02,     0x02,   "pb_repr_nx_ring",    VPD_KEYWORD_PDR },
  { "pci_repr",       0xE7,    0x09,     0x09,   "pci_repr_ring",      VPD_KEYWORD_PDR },
  { "perv_repr",      0xE8,    0x00,     0x00,   "perv_repr_ring",     VPD_KEYWORD_PDR },
  { "perv_repr_net",  0xE9,    0x00,     0x00,   "perv_repr_net_ring", VPD_KEYWORD_PDR },
  { "perv_repr_pib",  0xEA,    0x00,     0x00,   "perv_repr_pib_ring", VPD_KEYWORD_PDR },
  { "xb_repr",        0xEB,    0x04,     0x04,   "xb_repr_ring",       VPD_KEYWORD_PDR },
};

const uint32_t RING_ID_LIST_PG_SIZE = sizeof(RING_ID_LIST_PG)/sizeof(RING_ID_LIST_PG[0]);
const uint32_t RING_ID_LIST_PR_SIZE = sizeof(RING_ID_LIST_PR)/sizeof(RING_ID_LIST_PR[0]);

// The following defines are probably safe to decommision at this point.
const RingIdList RING_ID_LIST[] = {
  /*   ringName      ringId chipIdMin chipIdMax     ringNameImg        mvpdKeyword  */
  { "ab_repr",        0xE0,    0x08,     0x08,   "ab_repr_ring",       VPD_KEYWORD_PDR },
  { "ex_repr_core",   0xE1,    0x10,     0x1F,   "ex_repr_core_ring",  VPD_KEYWORD_PDR },
  { "ex_repr_eco",    0xE2,    0x10,     0x1F,   "ex_repr_eco_ring",   VPD_KEYWORD_PDR },
  { "pb_repr",        0xE3,    0x02,     0x02,   "pb_repr_ring",       VPD_KEYWORD_PDR },
  { "pb_repr_mcl",    0xE4,    0x02,     0x02,   "pb_repr_mcl_ring",   VPD_KEYWORD_PDR },
  { "pb_repr_mcr",    0xE5,    0x02,     0x02,   "pb_repr_mcr_ring",   VPD_KEYWORD_PDR },
  { "pb_repr_nx",     0xE6,    0x02,     0x02,   "pb_repr_nx_ring",    VPD_KEYWORD_PDR },
  { "pci_repr",       0xE7,    0x09,     0x09,   "pci_repr_ring",      VPD_KEYWORD_PDR },
  { "perv_repr",      0xE8,    0x00,     0x00,   "perv_repr_ring",     VPD_KEYWORD_PDR },
  { "perv_repr_net",  0xE9,    0x00,     0x00,   "perv_repr_net_ring", VPD_KEYWORD_PDR },
  { "perv_repr_pib",  0xEA,    0x00,     0x00,   "perv_repr_pib_ring", VPD_KEYWORD_PDR },
  { "xb_repr",        0xEB,    0x04,     0x04,   "xb_repr_ring",       VPD_KEYWORD_PDR },
};
const uint32_t RING_ID_LIST_SIZE = sizeof(RING_ID_LIST)/sizeof(RING_ID_LIST[0]);

// get_vpd_ring_list_entry() retrieves the MVPD list entry based on either a ringName
//   or a ringId.  If both are supplied, only the ringName is used. If ringName==NULL,
//   then the ringId is used. A pointer to the RingIdList is returned.
int get_vpd_ring_list_entry(const char *i_ringName, 
														const uint8_t i_ringId, 
														RingIdList **i_ringIdList)
{
	int rc=0, NOT_FOUND=0, FOUND=1;
  uint8_t iVpdType;
  uint8_t iRing;
	RingIdList *ring_id_list=NULL;
	uint8_t ring_id_list_size;

	rc = NOT_FOUND;
	for (iVpdType=0; iVpdType<NUM_OF_VPD_TYPES; iVpdType++)  {
    if (iVpdType==0)  {
		  ring_id_list = (RingIdList*)RING_ID_LIST_PG;
		  ring_id_list_size = (uint32_t)RING_ID_LIST_PG_SIZE;
		}
		else  {
		  ring_id_list = (RingIdList*)RING_ID_LIST_PR;
		  ring_id_list_size = (uint32_t)RING_ID_LIST_PR_SIZE;
		}
		// Search the MVPD reference lists.
		if (i_ringName)  {
			for (iRing=0; iRing<ring_id_list_size; iRing++)  {
				if (strcmp((ring_id_list+iRing)->ringNameImg,i_ringName)==0)  {
			  	*i_ringIdList = ring_id_list+iRing;
					return FOUND;
			  }
	  	}
		}
		// Since ringName was not supplied, search for ringId.
		// 2012-11-12: TBD.

	}
	return rc;
}


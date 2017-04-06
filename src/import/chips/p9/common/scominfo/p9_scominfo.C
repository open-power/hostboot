/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/scominfo/p9_scominfo.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
///
/// @file p9_scominfo.C
/// @brief P9 chip unit SCOM address platform translation code
///
/// HWP HWP Owner: jmcgill@us.ibm.com
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

// includes
#include "p9_scominfo.H"
#include "p9_scom_addr.H"

#define P9_SCOMINFO_C

extern "C"
{
    uint64_t p9_scominfo_createChipUnitScomAddr(const p9ChipUnits_t i_p9CU, const uint8_t i_chipUnitNum,
            const uint64_t i_scomAddr, const uint32_t i_mode)
    {
        p9_scom_addr l_scom(i_scomAddr);
        uint8_t l_ring = l_scom.get_ring();
        uint8_t l_chiplet_id = l_scom.get_chiplet_id();

        //Used to help generate entries for the SCOMdef documentation,
        //These aren't general PIB addresses
        if ((i_mode & PPE_MODE) == PPE_MODE)
        {
            switch (i_p9CU)
            {

                case PU_EX_CHIPUNIT:
                    if (PPE_EP05_CHIPLET_ID >= l_scom.get_chiplet_id() &&
                        l_scom.get_chiplet_id() >= PPE_EP00_CHIPLET_ID)
                    {
                        l_scom.set_chiplet_id(PPE_EP00_CHIPLET_ID + (i_chipUnitNum / 2));
                        l_scom.set_port( ( i_chipUnitNum % 2 ) + 1 );
                    }

                    break;

                default:
                    l_scom.set_addr(FAILED_TRANSLATION);
                    break;
            }
        }
        //Regular PIB addresses (not PPE)
        else
        {
            switch (i_p9CU)
            {
                case PU_PERV_CHIPUNIT:
                    l_scom.set_chiplet_id(i_chipUnitNum);
                    break;

                case PU_C_CHIPUNIT:
                    l_scom.set_chiplet_id(EC00_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_EX_CHIPUNIT:
                    if (EP05_CHIPLET_ID >= l_scom.get_chiplet_id() &&
                        l_scom.get_chiplet_id() >= EP00_CHIPLET_ID)
                    {
                        l_scom.set_chiplet_id(EP00_CHIPLET_ID + (i_chipUnitNum / 2));
                        uint8_t l_ringId = (l_scom.get_ring() & 0xF); // Clear bits 16:17
                        l_ringId = ( l_ringId - ( l_ringId % 2 ) ) + ( i_chipUnitNum % 2 );
                        l_scom.set_ring( l_ringId & 0xF );
                    }
                    else if (EC23_CHIPLET_ID >= l_scom.get_chiplet_id() &&
                             l_scom.get_chiplet_id() >= EC00_CHIPLET_ID)
                    {
                        l_scom.set_chiplet_id( EC00_CHIPLET_ID +
                                               (l_scom.get_chiplet_id() % 2) +
                                               (i_chipUnitNum * 2));
                    }

                    break;

                case PU_EQ_CHIPUNIT:
                    l_scom.set_chiplet_id(EP00_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_CAPP_CHIPUNIT:
                    l_scom.set_chiplet_id(N0_CHIPLET_ID + (i_chipUnitNum * 2));
                    break;

                case PU_MCS_CHIPUNIT:
                    l_scom.set_chiplet_id(N3_CHIPLET_ID - (2 * (i_chipUnitNum / 2)));
                    l_scom.set_sat_id(2 * (i_chipUnitNum % 2));
                    break;

                case PU_MCBIST_CHIPUNIT:
                    l_scom.set_chiplet_id(MC01_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_MCA_CHIPUNIT:
                    if (l_scom.get_chiplet_id() == MC01_CHIPLET_ID || l_scom.get_chiplet_id() ==  MC23_CHIPLET_ID)
                    {
                        l_scom.set_chiplet_id(MC01_CHIPLET_ID + (i_chipUnitNum / 4));

                        if ( (l_scom.get_ring() & 0xF) == MC_MC01_0_RING_ID)
                        {
                            // mc
                            l_scom.set_sat_id( ( l_scom.get_sat_id() - ( l_scom.get_sat_id() % 4 ) ) +
                                               ( i_chipUnitNum % 4 ));
                        }
                        else
                        {
                            // iomc
                            l_scom.set_ring( (MC_IOM01_0_RING_ID + (i_chipUnitNum % 4)) & 0xF );
                        }
                    }
                    else
                    {
                        //mcs->mca regisers
                        uint8_t i_mcs_unitnum = ( i_chipUnitNum / 2 );
                        l_scom.set_chiplet_id(N3_CHIPLET_ID - (2 * (i_mcs_unitnum / 2)));
                        l_scom.set_sat_id(2 * (i_mcs_unitnum % 2));
                        uint8_t i_mcs_sat_offset = (0x2F & l_scom.get_sat_offset());
                        i_mcs_sat_offset |= ((i_chipUnitNum % 2) << 4);
                        l_scom.set_sat_offset(i_mcs_sat_offset);
                    }

                    break;

                case PU_MC_CHIPUNIT:
                    l_scom.set_chiplet_id(MC01_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_MI_CHIPUNIT:
                    //-------------------------------------------
                    // MI
                    //-------------------------------------------
                    //          Chiplet   Ring   Satid   Off
                    //MCS0           05     02       0   !SCOM3
                    //MCS1           05     02       2   !SCOM3
                    //MCS2           03     02       0   !SCOM3
                    //MCS3           03     02       2   !SCOM3
                    l_scom.set_chiplet_id(N3_CHIPLET_ID - (2 * (i_chipUnitNum / 2)));
                    l_scom.set_sat_id(2 * (i_chipUnitNum % 2));
                    break;

                case PU_DMI_CHIPUNIT:
                    if (((l_chiplet_id == N3_CHIPLET_ID) || (l_chiplet_id == N1_CHIPLET_ID)))
                    {
                        //SCOM3   (See mc_clscom_rlm.fig <= 0xB vs mc_scomfir_rlm.fig > 0xB)
                        //DMI0           05     02       0   0x2X (X <= 0xB)
                        //DMI1           05     02       0   0x3X (X <= 0xB)
                        //DMI2           05     02       2   0x2X (X <= 0xB)
                        //DMI3           05     02       2   0x3X (X <= 0xB)
                        //DMI4           03     02       0   0x2X (X <= 0xB)
                        //DMI5           03     02       0   0x3X (X <= 0xB)
                        //DMI6           03     02       2   0x2X (X <= 0xB)
                        //DMI7           03     02       2   0x3X (X <= 0xB)
                        l_scom.set_chiplet_id(N3_CHIPLET_ID - (2 * (i_chipUnitNum / 4)));
                        l_scom.set_sat_id(2 * ((i_chipUnitNum / 2) % 2));
                        uint8_t l_sat_offset = l_scom.get_sat_offset();
                        l_sat_offset = (l_sat_offset & 0xF) + ((2 + (i_chipUnitNum % 2)) << 4);
                        l_scom.set_sat_offset(l_sat_offset);
                    }

                    if (((l_chiplet_id == MC01_CHIPLET_ID) || (l_chiplet_id == MC23_CHIPLET_ID)))
                    {
                        //-------------------------------------------
                        // DMI
                        //-------------------------------------------
                        //SCOM1,2
                        //DMI0           07     02       0
                        //DMI1           07     02       1
                        //DMI2           07     02       2
                        //DMI3           07     02       3
                        //DMI4           08     02       0
                        //DMI5           08     02       1
                        //DMI6           08     02       2
                        //DMI7           08     02       3
                        if (l_ring == P9C_MC_CHAN_RING_ID)
                        {
                            l_scom.set_chiplet_id(MC01_CHIPLET_ID + (i_chipUnitNum / 4));
                            uint8_t l_msat = l_scom.get_sat_id();
                            l_msat = l_msat & 0xC;
                            l_scom.set_sat_id(l_msat + i_chipUnitNum % 4);
                        }

                        //SCOM4
                        //DMI0           07     08     0xD   0x0X
                        //DMI1           07     08     0xD   0x1X
                        //DMI2           07     08     0xD   0x2X
                        //DMI3           07     08     0xD   0x3X
                        //DMI4           08     08     0xD   0x0X
                        //DMI5           08     08     0xD   0x1X
                        //DMI6           08     08     0xD   0x2X
                        //DMI7           08     08     0xD   0x3X
                        if (l_ring == P9C_MC_BIST_RING_ID)
                        {
                            l_scom.set_chiplet_id(MC01_CHIPLET_ID + (i_chipUnitNum / 4));
                            uint8_t l_sat_offset = l_scom.get_sat_offset();
                            l_sat_offset = (l_sat_offset & 0xF) + ((i_chipUnitNum % 2) << 4);
                            l_scom.set_sat_offset(l_sat_offset);
                        }

                        //-------------------------------------------
                        // DMI IO
                        //-------------------------------------------
                        //          Chiplet   Ring   Satid    Off    RXTXGrp
                        //DMI0           07     04       0   0x3F       0x00
                        //DMI1           07     04       0   0x3F       0x01
                        //DMI2           07     04       0   0x3F       0x02
                        //DMI3           07     04       0   0x3F       0x03
                        //DMI4           08     04       0   0x3F       0x00
                        //DMI5           08     04       0   0x3F       0x01
                        //DMI6           08     04       0   0x3F       0x02
                        //DMI7           08     04       0   0x3F       0x03

                        //DMI0           07     04       0   0x3F       0x20
                        //DMI1           07     04       0   0x3F       0x21
                        //DMI2           07     04       0   0x3F       0x22
                        //DMI3           07     04       0   0x3F       0x23
                        //DMI4           08     04       0   0x3F       0x20
                        //DMI5           08     04       0   0x3F       0x21
                        //DMI6           08     04       0   0x3F       0x22
                        //DMI7           08     04       0   0x3F       0x23
                        if (l_ring == P9C_MC_IO_RING_ID)
                        {
                            l_scom.set_chiplet_id(MC01_CHIPLET_ID + (i_chipUnitNum / 4));
                            uint8_t l_rxtx_grp = l_scom.get_rxtx_group_id();
                            l_scom.set_rxtx_group_id((l_rxtx_grp & 0xF0) + (i_chipUnitNum % 4));
                        }

                    }

                    break;

                case PU_NV_CHIPUNIT:
                    if (i_mode == P9N_DD1_SI_MODE)
                    {
                        l_scom.set_sat_id((l_scom.get_sat_id() % 4) + ((i_chipUnitNum / 2) * 4));
                        l_scom.set_sat_offset( (l_scom.get_sat_offset() % 32) +
                                               (32 * (i_chipUnitNum % 2)));
                    }
                    else
                    {
                        uint64_t l_sa = i_scomAddr;

                        //                       rrrrrrSTIDxxx---
                        //                       000100       yyy
                        //       x"4900" & "00" when "00100010", -- stk0, ntl0, 00-07, hyp-only
                        //       x"0b00" & "11" when "00101001", -- stk0, ntl1, 24-31, user-acc
                        //                             STID
                        //       x"5900" & "00" when "01100010", -- stk1, ntl0, 00-07, hyp-only
                        //       x"1b00" & "11" when "01101001", -- stk1, ntl1, 24-31, user-acc
                        //                             STID
                        //       x"6900" & "00" when "10100010", -- stk2, ntl0, 00-07, hyp-only
                        //       x"2b00" & "11" when "10101001", -- stk2, ntl1, 24-31, user-acc

                        if ((i_chipUnitNum / 2) == 0)
                        {
                            l_sa = (l_sa & 0xFFFFFFFFFFFF007FULL) | 0x0000000000001100ULL ;
                        }

                        if ((i_chipUnitNum / 2) == 1)
                        {
                            l_sa = (l_sa & 0xFFFFFFFFFFFF007FULL) | 0x0000000000001300ULL ;
                        }

                        if ((i_chipUnitNum / 2) == 2)
                        {
                            l_sa = (l_sa & 0xFFFFFFFFFFFF007FULL) | 0x0000000000001500ULL ;
                        }

                        uint64_t l_eo = (l_sa & 0x71) >> 3;

                        if (l_eo > 5 && (i_chipUnitNum % 2 == 0))
                        {
                            l_sa -= 0x20ULL; // 0b100 000
                        }

                        if (l_eo <= 5 && (i_chipUnitNum % 2 == 1))
                        {
                            l_sa += 0x20ULL; // 0b100 000
                        }

                        l_scom.set_addr(l_sa);
                    }

                    break;

                case PU_PEC_CHIPUNIT:
                    if (l_scom.get_chiplet_id() == N2_CHIPLET_ID)
                    {
                        // nest
                        l_scom.set_ring( (N2_PCIS0_0_RING_ID + i_chipUnitNum) & 0xF);
                    }
                    else
                    {
                        // iopci / pci
                        l_scom.set_chiplet_id(PCI0_CHIPLET_ID + i_chipUnitNum);
                    }

                    break;

                case PU_PHB_CHIPUNIT:
                    if (l_scom.get_chiplet_id() == N2_CHIPLET_ID)
                    {
                        // nest
                        if (i_chipUnitNum == 0)
                        {
                            l_scom.set_ring(N2_PCIS0_0_RING_ID & 0xF);
                            l_scom.set_sat_id(((l_scom.get_sat_id() < 4) ? (1) : (4)));
                        }
                        else
                        {
                            l_scom.set_ring( (N2_PCIS0_0_RING_ID + (i_chipUnitNum / 3) + 1) & 0xF);
                            l_scom.set_sat_id( ((l_scom.get_sat_id() < 4) ? (1) : (4)) +
                                               ((i_chipUnitNum % 2) ? (0) : (1)) +
                                               (2 * (i_chipUnitNum / 5)));
                        }
                    }
                    else
                    {
                        // pci
                        if (i_chipUnitNum == 0)
                        {
                            l_scom.set_chiplet_id(PCI0_CHIPLET_ID);
                            l_scom.set_sat_id(((l_scom.get_sat_id() < 4) ? (1) : (4)));
                        }
                        else
                        {
                            l_scom.set_chiplet_id(PCI0_CHIPLET_ID + (i_chipUnitNum / 3) + 1);
                            l_scom.set_sat_id(((l_scom.get_sat_id() < 4) ? (1) : (4)) +
                                              ((i_chipUnitNum % 2) ? (0) : (1)) +
                                              (2 * (i_chipUnitNum / 5)));
                        }
                    }

                    break;

                case PU_OBUS_CHIPUNIT:
                    l_scom.set_chiplet_id(OB0_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_XBUS_CHIPUNIT:

                    l_ring &= 0xF;

                    if (XB_IOX_2_RING_ID >= l_ring &&
                        l_ring >= XB_IOX_0_RING_ID)
                    {
                        l_scom.set_ring( (XB_IOX_0_RING_ID + i_chipUnitNum) & 0xF);
                    }

                    else if (XB_PBIOX_2_RING_ID >= l_ring &&
                             l_ring >= XB_PBIOX_0_RING_ID)
                    {
                        l_scom.set_ring( (XB_PBIOX_0_RING_ID + i_chipUnitNum) & 0xF);
                    }

                    break;

                case PU_SBE_CHIPUNIT:
                    l_scom.set_chiplet_id(i_chipUnitNum);
                    break;

                case PU_PPE_CHIPUNIT:

                    // PPE SBE
                    if (i_chipUnitNum == PPE_SBE_CHIPUNIT_NUM)
                    {
                        l_scom.set_chiplet_id(PIB_CHIPLET_ID);
                        l_scom.set_port(SBE_PORT_ID);
                        l_scom.set_ring(PPE_SBE_RING_ID);
                        l_scom.set_sat_id(PPE_SBE_SAT_ID);
                        l_scom.set_sat_offset(0x0F & l_scom.get_sat_offset());
                        break;
                    }

                    // Need to set SAT offset if address is that of PPE SBE
                    if (l_scom.get_port() == SBE_PORT_ID)
                    {
                        // Adjust offset if input address is of SBE
                        // (ex: 000E0005 --> GPE: xxxxxx1x)
                        l_scom.set_sat_offset(l_scom.get_sat_offset() | 0x10);
                    }

                    // PPE GPE
                    if ( (i_chipUnitNum >= PPE_GPE0_CHIPUNIT_NUM) && (i_chipUnitNum <= PPE_GPE3_CHIPUNIT_NUM) )
                    {
                        l_scom.set_chiplet_id(PIB_CHIPLET_ID);
                        l_scom.set_port(GPE_PORT_ID);
                        l_scom.set_ring( (i_chipUnitNum - PPE_GPE0_CHIPUNIT_NUM) * 8 );
                        l_scom.set_sat_id(PPE_GPE_SAT_ID);
                    }

                    // PPE CME
                    else if ( (i_chipUnitNum >= PPE_EQ0_CME0_CHIPUNIT_NUM) && (i_chipUnitNum <= PPE_EQ5_CME1_CHIPUNIT_NUM) )
                    {
                        if (i_chipUnitNum >= PPE_EQ0_CME1_CHIPUNIT_NUM)
                        {
                            l_scom.set_chiplet_id(EP00_CHIPLET_ID +
                                                  (i_chipUnitNum % PPE_EQ0_CME1_CHIPUNIT_NUM));
                        }
                        else
                        {
                            l_scom.set_chiplet_id(EP00_CHIPLET_ID +
                                                  (i_chipUnitNum % PPE_EQ0_CME0_CHIPUNIT_NUM));
                        }

                        l_scom.set_port(UNIT_PORT_ID);
                        l_scom.set_ring( ((i_chipUnitNum / PPE_EQ0_CME1_CHIPUNIT_NUM) + 8) & 0xF );
                        l_scom.set_sat_id(PPE_CME_SAT_ID);
                    }

                    // PPE IO (XBUS/OBUS/DMI)
                    else if ( (i_chipUnitNum >= PPE_IO_XBUS_CHIPUNIT_NUM) && (i_chipUnitNum <= PPE_IO1_DMI_CHIPUNIT_NUM) )
                    {
                        l_scom.set_chiplet_id( XB_CHIPLET_ID +
                                               (i_chipUnitNum % PPE_IO_XBUS_CHIPUNIT_NUM) +
                                               ((i_chipUnitNum / PPE_IO_OB0_CHIPUNIT_NUM) * 2) );
                        l_scom.set_port(UNIT_PORT_ID);

                        if (i_chipUnitNum == PPE_IO_XBUS_CHIPUNIT_NUM)
                        {
                            l_scom.set_ring(XB_IOPPE_0_RING_ID & 0xF);
                        }
                        else
                        {
                            l_scom.set_ring(OB_PPE_RING_ID & 0xF);
                        }

                        l_scom.set_sat_id(OB_PPE_SAT_ID); // Same SAT_ID value for XBUS
                    }

                    // PPE PB
                    else if ( (i_chipUnitNum >= PPE_PB0_CHIPUNIT_NUM) && (i_chipUnitNum <= PPE_PB2_CHIPUNIT_NUM) )
                    {
                        l_scom.set_chiplet_id(N3_CHIPLET_ID); // TODO: Need to set ChipID for PB1 and PB2 in Cummulus
                        l_scom.set_port(UNIT_PORT_ID);
                        l_scom.set_ring(N3_PB_3_RING_ID & 0xF);
                        l_scom.set_sat_id(PPE_PB_SAT_ID);
                    }

                    // Invalid i_chipUnitNum
                    else
                    {
                        l_scom.set_addr(FAILED_TRANSLATION);
                    }

                    break;

                default:
                    l_scom.set_addr(FAILED_TRANSLATION);
                    break;
            }
        }

        return l_scom.get_addr();
    }


    uint32_t p9_scominfo_isChipUnitScom(const uint64_t i_scomAddr, bool& o_chipUnitRelated,
                                        std::vector<p9_chipUnitPairing_t>& o_chipUnitPairing, const uint32_t i_mode)
    {
        p9_scom_addr l_scom(i_scomAddr);
        o_chipUnitRelated = false;

        uint8_t l_chiplet_id = l_scom.get_chiplet_id();
        uint8_t l_port = l_scom.get_port();
        uint8_t l_ring = l_scom.get_ring();
        uint8_t l_sat_id = l_scom.get_sat_id();
        uint8_t l_sat_offset = l_scom.get_sat_offset();

        if ((i_mode & PPE_MODE) == PPE_MODE)
        {
            if (PPE_EP00_CHIPLET_ID <= l_chiplet_id &&
                l_chiplet_id <= PPE_EP05_CHIPLET_ID)
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EX_CHIPUNIT,
                                            ((l_chiplet_id - PPE_EP00_CHIPLET_ID) * 2) +
                                            (l_port - 1)));

            }

        }

        else if (l_scom.is_unicast())
        {
            // common 'pervasive' registers associated with each pervasive chiplet type
            // permit addressing by PERV target type (for all pervasive chiplet instances)
            // or by C/EX/EQ target types (by their associated pervasive chiplet instances)
            if (((l_port == GPREG_PORT_ID) ||
                 ((l_port >= CME_PORT_ID) && (l_port <= CPM_PORT_ID)) ||
                 (l_port == PCBSLV_PORT_ID) ||
                 (l_port == UNIT_PORT_ID && l_ring == EC_PSCM_RING_ID) || //Catches all PSCOM regs
                 (l_port == UNIT_PORT_ID && l_ring == EC_PERV_RING_ID
                  && l_sat_id == PERV_DBG_SAT_ID))) // Each chiplet also has a DBG macro
            {
                o_chipUnitRelated = true;
                // PU_PERV_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PERV_CHIPUNIT,
                                            l_chiplet_id));

                // PU_C_CHIPUNIT / PU_EX_CHIPUNIT
                if ((l_chiplet_id >= EC00_CHIPLET_ID) && (l_chiplet_id <= EC23_CHIPLET_ID))
                {
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_C_CHIPUNIT,
                                                l_chiplet_id - EC00_CHIPLET_ID));
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EX_CHIPUNIT,
                                                (l_chiplet_id - EC00_CHIPLET_ID) / 2));
                }

                // PU_EQ_CHIPUNIT
                if ((l_chiplet_id >= EP00_CHIPLET_ID) && (l_chiplet_id <= EP05_CHIPLET_ID))
                {
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EQ_CHIPUNIT,
                                                l_chiplet_id - EP00_CHIPLET_ID));
                }
            }

            // core registers which can be addressed by either C/EX target types
            // c: 0..24
            if (((l_chiplet_id >= EC00_CHIPLET_ID) && (l_chiplet_id <= EC23_CHIPLET_ID)) &&
                (l_port == UNIT_PORT_ID) &&
                ((l_ring >= EC_PERV_RING_ID) && (l_ring <= EC_PC_3_RING_ID)))
            {
                o_chipUnitRelated = true;
                // PU_C_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_C_CHIPUNIT,
                                            l_chiplet_id - EC00_CHIPLET_ID));
                // PU_EX_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EX_CHIPUNIT,
                                            (l_chiplet_id - EC00_CHIPLET_ID) / 2));
            }

            // quad registers which can be addressed by either EQ/EX target types
            // ex: 0..12
            // eq: 0..6
            if (((l_chiplet_id >= EP00_CHIPLET_ID) && (l_chiplet_id <= EP05_CHIPLET_ID)) &&
                (l_port == UNIT_PORT_ID) &&
                (((l_ring >= EQ_PERV_RING_ID)  && (l_ring <= EQ_L3_1_RING_ID)) ||
                 ((l_ring >= EQ_CME_0_RING_ID) && (l_ring <= EQ_L2_1_TRA_RING_ID))))
            {
                o_chipUnitRelated = true;
                // PU_EQ_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EQ_CHIPUNIT,
                                            l_chiplet_id - EP00_CHIPLET_ID));

                // PU_EX_CHIPUNIT
                if ((l_ring == EQ_L2_0_RING_ID)  || (l_ring == EQ_NC_0_RING_ID) || (l_ring == EQ_L3_0_RING_ID) ||
                    (l_ring == EQ_CME_0_RING_ID) || (l_ring == EQ_L2_0_TRA_RING_ID))
                {
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EX_CHIPUNIT,
                                                (l_chiplet_id - EP00_CHIPLET_ID) * 2));
                }
                // PU_EX_CHIPUNIT
                else if ((l_ring == EQ_L2_1_RING_ID)  || (l_ring == EQ_NC_1_RING_ID) || (l_ring == EQ_L3_1_RING_ID) ||
                         (l_ring == EQ_CME_1_RING_ID) || (l_ring == EQ_L2_1_TRA_RING_ID))
                {
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_EX_CHIPUNIT,
                                                ((l_chiplet_id - EP00_CHIPLET_ID) * 2) + 1));
                }
            }

            // PU_CAPP_CHIPUNIT
            // capp: 0..1
            if ((((l_chiplet_id == N0_CHIPLET_ID) && (l_ring == N0_CXA0_0_RING_ID)) ||
                 ((l_chiplet_id == N2_CHIPLET_ID) && (l_ring == N2_CXA1_0_RING_ID))) &&
                (l_port == UNIT_PORT_ID))
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_CAPP_CHIPUNIT,
                                            (l_chiplet_id / 2) - 1));
            }

            //==== NIMBUS ====
            if (i_mode == P9N_DD1_SI_MODE || i_mode == P9N_DD2_SI_MODE)
            {
                // PU_MCS_CHIPUNIT (nest)
                // mcs: 0..3
                if (((l_chiplet_id == N3_CHIPLET_ID) || (l_chiplet_id == N1_CHIPLET_ID)) &&
                    (l_port == UNIT_PORT_ID) &&
                    (l_ring == N3_MC01_0_RING_ID) &&
                    ((l_sat_id == MC_DIR_SAT_ID_PBI_01) || (l_sat_id == MC_DIR_SAT_ID_PBI_23)) &&
                    (((0x2F & l_sat_offset) < MC_MCS_MCA_OFFSET_MCP0XLT0 || MC_MCS_MCA_OFFSET_MCPERF3 < (0x2F & l_sat_offset))))
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MCS_CHIPUNIT,
                                                ((l_chiplet_id == N3_CHIPLET_ID) ? (0) : (2)) +
                                                (l_sat_id / 2)));
                }

                // PU_MCBIST_CHIPUNIT (mc)
                // mcbist: 0..1
                if (((l_chiplet_id == MC01_CHIPLET_ID) || (l_chiplet_id == MC23_CHIPLET_ID)) &&
                    (((l_port == UNIT_PORT_ID) &&
                      (((l_ring == MC_MC01_1_RING_ID) &&
                        ((l_sat_id & 0xC) == MC_DIR_SAT_ID_MCBIST)) || //MCBIST has 2 bit sat_id
                       ((l_ring == MC_PERV_RING_ID) || //Translate MC perv regs with MCBIST
                        (l_ring == XB_PSCM_RING_ID) ||
                        (l_ring == MC_MCTRA_0_RING_ID)) )) || //Translate TRA regs with MCBIST
                     (l_port != UNIT_PORT_ID)) )   //Translate MC perv regs with MCBIST
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MCBIST_CHIPUNIT,
                                                l_chiplet_id - MC01_CHIPLET_ID));
                }

                // PU_MCA_CHIPUNIT (mc)
                // mca: 0..7
                // These regisers are in the mcs chiplet but are logically mca targetted
                if (((l_chiplet_id == N3_CHIPLET_ID) || (l_chiplet_id == N1_CHIPLET_ID)) &&
                    (l_port == UNIT_PORT_ID) &&
                    (l_ring == N3_MC01_0_RING_ID) &&
                    ((l_sat_id == MC_DIR_SAT_ID_PBI_01) || (l_sat_id == MC_DIR_SAT_ID_PBI_23)) &&
                    (((0x2F & l_sat_offset) >= MC_MCS_MCA_OFFSET_MCP0XLT0 && MC_MCS_MCA_OFFSET_MCPERF3 >= (0x2F & l_sat_offset))))
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MCA_CHIPUNIT,
                                                ((((l_chiplet_id == N3_CHIPLET_ID) ? (0) : (2)) +
                                                  (l_sat_id / 2)) * 2) +
                                                ((l_sat_offset & 0x10) >> 4) ));
                }

                // PU_MCA_CHIPUNIT (mc)
                // mca: 0..7
                if (((l_chiplet_id == MC01_CHIPLET_ID) || (l_chiplet_id == MC23_CHIPLET_ID)) &&
                    (l_port == UNIT_PORT_ID) &&
                    (l_ring == MC_MC01_0_RING_ID) &&
                    ((l_sat_id >= MC_DIR_SAT_ID_SRQ_0) && (l_sat_id <= MC_DIR_SAT_ID_ECC64_3)))
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MCA_CHIPUNIT,
                                                (4 * (l_chiplet_id - MC01_CHIPLET_ID)) +
                                                (l_sat_id % 4)));
                }

                // PU_MCA_CHIPUNIT (iomc)
                // mca: 0..7
                if (((l_chiplet_id == MC01_CHIPLET_ID) || (l_chiplet_id == MC23_CHIPLET_ID)) &&
                    (l_port == UNIT_PORT_ID) &&
                    ((l_ring >= MC_IOM01_0_RING_ID) && (l_ring <= MC_IOM23_1_RING_ID)) &&
                    (l_sat_id == MC_IND_SAT_ID))
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MCA_CHIPUNIT,
                                                (4 * (l_chiplet_id - MC01_CHIPLET_ID)) +
                                                (l_ring - MC_IOM01_0_RING_ID)));
                }
            }
            else
            {
                //==== CUMULUS =====
                // Figtree references: mc_top_baseaddr.fig, e9_uchip_offset.fig
                //-------------------------------------------
                // MC
                //-------------------------------------------
                // MC            07     08     0xC(!0xD)
                // MC            08     08     0xC(!0xD)
                //Probably any other chipelt 07/08 registers that don't fall into the DMI target range
                if (((l_chiplet_id == MC01_CHIPLET_ID) || (l_chiplet_id == MC23_CHIPLET_ID)) &&
                    ( ( (l_port == UNIT_PORT_ID) &&
                        (
                            ( (l_ring == P9C_MC_BIST_RING_ID) &&
                              (l_sat_id != P9C_SAT_ID_CHAN_MCBIST)
                            ) ||
                            ( (l_ring == MC_PERV_RING_ID) || //Translate MC perv regs with MC
                              (l_ring == XB_PSCM_RING_ID) ||
                              (l_ring == MC_MCTRA_0_RING_ID)
                            ) ||
                            ( (l_ring == P9C_MC_IO_RING_ID) &&
                              (l_sat_id == MC_IND_SAT_ID) &&
                              (l_sat_offset != P9C_MC_OFFSET_IND)
                            )
                        )
                      ) || //Translate TRA regs with MCBIST
                      (l_port != UNIT_PORT_ID)
                    ) )   //Translate MC perv regs with MCBIST
                {

                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MC_CHIPUNIT,
                                                l_chiplet_id - MC01_CHIPLET_ID));

                }

                if (((l_chiplet_id == N3_CHIPLET_ID) || (l_chiplet_id == N1_CHIPLET_ID)) &&
                    (l_port == UNIT_PORT_ID) &&
                    (l_ring == N3_MC01_0_RING_ID) &&
                    (l_sat_id == P9C_N3_MCS01_SAT_ID || l_sat_id == P9C_N3_MCS23_SAT_ID))
                {
                    //-------------------------------------------
                    // DMI
                    //-------------------------------------------
                    //SCOM3   (See mc_clscom_rlm.fig <= 0xB vs mc_scomfir_rlm.fig > 0xB)
                    //DMI0           05     02       0   0x2X (X <= 0xB)
                    //DMI1           05     02       0   0x3X (X <= 0xB)
                    //DMI2           05     02       2   0x2X (X <= 0xB)
                    //DMI3           05     02       2   0x3X (X <= 0xB)
                    //DMI4           03     02       0   0x2X (X <= 0xB)
                    //DMI5           03     02       0   0x3X (X <= 0xB)
                    //DMI6           03     02       2   0x2X (X <= 0xB)
                    //DMI7           03     02       2   0x3X (X <= 0xB)
                    if ((0x20 <= l_sat_offset && l_sat_offset <= 0x2B) ||
                        (0x30 <= l_sat_offset && l_sat_offset <= 0x3B))
                    {
                        uint8_t l_off_nib0 = (l_sat_offset >> 4);
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_DMI_CHIPUNIT,
                                                    ((l_chiplet_id == N3_CHIPLET_ID) ? (0) : (4)) +
                                                    (l_off_nib0 - 2) + l_sat_id));

                    }
                    //-------------------------------------------
                    // MI
                    //-------------------------------------------
                    //          Chiplet   Ring   Satid   Off
                    //MCS0           05     02       0   !SCOM3
                    //MCS1           05     02       2   !SCOM3
                    //MCS2           03     02       0   !SCOM3
                    //MCS3           03     02       2   !SCOM3
                    else
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_MI_CHIPUNIT,
                                                    (l_sat_id / 2) +
                                                    ((l_chiplet_id == N3_CHIPLET_ID) ? (0) : (2))));
                    }

                }

                if (((l_chiplet_id == MC01_CHIPLET_ID) || (l_chiplet_id == MC23_CHIPLET_ID)) &&
                    (l_port == UNIT_PORT_ID))
                {
                    //-------------------------------------------
                    // DMI
                    //-------------------------------------------
                    //SCOM1,2
                    //DMI0           07     02       0
                    //DMI1           07     02       1
                    //DMI2           07     02       2
                    //DMI3           07     02       3
                    //DMI4           08     02       0
                    //DMI5           08     02       1
                    //DMI6           08     02       2
                    //DMI7           08     02       3
                    if (l_ring == P9C_MC_CHAN_RING_ID)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_DMI_CHIPUNIT,
                                                    ((l_chiplet_id == MC01_CHIPLET_ID ? (0) : (4))) +
                                                    (0x3 & l_sat_id)));

                    }

                    //SCOM4
                    //DMI0           07     08     0xD   0x0X
                    //DMI1           07     08     0xD   0x1X
                    //DMI2           07     08     0xD   0x2X
                    //DMI3           07     08     0xD   0x3X
                    //DMI4           08     08     0xD   0x0X
                    //DMI5           08     08     0xD   0x1X
                    //DMI6           08     08     0xD   0x2X
                    //DMI7           08     08     0xD   0x3X
                    if (l_ring == P9C_MC_BIST_RING_ID && l_sat_id == P9C_SAT_ID_CHAN_MCBIST)
                    {
                        uint8_t l_off_nib0 = (l_sat_offset >> 4);
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_DMI_CHIPUNIT,
                                                    ((l_chiplet_id == MC01_CHIPLET_ID ? (0) : (4))) +
                                                    l_off_nib0));

                    }

                    //-------------------------------------------
                    // DMI IO
                    //-------------------------------------------
                    //          Chiplet   Ring   Satid    Off    RXTXGrp
                    //DMI0           07     04       0   0x3F       0x00
                    //DMI1           07     04       0   0x3F       0x01
                    //DMI2           07     04       0   0x3F       0x02
                    //DMI3           07     04       0   0x3F       0x03
                    //DMI4           08     04       0   0x3F       0x00
                    //DMI5           08     04       0   0x3F       0x01
                    //DMI6           08     04       0   0x3F       0x02
                    //DMI7           08     04       0   0x3F       0x03

                    //DMI0           07     04       0   0x3F       0x20
                    //DMI1           07     04       0   0x3F       0x21
                    //DMI2           07     04       0   0x3F       0x22
                    //DMI3           07     04       0   0x3F       0x23
                    //DMI4           08     04       0   0x3F       0x20
                    //DMI5           08     04       0   0x3F       0x21
                    //DMI6           08     04       0   0x3F       0x22
                    //DMI7           08     04       0   0x3F       0x23
                    if (l_ring == P9C_MC_IO_RING_ID && l_sat_id == MC_IND_SAT_ID &&
                        l_sat_offset == P9C_MC_OFFSET_IND )
                    {
                        uint32_t l_rxtx_grp = l_scom.get_rxtx_group_id();

                        if (l_rxtx_grp >= 0x20)
                        {
                            l_rxtx_grp -= 0x20;
                        }

                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_DMI_CHIPUNIT,
                                                    ((l_chiplet_id == MC01_CHIPLET_ID ? (0) : (4))) +
                                                    l_rxtx_grp));

                    }

                }

            }

            // PU_NV_CHIPUNIT
            if (i_mode == P9N_DD1_SI_MODE)
            {
                // See npu_misc_regs.vhdl, line 2710,
                // sc_addr(0 to 6) represents sat_id(0..3) and sat_offset(0..2)
                // only stkX, ntlX registers are translated to NX target type
                // nv: 0..5
                if ((l_chiplet_id == N3_CHIPLET_ID) &&
                    (l_port == UNIT_PORT_ID) &&
                    (((l_ring == N3_NPU_0_RING_ID) && ((l_sat_id % 4) == 3) && l_sat_id <= 11)))
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT,
                                                (2 * (l_sat_id / 4)) +
                                                (l_sat_offset / 32)));
                }
            }
            else
            {
                //DD2 NV link (and Cumulus until we know better)
                // See npu_misc_regs.vhdl
                // sc_addr(0 to 7)  bits 1 to 4 are the sat_id bit 0 is the lsb of the ring
                //  rings 4 and 5 are used.
                //                       rrrrrrSTIDxxx---
                //                       000100
                //       x"4900" & "00" when "00100010", -- stk0, ntl0, 00-07, hyp-only
                //       x"4900" & "01" when "00100011", -- stk0, ntl0, 08-15, hyp-only
                //       x"4900" & "10" when "00100100", -- stk0, ntl0, 16-23, hyp-only
                //       x"0900" & "11" when "00100101", -- stk0, ntl0, 24-31, user-acc
                //       x"4b00" & "00" when "00100110", -- stk0, ntl1, 00-07, hyp-only
                //       x"4b00" & "01" when "00100111", -- stk0, ntl1, 08-15, hyp-only
                //       x"4b00" & "10" when "00101000", -- stk0, ntl1, 16-23, hyp-only --          addresses 0x140-147
                //       x"0b00" & "11" when "00101001", -- stk0, ntl1, 24-31, user-acc
                //                             STID
                //       x"5900" & "00" when "01100010", -- stk1, ntl0, 00-07, hyp-only
                //       x"5900" & "01" when "01100011", -- stk1, ntl0, 08-15, hyp-only
                //       x"5900" & "10" when "01100100", -- stk1, ntl0, 16-23, hyp-only
                //       x"1900" & "11" when "01100101", -- stk1, ntl0, 24-31, user-acc
                //       x"5b00" & "00" when "01100110", -- stk1, ntl1, 00-07, hyp-only
                //       x"5b00" & "01" when "01100111", -- stk1, ntl1, 08-15, hyp-only
                //       x"5b00" & "10" when "01101000", -- stk1, ntl1, 16-23, hyp-only --          addresses 0x340-347
                //       x"1b00" & "11" when "01101001", -- stk1, ntl1, 24-31, user-acc
                //                             STID
                //       x"6900" & "00" when "10100010", -- stk2, ntl0, 00-07, hyp-only
                //       x"6900" & "01" when "10100011", -- stk2, ntl0, 08-15, hyp-only
                //       x"6900" & "10" when "10100100", -- stk2, ntl0, 16-23, hyp-only
                //       x"2900" & "11" when "10100101", -- stk2, ntl0, 24-31, user-acc
                //       x"6b00" & "00" when "10100110", -- stk2, ntl1, 00-07, hyp-only
                //       x"6b00" & "01" when "10100111", -- stk2, ntl1, 08-15, hyp-only
                //       x"6b00" & "10" when "10101000", -- stk2, ntl1, 16-23, hyp-only --          addresses 0x540-54f
                //       x"2b00" & "11" when "10101001", -- stk2, ntl1, 24-31, user-acc
                if ((l_chiplet_id == N3_CHIPLET_ID) &&
                    (l_port == UNIT_PORT_ID))
                {

                    //We have to do ugly bit manipulation here anyway.  It is clearer
                    //just to do it with the raw scom address.
                    //Combine the ring(6) sat_id(4) and high order 3 bits of sat_offset
                    //to compare with vhdl values for NV registers
                    uint64_t npuaddr = (i_scomAddr & 0xFFF8ULL) >> 3;

                    if (0x0222ULL <= npuaddr && npuaddr <= 0x0225ULL)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT, 0));
                    }

                    if (0x0226ULL <= npuaddr && npuaddr <= 0x0229ULL)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT, 1));
                    }

                    if (0x0262ULL <= npuaddr && npuaddr <= 0x0265ULL)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT, 2));
                    }

                    if (0x0266ULL <= npuaddr && npuaddr <= 0x0269ULL)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT, 3));
                    }

                    if (0x02A2ULL <= npuaddr && npuaddr <= 0x02A5ULL)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT, 4));
                    }

                    if (0x02A6ULL <= npuaddr && npuaddr <= 0x02A9ULL)
                    {
                        o_chipUnitRelated = true;
                        o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_NV_CHIPUNIT, 5));
                    }
                }

            }

            // PU_PEC_CHIPUNIT (nest)
            // pec: 0..2
            if ((l_chiplet_id == N2_CHIPLET_ID) &&
                (l_port == UNIT_PORT_ID) &&
                ((l_ring >= N2_PCIS0_0_RING_ID) && (l_ring <= N2_PCIS2_0_RING_ID)) &&
                (l_sat_id == PEC_SAT_ID))
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PEC_CHIPUNIT,
                                            (l_ring - N2_PCIS0_0_RING_ID)));
            }

            // PU_PEC_CHIPUNIT (iopci/pci)
            // source: iop_scom_cntl_rlm_mac.vhdl
            // pec: 0..2
            if (((l_chiplet_id >= PCI0_CHIPLET_ID) && (l_chiplet_id <= PCI2_CHIPLET_ID)) &&
                ((l_port != UNIT_PORT_ID) ||
                 ((l_port == UNIT_PORT_ID) &&
                  ((l_ring == PCI_IOPCI_0_RING_ID) || (l_ring == PCI_PE_0_RING_ID) ||
                   (l_ring == PCI_PERV_RING_ID)) &&
                  (l_sat_id == PEC_SAT_ID))))
            {
                if ((l_chiplet_id >= PCI0_CHIPLET_ID) && (l_chiplet_id <= PCI2_CHIPLET_ID))
                {
                    o_chipUnitRelated = true;
                    o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PEC_CHIPUNIT,
                                                (l_chiplet_id - PCI0_CHIPLET_ID)));
                }
            }

            // PU_PHB_CHIPUNIT (nest)
            // phb: 0..5
            if ((l_chiplet_id == N2_CHIPLET_ID) &&
                (l_port == UNIT_PORT_ID) &&
                ((l_ring >= N2_PCIS0_0_RING_ID) && (l_ring <= N2_PCIS2_0_RING_ID)) &&
                (((l_ring - l_sat_id) >= 2) && ((l_ring - l_sat_id) < l_ring)))
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PHB_CHIPUNIT,
                                            ((l_ring - N2_PCIS0_0_RING_ID) ?
                                             (((l_ring - N2_PCIS0_0_RING_ID) * 2) - 1) :
                                             (0)) +
                                            (l_sat_id - 1)));
            }

            // PU_PHB_CHIPUNIT (pci)
            // phb: 0..5
            if (((l_chiplet_id >= PCI0_CHIPLET_ID) && (l_chiplet_id <= PCI2_CHIPLET_ID)) &&
                (l_port == UNIT_PORT_ID) &&
                (l_ring == PCI_PE_0_RING_ID) &&
                (((l_sat_id >= 1) && (l_sat_id <= (l_chiplet_id - PCI0_CHIPLET_ID + 1))) || // aib_stack
                 ((l_sat_id >= 4) && (l_sat_id <= (l_chiplet_id - PCI0_CHIPLET_ID + 4)))))  // pbcq_etu
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PHB_CHIPUNIT,
                                            ((l_chiplet_id - PCI0_CHIPLET_ID) ?
                                             (((l_chiplet_id - PCI0_CHIPLET_ID) * 2) - 1) :
                                             (0)) +
                                            l_sat_id -
                                            ((l_sat_id >= 4) ? (4) : (1))));
            }

            // PU_OBUS_CHIPUNIT
            // obus: 0..3
            if (((l_chiplet_id >= OB0_CHIPLET_ID) && (l_chiplet_id <= OB3_CHIPLET_ID)))
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_OBUS_CHIPUNIT,
                                            (l_chiplet_id - OB0_CHIPLET_ID)));
            }

            // PU_XBUS_CHIPUNIT
            // xbus: 0..2
            if ((l_chiplet_id == XB_CHIPLET_ID) &&
                (l_port == UNIT_PORT_ID) &&
                (((l_ring >= XB_IOX_0_RING_ID) && (l_ring <= XB_IOX_2_RING_ID) && (l_sat_id == XB_IOF_SAT_ID)) ||
                 ((l_ring >= XB_PBIOX_0_RING_ID) && (l_ring <= XB_PBIOX_2_RING_ID) && (l_sat_id == XB_PB_SAT_ID))))
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_XBUS_CHIPUNIT,
                                            l_ring % 3));
            }

            // -----------------------------------------------------------------------------
            // Common 'ppe' registers associated with each pervasive chiplet type
            // Permit addressing by PPE target type (for all ppe chiplet instances)
            // -----------------------------------------------------------------------------

            // SBE PM registers
            //    Port ID = 14
            if ( (l_port == SBE_PORT_ID) &&
                 (l_chiplet_id == PIB_CHIPLET_ID) &&
                 (l_ring == PPE_SBE_RING_ID) &&
                 (l_sat_id == PPE_SBE_SAT_ID) )
            {
                o_chipUnitRelated = true;
                // PU_SBE_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_SBE_CHIPUNIT,
                                            l_chiplet_id));
                // PU_PPE_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PPE_CHIPUNIT,
                                            l_chiplet_id));
            }

            // GPE registers
            //    Port ID = 1
            if ( (l_port == GPE_PORT_ID) &&
                 (l_chiplet_id == PIB_CHIPLET_ID) &&
                 ( (l_ring == PPE_GPE0_RING_ID) ||
                   (l_ring == PPE_GPE1_RING_ID) ||
                   (l_ring == PPE_GPE2_RING_ID) ||
                   (l_ring == PPE_GPE3_RING_ID) ) &&
                 (l_sat_id == PPE_GPE_SAT_ID) )
            {
                o_chipUnitRelated = true;
                // PU_PPE_CHIPUNIT
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(
                                                PU_PPE_CHIPUNIT,
                                                PPE_GPE0_CHIPUNIT_NUM + (l_ring / 8)));
            }

            // CME registers which can be addressed by PPE target type
            //    Port ID = 1
            //    0x10 <= Chiplet ID <= 0x15
            //    Ring_ID = 0x8 or Ring_ID = 0x9
            //    SAT_ID = 0
            if ( (l_port == UNIT_PORT_ID) &&
                 ((l_chiplet_id >= EP00_CHIPLET_ID) && (l_chiplet_id <= EP05_CHIPLET_ID)) &&
                 ( (l_ring == EQ_CME_0_RING_ID) || (l_ring == EQ_CME_1_RING_ID) ) &&
                 (l_sat_id == PPE_CME_SAT_ID) )
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PPE_CHIPUNIT,
                                            (l_chiplet_id - EP00_CHIPLET_ID) +
                                            PPE_EQ0_CME0_CHIPUNIT_NUM +
                                            ((l_ring % 8) * 10)));
            }

            // PB registers which can be addressed by PPE target type
            //    Port ID = 1
            //    Chiplet ID = 0x05
            //    Ring_ID = 0x9
            //    SAT_ID = 0
            if ( (l_port == UNIT_PORT_ID) &&
                 (l_chiplet_id == N3_CHIPLET_ID) &&
                 (l_ring == N3_PB_3_RING_ID) &&
                 (l_sat_id == PPE_PB_SAT_ID) )
            {
                o_chipUnitRelated = true;
                // TODO: Need to update for PB1/PB2 of Cummulus whenever address
                //       values are available.
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PPE_CHIPUNIT,
                                            PPE_PB0_CHIPUNIT_NUM));
            }

            // XBUS registers which can be addressed by PPE target type (IOPPE)
            //    Port ID = 1
            //    Chiplet ID = 0x06
            //    Ring_ID = 0x2
            //    SAT_ID = 1
            if ( (l_port == UNIT_PORT_ID) &&
                 (l_chiplet_id == XB_CHIPLET_ID) &&
                 (l_ring == XB_IOPPE_0_RING_ID) &&
                 (l_sat_id == XB_PPE_SAT_ID) )
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PPE_CHIPUNIT,
                                            PPE_IO_XBUS_CHIPUNIT_NUM));
            }

            // OBUS registers which can be addressed by PPE target type (IOPPE)
            //    Port ID = 1
            //    Chiplet ID = 0x09, 0x0A, 0x0B, or 0x0C
            //    Ring_ID = 0x4
            //    SAT_ID = 1
            if ( (l_port == UNIT_PORT_ID) &&
                 ((l_chiplet_id >= OB0_CHIPLET_ID) && (l_chiplet_id <= OB3_CHIPLET_ID)) &&
                 (l_ring == OB_PPE_RING_ID) &&
                 (l_sat_id == OB_PPE_SAT_ID) )
            {
                o_chipUnitRelated = true;
                o_chipUnitPairing.push_back(p9_chipUnitPairing_t(PU_PPE_CHIPUNIT,
                                            (l_chiplet_id - OB0_CHIPLET_ID) + PPE_IO_OB0_CHIPUNIT_NUM));
            }
        }

        return (!l_scom.is_valid());
    }

    uint32_t p9_scominfo_fixChipUnitScomAddrOrTarget(const p9ChipUnits_t i_p9CU, const uint32_t i_targetChipUnitNum,
            const uint64_t i_scomaddr, uint64_t& o_modifiedScomAddr, p9ChipUnits_t& o_p9CU,
            uint32_t& o_modifiedChipUnitNum, const uint32_t i_mode)
    {
        uint32_t rc = 0;

        o_modifiedScomAddr = i_scomaddr;
        o_p9CU = i_p9CU;
        o_modifiedChipUnitNum = i_targetChipUnitNum;

        return rc;
    }


} // extern "C"

#undef P9_SCOMINFO_C

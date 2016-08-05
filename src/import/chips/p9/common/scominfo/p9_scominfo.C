/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/scominfo/p9_scominfo.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

        //Used to help generate entries for the SCOMdef documentation,
        //These aren't general PIB addresses
        if (i_mode == PPE_MODE)
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

                case PU_NV_CHIPUNIT:
                    l_scom.set_sat_id((l_scom.get_sat_id() % 4) + ((i_chipUnitNum / 2) * 4));
                    l_scom.set_sat_offset( (l_scom.get_sat_offset() % 32) +
                                           (32 * (i_chipUnitNum % 2)));
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

        if (i_mode == PPE_MODE)
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
                 (l_port == UNIT_PORT_ID && l_ring == EC_PSCM_RING_ID))) //Catches all PSCOM regs
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

            // PU_NV_CHIPUNIT
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

} // extern "C"

#undef P9_SCOMINFO_C

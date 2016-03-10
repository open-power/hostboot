/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/scominfo/p9_scominfo.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
                        l_scom.set_ring( ( l_scom.get_ring() - ( l_scom.get_ring() % 2 ) ) +
                                         ( i_chipUnitNum % 2 ) );
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
                    l_scom.set_chiplet_id(MC01_CHIPLET_ID + (i_chipUnitNum / 4));

                    if (l_scom.get_ring() == MC_MC01_0_RING_ID)
                    {
                        // mc
                        l_scom.set_sat_id( ( l_scom.get_sat_id() - ( l_scom.get_sat_id() % 4 ) ) +
                                           ( i_chipUnitNum % 4 ));
                    }
                    else
                    {
                        // iomc
                        l_scom.set_ring(MC_IOM01_0_RING_ID + (i_chipUnitNum % 4));
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
                        l_scom.set_ring(N2_PCIS0_0_RING_ID + i_chipUnitNum);
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
                            l_scom.set_ring(N2_PCIS0_0_RING_ID);
                            l_scom.set_sat_id(((l_scom.get_sat_id() < 4) ? (1) : (4)));
                        }
                        else
                        {
                            l_scom.set_ring(N2_PCIS0_0_RING_ID + (i_chipUnitNum / 3) + 1);
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
                    if (XB_IOX_2_RING_ID >= l_scom.get_ring() &&
                        l_scom.get_ring() >= XB_IOX_0_RING_ID)
                    {
                        l_scom.set_ring(XB_IOX_0_RING_ID + i_chipUnitNum);
                    }

                    if (XB_PBIOX_2_RING_ID >= l_scom.get_ring() &&
                        l_scom.get_ring() >= XB_PBIOX_0_RING_ID)
                    {
                        l_scom.set_ring(XB_PBIOX_0_RING_ID + i_chipUnitNum);
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
                ((l_sat_id == MC_DIR_SAT_ID_PBI_01) || (l_sat_id == MC_DIR_SAT_ID_PBI_23)))
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
        }

        return (!l_scom.is_valid());
    }

} // extern "C"

#undef P9_SCOMINFO_C

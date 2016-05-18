/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/scominfo/p9_scom_addr.H $                     */
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
/// @file p9_cu.H
/// @brief P9 chip unit definitions
///
/// HWP HWP Owner: jmcgill@us.ibm.com
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

#ifndef P9_SCOM_ADDR_H
#define P9_SCOM_ADDR_H

// includes
#include <stdint.h>

extern "C"
{
    /// P9 Chiplet ID enumeration
    typedef enum
    {
        PIB_CHIPLET_ID  = 0x00,     ///< PIB chiplet
        PERV_CHIPLET_ID = 0x01,     ///< TP chiplet
        N0_CHIPLET_ID   = 0x02,     ///< Nest0 (North) chiplet
        N1_CHIPLET_ID   = 0x03,     ///< Nest1 (East) chiplet
        N2_CHIPLET_ID   = 0x04,     ///< Nest2 (South) chiplet
        N3_CHIPLET_ID   = 0x05,     ///< Nest3 (West) chiplet
        XB_CHIPLET_ID   = 0x06,     ///< XBus chiplet
        MC01_CHIPLET_ID = 0x07,     ///< MC01 (West) chiplet
        MC23_CHIPLET_ID = 0x08,     ///< MC23 (East) chiplet
        OB0_CHIPLET_ID  = 0x09,     ///< OBus0 chiplet
        OB1_CHIPLET_ID  = 0x0A,     ///< OBus1 chiplet (Cumulus only)
        OB2_CHIPLET_ID  = 0x0B,     ///< OBus2 chiplet (Cumulus only)
        OB3_CHIPLET_ID  = 0x0C,     ///< OBus3 chiplet
        PCI0_CHIPLET_ID = 0x0D,     ///< PCIe0 chiplet
        PCI1_CHIPLET_ID = 0x0E,     ///< PCIe1 chiplet
        PCI2_CHIPLET_ID = 0x0F,     ///< PCIe2 chiplet
        EP00_CHIPLET_ID = 0x10,     ///< Quad0 chiplet (EX0/1)
        EP01_CHIPLET_ID = 0x11,     ///< Quad1 chiplet (EX2/3)
        EP02_CHIPLET_ID = 0x12,     ///< Quad2 chiplet (EX4/5)
        EP03_CHIPLET_ID = 0x13,     ///< Quad3 chiplet (EX6/7)
        EP04_CHIPLET_ID = 0x14,     ///< Quad4 chiplet (EX8/9)
        EP05_CHIPLET_ID = 0x15,     ///< Quad5 chiplet (EX10/11)
        EC00_CHIPLET_ID = 0x20,     ///< Core0 chiplet (Quad0, EX0, C0)
        EC01_CHIPLET_ID = 0x21,     ///< Core1 chiplet (Quad0, EX0, C1)
        EC02_CHIPLET_ID = 0x22,     ///< Core2 chiplet (Quad0, EX1, C0)
        EC03_CHIPLET_ID = 0x23,     ///< Core3 chiplet (Quad0, EX1, C1)
        EC04_CHIPLET_ID = 0x24,     ///< Core4 chiplet (Quad1, EX2, C0)
        EC05_CHIPLET_ID = 0x25,     ///< Core5 chiplet (Quad1, EX2, C1)
        EC06_CHIPLET_ID = 0x26,     ///< Core6 chiplet (Quad1, EX3, C0)
        EC07_CHIPLET_ID = 0x27,     ///< Core7 chiplet (Quad1, EX3, C1)
        EC08_CHIPLET_ID = 0x28,     ///< Core8 chiplet (Quad2, EX4, C0)
        EC09_CHIPLET_ID = 0x29,     ///< Core9 chiplet (Quad2, EX4, C1)
        EC10_CHIPLET_ID = 0x2A,     ///< Core10 chiplet (Quad2, EX5, C0)
        EC11_CHIPLET_ID = 0x2B,     ///< Core11 chiplet (Quad2, EX5, C1)
        EC12_CHIPLET_ID = 0x2C,     ///< Core12 chiplet (Quad3, EX6, C0)
        EC13_CHIPLET_ID = 0x2D,     ///< Core13 chiplet (Quad3, EX6, C1)
        EC14_CHIPLET_ID = 0x2E,     ///< Core14 chiplet (Quad3, EX7, C0)
        EC15_CHIPLET_ID = 0x2F,     ///< Core15 chiplet (Quad3, EX7, C1)
        EC16_CHIPLET_ID = 0x30,     ///< Core16 chiplet (Quad4, EX8, C0)
        EC17_CHIPLET_ID = 0x31,     ///< Core17 chiplet (Quad4, EX8, C1)
        EC18_CHIPLET_ID = 0x32,     ///< Core18 chiplet (Quad4, EX9, C0)
        EC19_CHIPLET_ID = 0x33,     ///< Core19 chiplet (Quad4, EX9, C1)
        EC20_CHIPLET_ID = 0x34,     ///< Core20 chiplet (Quad5, EX10, C0)
        EC21_CHIPLET_ID = 0x35,     ///< Core21 chiplet (Quad5, EX10, C1)
        EC22_CHIPLET_ID = 0x36,     ///< Core22 chiplet (Quad5, EX11, C0)
        EC23_CHIPLET_ID = 0x37      ///< Core23 chiplet (Quad5, EX11, C1)
    } p9_chiplet_id_t;

    /// P9 Chiplet ID enumeration
    typedef enum
    {
        PPE_EP00_CHIPLET_ID = 0x09,     ///< Quad0
        PPE_EP01_CHIPLET_ID = 0x0A,     ///< Quad1
        PPE_EP02_CHIPLET_ID = 0x0B,     ///< Quad2
        PPE_EP03_CHIPLET_ID = 0x0C,     ///< Quad3
        PPE_EP04_CHIPLET_ID = 0x0D,     ///< Quad4
        PPE_EP05_CHIPLET_ID = 0x0E      ///< Quad5
    } p9_ppe_chiplet_id_t;

    /// P9 SCOM port ID enumeration
    typedef enum
    {
        GPREG_PORT_ID = 0x0,        ///< GP registers
        UNIT_PORT_ID = 0x1,         ///< Functional registers
        CME_PORT_ID = 0x2,          ///< CME registers
        CC_PORT_ID = 0x3,           ///< Clock control registers
        FIR_PORT_ID = 0x4,          ///< Common FIR registers
        CPM_PORT_ID = 0x5,          ///< CPM registers
        PCBSLV_PORT_ID = 0xF        ///< PCB Slave registers
    } p9_port_id_t;

    /// P9 Core chiplet SCOM ring ID enumeration
    /// source: tpc_p9_core_top.vhdl
    typedef enum
    {
        EC_PSCM_RING_ID = 0x0,      ///< PSCOM
        EC_PERV_RING_ID = 0x1,      ///< PERV
        EC_PC_0_RING_ID = 0x2,      ///< PC_0
        EC_PC_1_RING_ID = 0x3,      ///< PC_1
        EC_PC_2_RING_ID = 0x4,      ///< PC_2
        EC_PC_3_RING_ID = 0x5       ///< PC_3
    } p9_ec_ring_id_t;

    /// P9 Quad chiplet SCOM ring ID enumeration
    /// source: tpc_p9_l3_top.vhdl
    typedef enum
    {
        EQ_PSCM_RING_ID = 0x0,      ///< PSCOM
        EQ_PERV_RING_ID = 0x1,      ///< PERV
        EQ_L2_0_RING_ID = 0x2,      ///< L2_0
        EQ_L2_1_RING_ID = 0x3,      ///< L2_1
        EQ_NC_0_RING_ID = 0x4,      ///< NC_0
        EQ_NC_1_RING_ID = 0x5,      ///< NC_1
        EQ_L3_0_RING_ID = 0x6,      ///< L3_0
        EQ_L3_1_RING_ID = 0x7,      ///< L3_1
        EQ_CME_0_RING_ID = 0x8,     ///< CME_0
        EQ_CME_1_RING_ID = 0x9,     ///< CME_1
        EQ_L2_0_TRA_RING_ID = 0xA,  ///< L2_0_TRA
        EQ_L2_1_TRA_RING_ID = 0xB   ///< L2_1_TRA
    } p9_eq_ring_id_t;

    /// P9 N0 chiplet SCOM ring ID enumeration
    /// source: tpc_p9_n0_top.vhdl
    typedef enum
    {
        N0_PSCM_RING_ID = 0x0,      ///< PSCOM
        N0_PERV_RING_ID = 0x1,      ///< PERV
        N0_CXA0_0_RING_ID = 0x2,    ///< CXA0_0
        N0_NX_0_RING_ID = 0x4,      ///< NX_0
        N0_PBIOE0_0_RING_ID = 0x6,  ///< PBIOE0_0
        N0_PBIOE1_0_RING_ID = 0x7,  ///< PBIOE1_0
        N0_PBIOE2_0_RING_ID = 0x8   ///< PBIOE2_0
    } p9_n0_ring_id_t;

    /// P9 N1 chiplet SCOM ring ID enumeration
    /// source: tpc_p9_n1_top.vhdl
    typedef enum
    {
        N1_PSCM_RING_ID = 0x0,      ///< PSCOM
        N1_PERV_RING_ID = 0x1,      ///< PERV
        N1_MC23_0_RING_ID = 0x2,    ///< MC23_0
        N1_MCD_0_RING_ID = 0x4,     ///< MCD_0
        N1_MCD_1_RING_ID = 0x5,     ///< MCD_1
        N1_VA_0_RING_ID = 0x6       ///< VA_0
    } p9_n1_ring_id_t;

    /// P9 N2 chiplet SCOM ring ID enumeration
    /// source: tpc_p9_n2_top.vhdl
    typedef enum
    {
        N2_PSCM_RING_ID = 0x0,      ///< PSCOM
        N2_PERV_RING_ID = 0x1,      ///< PERV
        N2_CXA1_0_RING_ID = 0x2,    ///< CXA1_0
        N2_PCIS0_0_RING_ID = 0x3,   ///< PCIS0_0
        N2_PCIS1_0_RING_ID = 0x4,   ///< PCIS1_0
        N2_PCIS2_0_RING_ID = 0x5,   ///< PCIS2_0
        N2_IOPSI_0_RING_ID = 0x6    ///< IOPSI_0
    } p9_n2_ring_id_t;

    typedef enum
    {
        PEC_SAT_ID = 0x0
    } p9_pec_sat_id_t;

    /// P9 N3 chiplet SCOM ring ID enumeration
    /// source: tpc_p9_n3_top.vhdl
    typedef enum
    {
        N3_PSCM_RING_ID = 0x0,      ///< PSCOM
        N3_PERV_RING_ID = 0x1,      ///< PERV
        N3_MC01_0_RING_ID = 0x2,    ///< MC01_0
        N3_NPU_0_RING_ID = 0x4,     ///< NPU_0
        N3_NPU_1_RING_ID = 0x5,     ///< NPU_1
        N3_PB_0_RING_ID = 0x6,      ///< PB_0
        N3_PB_1_RING_ID = 0x7,      ///< PB_1
        N3_PB_2_RING_ID = 0x8,      ///< PB_2
        N3_PB_3_RING_ID = 0x9,      ///< PB_3
        N3_BR_0_RING_ID = 0xa,      ///< BR_0
        N3_MM_0_RING_ID = 0xb,      ///< MM_0
        N3_INT_0_RING_ID = 0xc,     ///< INT_0
        N3_PB_4_RING_ID = 0xd,      ///< PB_4
        N3_PB_5_RING_ID = 0xe,      ///< PB_5
    } p9_n3_ring_id_t;

    /// P9 XBUS chiplet SCOM ring ID enumeration
    /// source: tpc_p9_xb_top.vhdl
    typedef enum
    {
        XB_PSCM_RING_ID = 0x0,      ///< PSCOM
        XB_PERV_RING_ID = 0x1,      ///< PERV
        XB_IOPPE_0_RING_ID = 0x2,   ///< IOPPE
        XB_IOX_0_RING_ID = 0x3,     ///< IOX_0
        XB_IOX_1_RING_ID = 0x4,     ///< IOX_1
        XB_IOX_2_RING_ID = 0x5,     ///< IOX_2
        XB_PBIOX_0_RING_ID = 0x6,   ///< PBIOX_0
        XB_PBIOX_1_RING_ID = 0x7,   ///< PBIOX_1
        XB_PBIOX_2_RING_ID = 0x8    ///< PBIOX_2
    } p9_xb_ring_id_t;

    typedef enum
    {
        XB_PB_SAT_ID = 0x0
    } p9_xb_pb_sat_id_t;

    typedef enum
    {
        XB_IOF_SAT_ID = 0x0,
        XB_PPE_SAT_ID = 0x1
    } p9_xb_iof_sat_id_t;

    /// P9 MC chiplet SCOM ring ID enumeration
    /// source: tpc_p9_mcslow_top.vhdl
#ifdef MC_E9022
    typedef enum
    {
        MC_PSCM_RING_ID = 0x0,      ///< PSCOM
        MC_PERV_RING_ID = 0x1,      ///< PERV
        MC_MC01_0_RING_ID = 0x2,    ///< MC01_0 / MC23_0
        MC_MCTRA_0_RING_ID = 0x3,   ///< MCTRA01_0 / MCTRA23_0
        MC_IOM0_0_RING_ID = 0x4,    ///< IOM01_0 / IOM45_0
        MC_IOM0_1_RING_ID = 0x5,    ///< IOM01_1 / IOM45_1
        MC_IOM1_0_RING_ID = 0x6,    ///< IOM01_2 / IOM45_2
        MC_IOM1_1_RING_ID = 0x7,    ///< IOM01_3 / IOM45_3
        MC_IOM2_0_RING_ID = 0x8,    ///< IOM23_0 / IOM67_0
        MC_IOM2_1_RING_ID = 0x9,    ///< IOM23_1 / IOM67_1
        MC_IOM3_0_RING_ID = 0xa,    ///< IOM23_2 / IOM67_2
        MC_IOM3_1_RING_ID = 0xb     ///< IOM23_3 / IOM67_3
    } p9_mc_ring_id_t;
#else
    typedef enum
    {
        MC_PSCM_RING_ID = 0x0,      ///< PSCOM
        MC_PERV_RING_ID = 0x1,      ///< PERV
        MC_MC01_0_RING_ID = 0x2,    ///< MC01_0 / MC23_0
        MC_MCTRA_0_RING_ID = 0x3,   ///< MCTRA01_0 / MCTRA23_0
        MC_IOM01_0_RING_ID = 0x4,   ///< IOM01_0 / IOM45_0
        MC_IOM01_1_RING_ID = 0x5,   ///< IOM01_1 / IOM45_1
        MC_IOM23_0_RING_ID = 0x6,   ///< IOM23_0 / IOM67_0
        MC_IOM23_1_RING_ID = 0x7,   ///< IOM23_1 / IOM67_1
        MC_MC01_1_RING_ID = 0x8,    ///< MC01_1 / MC23_1
    } p9_mc_ring_id_t;
#endif

    typedef enum
    {
        MC_DIR_SAT_ID_PBI_01 = 0x0,
        MC_DIR_SAT_ID_PBI_23 = 0x2,
        MC_DIR_SAT_ID_SRQ_0 = 0x4,
        MC_DIR_SAT_ID_SRQ_1 = 0x5,
        MC_DIR_SAT_ID_SRQ_2 = 0x6,
        MC_DIR_SAT_ID_SRQ_3 = 0x7,
        MC_DIR_SAT_ID_ECC64_0 = 0x8,
        MC_DIR_SAT_ID_ECC64_1 = 0x9,
        MC_DIR_SAT_ID_ECC64_2 = 0xa,
        MC_DIR_SAT_ID_ECC64_3 = 0xb,
    } p9_mc_dir0_sat_id_t;

    //These are for registers that reside in the MCS chiplet, but
    //are used for MCA registers and should be targetted with MCA
    //target type.  There is no way to identify them other than by
    //register offset value.  All registers know of this type are
    //listed bellow, but a range is used for checking
    typedef enum
    {
        MC_MCS_MCA_OFFSET_MCP0XLT0  = 0x20,
        MC_MCS_MCA_OFFSET_MCP0XLT1  = 0x21,
        MC_MCS_MCA_OFFSET_MCP0XLT2  = 0x22,
        MC_MCS_MCA_OFFSET_MCPERF0  = 0x23,
        MC_MCS_MCA_OFFSET_MCPERF2  = 0x24,
        MC_MCS_MCA_OFFSET_MCAMOC  = 0x25,
        MC_MCS_MCA_OFFSET_MCEPSQ  = 0x26,
        MC_MCS_MCA_OFFSET_MCBUSYQ  = 0x27,
        MC_MCS_MCA_OFFSET_MCERRINJ  = 0x28,
        MC_MCS_MCA_OFFSET_MCEBUSCL  = 0x29,
        MC_MCS_MCA_OFFSET_MCWAT  = 0x2A,
        MC_MCS_MCA_OFFSET_MCPERF3  = 0x2B
    } p9_mcs_mca_offset_t;

    typedef enum
    {
        MC_DIR_SAT_ID_MCBIST = 0xC
    } p9_mc_dir1_sat_id_t;

    typedef enum
    {
        MC_IND_SAT_ID = 0x0
    } p9_mc_ind_sat_id_t;

    /// P9 OB chiplet SCOM ring ID enumeration
    /// source: tpc_p9_ob_top.vhdl
    typedef enum
    {
        OB_PSCM_RING_ID = 0x0,      ///< PSCOM
        OB_PERV_RING_ID = 0x1,      ///< PERV
        OB_PBIOA_0_RING_ID = 0x2,   ///< PBIOA_0
        OB_IOO_0_RING_ID = 0x3,     ///< IOO_0
        OB_PPE_RING_ID = 0x4        ///< PPE
    } p9_ob_ring_id_t;

    typedef enum
    {
        OB_PB_SAT_ID = 0x0
    } p9_ob_pb_sat_id_t;

    typedef enum
    {
        OB_IOO_SAT_ID = 0x0,
        OB_PPE_SAT_ID = 0x1
    } p9_ob_ioo_sat_id_t;

    /// P9 PCIe chiplet SCOM ring ID enumeration
    /// source: tpc_p9_pci[012]_top.vhdl
    typedef enum
    {
        PCI_PSCM_RING_ID = 0x0,      ///< PSCOM
        PCI_PERV_RING_ID = 0x1,      ///< TRA
        PCI_PE_0_RING_ID = 0x2,      ///< PE_0
        PCI_IOPCI_0_RING_ID = 0x3    ///< IOPCI_0
    } p9_pci_ring_id_t;

//        8             7             6             5             4             3          2         1
//
//  |0 1 2 3| |4 5 6 7| |8 9 10 11| |12 13 14 15| |16 17 18 19| |20 21 22 23| |24 25 26 27| |28 29 30 31|
//    {A}{     B      }             {   C    }          {      D      }{     E      }{        F          }
//
// A - Is multiCast if bit 1 = 0x1
// B - Contains Chiplet ID (6 bits) [2:7]
// C - Contains Port Number (4 bits) [12:15]
// D - Ring (4 bits) [18:21]
// E - Sat ID (4 bits) [22:25]
// F - Sat Offset (6 bits) [26:31]

    /// P9 SCOM address class
    class p9_scom_addr
    {

        public:
            /// @brief Construct a SCOM address object
            /// @param[in] i_addr 64-bit raw SCOM address
            p9_scom_addr(const uint64_t i_addr)
                : iv_addr(i_addr)
            {
            }

            /// @brief Set full/raw SCOM address
            /// @param[in] i_addr 64-bit SCOM address
            /// @retval none
            inline void set_addr(const uint64_t i_addr)
            {
                iv_addr = i_addr;
                return;
            }

            /// @brief Retrieve full/raw SCOM address
            /// @retval uint64_t 64-bit SCOM address
            inline uint64_t get_addr() const
            {
                return (iv_addr);
            }

            /// @brief Determine if SCOM address is direct-form
            /// @retval bool True if SCOM address is direct-form, false otherwise
            inline bool is_direct() const
            {
                return (((iv_addr >> 63) & 0x1) == 0x0);
            }

            /// @brief Determine if SCOM address is indirect-form
            /// @retval bool True if SCOM address is indirect-form, false otherwise
            inline bool is_indirect() const
            {
                return (!is_direct());
            }

            /// @brief Determine if SCOM address is unicast
            /// @retval bool True if SCOM address is unicast, false otherwise
            inline bool is_unicast() const
            {
                return (!(is_multicast()));
            }

            /// @brief Determine if SCOM address is multicast
            /// @retval bool True if SCOM address is multicast, false otherwise
            inline bool is_multicast() const
            {
                return (((iv_addr >> 30) & 0x1) == 0x1);
            }

            /// @brief Extract pervasive chiplet ID from SCOM address
            /// @retval uint8_t Pervasive chiplet ID value
            inline uint8_t get_chiplet_id() const
            {
                return ((iv_addr >> 24) & 0x3F);
            }

            /// @brief Modify SCOM address, update pervasive chiplet ID
            /// @param[in] i_chiplet_id Chiplet ID value to write
            /// @retval none
            inline void set_chiplet_id(const uint8_t i_chiplet_id)
            {
                iv_addr &= 0xFFFFFFFFC0FFFFFFULL;
                iv_addr |= ((i_chiplet_id & 0x3F) << 24);
                return;
            }

            /// @brief Extract port field from SCOM address
            /// @retval uint8_t Port field value
            inline uint8_t get_port() const
            {
                return ((iv_addr >> 16) & 0xF);
            }

            /// @brief Modify the port field from SCOM address
            /// @retval uint8_t Port field value
            inline void set_port(const uint8_t i_port)
            {
                iv_addr &= 0xFFFFFFFFFFF0FFFFULL;
                iv_addr |= ((i_port & 0xF) << 16);
                return;
            }

            /// @brief Extract ring field from SCOM address
            /// @retval uint8_t Ring field value
            inline uint8_t get_ring() const
            {
                return ((iv_addr >> 10) & 0xF);
            }

            /// @brief Modify SCOM address, update ring field value
            /// @param[in] i_ring Ring field value to write
            /// @retval none
            inline void set_ring(const uint8_t i_ring)
            {
                iv_addr &= 0xFFFFFFFFFFFFC3FFULL;
                iv_addr |= ((i_ring & 0xF) << 10);
                return;
            }

            /// @brief Extract satellite ID field from SCOM address
            /// @retval uint8_t Satellite ID field value
            inline uint8_t get_sat_id() const
            {
                return ((iv_addr >> 6) & 0xF);
            }

            /// @brief Modify SCOM address, update satellite ID field
            /// @param[in] i_sat_id Satellite ID value to write
            /// @retval none
            inline void set_sat_id(const uint8_t i_sat_id)
            {
                iv_addr &= 0xFFFFFFFFFFFFFC3FULL;
                iv_addr |= ((i_sat_id & 0xF) << 6);
                return;
            }

            /// @brief Extract satellite register offset field from SCOM address
            /// @retval uint8_t Satellite register offset field value
            inline uint8_t get_sat_offset() const
            {
                return (iv_addr & 0x3F);
            }

            /// @brief Modify SCOM address, update satellite offset field
            /// @param[in] i_sat_offset Satellite offset value to write
            /// @retval none
            inline void set_sat_offset(const uint8_t i_sat_offset)
            {
                iv_addr &= 0xFFFFFFFFFFFFFFC0ULL;
                iv_addr |= (i_sat_offset & 0x3F);
                return;
            }

            /// @brief Determine if SCOM address is valid/well-formed
            /// @retval bool True if SCOM address is valid, false otherwise
            inline bool is_valid() const
            {
                return true;
            }

        private:
            uint64_t iv_addr;   ///< 64-bit raw SCOM address
    };

} // extern "C"

#endif /* P9_SCOM_ADDR_H */

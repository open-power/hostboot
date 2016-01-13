/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_misc_scom_addresses.H $            */
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
/// @file p9_misc_scom_addresses.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

/*---------------------------------------------------------------
 *
 *---------------------------------------------------------------
 *
 *  Issues:
 *
 * Closed
 *    TOD reg same address.             HW323439
 *       - Issue was closed with the explaination "same as p8"
 *    IO0 registers need fixed.         HW320437
 *    PHB registers need fixed.         HW320416  ( all regs commented out now )
 *    OSC/perv regs same address.       HW323437
 *    MC regs with same address.        HW323435 (matteo)
 *         Duplicate IOM registers.          HW320456 (designers)
 *    PEC Sat_id issue                  HW329652
 *    PB.PB_PPE registers need fixed.   HW320435
 *    EX05 registers need fixed.        HW320427  (9020) - L2 ring id's are incorrect
 *    IOFPPE registers need fixed.      HW320424  (9020) - Investigate NULL scope
 *    PEC addresses are wrong.          HW322598  (9020)
 *    MC registers need fixed.          HW320433
 *    VA.VA_NORTH registers need fixed. HW320436
 *
 * Format:
 *
 *  <UNIT>_<SUBUNIT>_<INSTANCE>_<REGISTER>_<ACCESS/TYPE>
 *
 *  Notes: Subunits are only added to make names unique when
 *  there are name collisions.
 *  Only units with more than one instance has instance numbers.
 *  If there is only one, the instance number is omitted.
 *
 *  Instance numbers are chiplet id's for the PERV unit.  The
 *  chiplet id's are mapped to their name and used instead of
 *  instance numbers.  See bellow.
 *
 *  For registers with a single access type the type and access
 *  methods are omitted.
 *
 *  For access types where all bits have the same access methods, the
 *  access method is appended to the name.  If the access methods
 *  are different for some bits, the access type is appended to the
 *  name _SCOM instead of _RO.  The _RW(X) access method is omitted
 *  and assumed to be default.
 *
 *  Valid units / subunits
 *    PU                    : No unit chip level
 *        MCD0[0..1]        : mcd subunit
 *        PIB2OPB[0..1]     : PIB2OPB subunit
 *        OTPROM[0..1]      : otprom subunit
 *        NPU               : common npu subunit
 *        NPU[0..2]         : Npu stacks 0 to 2
 *          CTL             : Npu CTL subunit
 *          DAT             : Npu DAT subunit
 *          SM[0..3]        : Npu SM subunits
 *          NTL[0..1]       : Npu NTL subunit
 *    PERV                  : Pervasive
 *        FSI2PIB           : subunit
 *        FSISHIFT          : subunit
 *        FSII2C            : subunit
 *        FSB               : subunit
 *    EX                    : Ex unit (1/2 quad, 2 cores)
 *        L2                : L2 subunit
 *        L3                : L3 subunit
 *    PEC                   : PCI Pec unit
 *        STACK0            : subunit
 *        STACK1            : subunit
 *        STACK2            : subunit
 *    C                     : core
 *    EQ                    : quad
 *    OBUS                  : obus
 *    CAPP                  : capp
 *    MCBIST                : mcbist
 *    MCA                   : mca
 *    NVBUS                 : (not implemented yet)
 *    PHB                   : (not implemented yet)
 *    MI                    : (not implemented yet)
 *    DMI                   : (not implemented yet)
 *    MCS                   : (not implemented yet)
 *    OCC                   : (not implemented yet)
 *    PPE                   : (not implemented yet)
 *    SBE                   : (not implemented yet)
 *    XBUS                  : (not implemented yet)
 *
 * Pervasive instance names follow chiplet id.
 *
 * Instance/  | Chiplet
 * Chiplet    | name
 * -----------+-----------
 * 0x00       | PIB
 * 0x01       | TP
 * 0x02       | N0
 * 0x03       | N1
 * 0x04       | N2
 * 0x05       | N3
 * 0x06       | XB
 * 0x07       | MC01
 * 0x08       | MC23
 * 0x09       | OB0
 * 0x0A       | OB1
 * 0x0B       | OB2
 * 0x0C       | OB3
 * 0x0D       | PCI0
 * 0x0E       | PCI1
 * 0x0F       | PCI2
 * 0x10       | EP00
 * 0x11       | EP01
 * 0x12       | EP02
 * 0x13       | EP03
 * 0x14       | EP04
 * 0x15       | EP05
 * 0x20       | EC00
 * 0x21       | EC01
 * 0x22       | EC02
 * 0x23       | EC03
 * 0x24       | EC04
 * 0x25       | EC05
 * 0x26       | EC06
 * 0x27       | EC07
 * 0x28       | EC08
 * 0x29       | EC09
 * 0x2A       | EC10
 * 0x2B       | EC11
 * 0x2C       | EC12
 * 0x2D       | EC13
 * 0x2E       | EC14
 * 0x2F       | EC15
 * 0x30       | EC16
 * 0x31       | EC17
 * 0x32       | EC18
 * 0x33       | EC19
 * 0x34       | EC20
 * 0x35       | EC21
 * 0x36       | EC22
 * 0x37       | EC23
 *
 *
 *---------------------------------------------------------------
 *
 * NOTES:
 *
 * there is a SPR ring that goes around the chip with an
 * address(0:9)/tid(0:1) (thread id)/mfspr_data(0:63) and return mfspr_data_v/mfspr_data(0:63)
 *
 *    Add PU_<SUBUNITS>  (only if there are conflicts on these registers)
 *       0x0001XXXX OTPROM
 *       0x0002XXXX FSIM0
 *       0x0003XXXX FSIM1
 *       0x0004XXXX TOD
 *       0x0005XXXX FSI_MBOX
 *       0x0006XXXX OCI_BRIDGE
 *       0x0007XXXX SPI_ADC
 *       0x0008XXXX PIBMEM
 *       0x0009XXXX ADU
 *       0x000AXXXX I2CM
 *       0x000BXXXX SBE_FIFO
 *       0x000DXXXX PSU
 *       0x000EXXXX SBE
 *
 * 0x0000100A for FSI2PIB  => PERV_FSI2PIB
 * 0x00000Cxx for FSISHIFT =>  PERV_FSISHIFT
 * 0x000018xx for FSI I2C =>  PERV_FSII2C
 * 0x000024xx for FSI SBEFIFO => PERV_FSB
 *
 * 0x00000400 PEEK_TABLE
 * 0x00000800 FSI_SLAVE
 * 0x00000C00 FSI_SHIFT
 * 0x00001000 FSI2PIB
 * 0x00001400 FSI_SCRATCHPAD
 * 0x00001800 FSI_I2CM
 * 0x00002400 FSI_SBE_FIFO
 *
 * address fields
 * 0xCCRPxxxx
 *
 * CC=chiplet
 * R=always 0?
 * P=port
 *   0=gpregs
 *   1=normal unit scom ring (exclude)
 *   3=clock controller
 *   4=firs
 *   5=cpm
 *
 * =============================================================================
 * Compiling
 *
 * Precompile the header to save time on subsquent compiles:
 * g++ -I. -c scom_addresses.H
 *
 * Use these options to help reduce the binary size
 * g++ -I. -Os -fdata-sections -ffunction-sections <file>.C -o <output> -Wl,--gc-sections
 *
 *
 *---------------------------------------------------------------
 */

#include <p9_const_common.H>


#ifndef __P9_MISC_SCOM_ADDRESSES_H
#define __P9_MISC_SCOM_ADDRESSES_H


#include <p9_scom_template_consts.H>
#include <p9_misc_scom_addresses_fixes.H>


REG64( PHB_ACT0_REG                                            , RULL(0x0D01090E), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_ACT0_REG                                          , RULL(0x0D01090E), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_ACT0_REG                                          , RULL(0x0E01090E), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_ACT0_REG                                          , RULL(0x0E01094E), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_ACT0_REG                                          , RULL(0x0F01090E), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_ACT0_REG                                          , RULL(0x0F01094E), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_ACT0_REG                                          , RULL(0x0F01098E), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PHB_ACTION1_REG                                         , RULL(0x0D01090F), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_ACTION1_REG                                       , RULL(0x0D01090F), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_ACTION1_REG                                       , RULL(0x0E01090F), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_ACTION1_REG                                       , RULL(0x0E01094F), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_ACTION1_REG                                       , RULL(0x0F01090F), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_ACTION1_REG                                       , RULL(0x0F01094F), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_ACTION1_REG                                       , RULL(0x0F01098F), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_0_HASH_FUNCTION_REG                             , RULL(0x02011141), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_10_HASH_FUNCTION_REG                            , RULL(0x0201114B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_1_HASH_FUNCTION_REG                             , RULL(0x02011142), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_2_HASH_FUNCTION_REG                             , RULL(0x02011143), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_3_HASH_FUNCTION_REG                             , RULL(0x02011144), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_4_HASH_FUNCTION_REG                             , RULL(0x02011145), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_5_HASH_FUNCTION_REG                             , RULL(0x02011146), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_6_HASH_FUNCTION_REG                             , RULL(0x02011147), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_7_HASH_FUNCTION_REG                             , RULL(0x02011148), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_8_HASH_FUNCTION_REG                             , RULL(0x02011149), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_ADDR_9_HASH_FUNCTION_REG                             , RULL(0x0201114A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_ADDR_TRAP_REG                                       , RULL(0x0D010003), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ADDR_TRAP_REG                                     , RULL(0x0D010003), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ADDR_TRAP_REG                                     , RULL(0x0E010003), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ADDR_TRAP_REG                                     , RULL(0x0F010003), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_ADDR_TRAP_REG                                     , RULL(0x02010003), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_ADDR_TRAP_REG                                     , RULL(0x03010003), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_ADDR_TRAP_REG                                     , RULL(0x04010003), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_ADDR_TRAP_REG                                     , RULL(0x05010003), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( CAPP_APCFG                                              , RULL(0x02010819), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APCFG                                            , RULL(0x02010819), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APCFG                                            , RULL(0x04010819), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APCLCO                                             , RULL(0x02010821), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APCLCO                                           , RULL(0x02010821), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APCLCO                                           , RULL(0x04010821), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APCRDFSMMASK                                       , RULL(0x02010823), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APCRDFSMMASK                                     , RULL(0x02010823), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APCRDFSMMASK                                     , RULL(0x04010823), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APCTL                                              , RULL(0x02010818), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APCTL                                            , RULL(0x02010818), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APCTL                                            , RULL(0x04010818), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APC_ARRY_ADDR                                      , RULL(0x0201082A), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APC_ARRY_ADDR                                    , RULL(0x0201082A), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APC_ARRY_ADDR                                    , RULL(0x0401082A), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APC_ARRY_RDDATA                                    , RULL(0x0201082B), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APC_ARRY_RDDATA                                  , RULL(0x0201082B), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APC_ARRY_RDDATA                                  , RULL(0x0401082B), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APC_ARRY_WRDATA                                    , RULL(0x02010842), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APC_ARRY_WRDATA                                  , RULL(0x02010842), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APC_ARRY_WRDATA                                  , RULL(0x04010842), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APC_ERRINJ                                         , RULL(0x02010810), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APC_ERRINJ                                       , RULL(0x02010810), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APC_ERRINJ                                       , RULL(0x04010810), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_APC_PMUSEL                                         , RULL(0x02010816), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_APC_PMUSEL                                       , RULL(0x02010816), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_APC_PMUSEL                                       , RULL(0x04010816), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_ASE_TUPLE0                                         , RULL(0x02010846), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_ASE_TUPLE0                                       , RULL(0x02010846), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_ASE_TUPLE0                                       , RULL(0x04010846), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_ASE_TUPLE1                                         , RULL(0x02010847), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_ASE_TUPLE1                                       , RULL(0x02010847), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_ASE_TUPLE1                                       , RULL(0x04010847), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_ASE_TUPLE2                                         , RULL(0x02010848), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_ASE_TUPLE2                                       , RULL(0x02010848), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_ASE_TUPLE2                                       , RULL(0x04010848), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_ASE_TUPLE3                                         , RULL(0x02010849), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_ASE_TUPLE3                                       , RULL(0x02010849), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_ASE_TUPLE3                                       , RULL(0x04010849), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PEC_ASSIST_INTERRUPT_REG                                , RULL(0x0D0F0011), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ASSIST_INTERRUPT_REG                              , RULL(0x0D0F0011), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ASSIST_INTERRUPT_REG                              , RULL(0x0E0F0011), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ASSIST_INTERRUPT_REG                              , RULL(0x0F0F0011), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_ATOMIC_LOCK_MASK_LATCH_REG                          , RULL(0x0D010007), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x0D010007), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x0E010007), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x0F010007), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x02010007), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x03010007), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x04010007), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_ATOMIC_LOCK_MASK_LATCH_REG                        , RULL(0x05010007), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_ATOMIC_LOCK_REG                                     , RULL(0x0D0F03FF), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ATOMIC_LOCK_REG                                   , RULL(0x0D0F03FF), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ATOMIC_LOCK_REG                                   , RULL(0x0E0F03FF), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ATOMIC_LOCK_REG                                   , RULL(0x0F0F03FF), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( NV_ATR_HA_PTR                                           , RULL(0x050110D2), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_ATR_HA_PTR                                         , RULL(0x050110D2), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_ATR_HA_PTR                                         , RULL(0x050110F2), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_ATR_HA_PTR                                         , RULL(0x050111D2), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_ATR_HA_PTR                                         , RULL(0x050111F2), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_ATR_HA_PTR                                 , RULL(0x050112D2), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_ATR_HA_PTR                                 , RULL(0x050112F2), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM0_ATS_CKSW                                     , RULL(0x05011304), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_ATS_CTRL                                     , RULL(0x05011320), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM0_ATS_HOLD                                     , RULL(0x05011305), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_NPU_SM0_ATS_MASK                                     , RULL(0x05011306), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_RO   );

REG64( PU_NPU_SM1_ATS_TCR                                      , RULL(0x05011326), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM      );

REG64( PEC_ATTN_INTERRUPT_REG                                  , RULL(0x0D0F001A), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ATTN_INTERRUPT_REG                                , RULL(0x0D0F001A), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ATTN_INTERRUPT_REG                                , RULL(0x0E0F001A), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ATTN_INTERRUPT_REG                                , RULL(0x0F0F001A), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_BANK0_MCD_BOT                                        , RULL(0x0301140C), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_BANK0_MCD_BOT                                   , RULL(0x0301100C), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_BANK0_MCD_CHA                                        , RULL(0x0301140D), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_BANK0_MCD_CHA                                   , RULL(0x0301100D), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_BANK0_MCD_CMD                                        , RULL(0x0301140E), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_BANK0_MCD_CMD                                   , RULL(0x0301100E), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_BANK0_MCD_REC                                        , RULL(0x03011410), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_MCD1_BANK0_MCD_REC                                   , RULL(0x03011010), SH_UNT_PU_MCD1  , SH_ACS_SCOM      );

REG64( PU_BANK0_MCD_RW                                         , RULL(0x0301140F), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_MCD1_BANK0_MCD_RW                                    , RULL(0x0301100F), SH_UNT_PU_MCD1  , SH_ACS_SCOM      );

REG64( PU_BANK0_MCD_STR                                        , RULL(0x0301140B), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_BANK0_MCD_STR                                   , RULL(0x0301100B), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_BANK0_MCD_TOP                                        , RULL(0x0301140A), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_BANK0_MCD_TOP                                   , RULL(0x0301100A), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_BANK0_MCD_VGC                                        , RULL(0x03011411), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_BANK0_MCD_VGC                                   , RULL(0x03011011), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PEC_0_STACK0_BARE_REG                                   , RULL(0x04010C54), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_BARE_REG                                   , RULL(0x04010C94), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_BARE_REG                                   , RULL(0x04010CD4), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_BARE_REG                                   , RULL(0x04011054), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_BARE_REG                                   , RULL(0x04011094), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_BARE_REG                                   , RULL(0x040110D4), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_BARE_REG                                   , RULL(0x04011454), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_BARE_REG                                   , RULL(0x04011494), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_BARE_REG                                   , RULL(0x040114D4), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_BARE_REG                                     , RULL(0x04010C54), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_BARE_REG                                     , RULL(0x04010C94), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_BARE_REG                                     , RULL(0x04010CD4), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PHB_BARE_REG                                            , RULL(0x04010C54), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_BARE_REG                                          , RULL(0x04010C54), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_BARE_REG                                          , RULL(0x04011054), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_BARE_REG                                          , RULL(0x04011094), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_BARE_REG                                          , RULL(0x04011454), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_BARE_REG                                          , RULL(0x04011494), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_BARE_REG                                          , RULL(0x040114D4), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PU_BCDE_CTL_OCI                                         , RULL(0xC0040080), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCDE_CTL_SCOM                                        , RULL(0x05016850), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_BCDE_OCIBAR_OCI                                      , RULL(0xC00400A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCDE_OCIBAR_SCOM                                     , RULL(0x05016854), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_BCDE_PBADR_OCI                                       , RULL(0xC0040098), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCDE_PBADR_SCOM                                      , RULL(0x05016853), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_BCDE_SET_OCI                                         , RULL(0xC0040088), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCDE_SET_SCOM                                        , RULL(0x05016851), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_BCDE_STAT_OCI                                        , RULL(0xC0040090), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCDE_STAT_SCOM                                       , RULL(0x05016852), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_BCUE_CTL_OCI                                         , RULL(0xC00400A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCUE_CTL_SCOM                                        , RULL(0x05016855), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_BCUE_OCIBAR_OCI                                      , RULL(0xC00400C8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCUE_OCIBAR_SCOM                                     , RULL(0x05016859), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_BCUE_PBADR_OCI                                       , RULL(0xC00400C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCUE_PBADR_SCOM                                      , RULL(0x05016858), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_BCUE_SET_OCI                                         , RULL(0xC00400B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCUE_SET_SCOM                                        , RULL(0x05016856), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_BCUE_STAT_OCI                                        , RULL(0xC00400B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_BCUE_STAT_SCOM                                       , RULL(0x05016857), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_NPU_BDF2PE_00_CONFIG                                 , RULL(0x050113A0), SH_UNT_PU_NPU   , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_BDF2PE_00_CONFIG                            , RULL(0x0501108A), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_BDF2PE_00_CONFIG                            , RULL(0x0501118A), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_BDF2PE_00_CONFIG                            , RULL(0x0501128A), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_01_CONFIG                                 , RULL(0x050113A1), SH_UNT_PU_NPU   , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_BDF2PE_01_CONFIG                            , RULL(0x0501108B), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_BDF2PE_01_CONFIG                            , RULL(0x0501118B), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_BDF2PE_01_CONFIG                            , RULL(0x0501128B), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_02_CONFIG                                 , RULL(0x050113A2), SH_UNT_PU_NPU   , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_BDF2PE_02_CONFIG                            , RULL(0x0501108C), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_BDF2PE_02_CONFIG                            , RULL(0x0501118C), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_BDF2PE_02_CONFIG                            , RULL(0x0501128C), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_10_CONFIG                                 , RULL(0x050113A3), SH_UNT_PU_NPU   , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_BDF2PE_10_CONFIG                            , RULL(0x0501108D), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_BDF2PE_10_CONFIG                            , RULL(0x0501118D), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_BDF2PE_10_CONFIG                            , RULL(0x0501128D), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_11_CONFIG                                 , RULL(0x050113A4), SH_UNT_PU_NPU   , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_BDF2PE_11_CONFIG                            , RULL(0x0501108E), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_BDF2PE_11_CONFIG                            , RULL(0x0501118E), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_BDF2PE_11_CONFIG                            , RULL(0x0501128E), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_12_CONFIG                                 , RULL(0x050113A5), SH_UNT_PU_NPU   , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_BDF2PE_12_CONFIG                            , RULL(0x0501108F), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_BDF2PE_12_CONFIG                            , RULL(0x0501118F), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_BDF2PE_12_CONFIG                            , RULL(0x0501128F), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_20_CONFIG                                 , RULL(0x050113A6), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_21_CONFIG                                 , RULL(0x050113A7), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_22_CONFIG                                 , RULL(0x050113A8), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_30_CONFIG                                 , RULL(0x050113A9), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_31_CONFIG                                 , RULL(0x050113AA), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_32_CONFIG                                 , RULL(0x050113AB), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_40_CONFIG                                 , RULL(0x050113AC), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_41_CONFIG                                 , RULL(0x050113AD), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_42_CONFIG                                 , RULL(0x050113AE), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_BDF2PE_50_CONFIG                                 , RULL(0x050113AF), SH_UNT_PU_NPU   , SH_ACS_SCOM      );

REG64( PU_NPU_DAT_BDF2PE_51_CONFIG                             , RULL(0x050113B0), SH_UNT_PU_NPU_DAT,
       SH_ACS_SCOM      );

REG64( PU_NPU_DAT_BDF2PE_52_CONFIG                             , RULL(0x050113B1), SH_UNT_PU_NPU_DAT,
       SH_ACS_SCOM      );

REG64( PEC_BIST                                                , RULL(0x0D03000B), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_BIST                                              , RULL(0x0D03000B), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_BIST                                              , RULL(0x0E03000B), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_BIST                                              , RULL(0x0F03000B), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( CAPP_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL                , RULL(0x0201082C), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL              , RULL(0x0201082C), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL              , RULL(0x0401082C), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CAPP_ERR_STATUS_CONTROL                            , RULL(0x0201080E), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CAPP_ERR_STATUS_CONTROL                          , RULL(0x0201080E), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CAPP_ERR_STATUS_CONTROL                          , RULL(0x0401080E), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PEC_CC_ATOMIC_LOCK_REG                                  , RULL(0x0D0303FF), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CC_ATOMIC_LOCK_REG                                , RULL(0x0D0303FF), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CC_ATOMIC_LOCK_REG                                , RULL(0x0E0303FF), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CC_ATOMIC_LOCK_REG                                , RULL(0x0F0303FF), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_CC_PROTECT_MODE_REG                                 , RULL(0x0D0303FE), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CC_PROTECT_MODE_REG                               , RULL(0x0D0303FE), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CC_PROTECT_MODE_REG                               , RULL(0x0E0303FE), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CC_PROTECT_MODE_REG                               , RULL(0x0F0303FE), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_ECC_FIRST                                  , RULL(0x050110A6), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_ECC_FIRST                                  , RULL(0x050111A6), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_ECC_FIRST                                  , RULL(0x050112A6), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_ECC_HOLD                                   , RULL(0x050110A4), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_ECC_HOLD                                   , RULL(0x050111A4), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_ECC_HOLD                                   , RULL(0x050112A4), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_ECC_MASK                                   , RULL(0x050110A5), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_ECC_MASK                                   , RULL(0x050111A5), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_ECC_MASK                                   , RULL(0x050112A5), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_CERR_FIRST0                                 , RULL(0x0501109A), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_FIRST0                                 , RULL(0x0501119A), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_FIRST0                                 , RULL(0x0501129A), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_FIRST0                                 , RULL(0x05011017), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_FIRST0                                 , RULL(0x05011037), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_FIRST0                                 , RULL(0x05011057), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_FIRST0                                 , RULL(0x05011077), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_FIRST0                                 , RULL(0x05011117), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_FIRST0                                 , RULL(0x05011137), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_FIRST0                                 , RULL(0x05011157), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_FIRST0                                 , RULL(0x05011177), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_FIRST0                                 , RULL(0x05011217), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_FIRST0                                 , RULL(0x05011237), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_FIRST0                                 , RULL(0x05011257), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_FIRST0                                 , RULL(0x05011277), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_FIRST1                                          , RULL(0x050110C4), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_FIRST1                                        , RULL(0x050110C4), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_FIRST1                                        , RULL(0x050110E4), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_FIRST1                                        , RULL(0x050111C4), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_FIRST1                                        , RULL(0x050111E4), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_CERR_FIRST1                                 , RULL(0x0501109B), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_FIRST1                                 , RULL(0x0501119B), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_FIRST1                                 , RULL(0x0501129B), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_FIRST1                                 , RULL(0x05011018), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_FIRST1                                 , RULL(0x05011038), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_FIRST1                                 , RULL(0x05011058), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_FIRST1                                 , RULL(0x05011078), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_FIRST1                                 , RULL(0x05011118), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_FIRST1                                 , RULL(0x05011138), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_FIRST1                                 , RULL(0x05011158), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_FIRST1                                 , RULL(0x05011178), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_FIRST1                                , RULL(0x050112C4), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_FIRST1                                , RULL(0x050112E4), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_FIRST1                                 , RULL(0x05011218), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_FIRST1                                 , RULL(0x05011238), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_FIRST1                                 , RULL(0x05011258), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_FIRST1                                 , RULL(0x05011278), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_FIRST2                                          , RULL(0x050110C8), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_FIRST2                                        , RULL(0x050110C8), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_FIRST2                                        , RULL(0x050110E8), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_FIRST2                                        , RULL(0x050111C8), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_FIRST2                                        , RULL(0x050111E8), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_FIRST2                                 , RULL(0x05011019), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_FIRST2                                 , RULL(0x05011039), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_FIRST2                                 , RULL(0x05011059), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_FIRST2                                 , RULL(0x05011079), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_FIRST2                                 , RULL(0x05011119), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_FIRST2                                 , RULL(0x05011139), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_FIRST2                                 , RULL(0x05011159), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_FIRST2                                 , RULL(0x05011179), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_FIRST2                                , RULL(0x050112C8), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_FIRST2                                , RULL(0x050112E8), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_FIRST2                                 , RULL(0x05011219), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_FIRST2                                 , RULL(0x05011239), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_FIRST2                                 , RULL(0x05011259), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_FIRST2                                 , RULL(0x05011279), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_FIRST_MASK1                                     , RULL(0x050110C5), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_FIRST_MASK1                                   , RULL(0x050110C5), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_FIRST_MASK1                                   , RULL(0x050110E5), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_FIRST_MASK1                                   , RULL(0x050111C5), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_FIRST_MASK1                                   , RULL(0x050111E5), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_FIRST_MASK1                           , RULL(0x050112C5), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_FIRST_MASK1                           , RULL(0x050112E5), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( NV_CERR_FIRST_MASK2                                     , RULL(0x050110C9), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_FIRST_MASK2                                   , RULL(0x050110C9), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_FIRST_MASK2                                   , RULL(0x050110E9), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_FIRST_MASK2                                   , RULL(0x050111C9), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_FIRST_MASK2                                   , RULL(0x050111E9), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_FIRST_MASK2                           , RULL(0x050112C9), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_FIRST_MASK2                           , RULL(0x050112E9), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_CERR_HOLD0                                  , RULL(0x0501109E), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_HOLD0                                  , RULL(0x0501119E), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_HOLD0                                  , RULL(0x0501129E), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_HOLD0                                  , RULL(0x0501101D), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_HOLD0                                  , RULL(0x0501103D), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_HOLD0                                  , RULL(0x0501105D), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_HOLD0                                  , RULL(0x0501107D), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_HOLD0                                  , RULL(0x0501111D), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_HOLD0                                  , RULL(0x0501113D), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_HOLD0                                  , RULL(0x0501115D), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_HOLD0                                  , RULL(0x0501117D), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_HOLD0                                  , RULL(0x0501121D), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_HOLD0                                  , RULL(0x0501123D), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_HOLD0                                  , RULL(0x0501125D), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_HOLD0                                  , RULL(0x0501127D), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_HOLD1                                           , RULL(0x050110C2), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_HOLD1                                         , RULL(0x050110C2), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_HOLD1                                         , RULL(0x050110E2), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_HOLD1                                         , RULL(0x050111C2), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_HOLD1                                         , RULL(0x050111E2), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_CERR_HOLD1                                  , RULL(0x0501109F), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_HOLD1                                  , RULL(0x0501119F), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_HOLD1                                  , RULL(0x0501129F), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_HOLD1                                  , RULL(0x0501101E), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_HOLD1                                  , RULL(0x0501103E), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_HOLD1                                  , RULL(0x0501105E), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_HOLD1                                  , RULL(0x0501107E), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_HOLD1                                  , RULL(0x0501111E), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_HOLD1                                  , RULL(0x0501113E), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_HOLD1                                  , RULL(0x0501115E), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_HOLD1                                  , RULL(0x0501117E), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_HOLD1                                 , RULL(0x050112C2), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_HOLD1                                 , RULL(0x050112E2), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_HOLD1                                  , RULL(0x0501121E), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_HOLD1                                  , RULL(0x0501123E), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_HOLD1                                  , RULL(0x0501125E), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_HOLD1                                  , RULL(0x0501127E), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_HOLD2                                           , RULL(0x050110C6), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_HOLD2                                         , RULL(0x050110C6), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_HOLD2                                         , RULL(0x050110E6), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_HOLD2                                         , RULL(0x050111C6), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_HOLD2                                         , RULL(0x050111E6), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_HOLD2                                  , RULL(0x0501101F), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_HOLD2                                  , RULL(0x0501103F), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_HOLD2                                  , RULL(0x0501105F), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_HOLD2                                  , RULL(0x0501107F), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_HOLD2                                  , RULL(0x0501111F), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_HOLD2                                  , RULL(0x0501113F), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_HOLD2                                  , RULL(0x0501115F), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_HOLD2                                  , RULL(0x0501117F), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_HOLD2                                 , RULL(0x050112C6), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_HOLD2                                 , RULL(0x050112E6), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_HOLD2                                  , RULL(0x0501121F), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_HOLD2                                  , RULL(0x0501123F), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_HOLD2                                  , RULL(0x0501125F), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_HOLD2                                  , RULL(0x0501127F), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_LOG_FIRST                                  , RULL(0x050110AC), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_LOG_FIRST                                  , RULL(0x050111AC), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_LOG_FIRST                                  , RULL(0x050112AC), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_LOG_HOLD                                   , RULL(0x050110AA), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_LOG_HOLD                                   , RULL(0x050111AA), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_LOG_HOLD                                   , RULL(0x050112AA), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_LOG_MASK                                   , RULL(0x050110AB), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_LOG_MASK                                   , RULL(0x050111AB), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_LOG_MASK                                   , RULL(0x050112AB), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_CERR_MASK0                                  , RULL(0x0501109C), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_MASK0                                  , RULL(0x0501119C), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_MASK0                                  , RULL(0x0501129C), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_MASK0                                  , RULL(0x0501101A), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MASK0                                  , RULL(0x0501103A), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MASK0                                  , RULL(0x0501105A), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MASK0                                  , RULL(0x0501107A), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MASK0                                  , RULL(0x0501111A), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MASK0                                  , RULL(0x0501113A), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MASK0                                  , RULL(0x0501115A), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MASK0                                  , RULL(0x0501117A), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MASK0                                  , RULL(0x0501121A), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MASK0                                  , RULL(0x0501123A), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MASK0                                  , RULL(0x0501125A), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MASK0                                  , RULL(0x0501127A), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_MASK1                                           , RULL(0x050110C3), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_MASK1                                         , RULL(0x050110C3), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_MASK1                                         , RULL(0x050110E3), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_MASK1                                         , RULL(0x050111C3), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_MASK1                                         , RULL(0x050111E3), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_CERR_MASK1                                  , RULL(0x0501109D), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_MASK1                                  , RULL(0x0501119D), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_MASK1                                  , RULL(0x0501129D), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_MASK1                                  , RULL(0x0501101B), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MASK1                                  , RULL(0x0501103B), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MASK1                                  , RULL(0x0501105B), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MASK1                                  , RULL(0x0501107B), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MASK1                                  , RULL(0x0501111B), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MASK1                                  , RULL(0x0501113B), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MASK1                                  , RULL(0x0501115B), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MASK1                                  , RULL(0x0501117B), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_MASK1                                 , RULL(0x050112C3), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_MASK1                                 , RULL(0x050112E3), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MASK1                                  , RULL(0x0501121B), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MASK1                                  , RULL(0x0501123B), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MASK1                                  , RULL(0x0501125B), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MASK1                                  , RULL(0x0501127B), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CERR_MASK2                                           , RULL(0x050110C7), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CERR_MASK2                                         , RULL(0x050110C7), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CERR_MASK2                                         , RULL(0x050110E7), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CERR_MASK2                                         , RULL(0x050111C7), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CERR_MASK2                                         , RULL(0x050111E7), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_MASK2                                  , RULL(0x0501101C), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MASK2                                  , RULL(0x0501103C), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MASK2                                  , RULL(0x0501105C), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MASK2                                  , RULL(0x0501107C), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MASK2                                  , RULL(0x0501111C), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MASK2                                  , RULL(0x0501113C), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MASK2                                  , RULL(0x0501115C), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MASK2                                  , RULL(0x0501117C), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CERR_MASK2                                 , RULL(0x050112C7), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CERR_MASK2                                 , RULL(0x050112E7), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MASK2                                  , RULL(0x0501121C), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MASK2                                  , RULL(0x0501123C), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MASK2                                  , RULL(0x0501125C), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MASK2                                  , RULL(0x0501127C), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_CERR_MESSAGE0                               , RULL(0x05011098), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_MESSAGE0                               , RULL(0x05011198), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_MESSAGE0                               , RULL(0x05011298), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_MESSAGE0                               , RULL(0x05011011), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MESSAGE0                               , RULL(0x05011031), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MESSAGE0                               , RULL(0x05011051), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MESSAGE0                               , RULL(0x05011071), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MESSAGE0                               , RULL(0x05011111), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MESSAGE0                               , RULL(0x05011131), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MESSAGE0                               , RULL(0x05011151), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MESSAGE0                               , RULL(0x05011171), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MESSAGE0                               , RULL(0x05011211), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MESSAGE0                               , RULL(0x05011231), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MESSAGE0                               , RULL(0x05011251), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MESSAGE0                               , RULL(0x05011271), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_CERR_MESSAGE1                               , RULL(0x05011099), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CERR_MESSAGE1                               , RULL(0x05011199), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CERR_MESSAGE1                               , RULL(0x05011299), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CERR_MESSAGE1                               , RULL(0x05011012), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MESSAGE1                               , RULL(0x05011032), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MESSAGE1                               , RULL(0x05011052), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MESSAGE1                               , RULL(0x05011072), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MESSAGE1                               , RULL(0x05011112), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MESSAGE1                               , RULL(0x05011132), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MESSAGE1                               , RULL(0x05011152), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MESSAGE1                               , RULL(0x05011172), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MESSAGE1                               , RULL(0x05011212), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MESSAGE1                               , RULL(0x05011232), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MESSAGE1                               , RULL(0x05011252), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MESSAGE1                               , RULL(0x05011272), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_CERR_MESSAGE2                               , RULL(0x05011013), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MESSAGE2                               , RULL(0x05011033), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MESSAGE2                               , RULL(0x05011053), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MESSAGE2                               , RULL(0x05011073), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MESSAGE2                               , RULL(0x05011113), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MESSAGE2                               , RULL(0x05011133), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MESSAGE2                               , RULL(0x05011153), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MESSAGE2                               , RULL(0x05011173), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MESSAGE2                               , RULL(0x05011213), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MESSAGE2                               , RULL(0x05011233), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MESSAGE2                               , RULL(0x05011253), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MESSAGE2                               , RULL(0x05011273), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_CERR_MESSAGE3                               , RULL(0x05011014), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MESSAGE3                               , RULL(0x05011034), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MESSAGE3                               , RULL(0x05011054), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MESSAGE3                               , RULL(0x05011074), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MESSAGE3                               , RULL(0x05011114), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MESSAGE3                               , RULL(0x05011134), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MESSAGE3                               , RULL(0x05011154), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MESSAGE3                               , RULL(0x05011174), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MESSAGE3                               , RULL(0x05011214), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MESSAGE3                               , RULL(0x05011234), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MESSAGE3                               , RULL(0x05011254), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MESSAGE3                               , RULL(0x05011274), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_CERR_MESSAGE4                               , RULL(0x05011015), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CERR_MESSAGE4                               , RULL(0x05011035), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CERR_MESSAGE4                               , RULL(0x05011055), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CERR_MESSAGE4                               , RULL(0x05011075), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CERR_MESSAGE4                               , RULL(0x05011115), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CERR_MESSAGE4                               , RULL(0x05011135), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CERR_MESSAGE4                               , RULL(0x05011155), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CERR_MESSAGE4                               , RULL(0x05011175), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CERR_MESSAGE4                               , RULL(0x05011215), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CERR_MESSAGE4                               , RULL(0x05011235), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CERR_MESSAGE4                               , RULL(0x05011255), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CERR_MESSAGE4                               , RULL(0x05011275), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_PTY_FIRST                                  , RULL(0x050110A9), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_PTY_FIRST                                  , RULL(0x050111A9), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_PTY_FIRST                                  , RULL(0x050112A9), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_PTY_HOLD                                   , RULL(0x050110A7), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_PTY_HOLD                                   , RULL(0x050111A7), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_PTY_HOLD                                   , RULL(0x050112A7), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_CERR_PTY_MASK                                   , RULL(0x050110A8), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CERR_PTY_MASK                                   , RULL(0x050111A8), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_CERR_PTY_MASK                                   , RULL(0x050112A8), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_CERR_RPT0_REG                              , RULL(0x04010C4A), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_0_STACK1_CERR_RPT0_REG                              , RULL(0x04010C8A), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_0_STACK2_CERR_RPT0_REG                              , RULL(0x04010CCA), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK0_CERR_RPT0_REG                              , RULL(0x0401104A), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK1_CERR_RPT0_REG                              , RULL(0x0401108A), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK2_CERR_RPT0_REG                              , RULL(0x040110CA), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK0_CERR_RPT0_REG                              , RULL(0x0401144A), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK1_CERR_RPT0_REG                              , RULL(0x0401148A), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK2_CERR_RPT0_REG                              , RULL(0x040114CA), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK0_CERR_RPT0_REG                                , RULL(0x04010C4A), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK1_CERR_RPT0_REG                                , RULL(0x04010C8A), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK2_CERR_RPT0_REG                                , RULL(0x04010CCA), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PHB_CERR_RPT0_REG                                       , RULL(0x04010C4A), SH_UNT_PHB      , SH_ACS_SCOM_RO   );
REG64( PHB_0_CERR_RPT0_REG                                     , RULL(0x04010C4A), SH_UNT_PHB_0    , SH_ACS_SCOM_RO   );
REG64( PHB_1_CERR_RPT0_REG                                     , RULL(0x0401104A), SH_UNT_PHB_1    , SH_ACS_SCOM_RO   );
REG64( PHB_2_CERR_RPT0_REG                                     , RULL(0x0401108A), SH_UNT_PHB_2    , SH_ACS_SCOM_RO   );
REG64( PHB_3_CERR_RPT0_REG                                     , RULL(0x0401144A), SH_UNT_PHB_3    , SH_ACS_SCOM_RO   );
REG64( PHB_4_CERR_RPT0_REG                                     , RULL(0x0401148A), SH_UNT_PHB_4    , SH_ACS_SCOM_RO   );
REG64( PHB_5_CERR_RPT0_REG                                     , RULL(0x040114CA), SH_UNT_PHB_5    , SH_ACS_SCOM_RO   );

REG64( PEC_0_STACK0_CERR_RPT1_REG                              , RULL(0x04010C4B), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_0_STACK1_CERR_RPT1_REG                              , RULL(0x04010C8B), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_0_STACK2_CERR_RPT1_REG                              , RULL(0x04010CCB), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK0_CERR_RPT1_REG                              , RULL(0x0401104B), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK1_CERR_RPT1_REG                              , RULL(0x0401108B), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK2_CERR_RPT1_REG                              , RULL(0x040110CB), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK0_CERR_RPT1_REG                              , RULL(0x0401144B), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK1_CERR_RPT1_REG                              , RULL(0x0401148B), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK2_CERR_RPT1_REG                              , RULL(0x040114CB), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK0_CERR_RPT1_REG                                , RULL(0x04010C4B), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK1_CERR_RPT1_REG                                , RULL(0x04010C8B), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK2_CERR_RPT1_REG                                , RULL(0x04010CCB), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PHB_CERR_RPT1_REG                                       , RULL(0x04010C4B), SH_UNT_PHB      , SH_ACS_SCOM_RO   );
REG64( PHB_0_CERR_RPT1_REG                                     , RULL(0x04010C4B), SH_UNT_PHB_0    , SH_ACS_SCOM_RO   );
REG64( PHB_1_CERR_RPT1_REG                                     , RULL(0x0401104B), SH_UNT_PHB_1    , SH_ACS_SCOM_RO   );
REG64( PHB_2_CERR_RPT1_REG                                     , RULL(0x0401108B), SH_UNT_PHB_2    , SH_ACS_SCOM_RO   );
REG64( PHB_3_CERR_RPT1_REG                                     , RULL(0x0401144B), SH_UNT_PHB_3    , SH_ACS_SCOM_RO   );
REG64( PHB_4_CERR_RPT1_REG                                     , RULL(0x0401148B), SH_UNT_PHB_4    , SH_ACS_SCOM_RO   );
REG64( PHB_5_CERR_RPT1_REG                                     , RULL(0x040114CB), SH_UNT_PHB_5    , SH_ACS_SCOM_RO   );

REG64( PU_CLKRATIO                                             , RULL(0x07010FF0), SH_UNT          ,
       SH_ACS_SCOM_RO   ); //DUPS: 08010FF0,

REG64( PEC_CLK_REGION                                          , RULL(0x0D030006), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CLK_REGION                                        , RULL(0x0D030006), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CLK_REGION                                        , RULL(0x0E030006), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CLK_REGION                                        , RULL(0x0F030006), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_CLOCK_STAT_ARY                                      , RULL(0x0D03000A), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CLOCK_STAT_ARY                                    , RULL(0x0D03000A), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CLOCK_STAT_ARY                                    , RULL(0x0E03000A), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CLOCK_STAT_ARY                                    , RULL(0x0F03000A), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_CLOCK_STAT_NSL                                      , RULL(0x0D030009), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CLOCK_STAT_NSL                                    , RULL(0x0D030009), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CLOCK_STAT_NSL                                    , RULL(0x0E030009), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CLOCK_STAT_NSL                                    , RULL(0x0F030009), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_CLOCK_STAT_SL                                       , RULL(0x0D030008), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CLOCK_STAT_SL                                     , RULL(0x0D030008), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CLOCK_STAT_SL                                     , RULL(0x0E030008), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CLOCK_STAT_SL                                     , RULL(0x0F030008), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_CME0_CME_LCL_DBG_PPE                                 , RULL(0x109010120), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_LCL_DBG_PPE1                                , RULL(0x109010138), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_LCL_DBG_PPE2                                , RULL(0x109010130), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_LCL_DBG_PPE                                 , RULL(0x109020120), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_DBG_PPE1                                , RULL(0x109020138), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_LCL_DBG_PPE2                                , RULL(0x109020130), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_LCL_DBG_PPE                                 , RULL(0x10A010120), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_DBG_PPE1                                , RULL(0x10A010138), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_LCL_DBG_PPE2                                , RULL(0x10A010130), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_LCL_DBG_PPE                                 , RULL(0x10A020120), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_DBG_PPE1                                , RULL(0x10A020138), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_LCL_DBG_PPE2                                , RULL(0x10A020130), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_LCL_DBG_PPE                                 , RULL(0x10B010120), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_DBG_PPE1                                , RULL(0x10B010138), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_LCL_DBG_PPE2                                , RULL(0x10B010130), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_LCL_DBG_PPE                                 , RULL(0x10B020120), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_DBG_PPE1                                , RULL(0x10B020138), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_LCL_DBG_PPE2                                , RULL(0x10B020130), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_LCL_DBG_PPE                                 , RULL(0x10C010120), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_DBG_PPE1                                , RULL(0x10C010138), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_LCL_DBG_PPE2                                , RULL(0x10C010130), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_LCL_DBG_PPE                                 , RULL(0x10C020120), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_DBG_PPE1                                , RULL(0x10C020138), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_LCL_DBG_PPE2                                , RULL(0x10C020130), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_LCL_DBG_PPE                                 , RULL(0x10D010120), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_DBG_PPE1                                , RULL(0x10D010138), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_LCL_DBG_PPE2                                , RULL(0x10D010130), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_LCL_DBG_PPE                                 , RULL(0x10D020120), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_DBG_PPE1                                , RULL(0x10D020138), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_LCL_DBG_PPE2                                , RULL(0x10D020130), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_LCL_DBG_PPE                                , RULL(0x10E010120), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_DBG_PPE1                               , RULL(0x10E010138), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_LCL_DBG_PPE2                               , RULL(0x10E010130), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_LCL_DBG_PPE                                , RULL(0x10E020120), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_DBG_PPE1                               , RULL(0x10E020138), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_LCL_DBG_PPE2                               , RULL(0x10E020130), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_LCL_EIMR_PPE                                , RULL(0x109010020), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_LCL_EIMR_PPE1                               , RULL(0x109010038), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_LCL_EIMR_PPE2                               , RULL(0x109010030), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_LCL_EIMR_PPE                                , RULL(0x109020020), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_EIMR_PPE1                               , RULL(0x109020038), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_LCL_EIMR_PPE2                               , RULL(0x109020030), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_LCL_EIMR_PPE                                , RULL(0x10A010020), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_EIMR_PPE1                               , RULL(0x10A010038), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_LCL_EIMR_PPE2                               , RULL(0x10A010030), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_LCL_EIMR_PPE                                , RULL(0x10A020020), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_EIMR_PPE1                               , RULL(0x10A020038), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_LCL_EIMR_PPE2                               , RULL(0x10A020030), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_LCL_EIMR_PPE                                , RULL(0x10B010020), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_EIMR_PPE1                               , RULL(0x10B010038), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_LCL_EIMR_PPE2                               , RULL(0x10B010030), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_LCL_EIMR_PPE                                , RULL(0x10B020020), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_EIMR_PPE1                               , RULL(0x10B020038), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_LCL_EIMR_PPE2                               , RULL(0x10B020030), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_LCL_EIMR_PPE                                , RULL(0x10C010020), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_EIMR_PPE1                               , RULL(0x10C010038), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_LCL_EIMR_PPE2                               , RULL(0x10C010030), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_LCL_EIMR_PPE                                , RULL(0x10C020020), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_EIMR_PPE1                               , RULL(0x10C020038), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_LCL_EIMR_PPE2                               , RULL(0x10C020030), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_LCL_EIMR_PPE                                , RULL(0x10D010020), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_EIMR_PPE1                               , RULL(0x10D010038), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_LCL_EIMR_PPE2                               , RULL(0x10D010030), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_LCL_EIMR_PPE                                , RULL(0x10D020020), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_EIMR_PPE1                               , RULL(0x10D020038), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_LCL_EIMR_PPE2                               , RULL(0x10D020030), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_LCL_EIMR_PPE                               , RULL(0x10E010020), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_EIMR_PPE1                              , RULL(0x10E010038), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_LCL_EIMR_PPE2                              , RULL(0x10E010030), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_LCL_EIMR_PPE                               , RULL(0x10E020020), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_EIMR_PPE1                              , RULL(0x10E020038), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_LCL_EIMR_PPE2                              , RULL(0x10E020030), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_LCL_EINR_PPE                                , RULL(0x1090100A0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_EINR_PPE                                , RULL(0x1090200A0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_EINR_PPE                                , RULL(0x10A0100A0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_EINR_PPE                                , RULL(0x10A0200A0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_EINR_PPE                                , RULL(0x10B0100A0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_EINR_PPE                                , RULL(0x10B0200A0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_EINR_PPE                                , RULL(0x10C0100A0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_EINR_PPE                                , RULL(0x10C0200A0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_EINR_PPE                                , RULL(0x10D0100A0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_EINR_PPE                                , RULL(0x10D0200A0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_EINR_PPE                               , RULL(0x10E0100A0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_EINR_PPE                               , RULL(0x10E0200A0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_EIPR_PPE                                , RULL(0x109010040), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_LCL_EIPR_PPE1                               , RULL(0x109010058), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_LCL_EIPR_PPE2                               , RULL(0x109010050), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_LCL_EIPR_PPE                                , RULL(0x109020040), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_EIPR_PPE1                               , RULL(0x109020058), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_LCL_EIPR_PPE2                               , RULL(0x109020050), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_LCL_EIPR_PPE                                , RULL(0x10A010040), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_EIPR_PPE1                               , RULL(0x10A010058), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_LCL_EIPR_PPE2                               , RULL(0x10A010050), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_LCL_EIPR_PPE                                , RULL(0x10A020040), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_EIPR_PPE1                               , RULL(0x10A020058), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_LCL_EIPR_PPE2                               , RULL(0x10A020050), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_LCL_EIPR_PPE                                , RULL(0x10B010040), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_EIPR_PPE1                               , RULL(0x10B010058), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_LCL_EIPR_PPE2                               , RULL(0x10B010050), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_LCL_EIPR_PPE                                , RULL(0x10B020040), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_EIPR_PPE1                               , RULL(0x10B020058), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_LCL_EIPR_PPE2                               , RULL(0x10B020050), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_LCL_EIPR_PPE                                , RULL(0x10C010040), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_EIPR_PPE1                               , RULL(0x10C010058), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_LCL_EIPR_PPE2                               , RULL(0x10C010050), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_LCL_EIPR_PPE                                , RULL(0x10C020040), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_EIPR_PPE1                               , RULL(0x10C020058), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_LCL_EIPR_PPE2                               , RULL(0x10C020050), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_LCL_EIPR_PPE                                , RULL(0x10D010040), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_EIPR_PPE1                               , RULL(0x10D010058), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_LCL_EIPR_PPE2                               , RULL(0x10D010050), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_LCL_EIPR_PPE                                , RULL(0x10D020040), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_EIPR_PPE1                               , RULL(0x10D020058), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_LCL_EIPR_PPE2                               , RULL(0x10D020050), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_LCL_EIPR_PPE                               , RULL(0x10E010040), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_EIPR_PPE1                              , RULL(0x10E010058), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_LCL_EIPR_PPE2                              , RULL(0x10E010050), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_LCL_EIPR_PPE                               , RULL(0x10E020040), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_EIPR_PPE1                              , RULL(0x10E020058), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_LCL_EIPR_PPE2                              , RULL(0x10E020050), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_LCL_EISR_PPE                                , RULL(0x109010000), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_LCL_EISR_PPE1                               , RULL(0x109010018), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_LCL_EISR_PPE2                               , RULL(0x109010010), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_LCL_EISR_PPE                                , RULL(0x109020000), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_EISR_PPE1                               , RULL(0x109020018), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_LCL_EISR_PPE2                               , RULL(0x109020010), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_LCL_EISR_PPE                                , RULL(0x10A010000), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_EISR_PPE1                               , RULL(0x10A010018), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_LCL_EISR_PPE2                               , RULL(0x10A010010), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_LCL_EISR_PPE                                , RULL(0x10A020000), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_EISR_PPE1                               , RULL(0x10A020018), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_LCL_EISR_PPE2                               , RULL(0x10A020010), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_LCL_EISR_PPE                                , RULL(0x10B010000), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_EISR_PPE1                               , RULL(0x10B010018), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_LCL_EISR_PPE2                               , RULL(0x10B010010), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_LCL_EISR_PPE                                , RULL(0x10B020000), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_EISR_PPE1                               , RULL(0x10B020018), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_LCL_EISR_PPE2                               , RULL(0x10B020010), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_LCL_EISR_PPE                                , RULL(0x10C010000), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_EISR_PPE1                               , RULL(0x10C010018), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_LCL_EISR_PPE2                               , RULL(0x10C010010), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_LCL_EISR_PPE                                , RULL(0x10C020000), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_EISR_PPE1                               , RULL(0x10C020018), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_LCL_EISR_PPE2                               , RULL(0x10C020010), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_LCL_EISR_PPE                                , RULL(0x10D010000), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_EISR_PPE1                               , RULL(0x10D010018), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_LCL_EISR_PPE2                               , RULL(0x10D010010), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_LCL_EISR_PPE                                , RULL(0x10D020000), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_EISR_PPE1                               , RULL(0x10D020018), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_LCL_EISR_PPE2                               , RULL(0x10D020010), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_LCL_EISR_PPE                               , RULL(0x10E010000), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_EISR_PPE1                              , RULL(0x10E010018), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_LCL_EISR_PPE2                              , RULL(0x10E010010), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_LCL_EISR_PPE                               , RULL(0x10E020000), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_EISR_PPE1                              , RULL(0x10E020018), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_LCL_EISR_PPE2                              , RULL(0x10E020010), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_LCL_EISTR_PPE                               , RULL(0x109010080), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_EISTR_PPE                               , RULL(0x109020080), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_EISTR_PPE                               , RULL(0x10A010080), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_EISTR_PPE                               , RULL(0x10A020080), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_EISTR_PPE                               , RULL(0x10B010080), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_EISTR_PPE                               , RULL(0x10B020080), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_EISTR_PPE                               , RULL(0x10C010080), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_EISTR_PPE                               , RULL(0x10C020080), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_EISTR_PPE                               , RULL(0x10D010080), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_EISTR_PPE                               , RULL(0x10D020080), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_EISTR_PPE                              , RULL(0x10E010080), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_EISTR_PPE                              , RULL(0x10E020080), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_EITR_PPE                                , RULL(0x109010060), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_LCL_EITR_PPE1                               , RULL(0x109010078), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_LCL_EITR_PPE2                               , RULL(0x109010070), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_LCL_EITR_PPE                                , RULL(0x109020060), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_EITR_PPE1                               , RULL(0x109020078), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_LCL_EITR_PPE2                               , RULL(0x109020070), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_LCL_EITR_PPE                                , RULL(0x10A010060), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_EITR_PPE1                               , RULL(0x10A010078), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_LCL_EITR_PPE2                               , RULL(0x10A010070), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_LCL_EITR_PPE                                , RULL(0x10A020060), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_EITR_PPE1                               , RULL(0x10A020078), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_LCL_EITR_PPE2                               , RULL(0x10A020070), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_LCL_EITR_PPE                                , RULL(0x10B010060), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_EITR_PPE1                               , RULL(0x10B010078), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_LCL_EITR_PPE2                               , RULL(0x10B010070), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_LCL_EITR_PPE                                , RULL(0x10B020060), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_EITR_PPE1                               , RULL(0x10B020078), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_LCL_EITR_PPE2                               , RULL(0x10B020070), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_LCL_EITR_PPE                                , RULL(0x10C010060), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_EITR_PPE1                               , RULL(0x10C010078), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_LCL_EITR_PPE2                               , RULL(0x10C010070), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_LCL_EITR_PPE                                , RULL(0x10C020060), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_EITR_PPE1                               , RULL(0x10C020078), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_LCL_EITR_PPE2                               , RULL(0x10C020070), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_LCL_EITR_PPE                                , RULL(0x10D010060), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_EITR_PPE1                               , RULL(0x10D010078), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_LCL_EITR_PPE2                               , RULL(0x10D010070), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_LCL_EITR_PPE                                , RULL(0x10D020060), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_EITR_PPE1                               , RULL(0x10D020078), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_LCL_EITR_PPE2                               , RULL(0x10D020070), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_LCL_EITR_PPE                               , RULL(0x10E010060), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_EITR_PPE1                              , RULL(0x10E010078), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_LCL_EITR_PPE2                              , RULL(0x10E010070), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_LCL_EITR_PPE                               , RULL(0x10E020060), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_EITR_PPE1                              , RULL(0x10E020078), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_LCL_EITR_PPE2                              , RULL(0x10E020070), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_LCL_ICCR_PPE                                , RULL(0x109010700), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_LCL_ICCR_PPE1                               , RULL(0x109010718), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_LCL_ICCR_PPE2                               , RULL(0x109010710), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_LCL_ICCR_PPE                                , RULL(0x109020700), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_ICCR_PPE1                               , RULL(0x109020718), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_LCL_ICCR_PPE2                               , RULL(0x109020710), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_LCL_ICCR_PPE                                , RULL(0x10A010700), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_ICCR_PPE1                               , RULL(0x10A010718), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_LCL_ICCR_PPE2                               , RULL(0x10A010710), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_LCL_ICCR_PPE                                , RULL(0x10A020700), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_ICCR_PPE1                               , RULL(0x10A020718), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_LCL_ICCR_PPE2                               , RULL(0x10A020710), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_LCL_ICCR_PPE                                , RULL(0x10B010700), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_ICCR_PPE1                               , RULL(0x10B010718), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_LCL_ICCR_PPE2                               , RULL(0x10B010710), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_LCL_ICCR_PPE                                , RULL(0x10B020700), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_ICCR_PPE1                               , RULL(0x10B020718), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_LCL_ICCR_PPE2                               , RULL(0x10B020710), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_LCL_ICCR_PPE                                , RULL(0x10C010700), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_ICCR_PPE1                               , RULL(0x10C010718), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_LCL_ICCR_PPE2                               , RULL(0x10C010710), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_LCL_ICCR_PPE                                , RULL(0x10C020700), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_ICCR_PPE1                               , RULL(0x10C020718), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_LCL_ICCR_PPE2                               , RULL(0x10C020710), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_LCL_ICCR_PPE                                , RULL(0x10D010700), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_ICCR_PPE1                               , RULL(0x10D010718), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_LCL_ICCR_PPE2                               , RULL(0x10D010710), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_LCL_ICCR_PPE                                , RULL(0x10D020700), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_ICCR_PPE1                               , RULL(0x10D020718), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_LCL_ICCR_PPE2                               , RULL(0x10D020710), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_LCL_ICCR_PPE                               , RULL(0x10E010700), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_ICCR_PPE1                              , RULL(0x10E010718), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_LCL_ICCR_PPE2                              , RULL(0x10E010710), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_LCL_ICCR_PPE                               , RULL(0x10E020700), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_ICCR_PPE1                              , RULL(0x10E020718), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_LCL_ICCR_PPE2                              , RULL(0x10E020710), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_LCL_ICRR_PPE                                , RULL(0x109010740), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_ICRR_PPE                                , RULL(0x109020740), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_ICRR_PPE                                , RULL(0x10A010740), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_ICRR_PPE                                , RULL(0x10A020740), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_ICRR_PPE                                , RULL(0x10B010740), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_ICRR_PPE                                , RULL(0x10B020740), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_ICRR_PPE                                , RULL(0x10C010740), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_ICRR_PPE                                , RULL(0x10C020740), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_ICRR_PPE                                , RULL(0x10D010740), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_ICRR_PPE                                , RULL(0x10D020740), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_ICRR_PPE                               , RULL(0x10E010740), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_ICRR_PPE                               , RULL(0x10E020740), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_ICSR_PPE                                , RULL(0x109010720), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_ICSR_PPE                                , RULL(0x109020720), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_ICSR_PPE                                , RULL(0x10A010720), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_ICSR_PPE                                , RULL(0x10A020720), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_ICSR_PPE                                , RULL(0x10B010720), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_ICSR_PPE                                , RULL(0x10B020720), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_ICSR_PPE                                , RULL(0x10C010720), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_ICSR_PPE                                , RULL(0x10C020720), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_ICSR_PPE                                , RULL(0x10D010720), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_ICSR_PPE                                , RULL(0x10D020720), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_ICSR_PPE                               , RULL(0x10E010720), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_ICSR_PPE                               , RULL(0x10E020720), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_LMCR_PPE                                , RULL(0x1090101A0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_LMCR_PPE                                , RULL(0x1090201A0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_LMCR_PPE                                , RULL(0x10A0101A0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_LMCR_PPE                                , RULL(0x10A0201A0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_LMCR_PPE                                , RULL(0x10B0101A0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_LMCR_PPE                                , RULL(0x10B0201A0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_LMCR_PPE                                , RULL(0x10C0101A0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_LMCR_PPE                                , RULL(0x10C0201A0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_LMCR_PPE                                , RULL(0x10D0101A0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_LMCR_PPE                                , RULL(0x10D0201A0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_LMCR_PPE                               , RULL(0x10E0101A0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_LMCR_PPE                               , RULL(0x10E0201A0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_PECESR0_PPE                             , RULL(0x109010280), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_PECESR0_PPE                             , RULL(0x109020280), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_PECESR0_PPE                             , RULL(0x10A010280), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_PECESR0_PPE                             , RULL(0x10A020280), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_PECESR0_PPE                             , RULL(0x10B010280), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_PECESR0_PPE                             , RULL(0x10B020280), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_PECESR0_PPE                             , RULL(0x10C010280), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_PECESR0_PPE                             , RULL(0x10C020280), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_PECESR0_PPE                             , RULL(0x10D010280), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_PECESR0_PPE                             , RULL(0x10D020280), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_PECESR0_PPE                            , RULL(0x10E010280), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_PECESR0_PPE                            , RULL(0x10E020280), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_PECESR1_PPE                             , RULL(0x1090102A0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_PECESR1_PPE                             , RULL(0x1090202A0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_PECESR1_PPE                             , RULL(0x10A0102A0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_PECESR1_PPE                             , RULL(0x10A0202A0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_PECESR1_PPE                             , RULL(0x10B0102A0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_PECESR1_PPE                             , RULL(0x10B0202A0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_PECESR1_PPE                             , RULL(0x10C0102A0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_PECESR1_PPE                             , RULL(0x10C0202A0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_PECESR1_PPE                             , RULL(0x10D0102A0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_PECESR1_PPE                             , RULL(0x10D0202A0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_PECESR1_PPE                            , RULL(0x10E0102A0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_PECESR1_PPE                            , RULL(0x10E0202A0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_SISR_PPE                                , RULL(0x109010520), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_SISR_PPE                                , RULL(0x109020520), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_SISR_PPE                                , RULL(0x10A010520), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_SISR_PPE                                , RULL(0x10A020520), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_SISR_PPE                                , RULL(0x10B010520), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_SISR_PPE                                , RULL(0x10B020520), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_SISR_PPE                                , RULL(0x10C010520), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_SISR_PPE                                , RULL(0x10C020520), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_SISR_PPE                                , RULL(0x10D010520), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_SISR_PPE                                , RULL(0x10D020520), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_SISR_PPE                               , RULL(0x10E010520), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_SISR_PPE                               , RULL(0x10E020520), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_LCL_TSEL_PPE                                , RULL(0x109010100), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_LCL_TSEL_PPE                                , RULL(0x109020100), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_LCL_TSEL_PPE                                , RULL(0x10A010100), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_LCL_TSEL_PPE                                , RULL(0x10A020100), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_LCL_TSEL_PPE                                , RULL(0x10B010100), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_LCL_TSEL_PPE                                , RULL(0x10B020100), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_LCL_TSEL_PPE                                , RULL(0x10C010100), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_LCL_TSEL_PPE                                , RULL(0x10C020100), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_LCL_TSEL_PPE                                , RULL(0x10D010100), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_LCL_TSEL_PPE                                , RULL(0x10D020100), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_LCL_TSEL_PPE                               , RULL(0x10E010100), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_LCL_TSEL_PPE                               , RULL(0x10E020100), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_AFSR_PPE                               , RULL(0x109010160), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_AFSR_PPE                               , RULL(0x109020160), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_AFSR_PPE                               , RULL(0x10A010160), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_AFSR_PPE                               , RULL(0x10A020160), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_AFSR_PPE                               , RULL(0x10B010160), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_AFSR_PPE                               , RULL(0x10B020160), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_AFSR_PPE                               , RULL(0x10C010160), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_AFSR_PPE                               , RULL(0x10C020160), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_AFSR_PPE                               , RULL(0x10D010160), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_AFSR_PPE                               , RULL(0x10D020160), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_AFSR_PPE                              , RULL(0x10E010160), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_AFSR_PPE                              , RULL(0x10E020160), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_AFTR_PPE                               , RULL(0x109010180), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_AFTR_PPE                               , RULL(0x109020180), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_AFTR_PPE                               , RULL(0x10A010180), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_AFTR_PPE                               , RULL(0x10A020180), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_AFTR_PPE                               , RULL(0x10B010180), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_AFTR_PPE                               , RULL(0x10B020180), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_AFTR_PPE                               , RULL(0x10C010180), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_AFTR_PPE                               , RULL(0x10C020180), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_AFTR_PPE                               , RULL(0x10D010180), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_AFTR_PPE                               , RULL(0x10D020180), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_AFTR_PPE                              , RULL(0x10E010180), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_AFTR_PPE                              , RULL(0x10E020180), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_BCECSR_PPE                             , RULL(0x1090101F0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_BCECSR_PPE                             , RULL(0x1090201F0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_BCECSR_PPE                             , RULL(0x10A0101F0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_BCECSR_PPE                             , RULL(0x10A0201F0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_BCECSR_PPE                             , RULL(0x10B0101F0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_BCECSR_PPE                             , RULL(0x10B0201F0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_BCECSR_PPE                             , RULL(0x10C0101F0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_BCECSR_PPE                             , RULL(0x10C0201F0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_BCECSR_PPE                             , RULL(0x10D0101F0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_BCECSR_PPE                             , RULL(0x10D0201F0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_BCECSR_PPE                            , RULL(0x10E0101F0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_BCECSR_PPE                            , RULL(0x10E0201F0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_FLAGS_PPE                              , RULL(0x109010400), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_SCOM_FLAGS_PPE1                             , RULL(0x109010418), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_SCOM_FLAGS_PPE2                             , RULL(0x109010410), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_SCOM_FLAGS_PPE                              , RULL(0x109020400), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_FLAGS_PPE1                             , RULL(0x109020418), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_SCOM_FLAGS_PPE2                             , RULL(0x109020410), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_SCOM_FLAGS_PPE                              , RULL(0x10A010400), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_FLAGS_PPE1                             , RULL(0x10A010418), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_SCOM_FLAGS_PPE2                             , RULL(0x10A010410), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_SCOM_FLAGS_PPE                              , RULL(0x10A020400), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_FLAGS_PPE1                             , RULL(0x10A020418), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_SCOM_FLAGS_PPE2                             , RULL(0x10A020410), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_SCOM_FLAGS_PPE                              , RULL(0x10B010400), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_FLAGS_PPE1                             , RULL(0x10B010418), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_SCOM_FLAGS_PPE2                             , RULL(0x10B010410), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_SCOM_FLAGS_PPE                              , RULL(0x10B020400), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_FLAGS_PPE1                             , RULL(0x10B020418), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_SCOM_FLAGS_PPE2                             , RULL(0x10B020410), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_SCOM_FLAGS_PPE                              , RULL(0x10C010400), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_FLAGS_PPE1                             , RULL(0x10C010418), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_SCOM_FLAGS_PPE2                             , RULL(0x10C010410), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_SCOM_FLAGS_PPE                              , RULL(0x10C020400), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_FLAGS_PPE1                             , RULL(0x10C020418), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_SCOM_FLAGS_PPE2                             , RULL(0x10C020410), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_SCOM_FLAGS_PPE                              , RULL(0x10D010400), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_FLAGS_PPE1                             , RULL(0x10D010418), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_SCOM_FLAGS_PPE2                             , RULL(0x10D010410), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_SCOM_FLAGS_PPE                              , RULL(0x10D020400), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_FLAGS_PPE1                             , RULL(0x10D020418), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_SCOM_FLAGS_PPE2                             , RULL(0x10D020410), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_SCOM_FLAGS_PPE                             , RULL(0x10E010400), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_FLAGS_PPE1                            , RULL(0x10E010418), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_SCOM_FLAGS_PPE2                            , RULL(0x10E010410), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_SCOM_FLAGS_PPE                             , RULL(0x10E020400), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_FLAGS_PPE1                            , RULL(0x10E020418), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_SCOM_FLAGS_PPE2                            , RULL(0x10E020410), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_SCOM_PMCRS0_PPE                             , RULL(0x109010240), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PMCRS0_PPE                             , RULL(0x109020240), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PMCRS0_PPE                             , RULL(0x10A010240), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PMCRS0_PPE                             , RULL(0x10A020240), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PMCRS0_PPE                             , RULL(0x10B010240), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PMCRS0_PPE                             , RULL(0x10B020240), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PMCRS0_PPE                             , RULL(0x10C010240), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PMCRS0_PPE                             , RULL(0x10C020240), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PMCRS0_PPE                             , RULL(0x10D010240), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PMCRS0_PPE                             , RULL(0x10D020240), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PMCRS0_PPE                            , RULL(0x10E010240), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PMCRS0_PPE                            , RULL(0x10E020240), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PMCRS1_PPE                             , RULL(0x109010260), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PMCRS1_PPE                             , RULL(0x109020260), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PMCRS1_PPE                             , RULL(0x10A010260), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PMCRS1_PPE                             , RULL(0x10A020260), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PMCRS1_PPE                             , RULL(0x10B010260), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PMCRS1_PPE                             , RULL(0x10B020260), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PMCRS1_PPE                             , RULL(0x10C010260), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PMCRS1_PPE                             , RULL(0x10C020260), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PMCRS1_PPE                             , RULL(0x10D010260), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PMCRS1_PPE                             , RULL(0x10D020260), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PMCRS1_PPE                            , RULL(0x10E010260), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PMCRS1_PPE                            , RULL(0x10E020260), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PMSRS0_PPE                             , RULL(0x109010200), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PMSRS0_PPE                             , RULL(0x109020200), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PMSRS0_PPE                             , RULL(0x10A010200), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PMSRS0_PPE                             , RULL(0x10A020200), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PMSRS0_PPE                             , RULL(0x10B010200), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PMSRS0_PPE                             , RULL(0x10B020200), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PMSRS0_PPE                             , RULL(0x10C010200), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PMSRS0_PPE                             , RULL(0x10C020200), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PMSRS0_PPE                             , RULL(0x10D010200), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PMSRS0_PPE                             , RULL(0x10D020200), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PMSRS0_PPE                            , RULL(0x10E010200), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PMSRS0_PPE                            , RULL(0x10E020200), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PMSRS1_PPE                             , RULL(0x109010220), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PMSRS1_PPE                             , RULL(0x109020220), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PMSRS1_PPE                             , RULL(0x10A010220), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PMSRS1_PPE                             , RULL(0x10A020220), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PMSRS1_PPE                             , RULL(0x10B010220), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PMSRS1_PPE                             , RULL(0x10B020220), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PMSRS1_PPE                             , RULL(0x10C010220), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PMSRS1_PPE                             , RULL(0x10C020220), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PMSRS1_PPE                             , RULL(0x10D010220), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PMSRS1_PPE                             , RULL(0x10D020220), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PMSRS1_PPE                            , RULL(0x10E010220), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PMSRS1_PPE                            , RULL(0x10E020220), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS00_PPE                            , RULL(0x109010300), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS00_PPE                            , RULL(0x109020300), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS00_PPE                            , RULL(0x10A010300), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS00_PPE                            , RULL(0x10A020300), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS00_PPE                            , RULL(0x10B010300), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS00_PPE                            , RULL(0x10B020300), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS00_PPE                            , RULL(0x10C010300), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS00_PPE                            , RULL(0x10C020300), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS00_PPE                            , RULL(0x10D010300), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS00_PPE                            , RULL(0x10D020300), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS00_PPE                           , RULL(0x10E010300), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS00_PPE                           , RULL(0x10E020300), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS01_PPE                            , RULL(0x109010320), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS01_PPE                            , RULL(0x109020320), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS01_PPE                            , RULL(0x10A010320), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS01_PPE                            , RULL(0x10A020320), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS01_PPE                            , RULL(0x10B010320), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS01_PPE                            , RULL(0x10B020320), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS01_PPE                            , RULL(0x10C010320), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS01_PPE                            , RULL(0x10C020320), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS01_PPE                            , RULL(0x10D010320), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS01_PPE                            , RULL(0x10D020320), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS01_PPE                           , RULL(0x10E010320), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS01_PPE                           , RULL(0x10E020320), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS02_PPE                            , RULL(0x109010340), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS02_PPE                            , RULL(0x109020340), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS02_PPE                            , RULL(0x10A010340), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS02_PPE                            , RULL(0x10A020340), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS02_PPE                            , RULL(0x10B010340), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS02_PPE                            , RULL(0x10B020340), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS02_PPE                            , RULL(0x10C010340), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS02_PPE                            , RULL(0x10C020340), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS02_PPE                            , RULL(0x10D010340), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS02_PPE                            , RULL(0x10D020340), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS02_PPE                           , RULL(0x10E010340), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS02_PPE                           , RULL(0x10E020340), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS03_PPE                            , RULL(0x109010360), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS03_PPE                            , RULL(0x109020360), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS03_PPE                            , RULL(0x10A010360), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS03_PPE                            , RULL(0x10A020360), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS03_PPE                            , RULL(0x10B010360), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS03_PPE                            , RULL(0x10B020360), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS03_PPE                            , RULL(0x10C010360), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS03_PPE                            , RULL(0x10C020360), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS03_PPE                            , RULL(0x10D010360), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS03_PPE                            , RULL(0x10D020360), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS03_PPE                           , RULL(0x10E010360), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS03_PPE                           , RULL(0x10E020360), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS10_PPE                            , RULL(0x109010380), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS10_PPE                            , RULL(0x109020380), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS10_PPE                            , RULL(0x10A010380), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS10_PPE                            , RULL(0x10A020380), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS10_PPE                            , RULL(0x10B010380), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS10_PPE                            , RULL(0x10B020380), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS10_PPE                            , RULL(0x10C010380), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS10_PPE                            , RULL(0x10C020380), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS10_PPE                            , RULL(0x10D010380), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS10_PPE                            , RULL(0x10D020380), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS10_PPE                           , RULL(0x10E010380), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS10_PPE                           , RULL(0x10E020380), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS11_PPE                            , RULL(0x1090103A0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS11_PPE                            , RULL(0x1090203A0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS11_PPE                            , RULL(0x10A0103A0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS11_PPE                            , RULL(0x10A0203A0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS11_PPE                            , RULL(0x10B0103A0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS11_PPE                            , RULL(0x10B0203A0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS11_PPE                            , RULL(0x10C0103A0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS11_PPE                            , RULL(0x10C0203A0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS11_PPE                            , RULL(0x10D0103A0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS11_PPE                            , RULL(0x10D0203A0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS11_PPE                           , RULL(0x10E0103A0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS11_PPE                           , RULL(0x10E0203A0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS12_PPE                            , RULL(0x1090103C0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS12_PPE                            , RULL(0x1090203C0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS12_PPE                            , RULL(0x10A0103C0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS12_PPE                            , RULL(0x10A0203C0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS12_PPE                            , RULL(0x10B0103C0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS12_PPE                            , RULL(0x10B0203C0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS12_PPE                            , RULL(0x10C0103C0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS12_PPE                            , RULL(0x10C0203C0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS12_PPE                            , RULL(0x10D0103C0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS12_PPE                            , RULL(0x10D0203C0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS12_PPE                           , RULL(0x10E0103C0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS12_PPE                           , RULL(0x10E0203C0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_PSCRS13_PPE                            , RULL(0x1090103E0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_PSCRS13_PPE                            , RULL(0x1090203E0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_PSCRS13_PPE                            , RULL(0x10A0103E0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_PSCRS13_PPE                            , RULL(0x10A0203E0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_PSCRS13_PPE                            , RULL(0x10B0103E0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_PSCRS13_PPE                            , RULL(0x10B0203E0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_PSCRS13_PPE                            , RULL(0x10C0103E0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_PSCRS13_PPE                            , RULL(0x10C0203E0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_PSCRS13_PPE                            , RULL(0x10D0103E0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_PSCRS13_PPE                            , RULL(0x10D0203E0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_PSCRS13_PPE                           , RULL(0x10E0103E0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_PSCRS13_PPE                           , RULL(0x10E0203E0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_QFMR_PPE                               , RULL(0x109010140), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_QFMR_PPE                               , RULL(0x109020140), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_QFMR_PPE                               , RULL(0x10A010140), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_QFMR_PPE                               , RULL(0x10A020140), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_QFMR_PPE                               , RULL(0x10B010140), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_QFMR_PPE                               , RULL(0x10B020140), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_QFMR_PPE                               , RULL(0x10C010140), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_QFMR_PPE                               , RULL(0x10C020140), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_QFMR_PPE                               , RULL(0x10D010140), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_QFMR_PPE                               , RULL(0x10D020140), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_QFMR_PPE                              , RULL(0x10E010140), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_QFMR_PPE                              , RULL(0x10E020140), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_SICR_PPE                               , RULL(0x109010500), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME0_CME_SCOM_SICR_PPE1                              , RULL(0x109010518), SH_UNT_PU_CME0  ,
       SH_ACS_PPE1      );
REG64( PU_CME0_CME_SCOM_SICR_PPE2                              , RULL(0x109010510), SH_UNT_PU_CME0  ,
       SH_ACS_PPE2      );
REG64( PU_CME1_CME_SCOM_SICR_PPE                               , RULL(0x109020500), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_SICR_PPE1                              , RULL(0x109020518), SH_UNT_PU_CME1  ,
       SH_ACS_PPE1      );
REG64( PU_CME1_CME_SCOM_SICR_PPE2                              , RULL(0x109020510), SH_UNT_PU_CME1  ,
       SH_ACS_PPE2      );
REG64( PU_CME2_CME_SCOM_SICR_PPE                               , RULL(0x10A010500), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_SICR_PPE1                              , RULL(0x10A010518), SH_UNT_PU_CME2  ,
       SH_ACS_PPE1      );
REG64( PU_CME2_CME_SCOM_SICR_PPE2                              , RULL(0x10A010510), SH_UNT_PU_CME2  ,
       SH_ACS_PPE2      );
REG64( PU_CME3_CME_SCOM_SICR_PPE                               , RULL(0x10A020500), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_SICR_PPE1                              , RULL(0x10A020518), SH_UNT_PU_CME3  ,
       SH_ACS_PPE1      );
REG64( PU_CME3_CME_SCOM_SICR_PPE2                              , RULL(0x10A020510), SH_UNT_PU_CME3  ,
       SH_ACS_PPE2      );
REG64( PU_CME4_CME_SCOM_SICR_PPE                               , RULL(0x10B010500), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_SICR_PPE1                              , RULL(0x10B010518), SH_UNT_PU_CME4  ,
       SH_ACS_PPE1      );
REG64( PU_CME4_CME_SCOM_SICR_PPE2                              , RULL(0x10B010510), SH_UNT_PU_CME4  ,
       SH_ACS_PPE2      );
REG64( PU_CME5_CME_SCOM_SICR_PPE                               , RULL(0x10B020500), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_SICR_PPE1                              , RULL(0x10B020518), SH_UNT_PU_CME5  ,
       SH_ACS_PPE1      );
REG64( PU_CME5_CME_SCOM_SICR_PPE2                              , RULL(0x10B020510), SH_UNT_PU_CME5  ,
       SH_ACS_PPE2      );
REG64( PU_CME6_CME_SCOM_SICR_PPE                               , RULL(0x10C010500), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_SICR_PPE1                              , RULL(0x10C010518), SH_UNT_PU_CME6  ,
       SH_ACS_PPE1      );
REG64( PU_CME6_CME_SCOM_SICR_PPE2                              , RULL(0x10C010510), SH_UNT_PU_CME6  ,
       SH_ACS_PPE2      );
REG64( PU_CME7_CME_SCOM_SICR_PPE                               , RULL(0x10C020500), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_SICR_PPE1                              , RULL(0x10C020518), SH_UNT_PU_CME7  ,
       SH_ACS_PPE1      );
REG64( PU_CME7_CME_SCOM_SICR_PPE2                              , RULL(0x10C020510), SH_UNT_PU_CME7  ,
       SH_ACS_PPE2      );
REG64( PU_CME8_CME_SCOM_SICR_PPE                               , RULL(0x10D010500), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_SICR_PPE1                              , RULL(0x10D010518), SH_UNT_PU_CME8  ,
       SH_ACS_PPE1      );
REG64( PU_CME8_CME_SCOM_SICR_PPE2                              , RULL(0x10D010510), SH_UNT_PU_CME8  ,
       SH_ACS_PPE2      );
REG64( PU_CME9_CME_SCOM_SICR_PPE                               , RULL(0x10D020500), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_SICR_PPE1                              , RULL(0x10D020518), SH_UNT_PU_CME9  ,
       SH_ACS_PPE1      );
REG64( PU_CME9_CME_SCOM_SICR_PPE2                              , RULL(0x10D020510), SH_UNT_PU_CME9  ,
       SH_ACS_PPE2      );
REG64( PU_CME10_CME_SCOM_SICR_PPE                              , RULL(0x10E010500), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_SICR_PPE1                             , RULL(0x10E010518), SH_UNT_PU_CME10 ,
       SH_ACS_PPE1      );
REG64( PU_CME10_CME_SCOM_SICR_PPE2                             , RULL(0x10E010510), SH_UNT_PU_CME10 ,
       SH_ACS_PPE2      );
REG64( PU_CME11_CME_SCOM_SICR_PPE                              , RULL(0x10E020500), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_SICR_PPE1                             , RULL(0x10E020518), SH_UNT_PU_CME11 ,
       SH_ACS_PPE1      );
REG64( PU_CME11_CME_SCOM_SICR_PPE2                             , RULL(0x10E020510), SH_UNT_PU_CME11 ,
       SH_ACS_PPE2      );

REG64( PU_CME0_CME_SCOM_SRTCH0_PPE                             , RULL(0x109010420), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_SRTCH0_PPE                             , RULL(0x109020420), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_SRTCH0_PPE                             , RULL(0x10A010420), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_SRTCH0_PPE                             , RULL(0x10A020420), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_SRTCH0_PPE                             , RULL(0x10B010420), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_SRTCH0_PPE                             , RULL(0x10B020420), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_SRTCH0_PPE                             , RULL(0x10C010420), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_SRTCH0_PPE                             , RULL(0x10C020420), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_SRTCH0_PPE                             , RULL(0x10D010420), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_SRTCH0_PPE                             , RULL(0x10D020420), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_SRTCH0_PPE                            , RULL(0x10E010420), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_SRTCH0_PPE                            , RULL(0x10E020420), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_SRTCH1_PPE                             , RULL(0x109010440), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_SRTCH1_PPE                             , RULL(0x109020440), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_SRTCH1_PPE                             , RULL(0x10A010440), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_SRTCH1_PPE                             , RULL(0x10A020440), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_SRTCH1_PPE                             , RULL(0x10B010440), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_SRTCH1_PPE                             , RULL(0x10B020440), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_SRTCH1_PPE                             , RULL(0x10C010440), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_SRTCH1_PPE                             , RULL(0x10C020440), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_SRTCH1_PPE                             , RULL(0x10D010440), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_SRTCH1_PPE                             , RULL(0x10D020440), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_SRTCH1_PPE                            , RULL(0x10E010440), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_SRTCH1_PPE                            , RULL(0x10E020440), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_VDSR_PPE                               , RULL(0x109010640), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_VDSR_PPE                               , RULL(0x109020640), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_VDSR_PPE                               , RULL(0x10A010640), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_VDSR_PPE                               , RULL(0x10A020640), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_VDSR_PPE                               , RULL(0x10B010640), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_VDSR_PPE                               , RULL(0x10B020640), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_VDSR_PPE                               , RULL(0x10C010640), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_VDSR_PPE                               , RULL(0x10C020640), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_VDSR_PPE                               , RULL(0x10D010640), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_VDSR_PPE                               , RULL(0x10D020640), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_VDSR_PPE                              , RULL(0x10E010640), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_VDSR_PPE                              , RULL(0x10E020640), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_VTSR0_PPE                              , RULL(0x109010600), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_VTSR0_PPE                              , RULL(0x109020600), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_VTSR0_PPE                              , RULL(0x10A010600), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_VTSR0_PPE                              , RULL(0x10A020600), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_VTSR0_PPE                              , RULL(0x10B010600), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_VTSR0_PPE                              , RULL(0x10B020600), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_VTSR0_PPE                              , RULL(0x10C010600), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_VTSR0_PPE                              , RULL(0x10C020600), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_VTSR0_PPE                              , RULL(0x10D010600), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_VTSR0_PPE                              , RULL(0x10D020600), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_VTSR0_PPE                             , RULL(0x10E010600), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_VTSR0_PPE                             , RULL(0x10E020600), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_VTSR1_PPE                              , RULL(0x109010620), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_VTSR1_PPE                              , RULL(0x109020620), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_VTSR1_PPE                              , RULL(0x10A010620), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_VTSR1_PPE                              , RULL(0x10A020620), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_VTSR1_PPE                              , RULL(0x10B010620), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_VTSR1_PPE                              , RULL(0x10B020620), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_VTSR1_PPE                              , RULL(0x10C010620), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_VTSR1_PPE                              , RULL(0x10C020620), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_VTSR1_PPE                              , RULL(0x10D010620), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_VTSR1_PPE                              , RULL(0x10D020620), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_VTSR1_PPE                             , RULL(0x10E010620), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_VTSR1_PPE                             , RULL(0x10E020620), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x109010580), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x109020580), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10A010580), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10A020580), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10B010580), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10B020580), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10C010580), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10C020580), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10D010580), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_XIPCBMD0_PPE                           , RULL(0x10D020580), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_XIPCBMD0_PPE                          , RULL(0x10E010580), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_XIPCBMD0_PPE                          , RULL(0x10E020580), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x1090105A0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x1090205A0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10A0105A0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10A0205A0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10B0105A0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10B0205A0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10C0105A0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10C0205A0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10D0105A0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_XIPCBMD1_PPE                           , RULL(0x10D0205A0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_XIPCBMD1_PPE                          , RULL(0x10E0105A0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_XIPCBMD1_PPE                          , RULL(0x10E0205A0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x1090105C0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x1090205C0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10A0105C0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10A0205C0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10B0105C0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10B0205C0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10C0105C0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10C0205C0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10D0105C0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_XIPCBMI0_PPE                           , RULL(0x10D0205C0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_XIPCBMI0_PPE                          , RULL(0x10E0105C0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_XIPCBMI0_PPE                          , RULL(0x10E0205C0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_CME0_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x1090105E0), SH_UNT_PU_CME0  ,
       SH_ACS_PPE       );
REG64( PU_CME1_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x1090205E0), SH_UNT_PU_CME1  ,
       SH_ACS_PPE       );
REG64( PU_CME2_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10A0105E0), SH_UNT_PU_CME2  ,
       SH_ACS_PPE       );
REG64( PU_CME3_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10A0205E0), SH_UNT_PU_CME3  ,
       SH_ACS_PPE       );
REG64( PU_CME4_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10B0105E0), SH_UNT_PU_CME4  ,
       SH_ACS_PPE       );
REG64( PU_CME5_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10B0205E0), SH_UNT_PU_CME5  ,
       SH_ACS_PPE       );
REG64( PU_CME6_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10C0105E0), SH_UNT_PU_CME6  ,
       SH_ACS_PPE       );
REG64( PU_CME7_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10C0205E0), SH_UNT_PU_CME7  ,
       SH_ACS_PPE       );
REG64( PU_CME8_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10D0105E0), SH_UNT_PU_CME8  ,
       SH_ACS_PPE       );
REG64( PU_CME9_CME_SCOM_XIPCBMI1_PPE                           , RULL(0x10D0205E0), SH_UNT_PU_CME9  ,
       SH_ACS_PPE       );
REG64( PU_CME10_CME_SCOM_XIPCBMI1_PPE                          , RULL(0x10E0105E0), SH_UNT_PU_CME10 ,
       SH_ACS_PPE       );
REG64( PU_CME11_CME_SCOM_XIPCBMI1_PPE                          , RULL(0x10E0205E0), SH_UNT_PU_CME11 ,
       SH_ACS_PPE       );

REG64( PU_COMMAND_REGISTER                                     , RULL(0x00010000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_COMMAND_REGISTER_B                                   , RULL(0x000A0005), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_COMMAND_REGISTER_C                                   , RULL(0x000A1005), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_COMMAND_REGISTER_D                                   , RULL(0x000A2005), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_COMMAND_REGISTER_E                                   , RULL(0x000A3005), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_CONFIG0                                     , RULL(0x05011080), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CONFIG0                                     , RULL(0x05011180), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CONFIG0                                     , RULL(0x05011280), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CONFIG0                                     , RULL(0x05011000), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CONFIG0                                     , RULL(0x05011020), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CONFIG0                                     , RULL(0x05011040), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CONFIG0                                     , RULL(0x05011060), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CONFIG0                                     , RULL(0x05011100), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CONFIG0                                     , RULL(0x05011120), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CONFIG0                                     , RULL(0x05011140), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CONFIG0                                     , RULL(0x05011160), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CONFIG0                                     , RULL(0x05011200), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CONFIG0                                     , RULL(0x05011220), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CONFIG0                                     , RULL(0x05011240), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CONFIG0                                     , RULL(0x05011260), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CONFIG1                                              , RULL(0x050110D8), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CONFIG1                                            , RULL(0x050110D8), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CONFIG1                                            , RULL(0x050110F8), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CONFIG1                                            , RULL(0x050111D8), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CONFIG1                                            , RULL(0x050111F8), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_CONFIG1                                     , RULL(0x05011081), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_CONFIG1                                         , RULL(0x050110A1), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_CONFIG1                                         , RULL(0x050111A1), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CONFIG1                                     , RULL(0x05011181), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CONFIG1                                     , RULL(0x05011281), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CONFIG1                                         , RULL(0x050112A1), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_CONFIG1                                     , RULL(0x05011001), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CONFIG1                                     , RULL(0x05011021), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CONFIG1                                     , RULL(0x05011041), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CONFIG1                                     , RULL(0x05011061), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CONFIG1                                     , RULL(0x05011101), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CONFIG1                                     , RULL(0x05011121), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CONFIG1                                     , RULL(0x05011141), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CONFIG1                                     , RULL(0x05011161), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CONFIG1                                    , RULL(0x050112D8), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CONFIG1                                    , RULL(0x050112F8), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CONFIG1                                     , RULL(0x05011201), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CONFIG1                                     , RULL(0x05011221), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CONFIG1                                     , RULL(0x05011241), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CONFIG1                                     , RULL(0x05011261), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_CONFIG2                                              , RULL(0x050110C0), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CONFIG2                                            , RULL(0x050110C0), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CONFIG2                                            , RULL(0x050110E0), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CONFIG2                                            , RULL(0x050111C0), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CONFIG2                                            , RULL(0x050111E0), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_CONFIG2                                     , RULL(0x05011082), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CONFIG2                                     , RULL(0x05011182), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CONFIG2                                     , RULL(0x05011282), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CONFIG2                                    , RULL(0x050112C0), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CONFIG2                                    , RULL(0x050112E0), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( NV_CONFIG3                                              , RULL(0x050110C1), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CONFIG3                                            , RULL(0x050110C1), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CONFIG3                                            , RULL(0x050110E1), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CONFIG3                                            , RULL(0x050111C1), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CONFIG3                                            , RULL(0x050111E1), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_CONFIG3                                     , RULL(0x05011083), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CONFIG3                                     , RULL(0x05011183), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CONFIG3                                     , RULL(0x05011283), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CONFIG3                                    , RULL(0x050112C1), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CONFIG3                                    , RULL(0x050112E1), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_CONFIG_RELAXED0                             , RULL(0x0501100A), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CONFIG_RELAXED0                             , RULL(0x0501102A), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CONFIG_RELAXED0                             , RULL(0x0501104A), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CONFIG_RELAXED0                             , RULL(0x0501106A), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CONFIG_RELAXED0                             , RULL(0x0501110A), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CONFIG_RELAXED0                             , RULL(0x0501112A), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CONFIG_RELAXED0                             , RULL(0x0501114A), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CONFIG_RELAXED0                             , RULL(0x0501116A), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CONFIG_RELAXED0                             , RULL(0x0501120A), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CONFIG_RELAXED0                             , RULL(0x0501122A), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CONFIG_RELAXED0                             , RULL(0x0501124A), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CONFIG_RELAXED0                             , RULL(0x0501126A), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_CONFIG_RELAXED1                             , RULL(0x0501100B), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CONFIG_RELAXED1                             , RULL(0x0501102B), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CONFIG_RELAXED1                             , RULL(0x0501104B), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CONFIG_RELAXED1                             , RULL(0x0501106B), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CONFIG_RELAXED1                             , RULL(0x0501110B), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CONFIG_RELAXED1                             , RULL(0x0501112B), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CONFIG_RELAXED1                             , RULL(0x0501114B), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CONFIG_RELAXED1                             , RULL(0x0501116B), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CONFIG_RELAXED1                             , RULL(0x0501120B), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CONFIG_RELAXED1                             , RULL(0x0501122B), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CONFIG_RELAXED1                             , RULL(0x0501124B), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CONFIG_RELAXED1                             , RULL(0x0501126B), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_CONFIG_RELAXED2                             , RULL(0x0501100C), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_CONFIG_RELAXED2                             , RULL(0x0501102C), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_CONFIG_RELAXED2                             , RULL(0x0501104C), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_CONFIG_RELAXED2                             , RULL(0x0501106C), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_CONFIG_RELAXED2                             , RULL(0x0501110C), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_CONFIG_RELAXED2                             , RULL(0x0501112C), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_CONFIG_RELAXED2                             , RULL(0x0501114C), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_CONFIG_RELAXED2                             , RULL(0x0501116C), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_CONFIG_RELAXED2                             , RULL(0x0501120C), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_CONFIG_RELAXED2                             , RULL(0x0501122C), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_CONFIG_RELAXED2                             , RULL(0x0501124C), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_CONFIG_RELAXED2                             , RULL(0x0501126C), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PEC_CONTROL_REG                                         , RULL(0x0D050012), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CONTROL_REG                                       , RULL(0x0D050012), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CONTROL_REG                                       , RULL(0x0E050012), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CONTROL_REG                                       , RULL(0x0F050012), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_CONTROL_REGISTER_B                                   , RULL(0x000A0000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_CONTROL_REGISTER_C                                   , RULL(0x000A1000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_CONTROL_REGISTER_D                                   , RULL(0x000A2000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_CONTROL_REGISTER_E                                   , RULL(0x000A3000), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_CPLT_CONF0                                          , RULL(0x0D000008), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_CPLT_CONF0_OR                                       , RULL(0x0D000018), SH_UNT_PEC      , SH_ACS_SCOM1_OR  );
REG64( PEC_CPLT_CONF0_CLEAR                                    , RULL(0x0D000028), SH_UNT_PEC      ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_0_CPLT_CONF0                                        , RULL(0x0D000008), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_CPLT_CONF0_OR                                     , RULL(0x0D000018), SH_UNT_PEC_0    , SH_ACS_SCOM1_OR  );
REG64( PEC_0_CPLT_CONF0_CLEAR                                  , RULL(0x0D000028), SH_UNT_PEC_0    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_1_CPLT_CONF0                                        , RULL(0x0E000008), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_CPLT_CONF0_OR                                     , RULL(0x0E000018), SH_UNT_PEC_1    , SH_ACS_SCOM1_OR  );
REG64( PEC_1_CPLT_CONF0_CLEAR                                  , RULL(0x0E000028), SH_UNT_PEC_1    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_2_CPLT_CONF0                                        , RULL(0x0F000008), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_CPLT_CONF0_OR                                     , RULL(0x0F000018), SH_UNT_PEC_2    , SH_ACS_SCOM1_OR  );
REG64( PEC_2_CPLT_CONF0_CLEAR                                  , RULL(0x0F000028), SH_UNT_PEC_2    ,
       SH_ACS_SCOM2_CLEAR );

REG64( PEC_CPLT_CONF1                                          , RULL(0x0D000009), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_CPLT_CONF1_OR                                       , RULL(0x0D000019), SH_UNT_PEC      , SH_ACS_SCOM1_OR  );
REG64( PEC_CPLT_CONF1_CLEAR                                    , RULL(0x0D000029), SH_UNT_PEC      ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_0_CPLT_CONF1                                        , RULL(0x0D000009), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_CPLT_CONF1_OR                                     , RULL(0x0D000019), SH_UNT_PEC_0    , SH_ACS_SCOM1_OR  );
REG64( PEC_0_CPLT_CONF1_CLEAR                                  , RULL(0x0D000029), SH_UNT_PEC_0    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_1_CPLT_CONF1                                        , RULL(0x0E000009), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_CPLT_CONF1_OR                                     , RULL(0x0E000019), SH_UNT_PEC_1    , SH_ACS_SCOM1_OR  );
REG64( PEC_1_CPLT_CONF1_CLEAR                                  , RULL(0x0E000029), SH_UNT_PEC_1    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_2_CPLT_CONF1                                        , RULL(0x0F000009), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_CPLT_CONF1_OR                                     , RULL(0x0F000019), SH_UNT_PEC_2    , SH_ACS_SCOM1_OR  );
REG64( PEC_2_CPLT_CONF1_CLEAR                                  , RULL(0x0F000029), SH_UNT_PEC_2    ,
       SH_ACS_SCOM2_CLEAR );

REG64( PEC_CPLT_CTRL0                                          , RULL(0x0D000000), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_CPLT_CTRL0_OR                                       , RULL(0x0D000010), SH_UNT_PEC      , SH_ACS_SCOM1_OR  );
REG64( PEC_CPLT_CTRL0_CLEAR                                    , RULL(0x0D000020), SH_UNT_PEC      ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_0_CPLT_CTRL0                                        , RULL(0x0D000000), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_CPLT_CTRL0_OR                                     , RULL(0x0D000010), SH_UNT_PEC_0    , SH_ACS_SCOM1_OR  );
REG64( PEC_0_CPLT_CTRL0_CLEAR                                  , RULL(0x0D000020), SH_UNT_PEC_0    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_1_CPLT_CTRL0                                        , RULL(0x0E000000), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_CPLT_CTRL0_OR                                     , RULL(0x0E000010), SH_UNT_PEC_1    , SH_ACS_SCOM1_OR  );
REG64( PEC_1_CPLT_CTRL0_CLEAR                                  , RULL(0x0E000020), SH_UNT_PEC_1    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_2_CPLT_CTRL0                                        , RULL(0x0F000000), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_CPLT_CTRL0_OR                                     , RULL(0x0F000010), SH_UNT_PEC_2    , SH_ACS_SCOM1_OR  );
REG64( PEC_2_CPLT_CTRL0_CLEAR                                  , RULL(0x0F000020), SH_UNT_PEC_2    ,
       SH_ACS_SCOM2_CLEAR );

REG64( PEC_CPLT_CTRL1                                          , RULL(0x0D000001), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_CPLT_CTRL1_OR                                       , RULL(0x0D000011), SH_UNT_PEC      , SH_ACS_SCOM1_OR  );
REG64( PEC_CPLT_CTRL1_CLEAR                                    , RULL(0x0D000021), SH_UNT_PEC      ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_0_CPLT_CTRL1                                        , RULL(0x0D000001), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_CPLT_CTRL1_OR                                     , RULL(0x0D000011), SH_UNT_PEC_0    , SH_ACS_SCOM1_OR  );
REG64( PEC_0_CPLT_CTRL1_CLEAR                                  , RULL(0x0D000021), SH_UNT_PEC_0    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_1_CPLT_CTRL1                                        , RULL(0x0E000001), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_CPLT_CTRL1_OR                                     , RULL(0x0E000011), SH_UNT_PEC_1    , SH_ACS_SCOM1_OR  );
REG64( PEC_1_CPLT_CTRL1_CLEAR                                  , RULL(0x0E000021), SH_UNT_PEC_1    ,
       SH_ACS_SCOM2_CLEAR );
REG64( PEC_2_CPLT_CTRL1                                        , RULL(0x0F000001), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_CPLT_CTRL1_OR                                     , RULL(0x0F000011), SH_UNT_PEC_2    , SH_ACS_SCOM1_OR  );
REG64( PEC_2_CPLT_CTRL1_CLEAR                                  , RULL(0x0F000021), SH_UNT_PEC_2    ,
       SH_ACS_SCOM2_CLEAR );

REG64( PEC_CPLT_MASK0                                          , RULL(0x0D000101), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CPLT_MASK0                                        , RULL(0x0D000101), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CPLT_MASK0                                        , RULL(0x0E000101), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CPLT_MASK0                                        , RULL(0x0F000101), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_CPLT_STAT0                                          , RULL(0x0D000100), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CPLT_STAT0                                        , RULL(0x0D000100), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CPLT_STAT0                                        , RULL(0x0E000100), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CPLT_STAT0                                        , RULL(0x0F000100), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_CQSTAT_REG                                 , RULL(0x04010C4C), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_0_STACK1_CQSTAT_REG                                 , RULL(0x04010C8C), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_0_STACK2_CQSTAT_REG                                 , RULL(0x04010CCC), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK0_CQSTAT_REG                                 , RULL(0x0401104C), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK1_CQSTAT_REG                                 , RULL(0x0401108C), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_1_STACK2_CQSTAT_REG                                 , RULL(0x040110CC), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK0_CQSTAT_REG                                 , RULL(0x0401144C), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK1_CQSTAT_REG                                 , RULL(0x0401148C), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_2_STACK2_CQSTAT_REG                                 , RULL(0x040114CC), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK0_CQSTAT_REG                                   , RULL(0x04010C4C), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK1_CQSTAT_REG                                   , RULL(0x04010C8C), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PEC_STACK2_CQSTAT_REG                                   , RULL(0x04010CCC), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PHB_CQSTAT_REG                                          , RULL(0x04010C4C), SH_UNT_PHB      , SH_ACS_SCOM_RO   );
REG64( PHB_0_CQSTAT_REG                                        , RULL(0x04010C4C), SH_UNT_PHB_0    , SH_ACS_SCOM_RO   );
REG64( PHB_1_CQSTAT_REG                                        , RULL(0x0401104C), SH_UNT_PHB_1    , SH_ACS_SCOM_RO   );
REG64( PHB_2_CQSTAT_REG                                        , RULL(0x0401108C), SH_UNT_PHB_2    , SH_ACS_SCOM_RO   );
REG64( PHB_3_CQSTAT_REG                                        , RULL(0x0401144C), SH_UNT_PHB_3    , SH_ACS_SCOM_RO   );
REG64( PHB_4_CQSTAT_REG                                        , RULL(0x0401148C), SH_UNT_PHB_4    , SH_ACS_SCOM_RO   );
REG64( PHB_5_CQSTAT_REG                                        , RULL(0x040114CC), SH_UNT_PHB_5    , SH_ACS_SCOM_RO   );

REG64( NV_CREQ_DA_PTR                                          , RULL(0x050110D4), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CREQ_DA_PTR                                        , RULL(0x050110D4), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CREQ_DA_PTR                                        , RULL(0x050110F4), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CREQ_DA_PTR                                        , RULL(0x050111D4), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CREQ_DA_PTR                                        , RULL(0x050111F4), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CREQ_DA_PTR                                , RULL(0x050112D4), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CREQ_DA_PTR                                , RULL(0x050112F4), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( NV_CREQ_HA_PTR                                          , RULL(0x050110D0), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_CREQ_HA_PTR                                        , RULL(0x050110D0), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_CREQ_HA_PTR                                        , RULL(0x050110F0), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_CREQ_HA_PTR                                        , RULL(0x050111D0), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_CREQ_HA_PTR                                        , RULL(0x050111F0), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_CREQ_HA_PTR                                , RULL(0x050112D0), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_CREQ_HA_PTR                                , RULL(0x050112F0), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_CSAR                                                 , RULL(0x0501240D), SH_UNT          ,
       SH_ACS_SCOM_RW   ); //DUPS: 06010858,

REG64( PU_CSCR                                                 , RULL(0x0501240A), SH_UNT          ,
       SH_ACS_SCOM_RW   ); //DUPS: 06010855,
REG64( PU_CSCR_CLEAR                                           , RULL(0x0501240B), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_CSCR_OR                                              , RULL(0x0501240C), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_IOPPE_CSCR_CLEAR                                     , RULL(0x06010801), SH_UNT_PU_IOPPE ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_IOPPE_CSCR_OR                                        , RULL(0x06010802), SH_UNT_PU_IOPPE , SH_ACS_SCOM2_OR  );

REG64( PU_CSDR                                                 , RULL(0x0501240E), SH_UNT          ,
       SH_ACS_SCOM_RW   ); //DUPS: 06010859,

REG64( PU_NPU0_CTL_CTL_STATUS                                  , RULL(0x05011092), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_CTL_STATUS                                  , RULL(0x05011192), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_CTL_STATUS                                  , RULL(0x05011292), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PEC_CTRL_ATOMIC_LOCK_REG                                , RULL(0x0D0003FF), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CTRL_ATOMIC_LOCK_REG                              , RULL(0x0D0003FF), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CTRL_ATOMIC_LOCK_REG                              , RULL(0x0E0003FF), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CTRL_ATOMIC_LOCK_REG                              , RULL(0x0F0003FF), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_CTRL_PROTECT_MODE_REG                               , RULL(0x0D0003FE), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_CTRL_PROTECT_MODE_REG                             , RULL(0x0D0003FE), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_CTRL_PROTECT_MODE_REG                             , RULL(0x0E0003FE), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_CTRL_PROTECT_MODE_REG                             , RULL(0x0F0003FE), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_ARRAY_ADDR_REG                             , RULL(0x02010828), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_ARRAY_ADDR_REG                           , RULL(0x02010828), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_ARRAY_ADDR_REG                           , RULL(0x04010828), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_ARRAY_READ_REG                             , RULL(0x02010829), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_ARRAY_READ_REG                           , RULL(0x02010829), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_ARRAY_READ_REG                           , RULL(0x04010829), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_ARRAY_WRITE_REG                            , RULL(0x02010841), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_ARRAY_WRITE_REG                          , RULL(0x02010841), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_ARRAY_WRITE_REG                          , RULL(0x04010841), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_CAN_PRESP_REG0                             , RULL(0x0201081D), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_CAN_PRESP_REG0                           , RULL(0x0201081D), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_CAN_PRESP_REG0                           , RULL(0x0401081D), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_CAN_PRESP_REG1                             , RULL(0x0201081E), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_CAN_PRESP_REG1                           , RULL(0x0201081E), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_CAN_PRESP_REG1                           , RULL(0x0401081E), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_CAN_PRESP_REG2                             , RULL(0x0201081F), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_CAN_PRESP_REG2                           , RULL(0x0201081F), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_CAN_PRESP_REG2                           , RULL(0x0401081F), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_CAPI_CFG_REG                               , RULL(0x0201081A), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_CAPI_CFG_REG                             , RULL(0x0201081A), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_CAPI_CFG_REG                             , RULL(0x0401081A), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_CNTL_REG                                   , RULL(0x0201081B), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_CNTL_REG                                 , RULL(0x0201081B), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_CNTL_REG                                 , RULL(0x0401081B), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_ERROR_REPORT_REG                           , RULL(0x0201080A), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_ERROR_REPORT_REG                         , RULL(0x0201080A), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_ERROR_REPORT_REG                         , RULL(0x0401080A), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_PHB_TTAG_FILTER_REG                        , RULL(0x02010831), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_PHB_TTAG_FILTER_REG                      , RULL(0x02010831), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_PHB_TTAG_FILTER_REG                      , RULL(0x04010831), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG                      , RULL(0x02010817), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_PMU_EVENTS_SELECT_REG                    , RULL(0x02010817), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_PMU_EVENTS_SELECT_REG                    , RULL(0x04010817), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG                   , RULL(0x02010840), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG                 , RULL(0x02010840), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG                 , RULL(0x04010840), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1                  , RULL(0x02010844), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1                , RULL(0x02010844), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_REMOTE_ADDR_BAR_BARM_REG1                , RULL(0x04010844), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG                   , RULL(0x0201084A), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG                 , RULL(0x0201084A), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG                 , RULL(0x0401084A), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1                  , RULL(0x0201084B), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1                , RULL(0x0201084B), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_SNP_REMOTE_MMIO_BAR_BARM_REG1                , RULL(0x0401084B), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_CXA_TRIGCTL                                        , RULL(0x02010812), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_CXA_TRIGCTL                                      , RULL(0x02010812), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_CXA_TRIGCTL                                      , RULL(0x04010812), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_DATA0TO7_REGISTER_B                                  , RULL(0x000A0003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA0TO7_REGISTER_C                                  , RULL(0x000A1003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA0TO7_REGISTER_D                                  , RULL(0x000A2003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA0TO7_REGISTER_E                                  , RULL(0x000A3003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA8TO15_REGISTER_B                                 , RULL(0x000A0001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA8TO15_REGISTER_C                                 , RULL(0x000A1001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA8TO15_REGISTER_D                                 , RULL(0x000A2001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATA8TO15_REGISTER_E                                 , RULL(0x000A3001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DATATAG_0_HASH_FUNCTION_REG                          , RULL(0x0201114C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_DATATAG_1_HASH_FUNCTION_REG                          , RULL(0x0201114D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_DATATAG_2_HASH_FUNCTION_REG                          , RULL(0x0201114E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_DATATAG_3_HASH_FUNCTION_REG                          , RULL(0x0201114F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_DATATAG_4_HASH_FUNCTION_REG                          , RULL(0x02011150), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_DATATAG_5_HASH_FUNCTION_REG                          , RULL(0x02011151), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_DATA_REGISTER                                        , RULL(0x00010003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU_CTL_DA_ADDR                                      , RULL(0x0501138E), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_DA_DATA                                      , RULL(0x0501138F), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM_RW   );

REG64( PEC_DBG_CBS_CC                                          , RULL(0x0D030013), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_CBS_CC                                        , RULL(0x0D030013), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_CBS_CC                                        , RULL(0x0E030013), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_CBS_CC                                        , RULL(0x0F030013), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_DBG_INST1_COND_REG_1                                , RULL(0x0D0107C1), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_INST1_COND_REG_1                              , RULL(0x0D0107C1), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_INST1_COND_REG_1                              , RULL(0x0E0107C1), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_INST1_COND_REG_1                              , RULL(0x0F0107C1), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_INST1_COND_REG_1                              , RULL(0x020107E1), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_INST1_COND_REG_1                              , RULL(0x030107E1), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_INST1_COND_REG_1                              , RULL(0x040107E1), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_INST1_COND_REG_1                              , RULL(0x050107E1), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_INST1_COND_REG_2                                , RULL(0x0D0107C2), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_INST1_COND_REG_2                              , RULL(0x0D0107C2), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_INST1_COND_REG_2                              , RULL(0x0E0107C2), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_INST1_COND_REG_2                              , RULL(0x0F0107C2), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_INST1_COND_REG_2                              , RULL(0x020107E2), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_INST1_COND_REG_2                              , RULL(0x030107E2), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_INST1_COND_REG_2                              , RULL(0x040107E2), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_INST1_COND_REG_2                              , RULL(0x050107E2), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_INST1_COND_REG_3                                , RULL(0x0D0107C3), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_INST1_COND_REG_3                              , RULL(0x0D0107C3), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_INST1_COND_REG_3                              , RULL(0x0E0107C3), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_INST1_COND_REG_3                              , RULL(0x0F0107C3), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_INST1_COND_REG_3                              , RULL(0x020107E3), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_INST1_COND_REG_3                              , RULL(0x030107E3), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_INST1_COND_REG_3                              , RULL(0x040107E3), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_INST1_COND_REG_3                              , RULL(0x050107E3), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_INST2_COND_REG_1                                , RULL(0x0D0107C4), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_INST2_COND_REG_1                              , RULL(0x0D0107C4), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_INST2_COND_REG_1                              , RULL(0x0E0107C4), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_INST2_COND_REG_1                              , RULL(0x0F0107C4), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_INST2_COND_REG_1                              , RULL(0x020107E4), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_INST2_COND_REG_1                              , RULL(0x030107E4), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_INST2_COND_REG_1                              , RULL(0x040107E4), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_INST2_COND_REG_1                              , RULL(0x050107E4), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_INST2_COND_REG_2                                , RULL(0x0D0107C5), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_INST2_COND_REG_2                              , RULL(0x0D0107C5), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_INST2_COND_REG_2                              , RULL(0x0E0107C5), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_INST2_COND_REG_2                              , RULL(0x0F0107C5), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_INST2_COND_REG_2                              , RULL(0x020107E5), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_INST2_COND_REG_2                              , RULL(0x030107E5), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_INST2_COND_REG_2                              , RULL(0x040107E5), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_INST2_COND_REG_2                              , RULL(0x050107E5), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_INST2_COND_REG_3                                , RULL(0x0D0107C6), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_INST2_COND_REG_3                              , RULL(0x0D0107C6), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_INST2_COND_REG_3                              , RULL(0x0E0107C6), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_INST2_COND_REG_3                              , RULL(0x0F0107C6), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_INST2_COND_REG_3                              , RULL(0x020107E6), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_INST2_COND_REG_3                              , RULL(0x030107E6), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_INST2_COND_REG_3                              , RULL(0x040107E6), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_INST2_COND_REG_3                              , RULL(0x050107E6), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_MODE_REG                                        , RULL(0x0D0107C0), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_MODE_REG                                      , RULL(0x0D0107C0), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_MODE_REG                                      , RULL(0x0E0107C0), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_MODE_REG                                      , RULL(0x0F0107C0), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_MODE_REG                                      , RULL(0x020107E0), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_MODE_REG                                      , RULL(0x030107E0), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_MODE_REG                                      , RULL(0x040107E0), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_MODE_REG                                      , RULL(0x050107E0), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_TRACE_MODE_REG_2                                , RULL(0x0D0107CB), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_TRACE_MODE_REG_2                              , RULL(0x0D0107CB), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_TRACE_MODE_REG_2                              , RULL(0x0E0107CB), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_TRACE_MODE_REG_2                              , RULL(0x0F0107CB), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_TRACE_MODE_REG_2                              , RULL(0x020107EB), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_TRACE_MODE_REG_2                              , RULL(0x030107EB), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_TRACE_MODE_REG_2                              , RULL(0x040107EB), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_TRACE_MODE_REG_2                              , RULL(0x050107EB), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_TRACE_REG_0                                     , RULL(0x0D0107C9), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_TRACE_REG_0                                   , RULL(0x0D0107C9), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_TRACE_REG_0                                   , RULL(0x0E0107C9), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_TRACE_REG_0                                   , RULL(0x0F0107C9), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_TRACE_REG_0                                   , RULL(0x020107E9), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_TRACE_REG_0                                   , RULL(0x030107E9), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_TRACE_REG_0                                   , RULL(0x040107E9), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_TRACE_REG_0                                   , RULL(0x050107E9), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_DBG_TRACE_REG_1                                     , RULL(0x0D0107CA), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_DBG_TRACE_REG_1                                   , RULL(0x0D0107CA), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_DBG_TRACE_REG_1                                   , RULL(0x0E0107CA), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_DBG_TRACE_REG_1                                   , RULL(0x0F0107CA), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_DBG_TRACE_REG_1                                   , RULL(0x020107EA), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_DBG_TRACE_REG_1                                   , RULL(0x030107EA), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_DBG_TRACE_REG_1                                   , RULL(0x040107EA), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_DBG_TRACE_REG_1                                   , RULL(0x050107EA), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( NV_DEBUG0_CONFIG                                        , RULL(0x050110CC), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_DEBUG0_CONFIG                                      , RULL(0x050110CC), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_DEBUG0_CONFIG                                      , RULL(0x050110EC), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_DEBUG0_CONFIG                                      , RULL(0x050111CC), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_DEBUG0_CONFIG                                      , RULL(0x050111EC), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_DEBUG0_CONFIG                               , RULL(0x05011088), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_DAT_DEBUG0_CONFIG                               , RULL(0x050110B0), SH_UNT_PU_NPU0_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_DEBUG0_CONFIG                               , RULL(0x05011188), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_DAT_DEBUG0_CONFIG                               , RULL(0x050111B0), SH_UNT_PU_NPU1_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU2_DAT_DEBUG0_CONFIG                               , RULL(0x050112B0), SH_UNT_PU_NPU2_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_DEBUG0_CONFIG                               , RULL(0x05011288), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_DEBUG0_CONFIG                               , RULL(0x0501100D), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_DEBUG0_CONFIG                               , RULL(0x0501102D), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_DEBUG0_CONFIG                               , RULL(0x0501104D), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_DEBUG0_CONFIG                               , RULL(0x0501106D), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_DEBUG0_CONFIG                               , RULL(0x0501110D), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_DEBUG0_CONFIG                               , RULL(0x0501112D), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_DEBUG0_CONFIG                               , RULL(0x0501114D), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_DEBUG0_CONFIG                               , RULL(0x0501116D), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_DEBUG0_CONFIG                              , RULL(0x050112CC), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_DEBUG0_CONFIG                              , RULL(0x050112EC), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_DEBUG0_CONFIG                               , RULL(0x0501120D), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_DEBUG0_CONFIG                               , RULL(0x0501122D), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_DEBUG0_CONFIG                               , RULL(0x0501124D), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_DEBUG0_CONFIG                               , RULL(0x0501126D), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU_SM2_DEBUG0_CONFIG                                , RULL(0x05011346), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( NV_DEBUG1_CONFIG                                        , RULL(0x050110CD), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_DEBUG1_CONFIG                                      , RULL(0x050110CD), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_DEBUG1_CONFIG                                      , RULL(0x050110ED), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_DEBUG1_CONFIG                                      , RULL(0x050111CD), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_DEBUG1_CONFIG                                      , RULL(0x050111ED), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_DEBUG1_CONFIG                               , RULL(0x05011089), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_DAT_DEBUG1_CONFIG                               , RULL(0x050110B1), SH_UNT_PU_NPU0_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_DEBUG1_CONFIG                               , RULL(0x05011189), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_DAT_DEBUG1_CONFIG                               , RULL(0x050111B1), SH_UNT_PU_NPU1_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU2_DAT_DEBUG1_CONFIG                               , RULL(0x050112B1), SH_UNT_PU_NPU2_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_DEBUG1_CONFIG                               , RULL(0x05011289), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_DEBUG1_CONFIG                               , RULL(0x0501100E), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_DEBUG1_CONFIG                               , RULL(0x0501102E), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_DEBUG1_CONFIG                               , RULL(0x0501104E), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_DEBUG1_CONFIG                               , RULL(0x0501106E), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_DEBUG1_CONFIG                               , RULL(0x0501110E), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_DEBUG1_CONFIG                               , RULL(0x0501112E), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_DEBUG1_CONFIG                               , RULL(0x0501114E), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_DEBUG1_CONFIG                               , RULL(0x0501116E), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_DEBUG1_CONFIG                              , RULL(0x050112CD), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_DEBUG1_CONFIG                              , RULL(0x050112ED), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_DEBUG1_CONFIG                               , RULL(0x0501120E), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_DEBUG1_CONFIG                               , RULL(0x0501122E), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_DEBUG1_CONFIG                               , RULL(0x0501124E), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_DEBUG1_CONFIG                               , RULL(0x0501126E), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU_SM2_DEBUG1_CONFIG                                , RULL(0x05011347), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_DEBUG_CONFIG                                 , RULL(0x05011380), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( CAPP_DEBUG_CONTROL                                      , RULL(0x02010811), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_DEBUG_CONTROL                                    , RULL(0x02010811), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_DEBUG_CONTROL                                    , RULL(0x04010811), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_DFSUOP1                                            , RULL(0x02010843), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_DFSUOP1                                          , RULL(0x02010843), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_DFSUOP1                                          , RULL(0x04010843), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_DISABLE_FORCE_PFET_OFF                               , RULL(0x0001000D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU_SM1_DMA_SYNC                                     , RULL(0x05011323), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM      );

REG64( PU_DMA_UP_ADDR                                          , RULL(0x05012914), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_DMA_VAS_MMIO_BAR                                     , RULL(0x0201105E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_DRPPRICTL_REG                                       , RULL(0x04010C01), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_DRPPRICTL_REG                                     , RULL(0x04010C01), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_DRPPRICTL_REG                                     , RULL(0x04011001), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_DRPPRICTL_REG                                     , RULL(0x04011401), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_DTS_RESULT0                                         , RULL(0x0D050000), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_DTS_RESULT0                                       , RULL(0x0D050000), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_DTS_RESULT0                                       , RULL(0x0E050000), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_DTS_RESULT0                                       , RULL(0x0F050000), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_DTS_TRC_RESULT                                      , RULL(0x0D050003), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_DTS_TRC_RESULT                                    , RULL(0x0D050003), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_DTS_TRC_RESULT                                    , RULL(0x0E050003), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_DTS_TRC_RESULT                                    , RULL(0x0F050003), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PU_NPU0_ECC_CONFIG                                      , RULL(0x050110A2), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_ECC_CONFIG                                      , RULL(0x050111A2), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_ECC_CONFIG                                      , RULL(0x050112A2), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART0_REGISTER                          , RULL(0x00018000), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART0_REGISTER                          , RULL(0x00018040), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART10_REGISTER                         , RULL(0x0001800A), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART10_REGISTER                         , RULL(0x0001804A), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART11_REGISTER                         , RULL(0x0001800B), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART11_REGISTER                         , RULL(0x0001804B), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART12_REGISTER                         , RULL(0x0001800C), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART12_REGISTER                         , RULL(0x0001804C), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART13_REGISTER                         , RULL(0x0001800D), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART13_REGISTER                         , RULL(0x0001804D), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART14_REGISTER                         , RULL(0x0001800E), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART14_REGISTER                         , RULL(0x0001804E), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART15_REGISTER                         , RULL(0x0001800F), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART15_REGISTER                         , RULL(0x0001804F), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART16_REGISTER                         , RULL(0x00018010), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART16_REGISTER                         , RULL(0x00018050), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART17_REGISTER                         , RULL(0x00018011), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART17_REGISTER                         , RULL(0x00018051), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART18_REGISTER                         , RULL(0x00018012), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART18_REGISTER                         , RULL(0x00018052), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART19_REGISTER                         , RULL(0x00018013), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART19_REGISTER                         , RULL(0x00018053), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART1_REGISTER                          , RULL(0x00018001), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART1_REGISTER                          , RULL(0x00018041), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART20_REGISTER                         , RULL(0x00018014), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART20_REGISTER                         , RULL(0x00018054), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART21_REGISTER                         , RULL(0x00018015), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART21_REGISTER                         , RULL(0x00018055), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART22_REGISTER                         , RULL(0x00018016), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART22_REGISTER                         , RULL(0x00018056), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART23_REGISTER                         , RULL(0x00018017), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART23_REGISTER                         , RULL(0x00018057), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART24_REGISTER                         , RULL(0x00018018), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART24_REGISTER                         , RULL(0x00018058), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART25_REGISTER                         , RULL(0x00018019), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART25_REGISTER                         , RULL(0x00018059), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART26_REGISTER                         , RULL(0x0001801A), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART26_REGISTER                         , RULL(0x0001805A), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART27_REGISTER                         , RULL(0x0001801B), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART27_REGISTER                         , RULL(0x0001805B), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART28_REGISTER                         , RULL(0x0001801C), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART28_REGISTER                         , RULL(0x0001805C), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART29_REGISTER                         , RULL(0x0001801D), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART29_REGISTER                         , RULL(0x0001805D), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART2_REGISTER                          , RULL(0x00018002), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART2_REGISTER                          , RULL(0x00018042), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART30_REGISTER                         , RULL(0x0001801E), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART30_REGISTER                         , RULL(0x0001805E), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART31_REGISTER                         , RULL(0x0001801F), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART31_REGISTER                         , RULL(0x0001805F), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART32_REGISTER                         , RULL(0x00018020), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART32_REGISTER                         , RULL(0x00018060), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART33_REGISTER                         , RULL(0x00018021), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART33_REGISTER                         , RULL(0x00018061), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART34_REGISTER                         , RULL(0x00018022), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART34_REGISTER                         , RULL(0x00018062), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART35_REGISTER                         , RULL(0x00018023), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART35_REGISTER                         , RULL(0x00018063), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART36_REGISTER                         , RULL(0x00018024), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART36_REGISTER                         , RULL(0x00018064), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART37_REGISTER                         , RULL(0x00018025), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART37_REGISTER                         , RULL(0x00018065), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART38_REGISTER                         , RULL(0x00018026), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART38_REGISTER                         , RULL(0x00018066), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART39_REGISTER                         , RULL(0x00018027), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART39_REGISTER                         , RULL(0x00018067), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART3_REGISTER                          , RULL(0x00018003), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART3_REGISTER                          , RULL(0x00018043), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART40_REGISTER                         , RULL(0x00018028), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART40_REGISTER                         , RULL(0x00018068), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART41_REGISTER                         , RULL(0x00018029), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART41_REGISTER                         , RULL(0x00018069), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART42_REGISTER                         , RULL(0x0001802A), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART42_REGISTER                         , RULL(0x0001806A), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART43_REGISTER                         , RULL(0x0001802B), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART43_REGISTER                         , RULL(0x0001806B), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART44_REGISTER                         , RULL(0x0001802C), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART44_REGISTER                         , RULL(0x0001806C), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART45_REGISTER                         , RULL(0x0001802D), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART45_REGISTER                         , RULL(0x0001806D), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART46_REGISTER                         , RULL(0x0001802E), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART46_REGISTER                         , RULL(0x0001806E), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART47_REGISTER                         , RULL(0x0001802F), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART47_REGISTER                         , RULL(0x0001806F), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART48_REGISTER                         , RULL(0x00018030), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART48_REGISTER                         , RULL(0x00018070), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART49_REGISTER                         , RULL(0x00018031), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART49_REGISTER                         , RULL(0x00018071), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART4_REGISTER                          , RULL(0x00018004), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART4_REGISTER                          , RULL(0x00018044), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART50_REGISTER                         , RULL(0x00018032), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART50_REGISTER                         , RULL(0x00018072), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART51_REGISTER                         , RULL(0x00018033), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART51_REGISTER                         , RULL(0x00018073), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART52_REGISTER                         , RULL(0x00018034), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART52_REGISTER                         , RULL(0x00018074), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART53_REGISTER                         , RULL(0x00018035), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART53_REGISTER                         , RULL(0x00018075), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART54_REGISTER                         , RULL(0x00018036), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART54_REGISTER                         , RULL(0x00018076), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART55_REGISTER                         , RULL(0x00018037), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART55_REGISTER                         , RULL(0x00018077), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART56_REGISTER                         , RULL(0x00018038), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART56_REGISTER                         , RULL(0x00018078), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART57_REGISTER                         , RULL(0x00018039), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART57_REGISTER                         , RULL(0x00018079), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART58_REGISTER                         , RULL(0x0001803A), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART58_REGISTER                         , RULL(0x0001807A), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART59_REGISTER                         , RULL(0x0001803B), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART59_REGISTER                         , RULL(0x0001807B), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART5_REGISTER                          , RULL(0x00018005), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART5_REGISTER                          , RULL(0x00018045), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART60_REGISTER                         , RULL(0x0001803C), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART60_REGISTER                         , RULL(0x0001807C), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART61_REGISTER                         , RULL(0x0001803D), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART61_REGISTER                         , RULL(0x0001807D), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART62_REGISTER                         , RULL(0x0001803E), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART62_REGISTER                         , RULL(0x0001807E), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART63_REGISTER                         , RULL(0x0001803F), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART63_REGISTER                         , RULL(0x0001807F), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART6_REGISTER                          , RULL(0x00018006), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART6_REGISTER                          , RULL(0x00018046), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART7_REGISTER                          , RULL(0x00018007), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART7_REGISTER                          , RULL(0x00018047), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART8_REGISTER                          , RULL(0x00018008), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART8_REGISTER                          , RULL(0x00018048), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_OTPROM0_ECID_PART9_REGISTER                          , RULL(0x00018009), SH_UNT_PU_OTPROM0,
       SH_ACS_SCOM      );
REG64( PU_OTPROM1_ECID_PART9_REGISTER                          , RULL(0x00018049), SH_UNT_PU_OTPROM1,
       SH_ACS_SCOM      );

REG64( PU_EECNT_REG                                            , RULL(0x05012809), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_HI_PRIOR_RCV_FIFO_ASB                            , RULL(0x020110C6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_HI_PRIOR_RCV_FIFO_BAR                            , RULL(0x020110C0), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_HI_PRIOR_RCV_FIFO_CNTL                           , RULL(0x020110C3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_LO_PRIOR_RCV_FIFO_ASB                            , RULL(0x020110CF), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_LO_PRIOR_RCV_FIFO_BAR                            , RULL(0x020110C9), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_LO_PRIOR_RCV_FIFO_CNTL                           , RULL(0x020110CC), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EFT_MAX_BYTE_CNT                                     , RULL(0x02011059), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_EHHCA_FIR_ACTION0_REG                                , RULL(0x05012986), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_EHHCA_FIR_ACTION1_REG                                , RULL(0x05012987), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_EHHCA_FIR_MASK_REG                                   , RULL(0x05012983), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_EHHCA_FIR_MASK_REG_AND                               , RULL(0x05012984), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_EHHCA_FIR_MASK_REG_OR                                , RULL(0x05012985), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_EHHCA_FIR_REG                                        , RULL(0x05012980), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_EHHCA_FIR_REG_AND                                    , RULL(0x05012981), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_EHHCA_FIR_REG_OR                                     , RULL(0x05012982), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_NPU0_SM0_EPSILON_CONFIG                              , RULL(0x05011002), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_EPSILON_CONFIG                              , RULL(0x05011022), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_EPSILON_CONFIG                              , RULL(0x05011042), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_EPSILON_CONFIG                              , RULL(0x05011062), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_EPSILON_CONFIG                              , RULL(0x05011102), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_EPSILON_CONFIG                              , RULL(0x05011122), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_EPSILON_CONFIG                              , RULL(0x05011142), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_EPSILON_CONFIG                              , RULL(0x05011162), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_EPSILON_CONFIG                              , RULL(0x05011202), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_EPSILON_CONFIG                              , RULL(0x05011222), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_EPSILON_CONFIG                              , RULL(0x05011242), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_EPSILON_CONFIG                              , RULL(0x05011262), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_ERAT_STATUS_CONTROL                                  , RULL(0x020110D6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU_CTL_ERROR_BRICK_GROUP_CONFIG                     , RULL(0x05011394), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PEC_ERROR_REG                                           , RULL(0x0D0F001F), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ERROR_REG                                         , RULL(0x0D0F001F), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ERROR_REG                                         , RULL(0x0E0F001F), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ERROR_REG                                         , RULL(0x0F0F001F), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_ERROR_STATUS                                        , RULL(0x0D03000F), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_ERROR_STATUS                                      , RULL(0x0D03000F), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_ERROR_STATUS                                      , RULL(0x0E03000F), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_ERROR_STATUS                                      , RULL(0x0F03000F), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( CAPP_ERRRPT                                             , RULL(0x0201080B), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_ERRRPT                                           , RULL(0x0201080B), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_ERRRPT                                           , RULL(0x0401080B), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_NPU_SM2_ERR_FIRST                                    , RULL(0x05011343), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM2_ERR_HOLD                                     , RULL(0x05011340), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_ERR_INFO_NPU_RING_ADDR                       , RULL(0x05011392), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM2_ERR_MASK                                     , RULL(0x05011342), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( CAPP_ERR_RPT_CLR                                        , RULL(0x02010813), SH_UNT_CAPP     , SH_ACS_SCOM_WO   );
REG64( CAPP_0_ERR_RPT_CLR                                      , RULL(0x02010813), SH_UNT_CAPP_0   , SH_ACS_SCOM_WO   );
REG64( CAPP_1_ERR_RPT_CLR                                      , RULL(0x04010813), SH_UNT_CAPP_1   , SH_ACS_SCOM_WO   );

REG64( PU_NPU_CTL_ERR_SCOPE_CTL_CONFIG                         , RULL(0x05011391), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PEC_ERR_STATUS_REG                                      , RULL(0x0D050013), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_ERR_STATUS_REG                                    , RULL(0x0D050013), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_ERR_STATUS_REG                                    , RULL(0x0E050013), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_ERR_STATUS_REG                                    , RULL(0x0F050013), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PU_ESB_CI_BASE                                          , RULL(0x05012916), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_ESB_NOTIFY                                           , RULL(0x05012917), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EXPORT_REGL_CTRL                                     , RULL(0x0001000E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EXTENDED_STATUS_B                                    , RULL(0x000A000C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EXTENDED_STATUS_C                                    , RULL(0x000A100C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EXTENDED_STATUS_D                                    , RULL(0x000A200C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_EXTENDED_STATUS_E                                    , RULL(0x000A300C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PB_CENT_SM1_EXTFIR_ACTION0_REG                       , RULL(0x05011C34), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM_RO   );

REG64( PU_PB_CENT_SM1_EXTFIR_ACTION1_REG                       , RULL(0x05011C35), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM_RO   );

REG64( PU_PB_CENT_SM1_EXTFIR_MASK_REG                          , RULL(0x05011C31), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM_RW   );
REG64( PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND                      , RULL(0x05011C32), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM1_AND );
REG64( PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR                       , RULL(0x05011C33), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM2_OR  );

REG64( PU_PB_CENT_SM1_EXTFIR_REG                               , RULL(0x05011C2E), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM_RW   );
REG64( PU_PB_CENT_SM1_EXTFIR_REG_AND                           , RULL(0x05011C2F), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM1_AND );
REG64( PU_PB_CENT_SM1_EXTFIR_REG_OR                            , RULL(0x05011C30), SH_UNT_PU_PB_CENT_SM1,
       SH_ACS_SCOM2_OR  );

REG64( PU_NPU_CTL_FENCE_0_CONFIG                               , RULL(0x0501138A), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_FENCE_1_CONFIG                               , RULL(0x0501138B), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_FENCE_STATE                                  , RULL(0x05011396), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_FI2C_CFG_PPE                                         , RULL(0xC0000800), SH_UNT          , SH_ACS_PPE       );
REG64( PU_FI2C_CFG_PPE1                                        , RULL(0xC0000810), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_FI2C_CFG_PPE2                                        , RULL(0xC0000818), SH_UNT          , SH_ACS_PPE2      );

REG64( PU_FI2C_SCFG0_PPE                                       , RULL(0xC0000860), SH_UNT          , SH_ACS_PPE       );
REG64( PU_FI2C_SCFG0_PPE1                                      , RULL(0xC0000870), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_FI2C_SCFG0_PPE2                                      , RULL(0xC0000878), SH_UNT          , SH_ACS_PPE2      );

REG64( PU_FI2C_SCFG1_PPE                                       , RULL(0xC0000880), SH_UNT          , SH_ACS_PPE       );
REG64( PU_FI2C_SCFG1_PPE1                                      , RULL(0xC0000890), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_FI2C_SCFG1_PPE2                                      , RULL(0xC0000898), SH_UNT          , SH_ACS_PPE2      );

REG64( PU_FI2C_SCFG2_PPE                                       , RULL(0xC00008A0), SH_UNT          , SH_ACS_PPE       );
REG64( PU_FI2C_SCFG2_PPE1                                      , RULL(0xC00008B0), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_FI2C_SCFG2_PPE2                                      , RULL(0xC00008B8), SH_UNT          , SH_ACS_PPE2      );

REG64( PU_FI2C_SCFG3_PPE                                       , RULL(0xC00008C0), SH_UNT          , SH_ACS_PPE       );
REG64( PU_FI2C_SCFG3_PPE1                                      , RULL(0xC00008D0), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_FI2C_SCFG3_PPE2                                      , RULL(0xC00008D8), SH_UNT          , SH_ACS_PPE2      );

REG64( PU_FI2C_STAT_PPE                                        , RULL(0xC0000820), SH_UNT          , SH_ACS_PPE       );

REG64( PU_FIFO1_REGISTER_READ_B                                , RULL(0x000A0004), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO1_REGISTER_READ_C                                , RULL(0x000A1004), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO1_REGISTER_READ_D                                , RULL(0x000A2004), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO1_REGISTER_READ_E                                , RULL(0x000A3004), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO4_REGISTER_READ_B                                , RULL(0x000A0012), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO4_REGISTER_READ_C                                , RULL(0x000A1012), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO4_REGISTER_READ_D                                , RULL(0x000A2012), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIFO4_REGISTER_READ_E                                , RULL(0x000A3012), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FIR_ACTION0_REG                                      , RULL(0x04011806), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( CAPP_FIR_ACTION0_REG                                    , RULL(0x02010806), SH_UNT_CAPP     , SH_ACS_SCOM_RO   );
REG64( CAPP_0_FIR_ACTION0_REG                                  , RULL(0x02010806), SH_UNT_CAPP_0   , SH_ACS_SCOM_RO   );
REG64( CAPP_1_FIR_ACTION0_REG                                  , RULL(0x04010806), SH_UNT_CAPP_1   , SH_ACS_SCOM_RO   );

REG64( PEC_FIR_ACTION0_REG                                     , RULL(0x0D010C06), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_FIR_ACTION0_REG                                   , RULL(0x0D010C06), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_FIR_ACTION0_REG                                   , RULL(0x0E010C06), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_FIR_ACTION0_REG                                   , RULL(0x0F010C06), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PU_NPU_MSC_SM0_FIR_ACTION0_REG_0                        , RULL(0x05011406), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_MSC_SM2_FIR_ACTION0_REG_1                        , RULL(0x05011446), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM_RW   );

REG64( PU_FIR_ACTION1_REG                                      , RULL(0x04011807), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( CAPP_FIR_ACTION1_REG                                    , RULL(0x02010807), SH_UNT_CAPP     , SH_ACS_SCOM_RO   );
REG64( CAPP_0_FIR_ACTION1_REG                                  , RULL(0x02010807), SH_UNT_CAPP_0   , SH_ACS_SCOM_RO   );
REG64( CAPP_1_FIR_ACTION1_REG                                  , RULL(0x04010807), SH_UNT_CAPP_1   , SH_ACS_SCOM_RO   );

REG64( PEC_FIR_ACTION1_REG                                     , RULL(0x0D010C07), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_FIR_ACTION1_REG                                   , RULL(0x0D010C07), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_FIR_ACTION1_REG                                   , RULL(0x0E010C07), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_FIR_ACTION1_REG                                   , RULL(0x0F010C07), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PU_NPU_MSC_SM0_FIR_ACTION1_REG_0                        , RULL(0x05011407), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_MSC_SM2_FIR_ACTION1_REG_1                        , RULL(0x05011447), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM_RW   );

REG64( PEC_FIR_MASK                                            , RULL(0x0D040002), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_FIR_MASK                                          , RULL(0x0D040002), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_FIR_MASK                                          , RULL(0x0E040002), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_FIR_MASK                                          , RULL(0x0F040002), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_FIR_MASK_REG                                         , RULL(0x04011803), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_FIR_MASK_REG_AND                                     , RULL(0x04011804), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_FIR_MASK_REG_OR                                      , RULL(0x04011805), SH_UNT          , SH_ACS_SCOM2_OR  );
REG64( CAPP_FIR_MASK_REG                                       , RULL(0x02010803), SH_UNT_CAPP     , SH_ACS_SCOM_RW   );
REG64( CAPP_FIR_MASK_REG_AND                                   , RULL(0x02010804), SH_UNT_CAPP     , SH_ACS_SCOM1_AND );
REG64( CAPP_FIR_MASK_REG_OR                                    , RULL(0x02010805), SH_UNT_CAPP     , SH_ACS_SCOM2_OR  );
REG64( CAPP_0_FIR_MASK_REG                                     , RULL(0x02010803), SH_UNT_CAPP_0   , SH_ACS_SCOM_RW   );
REG64( CAPP_0_FIR_MASK_REG_AND                                 , RULL(0x02010804), SH_UNT_CAPP_0   , SH_ACS_SCOM1_AND );
REG64( CAPP_0_FIR_MASK_REG_OR                                  , RULL(0x02010805), SH_UNT_CAPP_0   , SH_ACS_SCOM2_OR  );
REG64( CAPP_1_FIR_MASK_REG                                     , RULL(0x04010803), SH_UNT_CAPP_1   , SH_ACS_SCOM_RW   );
REG64( CAPP_1_FIR_MASK_REG_AND                                 , RULL(0x04010804), SH_UNT_CAPP_1   , SH_ACS_SCOM1_AND );
REG64( CAPP_1_FIR_MASK_REG_OR                                  , RULL(0x04010805), SH_UNT_CAPP_1   , SH_ACS_SCOM2_OR  );

REG64( PEC_FIR_MASK_REG                                        , RULL(0x0D010C03), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_FIR_MASK_REG_AND                                    , RULL(0x0D010C04), SH_UNT_PEC      , SH_ACS_SCOM1_AND );
REG64( PEC_FIR_MASK_REG_OR                                     , RULL(0x0D010C05), SH_UNT_PEC      , SH_ACS_SCOM2_OR  );
REG64( PEC_0_FIR_MASK_REG                                      , RULL(0x0D010C03), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_FIR_MASK_REG_AND                                  , RULL(0x0D010C04), SH_UNT_PEC_0    , SH_ACS_SCOM1_AND );
REG64( PEC_0_FIR_MASK_REG_OR                                   , RULL(0x0D010C05), SH_UNT_PEC_0    , SH_ACS_SCOM2_OR  );
REG64( PEC_1_FIR_MASK_REG                                      , RULL(0x0E010C03), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_FIR_MASK_REG_AND                                  , RULL(0x0E010C04), SH_UNT_PEC_1    , SH_ACS_SCOM1_AND );
REG64( PEC_1_FIR_MASK_REG_OR                                   , RULL(0x0E010C05), SH_UNT_PEC_1    , SH_ACS_SCOM2_OR  );
REG64( PEC_2_FIR_MASK_REG                                      , RULL(0x0F010C03), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_FIR_MASK_REG_AND                                  , RULL(0x0F010C04), SH_UNT_PEC_2    , SH_ACS_SCOM1_AND );
REG64( PEC_2_FIR_MASK_REG_OR                                   , RULL(0x0F010C05), SH_UNT_PEC_2    , SH_ACS_SCOM2_OR  );

REG64( PU_FIR_MASK_REGISTER                                    , RULL(0x00088008), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU_MSC_SM0_FIR_MASK_REG_0                           , RULL(0x05011403), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM_RW   );
REG64( PU_NPU_MSC_SM0_FIR_MASK_REG_0_AND                       , RULL(0x05011404), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM1_AND );
REG64( PU_NPU_MSC_SM0_FIR_MASK_REG_0_OR                        , RULL(0x05011405), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM2_OR  );

REG64( PU_NPU_MSC_SM2_FIR_MASK_REG_1                           , RULL(0x05011443), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM_RW   );
REG64( PU_NPU_MSC_SM2_FIR_MASK_REG_1_AND                       , RULL(0x05011444), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM1_AND );
REG64( PU_NPU_MSC_SM2_FIR_MASK_REG_1_OR                        , RULL(0x05011445), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM2_OR  );

REG64( PU_FIR_REG                                              , RULL(0x04011800), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_FIR_REG_AND                                          , RULL(0x04011801), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_FIR_REG_OR                                           , RULL(0x04011802), SH_UNT          , SH_ACS_SCOM2_OR  );
REG64( CAPP_FIR_REG                                            , RULL(0x02010800), SH_UNT_CAPP     , SH_ACS_SCOM_RW   );
REG64( CAPP_FIR_REG_AND                                        , RULL(0x02010801), SH_UNT_CAPP     , SH_ACS_SCOM1_AND );
REG64( CAPP_FIR_REG_OR                                         , RULL(0x02010802), SH_UNT_CAPP     , SH_ACS_SCOM2_OR  );
REG64( CAPP_0_FIR_REG                                          , RULL(0x02010800), SH_UNT_CAPP_0   , SH_ACS_SCOM_RW   );
REG64( CAPP_0_FIR_REG_AND                                      , RULL(0x02010801), SH_UNT_CAPP_0   , SH_ACS_SCOM1_AND );
REG64( CAPP_0_FIR_REG_OR                                       , RULL(0x02010802), SH_UNT_CAPP_0   , SH_ACS_SCOM2_OR  );
REG64( CAPP_1_FIR_REG                                          , RULL(0x04010800), SH_UNT_CAPP_1   , SH_ACS_SCOM_RW   );
REG64( CAPP_1_FIR_REG_AND                                      , RULL(0x04010801), SH_UNT_CAPP_1   , SH_ACS_SCOM1_AND );
REG64( CAPP_1_FIR_REG_OR                                       , RULL(0x04010802), SH_UNT_CAPP_1   , SH_ACS_SCOM2_OR  );

REG64( PHB_FIR_REG                                             , RULL(0x0D010908), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_FIR_REG_AND                                         , RULL(0x0D010909), SH_UNT_PHB      , SH_ACS_SCOM1_AND );
REG64( PHB_FIR_REG_OR                                          , RULL(0x0D01090A), SH_UNT_PHB      , SH_ACS_SCOM2_OR  );
REG64( PHB_0_FIR_REG                                           , RULL(0x0D010908), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_0_FIR_REG_AND                                       , RULL(0x0D010909), SH_UNT_PHB_0    , SH_ACS_SCOM1_AND );
REG64( PHB_0_FIR_REG_OR                                        , RULL(0x0D01090A), SH_UNT_PHB_0    , SH_ACS_SCOM2_OR  );
REG64( PHB_1_FIR_REG                                           , RULL(0x0E010908), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_1_FIR_REG_AND                                       , RULL(0x0E010909), SH_UNT_PHB_1    , SH_ACS_SCOM1_AND );
REG64( PHB_1_FIR_REG_OR                                        , RULL(0x0E01090A), SH_UNT_PHB_1    , SH_ACS_SCOM2_OR  );
REG64( PHB_2_FIR_REG                                           , RULL(0x0E010948), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_2_FIR_REG_AND                                       , RULL(0x0E010949), SH_UNT_PHB_2    , SH_ACS_SCOM1_AND );
REG64( PHB_2_FIR_REG_OR                                        , RULL(0x0E01094A), SH_UNT_PHB_2    , SH_ACS_SCOM2_OR  );
REG64( PHB_3_FIR_REG                                           , RULL(0x0F010908), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_3_FIR_REG_AND                                       , RULL(0x0F010909), SH_UNT_PHB_3    , SH_ACS_SCOM1_AND );
REG64( PHB_3_FIR_REG_OR                                        , RULL(0x0F01090A), SH_UNT_PHB_3    , SH_ACS_SCOM2_OR  );
REG64( PHB_4_FIR_REG                                           , RULL(0x0F010948), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_4_FIR_REG_AND                                       , RULL(0x0F010949), SH_UNT_PHB_4    , SH_ACS_SCOM1_AND );
REG64( PHB_4_FIR_REG_OR                                        , RULL(0x0F01094A), SH_UNT_PHB_4    , SH_ACS_SCOM2_OR  );
REG64( PHB_5_FIR_REG                                           , RULL(0x0F010988), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );
REG64( PHB_5_FIR_REG_AND                                       , RULL(0x0F010989), SH_UNT_PHB_5    , SH_ACS_SCOM1_AND );
REG64( PHB_5_FIR_REG_OR                                        , RULL(0x0F01098A), SH_UNT_PHB_5    , SH_ACS_SCOM2_OR  );

REG64( PU_NPU_MSC_SM0_FIR_REG_0                                , RULL(0x05011400), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM_RW   );
REG64( PU_NPU_MSC_SM0_FIR_REG_0_AND                            , RULL(0x05011401), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM1_AND );
REG64( PU_NPU_MSC_SM0_FIR_REG_0_OR                             , RULL(0x05011402), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM2_OR  );

REG64( PU_NPU_MSC_SM2_FIR_REG_1                                , RULL(0x05011440), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM_RW   );
REG64( PU_NPU_MSC_SM2_FIR_REG_1_AND                            , RULL(0x05011441), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM1_AND );
REG64( PU_NPU_MSC_SM2_FIR_REG_1_OR                             , RULL(0x05011442), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM2_OR  );

REG64( PEC_FIR_STATUS_REG                                      , RULL(0x0D010C00), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_FIR_STATUS_REG_AND                                  , RULL(0x0D010C01), SH_UNT_PEC      , SH_ACS_SCOM1_AND );
REG64( PEC_FIR_STATUS_REG_OR                                   , RULL(0x0D010C02), SH_UNT_PEC      , SH_ACS_SCOM2_OR  );
REG64( PEC_0_FIR_STATUS_REG                                    , RULL(0x0D010C00), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_FIR_STATUS_REG_AND                                , RULL(0x0D010C01), SH_UNT_PEC_0    , SH_ACS_SCOM1_AND );
REG64( PEC_0_FIR_STATUS_REG_OR                                 , RULL(0x0D010C02), SH_UNT_PEC_0    , SH_ACS_SCOM2_OR  );
REG64( PEC_1_FIR_STATUS_REG                                    , RULL(0x0E010C00), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_FIR_STATUS_REG_AND                                , RULL(0x0E010C01), SH_UNT_PEC_1    , SH_ACS_SCOM1_AND );
REG64( PEC_1_FIR_STATUS_REG_OR                                 , RULL(0x0E010C02), SH_UNT_PEC_1    , SH_ACS_SCOM2_OR  );
REG64( PEC_2_FIR_STATUS_REG                                    , RULL(0x0F010C00), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_FIR_STATUS_REG_AND                                , RULL(0x0F010C01), SH_UNT_PEC_2    , SH_ACS_SCOM1_AND );
REG64( PEC_2_FIR_STATUS_REG_OR                                 , RULL(0x0F010C02), SH_UNT_PEC_2    , SH_ACS_SCOM2_OR  );

REG64( PU_FIR_WOF_REG                                          , RULL(0x04011808), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_FIR_WOF_REG                                         , RULL(0x0D010C08), SH_UNT_PEC      ,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_0_FIR_WOF_REG                                       , RULL(0x0D010C08), SH_UNT_PEC_0    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_1_FIR_WOF_REG                                       , RULL(0x0E010C08), SH_UNT_PEC_1    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_2_FIR_WOF_REG                                       , RULL(0x0F010C08), SH_UNT_PEC_2    ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_NPU_MSC_SM0_FIR_WOF_REG_0                            , RULL(0x05011408), SH_UNT_PU_NPU_MSC_SM0,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_NPU_MSC_SM2_FIR_WOF_REG_1                            , RULL(0x05011448), SH_UNT_PU_NPU_MSC_SM2,
       SH_ACS_SCOM_WCLRREG );

REG64( CAPP_FLUSHCPIG                                          , RULL(0x02010820), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_FLUSHCPIG                                        , RULL(0x02010820), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_FLUSHCPIG                                        , RULL(0x04010820), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_FLUSHSHUE                                          , RULL(0x0201080F), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_FLUSHSHUE                                        , RULL(0x0201080F), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_FLUSHSHUE                                        , RULL(0x0401080F), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_NPU_CTL_FREEZE_0_CONFIG                              , RULL(0x05011388), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_FREEZE_1_CONFIG                              , RULL(0x05011389), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_FREEZE_STATE                                 , RULL(0x05011395), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_FSB_DOWNFIFO_DATA_IN                                 , RULL(0x000B0010), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_FSB_DOWNFIFO_REQ_RESET                               , RULL(0x000B0013), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_FSB_DOWNFIFO_SIG_EOT                                 , RULL(0x000B0012), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_FSB_DOWNFIFO_STATUS                                  , RULL(0x000B0011), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_FSB_UPFIFO_ACK_EOT                                   , RULL(0x000B0005), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_FSB_UPFIFO_DATA_OUT                                  , RULL(0x000B0000), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_FSB_UPFIFO_RESET                                     , RULL(0x000B0004), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_FSB_UPFIFO_STATUS                                    , RULL(0x000B0001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_GENID_BAR                                   , RULL(0x05011007), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_GENID_BAR                                   , RULL(0x05011027), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_GENID_BAR                                   , RULL(0x05011047), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_GENID_BAR                                   , RULL(0x05011067), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_GENID_BAR                                   , RULL(0x05011107), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_GENID_BAR                                   , RULL(0x05011127), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_GENID_BAR                                   , RULL(0x05011147), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_GENID_BAR                                   , RULL(0x05011167), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_GENID_BAR                                   , RULL(0x05011207), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_GENID_BAR                                   , RULL(0x05011227), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_GENID_BAR                                   , RULL(0x05011247), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_GENID_BAR                                   , RULL(0x05011267), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_GPE0_GPEDBG_OCI                                      , RULL(0xC0000010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEDBG_SCOM                                     , RULL(0x00060002), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPEIVPR_OCI                                     , RULL(0xC0000008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEIVPR_SCOM                                    , RULL(0x00060001), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPEMACR_OCI                                     , RULL(0xC0000020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEMACR_SCOM                                    , RULL(0x00060004), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPESTR_OCI                                      , RULL(0xC0000018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPESTR_SCOM                                     , RULL(0x00060003), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPETSEL_OCI                                     , RULL(0xC0000000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPETSEL_SCOM                                    , RULL(0x00060000), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPEXIEDR_OCI                                    , RULL(0xC0000118), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEXIEDR_SCOM                                   , RULL(0x00060023), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE0_GPEXIIAR_OCI                                    , RULL(0xC0000128), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEXIIAR_SCOM                                   , RULL(0x00060025), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPEXIIR_OCI                                     , RULL(0xC0000120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEXIIR_SCOM                                    , RULL(0x00060024), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPEXISPRG0_OCI                                  , RULL(0xC0000110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEXISPRG0_SCOM                                 , RULL(0x00060022), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE0_GPEXIXCR_OCI                                    , RULL(0xC0000100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEXIXCR_SCOM                                   , RULL(0x00060020), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE0_GPEXIXSR_OCI                                    , RULL(0xC0000108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_GPEXIXSR_SCOM                                   , RULL(0x00060021), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE0_MIB_XIDCAC_OCI                                  , RULL(0xC00000D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE0_MIB_XIDCAC_SCOM                                 , RULL(0x0006001A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE0_MIB_XIICAC                                      , RULL(0x00060019), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE0_MIB_XIMEM                                       , RULL(0x00060017), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE0_MIB_XISGB                                       , RULL(0x00060018), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE0_PPE_XIDBGPRO                                    , RULL(0x00060015), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE0_PPE_XIRAMDBG                                    , RULL(0x00060013), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE0_PPE_XIRAMEDR                                    , RULL(0x00060014), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE0_PPE_XIRAMGA                                     , RULL(0x00060012), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE0_PPE_XIRAMRA                                     , RULL(0x00060011), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE0_PPE_XIXCR                                       , RULL(0x00060010), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE1_GPEDBG_OCI                                      , RULL(0xC0010010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEDBG_SCOM                                     , RULL(0x00062002), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPEIVPR_OCI                                     , RULL(0xC0010008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEIVPR_SCOM                                    , RULL(0x00062001), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPEMACR_OCI                                     , RULL(0xC0010020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEMACR_SCOM                                    , RULL(0x00062004), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPESTR_OCI                                      , RULL(0xC0010018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPESTR_SCOM                                     , RULL(0x00062003), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPETSEL_OCI                                     , RULL(0xC0010000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPETSEL_SCOM                                    , RULL(0x00062000), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPEXIEDR_OCI                                    , RULL(0xC0010118), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEXIEDR_SCOM                                   , RULL(0x00062023), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE1_GPEXIIAR_OCI                                    , RULL(0xC0010128), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEXIIAR_SCOM                                   , RULL(0x00062025), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPEXIIR_OCI                                     , RULL(0xC0010120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEXIIR_SCOM                                    , RULL(0x00062024), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPEXISPRG0_OCI                                  , RULL(0xC0010110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEXISPRG0_SCOM                                 , RULL(0x00062022), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE1_GPEXIXCR_OCI                                    , RULL(0xC0010100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEXIXCR_SCOM                                   , RULL(0x00062020), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE1_GPEXIXSR_OCI                                    , RULL(0xC0010108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_GPEXIXSR_SCOM                                   , RULL(0x00062021), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE1_MIB_XIDCAC_OCI                                  , RULL(0xC00100D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE1_MIB_XIDCAC_SCOM                                 , RULL(0x0006201A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE1_MIB_XIICAC                                      , RULL(0x00062019), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE1_MIB_XIMEM                                       , RULL(0x00062017), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE1_MIB_XISGB                                       , RULL(0x00062018), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE1_PPE_XIDBGPRO                                    , RULL(0x00062015), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE1_PPE_XIRAMDBG                                    , RULL(0x00062013), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE1_PPE_XIRAMEDR                                    , RULL(0x00062014), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE1_PPE_XIRAMGA                                     , RULL(0x00062012), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE1_PPE_XIRAMRA                                     , RULL(0x00062011), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE1_PPE_XIXCR                                       , RULL(0x00062010), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE2_GPEDBG_OCI                                      , RULL(0xC0020010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEDBG_SCOM                                     , RULL(0x00064002), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPEIVPR_OCI                                     , RULL(0xC0020008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEIVPR_SCOM                                    , RULL(0x00064001), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPEMACR_OCI                                     , RULL(0xC0020020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEMACR_SCOM                                    , RULL(0x00064004), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPESTR_OCI                                      , RULL(0xC0020018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPESTR_SCOM                                     , RULL(0x00064003), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPETSEL_OCI                                     , RULL(0xC0020000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPETSEL_SCOM                                    , RULL(0x00064000), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPEXIEDR_OCI                                    , RULL(0xC0020118), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEXIEDR_SCOM                                   , RULL(0x00064023), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE2_GPEXIIAR_OCI                                    , RULL(0xC0020128), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEXIIAR_SCOM                                   , RULL(0x00064025), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPEXIIR_OCI                                     , RULL(0xC0020120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEXIIR_SCOM                                    , RULL(0x00064024), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPEXISPRG0_OCI                                  , RULL(0xC0020110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEXISPRG0_SCOM                                 , RULL(0x00064022), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE2_GPEXIXCR_OCI                                    , RULL(0xC0020100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEXIXCR_SCOM                                   , RULL(0x00064020), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE2_GPEXIXSR_OCI                                    , RULL(0xC0020108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_GPEXIXSR_SCOM                                   , RULL(0x00064021), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE2_MIB_XIDCAC_OCI                                  , RULL(0xC00200D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE2_MIB_XIDCAC_SCOM                                 , RULL(0x0006401A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE2_MIB_XIICAC                                      , RULL(0x00064019), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE2_MIB_XIMEM                                       , RULL(0x00064017), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE2_MIB_XISGB                                       , RULL(0x00064018), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE2_PPE_XIDBGPRO                                    , RULL(0x00064015), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE2_PPE_XIRAMDBG                                    , RULL(0x00064013), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE2_PPE_XIRAMEDR                                    , RULL(0x00064014), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE2_PPE_XIRAMGA                                     , RULL(0x00064012), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE2_PPE_XIRAMRA                                     , RULL(0x00064011), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE2_PPE_XIXCR                                       , RULL(0x00064010), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE3_GPEDBG_OCI                                      , RULL(0xC0030010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEDBG_SCOM                                     , RULL(0x00066002), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPEIVPR_OCI                                     , RULL(0xC0030008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEIVPR_SCOM                                    , RULL(0x00066001), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPEMACR_OCI                                     , RULL(0xC0030020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEMACR_SCOM                                    , RULL(0x00066004), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPESTR_OCI                                      , RULL(0xC0030018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPESTR_SCOM                                     , RULL(0x00066003), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPETSEL_OCI                                     , RULL(0xC0030000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPETSEL_SCOM                                    , RULL(0x00066000), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPEXIEDR_OCI                                    , RULL(0xC0030118), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEXIEDR_SCOM                                   , RULL(0x00066023), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE3_GPEXIIAR_OCI                                    , RULL(0xC0030128), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEXIIAR_SCOM                                   , RULL(0x00066025), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPEXIIR_OCI                                     , RULL(0xC0030120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEXIIR_SCOM                                    , RULL(0x00066024), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPEXISPRG0_OCI                                  , RULL(0xC0030110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEXISPRG0_SCOM                                 , RULL(0x00066022), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_GPE3_GPEXIXCR_OCI                                    , RULL(0xC0030100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEXIXCR_SCOM                                   , RULL(0x00066020), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE3_GPEXIXSR_OCI                                    , RULL(0xC0030108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_GPEXIXSR_SCOM                                   , RULL(0x00066021), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE3_MIB_XIDCAC_OCI                                  , RULL(0xC00300D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_GPE3_MIB_XIDCAC_SCOM                                 , RULL(0x0006601A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE3_MIB_XIICAC                                      , RULL(0x00066019), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE3_MIB_XIMEM                                       , RULL(0x00066017), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE3_MIB_XISGB                                       , RULL(0x00066018), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_GPE3_PPE_XIDBGPRO                                    , RULL(0x00066015), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE3_PPE_XIRAMDBG                                    , RULL(0x00066013), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE3_PPE_XIRAMEDR                                    , RULL(0x00066014), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GPE3_PPE_XIRAMGA                                     , RULL(0x00066012), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE3_PPE_XIRAMRA                                     , RULL(0x00066011), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_GPE3_PPE_XIXCR                                       , RULL(0x00066010), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_NPU0_SM0_GPU_BAR                                     , RULL(0x05011004), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_GPU_BAR                                     , RULL(0x05011024), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_GPU_BAR                                     , RULL(0x05011044), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_GPU_BAR                                     , RULL(0x05011064), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_GPU_BAR                                     , RULL(0x05011104), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_GPU_BAR                                     , RULL(0x05011124), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_GPU_BAR                                     , RULL(0x05011144), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_GPU_BAR                                     , RULL(0x05011164), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_GPU_BAR                                     , RULL(0x05011204), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_GPU_BAR                                     , RULL(0x05011224), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_GPU_BAR                                     , RULL(0x05011244), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_GPU_BAR                                     , RULL(0x05011264), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PEC_GXSTOP0_MASK_REG                                    , RULL(0x0D040014), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_GXSTOP0_MASK_REG                                  , RULL(0x0D040014), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_GXSTOP0_MASK_REG                                  , RULL(0x0E040014), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_GXSTOP0_MASK_REG                                  , RULL(0x0F040014), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_GXSTOP1_MASK_REG                                    , RULL(0x0D040015), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_GXSTOP1_MASK_REG                                  , RULL(0x0D040015), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_GXSTOP1_MASK_REG                                  , RULL(0x0E040015), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_GXSTOP1_MASK_REG                                  , RULL(0x0F040015), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_GXSTOP2_MASK_REG                                    , RULL(0x0D040016), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_GXSTOP2_MASK_REG                                  , RULL(0x0D040016), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_GXSTOP2_MASK_REG                                  , RULL(0x0E040016), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_GXSTOP2_MASK_REG                                  , RULL(0x0F040016), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_GXSTOP_TRIG_REG                                     , RULL(0x0D040013), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_GXSTOP_TRIG_REG                                   , RULL(0x0D040013), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_GXSTOP_TRIG_REG                                   , RULL(0x0E040013), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_GXSTOP_TRIG_REG                                   , RULL(0x0F040013), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_GZIP_CONTROL_REG                                     , RULL(0x02011140), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_ERRRPT_HOLD_REG                                 , RULL(0x02011152), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_HI_PRIOR_RCV_FIFO_ASB                           , RULL(0x020110C8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_HI_PRIOR_RCV_FIFO_BAR                           , RULL(0x020110C2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_HI_PRIOR_RCV_FIFO_CNTL                          , RULL(0x020110C5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_LO_PRIOR_RCV_FIFO_ASB                           , RULL(0x020110D1), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_LO_PRIOR_RCV_FIFO_BAR                           , RULL(0x020110CB), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_LO_PRIOR_RCV_FIFO_CNTL                          , RULL(0x020110CE), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_GZIP_MAX_BYTE_CNT                                    , RULL(0x0201105B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_0_REG                                    , RULL(0x0D0F0020), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_0_REG                                  , RULL(0x0D0F0020), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_0_REG                                  , RULL(0x0E0F0020), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_0_REG                                  , RULL(0x0F0F0020), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_1_REG                                    , RULL(0x0D0F0021), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_1_REG                                  , RULL(0x0D0F0021), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_1_REG                                  , RULL(0x0E0F0021), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_1_REG                                  , RULL(0x0F0F0021), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_2_REG                                    , RULL(0x0D0F0022), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_2_REG                                  , RULL(0x0D0F0022), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_2_REG                                  , RULL(0x0E0F0022), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_2_REG                                  , RULL(0x0F0F0022), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_3_REG                                    , RULL(0x0D0F0023), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_3_REG                                  , RULL(0x0D0F0023), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_3_REG                                  , RULL(0x0E0F0023), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_3_REG                                  , RULL(0x0F0F0023), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_4_REG                                    , RULL(0x0D0F0024), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_4_REG                                  , RULL(0x0D0F0024), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_4_REG                                  , RULL(0x0E0F0024), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_4_REG                                  , RULL(0x0F0F0024), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_5_REG                                    , RULL(0x0D0F0025), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_5_REG                                  , RULL(0x0D0F0025), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_5_REG                                  , RULL(0x0E0F0025), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_5_REG                                  , RULL(0x0F0F0025), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_HANG_PULSE_6_REG                                    , RULL(0x0D0F0026), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_HANG_PULSE_6_REG                                  , RULL(0x0D0F0026), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_HANG_PULSE_6_REG                                  , RULL(0x0E0F0026), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_HANG_PULSE_6_REG                                  , RULL(0x0F0F0026), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PU_HCA_BAR                                              , RULL(0x0501298A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_HCA_COUNT_BAR                                        , RULL(0x0501298B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_HCA_DROP                                             , RULL(0x05012991), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_HCA_FLUSH                                            , RULL(0x05012990), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_HCA_MIRROR_BAR                                       , RULL(0x05012993), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_HCA_MODES                                            , RULL(0x0501298F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_HCA_REF_BAR                                          , RULL(0x0501298E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_HCA_RESET                                            , RULL(0x05012992), SH_UNT          , SH_ACS_SCOM_W    );

REG64( PEC_HEARTBEAT_REG                                       , RULL(0x0D0F0018), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_HEARTBEAT_REG                                     , RULL(0x0D0F0018), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_HEARTBEAT_REG                                     , RULL(0x0E0F0018), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_HEARTBEAT_REG                                     , RULL(0x0F0F0018), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_HIGH_WATER                                  , RULL(0x05011009), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_HIGH_WATER                                  , RULL(0x05011029), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_HIGH_WATER                                  , RULL(0x05011049), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_HIGH_WATER                                  , RULL(0x05011069), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_HIGH_WATER                                  , RULL(0x05011109), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_HIGH_WATER                                  , RULL(0x05011129), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_HIGH_WATER                                  , RULL(0x05011149), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_HIGH_WATER                                  , RULL(0x05011169), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_HIGH_WATER                                  , RULL(0x05011209), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_HIGH_WATER                                  , RULL(0x05011229), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_HIGH_WATER                                  , RULL(0x05011249), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_HIGH_WATER                                  , RULL(0x05011269), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PEC_HOSTATTN                                            , RULL(0x0D040009), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_HOSTATTN                                          , RULL(0x0D040009), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_HOSTATTN                                          , RULL(0x0E040009), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_HOSTATTN                                          , RULL(0x0F040009), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_HOSTATTN_MASK                                       , RULL(0x0D04001A), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_HOSTATTN_MASK                                     , RULL(0x0D04001A), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_HOSTATTN_MASK                                     , RULL(0x0E04001A), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_HOSTATTN_MASK                                     , RULL(0x0F04001A), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_HTM0_HTM_CFG                                         , RULL(0x05012888), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_CFG                                         , RULL(0x050128C8), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_CTRL                                        , RULL(0x05012885), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_CTRL                                        , RULL(0x050128C5), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_FILT                                        , RULL(0x05012886), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_FILT                                        , RULL(0x050128C6), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_FLEX                                        , RULL(0x05012889), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_FLEX                                        , RULL(0x050128C9), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_LAST                                        , RULL(0x05012883), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RO   );
REG64( PU_HTM1_HTM_LAST                                        , RULL(0x050128C3), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RO   );

REG64( PU_HTM0_HTM_MEM                                         , RULL(0x05012881), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_MEM                                         , RULL(0x050128C1), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_MODE                                        , RULL(0x05012880), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_MODE                                        , RULL(0x050128C0), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_STAT                                        , RULL(0x05012882), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RO   );
REG64( PU_HTM1_HTM_STAT                                        , RULL(0x050128C2), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RO   );

REG64( PU_HTM0_HTM_TRIG                                        , RULL(0x05012884), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_TRIG                                        , RULL(0x050128C4), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_HTM0_HTM_TTYPEFILT                                   , RULL(0x05012887), SH_UNT_PU_HTM0  , SH_ACS_SCOM_RW   );
REG64( PU_HTM1_HTM_TTYPEFILT                                   , RULL(0x050128C7), SH_UNT_PU_HTM1  , SH_ACS_SCOM_RW   );

REG64( PU_I2C_BUSY_REGISTER_B                                  , RULL(0x000A000E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_I2C_BUSY_REGISTER_C                                  , RULL(0x000A100E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_I2C_BUSY_REGISTER_D                                  , RULL(0x000A200E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_I2C_BUSY_REGISTER_E                                  , RULL(0x000A300E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_ERR_B                                      , RULL(0x000A000C), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_IMM_RESET_ERR_C                                      , RULL(0x000A100C), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_IMM_RESET_ERR_D                                      , RULL(0x000A200C), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_IMM_RESET_ERR_E                                      , RULL(0x000A300C), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_IMM_RESET_I2C_B                                      , RULL(0x000A000B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_I2C_C                                      , RULL(0x000A100B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_I2C_D                                      , RULL(0x000A200B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_I2C_E                                      , RULL(0x000A300B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SCL_B                                    , RULL(0x000A000F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SCL_C                                    , RULL(0x000A100F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SCL_D                                    , RULL(0x000A200F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SCL_E                                    , RULL(0x000A300F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SDA_B                                    , RULL(0x000A0011), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SDA_C                                    , RULL(0x000A1011), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SDA_D                                    , RULL(0x000A2011), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_RESET_S_SDA_E                                    , RULL(0x000A3011), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SCL_B                                      , RULL(0x000A000D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SCL_C                                      , RULL(0x000A100D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SCL_D                                      , RULL(0x000A200D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SCL_E                                      , RULL(0x000A300D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SDA_B                                      , RULL(0x000A0010), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SDA_C                                      , RULL(0x000A1010), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SDA_D                                      , RULL(0x000A2010), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_IMM_SET_S_SDA_E                                      , RULL(0x000A3010), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_INHIBIT_CONFIG                              , RULL(0x05011091), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_INHIBIT_CONFIG                              , RULL(0x05011191), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_INHIBIT_CONFIG                              , RULL(0x05011291), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_INHIBIT_CONFIG                              , RULL(0x05011010), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_INHIBIT_CONFIG                              , RULL(0x05011030), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_INHIBIT_CONFIG                              , RULL(0x05011050), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_INHIBIT_CONFIG                              , RULL(0x05011070), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_INHIBIT_CONFIG                              , RULL(0x05011110), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_INHIBIT_CONFIG                              , RULL(0x05011130), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_INHIBIT_CONFIG                              , RULL(0x05011150), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_INHIBIT_CONFIG                              , RULL(0x05011170), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_INHIBIT_CONFIG                              , RULL(0x05011210), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_INHIBIT_CONFIG                              , RULL(0x05011230), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_INHIBIT_CONFIG                              , RULL(0x05011250), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_INHIBIT_CONFIG                              , RULL(0x05011270), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU_CTL_INHIBIT_CONFIG                               , RULL(0x05011387), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PEC_INJECT_REG                                          , RULL(0x0D050011), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_INJECT_REG                                        , RULL(0x0D050011), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_INJECT_REG                                        , RULL(0x0E050011), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_INJECT_REG                                        , RULL(0x0F050011), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_INTBAR_REG                                 , RULL(0x04010C53), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK1_INTBAR_REG                                 , RULL(0x04010C93), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK2_INTBAR_REG                                 , RULL(0x04010CD3), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK0_INTBAR_REG                                 , RULL(0x04011053), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK1_INTBAR_REG                                 , RULL(0x04011093), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK2_INTBAR_REG                                 , RULL(0x040110D3), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK0_INTBAR_REG                                 , RULL(0x04011453), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK1_INTBAR_REG                                 , RULL(0x04011493), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK2_INTBAR_REG                                 , RULL(0x040114D3), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_STACK0_INTBAR_REG                                   , RULL(0x04010C53), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_STACK1_INTBAR_REG                                   , RULL(0x04010C93), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_STACK2_INTBAR_REG                                   , RULL(0x04010CD3), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM      );
REG64( PHB_INTBAR_REG                                          , RULL(0x04010C53), SH_UNT_PHB      , SH_ACS_SCOM      );
REG64( PHB_0_INTBAR_REG                                        , RULL(0x04010C53), SH_UNT_PHB_0    , SH_ACS_SCOM      );
REG64( PHB_1_INTBAR_REG                                        , RULL(0x04011053), SH_UNT_PHB_1    , SH_ACS_SCOM      );
REG64( PHB_2_INTBAR_REG                                        , RULL(0x04011093), SH_UNT_PHB_2    , SH_ACS_SCOM      );
REG64( PHB_3_INTBAR_REG                                        , RULL(0x04011453), SH_UNT_PHB_3    , SH_ACS_SCOM      );
REG64( PHB_4_INTBAR_REG                                        , RULL(0x04011493), SH_UNT_PHB_4    , SH_ACS_SCOM      );
REG64( PHB_5_INTBAR_REG                                        , RULL(0x040114D3), SH_UNT_PHB_5    , SH_ACS_SCOM      );

REG64( PU_INTERRUPTS_B                                         , RULL(0x000A000A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPTS_C                                         , RULL(0x000A100A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPTS_D                                         , RULL(0x000A200A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPTS_E                                         , RULL(0x000A300A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_COND_B                                     , RULL(0x000A0009), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_COND_C                                     , RULL(0x000A1009), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_COND_D                                     , RULL(0x000A2009), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_COND_E                                     , RULL(0x000A3009), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_MASK_REGISTER_B_WO                         , RULL(0x000A0008), SH_UNT          , SH_ACS_SCOM_WO   );
REG64( PU_INTERRUPT_MASK_REGISTER_B_OR                         , RULL(0x000A0009), SH_UNT          , SH_ACS_SCOM1_OR  );
REG64( PU_INTERRUPT_MASK_REGISTER_B_AND                        , RULL(0x000A000A), SH_UNT          , SH_ACS_SCOM2_AND );

REG64( PU_INTERRUPT_MASK_REGISTER_C_WO                         , RULL(0x000A1008), SH_UNT          , SH_ACS_SCOM_WO   );
REG64( PU_INTERRUPT_MASK_REGISTER_C_OR                         , RULL(0x000A1009), SH_UNT          , SH_ACS_SCOM1_OR  );
REG64( PU_INTERRUPT_MASK_REGISTER_C_AND                        , RULL(0x000A100A), SH_UNT          , SH_ACS_SCOM2_AND );

REG64( PU_INTERRUPT_MASK_REGISTER_D_WO                         , RULL(0x000A2008), SH_UNT          , SH_ACS_SCOM_WO   );
REG64( PU_INTERRUPT_MASK_REGISTER_D_OR                         , RULL(0x000A2009), SH_UNT          , SH_ACS_SCOM1_OR  );
REG64( PU_INTERRUPT_MASK_REGISTER_D_AND                        , RULL(0x000A200A), SH_UNT          , SH_ACS_SCOM2_AND );

REG64( PU_INTERRUPT_MASK_REGISTER_E_WO                         , RULL(0x000A3008), SH_UNT          , SH_ACS_SCOM_WO   );
REG64( PU_INTERRUPT_MASK_REGISTER_E_OR                         , RULL(0x000A3009), SH_UNT          , SH_ACS_SCOM1_OR  );
REG64( PU_INTERRUPT_MASK_REGISTER_E_AND                        , RULL(0x000A300A), SH_UNT          , SH_ACS_SCOM2_AND );

REG64( PU_INTERRUPT_MASK_REGISTER_READ_B                       , RULL(0x000A0008), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_MASK_REGISTER_READ_C                       , RULL(0x000A1008), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_MASK_REGISTER_READ_D                       , RULL(0x000A2008), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INTERRUPT_MASK_REGISTER_READ_E                       , RULL(0x000A3008), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU_CTL_INT_0_CONFIG                                 , RULL(0x0501138C), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_INT_1_CONFIG                                 , RULL(0x0501138D), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_INT_BAR                                      , RULL(0x05011393), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_INT_CQ_ACTION0                                       , RULL(0x05013036), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_ACTION1                                       , RULL(0x05013037), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_AIB_CTL                                       , RULL(0x05013022), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_CQ_CFG_LDQ                                       , RULL(0x05013026), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_CFG_PB_GEN                                    , RULL(0x0501300A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_CQ_CFG_STQ1                                      , RULL(0x05013024), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_CFG_STQ2                                      , RULL(0x05013025), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_CNPM_SEL                                      , RULL(0x0501300F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_ERR_INFO0                                     , RULL(0x0501303A), SH_UNT          ,
       SH_ACS_SCOM_WCLRPART );

REG64( PU_INT_CQ_ERR_INFO1                                     , RULL(0x0501303B), SH_UNT          ,
       SH_ACS_SCOM_WCLRPART );

REG64( PU_INT_CQ_ERR_INFO2                                     , RULL(0x0501303C), SH_UNT          ,
       SH_ACS_SCOM_WCLRPART );

REG64( PU_INT_CQ_ERR_INFO3                                     , RULL(0x0501303D), SH_UNT          ,
       SH_ACS_SCOM_WCLRPART );

REG64( PU_INT_CQ_ERR_RPT_HOLD                                  , RULL(0x05013039), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_FIR                                           , RULL(0x05013030), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_FIRMASK                                       , RULL(0x05013033), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_IC_BAR                                        , RULL(0x05013010), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_MSGSND                                        , RULL(0x0501300B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_PBI_CTL                                       , RULL(0x05013020), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_CQ_PBO_CTL                                       , RULL(0x05013021), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_CQ_PC_BAR                                        , RULL(0x05013016), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_PC_BARM                                       , RULL(0x05013017), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_PMC_0                                         , RULL(0x05013028), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_1                                         , RULL(0x05013029), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_2                                         , RULL(0x0501302A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_3                                         , RULL(0x0501302B), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_4                                         , RULL(0x0501302C), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_5                                         , RULL(0x0501302D), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_6                                         , RULL(0x0501302E), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PMC_7                                         , RULL(0x0501302F), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_PM_CTL                                        , RULL(0x05013027), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_CQ_RST_CTL                                       , RULL(0x05013023), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_CQ_SWI_RSP                                       , RULL(0x05013009), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_CQ_TAR                                           , RULL(0x0501301E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_TM1_BAR                                       , RULL(0x05013012), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_TM2_BAR                                       , RULL(0x05013014), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_VC_BAR                                        , RULL(0x05013018), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_CQ_VC_BARM                                       , RULL(0x05013019), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_NPU_NTL1_INT_LOG_PE0                                 , RULL(0x050113E0), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE1                                 , RULL(0x050113E1), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE10                                , RULL(0x050113EA), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE11                                , RULL(0x050113EB), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE12                                , RULL(0x050113EC), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE13                                , RULL(0x050113ED), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE14                                , RULL(0x050113EE), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE15                                , RULL(0x050113EF), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE2                                 , RULL(0x050113E2), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE3                                 , RULL(0x050113E3), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE4                                 , RULL(0x050113E4), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE5                                 , RULL(0x050113E5), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE6                                 , RULL(0x050113E6), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE7                                 , RULL(0x050113E7), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE8                                 , RULL(0x050113E8), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL1_INT_LOG_PE9                                 , RULL(0x050113E9), SH_UNT_PU_NPU_NTL1,
       SH_ACS_SCOM      );

REG64( PU_INT_PC_AIB_RX_CRD_CMD                                , RULL(0x05013121), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AIB_RX_CRD_DAT                                , RULL(0x05013122), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AIB_RX_CRD_INIT                               , RULL(0x05013120), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AIB_TX_CRD                                    , RULL(0x05013124), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AIB_TX_ORDER                                  , RULL(0x05013126), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AIB_TX_PRIO                                   , RULL(0x05013125), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AT_KILL                                       , RULL(0x05013116), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_AT_KILL_MASK                                  , RULL(0x05013117), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_ECC                                       , RULL(0x05013131), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_PMC                                       , RULL(0x05013134), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_PMC_ATX0                                  , RULL(0x05013135), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_PMC_ATX1                                  , RULL(0x05013136), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_PMC_ATX2                                  , RULL(0x05013137), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_TMOT                                      , RULL(0x05013130), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_DBG_TRACE                                     , RULL(0x05013133), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_EQD_BLOCK_MODE                                , RULL(0x05013114), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_ERR0_CFG0                                     , RULL(0x05013140), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_ERR0_CFG1                                     , RULL(0x05013141), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_ERR0_FATAL                                    , RULL(0x05013144), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR0_INFO                                     , RULL(0x05013146), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR0_RECOV                                    , RULL(0x05013145), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR0_WOF                                      , RULL(0x05013142), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR0_WOF_DETAIL                               , RULL(0x05013143), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_PC_ERR1_CFG0                                     , RULL(0x05013148), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_ERR1_CFG1                                     , RULL(0x05013149), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_ERR1_FATAL                                    , RULL(0x0501314C), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR1_INFO                                     , RULL(0x0501314E), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR1_RECOV                                    , RULL(0x0501314D), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR1_WOF                                      , RULL(0x0501314A), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_ERR1_WOF_DETAIL                               , RULL(0x0501314B), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_PC_GLOBAL_CFG                                    , RULL(0x05013110), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_IVE_BLOCK_MODE                                , RULL(0x05013113), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_MMIO_ARB                                      , RULL(0x0501311A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_PCMD_ARB                                      , RULL(0x05013118), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_ADDITIONAL_PERF_1                         , RULL(0x05013174), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_PC_VPC_ADDITIONAL_PERF_2                         , RULL(0x05013175), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_PC_VPC_CACHE_EN                                  , RULL(0x05013161), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_DATA0                         , RULL(0x05013168), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_DATA2                         , RULL(0x0501316A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_DATA3                         , RULL(0x0501316B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_DATA4                         , RULL(0x0501316C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_DATA6                         , RULL(0x0501316E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_DATA7                         , RULL(0x0501316F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_CACHE_WATCH_SPEC                          , RULL(0x05013167), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_PC_VPC_CONFIG                                    , RULL(0x05013164), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_DEBUG                                     , RULL(0x05013170), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_ERR_CFG0                                  , RULL(0x05013178), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_ERR_CFG1                                  , RULL(0x05013179), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_FATAL_ERR                                 , RULL(0x0501317C), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_VPC_INFO_ERR                                  , RULL(0x0501317E), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_VPC_MAX_OUTSTANDING_OUTB_CMD                  , RULL(0x05013160), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_PERF_EVENT_SEL_1                          , RULL(0x05013171), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_PERF_EVENT_SEL_2                          , RULL(0x05013172), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_PERF_EVENT_SEL_3                          , RULL(0x05013173), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_RECOV_ERR                                 , RULL(0x0501317D), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_VPC_SCRUB_MASK                                , RULL(0x05013163), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_SCRUB_TRIG                                , RULL(0x05013162), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VPC_WOF_ERR                                   , RULL(0x0501317A), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_PC_VPC_WOF_ERR_DETAIL                            , RULL(0x0501317B), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_PC_VPD_BLOCK_MODE                                , RULL(0x05013115), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VRQ_CFG                                       , RULL(0x0501311C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VRQ_PEND_ARB                                  , RULL(0x0501311D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VRQ_VPC_ARB                                   , RULL(0x0501311F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VRQ_VPC_CRD                                   , RULL(0x0501311E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_PC_VSD_TABLE_ADDR                                , RULL(0x05013111), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_NPU_CTL_INT_REQ                                      , RULL(0x05011397), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_INT_TCTXT_CFG                                        , RULL(0x05013100), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_EN0                                        , RULL(0x05013108), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_EN1                                        , RULL(0x0501310C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_INDIR0                                     , RULL(0x05013104), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_INDIR1                                     , RULL(0x05013105), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_INDIR2                                     , RULL(0x05013106), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_INDIR3                                     , RULL(0x05013107), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_TCTXT_TRACK                                      , RULL(0x05013101), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_AIB_TIMEOUT                                   , RULL(0x0501322B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_AIB_TX_CMD_PRIORITY                           , RULL(0x0501323D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_AIB_TX_ORDERING_TAG_1                         , RULL(0x0501322C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_AIB_TX_ORDERING_TAG_2                         , RULL(0x0501322D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ATX_INIT_CREDIT_COUNT                         , RULL(0x0501323C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ATX_PERF_EVENT_SEL_1                          , RULL(0x05013240), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ATX_PERF_EVENT_SEL_2                          , RULL(0x05013241), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ATX_PERF_EVENT_SEL_3                          , RULL(0x05013242), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_AT_MACRO_KILL                                 , RULL(0x0501323E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_AT_MACRO_KILL_MASK                            , RULL(0x0501323F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_ADDITIONAL_PERF_1                         , RULL(0x05013253), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_EQC_ADDITIONAL_PERF_2                         , RULL(0x05013254), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_EQC_CACHE_EN                                  , RULL(0x05013211), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_CACHE_WATCH_DATA0                         , RULL(0x05013216), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_CACHE_WATCH_DATA1                         , RULL(0x05013217), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_CACHE_WATCH_DATA2                         , RULL(0x05013218), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_CACHE_WATCH_DATA3                         , RULL(0x05013219), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_CACHE_WATCH_SPEC                          , RULL(0x05013215), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_EQC_CONFIG                                    , RULL(0x05013214), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_DEBUG                                     , RULL(0x0501321A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_PERF_EVENT_SEL_1                          , RULL(0x05013250), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_PERF_EVENT_SEL_2                          , RULL(0x05013251), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_PERF_EVENT_SEL_3                          , RULL(0x05013252), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_SCRUB_MASK                                , RULL(0x05013213), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQC_SCRUB_TRIG                                , RULL(0x05013212), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_EQD_BLOCK_MODE                                , RULL(0x05013204), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ERR_CFG_G0R0                                  , RULL(0x05013270), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ERR_CFG_G0R1                                  , RULL(0x05013271), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ERR_CFG_G1R0                                  , RULL(0x05013272), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_ERR_CFG_G1R1                                  , RULL(0x05013273), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_FATAL_ERR_G0                                  , RULL(0x05013278), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_FATAL_ERR_G1                                  , RULL(0x0501327B), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_GLOBAL_CONFIG                                 , RULL(0x05013200), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_INFO_ERR_G0                                   , RULL(0x0501327A), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_INFO_ERR_G1                                   , RULL(0x0501327D), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_IRQ_CONFIG_0                                  , RULL(0x05013208), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_IRQ_CONFIG_1                                  , RULL(0x05013209), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_IRQ_CONFIG_2                                  , RULL(0x0501320A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_IRQ_CONFIG_3                                  , RULL(0x0501320B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_IRQ_CONFIG_4                                  , RULL(0x0501320C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_IRQ_CONFIG_5                                  , RULL(0x0501320D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_INT_VC_IRQ_PERF_EVENT_SEL_0                          , RULL(0x05013268), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IRQ_PERF_EVENT_SEL_1                          , RULL(0x05013269), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IRQ_PERF_EVENT_SEL_2                          , RULL(0x0501326A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IRQ_PERF_EVENT_SEL_3                          , RULL(0x0501326B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IRQ_PERF_EVENT_SEL_4                          , RULL(0x0501326C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IRQ_PERF_EVENT_SEL_5                          , RULL(0x0501326D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IRQ_TO_EQC_CREDITS                            , RULL(0x0501320E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_ADDITIONAL_PERF                           , RULL(0x0501325B), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_IVC_CACHE_EN                                  , RULL(0x05013221), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_CACHE_WATCH_ADDR                          , RULL(0x05013225), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_CACHE_WATCH_DATA                          , RULL(0x05013226), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_IVC_DEBUG                                     , RULL(0x0501322A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_HASH_1                                    , RULL(0x05013227), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_HASH_2                                    , RULL(0x05013228), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_HASH_3                                    , RULL(0x05013229), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_PERF_EVENT_SEL_1                          , RULL(0x05013258), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_PERF_EVENT_SEL_2                          , RULL(0x05013259), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_PERF_EVENT_SEL_3                          , RULL(0x0501325A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_SCRUB_MASK                                , RULL(0x05013223), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVC_SCRUB_TRIG                                , RULL(0x05013222), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_IVE_ISB_BLOCK_MODE                            , RULL(0x05013203), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_LBS6_DEBUG                                    , RULL(0x05013206), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_MAX_OUTSTANDING_EQC_OUTB_CMD                  , RULL(0x05013210), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_MAX_OUTSTANDING_IRQ_DMA                       , RULL(0x0501323B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_MAX_OUTSTANDING_IVC_CMD                       , RULL(0x05013220), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_MAX_OUTSTANDING_SBC_CMD                       , RULL(0x05013230), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_RECOV_ERR_G0                                  , RULL(0x05013279), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_RECOV_ERR_G1                                  , RULL(0x0501327C), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_SBC_ADDITIONAL_PERF                           , RULL(0x05013263), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_SBC_CACHE_EN                                  , RULL(0x05013231), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_CACHE_WATCH_ADDR                          , RULL(0x05013235), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_CACHE_WATCH_DATA                          , RULL(0x05013236), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_SBC_CONFIG                                    , RULL(0x05013234), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_DEBUG                                     , RULL(0x0501323A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_PERF_EVENT_SEL_1                          , RULL(0x05013260), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_PERF_EVENT_SEL_2                          , RULL(0x05013261), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_PERF_EVENT_SEL_3                          , RULL(0x05013262), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_SCRUB_MASK                                , RULL(0x05013233), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_SCRUB_TRIG                                , RULL(0x05013232), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_SOFTWR_ADDR                               , RULL(0x05013237), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_SOFTWR_DATA                               , RULL(0x05013239), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_SBC_SOFTWR_MASK                               , RULL(0x05013238), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_VPS_BLOCK_MODE                                , RULL(0x05013205), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_VSD_TABLE_ADDR                                , RULL(0x05013201), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_INT_VC_WOF_ERR_G0                                    , RULL(0x05013274), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_WOF_ERR_G0_DETAIL                             , RULL(0x05013275), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_INT_VC_WOF_ERR_G1                                    , RULL(0x05013276), SH_UNT          ,
       SH_ACS_SCOM_CLRPART );

REG64( PU_INT_VC_WOF_ERR_G1_DETAIL                             , RULL(0x05013277), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_NPU_SM1_IODA_ADDR                                    , RULL(0x05011321), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_IODA_DAT0                                    , RULL(0x05011322), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM      );

REG64( PU_IVT_OFFSET                                           , RULL(0x05012918), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_JTG_PIB_OJCFG                                        , RULL(0x0006D004), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_JTG_PIB_OJCFG_AND                                    , RULL(0x0006D005), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_JTG_PIB_OJCFG_OR                                     , RULL(0x0006D006), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_JTG_PIB_OJFRST                                       , RULL(0x0006D007), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_JTG_PIB_OJIC_SCOM                                    , RULL(0x0006D008), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_JTG_PIB_OJIC_SCOM1                                   , RULL(0x0006D009), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_JTG_PIB_OJIC_SCOM2                                   , RULL(0x0006D00A), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_JTG_PIB_OJSTAT                                       , RULL(0x0006D00B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_JTG_PIB_OJTDI                                        , RULL(0x0006D00C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_JTG_PIB_OJTDO                                        , RULL(0x0006D00D), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_NPU_CTL_LCO_CONFIG                                   , RULL(0x05011382), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA0                              , RULL(0x02010850), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA0                            , RULL(0x02010850), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA0                            , RULL(0x04010850), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA1                              , RULL(0x02010851), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA1                            , RULL(0x02010851), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA1                            , RULL(0x04010851), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA10                             , RULL(0x0201085A), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA10                           , RULL(0x0201085A), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA10                           , RULL(0x0401085A), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA11                             , RULL(0x0201085B), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA11                           , RULL(0x0201085B), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA11                           , RULL(0x0401085B), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA12                             , RULL(0x0201085C), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA12                           , RULL(0x0201085C), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA12                           , RULL(0x0401085C), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA13                             , RULL(0x0201085D), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA13                           , RULL(0x0201085D), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA13                           , RULL(0x0401085D), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA14                             , RULL(0x0201085E), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA14                           , RULL(0x0201085E), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA14                           , RULL(0x0401085E), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA15                             , RULL(0x0201085F), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA15                           , RULL(0x0201085F), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA15                           , RULL(0x0401085F), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA2                              , RULL(0x02010852), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA2                            , RULL(0x02010852), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA2                            , RULL(0x04010852), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA3                              , RULL(0x02010853), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA3                            , RULL(0x02010853), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA3                            , RULL(0x04010853), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA4                              , RULL(0x02010854), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA4                            , RULL(0x02010854), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA4                            , RULL(0x04010854), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA5                              , RULL(0x02010855), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA5                            , RULL(0x02010855), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA5                            , RULL(0x04010855), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA6                              , RULL(0x02010856), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA6                            , RULL(0x02010856), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA6                            , RULL(0x04010856), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA7                              , RULL(0x02010857), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA7                            , RULL(0x02010857), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA7                            , RULL(0x04010857), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA8                              , RULL(0x02010858), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA8                            , RULL(0x02010858), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA8                            , RULL(0x04010858), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_RESP_DATA9                              , RULL(0x02010859), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_RESP_DATA9                            , RULL(0x02010859), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_RESP_DATA9                            , RULL(0x04010859), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_LINK_DELAY_TIMER                                   , RULL(0x02010845), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_LINK_DELAY_TIMER                                 , RULL(0x02010845), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_LINK_DELAY_TIMER                                 , RULL(0x04010845), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PEC_LOCAL_FIR                                           , RULL(0x0D04000A), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_LOCAL_FIR_AND                                       , RULL(0x0D04000B), SH_UNT_PEC      , SH_ACS_SCOM1_AND );
REG64( PEC_LOCAL_FIR_OR                                        , RULL(0x0D04000C), SH_UNT_PEC      , SH_ACS_SCOM2_OR  );
REG64( PEC_0_LOCAL_FIR                                         , RULL(0x0D04000A), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_LOCAL_FIR_AND                                     , RULL(0x0D04000B), SH_UNT_PEC_0    , SH_ACS_SCOM1_AND );
REG64( PEC_0_LOCAL_FIR_OR                                      , RULL(0x0D04000C), SH_UNT_PEC_0    , SH_ACS_SCOM2_OR  );
REG64( PEC_1_LOCAL_FIR                                         , RULL(0x0E04000A), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_LOCAL_FIR_AND                                     , RULL(0x0E04000B), SH_UNT_PEC_1    , SH_ACS_SCOM1_AND );
REG64( PEC_1_LOCAL_FIR_OR                                      , RULL(0x0E04000C), SH_UNT_PEC_1    , SH_ACS_SCOM2_OR  );
REG64( PEC_2_LOCAL_FIR                                         , RULL(0x0F04000A), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_LOCAL_FIR_AND                                     , RULL(0x0F04000B), SH_UNT_PEC_2    , SH_ACS_SCOM1_AND );
REG64( PEC_2_LOCAL_FIR_OR                                      , RULL(0x0F04000C), SH_UNT_PEC_2    , SH_ACS_SCOM2_OR  );

REG64( PEC_LOCAL_FIR_ACTION0                                   , RULL(0x0D040010), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_LOCAL_FIR_ACTION0                                 , RULL(0x0D040010), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_LOCAL_FIR_ACTION0                                 , RULL(0x0E040010), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_LOCAL_FIR_ACTION0                                 , RULL(0x0F040010), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_LOCAL_FIR_ACTION1                                   , RULL(0x0D040011), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_LOCAL_FIR_ACTION1                                 , RULL(0x0D040011), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_LOCAL_FIR_ACTION1                                 , RULL(0x0E040011), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_LOCAL_FIR_ACTION1                                 , RULL(0x0F040011), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_LOCAL_FIR_MASK                                      , RULL(0x0D04000D), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_LOCAL_FIR_MASK_AND                                  , RULL(0x0D04000E), SH_UNT_PEC      , SH_ACS_SCOM1_AND );
REG64( PEC_LOCAL_FIR_MASK_OR                                   , RULL(0x0D04000F), SH_UNT_PEC      , SH_ACS_SCOM2_OR  );
REG64( PEC_0_LOCAL_FIR_MASK                                    , RULL(0x0D04000D), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_0_LOCAL_FIR_MASK_AND                                , RULL(0x0D04000E), SH_UNT_PEC_0    , SH_ACS_SCOM1_AND );
REG64( PEC_0_LOCAL_FIR_MASK_OR                                 , RULL(0x0D04000F), SH_UNT_PEC_0    , SH_ACS_SCOM2_OR  );
REG64( PEC_1_LOCAL_FIR_MASK                                    , RULL(0x0E04000D), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_1_LOCAL_FIR_MASK_AND                                , RULL(0x0E04000E), SH_UNT_PEC_1    , SH_ACS_SCOM1_AND );
REG64( PEC_1_LOCAL_FIR_MASK_OR                                 , RULL(0x0E04000F), SH_UNT_PEC_1    , SH_ACS_SCOM2_OR  );
REG64( PEC_2_LOCAL_FIR_MASK                                    , RULL(0x0F04000D), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );
REG64( PEC_2_LOCAL_FIR_MASK_AND                                , RULL(0x0F04000E), SH_UNT_PEC_2    , SH_ACS_SCOM1_AND );
REG64( PEC_2_LOCAL_FIR_MASK_OR                                 , RULL(0x0F04000F), SH_UNT_PEC_2    , SH_ACS_SCOM2_OR  );

REG64( PEC_LOCAL_XSTOP_ERR                                     , RULL(0x0D040018), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_LOCAL_XSTOP_ERR                                   , RULL(0x0D040018), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_LOCAL_XSTOP_ERR                                   , RULL(0x0E040018), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_LOCAL_XSTOP_ERR                                   , RULL(0x0F040018), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_LOCAL_XSTOP_MASK                                    , RULL(0x0D040019), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_LOCAL_XSTOP_MASK                                  , RULL(0x0D040019), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_LOCAL_XSTOP_MASK                                  , RULL(0x0E040019), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_LOCAL_XSTOP_MASK                                  , RULL(0x0F040019), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( NV_LOW_PWR                                              , RULL(0x050110DC), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_LOW_PWR                                            , RULL(0x050110DC), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_LOW_PWR                                            , RULL(0x050110FC), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_LOW_PWR                                            , RULL(0x050111DC), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_LOW_PWR                                            , RULL(0x050111FC), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_LOW_PWR                                    , RULL(0x050112DC), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_LOW_PWR                                    , RULL(0x050112FC), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_LOW_WATER                                   , RULL(0x05011008), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_LOW_WATER                                   , RULL(0x05011028), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_LOW_WATER                                   , RULL(0x05011048), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_LOW_WATER                                   , RULL(0x05011068), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_LOW_WATER                                   , RULL(0x05011108), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_LOW_WATER                                   , RULL(0x05011128), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_LOW_WATER                                   , RULL(0x05011148), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_LOW_WATER                                   , RULL(0x05011168), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_LOW_WATER                                   , RULL(0x05011208), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_LOW_WATER                                   , RULL(0x05011228), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_LOW_WATER                                   , RULL(0x05011248), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_LOW_WATER                                   , RULL(0x05011268), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_LPCTH_CONFIG                                , RULL(0x05011090), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_LPCTH_CONFIG                                , RULL(0x05011190), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_LPCTH_CONFIG                                , RULL(0x05011290), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PHB_MASK_REG                                            , RULL(0x0D01090B), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_MASK_REG_AND                                        , RULL(0x0D01090C), SH_UNT_PHB      , SH_ACS_SCOM1_AND );
REG64( PHB_MASK_REG_OR                                         , RULL(0x0D01090D), SH_UNT_PHB      , SH_ACS_SCOM2_OR  );
REG64( PHB_0_MASK_REG                                          , RULL(0x0D01090B), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_0_MASK_REG_AND                                      , RULL(0x0D01090C), SH_UNT_PHB_0    , SH_ACS_SCOM1_AND );
REG64( PHB_0_MASK_REG_OR                                       , RULL(0x0D01090D), SH_UNT_PHB_0    , SH_ACS_SCOM2_OR  );
REG64( PHB_1_MASK_REG                                          , RULL(0x0E01090B), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_1_MASK_REG_AND                                      , RULL(0x0E01090C), SH_UNT_PHB_1    , SH_ACS_SCOM1_AND );
REG64( PHB_1_MASK_REG_OR                                       , RULL(0x0E01090D), SH_UNT_PHB_1    , SH_ACS_SCOM2_OR  );
REG64( PHB_2_MASK_REG                                          , RULL(0x0E01094B), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_2_MASK_REG_AND                                      , RULL(0x0E01094C), SH_UNT_PHB_2    , SH_ACS_SCOM1_AND );
REG64( PHB_2_MASK_REG_OR                                       , RULL(0x0E01094D), SH_UNT_PHB_2    , SH_ACS_SCOM2_OR  );
REG64( PHB_3_MASK_REG                                          , RULL(0x0F01090B), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_3_MASK_REG_AND                                      , RULL(0x0F01090C), SH_UNT_PHB_3    , SH_ACS_SCOM1_AND );
REG64( PHB_3_MASK_REG_OR                                       , RULL(0x0F01090D), SH_UNT_PHB_3    , SH_ACS_SCOM2_OR  );
REG64( PHB_4_MASK_REG                                          , RULL(0x0F01094B), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_4_MASK_REG_AND                                      , RULL(0x0F01094C), SH_UNT_PHB_4    , SH_ACS_SCOM1_AND );
REG64( PHB_4_MASK_REG_OR                                       , RULL(0x0F01094D), SH_UNT_PHB_4    , SH_ACS_SCOM2_OR  );
REG64( PHB_5_MASK_REG                                          , RULL(0x0F01098B), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );
REG64( PHB_5_MASK_REG_AND                                      , RULL(0x0F01098C), SH_UNT_PHB_5    , SH_ACS_SCOM1_AND );
REG64( PHB_5_MASK_REG_OR                                       , RULL(0x0F01098D), SH_UNT_PHB_5    , SH_ACS_SCOM2_OR  );

REG64( PU_NPU0_SM0_MAX_PHY_BAR                                 , RULL(0x05011006), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_MAX_PHY_BAR                                 , RULL(0x05011026), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_MAX_PHY_BAR                                 , RULL(0x05011046), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_MAX_PHY_BAR                                 , RULL(0x05011066), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_MAX_PHY_BAR                                 , RULL(0x05011106), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_MAX_PHY_BAR                                 , RULL(0x05011126), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_MAX_PHY_BAR                                 , RULL(0x05011146), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_MAX_PHY_BAR                                 , RULL(0x05011166), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_MAX_PHY_BAR                                 , RULL(0x05011206), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_MAX_PHY_BAR                                 , RULL(0x05011226), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_MAX_PHY_BAR                                 , RULL(0x05011246), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_MAX_PHY_BAR                                 , RULL(0x05011266), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_MCC_FIR_REG                                          , RULL(0x03011400), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCC_FIR_REG_AND                                      , RULL(0x03011401), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_MCC_FIR_REG_OR                                       , RULL(0x03011402), SH_UNT          , SH_ACS_SCOM2_OR  );
REG64( PU_MCD1_MCC_FIR_REG                                     , RULL(0x03011000), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_MCC_FIR_REG_AND                                 , RULL(0x03011001), SH_UNT_PU_MCD1  , SH_ACS_SCOM1_AND );
REG64( PU_MCD1_MCC_FIR_REG_OR                                  , RULL(0x03011002), SH_UNT_PU_MCD1  , SH_ACS_SCOM2_OR  );

REG64( PU_MCD_DBG                                              , RULL(0x03011413), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_MCD1_MCD_DBG                                         , RULL(0x03011013), SH_UNT_PU_MCD1  , SH_ACS_SCOM      );

REG64( PU_MCD_ECAP                                             , RULL(0x03011412), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_MCD1_MCD_ECAP                                        , RULL(0x03011012), SH_UNT_PU_MCD1  , SH_ACS_SCOM      );

REG64( PU_MCD_FIR_ACTION0_REG                                  , RULL(0x03011406), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_MCD_FIR_ACTION0_REG                             , RULL(0x03011006), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_MCD_FIR_ACTION1_REG                                  , RULL(0x03011407), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_MCD_FIR_ACTION1_REG                             , RULL(0x03011007), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );

REG64( PU_MCD_FIR_MASK_REG                                     , RULL(0x03011403), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_MCD_FIR_MASK_REG_AND                                 , RULL(0x03011404), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_MCD_FIR_MASK_REG_OR                                  , RULL(0x03011405), SH_UNT          , SH_ACS_SCOM2_OR  );
REG64( PU_MCD1_MCD_FIR_MASK_REG                                , RULL(0x03011003), SH_UNT_PU_MCD1  , SH_ACS_SCOM_RW   );
REG64( PU_MCD1_MCD_FIR_MASK_REG_AND                            , RULL(0x03011004), SH_UNT_PU_MCD1  , SH_ACS_SCOM1_AND );
REG64( PU_MCD1_MCD_FIR_MASK_REG_OR                             , RULL(0x03011005), SH_UNT_PU_MCD1  , SH_ACS_SCOM2_OR  );

REG64( PU_MIB_XIICAC                                           , RULL(0x000E0009), SH_UNT          ,
       SH_ACS_SCOM_RO   ); //DUPS: 05012419, 06010853,

REG64( PU_MIB_XIMEM                                            , RULL(0x000E0007), SH_UNT          ,
       SH_ACS_SCOM_RO   ); //DUPS: 05012417, 06010851,

REG64( PU_MIB_XISGB                                            , RULL(0x000E0008), SH_UNT          ,
       SH_ACS_SCOM_RO   ); //DUPS: 05012418, 06010852,

REG64( PU_MIB_XISIB                                            , RULL(0x000E0006), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_NPU_CTL_MISC_CONFIG                                  , RULL(0x05011386), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_MISC_HOLD                                    , RULL(0x05011384), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_MISC_MASK                                    , RULL(0x05011385), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NMMU_MMCQ_PB_MODE_REG                                , RULL(0x05012C15), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_MMIOBAR0_MASK_REG                          , RULL(0x04010C4F), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK1_MMIOBAR0_MASK_REG                          , RULL(0x04010C8F), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK2_MMIOBAR0_MASK_REG                          , RULL(0x04010CCF), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK0_MMIOBAR0_MASK_REG                          , RULL(0x0401104F), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK1_MMIOBAR0_MASK_REG                          , RULL(0x0401108F), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK2_MMIOBAR0_MASK_REG                          , RULL(0x040110CF), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK0_MMIOBAR0_MASK_REG                          , RULL(0x0401144F), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK1_MMIOBAR0_MASK_REG                          , RULL(0x0401148F), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK2_MMIOBAR0_MASK_REG                          , RULL(0x040114CF), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_STACK0_MMIOBAR0_MASK_REG                            , RULL(0x04010C4F), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_STACK1_MMIOBAR0_MASK_REG                            , RULL(0x04010C8F), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_STACK2_MMIOBAR0_MASK_REG                            , RULL(0x04010CCF), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM      );
REG64( PHB_MMIOBAR0_MASK_REG                                   , RULL(0x04010C4F), SH_UNT_PHB      , SH_ACS_SCOM      );
REG64( PHB_0_MMIOBAR0_MASK_REG                                 , RULL(0x04010C4F), SH_UNT_PHB_0    , SH_ACS_SCOM      );
REG64( PHB_1_MMIOBAR0_MASK_REG                                 , RULL(0x0401104F), SH_UNT_PHB_1    , SH_ACS_SCOM      );
REG64( PHB_2_MMIOBAR0_MASK_REG                                 , RULL(0x0401108F), SH_UNT_PHB_2    , SH_ACS_SCOM      );
REG64( PHB_3_MMIOBAR0_MASK_REG                                 , RULL(0x0401144F), SH_UNT_PHB_3    , SH_ACS_SCOM      );
REG64( PHB_4_MMIOBAR0_MASK_REG                                 , RULL(0x0401148F), SH_UNT_PHB_4    , SH_ACS_SCOM      );
REG64( PHB_5_MMIOBAR0_MASK_REG                                 , RULL(0x040114CF), SH_UNT_PHB_5    , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_MMIOBAR0_REG                               , RULL(0x04010C4E), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK1_MMIOBAR0_REG                               , RULL(0x04010C8E), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK2_MMIOBAR0_REG                               , RULL(0x04010CCE), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK0_MMIOBAR0_REG                               , RULL(0x0401104E), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK1_MMIOBAR0_REG                               , RULL(0x0401108E), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK2_MMIOBAR0_REG                               , RULL(0x040110CE), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK0_MMIOBAR0_REG                               , RULL(0x0401144E), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK1_MMIOBAR0_REG                               , RULL(0x0401148E), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK2_MMIOBAR0_REG                               , RULL(0x040114CE), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_STACK0_MMIOBAR0_REG                                 , RULL(0x04010C4E), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_STACK1_MMIOBAR0_REG                                 , RULL(0x04010C8E), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_STACK2_MMIOBAR0_REG                                 , RULL(0x04010CCE), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM      );
REG64( PHB_MMIOBAR0_REG                                        , RULL(0x04010C4E), SH_UNT_PHB      , SH_ACS_SCOM      );
REG64( PHB_0_MMIOBAR0_REG                                      , RULL(0x04010C4E), SH_UNT_PHB_0    , SH_ACS_SCOM      );
REG64( PHB_1_MMIOBAR0_REG                                      , RULL(0x0401104E), SH_UNT_PHB_1    , SH_ACS_SCOM      );
REG64( PHB_2_MMIOBAR0_REG                                      , RULL(0x0401108E), SH_UNT_PHB_2    , SH_ACS_SCOM      );
REG64( PHB_3_MMIOBAR0_REG                                      , RULL(0x0401144E), SH_UNT_PHB_3    , SH_ACS_SCOM      );
REG64( PHB_4_MMIOBAR0_REG                                      , RULL(0x0401148E), SH_UNT_PHB_4    , SH_ACS_SCOM      );
REG64( PHB_5_MMIOBAR0_REG                                      , RULL(0x040114CE), SH_UNT_PHB_5    , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_MMIOBAR1_MASK_REG                          , RULL(0x04010C51), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK1_MMIOBAR1_MASK_REG                          , RULL(0x04010C91), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK2_MMIOBAR1_MASK_REG                          , RULL(0x04010CD1), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK0_MMIOBAR1_MASK_REG                          , RULL(0x04011051), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK1_MMIOBAR1_MASK_REG                          , RULL(0x04011091), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK2_MMIOBAR1_MASK_REG                          , RULL(0x040110D1), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK0_MMIOBAR1_MASK_REG                          , RULL(0x04011451), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK1_MMIOBAR1_MASK_REG                          , RULL(0x04011491), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK2_MMIOBAR1_MASK_REG                          , RULL(0x040114D1), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_STACK0_MMIOBAR1_MASK_REG                            , RULL(0x04010C51), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_STACK1_MMIOBAR1_MASK_REG                            , RULL(0x04010C91), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_STACK2_MMIOBAR1_MASK_REG                            , RULL(0x04010CD1), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM      );
REG64( PHB_MMIOBAR1_MASK_REG                                   , RULL(0x04010C51), SH_UNT_PHB      , SH_ACS_SCOM      );
REG64( PHB_0_MMIOBAR1_MASK_REG                                 , RULL(0x04010C51), SH_UNT_PHB_0    , SH_ACS_SCOM      );
REG64( PHB_1_MMIOBAR1_MASK_REG                                 , RULL(0x04011051), SH_UNT_PHB_1    , SH_ACS_SCOM      );
REG64( PHB_2_MMIOBAR1_MASK_REG                                 , RULL(0x04011091), SH_UNT_PHB_2    , SH_ACS_SCOM      );
REG64( PHB_3_MMIOBAR1_MASK_REG                                 , RULL(0x04011451), SH_UNT_PHB_3    , SH_ACS_SCOM      );
REG64( PHB_4_MMIOBAR1_MASK_REG                                 , RULL(0x04011491), SH_UNT_PHB_4    , SH_ACS_SCOM      );
REG64( PHB_5_MMIOBAR1_MASK_REG                                 , RULL(0x040114D1), SH_UNT_PHB_5    , SH_ACS_SCOM      );

REG64( PEC_0_STACK0_MMIOBAR1_REG                               , RULL(0x04010C50), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK1_MMIOBAR1_REG                               , RULL(0x04010C90), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK2_MMIOBAR1_REG                               , RULL(0x04010CD0), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK0_MMIOBAR1_REG                               , RULL(0x04011050), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK1_MMIOBAR1_REG                               , RULL(0x04011090), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK2_MMIOBAR1_REG                               , RULL(0x040110D0), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK0_MMIOBAR1_REG                               , RULL(0x04011450), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK1_MMIOBAR1_REG                               , RULL(0x04011490), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK2_MMIOBAR1_REG                               , RULL(0x040114D0), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_STACK0_MMIOBAR1_REG                                 , RULL(0x04010C50), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_STACK1_MMIOBAR1_REG                                 , RULL(0x04010C90), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_STACK2_MMIOBAR1_REG                                 , RULL(0x04010CD0), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM      );
REG64( PHB_MMIOBAR1_REG                                        , RULL(0x04010C50), SH_UNT_PHB      , SH_ACS_SCOM      );
REG64( PHB_0_MMIOBAR1_REG                                      , RULL(0x04010C50), SH_UNT_PHB_0    , SH_ACS_SCOM      );
REG64( PHB_1_MMIOBAR1_REG                                      , RULL(0x04011050), SH_UNT_PHB_1    , SH_ACS_SCOM      );
REG64( PHB_2_MMIOBAR1_REG                                      , RULL(0x04011090), SH_UNT_PHB_2    , SH_ACS_SCOM      );
REG64( PHB_3_MMIOBAR1_REG                                      , RULL(0x04011450), SH_UNT_PHB_3    , SH_ACS_SCOM      );
REG64( PHB_4_MMIOBAR1_REG                                      , RULL(0x04011490), SH_UNT_PHB_4    , SH_ACS_SCOM      );
REG64( PHB_5_MMIOBAR1_REG                                      , RULL(0x040114D0), SH_UNT_PHB_5    , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_CTL_MISC                            , RULL(0x05012C53), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_CTL_SLB                             , RULL(0x05012C54), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_CTL_SM                              , RULL(0x05012C52), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_CTL_TLB                             , RULL(0x05012C55), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_XLAT_CTL_REG0                       , RULL(0x05012C4A), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_XLAT_CTL_REG1                       , RULL(0x05012C4B), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_CFG_NMMU_XLAT_CTL_REG2                       , RULL(0x05012C4C), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_EPSILON_COUNTER_VALUE                        , RULL(0x05012C1D), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_NMMU_DBG_MODE                                , RULL(0x05012C59), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_NMMU_ERR_INJ                                 , RULL(0x05012C58), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_MM_NMMU_ERR_LOG                                 , RULL(0x05012C57), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PEC_MODE_REG                                            , RULL(0x0D040008), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_MODE_REG                                          , RULL(0x0D040008), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_MODE_REG                                          , RULL(0x0E040008), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_MODE_REG                                          , RULL(0x0F040008), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_MODE_REGISTER                                        , RULL(0x00010008), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_MODE_REGISTER_B                                      , RULL(0x000A0006), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_MODE_REGISTER_C                                      , RULL(0x000A1006), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_MODE_REGISTER_D                                      , RULL(0x000A2006), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_MODE_REGISTER_E                                      , RULL(0x000A3006), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_MULTICAST_GROUP_1                                   , RULL(0x0D0F0001), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_MULTICAST_GROUP_1                                 , RULL(0x0D0F0001), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_MULTICAST_GROUP_1                                 , RULL(0x0E0F0001), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_MULTICAST_GROUP_1                                 , RULL(0x0F0F0001), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_MULTICAST_GROUP_2                                   , RULL(0x0D0F0002), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_MULTICAST_GROUP_2                                 , RULL(0x0D0F0002), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_MULTICAST_GROUP_2                                 , RULL(0x0E0F0002), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_MULTICAST_GROUP_2                                 , RULL(0x0F0F0002), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_MULTICAST_GROUP_3                                   , RULL(0x0D0F0003), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_MULTICAST_GROUP_3                                 , RULL(0x0D0F0003), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_MULTICAST_GROUP_3                                 , RULL(0x0E0F0003), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_MULTICAST_GROUP_3                                 , RULL(0x0F0F0003), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_MULTICAST_GROUP_4                                   , RULL(0x0D0F0004), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_MULTICAST_GROUP_4                                 , RULL(0x0D0F0004), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_MULTICAST_GROUP_4                                 , RULL(0x0E0F0004), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_MULTICAST_GROUP_4                                 , RULL(0x0F0F0004), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_NDT_BAR                                     , RULL(0x05011005), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_NDT_BAR                                     , RULL(0x05011025), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_NDT_BAR                                     , RULL(0x05011045), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_NDT_BAR                                     , RULL(0x05011065), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_NDT_BAR                                     , RULL(0x05011105), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_NDT_BAR                                     , RULL(0x05011125), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_NDT_BAR                                     , RULL(0x05011145), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_NDT_BAR                                     , RULL(0x05011165), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_NDT_BAR                                     , RULL(0x05011205), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_NDT_BAR                                     , RULL(0x05011225), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_NDT_BAR                                     , RULL(0x05011245), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_NDT_BAR                                     , RULL(0x05011265), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PEC_NESTTRC_REG                                         , RULL(0x04010C03), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_NESTTRC_REG                                       , RULL(0x04010C03), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_NESTTRC_REG                                       , RULL(0x04011003), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_NESTTRC_REG                                       , RULL(0x04011403), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_0_STACK0_NET_CTRL0                                  , RULL(0x0D0F0040), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK0_NET_CTRL0_WAND                             , RULL(0x0D0F0041), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_0_STACK0_NET_CTRL0_WOR                              , RULL(0x0D0F0042), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM2_WOR );
REG64( PEC_1_STACK0_NET_CTRL0                                  , RULL(0x0E0F0040), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_NET_CTRL0_WAND                             , RULL(0x0E0F0041), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_1_STACK0_NET_CTRL0_WOR                              , RULL(0x0E0F0042), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM2_WOR );
REG64( PEC_2_STACK0_NET_CTRL0                                  , RULL(0x0F0F0040), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_NET_CTRL0_WAND                             , RULL(0x0F0F0041), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_2_STACK0_NET_CTRL0_WOR                              , RULL(0x0F0F0042), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM2_WOR );
REG64( PEC_STACK0_NET_CTRL0                                    , RULL(0x0D0F0040), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_NET_CTRL0_WAND                               , RULL(0x0D0F0041), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_STACK0_NET_CTRL0_WOR                                , RULL(0x0D0F0042), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM2_WOR );

REG64( PEC_0_STACK0_NET_CTRL1                                  , RULL(0x0D0F0044), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK0_NET_CTRL1_WAND                             , RULL(0x0D0F0045), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_0_STACK0_NET_CTRL1_WOR                              , RULL(0x0D0F0046), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM2_WOR );
REG64( PEC_1_STACK0_NET_CTRL1                                  , RULL(0x0E0F0044), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_NET_CTRL1_WAND                             , RULL(0x0E0F0045), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_1_STACK0_NET_CTRL1_WOR                              , RULL(0x0E0F0046), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM2_WOR );
REG64( PEC_2_STACK0_NET_CTRL1                                  , RULL(0x0F0F0044), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_NET_CTRL1_WAND                             , RULL(0x0F0F0045), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_2_STACK0_NET_CTRL1_WOR                              , RULL(0x0F0F0046), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM2_WOR );
REG64( PEC_STACK0_NET_CTRL1                                    , RULL(0x0D0F0044), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_NET_CTRL1_WAND                               , RULL(0x0D0F0045), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM1_WAND );
REG64( PEC_STACK0_NET_CTRL1_WOR                                , RULL(0x0D0F0046), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM2_WOR );

REG64( PEC_0_STACK0_NFIRACTION0_REG                            , RULL(0x04010C46), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_NFIRACTION0_REG                            , RULL(0x04010C86), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_NFIRACTION0_REG                            , RULL(0x04010CC6), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_NFIRACTION0_REG                            , RULL(0x04011046), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_NFIRACTION0_REG                            , RULL(0x04011086), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_NFIRACTION0_REG                            , RULL(0x040110C6), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_NFIRACTION0_REG                            , RULL(0x04011446), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_NFIRACTION0_REG                            , RULL(0x04011486), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_NFIRACTION0_REG                            , RULL(0x040114C6), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_NFIRACTION0_REG                              , RULL(0x04010C46), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_NFIRACTION0_REG                              , RULL(0x04010C86), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_NFIRACTION0_REG                              , RULL(0x04010CC6), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PHB_NFIRACTION0_REG                                     , RULL(0x04010C46), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_NFIRACTION0_REG                                   , RULL(0x04010C46), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_NFIRACTION0_REG                                   , RULL(0x04011046), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_NFIRACTION0_REG                                   , RULL(0x04011086), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_NFIRACTION0_REG                                   , RULL(0x04011446), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_NFIRACTION0_REG                                   , RULL(0x04011486), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_NFIRACTION0_REG                                   , RULL(0x040114C6), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PEC_0_STACK0_NFIRACTION1_REG                            , RULL(0x04010C47), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_NFIRACTION1_REG                            , RULL(0x04010C87), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_NFIRACTION1_REG                            , RULL(0x04010CC7), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_NFIRACTION1_REG                            , RULL(0x04011047), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_NFIRACTION1_REG                            , RULL(0x04011087), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_NFIRACTION1_REG                            , RULL(0x040110C7), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_NFIRACTION1_REG                            , RULL(0x04011447), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_NFIRACTION1_REG                            , RULL(0x04011487), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_NFIRACTION1_REG                            , RULL(0x040114C7), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_NFIRACTION1_REG                              , RULL(0x04010C47), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_NFIRACTION1_REG                              , RULL(0x04010C87), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_NFIRACTION1_REG                              , RULL(0x04010CC7), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PHB_NFIRACTION1_REG                                     , RULL(0x04010C47), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_NFIRACTION1_REG                                   , RULL(0x04010C47), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_NFIRACTION1_REG                                   , RULL(0x04011047), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_NFIRACTION1_REG                                   , RULL(0x04011087), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_NFIRACTION1_REG                                   , RULL(0x04011447), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_NFIRACTION1_REG                                   , RULL(0x04011487), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_NFIRACTION1_REG                                   , RULL(0x040114C7), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PEC_0_STACK0_NFIRMASK_REG                               , RULL(0x04010C43), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK0_NFIRMASK_REG_AND                           , RULL(0x04010C44), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_0_STACK0_NFIRMASK_REG_OR                            , RULL(0x04010C45), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_0_STACK1_NFIRMASK_REG                               , RULL(0x04010C83), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_NFIRMASK_REG_AND                           , RULL(0x04010C84), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_0_STACK1_NFIRMASK_REG_OR                            , RULL(0x04010C85), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_0_STACK2_NFIRMASK_REG                               , RULL(0x04010CC3), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_NFIRMASK_REG_AND                           , RULL(0x04010CC4), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_0_STACK2_NFIRMASK_REG_OR                            , RULL(0x04010CC5), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PEC_1_STACK0_NFIRMASK_REG                               , RULL(0x04011043), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_NFIRMASK_REG_AND                           , RULL(0x04011044), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_1_STACK0_NFIRMASK_REG_OR                            , RULL(0x04011045), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_1_STACK1_NFIRMASK_REG                               , RULL(0x04011083), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_NFIRMASK_REG_AND                           , RULL(0x04011084), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_1_STACK1_NFIRMASK_REG_OR                            , RULL(0x04011085), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_1_STACK2_NFIRMASK_REG                               , RULL(0x040110C3), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_NFIRMASK_REG_AND                           , RULL(0x040110C4), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_1_STACK2_NFIRMASK_REG_OR                            , RULL(0x040110C5), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PEC_2_STACK0_NFIRMASK_REG                               , RULL(0x04011443), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_NFIRMASK_REG_AND                           , RULL(0x04011444), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_2_STACK0_NFIRMASK_REG_OR                            , RULL(0x04011445), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_2_STACK1_NFIRMASK_REG                               , RULL(0x04011483), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_NFIRMASK_REG_AND                           , RULL(0x04011484), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_2_STACK1_NFIRMASK_REG_OR                            , RULL(0x04011485), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_2_STACK2_NFIRMASK_REG                               , RULL(0x040114C3), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_NFIRMASK_REG_AND                           , RULL(0x040114C4), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_2_STACK2_NFIRMASK_REG_OR                            , RULL(0x040114C5), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PEC_STACK0_NFIRMASK_REG                                 , RULL(0x04010C43), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_NFIRMASK_REG_AND                             , RULL(0x04010C44), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_STACK0_NFIRMASK_REG_OR                              , RULL(0x04010C45), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_STACK1_NFIRMASK_REG                                 , RULL(0x04010C83), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_NFIRMASK_REG_AND                             , RULL(0x04010C84), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_STACK1_NFIRMASK_REG_OR                              , RULL(0x04010C85), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_STACK2_NFIRMASK_REG                                 , RULL(0x04010CC3), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_NFIRMASK_REG_AND                             , RULL(0x04010CC4), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_STACK2_NFIRMASK_REG_OR                              , RULL(0x04010CC5), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PHB_NFIRMASK_REG                                        , RULL(0x04010C43), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_NFIRMASK_REG_AND                                    , RULL(0x04010C44), SH_UNT_PHB      , SH_ACS_SCOM1_AND );
REG64( PHB_NFIRMASK_REG_OR                                     , RULL(0x04010C45), SH_UNT_PHB      , SH_ACS_SCOM2_OR  );
REG64( PHB_0_NFIRMASK_REG                                      , RULL(0x04010C43), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_0_NFIRMASK_REG_AND                                  , RULL(0x04010C44), SH_UNT_PHB_0    , SH_ACS_SCOM1_AND );
REG64( PHB_0_NFIRMASK_REG_OR                                   , RULL(0x04010C45), SH_UNT_PHB_0    , SH_ACS_SCOM2_OR  );
REG64( PHB_1_NFIRMASK_REG                                      , RULL(0x04011043), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_1_NFIRMASK_REG_AND                                  , RULL(0x04011044), SH_UNT_PHB_1    , SH_ACS_SCOM1_AND );
REG64( PHB_1_NFIRMASK_REG_OR                                   , RULL(0x04011045), SH_UNT_PHB_1    , SH_ACS_SCOM2_OR  );
REG64( PHB_2_NFIRMASK_REG                                      , RULL(0x04011083), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_2_NFIRMASK_REG_AND                                  , RULL(0x04011084), SH_UNT_PHB_2    , SH_ACS_SCOM1_AND );
REG64( PHB_2_NFIRMASK_REG_OR                                   , RULL(0x04011085), SH_UNT_PHB_2    , SH_ACS_SCOM2_OR  );
REG64( PHB_3_NFIRMASK_REG                                      , RULL(0x04011443), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_3_NFIRMASK_REG_AND                                  , RULL(0x04011444), SH_UNT_PHB_3    , SH_ACS_SCOM1_AND );
REG64( PHB_3_NFIRMASK_REG_OR                                   , RULL(0x04011445), SH_UNT_PHB_3    , SH_ACS_SCOM2_OR  );
REG64( PHB_4_NFIRMASK_REG                                      , RULL(0x04011483), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_4_NFIRMASK_REG_AND                                  , RULL(0x04011484), SH_UNT_PHB_4    , SH_ACS_SCOM1_AND );
REG64( PHB_4_NFIRMASK_REG_OR                                   , RULL(0x04011485), SH_UNT_PHB_4    , SH_ACS_SCOM2_OR  );
REG64( PHB_5_NFIRMASK_REG                                      , RULL(0x040114C3), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );
REG64( PHB_5_NFIRMASK_REG_AND                                  , RULL(0x040114C4), SH_UNT_PHB_5    , SH_ACS_SCOM1_AND );
REG64( PHB_5_NFIRMASK_REG_OR                                   , RULL(0x040114C5), SH_UNT_PHB_5    , SH_ACS_SCOM2_OR  );

REG64( PEC_0_STACK0_NFIRWOF_REG                                , RULL(0x04010C48), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_0_STACK1_NFIRWOF_REG                                , RULL(0x04010C88), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_0_STACK2_NFIRWOF_REG                                , RULL(0x04010CC8), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_1_STACK0_NFIRWOF_REG                                , RULL(0x04011048), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_1_STACK1_NFIRWOF_REG                                , RULL(0x04011088), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_1_STACK2_NFIRWOF_REG                                , RULL(0x040110C8), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_2_STACK0_NFIRWOF_REG                                , RULL(0x04011448), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_2_STACK1_NFIRWOF_REG                                , RULL(0x04011488), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_2_STACK2_NFIRWOF_REG                                , RULL(0x040114C8), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_STACK0_NFIRWOF_REG                                  , RULL(0x04010C48), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_STACK1_NFIRWOF_REG                                  , RULL(0x04010C88), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_WCLRREG );
REG64( PEC_STACK2_NFIRWOF_REG                                  , RULL(0x04010CC8), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_NFIRWOF_REG                                         , RULL(0x04010C48), SH_UNT_PHB      ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_0_NFIRWOF_REG                                       , RULL(0x04010C48), SH_UNT_PHB_0    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_1_NFIRWOF_REG                                       , RULL(0x04011048), SH_UNT_PHB_1    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_2_NFIRWOF_REG                                       , RULL(0x04011088), SH_UNT_PHB_2    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_3_NFIRWOF_REG                                       , RULL(0x04011448), SH_UNT_PHB_3    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_4_NFIRWOF_REG                                       , RULL(0x04011488), SH_UNT_PHB_4    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_5_NFIRWOF_REG                                       , RULL(0x040114C8), SH_UNT_PHB_5    ,
       SH_ACS_SCOM_WCLRREG );

REG64( PEC_0_STACK0_NFIR_REG                                   , RULL(0x04010C40), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK0_NFIR_REG_AND                               , RULL(0x04010C41), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_0_STACK0_NFIR_REG_OR                                , RULL(0x04010C42), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_0_STACK1_NFIR_REG                                   , RULL(0x04010C80), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_NFIR_REG_AND                               , RULL(0x04010C81), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_0_STACK1_NFIR_REG_OR                                , RULL(0x04010C82), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_0_STACK2_NFIR_REG                                   , RULL(0x04010CC0), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_NFIR_REG_AND                               , RULL(0x04010CC1), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_0_STACK2_NFIR_REG_OR                                , RULL(0x04010CC2), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PEC_1_STACK0_NFIR_REG                                   , RULL(0x04011040), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_NFIR_REG_AND                               , RULL(0x04011041), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_1_STACK0_NFIR_REG_OR                                , RULL(0x04011042), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_1_STACK1_NFIR_REG                                   , RULL(0x04011080), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_NFIR_REG_AND                               , RULL(0x04011081), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_1_STACK1_NFIR_REG_OR                                , RULL(0x04011082), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_1_STACK2_NFIR_REG                                   , RULL(0x040110C0), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_NFIR_REG_AND                               , RULL(0x040110C1), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_1_STACK2_NFIR_REG_OR                                , RULL(0x040110C2), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PEC_2_STACK0_NFIR_REG                                   , RULL(0x04011440), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_NFIR_REG_AND                               , RULL(0x04011441), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_2_STACK0_NFIR_REG_OR                                , RULL(0x04011442), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_2_STACK1_NFIR_REG                                   , RULL(0x04011480), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_NFIR_REG_AND                               , RULL(0x04011481), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_2_STACK1_NFIR_REG_OR                                , RULL(0x04011482), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_2_STACK2_NFIR_REG                                   , RULL(0x040114C0), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_NFIR_REG_AND                               , RULL(0x040114C1), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_2_STACK2_NFIR_REG_OR                                , RULL(0x040114C2), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PEC_STACK0_NFIR_REG                                     , RULL(0x04010C40), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_NFIR_REG_AND                                 , RULL(0x04010C41), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM1_AND );
REG64( PEC_STACK0_NFIR_REG_OR                                  , RULL(0x04010C42), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM2_OR  );
REG64( PEC_STACK1_NFIR_REG                                     , RULL(0x04010C80), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_NFIR_REG_AND                                 , RULL(0x04010C81), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM1_AND );
REG64( PEC_STACK1_NFIR_REG_OR                                  , RULL(0x04010C82), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM2_OR  );
REG64( PEC_STACK2_NFIR_REG                                     , RULL(0x04010CC0), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_NFIR_REG_AND                                 , RULL(0x04010CC1), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM1_AND );
REG64( PEC_STACK2_NFIR_REG_OR                                  , RULL(0x04010CC2), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM2_OR  );
REG64( PHB_NFIR_REG                                            , RULL(0x04010C40), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_NFIR_REG_AND                                        , RULL(0x04010C41), SH_UNT_PHB      , SH_ACS_SCOM1_AND );
REG64( PHB_NFIR_REG_OR                                         , RULL(0x04010C42), SH_UNT_PHB      , SH_ACS_SCOM2_OR  );
REG64( PHB_0_NFIR_REG                                          , RULL(0x04010C40), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_0_NFIR_REG_AND                                      , RULL(0x04010C41), SH_UNT_PHB_0    , SH_ACS_SCOM1_AND );
REG64( PHB_0_NFIR_REG_OR                                       , RULL(0x04010C42), SH_UNT_PHB_0    , SH_ACS_SCOM2_OR  );
REG64( PHB_1_NFIR_REG                                          , RULL(0x04011040), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_1_NFIR_REG_AND                                      , RULL(0x04011041), SH_UNT_PHB_1    , SH_ACS_SCOM1_AND );
REG64( PHB_1_NFIR_REG_OR                                       , RULL(0x04011042), SH_UNT_PHB_1    , SH_ACS_SCOM2_OR  );
REG64( PHB_2_NFIR_REG                                          , RULL(0x04011080), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_2_NFIR_REG_AND                                      , RULL(0x04011081), SH_UNT_PHB_2    , SH_ACS_SCOM1_AND );
REG64( PHB_2_NFIR_REG_OR                                       , RULL(0x04011082), SH_UNT_PHB_2    , SH_ACS_SCOM2_OR  );
REG64( PHB_3_NFIR_REG                                          , RULL(0x04011440), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_3_NFIR_REG_AND                                      , RULL(0x04011441), SH_UNT_PHB_3    , SH_ACS_SCOM1_AND );
REG64( PHB_3_NFIR_REG_OR                                       , RULL(0x04011442), SH_UNT_PHB_3    , SH_ACS_SCOM2_OR  );
REG64( PHB_4_NFIR_REG                                          , RULL(0x04011480), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_4_NFIR_REG_AND                                      , RULL(0x04011481), SH_UNT_PHB_4    , SH_ACS_SCOM1_AND );
REG64( PHB_4_NFIR_REG_OR                                       , RULL(0x04011482), SH_UNT_PHB_4    , SH_ACS_SCOM2_OR  );
REG64( PHB_5_NFIR_REG                                          , RULL(0x040114C0), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );
REG64( PHB_5_NFIR_REG_AND                                      , RULL(0x040114C1), SH_UNT_PHB_5    , SH_ACS_SCOM1_AND );
REG64( PHB_5_NFIR_REG_OR                                       , RULL(0x040114C2), SH_UNT_PHB_5    , SH_ACS_SCOM2_OR  );

REG64( PU_NOTRUST_BAR0                                         , RULL(0x05012B40), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NOTRUST_BAR0MASK                                     , RULL(0x05012B42), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NOTRUST_BAR1                                         , RULL(0x05012B41), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NOTRUST_BAR1MASK                                     , RULL(0x05012B43), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NPU_SM0_NPU_ATS_DEBUG                                , RULL(0x05011303), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM0_NPU_AT_ECC                                   , RULL(0x05011302), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_NPU_AT_ESMR                                  , RULL(0x05011328), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_NPU_AT_ESR                                   , RULL(0x05011327), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_NPU_AT_FESMR                                 , RULL(0x0501132A), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_NPU_AT_FESR                                  , RULL(0x05011329), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM0_NPU_AT_PMU_CNT                               , RULL(0x05011301), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_RO   );

REG64( PU_NPU_SM0_NPU_AT_PMU_CTRL                              , RULL(0x05011300), SH_UNT_PU_NPU_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_NPU_SM1_NPU_Q_DMA_R                                  , RULL(0x05011325), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM      );

REG64( PU_NPU_CTL_NPU_VERSION                                  , RULL(0x05011390), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_NXCQ_PB_MODE_REG                                     , RULL(0x02011095), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_CQ_FIR_ACTION0_REG                                , RULL(0x02011086), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_NMMU_NX_CQ_FIR_ACTION0_REG                           , RULL(0x05012C06), SH_UNT_PU_NMMU  , SH_ACS_SCOM_RW   );

REG64( PU_NX_CQ_FIR_ACTION1_REG                                , RULL(0x02011087), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_NMMU_NX_CQ_FIR_ACTION1_REG                           , RULL(0x05012C07), SH_UNT_PU_NMMU  , SH_ACS_SCOM_RW   );

REG64( PU_NX_CQ_FIR_MASK_REG                                   , RULL(0x02011083), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_NX_CQ_FIR_MASK_REG_AND                               , RULL(0x02011084), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_NX_CQ_FIR_MASK_REG_OR                                , RULL(0x02011085), SH_UNT          , SH_ACS_SCOM2_OR  );
REG64( PU_NMMU_NX_CQ_FIR_MASK_REG                              , RULL(0x05012C03), SH_UNT_PU_NMMU  , SH_ACS_SCOM_RW   );
REG64( PU_NMMU_NX_CQ_FIR_MASK_REG_AND                          , RULL(0x05012C04), SH_UNT_PU_NMMU  , SH_ACS_SCOM1_AND );
REG64( PU_NMMU_NX_CQ_FIR_MASK_REG_OR                           , RULL(0x05012C05), SH_UNT_PU_NMMU  , SH_ACS_SCOM2_OR  );

REG64( PU_NX_CQ_FIR_REG                                        , RULL(0x02011080), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_NX_CQ_FIR_REG_AND                                    , RULL(0x02011081), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_NX_CQ_FIR_REG_OR                                     , RULL(0x02011082), SH_UNT          , SH_ACS_SCOM2_OR  );
REG64( PU_NMMU_NX_CQ_FIR_REG                                   , RULL(0x05012C00), SH_UNT_PU_NMMU  , SH_ACS_SCOM_RW   );
REG64( PU_NMMU_NX_CQ_FIR_REG_AND                               , RULL(0x05012C01), SH_UNT_PU_NMMU  , SH_ACS_SCOM1_AND );
REG64( PU_NMMU_NX_CQ_FIR_REG_OR                                , RULL(0x05012C02), SH_UNT_PU_NMMU  , SH_ACS_SCOM2_OR  );

REG64( PU_NX_CQ_FIR_WOF_REG                                    , RULL(0x02011088), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );
REG64( PU_NMMU_NX_CQ_FIR_WOF_REG                               , RULL(0x05012C08), SH_UNT_PU_NMMU  ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_NX_DEBUGMUX_CTRL                                     , RULL(0x0201110A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_NX_DEBUG_SNAPSHOT_0                                  , RULL(0x020110A4), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_NMMU_NX_DEBUG_SNAPSHOT_0                             , RULL(0x05012C24), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_DEBUG_SNAPSHOT_1                                  , RULL(0x020110A5), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_NMMU_NX_DEBUG_SNAPSHOT_1                             , RULL(0x05012C25), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_DMA_ENG_FIR                                       , RULL(0x02011100), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_NX_DMA_ENG_FIR_AND                                   , RULL(0x02011101), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_NX_DMA_ENG_FIR_OR                                    , RULL(0x02011102), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_NX_DMA_ENG_FIR_ACTION0                               , RULL(0x02011106), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_NX_DMA_ENG_FIR_ACTION1                               , RULL(0x02011107), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_NX_DMA_ENG_FIR_MASK                                  , RULL(0x02011103), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_NX_DMA_ENG_FIR_MASK_AND                              , RULL(0x02011104), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_NX_DMA_ENG_FIR_MASK_OR                               , RULL(0x02011105), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_NX_DMA_ENG_FIR_WOF                                   , RULL(0x02011108), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_NX_ERRORINJ_CTRL                                     , RULL(0x0201110C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_NX_MISC_CONTROL_REG                                  , RULL(0x020110A8), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_NMMU_NX_MISC_CONTROL_REG                             , RULL(0x05012C28), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_MMIO_BAR                                          , RULL(0x0201108D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_PB_DEBUG_REG                                      , RULL(0x02011090), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_NMMU_NX_PB_DEBUG_REG                                 , RULL(0x05012C10), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_PB_ECC_REG                                        , RULL(0x02011091), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_NMMU_NX_PB_ECC_REG                                   , RULL(0x05012C11), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_PB_ERR_RPT_0                                      , RULL(0x020110A2), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_NMMU_NX_PB_ERR_RPT_0                                 , RULL(0x05012C22), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_PB_ERR_RPT_1                                      , RULL(0x020110A1), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_PMU0_CONTROL_REG                                  , RULL(0x020110A6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_PMU0_COUNTER_REG                                  , RULL(0x020110A7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_PMU1_CONTROL_REG                                  , RULL(0x020110A9), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_PMU1_COUNTER_REG                                  , RULL(0x020110AA), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NMMU_NX_PMU_CONTROL_REG                              , RULL(0x05012C26), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NMMU_NX_PMU_COUNTER_REG                              , RULL(0x05012C27), SH_UNT_PU_NMMU  , SH_ACS_SCOM      );

REG64( PU_NX_RNG_BYPASS                                        , RULL(0x020110E4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_CFG                                           , RULL(0x020110E0), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_RDELAY                                        , RULL(0x020110E5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_RESET                                         , RULL(0x020110E6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_ST0                                           , RULL(0x020110E1), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_ST1                                           , RULL(0x020110E2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_ST2                                           , RULL(0x020110E3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_RNG_ST3                                           , RULL(0x020110E8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_NX_TRIGGER_CTRL                                      , RULL(0x0201110B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_CCSR_OCI                                     , RULL(0xC0060480), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_CCSR_OCI1                                    , RULL(0xC0060488), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_CCSR_OCI2                                    , RULL(0xC0060490), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_CCSR_SCOM                                    , RULL(0x0006C090), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_CCSR_SCOM1                                   , RULL(0x0006C091), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_CCSR_SCOM2                                   , RULL(0x0006C092), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_G0ISR0_OCI                                   , RULL(0xC0060320), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G0ISR0_SCOM                                  , RULL(0x0006C064), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G0ISR1_OCI                                   , RULL(0xC00603A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G0ISR1_SCOM                                  , RULL(0x0006C074), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G1ISR0_OCI                                   , RULL(0xC0060328), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G1ISR0_SCOM                                  , RULL(0x0006C065), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G1ISR1_OCI                                   , RULL(0xC00603A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G1ISR1_SCOM                                  , RULL(0x0006C075), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G2ISR0_OCI                                   , RULL(0xC0060330), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G2ISR0_SCOM                                  , RULL(0x0006C066), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G2ISR1_OCI                                   , RULL(0xC00603B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G2ISR1_SCOM                                  , RULL(0x0006C076), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G3ISR0_OCI                                   , RULL(0xC0060338), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G3ISR0_SCOM                                  , RULL(0x0006C067), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_G3ISR1_OCI                                   , RULL(0xC00603B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_G3ISR1_SCOM                                  , RULL(0x0006C077), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SCMD0A_OCI                                 , RULL(0xC0063838), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCMD0A_SCOM                                , RULL(0x0006C707), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCMD0B_OCI                                 , RULL(0xC00638B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCMD0B_SCOM                                , RULL(0x0006C717), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCMD1A_OCI                                 , RULL(0xC0063938), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCMD1A_SCOM                                , RULL(0x0006C727), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCMD1B_OCI                                 , RULL(0xC00639B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCMD1B_SCOM                                , RULL(0x0006C737), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL10A_OCI                               , RULL(0xC0063810), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL10A_SCOM                              , RULL(0x0006C702), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL10B_OCI                               , RULL(0xC0063890), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL10B_SCOM                              , RULL(0x0006C712), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL11A_OCI                               , RULL(0xC0063910), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL11A_SCOM                              , RULL(0x0006C722), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL11B_OCI                               , RULL(0xC0063990), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL11B_SCOM                              , RULL(0x0006C732), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL20A_OCI                               , RULL(0xC0063818), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL20A_SCOM                              , RULL(0x0006C703), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL20B_OCI                               , RULL(0xC0063898), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL20B_SCOM                              , RULL(0x0006C713), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL21A_OCI                               , RULL(0xC0063918), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL21A_SCOM                              , RULL(0x0006C723), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRL21B_OCI                               , RULL(0xC0063998), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRL21B_SCOM                              , RULL(0x0006C733), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLF0A_OCI                               , RULL(0xC0063800), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLF0A_SCOM                              , RULL(0x0006C700), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLF0B_OCI                               , RULL(0xC0063880), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLF0B_SCOM                              , RULL(0x0006C710), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLF1A_OCI                               , RULL(0xC0063900), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLF1A_SCOM                              , RULL(0x0006C720), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLF1B_OCI                               , RULL(0xC0063980), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLF1B_SCOM                              , RULL(0x0006C730), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLS0A_OCI                               , RULL(0xC0063808), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLS0A_SCOM                              , RULL(0x0006C701), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLS0B_OCI                               , RULL(0xC0063888), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLS0B_SCOM                              , RULL(0x0006C711), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLS1A_OCI                               , RULL(0xC0063908), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLS1A_SCOM                              , RULL(0x0006C721), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SCTRLS1B_OCI                               , RULL(0xC0063988), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SCTRLS1B_SCOM                              , RULL(0x0006C731), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SRD0A_OCI                                  , RULL(0xC0063848), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SRD0A_SCOM                                 , RULL(0x0006C709), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SRD0B_OCI                                  , RULL(0xC00638C8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SRD0B_SCOM                                 , RULL(0x0006C719), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SRD1A_OCI                                  , RULL(0xC0063948), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SRD1A_SCOM                                 , RULL(0x0006C729), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SRD1B_OCI                                  , RULL(0xC00639C8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SRD1B_SCOM                                 , RULL(0x0006C739), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SST0A_OCI                                  , RULL(0xC0063830), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SST0A_SCOM                                 , RULL(0x0006C706), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SST0B_OCI                                  , RULL(0xC00638B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SST0B_SCOM                                 , RULL(0x0006C716), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SST1A_OCI                                  , RULL(0xC0063930), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SST1A_SCOM                                 , RULL(0x0006C726), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SST1B_OCI                                  , RULL(0xC00639B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SST1B_SCOM                                 , RULL(0x0006C736), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_O2SWD0A_OCI                                  , RULL(0xC0063840), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SWD0A_SCOM                                 , RULL(0x0006C708), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SWD0B_OCI                                  , RULL(0xC00638C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SWD0B_SCOM                                 , RULL(0x0006C718), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SWD1A_OCI                                  , RULL(0xC0063940), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SWD1A_SCOM                                 , RULL(0x0006C728), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_O2SWD1B_OCI                                  , RULL(0xC00639C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_O2SWD1B_SCOM                                 , RULL(0x0006C738), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWCR0_OCI                                 , RULL(0xC0061040), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWCR0_SCOM                                , RULL(0x0006C208), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWCR1_OCI                                 , RULL(0xC00610C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWCR1_SCOM                                , RULL(0x0006C218), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWCR2_OCI                                 , RULL(0xC0061140), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWCR2_SCOM                                , RULL(0x0006C228), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWCR3_OCI                                 , RULL(0xC00611C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWCR3_SCOM                                , RULL(0x0006C238), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWSBR0_OCI                                , RULL(0xC0061060), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSBR0_SCOM                               , RULL(0x0006C20C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWSBR1_OCI                                , RULL(0xC00610E0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSBR1_SCOM                               , RULL(0x0006C21C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWSBR2_OCI                                , RULL(0xC0061160), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSBR2_SCOM                               , RULL(0x0006C22C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWSBR3_OCI                                , RULL(0xC00611E0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSBR3_SCOM                               , RULL(0x0006C23C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBLWSR0_OCI                                 , RULL(0xC0061050), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSR0_SCOM                                , RULL(0x0006C20A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OCBLWSR1_OCI                                 , RULL(0xC00610D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSR1_SCOM                                , RULL(0x0006C21A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OCBLWSR2_OCI                                 , RULL(0xC0061150), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSR2_SCOM                                , RULL(0x0006C22A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OCBLWSR3_OCI                                 , RULL(0xC00611D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBLWSR3_SCOM                                , RULL(0x0006C23A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OCBSES0_OCI                                  , RULL(0xC0061030), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSES0_SCOM                                 , RULL(0x0006C206), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSES1_OCI                                  , RULL(0xC00610B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSES1_SCOM                                 , RULL(0x0006C216), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSES2_OCI                                  , RULL(0xC0061130), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSES2_SCOM                                 , RULL(0x0006C226), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSES3_OCI                                  , RULL(0xC00611B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSES3_SCOM                                 , RULL(0x0006C236), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSHBR0_OCI                                 , RULL(0xC0061018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHBR0_SCOM                                , RULL(0x0006C203), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSHBR1_OCI                                 , RULL(0xC0061098), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHBR1_SCOM                                , RULL(0x0006C213), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSHBR2_OCI                                 , RULL(0xC0061118), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHBR2_SCOM                                , RULL(0x0006C223), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSHBR3_OCI                                 , RULL(0xC0061198), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHBR3_SCOM                                , RULL(0x0006C233), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSHCS0_OCI                                 , RULL(0xC0061020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHCS0_SCOM                                , RULL(0x0006C204), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHCS1_OCI                                 , RULL(0xC00610A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHCS1_SCOM                                , RULL(0x0006C214), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHCS2_OCI                                 , RULL(0xC0061120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHCS2_SCOM                                , RULL(0x0006C224), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHCS3_OCI                                 , RULL(0xC00611A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHCS3_SCOM                                , RULL(0x0006C234), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHI0_OCI                                  , RULL(0xC0061028), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHI0_SCOM                                 , RULL(0x0006C205), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHI1_OCI                                  , RULL(0xC00610A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHI1_SCOM                                 , RULL(0x0006C215), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHI2_OCI                                  , RULL(0xC0061128), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHI2_SCOM                                 , RULL(0x0006C225), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSHI3_OCI                                  , RULL(0xC00611A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSHI3_SCOM                                 , RULL(0x0006C235), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLBR0_OCI                                 , RULL(0xC0061000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLBR0_SCOM                                , RULL(0x0006C200), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSLBR1_OCI                                 , RULL(0xC0061080), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLBR1_SCOM                                , RULL(0x0006C210), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSLBR2_OCI                                 , RULL(0xC0061100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLBR2_SCOM                                , RULL(0x0006C220), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSLBR3_OCI                                 , RULL(0xC0061180), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLBR3_SCOM                                , RULL(0x0006C230), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCBSLCS0_OCI                                 , RULL(0xC0061008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLCS0_SCOM                                , RULL(0x0006C201), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLCS1_OCI                                 , RULL(0xC0061088), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLCS1_SCOM                                , RULL(0x0006C211), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLCS2_OCI                                 , RULL(0xC0061108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLCS2_SCOM                                , RULL(0x0006C221), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLCS3_OCI                                 , RULL(0xC0061188), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLCS3_SCOM                                , RULL(0x0006C231), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLI0_OCI                                  , RULL(0xC0061010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLI0_SCOM                                 , RULL(0x0006C202), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLI1_OCI                                  , RULL(0xC0061090), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLI1_SCOM                                 , RULL(0x0006C212), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLI2_OCI                                  , RULL(0xC0061110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLI2_SCOM                                 , RULL(0x0006C222), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCBSLI3_OCI                                  , RULL(0xC0061190), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCBSLI3_SCOM                                 , RULL(0x0006C232), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OCCFLG_OCI                                   , RULL(0xC0060450), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCCFLG_OCI1                                  , RULL(0xC0060458), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OCCFLG_OCI2                                  , RULL(0xC0060460), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OCCFLG_SCOM                                  , RULL(0x0006C08A), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OCCFLG_SCOM1                                 , RULL(0x0006C08B), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OCCFLG_SCOM2                                 , RULL(0x0006C08C), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OCCHBR_OCI                                   , RULL(0xC0060478), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCCHBR_SCOM                                  , RULL(0x0006C08F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCCMISC_OCI                                  , RULL(0xC0060400), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCCMISC_OCI1                                 , RULL(0xC0060408), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OCCMISC_OCI2                                 , RULL(0xC0060410), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OCCMISC_SCOM                                 , RULL(0x0006C080), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_OCB_OCI_OCCMISC_SCOM1                                , RULL(0x0006C081), SH_UNT          , SH_ACS_SCOM1     );
REG64( PU_OCB_OCI_OCCMISC_SCOM2                                , RULL(0x0006C082), SH_UNT          , SH_ACS_SCOM2     );

REG64( PU_OCB_OCI_OCCS0_OCI                                    , RULL(0xC0060430), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCCS0_SCOM                                   , RULL(0x0006C086), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCCS1_OCI                                    , RULL(0xC0060438), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCCS1_SCOM                                   , RULL(0x0006C087), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCCS2_OCI                                    , RULL(0xC0060440), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCCS2_SCOM                                   , RULL(0x0006C088), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCICFG_OCI                                   , RULL(0xC0060428), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCICFG_SCOM                                  , RULL(0x0006C085), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OCISR0_OCI                                   , RULL(0xC0060308), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCISR0_SCOM                                  , RULL(0x0006C061), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OCISR1_OCI                                   , RULL(0xC0060388), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OCISR1_SCOM                                  , RULL(0x0006C071), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_ODISR0_OCI                                   , RULL(0xC0060318), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_ODISR0_SCOM                                  , RULL(0x0006C063), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_ODISR1_OCI                                   , RULL(0xC0060398), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_ODISR1_SCOM                                  , RULL(0x0006C073), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OEHDR_OCI                                    , RULL(0xC0060420), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OEHDR_SCOM                                   , RULL(0x0006C084), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_OCI_OHTMCR_OCI                                   , RULL(0xC0060418), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OHTMCR_SCOM                                  , RULL(0x0006C083), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OIEPR0_OCI                                   , RULL(0xC0060060), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIEPR0_OCI1                                  , RULL(0xC0060068), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIEPR0_OCI2                                  , RULL(0xC0060070), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIEPR0_SCOM                                  , RULL(0x0006C00C), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIEPR0_SCOM1                                 , RULL(0x0006C00D), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIEPR0_SCOM2                                 , RULL(0x0006C00E), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIEPR1_OCI                                   , RULL(0xC0060160), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIEPR1_OCI1                                  , RULL(0xC0060168), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIEPR1_OCI2                                  , RULL(0xC0060170), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIEPR1_SCOM                                  , RULL(0x0006C02C), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIEPR1_SCOM1                                 , RULL(0x0006C02D), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIEPR1_SCOM2                                 , RULL(0x0006C02E), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIMR0_OCI                                    , RULL(0xC0060020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIMR0_OCI1                                   , RULL(0xC0060028), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIMR0_OCI2                                   , RULL(0xC0060030), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIMR0_SCOM                                   , RULL(0x0006C004), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIMR0_SCOM1                                  , RULL(0x0006C005), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIMR0_SCOM2                                  , RULL(0x0006C006), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIMR1_OCI                                    , RULL(0xC0060120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIMR1_OCI1                                   , RULL(0xC0060128), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIMR1_OCI2                                   , RULL(0xC0060130), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIMR1_SCOM                                   , RULL(0x0006C024), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIMR1_SCOM1                                  , RULL(0x0006C025), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIMR1_SCOM2                                  , RULL(0x0006C026), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIRR0A_OCI                                   , RULL(0xC0060200), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIRR0A_OCI1                                  , RULL(0xC0060208), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIRR0A_OCI2                                  , RULL(0xC0060210), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIRR0A_SCOM                                  , RULL(0x0006C040), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIRR0A_SCOM1                                 , RULL(0x0006C041), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIRR0A_SCOM2                                 , RULL(0x0006C042), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIRR0B_OCI                                   , RULL(0xC0060220), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIRR0B_OCI1                                  , RULL(0xC0060228), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIRR0B_OCI2                                  , RULL(0xC0060230), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIRR0B_SCOM                                  , RULL(0x0006C044), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIRR0B_SCOM1                                 , RULL(0x0006C045), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIRR0B_SCOM2                                 , RULL(0x0006C046), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIRR0C_OCI                                   , RULL(0xC0060240), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIRR0C_OCI1                                  , RULL(0xC0060248), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIRR0C_OCI2                                  , RULL(0xC0060250), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIRR0C_SCOM                                  , RULL(0x0006C048), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIRR0C_SCOM1                                 , RULL(0x0006C049), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIRR0C_SCOM2                                 , RULL(0x0006C04A), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIRR1A_OCI                                   , RULL(0xC0060280), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIRR1A_OCI1                                  , RULL(0xC0060288), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIRR1A_OCI2                                  , RULL(0xC0060290), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIRR1A_SCOM                                  , RULL(0x0006C050), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIRR1A_SCOM1                                 , RULL(0x0006C051), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIRR1A_SCOM2                                 , RULL(0x0006C052), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIRR1B_OCI                                   , RULL(0xC00602A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIRR1B_OCI1                                  , RULL(0xC00602A8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIRR1B_OCI2                                  , RULL(0xC00602B0), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIRR1B_SCOM                                  , RULL(0x0006C054), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIRR1B_SCOM1                                 , RULL(0x0006C055), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIRR1B_SCOM2                                 , RULL(0x0006C056), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OIRR1C_OCI                                   , RULL(0xC00602C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OIRR1C_OCI1                                  , RULL(0xC00602C8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OIRR1C_OCI2                                  , RULL(0xC00602D0), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OIRR1C_SCOM                                  , RULL(0x0006C058), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OIRR1C_SCOM1                                 , RULL(0x0006C059), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OIRR1C_SCOM2                                 , RULL(0x0006C05A), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OISR0_OCI                                    , RULL(0xC0060000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OISR0_OCI1                                   , RULL(0xC0060008), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OISR0_OCI2                                   , RULL(0xC0060010), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OISR0_SCOM                                   , RULL(0x0006C000), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OISR0_SCOM1                                  , RULL(0x0006C001), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OISR0_SCOM2                                  , RULL(0x0006C002), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OISR1_OCI                                    , RULL(0xC0060100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OISR1_OCI1                                   , RULL(0xC0060108), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OISR1_OCI2                                   , RULL(0xC0060110), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OISR1_SCOM                                   , RULL(0x0006C020), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OISR1_SCOM1                                  , RULL(0x0006C021), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OISR1_SCOM2                                  , RULL(0x0006C022), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OITR0_OCI                                    , RULL(0xC0060040), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OITR0_OCI1                                   , RULL(0xC0060048), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OITR0_OCI2                                   , RULL(0xC0060050), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OITR0_SCOM                                   , RULL(0x0006C008), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OITR0_SCOM1                                  , RULL(0x0006C009), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OITR0_SCOM2                                  , RULL(0x0006C00A), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_OITR1_OCI                                    , RULL(0xC0060140), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OITR1_OCI1                                   , RULL(0xC0060148), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OITR1_OCI2                                   , RULL(0xC0060150), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_OITR1_SCOM                                   , RULL(0x0006C028), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_OITR1_SCOM1                                  , RULL(0x0006C029), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_OITR1_SCOM2                                  , RULL(0x0006C02A), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_ONISR0_OCI                                   , RULL(0xC0060300), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_ONISR0_SCOM                                  , RULL(0x0006C060), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_ONISR1_OCI                                   , RULL(0xC0060380), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_ONISR1_SCOM                                  , RULL(0x0006C070), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OPIT0C0_OCI                                  , RULL(0xC0062000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C0_OCI1                                 , RULL(0xC0062800), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C0_SCOM                                 , RULL(0x0006C400), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C0_SCOM1                                , RULL(0x0006C500), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C1_OCI                                  , RULL(0xC0062008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C1_OCI1                                 , RULL(0xC0062808), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C1_SCOM                                 , RULL(0x0006C401), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C1_SCOM1                                , RULL(0x0006C501), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C10_OCI                                 , RULL(0xC0062050), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C10_OCI1                                , RULL(0xC0062850), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C10_SCOM                                , RULL(0x0006C40A), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C10_SCOM1                               , RULL(0x0006C50A), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C11_OCI                                 , RULL(0xC0062058), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C11_OCI1                                , RULL(0xC0062858), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C11_SCOM                                , RULL(0x0006C40B), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C11_SCOM1                               , RULL(0x0006C50B), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C12_OCI                                 , RULL(0xC0062060), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C12_OCI1                                , RULL(0xC0062860), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C12_SCOM                                , RULL(0x0006C40C), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C12_SCOM1                               , RULL(0x0006C50C), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C13_OCI                                 , RULL(0xC0062068), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C13_OCI1                                , RULL(0xC0062868), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C13_SCOM                                , RULL(0x0006C40D), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C13_SCOM1                               , RULL(0x0006C50D), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C14_OCI                                 , RULL(0xC0062070), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C14_OCI1                                , RULL(0xC0062870), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C14_SCOM                                , RULL(0x0006C40E), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C14_SCOM1                               , RULL(0x0006C50E), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C15_OCI                                 , RULL(0xC0062078), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C15_OCI1                                , RULL(0xC0062878), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C15_SCOM                                , RULL(0x0006C40F), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C15_SCOM1                               , RULL(0x0006C50F), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C16_OCI                                 , RULL(0xC0062080), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C16_OCI1                                , RULL(0xC0062880), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C16_SCOM                                , RULL(0x0006C410), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C16_SCOM1                               , RULL(0x0006C510), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C17_OCI                                 , RULL(0xC0062088), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C17_OCI1                                , RULL(0xC0062888), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C17_SCOM                                , RULL(0x0006C411), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C17_SCOM1                               , RULL(0x0006C511), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C18_OCI                                 , RULL(0xC0062090), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C18_OCI1                                , RULL(0xC0062890), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C18_SCOM                                , RULL(0x0006C412), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C18_SCOM1                               , RULL(0x0006C512), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C19_OCI                                 , RULL(0xC0062098), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C19_OCI1                                , RULL(0xC0062898), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C19_SCOM                                , RULL(0x0006C413), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C19_SCOM1                               , RULL(0x0006C513), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C2_OCI                                  , RULL(0xC0062010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C2_OCI1                                 , RULL(0xC0062810), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C2_SCOM                                 , RULL(0x0006C402), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C2_SCOM1                                , RULL(0x0006C502), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C20_OCI                                 , RULL(0xC00620A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C20_OCI1                                , RULL(0xC00628A0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C20_SCOM                                , RULL(0x0006C414), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C20_SCOM1                               , RULL(0x0006C514), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C21_OCI                                 , RULL(0xC00620A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C21_OCI1                                , RULL(0xC00628A8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C21_SCOM                                , RULL(0x0006C415), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C21_SCOM1                               , RULL(0x0006C515), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C22_OCI                                 , RULL(0xC00620B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C22_OCI1                                , RULL(0xC00628B0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C22_SCOM                                , RULL(0x0006C416), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C22_SCOM1                               , RULL(0x0006C516), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C23_OCI                                 , RULL(0xC00620B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C23_OCI1                                , RULL(0xC00628B8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C23_SCOM                                , RULL(0x0006C417), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C23_SCOM1                               , RULL(0x0006C517), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C3_OCI                                  , RULL(0xC0062018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C3_OCI1                                 , RULL(0xC0062818), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C3_SCOM                                 , RULL(0x0006C403), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C3_SCOM1                                , RULL(0x0006C503), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C4_OCI                                  , RULL(0xC0062020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C4_OCI1                                 , RULL(0xC0062820), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C4_SCOM                                 , RULL(0x0006C404), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C4_SCOM1                                , RULL(0x0006C504), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C5_OCI                                  , RULL(0xC0062028), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C5_OCI1                                 , RULL(0xC0062828), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C5_SCOM                                 , RULL(0x0006C405), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C5_SCOM1                                , RULL(0x0006C505), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C6_OCI                                  , RULL(0xC0062030), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C6_OCI1                                 , RULL(0xC0062830), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C6_SCOM                                 , RULL(0x0006C406), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C6_SCOM1                                , RULL(0x0006C506), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C7_OCI                                  , RULL(0xC0062038), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C7_OCI1                                 , RULL(0xC0062838), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C7_SCOM                                 , RULL(0x0006C407), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C7_SCOM1                                , RULL(0x0006C507), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C8_OCI                                  , RULL(0xC0062040), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C8_OCI1                                 , RULL(0xC0062840), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C8_SCOM                                 , RULL(0x0006C408), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C8_SCOM1                                , RULL(0x0006C508), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0C9_OCI                                  , RULL(0xC0062048), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0C9_OCI1                                 , RULL(0xC0062848), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0C9_SCOM                                 , RULL(0x0006C409), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0C9_SCOM1                                , RULL(0x0006C509), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT0PRA_OCI                                 , RULL(0xC0063000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT0PRA_OCI1                                , RULL(0xC0063008), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT0PRA_SCOM                                , RULL(0x0006C600), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT0PRA_SCOM1                               , RULL(0x0006C601), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT1C0_OCI                                  , RULL(0xC0062100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C0_OCI1                                 , RULL(0xC0062900), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C0_SCOM                                 , RULL(0x0006C420), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C0_SCOM1                                , RULL(0x0006C520), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C1_OCI                                  , RULL(0xC0062108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C1_OCI1                                 , RULL(0xC0062908), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C1_SCOM                                 , RULL(0x0006C421), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C1_SCOM1                                , RULL(0x0006C521), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C10_OCI                                 , RULL(0xC0062150), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C10_OCI1                                , RULL(0xC0062950), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C10_SCOM                                , RULL(0x0006C42A), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C10_SCOM1                               , RULL(0x0006C52A), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C11_OCI                                 , RULL(0xC0062158), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C11_OCI1                                , RULL(0xC0062958), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C11_SCOM                                , RULL(0x0006C42B), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C11_SCOM1                               , RULL(0x0006C52B), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C12_OCI                                 , RULL(0xC0062160), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C12_OCI1                                , RULL(0xC0062960), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C12_SCOM                                , RULL(0x0006C42C), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C12_SCOM1                               , RULL(0x0006C52C), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C13_OCI                                 , RULL(0xC0062168), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C13_OCI1                                , RULL(0xC0062968), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C13_SCOM                                , RULL(0x0006C42D), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C13_SCOM1                               , RULL(0x0006C52D), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C14_OCI                                 , RULL(0xC0062170), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C14_OCI1                                , RULL(0xC0062970), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C14_SCOM                                , RULL(0x0006C42E), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C14_SCOM1                               , RULL(0x0006C52E), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C15_OCI                                 , RULL(0xC0062178), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C15_OCI1                                , RULL(0xC0062978), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C15_SCOM                                , RULL(0x0006C42F), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C15_SCOM1                               , RULL(0x0006C52F), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C16_OCI                                 , RULL(0xC0062180), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C16_OCI1                                , RULL(0xC0062980), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C16_SCOM                                , RULL(0x0006C430), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C16_SCOM1                               , RULL(0x0006C530), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C17_OCI                                 , RULL(0xC0062188), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C17_OCI1                                , RULL(0xC0062988), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C17_SCOM                                , RULL(0x0006C431), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C17_SCOM1                               , RULL(0x0006C531), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C18_OCI                                 , RULL(0xC0062190), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C18_OCI1                                , RULL(0xC0062990), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C18_SCOM                                , RULL(0x0006C432), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C18_SCOM1                               , RULL(0x0006C532), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C19_OCI                                 , RULL(0xC0062198), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C19_OCI1                                , RULL(0xC0062998), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C19_SCOM                                , RULL(0x0006C433), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C19_SCOM1                               , RULL(0x0006C533), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C2_OCI                                  , RULL(0xC0062110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C2_OCI1                                 , RULL(0xC0062910), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C2_SCOM                                 , RULL(0x0006C422), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C2_SCOM1                                , RULL(0x0006C522), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C20_OCI                                 , RULL(0xC00621A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C20_OCI1                                , RULL(0xC00629A0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C20_SCOM                                , RULL(0x0006C434), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C20_SCOM1                               , RULL(0x0006C534), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C21_OCI                                 , RULL(0xC00621A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C21_OCI1                                , RULL(0xC00629A8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C21_SCOM                                , RULL(0x0006C435), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C21_SCOM1                               , RULL(0x0006C535), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C22_OCI                                 , RULL(0xC00621B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C22_OCI1                                , RULL(0xC00629B0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C22_SCOM                                , RULL(0x0006C436), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C22_SCOM1                               , RULL(0x0006C536), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C23_OCI                                 , RULL(0xC00621B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C23_OCI1                                , RULL(0xC00629B8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C23_SCOM                                , RULL(0x0006C437), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C23_SCOM1                               , RULL(0x0006C537), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C3_OCI                                  , RULL(0xC0062118), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C3_OCI1                                 , RULL(0xC0062918), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C3_SCOM                                 , RULL(0x0006C423), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C3_SCOM1                                , RULL(0x0006C523), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C4_OCI                                  , RULL(0xC0062120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C4_OCI1                                 , RULL(0xC0062920), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C4_SCOM                                 , RULL(0x0006C424), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C4_SCOM1                                , RULL(0x0006C524), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C5_OCI                                  , RULL(0xC0062128), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C5_OCI1                                 , RULL(0xC0062928), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C5_SCOM                                 , RULL(0x0006C425), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C5_SCOM1                                , RULL(0x0006C525), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C6_OCI                                  , RULL(0xC0062130), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C6_OCI1                                 , RULL(0xC0062930), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C6_SCOM                                 , RULL(0x0006C426), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C6_SCOM1                                , RULL(0x0006C526), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C7_OCI                                  , RULL(0xC0062138), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C7_OCI1                                 , RULL(0xC0062938), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C7_SCOM                                 , RULL(0x0006C427), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C7_SCOM1                                , RULL(0x0006C527), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C8_OCI                                  , RULL(0xC0062140), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C8_OCI1                                 , RULL(0xC0062940), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C8_SCOM                                 , RULL(0x0006C428), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C8_SCOM1                                , RULL(0x0006C528), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1C9_OCI                                  , RULL(0xC0062148), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1C9_OCI1                                 , RULL(0xC0062948), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1C9_SCOM                                 , RULL(0x0006C429), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1C9_SCOM1                                , RULL(0x0006C529), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT1PRA_OCI                                 , RULL(0xC0063100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT1PRA_OCI1                                , RULL(0xC0063108), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT1PRA_SCOM                                , RULL(0x0006C620), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT1PRA_SCOM1                               , RULL(0x0006C621), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT2C0_OCI                                  , RULL(0xC0062200), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C0_OCI1                                 , RULL(0xC0062A00), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C0_SCOM                                 , RULL(0x0006C440), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C0_SCOM1                                , RULL(0x0006C540), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C1_OCI                                  , RULL(0xC0062208), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C1_OCI1                                 , RULL(0xC0062A08), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C1_SCOM                                 , RULL(0x0006C441), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C1_SCOM1                                , RULL(0x0006C541), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C10_OCI                                 , RULL(0xC0062250), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C10_OCI1                                , RULL(0xC0062A50), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C10_SCOM                                , RULL(0x0006C44A), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C10_SCOM1                               , RULL(0x0006C54A), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C11_OCI                                 , RULL(0xC0062258), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C11_OCI1                                , RULL(0xC0062A58), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C11_SCOM                                , RULL(0x0006C44B), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C11_SCOM1                               , RULL(0x0006C54B), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C12_OCI                                 , RULL(0xC0062260), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C12_OCI1                                , RULL(0xC0062A60), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C12_SCOM                                , RULL(0x0006C44C), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C12_SCOM1                               , RULL(0x0006C54C), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C13_OCI                                 , RULL(0xC0062268), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C13_OCI1                                , RULL(0xC0062A68), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C13_SCOM                                , RULL(0x0006C44D), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C13_SCOM1                               , RULL(0x0006C54D), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C14_OCI                                 , RULL(0xC0062270), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C14_OCI1                                , RULL(0xC0062A70), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C14_SCOM                                , RULL(0x0006C44E), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C14_SCOM1                               , RULL(0x0006C54E), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C15_OCI                                 , RULL(0xC0062278), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C15_OCI1                                , RULL(0xC0062A78), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C15_SCOM                                , RULL(0x0006C44F), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C15_SCOM1                               , RULL(0x0006C54F), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C16_OCI                                 , RULL(0xC0062280), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C16_OCI1                                , RULL(0xC0062A80), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C16_SCOM                                , RULL(0x0006C450), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C16_SCOM1                               , RULL(0x0006C550), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C17_OCI                                 , RULL(0xC0062288), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C17_OCI1                                , RULL(0xC0062A88), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C17_SCOM                                , RULL(0x0006C451), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C17_SCOM1                               , RULL(0x0006C551), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C18_OCI                                 , RULL(0xC0062290), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C18_OCI1                                , RULL(0xC0062A90), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C18_SCOM                                , RULL(0x0006C452), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C18_SCOM1                               , RULL(0x0006C552), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C19_OCI                                 , RULL(0xC0062298), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C19_OCI1                                , RULL(0xC0062A98), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C19_SCOM                                , RULL(0x0006C453), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C19_SCOM1                               , RULL(0x0006C553), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C2_OCI                                  , RULL(0xC0062210), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C2_OCI1                                 , RULL(0xC0062A10), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C2_SCOM                                 , RULL(0x0006C442), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C2_SCOM1                                , RULL(0x0006C542), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C20_OCI                                 , RULL(0xC00622A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C20_OCI1                                , RULL(0xC0062AA0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C20_SCOM                                , RULL(0x0006C454), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C20_SCOM1                               , RULL(0x0006C554), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C21_OCI                                 , RULL(0xC00622A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C21_OCI1                                , RULL(0xC0062AA8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C21_SCOM                                , RULL(0x0006C455), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C21_SCOM1                               , RULL(0x0006C555), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C22_OCI                                 , RULL(0xC00622B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C22_OCI1                                , RULL(0xC0062AB0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C22_SCOM                                , RULL(0x0006C456), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C22_SCOM1                               , RULL(0x0006C556), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C23_OCI                                 , RULL(0xC00622B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C23_OCI1                                , RULL(0xC0062AB8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C23_SCOM                                , RULL(0x0006C457), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C23_SCOM1                               , RULL(0x0006C557), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C3_OCI                                  , RULL(0xC0062218), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C3_OCI1                                 , RULL(0xC0062A18), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C3_SCOM                                 , RULL(0x0006C443), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C3_SCOM1                                , RULL(0x0006C543), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C4_OCI                                  , RULL(0xC0062220), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C4_OCI1                                 , RULL(0xC0062A20), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C4_SCOM                                 , RULL(0x0006C444), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C4_SCOM1                                , RULL(0x0006C544), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C5_OCI                                  , RULL(0xC0062228), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C5_OCI1                                 , RULL(0xC0062A28), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C5_SCOM                                 , RULL(0x0006C445), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C5_SCOM1                                , RULL(0x0006C545), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C6_OCI                                  , RULL(0xC0062230), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C6_OCI1                                 , RULL(0xC0062A30), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C6_SCOM                                 , RULL(0x0006C446), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C6_SCOM1                                , RULL(0x0006C546), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C7_OCI                                  , RULL(0xC0062238), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C7_OCI1                                 , RULL(0xC0062A38), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C7_SCOM                                 , RULL(0x0006C447), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C7_SCOM1                                , RULL(0x0006C547), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C8_OCI                                  , RULL(0xC0062240), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C8_OCI1                                 , RULL(0xC0062A40), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C8_SCOM                                 , RULL(0x0006C448), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C8_SCOM1                                , RULL(0x0006C548), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2C9_OCI                                  , RULL(0xC0062248), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2C9_OCI1                                 , RULL(0xC0062A48), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2C9_SCOM                                 , RULL(0x0006C449), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2C9_SCOM1                                , RULL(0x0006C549), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT2PRA_OCI                                 , RULL(0xC0063200), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT2PRA_OCI1                                , RULL(0xC0063208), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT2PRA_SCOM                                , RULL(0x0006C640), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT2PRA_SCOM1                               , RULL(0x0006C641), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT3C0_OCI                                  , RULL(0xC0062300), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C0_OCI1                                 , RULL(0xC0062B00), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C0_SCOM                                 , RULL(0x0006C460), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C0_SCOM1                                , RULL(0x0006C560), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C1_OCI                                  , RULL(0xC0062308), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C1_OCI1                                 , RULL(0xC0062B08), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C1_SCOM                                 , RULL(0x0006C461), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C1_SCOM1                                , RULL(0x0006C561), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C10_OCI                                 , RULL(0xC0062350), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C10_OCI1                                , RULL(0xC0062B50), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C10_SCOM                                , RULL(0x0006C46A), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C10_SCOM1                               , RULL(0x0006C56A), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C11_OCI                                 , RULL(0xC0062358), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C11_OCI1                                , RULL(0xC0062B58), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C11_SCOM                                , RULL(0x0006C46B), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C11_SCOM1                               , RULL(0x0006C56B), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C12_OCI                                 , RULL(0xC0062360), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C12_OCI1                                , RULL(0xC0062B60), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C12_SCOM                                , RULL(0x0006C46C), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C12_SCOM1                               , RULL(0x0006C56C), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C13_OCI                                 , RULL(0xC0062368), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C13_OCI1                                , RULL(0xC0062B68), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C13_SCOM                                , RULL(0x0006C46D), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C13_SCOM1                               , RULL(0x0006C56D), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C14_OCI                                 , RULL(0xC0062370), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C14_OCI1                                , RULL(0xC0062B70), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C14_SCOM                                , RULL(0x0006C46E), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C14_SCOM1                               , RULL(0x0006C56E), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C15_OCI                                 , RULL(0xC0062378), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C15_OCI1                                , RULL(0xC0062B78), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C15_SCOM                                , RULL(0x0006C46F), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C15_SCOM1                               , RULL(0x0006C56F), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C16_OCI                                 , RULL(0xC0062380), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C16_OCI1                                , RULL(0xC0062B80), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C16_SCOM                                , RULL(0x0006C470), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C16_SCOM1                               , RULL(0x0006C570), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C17_OCI                                 , RULL(0xC0062388), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C17_OCI1                                , RULL(0xC0062B88), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C17_SCOM                                , RULL(0x0006C471), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C17_SCOM1                               , RULL(0x0006C571), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C18_OCI                                 , RULL(0xC0062390), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C18_OCI1                                , RULL(0xC0062B90), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C18_SCOM                                , RULL(0x0006C472), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C18_SCOM1                               , RULL(0x0006C572), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C19_OCI                                 , RULL(0xC0062398), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C19_OCI1                                , RULL(0xC0062B98), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C19_SCOM                                , RULL(0x0006C473), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C19_SCOM1                               , RULL(0x0006C573), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C2_OCI                                  , RULL(0xC0062310), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C2_OCI1                                 , RULL(0xC0062B10), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C2_SCOM                                 , RULL(0x0006C462), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C2_SCOM1                                , RULL(0x0006C562), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C20_OCI                                 , RULL(0xC00623A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C20_OCI1                                , RULL(0xC0062BA0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C20_SCOM                                , RULL(0x0006C474), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C20_SCOM1                               , RULL(0x0006C574), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C21_OCI                                 , RULL(0xC00623A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C21_OCI1                                , RULL(0xC0062BA8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C21_SCOM                                , RULL(0x0006C475), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C21_SCOM1                               , RULL(0x0006C575), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C22_OCI                                 , RULL(0xC00623B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C22_OCI1                                , RULL(0xC0062BB0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C22_SCOM                                , RULL(0x0006C476), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C22_SCOM1                               , RULL(0x0006C576), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C23_OCI                                 , RULL(0xC00623B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C23_OCI1                                , RULL(0xC0062BB8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C23_SCOM                                , RULL(0x0006C477), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C23_SCOM1                               , RULL(0x0006C577), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C3_OCI                                  , RULL(0xC0062318), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C3_OCI1                                 , RULL(0xC0062B18), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C3_SCOM                                 , RULL(0x0006C463), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C3_SCOM1                                , RULL(0x0006C563), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C4_OCI                                  , RULL(0xC0062320), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C4_OCI1                                 , RULL(0xC0062B20), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C4_SCOM                                 , RULL(0x0006C464), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C4_SCOM1                                , RULL(0x0006C564), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C5_OCI                                  , RULL(0xC0062328), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C5_OCI1                                 , RULL(0xC0062B28), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C5_SCOM                                 , RULL(0x0006C465), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C5_SCOM1                                , RULL(0x0006C565), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C6_OCI                                  , RULL(0xC0062330), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C6_OCI1                                 , RULL(0xC0062B30), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C6_SCOM                                 , RULL(0x0006C466), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C6_SCOM1                                , RULL(0x0006C566), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C7_OCI                                  , RULL(0xC0062338), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C7_OCI1                                 , RULL(0xC0062B38), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C7_SCOM                                 , RULL(0x0006C467), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C7_SCOM1                                , RULL(0x0006C567), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C8_OCI                                  , RULL(0xC0062340), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C8_OCI1                                 , RULL(0xC0062B40), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C8_SCOM                                 , RULL(0x0006C468), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C8_SCOM1                                , RULL(0x0006C568), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3C9_OCI                                  , RULL(0xC0062348), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3C9_OCI1                                 , RULL(0xC0062B48), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3C9_SCOM                                 , RULL(0x0006C469), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3C9_SCOM1                                , RULL(0x0006C569), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT3PRA_OCI                                 , RULL(0xC0063300), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT3PRA_OCI1                                , RULL(0xC0063308), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT3PRA_SCOM                                , RULL(0x0006C660), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT3PRA_SCOM1                               , RULL(0x0006C661), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT4C0_OCI                                  , RULL(0xC0062400), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C0_OCI1                                 , RULL(0xC0062C00), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C0_SCOM                                 , RULL(0x0006C480), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C0_SCOM1                                , RULL(0x0006C580), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C1_OCI                                  , RULL(0xC0062408), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C1_OCI1                                 , RULL(0xC0062C08), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C1_SCOM                                 , RULL(0x0006C481), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C1_SCOM1                                , RULL(0x0006C581), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C10_OCI                                 , RULL(0xC0062450), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C10_OCI1                                , RULL(0xC0062C50), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C10_SCOM                                , RULL(0x0006C48A), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C10_SCOM1                               , RULL(0x0006C58A), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C11_OCI                                 , RULL(0xC0062458), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C11_OCI1                                , RULL(0xC0062C58), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C11_SCOM                                , RULL(0x0006C48B), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C11_SCOM1                               , RULL(0x0006C58B), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C12_OCI                                 , RULL(0xC0062460), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C12_OCI1                                , RULL(0xC0062C60), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C12_SCOM                                , RULL(0x0006C48C), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C12_SCOM1                               , RULL(0x0006C58C), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C13_OCI                                 , RULL(0xC0062468), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C13_OCI1                                , RULL(0xC0062C68), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C13_SCOM                                , RULL(0x0006C48D), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C13_SCOM1                               , RULL(0x0006C58D), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C14_OCI                                 , RULL(0xC0062470), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C14_OCI1                                , RULL(0xC0062C70), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C14_SCOM                                , RULL(0x0006C48E), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C14_SCOM1                               , RULL(0x0006C58E), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C15_OCI                                 , RULL(0xC0062478), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C15_OCI1                                , RULL(0xC0062C78), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C15_SCOM                                , RULL(0x0006C48F), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C15_SCOM1                               , RULL(0x0006C58F), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C16_OCI                                 , RULL(0xC0062480), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C16_OCI1                                , RULL(0xC0062C80), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C16_SCOM                                , RULL(0x0006C490), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C16_SCOM1                               , RULL(0x0006C590), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C17_OCI                                 , RULL(0xC0062488), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C17_OCI1                                , RULL(0xC0062C88), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C17_SCOM                                , RULL(0x0006C491), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C17_SCOM1                               , RULL(0x0006C591), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C18_OCI                                 , RULL(0xC0062490), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C18_OCI1                                , RULL(0xC0062C90), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C18_SCOM                                , RULL(0x0006C492), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C18_SCOM1                               , RULL(0x0006C592), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C19_OCI                                 , RULL(0xC0062498), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C19_OCI1                                , RULL(0xC0062C98), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C19_SCOM                                , RULL(0x0006C493), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C19_SCOM1                               , RULL(0x0006C593), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C2_OCI                                  , RULL(0xC0062410), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C2_OCI1                                 , RULL(0xC0062C10), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C2_SCOM                                 , RULL(0x0006C482), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C2_SCOM1                                , RULL(0x0006C582), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C20_OCI                                 , RULL(0xC00624A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C20_OCI1                                , RULL(0xC0062CA0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C20_SCOM                                , RULL(0x0006C494), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C20_SCOM1                               , RULL(0x0006C594), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C21_OCI                                 , RULL(0xC00624A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C21_OCI1                                , RULL(0xC0062CA8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C21_SCOM                                , RULL(0x0006C495), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C21_SCOM1                               , RULL(0x0006C595), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C22_OCI                                 , RULL(0xC00624B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C22_OCI1                                , RULL(0xC0062CB0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C22_SCOM                                , RULL(0x0006C496), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C22_SCOM1                               , RULL(0x0006C596), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C23_OCI                                 , RULL(0xC00624B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C23_OCI1                                , RULL(0xC0062CB8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C23_SCOM                                , RULL(0x0006C497), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C23_SCOM1                               , RULL(0x0006C597), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C3_OCI                                  , RULL(0xC0062418), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C3_OCI1                                 , RULL(0xC0062C18), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C3_SCOM                                 , RULL(0x0006C483), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C3_SCOM1                                , RULL(0x0006C583), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C4_OCI                                  , RULL(0xC0062420), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C4_OCI1                                 , RULL(0xC0062C20), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C4_SCOM                                 , RULL(0x0006C484), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C4_SCOM1                                , RULL(0x0006C584), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C5_OCI                                  , RULL(0xC0062428), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C5_OCI1                                 , RULL(0xC0062C28), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C5_SCOM                                 , RULL(0x0006C485), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C5_SCOM1                                , RULL(0x0006C585), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C6_OCI                                  , RULL(0xC0062430), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C6_OCI1                                 , RULL(0xC0062C30), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C6_SCOM                                 , RULL(0x0006C486), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C6_SCOM1                                , RULL(0x0006C586), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C7_OCI                                  , RULL(0xC0062438), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C7_OCI1                                 , RULL(0xC0062C38), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C7_SCOM                                 , RULL(0x0006C487), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C7_SCOM1                                , RULL(0x0006C587), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C8_OCI                                  , RULL(0xC0062440), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C8_OCI1                                 , RULL(0xC0062C40), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C8_SCOM                                 , RULL(0x0006C488), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C8_SCOM1                                , RULL(0x0006C588), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4C9_OCI                                  , RULL(0xC0062448), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4C9_OCI1                                 , RULL(0xC0062C48), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4C9_SCOM                                 , RULL(0x0006C489), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4C9_SCOM1                                , RULL(0x0006C589), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT4PRA_OCI                                 , RULL(0xC0063400), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT4PRA_OCI1                                , RULL(0xC0063408), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT4PRA_SCOM                                , RULL(0x0006C680), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT4PRA_SCOM1                               , RULL(0x0006C681), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT5C0_OCI                                  , RULL(0xC0062500), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C0_OCI1                                 , RULL(0xC0062D00), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C0_SCOM                                 , RULL(0x0006C4A0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C0_SCOM1                                , RULL(0x0006C5A0), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C1_OCI                                  , RULL(0xC0062508), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C1_OCI1                                 , RULL(0xC0062D08), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C1_SCOM                                 , RULL(0x0006C4A1), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C1_SCOM1                                , RULL(0x0006C5A1), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C10_OCI                                 , RULL(0xC0062550), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C10_OCI1                                , RULL(0xC0062D50), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C10_SCOM                                , RULL(0x0006C4AA), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C10_SCOM1                               , RULL(0x0006C5AA), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C11_OCI                                 , RULL(0xC0062558), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C11_OCI1                                , RULL(0xC0062D58), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C11_SCOM                                , RULL(0x0006C4AB), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C11_SCOM1                               , RULL(0x0006C5AB), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C12_OCI                                 , RULL(0xC0062560), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C12_OCI1                                , RULL(0xC0062D60), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C12_SCOM                                , RULL(0x0006C4AC), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C12_SCOM1                               , RULL(0x0006C5AC), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C13_OCI                                 , RULL(0xC0062568), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C13_OCI1                                , RULL(0xC0062D68), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C13_SCOM                                , RULL(0x0006C4AD), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C13_SCOM1                               , RULL(0x0006C5AD), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C14_OCI                                 , RULL(0xC0062570), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C14_OCI1                                , RULL(0xC0062D70), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C14_SCOM                                , RULL(0x0006C4AE), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C14_SCOM1                               , RULL(0x0006C5AE), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C15_OCI                                 , RULL(0xC0062578), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C15_OCI1                                , RULL(0xC0062D78), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C15_SCOM                                , RULL(0x0006C4AF), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C15_SCOM1                               , RULL(0x0006C5AF), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C16_OCI                                 , RULL(0xC0062580), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C16_OCI1                                , RULL(0xC0062D80), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C16_SCOM                                , RULL(0x0006C4B0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C16_SCOM1                               , RULL(0x0006C5B0), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C17_OCI                                 , RULL(0xC0062588), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C17_OCI1                                , RULL(0xC0062D88), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C17_SCOM                                , RULL(0x0006C4B1), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C17_SCOM1                               , RULL(0x0006C5B1), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C18_OCI                                 , RULL(0xC0062590), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C18_OCI1                                , RULL(0xC0062D90), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C18_SCOM                                , RULL(0x0006C4B2), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C18_SCOM1                               , RULL(0x0006C5B2), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C19_OCI                                 , RULL(0xC0062598), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C19_OCI1                                , RULL(0xC0062D98), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C19_SCOM                                , RULL(0x0006C4B3), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C19_SCOM1                               , RULL(0x0006C5B3), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C2_OCI                                  , RULL(0xC0062510), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C2_OCI1                                 , RULL(0xC0062D10), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C2_SCOM                                 , RULL(0x0006C4A2), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C2_SCOM1                                , RULL(0x0006C5A2), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C20_OCI                                 , RULL(0xC00625A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C20_OCI1                                , RULL(0xC0062DA0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C20_SCOM                                , RULL(0x0006C4B4), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C20_SCOM1                               , RULL(0x0006C5B4), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C21_OCI                                 , RULL(0xC00625A8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C21_OCI1                                , RULL(0xC0062DA8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C21_SCOM                                , RULL(0x0006C4B5), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C21_SCOM1                               , RULL(0x0006C5B5), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C22_OCI                                 , RULL(0xC00625B0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C22_OCI1                                , RULL(0xC0062DB0), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C22_SCOM                                , RULL(0x0006C4B6), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C22_SCOM1                               , RULL(0x0006C5B6), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C23_OCI                                 , RULL(0xC00625B8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C23_OCI1                                , RULL(0xC0062DB8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C23_SCOM                                , RULL(0x0006C4B7), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C23_SCOM1                               , RULL(0x0006C5B7), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C3_OCI                                  , RULL(0xC0062518), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C3_OCI1                                 , RULL(0xC0062D18), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C3_SCOM                                 , RULL(0x0006C4A3), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C3_SCOM1                                , RULL(0x0006C5A3), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C4_OCI                                  , RULL(0xC0062520), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C4_OCI1                                 , RULL(0xC0062D20), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C4_SCOM                                 , RULL(0x0006C4A4), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C4_SCOM1                                , RULL(0x0006C5A4), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C5_OCI                                  , RULL(0xC0062528), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C5_OCI1                                 , RULL(0xC0062D28), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C5_SCOM                                 , RULL(0x0006C4A5), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C5_SCOM1                                , RULL(0x0006C5A5), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C6_OCI                                  , RULL(0xC0062530), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C6_OCI1                                 , RULL(0xC0062D30), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C6_SCOM                                 , RULL(0x0006C4A6), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C6_SCOM1                                , RULL(0x0006C5A6), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C7_OCI                                  , RULL(0xC0062538), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C7_OCI1                                 , RULL(0xC0062D38), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C7_SCOM                                 , RULL(0x0006C4A7), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C7_SCOM1                                , RULL(0x0006C5A7), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C8_OCI                                  , RULL(0xC0062540), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C8_OCI1                                 , RULL(0xC0062D40), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C8_SCOM                                 , RULL(0x0006C4A8), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C8_SCOM1                                , RULL(0x0006C5A8), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5C9_OCI                                  , RULL(0xC0062548), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5C9_OCI1                                 , RULL(0xC0062D48), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5C9_SCOM                                 , RULL(0x0006C4A9), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5C9_SCOM1                                , RULL(0x0006C5A9), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT5PRA_OCI                                 , RULL(0xC0063500), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT5PRA_OCI1                                , RULL(0xC0063508), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT5PRA_SCOM                                , RULL(0x0006C6A0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT5PRA_SCOM1                               , RULL(0x0006C6A1), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT6PRB_OCI                                 , RULL(0xC0063600), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6PRB_OCI1                                , RULL(0xC0063608), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6PRB_SCOM                                , RULL(0x0006C6C0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6PRB_SCOM1                               , RULL(0x0006C6C1), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT6Q0_OCI                                  , RULL(0xC0062600), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6Q0_OCI1                                 , RULL(0xC0062E00), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6Q0_SCOM                                 , RULL(0x0006C4C0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6Q0_SCOM1                                , RULL(0x0006C5C0), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT6Q1_OCI                                  , RULL(0xC0062608), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6Q1_OCI1                                 , RULL(0xC0062E08), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6Q1_SCOM                                 , RULL(0x0006C4C1), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6Q1_SCOM1                                , RULL(0x0006C5C1), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT6Q2_OCI                                  , RULL(0xC0062610), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6Q2_OCI1                                 , RULL(0xC0062E10), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6Q2_SCOM                                 , RULL(0x0006C4C2), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6Q2_SCOM1                                , RULL(0x0006C5C2), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT6Q3_OCI                                  , RULL(0xC0062618), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6Q3_OCI1                                 , RULL(0xC0062E18), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6Q3_SCOM                                 , RULL(0x0006C4C3), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6Q3_SCOM1                                , RULL(0x0006C5C3), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT6Q4_OCI                                  , RULL(0xC0062620), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6Q4_OCI1                                 , RULL(0xC0062E20), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6Q4_SCOM                                 , RULL(0x0006C4C4), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6Q4_SCOM1                                , RULL(0x0006C5C4), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT6Q5_OCI                                  , RULL(0xC0062628), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT6Q5_OCI1                                 , RULL(0xC0062E28), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT6Q5_SCOM                                 , RULL(0x0006C4C5), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT6Q5_SCOM1                                , RULL(0x0006C5C5), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT7PRB_OCI                                 , RULL(0xC0063700), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7PRB_OCI1                                , RULL(0xC0063708), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7PRB_SCOM                                , RULL(0x0006C6E0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7PRB_SCOM1                               , RULL(0x0006C6E1), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );

REG64( PU_OCB_OCI_OPIT7Q0_OCI                                  , RULL(0xC0062700), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7Q0_OCI1                                 , RULL(0xC0062F00), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7Q0_SCOM                                 , RULL(0x0006C4E0), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7Q0_SCOM1                                , RULL(0x0006C5E0), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT7Q1_OCI                                  , RULL(0xC0062708), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7Q1_OCI1                                 , RULL(0xC0062F08), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7Q1_SCOM                                 , RULL(0x0006C4E1), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7Q1_SCOM1                                , RULL(0x0006C5E1), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT7Q2_OCI                                  , RULL(0xC0062710), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7Q2_OCI1                                 , RULL(0xC0062F10), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7Q2_SCOM                                 , RULL(0x0006C4E2), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7Q2_SCOM1                                , RULL(0x0006C5E2), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT7Q3_OCI                                  , RULL(0xC0062718), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7Q3_OCI1                                 , RULL(0xC0062F18), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7Q3_SCOM                                 , RULL(0x0006C4E3), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7Q3_SCOM1                                , RULL(0x0006C5E3), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT7Q4_OCI                                  , RULL(0xC0062720), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7Q4_OCI1                                 , RULL(0xC0062F20), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7Q4_SCOM                                 , RULL(0x0006C4E4), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7Q4_SCOM1                                , RULL(0x0006C5E4), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OPIT7Q5_OCI                                  , RULL(0xC0062728), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OPIT7Q5_OCI1                                 , RULL(0xC0062F28), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_OPIT7Q5_SCOM                                 , RULL(0x0006C4E5), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_OCI_OPIT7Q5_SCOM1                                , RULL(0x0006C5E5), SH_UNT          , SH_ACS_SCOM1_RO  );

REG64( PU_OCB_OCI_OTBR_OCI                                     , RULL(0xC00604F8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OTBR_SCOM                                    , RULL(0x0006C09F), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OTR0_OCI                                     , RULL(0xC0060800), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OTR0_SCOM                                    , RULL(0x0006C100), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OTR1_OCI                                     , RULL(0xC0060808), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OTR1_SCOM                                    , RULL(0x0006C101), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_OCI_OUISR0_OCI                                   , RULL(0xC0060310), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OUISR0_SCOM                                  , RULL(0x0006C062), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_OUISR1_OCI                                   , RULL(0xC0060390), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_OUISR1_SCOM                                  , RULL(0x0006C072), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_OCI_QCSR_OCI                                     , RULL(0xC00604A0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_QCSR_OCI1                                    , RULL(0xC00604A8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_QCSR_OCI2                                    , RULL(0xC00604B0), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_QCSR_SCOM                                    , RULL(0x0006C094), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_QCSR_SCOM1                                   , RULL(0x0006C095), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_QCSR_SCOM2                                   , RULL(0x0006C096), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_OCI_QSSR_OCI                                     , RULL(0xC00604C0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_OCB_OCI_QSSR_OCI1                                    , RULL(0xC00604C8), SH_UNT          , SH_ACS_OCI1      );
REG64( PU_OCB_OCI_QSSR_OCI2                                    , RULL(0xC00604D0), SH_UNT          , SH_ACS_OCI2      );
REG64( PU_OCB_OCI_QSSR_SCOM                                    , RULL(0x0006C098), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_OCB_OCI_QSSR_SCOM1                                   , RULL(0x0006C099), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_OCI_QSSR_SCOM2                                   , RULL(0x0006C09A), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_PIB_OACR                                         , RULL(0x0006D207), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBAR0                                       , RULL(0x0006D010), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBAR1                                       , RULL(0x0006D030), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBAR2                                       , RULL(0x0006D050), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBAR3                                       , RULL(0x0006D070), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBCSR0_RO                                   , RULL(0x0006D011), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_PIB_OCBCSR0_CLEAR                                , RULL(0x0006D012), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_PIB_OCBCSR0_OR                                   , RULL(0x0006D013), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_PIB_OCBCSR1_RO                                   , RULL(0x0006D031), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_PIB_OCBCSR1_CLEAR                                , RULL(0x0006D032), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_PIB_OCBCSR1_OR                                   , RULL(0x0006D033), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_PIB_OCBCSR2_RO                                   , RULL(0x0006D051), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_PIB_OCBCSR2_CLEAR                                , RULL(0x0006D052), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_PIB_OCBCSR2_OR                                   , RULL(0x0006D053), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_PIB_OCBCSR3_RO                                   , RULL(0x0006D071), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_PIB_OCBCSR3_CLEAR                                , RULL(0x0006D072), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_PIB_OCBCSR3_OR                                   , RULL(0x0006D073), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_PIB_OCBDR0                                       , RULL(0x0006D015), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBDR1                                       , RULL(0x0006D035), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBDR2                                       , RULL(0x0006D055), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBDR3                                       , RULL(0x0006D075), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCBEAR                                       , RULL(0x0006D210), SH_UNT          ,
       SH_ACS_SCOM_WCLRPART );

REG64( PU_OCB_PIB_OCBESR0                                      , RULL(0x0006D014), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_OCB_PIB_OCBESR1                                      , RULL(0x0006D034), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_OCB_PIB_OCBESR2                                      , RULL(0x0006D054), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_OCB_PIB_OCBESR3                                      , RULL(0x0006D074), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_OCB_PIB_OCDBG                                        , RULL(0x0006D003), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OCR_RO                                       , RULL(0x0006D000), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_OCB_PIB_OCR_CLEAR                                    , RULL(0x0006D001), SH_UNT          ,
       SH_ACS_SCOM1_CLEAR );
REG64( PU_OCB_PIB_OCR_OR                                       , RULL(0x0006D002), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_OCB_PIB_OEAR                                         , RULL(0x0006D206), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_PIB_OESR                                         , RULL(0x0006D204), SH_UNT          ,
       SH_ACS_SCOM_WCLEAR );

REG64( PU_OCB_PIB_OPPCINJ                                      , RULL(0x0006D111), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_OCB_PIB_OREV                                         , RULL(0x0006D202), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_OCB_PIB_OSTOEAR                                      , RULL(0x0006D200), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_OCB_PIB_OSTOESR                                      , RULL(0x0006D201), SH_UNT          ,
       SH_ACS_SCOM_WCLEAR );

REG64( PU_OCB_PIB_OTDCR                                        , RULL(0x0006D110), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_OPCG_ALIGN                                          , RULL(0x0D030001), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_ALIGN                                        , RULL(0x0D030001), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_ALIGN                                        , RULL(0x0E030001), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_ALIGN                                        , RULL(0x0F030001), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_OPCG_CAPT1                                          , RULL(0x0D030010), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_CAPT1                                        , RULL(0x0D030010), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_CAPT1                                        , RULL(0x0E030010), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_CAPT1                                        , RULL(0x0F030010), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_OPCG_CAPT2                                          , RULL(0x0D030011), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_CAPT2                                        , RULL(0x0D030011), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_CAPT2                                        , RULL(0x0E030011), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_CAPT2                                        , RULL(0x0F030011), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_OPCG_CAPT3                                          , RULL(0x0D030012), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_CAPT3                                        , RULL(0x0D030012), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_CAPT3                                        , RULL(0x0E030012), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_CAPT3                                        , RULL(0x0F030012), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_OPCG_REG0                                           , RULL(0x0D030002), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_REG0                                         , RULL(0x0D030002), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_REG0                                         , RULL(0x0E030002), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_REG0                                         , RULL(0x0F030002), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_OPCG_REG1                                           , RULL(0x0D030003), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_REG1                                         , RULL(0x0D030003), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_REG1                                         , RULL(0x0E030003), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_REG1                                         , RULL(0x0F030003), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_OPCG_REG2                                           , RULL(0x0D030004), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_OPCG_REG2                                         , RULL(0x0D030004), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_OPCG_REG2                                         , RULL(0x0E030004), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_OPCG_REG2                                         , RULL(0x0F030004), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU_CTL_OPTICAL_IO_CONFIG                            , RULL(0x05011383), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_PBABAR0                                              , RULL(0x05012B00), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABAR1                                              , RULL(0x05012B01), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABAR2                                              , RULL(0x05012B02), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABAR3                                              , RULL(0x05012B03), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABARMSK0                                           , RULL(0x05012B04), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABARMSK1                                           , RULL(0x05012B05), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABARMSK2                                           , RULL(0x05012B06), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBABARMSK3                                           , RULL(0x05012B07), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBACFG                                               , RULL(0x0501284B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBAERRRPT0                                           , RULL(0x0501284C), SH_UNT          ,
       SH_ACS_SCOM_WCLRPART );

REG64( PU_PBAERRRPT1                                           , RULL(0x0501284D), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAERRRPT2                                           , RULL(0x0501284E), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAFIR                                               , RULL(0x05012840), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PBAFIR_AND                                           , RULL(0x05012841), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PBAFIR_OR                                            , RULL(0x05012842), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PBAFIRACT0                                           , RULL(0x05012846), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBAFIRACT1                                           , RULL(0x05012847), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBAFIRMASK                                           , RULL(0x05012843), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PBAFIRMASK_AND                                       , RULL(0x05012844), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PBAFIRMASK_OR                                        , RULL(0x05012845), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PEC_PBAIBHWCFG_REG                                      , RULL(0x0D010800), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_PBAIBHWCFG_REG                                    , RULL(0x0D010800), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_PBAIBHWCFG_REG                                    , RULL(0x0E010800), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_PBAIBHWCFG_REG                                    , RULL(0x0F010800), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PHB_PBAIB_CERR_RPT_REG                                  , RULL(0x0D010841), SH_UNT_PHB      , SH_ACS_SCOM_RO   );
REG64( PHB_0_PBAIB_CERR_RPT_REG                                , RULL(0x0D010841), SH_UNT_PHB_0    , SH_ACS_SCOM_RO   );
REG64( PHB_1_PBAIB_CERR_RPT_REG                                , RULL(0x0E010841), SH_UNT_PHB_1    , SH_ACS_SCOM_RO   );
REG64( PHB_2_PBAIB_CERR_RPT_REG                                , RULL(0x0E010881), SH_UNT_PHB_2    , SH_ACS_SCOM_RO   );
REG64( PHB_3_PBAIB_CERR_RPT_REG                                , RULL(0x0F010841), SH_UNT_PHB_3    , SH_ACS_SCOM_RO   );
REG64( PHB_4_PBAIB_CERR_RPT_REG                                , RULL(0x0F010881), SH_UNT_PHB_4    , SH_ACS_SCOM_RO   );
REG64( PHB_5_PBAIB_CERR_RPT_REG                                , RULL(0x0F0108C1), SH_UNT_PHB_5    , SH_ACS_SCOM_RO   );
REG64( PU_PBAIB_STACK1_PBAIB_CERR_RPT_REG                      , RULL(0x0D010881), SH_UNT_PU_PBAIB_STACK1,
       SH_ACS_SCOM_RO   );
REG64( PU_PBAIB_STACK2_PBAIB_CERR_RPT_REG                      , RULL(0x0D0108C1), SH_UNT_PU_PBAIB_STACK2,
       SH_ACS_SCOM_RO   );
REG64( PU_PBAIB_STACK5_PBAIB_CERR_RPT_REG                      , RULL(0x0E0108C1), SH_UNT_PU_PBAIB_STACK5,
       SH_ACS_SCOM_RO   );

REG64( PU_PBAMODE_OCI                                          , RULL(0xC0040000), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAMODE_SCOM                                         , RULL(0x05016840), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PBAOCCACT                                            , RULL(0x0501284A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBAPBOCR0_OCI                                        , RULL(0xC00400D0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAPBOCR0_SCOM                                       , RULL(0x0501685A), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAPBOCR1_OCI                                        , RULL(0xC00400D8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAPBOCR1_SCOM                                       , RULL(0x0501685B), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAPBOCR2_OCI                                        , RULL(0xC00400E0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAPBOCR2_SCOM                                       , RULL(0x0501685C), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAPBOCR3_OCI                                        , RULL(0xC00400E8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAPBOCR3_SCOM                                       , RULL(0x0501685D), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAPBOCR4_OCI                                        , RULL(0xC00400F0), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAPBOCR4_SCOM                                       , RULL(0x0501685E), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAPBOCR5_OCI                                        , RULL(0xC00400F8), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAPBOCR5_SCOM                                       , RULL(0x0501685F), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBARBUFVAL0                                          , RULL(0x05012850), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBARBUFVAL1                                          , RULL(0x05012851), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBARBUFVAL2                                          , RULL(0x05012852), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBARBUFVAL3                                          , RULL(0x05012853), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBARBUFVAL4                                          , RULL(0x05012854), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBARBUFVAL5                                          , RULL(0x05012855), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBASLVCTL0_OCI                                       , RULL(0xC0040020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBASLVCTL0_SCOM                                      , RULL(0x05016844), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBASLVCTL1_OCI                                       , RULL(0xC0040028), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBASLVCTL1_SCOM                                      , RULL(0x05016845), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBASLVCTL2_OCI                                       , RULL(0xC0040030), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBASLVCTL2_SCOM                                      , RULL(0x05016846), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBASLVCTL3_OCI                                       , RULL(0xC0040038), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBASLVCTL3_SCOM                                      , RULL(0x05016847), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBASLVRST_OCI                                        , RULL(0xC0040008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBASLVRST_SCOM                                       , RULL(0x05016841), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PBAWBUFVAL0                                          , RULL(0x05012858), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAWBUFVAL1                                          , RULL(0x05012859), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAXCFG_OCI                                          , RULL(0xC0040108), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXCFG_SCOM                                         , RULL(0x05016861), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PBAXRCVSTAT_OCI                                      , RULL(0xC0040120), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXRCVSTAT_SCOM                                     , RULL(0x05016864), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAXSHBR0_OCI                                        , RULL(0xC0040130), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXSHBR0_SCOM                                       , RULL(0x05016866), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBAXSHBR1_OCI                                        , RULL(0xC0040150), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXSHBR1_SCOM                                       , RULL(0x0501686A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBAXSHCS0_OCI                                        , RULL(0xC0040138), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXSHCS0_SCOM                                       , RULL(0x05016867), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PBAXSHCS1_OCI                                        , RULL(0xC0040158), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXSHCS1_SCOM                                       , RULL(0x0501686B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PBAXSNDSTAT_OCI                                      , RULL(0xC0040110), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXSNDSTAT_SCOM                                     , RULL(0x05016862), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PBAXSNDTX_OCI                                        , RULL(0xC0040100), SH_UNT          , SH_ACS_OCI       );
REG64( PU_PBAXSNDTX_SCOM                                       , RULL(0x05016860), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_PBCQEINJ_REG                                        , RULL(0x04010C02), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_PBCQEINJ_REG                                      , RULL(0x04010C02), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_PBCQEINJ_REG                                      , RULL(0x04011002), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_PBCQEINJ_REG                                      , RULL(0x04011402), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_PBCQHWCFG_REG                                       , RULL(0x04010C00), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_PBCQHWCFG_REG                                     , RULL(0x04010C00), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_PBCQHWCFG_REG                                     , RULL(0x04011000), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_PBCQHWCFG_REG                                     , RULL(0x04011400), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_0_STACK0_PBCQMODE_REG                               , RULL(0x04010C4D), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_PBCQMODE_REG                               , RULL(0x04010C8D), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_PBCQMODE_REG                               , RULL(0x04010CCD), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_PBCQMODE_REG                               , RULL(0x0401104D), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_PBCQMODE_REG                               , RULL(0x0401108D), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_PBCQMODE_REG                               , RULL(0x040110CD), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_PBCQMODE_REG                               , RULL(0x0401144D), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_PBCQMODE_REG                               , RULL(0x0401148D), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_PBCQMODE_REG                               , RULL(0x040114CD), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_PBCQMODE_REG                                 , RULL(0x04010C4D), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_PBCQMODE_REG                                 , RULL(0x04010C8D), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_PBCQMODE_REG                                 , RULL(0x04010CCD), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PHB_PBCQMODE_REG                                        , RULL(0x04010C4D), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_PBCQMODE_REG                                      , RULL(0x04010C4D), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_PBCQMODE_REG                                      , RULL(0x0401104D), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_PBCQMODE_REG                                      , RULL(0x0401108D), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_PBCQMODE_REG                                      , RULL(0x0401144D), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_PBCQMODE_REG                                      , RULL(0x0401148D), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_PBCQMODE_REG                                      , RULL(0x040114CD), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_00_REG                                   , RULL(0x05013430), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_01_REG                                   , RULL(0x05013431), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_10_REG                                   , RULL(0x05013432), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_11_REG                                   , RULL(0x05013433), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_20_REG                                   , RULL(0x05013434), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_21_REG                                   , RULL(0x05013435), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_30_REG                                   , RULL(0x05013436), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_31_REG                                   , RULL(0x05013437), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_40_REG                                   , RULL(0x05013438), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_41_REG                                   , RULL(0x05013439), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_50_REG                                   , RULL(0x0501343A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_51_REG                                   , RULL(0x0501343B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PBE_MAILBOX_CTL_REG                                  , RULL(0x0501342E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PBE_MAILBOX_DATA_REG                                 , RULL(0x0501342F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_00_REG                               , RULL(0x05013830), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_01_REG                               , RULL(0x05013831), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_10_REG                               , RULL(0x05013832), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_11_REG                               , RULL(0x05013833), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_20_REG                               , RULL(0x05013834), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_21_REG                               , RULL(0x05013835), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_30_REG                               , RULL(0x05013836), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_31_REG                               , RULL(0x05013837), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_40_REG                               , RULL(0x05013838), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_41_REG                               , RULL(0x05013839), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_50_REG                               , RULL(0x0501383A), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_51_REG                               , RULL(0x0501383B), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_60_REG                               , RULL(0x0501383C), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_61_REG                               , RULL(0x0501383D), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_70_REG                               , RULL(0x0501383E), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_71_REG                               , RULL(0x0501383F), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PBO_MAILBOX_CTL_REG                              , RULL(0x0501382E), SH_UNT_PU_IOE   , SH_ACS_SCOM      );

REG64( PU_IOE_PBO_MAILBOX_DATA_REG                             , RULL(0x0501382F), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_PB_CENT_SM0_PB_CENT_FIR_ACTION0_REG                  , RULL(0x05011C06), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_PB_CENT_SM0_PB_CENT_FIR_ACTION1_REG                  , RULL(0x05011C07), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG                     , RULL(0x05011C03), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM_RW   );
REG64( PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_AND                 , RULL(0x05011C04), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM1_AND );
REG64( PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_OR                  , RULL(0x05011C05), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM2_OR  );

REG64( PU_PB_CENT_SM0_PB_CENT_FIR_REG                          , RULL(0x05011C00), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM_RW   );
REG64( PU_PB_CENT_SM0_PB_CENT_FIR_REG_AND                      , RULL(0x05011C01), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM1_AND );
REG64( PU_PB_CENT_SM0_PB_CENT_FIR_REG_OR                       , RULL(0x05011C02), SH_UNT_PU_PB_CENT_SM0,
       SH_ACS_SCOM2_OR  );

REG64( PU_PB_EAST_FIR_ACTION0_REG                              , RULL(0x05012006), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_EAST_FIR_ACTION1_REG                              , RULL(0x05012007), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_EAST_FIR_MASK_REG                                 , RULL(0x05012003), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PB_EAST_FIR_MASK_REG_AND                             , RULL(0x05012004), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PB_EAST_FIR_MASK_REG_OR                              , RULL(0x05012005), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PB_EAST_FIR_REG                                      , RULL(0x05012000), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PB_EAST_FIR_REG_AND                                  , RULL(0x05012001), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PB_EAST_FIR_REG_OR                                   , RULL(0x05012002), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PB_ELINK_DATA_01_CFG_REG                             , RULL(0x05013410), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_ELINK_DATA_23_CFG_REG                             , RULL(0x05013411), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_ELINK_DATA_45_CFG_REG                             , RULL(0x05013412), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_ELINK_DLY_0123_REG                                , RULL(0x0501340E), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_ELINK_DLY_45_REG                                  , RULL(0x0501340F), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_ELINK_PMU0                                        , RULL(0x0501341B), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU1                                        , RULL(0x0501341C), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU2                                        , RULL(0x0501341D), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU3                                        , RULL(0x0501341E), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU4                                        , RULL(0x0501341F), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU5                                        , RULL(0x05013420), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU6                                        , RULL(0x05013421), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU7                                        , RULL(0x05013422), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_PB_ELINK_PMU_CTL_REG                                 , RULL(0x0501341A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_ELINK_RT_DELAY_CTL_REG                            , RULL(0x05013419), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PB_ELINK_SYN_01_REG                                  , RULL(0x05013414), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_ELINK_SYN_23_REG                                  , RULL(0x05013415), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_ELINK_SYN_45_REG                                  , RULL(0x05013416), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_EN_DOB_ECC_ERR_REG                                , RULL(0x05013418), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_IOE_PB_EN_DOB_ECC_ERR_REG                            , RULL(0x05013818), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_PB_FM0123_ERR                                        , RULL(0x05013425), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_IOE_PB_FM0123_ERR                                    , RULL(0x05013825), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_FM4567_ERR                                    , RULL(0x05013826), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_PB_FM45_ERR                                          , RULL(0x05013426), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_FP01_CFG                                          , RULL(0x0501340A), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_FP01_CFG                                      , RULL(0x0501380A), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_PB_FP23_CFG                                          , RULL(0x0501340B), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_FP23_CFG                                      , RULL(0x0501380B), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_PB_FP45_CFG                                          , RULL(0x0501340C), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_FP45_CFG                                      , RULL(0x0501380C), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_FP67_CFG                                      , RULL(0x0501380D), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_PB_IOE_FIR_ACTION0_REG                               , RULL(0x05013406), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_IOE_FIR_ACTION1_REG                               , RULL(0x05013407), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_IOE_FIR_MASK_REG                                  , RULL(0x05013403), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PB_IOE_FIR_MASK_REG_AND                              , RULL(0x05013404), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PB_IOE_FIR_MASK_REG_OR                               , RULL(0x05013405), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PB_IOE_FIR_REG                                       , RULL(0x05013400), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PB_IOE_FIR_REG_AND                                   , RULL(0x05013401), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PB_IOE_FIR_REG_OR                                    , RULL(0x05013402), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_IOE_PB_IOO_FIR_ACTION0_REG                           , RULL(0x05013806), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_IOO_FIR_ACTION1_REG                           , RULL(0x05013807), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_IOO_FIR_MASK_REG                              , RULL(0x05013803), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_IOO_FIR_MASK_REG_AND                          , RULL(0x05013804), SH_UNT_PU_IOE   , SH_ACS_SCOM1_AND );
REG64( PU_IOE_PB_IOO_FIR_MASK_REG_OR                           , RULL(0x05013805), SH_UNT_PU_IOE   , SH_ACS_SCOM2_OR  );

REG64( PU_IOE_PB_IOO_FIR_REG                                   , RULL(0x05013800), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_IOO_FIR_REG_AND                               , RULL(0x05013801), SH_UNT_PU_IOE   , SH_ACS_SCOM1_AND );
REG64( PU_IOE_PB_IOO_FIR_REG_OR                                , RULL(0x05013802), SH_UNT_PU_IOE   , SH_ACS_SCOM2_OR  );

REG64( PU_PB_MISC_CFG                                          , RULL(0x05013423), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_IOE_PB_MISC_CFG                                      , RULL(0x05013823), SH_UNT_PU_IOE   , SH_ACS_SCOM      );

REG64( PU_IOE_PB_OLINK_DATA_01_CFG_REG                         , RULL(0x05013810), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_OLINK_DATA_23_CFG_REG                         , RULL(0x05013811), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_OLINK_DATA_45_CFG_REG                         , RULL(0x05013812), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_OLINK_DATA_67_CFG_REG                         , RULL(0x05013813), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_OLINK_DLY_0123_REG                            , RULL(0x0501380E), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_OLINK_DLY_4567_REG                            , RULL(0x0501380F), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_OLINK_PMU0                                    , RULL(0x0501381B), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU1                                    , RULL(0x0501381C), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU2                                    , RULL(0x0501381D), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU3                                    , RULL(0x0501381E), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU4                                    , RULL(0x0501381F), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU5                                    , RULL(0x05013820), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU6                                    , RULL(0x05013821), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU7                                    , RULL(0x05013822), SH_UNT_PU_IOE   ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_IOE_PB_OLINK_PMU_CTL_REG                             , RULL(0x0501381A), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_IOE_PB_OLINK_RT_DELAY_CTL_REG                        , RULL(0x05013819), SH_UNT_PU_IOE   , SH_ACS_SCOM      );

REG64( PU_IOE_PB_OLINK_SYN_01_REG                              , RULL(0x05013814), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_OLINK_SYN_23_REG                              , RULL(0x05013815), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_OLINK_SYN_45_REG                              , RULL(0x05013816), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_OLINK_SYN_67_REG                              , RULL(0x05013817), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_PB_PERFTRACE_CFG_REG                                 , RULL(0x05013429), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_PERFTRACE_CFG_REG                             , RULL(0x05013829), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_PB_PPE_LFIR                                          , RULL(0x05012400), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PB_PPE_LFIR_AND                                      , RULL(0x05012401), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PB_PPE_LFIR_OR                                       , RULL(0x05012402), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PB_PPE_LFIRACT0                                      , RULL(0x05012406), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_PPE_LFIRACT1                                      , RULL(0x05012407), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_PPE_LFIRMASK                                      , RULL(0x05012403), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PB_PPE_LFIRMASK_AND                                  , RULL(0x05012404), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PB_PPE_LFIRMASK_OR                                   , RULL(0x05012405), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PB_PR0123_ERR                                        , RULL(0x05013427), SH_UNT          , SH_ACS_SCOM_RO   );
REG64( PU_IOE_PB_PR0123_ERR                                    , RULL(0x05013827), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_IOE_PB_PR4567_ERR                                    , RULL(0x05013828), SH_UNT_PU_IOE   , SH_ACS_SCOM_RO   );

REG64( PU_PB_PR45_ERR                                          , RULL(0x05013428), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_PSAVE_CFG                                         , RULL(0x0501241A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PB_PSAVE_MON_CFG                                     , RULL(0x0501241B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_PB_PSAVE_X0EVN_HIST                                  , RULL(0x0501241C), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_PSAVE_X0ODD_HIST                                  , RULL(0x0501241D), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_PSAVE_X1EVN_HIST                                  , RULL(0x0501241E), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_PSAVE_X1ODD_HIST                                  , RULL(0x0501241F), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_PSAVE_X2EVN_HIST                                  , RULL(0x05012420), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_PSAVE_X2ODD_HIST                                  , RULL(0x05012421), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PB_TRACE_CFG                                         , RULL(0x05013424), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_IOE_PB_TRACE_CFG                                     , RULL(0x05013824), SH_UNT_PU_IOE   , SH_ACS_SCOM_RW   );

REG64( PU_PB_WEST_SM0_PB_WEST_FIR_ACTION0_REG                  , RULL(0x05011806), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_PB_WEST_SM0_PB_WEST_FIR_ACTION1_REG                  , RULL(0x05011807), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM_RW   );

REG64( PU_PB_WEST_SM0_PB_WEST_FIR_MASK_REG                     , RULL(0x05011803), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM_RW   );
REG64( PU_PB_WEST_SM0_PB_WEST_FIR_MASK_REG_AND                 , RULL(0x05011804), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM1_AND );
REG64( PU_PB_WEST_SM0_PB_WEST_FIR_MASK_REG_OR                  , RULL(0x05011805), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM2_OR  );

REG64( PU_PB_WEST_SM0_PB_WEST_FIR_REG                          , RULL(0x05011800), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM_RW   );
REG64( PU_PB_WEST_SM0_PB_WEST_FIR_REG_AND                      , RULL(0x05011801), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM1_AND );
REG64( PU_PB_WEST_SM0_PB_WEST_FIR_REG_OR                       , RULL(0x05011802), SH_UNT_PU_PB_WEST_SM0,
       SH_ACS_SCOM2_OR  );

REG64( PEC_PCS_M1_CONTROL_REG                                  , RULL(0x80000C010D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_M1_CONTROL_REG                                , RULL(0x80000C010D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_M1_CONTROL_REG                                , RULL(0x80000C010E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_M1_CONTROL_REG                                , RULL(0x80000C010F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_M2_CONTROL_REG                                  , RULL(0x80000C020D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_M2_CONTROL_REG                                , RULL(0x80000C020D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_M2_CONTROL_REG                                , RULL(0x80000C020E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_M2_CONTROL_REG                                , RULL(0x80000C020F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_M3_CONTROL_REG                                  , RULL(0x80000C030D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_M3_CONTROL_REG                                , RULL(0x80000C030D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_M3_CONTROL_REG                                , RULL(0x80000C030E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_M3_CONTROL_REG                                , RULL(0x80000C030F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_M4_CONTROL_REG                                  , RULL(0x80000C040D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_M4_CONTROL_REG                                , RULL(0x80000C040D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_M4_CONTROL_REG                                , RULL(0x80000C040E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_M4_CONTROL_REG                                , RULL(0x80000C040F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PCS_SYS_CONTROL_REG                                 , RULL(0x80000C000D010C3F), SH_UNT_PEC      ,
       SH_ACS_SCOM      );
REG64( PEC_0_PCS_SYS_CONTROL_REG                               , RULL(0x80000C000D010C3F), SH_UNT_PEC_0    ,
       SH_ACS_SCOM      );
REG64( PEC_1_PCS_SYS_CONTROL_REG                               , RULL(0x80000C000E010C3F), SH_UNT_PEC_1    ,
       SH_ACS_SCOM      );
REG64( PEC_2_PCS_SYS_CONTROL_REG                               , RULL(0x80000C000F010C3F), SH_UNT_PEC_2    ,
       SH_ACS_SCOM      );

REG64( PEC_PECAPP_CNTL_REG                                     , RULL(0x04010C07), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_PECAPP_CNTL_REG                                   , RULL(0x04010C07), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_PECAPP_CNTL_REG                                   , RULL(0x04011007), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_PECAPP_CNTL_REG                                   , RULL(0x04011407), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_PECAPP_SEC_BAR                                      , RULL(0x0D010801), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PECAPP_SEC_BAR                                    , RULL(0x0D010801), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PECAPP_SEC_BAR                                    , RULL(0x0E010801), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PECAPP_SEC_BAR                                    , RULL(0x0F010801), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( NV_PERF_CONFIG                                          , RULL(0x050110CE), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_PERF_CONFIG                                        , RULL(0x050110CE), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_PERF_CONFIG                                        , RULL(0x050110EE), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_PERF_CONFIG                                        , RULL(0x050111CE), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_PERF_CONFIG                                        , RULL(0x050111EE), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_PERF_CONFIG                                 , RULL(0x05011087), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_PERF_CONFIG                                 , RULL(0x05011187), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_PERF_CONFIG                                 , RULL(0x05011287), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM0_PERF_CONFIG                                 , RULL(0x0501100F), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_PERF_CONFIG                                 , RULL(0x0501102F), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_PERF_CONFIG                                 , RULL(0x0501104F), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_PERF_CONFIG                                 , RULL(0x0501106F), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_PERF_CONFIG                                 , RULL(0x0501110F), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_PERF_CONFIG                                 , RULL(0x0501112F), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_PERF_CONFIG                                 , RULL(0x0501114F), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_PERF_CONFIG                                 , RULL(0x0501116F), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_PERF_CONFIG                                , RULL(0x050112CE), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_PERF_CONFIG                                , RULL(0x050112EE), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_PERF_CONFIG                                 , RULL(0x0501120F), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_PERF_CONFIG                                 , RULL(0x0501122F), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_PERF_CONFIG                                 , RULL(0x0501124F), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_PERF_CONFIG                                 , RULL(0x0501126F), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( NV_PERF_COUNT                                           , RULL(0x050110CF), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_PERF_COUNT                                         , RULL(0x050110CF), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_PERF_COUNT                                         , RULL(0x050110EF), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_PERF_COUNT                                         , RULL(0x050111CF), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_PERF_COUNT                                         , RULL(0x050111EF), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_CTL_PERF_COUNT                                  , RULL(0x05011086), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_PERF_COUNT                                  , RULL(0x05011186), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_PERF_COUNT                                  , RULL(0x05011286), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_PERF_COUNT                                 , RULL(0x050112CF), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_PERF_COUNT                                 , RULL(0x050112EF), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_PERF_MASK_CONFIG                            , RULL(0x05011085), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_PERF_MASK_CONFIG                            , RULL(0x05011185), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_PERF_MASK_CONFIG                            , RULL(0x05011285), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU0_CTL_PERF_MATCH_CONFIG                           , RULL(0x05011084), SH_UNT_PU_NPU0_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU1_CTL_PERF_MATCH_CONFIG                           , RULL(0x05011184), SH_UNT_PU_NPU1_CTL,
       SH_ACS_SCOM      );
REG64( PU_NPU2_CTL_PERF_MATCH_CONFIG                           , RULL(0x05011284), SH_UNT_PU_NPU2_CTL,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE0                              , RULL(0x050113D0), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE1                              , RULL(0x050113D1), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE10                             , RULL(0x050113DA), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE11                             , RULL(0x050113DB), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE12                             , RULL(0x050113DC), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE13                             , RULL(0x050113DD), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE14                             , RULL(0x050113DE), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE15                             , RULL(0x050113DF), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE2                              , RULL(0x050113D2), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE3                              , RULL(0x050113D3), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE4                              , RULL(0x050113D4), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE5                              , RULL(0x050113D5), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE6                              , RULL(0x050113D6), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE7                              , RULL(0x050113D7), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE8                              , RULL(0x050113D8), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_ADDR_PE9                              , RULL(0x050113D9), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE0                              , RULL(0x050113C0), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE1                              , RULL(0x050113C1), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE10                             , RULL(0x050113CA), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE11                             , RULL(0x050113CB), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE12                             , RULL(0x050113CC), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE13                             , RULL(0x050113CD), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE14                             , RULL(0x050113CE), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE15                             , RULL(0x050113CF), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE2                              , RULL(0x050113C2), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE3                              , RULL(0x050113C3), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE4                              , RULL(0x050113C4), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE5                              , RULL(0x050113C5), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE6                              , RULL(0x050113C6), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE7                              , RULL(0x050113C7), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE8                              , RULL(0x050113C8), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PU_NPU_NTL0_PESTB_DATA_PE9                              , RULL(0x050113C9), SH_UNT_PU_NPU_NTL0,
       SH_ACS_SCOM      );

REG64( PEC_0_STACK0_PE_DFREEZE_REG                             , RULL(0x04010C55), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK1_PE_DFREEZE_REG                             , RULL(0x04010C95), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_0_STACK2_PE_DFREEZE_REG                             , RULL(0x04010CD5), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK0_PE_DFREEZE_REG                             , RULL(0x04011055), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK1_PE_DFREEZE_REG                             , RULL(0x04011095), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_1_STACK2_PE_DFREEZE_REG                             , RULL(0x040110D5), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK0_PE_DFREEZE_REG                             , RULL(0x04011455), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK1_PE_DFREEZE_REG                             , RULL(0x04011495), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_2_STACK2_PE_DFREEZE_REG                             , RULL(0x040114D5), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK0_PE_DFREEZE_REG                               , RULL(0x04010C55), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK1_PE_DFREEZE_REG                               , RULL(0x04010C95), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PEC_STACK2_PE_DFREEZE_REG                               , RULL(0x04010CD5), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PHB_PE_DFREEZE_REG                                      , RULL(0x04010C55), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_PE_DFREEZE_REG                                    , RULL(0x04010C55), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_PE_DFREEZE_REG                                    , RULL(0x04011055), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_PE_DFREEZE_REG                                    , RULL(0x04011095), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_PE_DFREEZE_REG                                    , RULL(0x04011455), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_PE_DFREEZE_REG                                    , RULL(0x04011495), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_PE_DFREEZE_REG                                    , RULL(0x040114D5), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );

REG64( PEC_0_STACK0_PHBBAR_REG                                 , RULL(0x04010C52), SH_UNT_PEC_0_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK1_PHBBAR_REG                                 , RULL(0x04010C92), SH_UNT_PEC_0_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_0_STACK2_PHBBAR_REG                                 , RULL(0x04010CD2), SH_UNT_PEC_0_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK0_PHBBAR_REG                                 , RULL(0x04011052), SH_UNT_PEC_1_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK1_PHBBAR_REG                                 , RULL(0x04011092), SH_UNT_PEC_1_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_1_STACK2_PHBBAR_REG                                 , RULL(0x040110D2), SH_UNT_PEC_1_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK0_PHBBAR_REG                                 , RULL(0x04011452), SH_UNT_PEC_2_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK1_PHBBAR_REG                                 , RULL(0x04011492), SH_UNT_PEC_2_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_2_STACK2_PHBBAR_REG                                 , RULL(0x040114D2), SH_UNT_PEC_2_STACK2,
       SH_ACS_SCOM      );
REG64( PEC_STACK0_PHBBAR_REG                                   , RULL(0x04010C52), SH_UNT_PEC_STACK0,
       SH_ACS_SCOM      );
REG64( PEC_STACK1_PHBBAR_REG                                   , RULL(0x04010C92), SH_UNT_PEC_STACK1,
       SH_ACS_SCOM      );
REG64( PEC_STACK2_PHBBAR_REG                                   , RULL(0x04010CD2), SH_UNT_PEC_STACK2,
       SH_ACS_SCOM      );
REG64( PHB_PHBBAR_REG                                          , RULL(0x04010C52), SH_UNT_PHB      , SH_ACS_SCOM      );
REG64( PHB_0_PHBBAR_REG                                        , RULL(0x04010C52), SH_UNT_PHB_0    , SH_ACS_SCOM      );
REG64( PHB_1_PHBBAR_REG                                        , RULL(0x04011052), SH_UNT_PHB_1    , SH_ACS_SCOM      );
REG64( PHB_2_PHBBAR_REG                                        , RULL(0x04011092), SH_UNT_PHB_2    , SH_ACS_SCOM      );
REG64( PHB_3_PHBBAR_REG                                        , RULL(0x04011452), SH_UNT_PHB_3    , SH_ACS_SCOM      );
REG64( PHB_4_PHBBAR_REG                                        , RULL(0x04011492), SH_UNT_PHB_4    , SH_ACS_SCOM      );
REG64( PHB_5_PHBBAR_REG                                        , RULL(0x040114D2), SH_UNT_PHB_5    , SH_ACS_SCOM      );

REG64( PHB_PHBRESET_REG                                        , RULL(0x0D010840), SH_UNT_PHB      , SH_ACS_SCOM_RW   );
REG64( PHB_0_PHBRESET_REG                                      , RULL(0x0D010840), SH_UNT_PHB_0    , SH_ACS_SCOM_RW   );
REG64( PHB_1_PHBRESET_REG                                      , RULL(0x0E010840), SH_UNT_PHB_1    , SH_ACS_SCOM_RW   );
REG64( PHB_2_PHBRESET_REG                                      , RULL(0x0E010880), SH_UNT_PHB_2    , SH_ACS_SCOM_RW   );
REG64( PHB_3_PHBRESET_REG                                      , RULL(0x0F010840), SH_UNT_PHB_3    , SH_ACS_SCOM_RW   );
REG64( PHB_4_PHBRESET_REG                                      , RULL(0x0F010880), SH_UNT_PHB_4    , SH_ACS_SCOM_RW   );
REG64( PHB_5_PHBRESET_REG                                      , RULL(0x0F0108C0), SH_UNT_PHB_5    , SH_ACS_SCOM_RW   );
REG64( PU_PBAIB_STACK1_PHBRESET_REG                            , RULL(0x0D010880), SH_UNT_PU_PBAIB_STACK1,
       SH_ACS_SCOM_RW   );
REG64( PU_PBAIB_STACK2_PHBRESET_REG                            , RULL(0x0D0108C0), SH_UNT_PU_PBAIB_STACK2,
       SH_ACS_SCOM_RW   );
REG64( PU_PBAIB_STACK5_PHBRESET_REG                            , RULL(0x0E0108C0), SH_UNT_PU_PBAIB_STACK5,
       SH_ACS_SCOM_RW   );

REG64( PU_PIBI2CM_ATOMIC_LOCK_REG_B                            , RULL(0x000A03FF), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_ATOMIC_LOCK_REG_C                            , RULL(0x000A13FF), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_ATOMIC_LOCK_REG_D                            , RULL(0x000A23FF), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_ATOMIC_LOCK_REG_E                            , RULL(0x000A33FF), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_PROTECT_MODE_REG_B                           , RULL(0x000A03FE), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_PROTECT_MODE_REG_C                           , RULL(0x000A13FE), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_PROTECT_MODE_REG_D                           , RULL(0x000A23FE), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBI2CM_PROTECT_MODE_REG_E                           , RULL(0x000A33FE), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_ADDRESS_REGISTER                              , RULL(0x00088001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_ADDRESS_REGISTER_FA                           , RULL(0x00088007), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_CONTROL_REGISTER                              , RULL(0x00088000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_REPAIR_REGISTER_0                             , RULL(0x0008800B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_REPAIR_REGISTER_1                             , RULL(0x0008800C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_REPAIR_REGISTER_2                             , RULL(0x0008800D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_REPAIR_REGISTER_3                             , RULL(0x0008800E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_RESET_REGISTER                                , RULL(0x00088006), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PIBMEM_STATUS_REG                                    , RULL(0x00088005), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_PLL_LOCK_REG                                        , RULL(0x0D0F0019), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PLL_LOCK_REG                                      , RULL(0x0D0F0019), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PLL_LOCK_REG                                      , RULL(0x0E0F0019), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PLL_LOCK_REG                                      , RULL(0x0F0F0019), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_PMONCTL_REG                                         , RULL(0x04010C04), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_PMONCTL_REG                                       , RULL(0x04010C04), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_PMONCTL_REG                                       , RULL(0x04011004), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_PMONCTL_REG                                       , RULL(0x04011404), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( CAPP_PMU_CNTRA_CFG                                      , RULL(0x02010814), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PMU_CNTRA_CFG                                    , RULL(0x02010814), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PMU_CNTRA_CFG                                    , RULL(0x04010814), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_PMU_CNTRA_REG                                      , RULL(0x02010815), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PMU_CNTRA_REG                                    , RULL(0x02010815), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PMU_CNTRA_REG                                    , RULL(0x04010815), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_PMU_CNTRB_CFG                                      , RULL(0x02010824), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PMU_CNTRB_CFG                                    , RULL(0x02010824), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PMU_CNTRB_CFG                                    , RULL(0x04010824), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_PMU_CNTRB_REG                                      , RULL(0x02010825), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PMU_CNTRB_REG                                    , RULL(0x02010825), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PMU_CNTRB_REG                                    , RULL(0x04010825), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_PPE_XIDBGPRO                                         , RULL(0x000E0005), SH_UNT          ,
       SH_ACS_SCOM      ); //DUPS: 05012415, 0601084F,

REG64( PU_PPE_XIRAMDBG                                         , RULL(0x000E0003), SH_UNT          ,
       SH_ACS_SCOM      ); //DUPS: 05012413, 0601084D,

REG64( PU_PPE_XIRAMEDR                                         , RULL(0x000E0004), SH_UNT          ,
       SH_ACS_SCOM      ); //DUPS: 05012414, 0601084E,

REG64( PU_PPE_XIRAMGA                                          , RULL(0x000E0002), SH_UNT          ,
       SH_ACS_SCOM_WO   ); //DUPS: 05012412, 0601084C,

REG64( PU_PPE_XIRAMRA                                          , RULL(0x000E0001), SH_UNT          ,
       SH_ACS_SCOM_WO   ); //DUPS: 05012411, 0601084B,

REG64( PU_PPE_XIXCR                                            , RULL(0x000E0000), SH_UNT          ,
       SH_ACS_SCOM_WO   ); //DUPS: 05012410, 0601084A,

REG64( NV_PRB_HA_PTR                                           , RULL(0x050110D1), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_PRB_HA_PTR                                         , RULL(0x050110D1), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_PRB_HA_PTR                                         , RULL(0x050110F1), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_PRB_HA_PTR                                         , RULL(0x050111D1), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_PRB_HA_PTR                                         , RULL(0x050111F1), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_PRB_HA_PTR                                 , RULL(0x050112D1), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_PRB_HA_PTR                                 , RULL(0x050112F1), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PEC_PREDV_REG                                           , RULL(0x04010C06), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_PREDV_REG                                         , RULL(0x04010C06), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_PREDV_REG                                         , RULL(0x04011006), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_PREDV_REG                                         , RULL(0x04011406), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PEC_PRE_COUNTER_REG                                     , RULL(0x0D0F0028), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PRE_COUNTER_REG                                   , RULL(0x0D0F0028), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PRE_COUNTER_REG                                   , RULL(0x0E0F0028), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PRE_COUNTER_REG                                   , RULL(0x0F0F0028), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_PRGM_REGISTER                                        , RULL(0x00010009), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_PRIMARY_ADDRESS_REG                                 , RULL(0x0D0F0000), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PRIMARY_ADDRESS_REG                               , RULL(0x0D0F0000), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PRIMARY_ADDRESS_REG                               , RULL(0x0E0F0000), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PRIMARY_ADDRESS_REG                               , RULL(0x0F0F0000), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_PROBE_PROTECT_STATUS                                 , RULL(0x0001000A), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_PROTECT_MODE_REG                                    , RULL(0x0D0F03FE), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PROTECT_MODE_REG                                  , RULL(0x0D0F03FE), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PROTECT_MODE_REG                                  , RULL(0x0E0F03FE), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PROTECT_MODE_REG                                  , RULL(0x0F0F03FE), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_PRV_MISC_PPE                                         , RULL(0xC0002000), SH_UNT          , SH_ACS_PPE       );
REG64( PU_PRV_MISC_PPE1                                        , RULL(0xC0002010), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_PRV_MISC_PPE2                                        , RULL(0xC0002018), SH_UNT          , SH_ACS_PPE2      );

REG64( PEC_PSCOM_ERROR_MASK                                    , RULL(0x0D010002), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PSCOM_ERROR_MASK                                  , RULL(0x0D010002), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PSCOM_ERROR_MASK                                  , RULL(0x0E010002), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PSCOM_ERROR_MASK                                  , RULL(0x0F010002), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_PSCOM_ERROR_MASK                                  , RULL(0x02010002), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_PSCOM_ERROR_MASK                                  , RULL(0x03010002), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_PSCOM_ERROR_MASK                                  , RULL(0x04010002), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_PSCOM_ERROR_MASK                                  , RULL(0x05010002), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_PSCOM_MODE_REG                                      , RULL(0x0D010000), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PSCOM_MODE_REG                                    , RULL(0x0D010000), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PSCOM_MODE_REG                                    , RULL(0x0E010000), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PSCOM_MODE_REG                                    , RULL(0x0F010000), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_PSCOM_MODE_REG                                    , RULL(0x02010000), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_PSCOM_MODE_REG                                    , RULL(0x03010000), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_PSCOM_MODE_REG                                    , RULL(0x04010000), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_PSCOM_MODE_REG                                    , RULL(0x05010000), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_PSCOM_STATUS_ERROR_REG                              , RULL(0x0D010001), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_PSCOM_STATUS_ERROR_REG                            , RULL(0x0D010001), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_PSCOM_STATUS_ERROR_REG                            , RULL(0x0E010001), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_PSCOM_STATUS_ERROR_REG                            , RULL(0x0F010001), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_PSCOM_STATUS_ERROR_REG                            , RULL(0x02010001), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_PSCOM_STATUS_ERROR_REG                            , RULL(0x03010001), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_PSCOM_STATUS_ERROR_REG                            , RULL(0x04010001), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_PSCOM_STATUS_ERROR_REG                            , RULL(0x05010001), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PU_PSIHB_DEBUG_REG                                      , RULL(0x05012911), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSIHB_ERROR_MASK_REG                                 , RULL(0x0501290F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSIHB_FIR_ACTION0_REG                                , RULL(0x05012906), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PSIHB_FIR_ACTION1_REG                                , RULL(0x05012907), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_PSIHB_FIR_MASK_REG                                   , RULL(0x05012903), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PSIHB_FIR_MASK_REG_AND                               , RULL(0x05012904), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PSIHB_FIR_MASK_REG_OR                                , RULL(0x05012905), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PSIHB_FIR_REG                                        , RULL(0x05012900), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PSIHB_FIR_REG_AND                                    , RULL(0x05012901), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PSIHB_FIR_REG_OR                                     , RULL(0x05012902), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PSIHB_INTERRUPT_CONTROL                              , RULL(0x05012915), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSIHB_INTERRUPT_LEVEL                                , RULL(0x05012919), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSIHB_INTERRUPT_STATUS                               , RULL(0x0501291A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSIHB_STATUS_CTL_REG_SCOM                            , RULL(0x0501290E), SH_UNT          , SH_ACS_SCOM      );
REG64( PU_PSIHB_STATUS_CTL_REG_SCOM1                           , RULL(0x05012912), SH_UNT          , SH_ACS_SCOM1     );
REG64( PU_PSIHB_STATUS_CTL_REG_SCOM2                           , RULL(0x05012913), SH_UNT          , SH_ACS_SCOM2     );

REG64( PU_PSI_BRIDGE_BAR_REG                                   , RULL(0x0501290A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSI_BRIDGE_FSP_BAR_REG                               , RULL(0x0501290B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSI_FSP_MMR_REG                                      , RULL(0x0501290C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSI_TCE_ADDR_REG                                     , RULL(0x05012B44), SH_UNT          , SH_ACS_SCOM      );

REG64( CAPP_PSLTTMAP0                                          , RULL(0x0201082D), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PSLTTMAP0                                        , RULL(0x0201082D), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PSLTTMAP0                                        , RULL(0x0401082D), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_PSLTTMAP1                                          , RULL(0x0201082E), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PSLTTMAP1                                        , RULL(0x0201082E), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PSLTTMAP1                                        , RULL(0x0401082E), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_PSLTTMAP2                                          , RULL(0x0201082F), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PSLTTMAP2                                        , RULL(0x0201082F), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PSLTTMAP2                                        , RULL(0x0401082F), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_PSLTTMAP3                                          , RULL(0x02010830), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_PSLTTMAP3                                        , RULL(0x02010830), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_PSLTTMAP3                                        , RULL(0x04010830), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_DOORBELL_REG                                , RULL(0x000D0063), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PSU_HOST_DOORBELL_REG_AND                            , RULL(0x000D0064), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PSU_HOST_DOORBELL_REG_OR                             , RULL(0x000D0065), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_PSU_HOST_SBE_MBOX0_REG                               , RULL(0x000D0050), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX1_REG                               , RULL(0x000D0051), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX2_REG                               , RULL(0x000D0052), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX3_REG                               , RULL(0x000D0053), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX4_REG                               , RULL(0x000D0054), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX5_REG                               , RULL(0x000D0055), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX6_REG                               , RULL(0x000D0056), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_HOST_SBE_MBOX7_REG                               , RULL(0x000D0057), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_ACTCYCLECNT_REG                           , RULL(0x000D0023), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_CYCLECNT_REG                              , RULL(0x000D0022), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_EVENTCNT_REG                              , RULL(0x000D0024), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_FILTER_REG                                , RULL(0x000D0021), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_MAXCYCLECNT_REG                           , RULL(0x000D0025), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_MINCYCLECNT_REG                           , RULL(0x000D0026), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR0_STOP_TIMER_REG                            , RULL(0x000D0020), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_ACTCYCLECNT_REG                           , RULL(0x000D0033), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_CYCLECNT_REG                              , RULL(0x000D0032), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_EVENTCNT_REG                              , RULL(0x000D0034), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_FILTER_REG                                , RULL(0x000D0031), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_MAXCYCLECNT_REG                           , RULL(0x000D0035), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_MINCYCLECNT_REG                           , RULL(0x000D0036), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR1_STOP_TIMER_REG                            , RULL(0x000D0030), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_ACTCYCLECNT_REG                           , RULL(0x000D0043), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_CYCLECNT_REG                              , RULL(0x000D0042), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_EVENTCNT_REG                              , RULL(0x000D0044), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_FILTER_REG                                , RULL(0x000D0041), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_MAXCYCLECNT_REG                           , RULL(0x000D0045), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_MINCYCLECNT_REG                           , RULL(0x000D0046), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR2_STOP_TIMER_REG                            , RULL(0x000D0040), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_INSTR_CTRL_STATUS_REG                            , RULL(0x000D0010), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_2NDLAST_ADDR_TRACE_REG                   , RULL(0x000D0005), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_2NDLAST_REQDATA_TRACE_REG                , RULL(0x000D0006), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_2NDLAST_RSPDATA_TRACE_REG                , RULL(0x000D0007), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_CTRL_STATUS_REG                          , RULL(0x000D0000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_FILTER_REG                               , RULL(0x000D0001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_LAST_ADDR_TRACE_REG                      , RULL(0x000D0002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_LAST_REQDATA_TRACE_REG                   , RULL(0x000D0003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_PIBHIST_LAST_RSPDATA_TRACE_REG                   , RULL(0x000D0004), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_PSU_SBE_DOORBELL_REG                                 , RULL(0x000D0060), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_PSU_SBE_DOORBELL_REG_AND                             , RULL(0x000D0061), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_PSU_SBE_DOORBELL_REG_OR                              , RULL(0x000D0062), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PEC_RECOV_INTERRUPT_REG                                 , RULL(0x0D0F001B), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_RECOV_INTERRUPT_REG                               , RULL(0x0D0F001B), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_RECOV_INTERRUPT_REG                               , RULL(0x0E0F001B), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_RECOV_INTERRUPT_REG                               , RULL(0x0F0F001B), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU0_REM0                                            , RULL(0x050110AD), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_REM0                                            , RULL(0x050111AD), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_REM0                                            , RULL(0x050112AD), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_NPU0_REM1                                            , RULL(0x050110AE), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_REM1                                            , RULL(0x050111AE), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_REM1                                            , RULL(0x050112AE), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_RESET_REGISTER_B                                     , RULL(0x000A0001), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESET_REGISTER_C                                     , RULL(0x000A1001), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESET_REGISTER_D                                     , RULL(0x000A2001), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESET_REGISTER_E                                     , RULL(0x000A3001), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_B                 , RULL(0x000A000D), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_C                 , RULL(0x000A100D), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_D                 , RULL(0x000A200D), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_E                 , RULL(0x000A300D), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PEC_RFIR                                                , RULL(0x0D040001), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_RFIR                                              , RULL(0x0D040001), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_RFIR                                              , RULL(0x0E040001), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_RFIR                                              , RULL(0x0F040001), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_RING_FENCE_MASK_LATCH_REG                           , RULL(0x0D010008), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_RING_FENCE_MASK_LATCH_REG                         , RULL(0x0D010008), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_RING_FENCE_MASK_LATCH_REG                         , RULL(0x0E010008), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_RING_FENCE_MASK_LATCH_REG                         , RULL(0x0F010008), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_RING_FENCE_MASK_LATCH_REG                         , RULL(0x02010008), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_RING_FENCE_MASK_LATCH_REG                         , RULL(0x03010008), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_RING_FENCE_MASK_LATCH_REG                         , RULL(0x04010008), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_RING_FENCE_MASK_LATCH_REG                         , RULL(0x05010008), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PU_NPU_CTL_RLX_CONFIG                                   , RULL(0x05011381), SH_UNT_PU_NPU_CTL,
       SH_ACS_SCOM      );

REG64( PU_RNG_FAILED_INT                                       , RULL(0x020110E7), SH_UNT          , SH_ACS_SCOM      );

REG64( NV_RSP_DA_PTR                                           , RULL(0x050110D5), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_RSP_DA_PTR                                         , RULL(0x050110D5), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_RSP_DA_PTR                                         , RULL(0x050110F5), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_RSP_DA_PTR                                         , RULL(0x050111D5), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_RSP_DA_PTR                                         , RULL(0x050111F5), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_RSP_DA_PTR                                 , RULL(0x050112D5), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_RSP_DA_PTR                                 , RULL(0x050112F5), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( NV_RSP_HA_PTR                                           , RULL(0x050110D3), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_RSP_HA_PTR                                         , RULL(0x050110D3), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_RSP_HA_PTR                                         , RULL(0x050110F3), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_RSP_HA_PTR                                         , RULL(0x050111D3), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_RSP_HA_PTR                                         , RULL(0x050111F3), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_RSP_HA_PTR                                 , RULL(0x050112D3), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_RSP_HA_PTR                                 , RULL(0x050112F3), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_RX_CH_FSM_REG                                        , RULL(0x0501280D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_CH_INTADDR_REG                                    , RULL(0x05012818), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_CH_MISC_REG                                       , RULL(0x0501281B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_CTRL_STAT_REG                                     , RULL(0x05012808), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_DBFF_REG0                                         , RULL(0x05012819), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_DBFF_REG1                                         , RULL(0x0501281A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_DF_FSM_REG                                        , RULL(0x0501280E), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_ERROR_REG_WCLEAR                                  , RULL(0x0501280A), SH_UNT          ,
       SH_ACS_SCOM_WCLEAR );
REG64( PU_RX_ERROR_REG_OR                                      , RULL(0x0501280C), SH_UNT          , SH_ACS_SCOM1_OR  );

REG64( PU_RX_ERR_MODE                                          , RULL(0x0501280F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_MASK_REG                                          , RULL(0x0501280B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_PSI_CNTL                                          , RULL(0x04011820), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_PSI_MODE                                          , RULL(0x04011821), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_RX_PSI_STATUS                                        , RULL(0x04011822), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_SCAN_REGION_TYPE                                    , RULL(0x0D030005), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SCAN_REGION_TYPE                                  , RULL(0x0D030005), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SCAN_REGION_TYPE                                  , RULL(0x0E030005), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SCAN_REGION_TYPE                                  , RULL(0x0F030005), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_SCOM_PPE_CNTL                                        , RULL(0x06010860), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SCOM_PPE_FLAGS                                       , RULL(0x06010863), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_SCOM_PPE_FLAGS_OR                                    , RULL(0x06010864), SH_UNT          , SH_ACS_SCOM1_OR  );
REG64( PU_SCOM_PPE_FLAGS_CLEAR                                 , RULL(0x06010865), SH_UNT          ,
       SH_ACS_SCOM2_CLEAR );

REG64( PU_SCOM_PPE_WORK_REG1                                   , RULL(0x06010861), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SCOM_PPE_WORK_REG2                                   , RULL(0x06010862), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SCRATCH0_PPE                                         , RULL(0xC0001000), SH_UNT          , SH_ACS_PPE       );
REG64( PU_SCRATCH0_PPE1                                        , RULL(0xC0001010), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_SCRATCH0_PPE2                                        , RULL(0xC0001018), SH_UNT          , SH_ACS_PPE2      );
REG64( PU_NPU0_SCRATCH0                                        , RULL(0x050110A3), SH_UNT_PU_NPU0  , SH_ACS_SCOM      );
REG64( PU_NPU1_SCRATCH0                                        , RULL(0x050111A3), SH_UNT_PU_NPU1  , SH_ACS_SCOM      );
REG64( PU_NPU2_SCRATCH0                                        , RULL(0x050112A3), SH_UNT_PU_NPU2  , SH_ACS_SCOM      );

REG64( PU_SCRATCH1_PPE                                         , RULL(0xC0001020), SH_UNT          , SH_ACS_PPE       );
REG64( PU_SCRATCH1_PPE1                                        , RULL(0xC0001030), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_SCRATCH1_PPE2                                        , RULL(0xC0001038), SH_UNT          , SH_ACS_PPE2      );
REG64( NV_SCRATCH1                                             , RULL(0x050110DA), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_SCRATCH1                                           , RULL(0x050110DA), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_SCRATCH1                                           , RULL(0x050110FA), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_SCRATCH1                                           , RULL(0x050111DA), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_SCRATCH1                                           , RULL(0x050111FA), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU0_DAT_SCRATCH1                                    , RULL(0x050110BC), SH_UNT_PU_NPU0_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU1_DAT_SCRATCH1                                    , RULL(0x050111BC), SH_UNT_PU_NPU1_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU2_DAT_SCRATCH1                                    , RULL(0x050112BC), SH_UNT_PU_NPU2_DAT,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_SCRATCH1                                   , RULL(0x050112DA), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_SCRATCH1                                   , RULL(0x050112FA), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_SCRATCH2_PPE                                         , RULL(0xC0001040), SH_UNT          , SH_ACS_PPE       );
REG64( PU_SCRATCH2_PPE1                                        , RULL(0xC0001050), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_SCRATCH2_PPE2                                        , RULL(0xC0001058), SH_UNT          , SH_ACS_PPE2      );
REG64( NV_SCRATCH2                                             , RULL(0x050110CA), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_SCRATCH2                                           , RULL(0x050110CA), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_SCRATCH2                                           , RULL(0x050110EA), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_SCRATCH2                                           , RULL(0x050111CA), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_SCRATCH2                                           , RULL(0x050111EA), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_SCRATCH2                                   , RULL(0x050112CA), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_SCRATCH2                                   , RULL(0x050112EA), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_SCRATCH3_PPE                                         , RULL(0xC0001060), SH_UNT          , SH_ACS_PPE       );
REG64( PU_SCRATCH3_PPE1                                        , RULL(0xC0001070), SH_UNT          , SH_ACS_PPE1      );
REG64( PU_SCRATCH3_PPE2                                        , RULL(0xC0001078), SH_UNT          , SH_ACS_PPE2      );
REG64( NV_SCRATCH3                                             , RULL(0x050110CB), SH_UNT_NV       , SH_ACS_SCOM      );
REG64( NV_0_SCRATCH3                                           , RULL(0x050110CB), SH_UNT_NV_0     , SH_ACS_SCOM      );
REG64( NV_1_SCRATCH3                                           , RULL(0x050110EB), SH_UNT_NV_1     , SH_ACS_SCOM      );
REG64( NV_2_SCRATCH3                                           , RULL(0x050111CB), SH_UNT_NV_2     , SH_ACS_SCOM      );
REG64( NV_3_SCRATCH3                                           , RULL(0x050111EB), SH_UNT_NV_3     , SH_ACS_SCOM      );
REG64( PU_NPU2_NTL0_SCRATCH3                                   , RULL(0x050112CB), SH_UNT_PU_NPU2_NTL0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_NTL1_SCRATCH3                                   , RULL(0x050112EB), SH_UNT_PU_NPU2_NTL1,
       SH_ACS_SCOM      );

REG64( PU_SECURITY_SWITCH_REGISTER_SCOM                        , RULL(0x00010005), SH_UNT          , SH_ACS_SCOM_WOR  );
REG64( PU_SECURITY_SWITCH_REGISTER_SCOM1                       , RULL(0x00010006), SH_UNT          , SH_ACS_SCOM1     );

REG64( PU_SEND_WC_BASE_ADDR                                    , RULL(0x020110D2), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_SKITTER_CLKSRC_REG                                  , RULL(0x0D050016), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SKITTER_CLKSRC_REG                                , RULL(0x0D050016), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SKITTER_CLKSRC_REG                                , RULL(0x0E050016), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SKITTER_CLKSRC_REG                                , RULL(0x0F050016), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_SKITTER_DATA0                                       , RULL(0x0D050019), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_SKITTER_DATA0                                     , RULL(0x0D050019), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_SKITTER_DATA0                                     , RULL(0x0E050019), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_SKITTER_DATA0                                     , RULL(0x0F050019), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_SKITTER_DATA1                                       , RULL(0x0D05001A), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_SKITTER_DATA1                                     , RULL(0x0D05001A), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_SKITTER_DATA1                                     , RULL(0x0E05001A), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_SKITTER_DATA1                                     , RULL(0x0F05001A), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_SKITTER_DATA2                                       , RULL(0x0D05001B), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_SKITTER_DATA2                                     , RULL(0x0D05001B), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_SKITTER_DATA2                                     , RULL(0x0E05001B), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_SKITTER_DATA2                                     , RULL(0x0F05001B), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_SKITTER_FORCE_REG                                   , RULL(0x0D050014), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SKITTER_FORCE_REG                                 , RULL(0x0D050014), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SKITTER_FORCE_REG                                 , RULL(0x0E050014), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SKITTER_FORCE_REG                                 , RULL(0x0F050014), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_SKITTER_MODE_REG                                    , RULL(0x0D050010), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SKITTER_MODE_REG                                  , RULL(0x0D050010), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SKITTER_MODE_REG                                  , RULL(0x0E050010), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SKITTER_MODE_REG                                  , RULL(0x0F050010), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_SLAVE_CONFIG_REG                                    , RULL(0x0D0F001E), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SLAVE_CONFIG_REG                                  , RULL(0x0D0F001E), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SLAVE_CONFIG_REG                                  , RULL(0x0E0F001E), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SLAVE_CONFIG_REG                                  , RULL(0x0F0F001E), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_SM_STATUS                                   , RULL(0x05011016), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_SM_STATUS                                   , RULL(0x05011036), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_SM_STATUS                                   , RULL(0x05011056), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_SM_STATUS                                   , RULL(0x05011076), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_SM_STATUS                                   , RULL(0x05011116), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_SM_STATUS                                   , RULL(0x05011136), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_SM_STATUS                                   , RULL(0x05011156), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_SM_STATUS                                   , RULL(0x05011176), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_SM_STATUS                                   , RULL(0x05011216), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_SM_STATUS                                   , RULL(0x05011236), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_SM_STATUS                                   , RULL(0x05011256), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_SM_STATUS                                   , RULL(0x05011276), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PEC_SPATTN_SCOM                                         , RULL(0x0D040004), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_SPATTN_SCOM1                                        , RULL(0x0D040005), SH_UNT_PEC      , SH_ACS_SCOM1_NC  );
REG64( PEC_SPATTN_SCOM2                                        , RULL(0x0D040006), SH_UNT_PEC      , SH_ACS_SCOM2_NC  );
REG64( PEC_0_SPATTN_SCOM                                       , RULL(0x0D040004), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_0_SPATTN_SCOM1                                      , RULL(0x0D040005), SH_UNT_PEC_0    , SH_ACS_SCOM1_NC  );
REG64( PEC_0_SPATTN_SCOM2                                      , RULL(0x0D040006), SH_UNT_PEC_0    , SH_ACS_SCOM2_NC  );
REG64( PEC_1_SPATTN_SCOM                                       , RULL(0x0E040004), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_1_SPATTN_SCOM1                                      , RULL(0x0E040005), SH_UNT_PEC_1    , SH_ACS_SCOM1_NC  );
REG64( PEC_1_SPATTN_SCOM2                                      , RULL(0x0E040006), SH_UNT_PEC_1    , SH_ACS_SCOM2_NC  );
REG64( PEC_2_SPATTN_SCOM                                       , RULL(0x0F040004), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );
REG64( PEC_2_SPATTN_SCOM1                                      , RULL(0x0F040005), SH_UNT_PEC_2    , SH_ACS_SCOM1_NC  );
REG64( PEC_2_SPATTN_SCOM2                                      , RULL(0x0F040006), SH_UNT_PEC_2    , SH_ACS_SCOM2_NC  );

REG64( PEC_SPA_MASK                                            , RULL(0x0D040007), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SPA_MASK                                          , RULL(0x0D040007), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SPA_MASK                                          , RULL(0x0E040007), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SPA_MASK                                          , RULL(0x0F040007), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_SPIMPSS_ADC_CTRL_REG0                                , RULL(0x00070000), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_100NS_REG                                     , RULL(0x00070028), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_CMD_REG                                   , RULL(0x00070004), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_CTRL_REG1                                 , RULL(0x00070001), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_CTRL_REG2                                 , RULL(0x00070002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_RDATA_REG0                                , RULL(0x00070020), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_RDATA_REG1                                , RULL(0x00070021), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_RDATA_REG2                                , RULL(0x00070022), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_RDATA_REG3                                , RULL(0x00070023), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_RESET_REGISTER                            , RULL(0x00070005), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_STATUS_REG                                , RULL(0x00070003), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_ADC_WDATA_REG                                 , RULL(0x00070010), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_COMMAND_REG                               , RULL(0x00070044), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_CTRL_REG0                                 , RULL(0x00070040), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_CTRL_REG1                                 , RULL(0x00070041), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_CTRL_REG2                                 , RULL(0x00070042), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_RDATA_REG                                 , RULL(0x00070060), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_RESET_REGISTER                            , RULL(0x00070045), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_STATUS_REG                                , RULL(0x00070043), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SPIPSS_P2S_WDATA_REG                                 , RULL(0x00070050), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SRAM_SRBV0_OCI                                       , RULL(0xC0050020), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRBV0_SCOM                                      , RULL(0x0006A004), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SRBV1_OCI                                       , RULL(0xC0050028), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRBV1_SCOM                                      , RULL(0x0006A005), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SRBV2_OCI                                       , RULL(0xC0050030), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRBV2_SCOM                                      , RULL(0x0006A006), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SRBV3_OCI                                       , RULL(0xC0050038), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRBV3_SCOM                                      , RULL(0x0006A007), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SRCHSW_OCI                                      , RULL(0xC0050040), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRCHSW_SCOM                                     , RULL(0x0006A008), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SREAR_OCI                                       , RULL(0xC0050018), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SREAR_SCOM                                      , RULL(0x0006A003), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SRMAP_OCI                                       , RULL(0xC0050010), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRMAP_SCOM                                      , RULL(0x0006A002), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SRAM_SRMR_OCI                                        , RULL(0xC0050008), SH_UNT          , SH_ACS_OCI       );
REG64( PU_SRAM_SRMR_SCOM                                       , RULL(0x0006A001), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_STATUS_REGISTER                                      , RULL(0x00010002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_STATUS_REGISTER_B                                    , RULL(0x000A0002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_STATUS_REGISTER_C                                    , RULL(0x000A1002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_STATUS_REGISTER_D                                    , RULL(0x000A2002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_STATUS_REGISTER_E                                    , RULL(0x000A3002), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_STATUS_REGISTER_ENGINE_B                             , RULL(0x000A000B), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_STATUS_REGISTER_ENGINE_C                             , RULL(0x000A100B), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_STATUS_REGISTER_ENGINE_D                             , RULL(0x000A200B), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PU_STATUS_REGISTER_ENGINE_E                             , RULL(0x000A300B), SH_UNT          ,
       SH_ACS_SCOM      ); //WARNING - VALUE SET SAME AS ANOTHER REG

REG64( PEC_SUM_MASK_REG                                        , RULL(0x0D040017), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SUM_MASK_REG                                      , RULL(0x0D040017), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SUM_MASK_REG                                      , RULL(0x0E040017), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SUM_MASK_REG                                      , RULL(0x0F040017), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_SU_CH0_ABORT_CSB                                     , RULL(0x02011043), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_CH1_ABORT_CSB                                     , RULL(0x02011045), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_CH2_ABORT_CSB                                     , RULL(0x02011047), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_CH3_ABORT_CSB                                     , RULL(0x02011049), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_CH4_ABORT_CSB                                     , RULL(0x0201104B), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_CRB_KILL_REQ                                      , RULL(0x02011053), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SU_DMA_ERROR_REPORT_0                                , RULL(0x02011057), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_DMA_ERROR_REPORT_1                                , RULL(0x02011058), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_ENGINE_ENABLE                                     , RULL(0x02011041), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SU_ERAT_ERROR_RPT                                    , RULL(0x020110D7), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_INBOUND_WRITE_CONTROL                             , RULL(0x02011042), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SU_PERFMON_CONTROL_0                                 , RULL(0x02011054), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SU_PERFMON_CONTROL_1                                 , RULL(0x02011055), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_SU_STATUS                                            , RULL(0x02011040), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SU_UMAC_ERROR_RPT                                    , RULL(0x020110D3), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SU_UMAC_ERROR_RPT1                                   , RULL(0x020110D8), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SYM_HI_PRIOR_RCV_FIFO_ASB                            , RULL(0x020110C7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SYM_HI_PRIOR_RCV_FIFO_BAR                            , RULL(0x020110C1), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SYM_HI_PRIOR_RCV_FIFO_CNTL                           , RULL(0x020110C4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SYM_LO_PRIOR_RCV_FIFO_ASB                            , RULL(0x020110D0), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SYM_LO_PRIOR_RCV_FIFO_BAR                            , RULL(0x020110CA), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SYM_LO_PRIOR_RCV_FIFO_CNTL                           , RULL(0x020110CD), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_SYM_MAX_BYTE_CNT                                     , RULL(0x0201105A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_SYNC_CONFIG                                         , RULL(0x0D030000), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_SYNC_CONFIG                                       , RULL(0x0D030000), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_SYNC_CONFIG                                       , RULL(0x0E030000), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_SYNC_CONFIG                                       , RULL(0x0F030000), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_SYNC_FIR_ACTION0_REG                                 , RULL(0x050129C6), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SYNC_FIR_ACTION1_REG                                 , RULL(0x050129C7), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_SYNC_FIR_MASK_REG                                    , RULL(0x050129C3), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_SYNC_FIR_MASK_REG_AND                                , RULL(0x050129C4), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_SYNC_FIR_MASK_REG_OR                                 , RULL(0x050129C5), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_SYNC_FIR_REG                                         , RULL(0x050129C0), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_SYNC_FIR_REG_AND                                     , RULL(0x050129C1), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_SYNC_FIR_REG_OR                                      , RULL(0x050129C2), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_NPU_SM1_TCE_KILL                                     , RULL(0x05011324), SH_UNT_PU_NPU_SM1,
       SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_HI_DATA_REG                   , RULL(0x07010C00), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC01_FAST_TRA0_TRACE_LO_DATA_REG                   , RULL(0x07010C01), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRCTRL_CONFIG                 , RULL(0x07010C02), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_0               , RULL(0x07010C03), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_1               , RULL(0x07010C04), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_2               , RULL(0x07010C05), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_3               , RULL(0x07010C06), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_4               , RULL(0x07010C07), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_5               , RULL(0x07010C08), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA0_TRACE_TRDATA_CONFIG_9               , RULL(0x07010C09), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_HI_DATA_REG                   , RULL(0x07010C40), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC01_FAST_TRA1_TRACE_LO_DATA_REG                   , RULL(0x07010C41), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRCTRL_CONFIG                 , RULL(0x07010C42), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_0               , RULL(0x07010C43), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_1               , RULL(0x07010C44), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_2               , RULL(0x07010C45), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_3               , RULL(0x07010C46), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_4               , RULL(0x07010C47), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_5               , RULL(0x07010C48), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC01_FAST_TRA1_TRACE_TRDATA_CONFIG_9               , RULL(0x07010C49), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_HI_DATA_REG                   , RULL(0x08010C00), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC23_FAST_TRA0_TRACE_LO_DATA_REG                   , RULL(0x08010C01), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRCTRL_CONFIG                 , RULL(0x08010C02), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_0               , RULL(0x08010C03), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_1               , RULL(0x08010C04), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_2               , RULL(0x08010C05), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_3               , RULL(0x08010C06), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_4               , RULL(0x08010C07), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_5               , RULL(0x08010C08), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA0_TRACE_TRDATA_CONFIG_9               , RULL(0x08010C09), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_HI_DATA_REG                   , RULL(0x08010C40), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC23_FAST_TRA1_TRACE_LO_DATA_REG                   , RULL(0x08010C41), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRCTRL_CONFIG                 , RULL(0x08010C42), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_0               , RULL(0x08010C43), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_1               , RULL(0x08010C44), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_2               , RULL(0x08010C45), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_3               , RULL(0x08010C46), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_4               , RULL(0x08010C47), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_5               , RULL(0x08010C48), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCMC23_FAST_TRA1_TRACE_TRDATA_CONFIG_9               , RULL(0x08010C49), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_HI_DATA_REG                      , RULL(0x02010400), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN0_TRA0_TR0_TRACE_LO_DATA_REG                      , RULL(0x02010401), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x02010402), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x02010403), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x02010404), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x02010405), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x02010406), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x02010407), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x02010408), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x02010409), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_HI_DATA_REG                      , RULL(0x02010440), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN0_TRA0_TR1_TRACE_LO_DATA_REG                      , RULL(0x02010441), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x02010442), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x02010443), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x02010444), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x02010445), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x02010446), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x02010447), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x02010448), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA0_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x02010449), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_HI_DATA_REG                      , RULL(0x02010480), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN0_TRA1_TR0_TRACE_LO_DATA_REG                      , RULL(0x02010481), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x02010482), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x02010483), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x02010484), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x02010485), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x02010486), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x02010487), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x02010488), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN0_TRA1_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x02010489), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_HI_DATA_REG                      , RULL(0x03010400), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA0_TR0_TRACE_LO_DATA_REG                      , RULL(0x03010401), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x03010402), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010403), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010404), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010405), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010406), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010407), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010408), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010409), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_HI_DATA_REG                      , RULL(0x03010440), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA0_TR1_TRACE_LO_DATA_REG                      , RULL(0x03010441), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x03010442), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010443), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010444), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010445), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010446), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010447), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010448), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA0_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010449), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_HI_DATA_REG                      , RULL(0x03010480), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA1_TR0_TRACE_LO_DATA_REG                      , RULL(0x03010481), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x03010482), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010483), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010484), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010485), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010486), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010487), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010488), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010489), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_HI_DATA_REG                      , RULL(0x030104C0), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA1_TR1_TRACE_LO_DATA_REG                      , RULL(0x030104C1), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x030104C2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x030104C3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x030104C4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x030104C5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x030104C6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x030104C7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x030104C8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA1_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x030104C9), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_HI_DATA_REG                      , RULL(0x03010500), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA2_TR0_TRACE_LO_DATA_REG                      , RULL(0x03010501), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x03010502), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010503), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010504), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010505), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010506), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010507), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010508), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010509), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_HI_DATA_REG                      , RULL(0x03010540), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA2_TR1_TRACE_LO_DATA_REG                      , RULL(0x03010541), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x03010542), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010543), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010544), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010545), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010546), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010547), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010548), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA2_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010549), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_HI_DATA_REG                      , RULL(0x03010580), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA3_TR0_TRACE_LO_DATA_REG                      , RULL(0x03010581), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x03010582), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010583), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010584), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010585), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010586), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010587), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010588), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010589), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_HI_DATA_REG                      , RULL(0x030105C0), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA3_TR1_TRACE_LO_DATA_REG                      , RULL(0x030105C1), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x030105C2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x030105C3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x030105C4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x030105C5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x030105C6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x030105C7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x030105C8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA3_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x030105C9), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_HI_DATA_REG                      , RULL(0x03010600), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA4_TR0_TRACE_LO_DATA_REG                      , RULL(0x03010601), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x03010602), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010603), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010604), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010605), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010606), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010607), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010608), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010609), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_HI_DATA_REG                      , RULL(0x03010640), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA4_TR1_TRACE_LO_DATA_REG                      , RULL(0x03010641), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x03010642), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x03010643), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x03010644), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x03010645), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x03010646), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x03010647), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x03010648), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN1_TRA4_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x03010649), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_HI_DATA_REG                      , RULL(0x04010400), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN2_TRA0_TR0_TRACE_LO_DATA_REG                      , RULL(0x04010401), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x04010402), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x04010403), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x04010404), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x04010405), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x04010406), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x04010407), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x04010408), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x04010409), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_HI_DATA_REG                      , RULL(0x04010440), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN2_TRA0_TR1_TRACE_LO_DATA_REG                      , RULL(0x04010441), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x04010442), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x04010443), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x04010444), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x04010445), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x04010446), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x04010447), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x04010448), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN2_TRA0_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x04010449), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_HI_DATA_REG                      , RULL(0x05010400), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA0_TR0_TRACE_LO_DATA_REG                      , RULL(0x05010401), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x05010402), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010403), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010404), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010405), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010406), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010407), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010408), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010409), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_HI_DATA_REG                      , RULL(0x05010440), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA0_TR1_TRACE_LO_DATA_REG                      , RULL(0x05010441), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x05010442), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010443), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010444), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010445), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010446), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010447), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010448), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA0_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010449), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_HI_DATA_REG                      , RULL(0x05010480), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA1_TR0_TRACE_LO_DATA_REG                      , RULL(0x05010481), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x05010482), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010483), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010484), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010485), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010486), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010487), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010488), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010489), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_HI_DATA_REG                      , RULL(0x050104C0), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA1_TR1_TRACE_LO_DATA_REG                      , RULL(0x050104C1), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x050104C2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x050104C3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x050104C4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x050104C5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x050104C6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x050104C7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x050104C8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA1_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x050104C9), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_HI_DATA_REG                      , RULL(0x05010500), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA2_TR0_TRACE_LO_DATA_REG                      , RULL(0x05010501), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x05010502), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010503), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010504), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010505), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010506), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010507), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010508), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010509), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_HI_DATA_REG                      , RULL(0x05010540), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA2_TR1_TRACE_LO_DATA_REG                      , RULL(0x05010541), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x05010542), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010543), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010544), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010545), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010546), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010547), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010548), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA2_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010549), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_HI_DATA_REG                      , RULL(0x05010580), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA3_TR0_TRACE_LO_DATA_REG                      , RULL(0x05010581), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x05010582), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010583), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010584), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010585), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010586), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010587), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010588), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010589), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_HI_DATA_REG                      , RULL(0x050105C0), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA3_TR1_TRACE_LO_DATA_REG                      , RULL(0x050105C1), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x050105C2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x050105C3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x050105C4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x050105C5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x050105C6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x050105C7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x050105C8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA3_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x050105C9), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_HI_DATA_REG                      , RULL(0x05010600), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA4_TR0_TRACE_LO_DATA_REG                      , RULL(0x05010601), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x05010602), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010603), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010604), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010605), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010606), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010607), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010608), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA4_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010609), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_HI_DATA_REG                      , RULL(0x05010680), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA5_TR0_TRACE_LO_DATA_REG                      , RULL(0x05010681), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRCTRL_CONFIG                    , RULL(0x05010682), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_0                  , RULL(0x05010683), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_1                  , RULL(0x05010684), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_2                  , RULL(0x05010685), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_3                  , RULL(0x05010686), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_4                  , RULL(0x05010687), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_5                  , RULL(0x05010688), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR0_TRACE_TRDATA_CONFIG_9                  , RULL(0x05010689), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_HI_DATA_REG                      , RULL(0x050106C0), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA5_TR1_TRACE_LO_DATA_REG                      , RULL(0x050106C1), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRCTRL_CONFIG                    , RULL(0x050106C2), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_0                  , RULL(0x050106C3), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_1                  , RULL(0x050106C4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_2                  , RULL(0x050106C5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_3                  , RULL(0x050106C6), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_4                  , RULL(0x050106C7), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_5                  , RULL(0x050106C8), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TCN3_TRA5_TR1_TRACE_TRDATA_CONFIG_9                  , RULL(0x050106C9), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_HI_DATA_REG                   , RULL(0x0D010400), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_HI_DATA_REG                 , RULL(0x0D010400), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_LO_DATA_REG                   , RULL(0x0D010401), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_LO_DATA_REG                 , RULL(0x0D010401), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRCTRL_CONFIG                 , RULL(0x0D010402), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRCTRL_CONFIG               , RULL(0x0D010402), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_0               , RULL(0x0D010403), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_0             , RULL(0x0D010403), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_1               , RULL(0x0D010404), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_1             , RULL(0x0D010404), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_2               , RULL(0x0D010405), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_2             , RULL(0x0D010405), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_3               , RULL(0x0D010406), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_3             , RULL(0x0D010406), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_4               , RULL(0x0D010407), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_4             , RULL(0x0D010407), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_5               , RULL(0x0D010408), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_5             , RULL(0x0D010408), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_9               , RULL(0x0D010409), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TCPCI0_TRA0_TR0_TRACE_TRDATA_CONFIG_9             , RULL(0x0D010409), SH_UNT_PEC_0    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_HI_DATA_REG                 , RULL(0x0E010400), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_LO_DATA_REG                 , RULL(0x0E010401), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRCTRL_CONFIG               , RULL(0x0E010402), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_0             , RULL(0x0E010403), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_1             , RULL(0x0E010404), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_2             , RULL(0x0E010405), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_3             , RULL(0x0E010406), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_4             , RULL(0x0E010407), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_5             , RULL(0x0E010408), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_1_TCPCI1_TRA0_TR0_TRACE_TRDATA_CONFIG_9             , RULL(0x0E010409), SH_UNT_PEC_1    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_HI_DATA_REG                 , RULL(0x0F010400), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_LO_DATA_REG                 , RULL(0x0F010401), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRCTRL_CONFIG               , RULL(0x0F010402), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_0             , RULL(0x0F010403), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_1             , RULL(0x0F010404), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_2             , RULL(0x0F010405), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_3             , RULL(0x0F010406), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_4             , RULL(0x0F010407), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_5             , RULL(0x0F010408), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_2_TCPCI2_TRA0_TR0_TRACE_TRDATA_CONFIG_9             , RULL(0x0F010409), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU_SM2_TEST_CERR                                    , RULL(0x05011341), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( CAPP_TFMR                                               , RULL(0x02010827), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_TFMR                                             , RULL(0x02010827), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_TFMR                                             , RULL(0x04010827), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PEC_THERM_MODE_REG                                      , RULL(0x0D05000F), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_THERM_MODE_REG                                    , RULL(0x0D05000F), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_THERM_MODE_REG                                    , RULL(0x0E05000F), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_THERM_MODE_REG                                    , RULL(0x0F05000F), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_TIMEOUT_REG                                         , RULL(0x0D0F0010), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_TIMEOUT_REG                                       , RULL(0x0D0F0010), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_TIMEOUT_REG                                       , RULL(0x0E0F0010), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_TIMEOUT_REG                                       , RULL(0x0F0F0010), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_TIMESTAMP_COUNTER_READ                              , RULL(0x0D05001C), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_TIMESTAMP_COUNTER_READ                            , RULL(0x0D05001C), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_TIMESTAMP_COUNTER_READ                            , RULL(0x0E05001C), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_TIMESTAMP_COUNTER_READ                            , RULL(0x0F05001C), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( CAPP_TLBI_ERROR_REPORT                                  , RULL(0x0201080D), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_TLBI_ERROR_REPORT                                , RULL(0x0201080D), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_TLBI_ERROR_REPORT                                , RULL(0x0401080D), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_TOD_SYNC000                                        , RULL(0x02010826), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_TOD_SYNC000                                      , RULL(0x02010826), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_TOD_SYNC000                                      , RULL(0x04010826), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PU_TRUST_CONTROL                                        , RULL(0x05012B45), SH_UNT          , SH_ACS_SCOM      );

REG64( PEC_TUNNEL_BAR_REG                                      , RULL(0x04010C05), SH_UNT_PEC      , SH_ACS_SCOM_RW   );
REG64( PEC_0_TUNNEL_BAR_REG                                    , RULL(0x04010C05), SH_UNT_PEC_0    , SH_ACS_SCOM_RW   );
REG64( PEC_1_TUNNEL_BAR_REG                                    , RULL(0x04011005), SH_UNT_PEC_1    , SH_ACS_SCOM_RW   );
REG64( PEC_2_TUNNEL_BAR_REG                                    , RULL(0x04011405), SH_UNT_PEC_2    , SH_ACS_SCOM_RW   );

REG64( PU_TX_CH_FSM_REG                                        , RULL(0x05012805), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_CH_INTADDR_REG                                    , RULL(0x05012810), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_CH_MISC_REG                                       , RULL(0x05012813), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_CTRL_STAT_REG                                     , RULL(0x05012800), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_DBFF_REG0                                         , RULL(0x05012811), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_DBFF_REG1                                         , RULL(0x05012812), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_DF_FSM_REG                                        , RULL(0x05012806), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_ERROR_REG_WCLEAR                                  , RULL(0x05012802), SH_UNT          ,
       SH_ACS_SCOM_WCLEAR );
REG64( PU_TX_ERROR_REG_OR                                      , RULL(0x05012804), SH_UNT          , SH_ACS_SCOM1_OR  );

REG64( PU_TX_ERR_MODE                                          , RULL(0x05012807), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_MASK_REG                                          , RULL(0x05012803), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_PSI_CNTL                                          , RULL(0x04011830), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_PSI_MODE                                          , RULL(0x04011831), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_PSI_STATUS                                        , RULL(0x04011832), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_TX_TO_RT_REG                                         , RULL(0x05012801), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_UMAC_STATUS_CONTROL                                  , RULL(0x020110D5), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_BUFCTL                                           , RULL(0x0301180C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_CAMDATA0                                         , RULL(0x03011834), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_VAS_CAMDATA1                                         , RULL(0x03011835), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_VAS_CAMDISPCNTL                                      , RULL(0x03011833), SH_UNT          , SH_ACS_SCOM_WO   );

REG64( PU_VAS_CQERRRPT                                         , RULL(0x03011848), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_DBGCONT                                          , RULL(0x0301182E), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_VAS_DBGNORTH                                         , RULL(0x0301182D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_DBGSOUTH                                         , RULL(0x0301184C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_DBGTRIG                                          , RULL(0x0301182F), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_VAS_EGERRRPT                                         , RULL(0x0301184A), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_ERRINJNO                                         , RULL(0x03011832), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_ERRINJSO                                         , RULL(0x0301184B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_FIR_ACTION0_REG                                  , RULL(0x03011806), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_FIR_ACTION1_REG                                  , RULL(0x03011807), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_FIR_MASK_REG                                     , RULL(0x03011803), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_VAS_FIR_MASK_REG_AND                                 , RULL(0x03011804), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_VAS_FIR_MASK_REG_OR                                  , RULL(0x03011805), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_VAS_FIR_REG                                          , RULL(0x03011800), SH_UNT          , SH_ACS_SCOM_RW   );
REG64( PU_VAS_FIR_REG_AND                                      , RULL(0x03011801), SH_UNT          , SH_ACS_SCOM1_AND );
REG64( PU_VAS_FIR_REG_OR                                       , RULL(0x03011802), SH_UNT          , SH_ACS_SCOM2_OR  );

REG64( PU_VAS_FIR_WOF_REG                                      , RULL(0x03011808), SH_UNT          ,
       SH_ACS_SCOM_WCLRREG );

REG64( PU_VAS_INERRRPT                                         , RULL(0x0301182B), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_MISCCTL                                          , RULL(0x0301180D), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_MMIOCTL                                          , RULL(0x03011829), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_MMIODATA                                         , RULL(0x0301182A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_MMIOECC                                          , RULL(0x03011831), SH_UNT          , SH_ACS_SCOM_RO   );

REG64( PU_VAS_MMIO_BASE_ADDR                                   , RULL(0x020110D4), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_PBCFG0                                           , RULL(0x0301184D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PBCFG1                                           , RULL(0x0301184E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG1                                           , RULL(0x03011841), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG2                                           , RULL(0x03011842), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG3                                           , RULL(0x03011843), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG4                                           , RULL(0x03011844), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG5                                           , RULL(0x03011845), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG6                                           , RULL(0x03011846), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PGMIG7                                           , RULL(0x03011847), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_PMCNTL                                           , RULL(0x03011830), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_RGERRRPT                                         , RULL(0x0301182C), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_RMABAR                                           , RULL(0x0301180E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_RMABARM                                          , RULL(0x0301180F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_SOUTHCTL                                         , RULL(0x0301184F), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_UWMBAR                                           , RULL(0x0301180B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WCBSBAR                                          , RULL(0x03011840), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WCERRRPT                                         , RULL(0x03011849), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_VAS_WCMBAR                                           , RULL(0x0301180A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON0BAR                                        , RULL(0x03011810), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON0CMP                                        , RULL(0x03011820), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON0WID                                        , RULL(0x03011818), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON1BAR                                        , RULL(0x03011811), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON1CMP                                        , RULL(0x03011821), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON1WID                                        , RULL(0x03011819), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON2BAR                                        , RULL(0x03011812), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON2CMP                                        , RULL(0x03011822), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON2WID                                        , RULL(0x0301181A), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON3BAR                                        , RULL(0x03011813), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON3CMP                                        , RULL(0x03011823), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON3WID                                        , RULL(0x0301181B), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON4BAR                                        , RULL(0x03011814), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON4CMP                                        , RULL(0x03011824), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON4WID                                        , RULL(0x0301181C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON5BAR                                        , RULL(0x03011815), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON5CMP                                        , RULL(0x03011825), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON5WID                                        , RULL(0x0301181D), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON6BAR                                        , RULL(0x03011816), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON6CMP                                        , RULL(0x03011826), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON6WID                                        , RULL(0x0301181E), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON7BAR                                        , RULL(0x03011817), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON7CMP                                        , RULL(0x03011827), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_VAS_WRMON7WID                                        , RULL(0x0301181F), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PEC_VITAL_SCAN_OUT                                      , RULL(0x0D0F0017), SH_UNT_PEC      , SH_ACS_SCOM_RO   );
REG64( PEC_0_VITAL_SCAN_OUT                                    , RULL(0x0D0F0017), SH_UNT_PEC_0    , SH_ACS_SCOM_RO   );
REG64( PEC_1_VITAL_SCAN_OUT                                    , RULL(0x0E0F0017), SH_UNT_PEC_1    , SH_ACS_SCOM_RO   );
REG64( PEC_2_VITAL_SCAN_OUT                                    , RULL(0x0F0F0017), SH_UNT_PEC_2    , SH_ACS_SCOM_RO   );

REG64( PU_WATCHDOG_HANG_TIMERS_CNTL                            , RULL(0x0201105C), SH_UNT          , SH_ACS_SCOM_RW   );

REG64( PU_WATER_MARK_REGISTER_B                                , RULL(0x000A0007), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_WATER_MARK_REGISTER_C                                , RULL(0x000A1007), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_WATER_MARK_REGISTER_D                                , RULL(0x000A2007), SH_UNT          , SH_ACS_SCOM      );

REG64( PU_WATER_MARK_REGISTER_E                                , RULL(0x000A3007), SH_UNT          , SH_ACS_SCOM      );

REG64( PHB_WOF_REG                                             , RULL(0x0D010910), SH_UNT_PHB      ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_0_WOF_REG                                           , RULL(0x0D010910), SH_UNT_PHB_0    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_1_WOF_REG                                           , RULL(0x0E010910), SH_UNT_PHB_1    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_2_WOF_REG                                           , RULL(0x0E010950), SH_UNT_PHB_2    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_3_WOF_REG                                           , RULL(0x0F010910), SH_UNT_PHB_3    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_4_WOF_REG                                           , RULL(0x0F010950), SH_UNT_PHB_4    ,
       SH_ACS_SCOM_WCLRREG );
REG64( PHB_5_WOF_REG                                           , RULL(0x0F010990), SH_UNT_PHB_5    ,
       SH_ACS_SCOM_WCLRREG );

REG64( PEC_WRITE_PROTECT_ENABLE_REG                            , RULL(0x0D010005), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_WRITE_PROTECT_ENABLE_REG                          , RULL(0x0D010005), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_WRITE_PROTECT_ENABLE_REG                          , RULL(0x0E010005), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_WRITE_PROTECT_ENABLE_REG                          , RULL(0x0F010005), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_WRITE_PROTECT_ENABLE_REG                          , RULL(0x02010005), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_WRITE_PROTECT_ENABLE_REG                          , RULL(0x03010005), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_WRITE_PROTECT_ENABLE_REG                          , RULL(0x04010005), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_WRITE_PROTECT_ENABLE_REG                          , RULL(0x05010005), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_WRITE_PROTECT_RINGS_REG                             , RULL(0x0D010006), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_WRITE_PROTECT_RINGS_REG                           , RULL(0x0D010006), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_WRITE_PROTECT_RINGS_REG                           , RULL(0x0E010006), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_WRITE_PROTECT_RINGS_REG                           , RULL(0x0F010006), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_N0_WRITE_PROTECT_RINGS_REG                           , RULL(0x02010006), SH_UNT_PU_N0    , SH_ACS_SCOM      );
REG64( PU_N1_WRITE_PROTECT_RINGS_REG                           , RULL(0x03010006), SH_UNT_PU_N1    , SH_ACS_SCOM      );
REG64( PU_N2_WRITE_PROTECT_RINGS_REG                           , RULL(0x04010006), SH_UNT_PU_N2    , SH_ACS_SCOM      );
REG64( PU_N3_WRITE_PROTECT_RINGS_REG                           , RULL(0x05010006), SH_UNT_PU_N3    , SH_ACS_SCOM      );

REG64( PEC_XFIR                                                , RULL(0x0D040000), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_XFIR                                              , RULL(0x0D040000), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_XFIR                                              , RULL(0x0E040000), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_XFIR                                              , RULL(0x0F040000), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( CAPP_XPT_CONTROL                                        , RULL(0x0201081C), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_XPT_CONTROL                                      , RULL(0x0201081C), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_XPT_CONTROL                                      , RULL(0x0401081C), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_XPT_ERROR_REPORT                                   , RULL(0x0201080C), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_XPT_ERROR_REPORT                                 , RULL(0x0201080C), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_XPT_ERROR_REPORT                                 , RULL(0x0401080C), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( CAPP_XPT_PMU_EVENTS_SEL                                 , RULL(0x02010822), SH_UNT_CAPP     , SH_ACS_SCOM      );
REG64( CAPP_0_XPT_PMU_EVENTS_SEL                               , RULL(0x02010822), SH_UNT_CAPP_0   , SH_ACS_SCOM      );
REG64( CAPP_1_XPT_PMU_EVENTS_SEL                               , RULL(0x04010822), SH_UNT_CAPP_1   , SH_ACS_SCOM      );

REG64( PEC_XSTOP1                                              , RULL(0x0D03000C), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_XSTOP1                                            , RULL(0x0D03000C), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_XSTOP1                                            , RULL(0x0E03000C), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_XSTOP1                                            , RULL(0x0F03000C), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_XSTOP2                                              , RULL(0x0D03000D), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_XSTOP2                                            , RULL(0x0D03000D), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_XSTOP2                                            , RULL(0x0E03000D), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_XSTOP2                                            , RULL(0x0F03000D), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_XSTOP3                                              , RULL(0x0D03000E), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_XSTOP3                                            , RULL(0x0D03000E), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_XSTOP3                                            , RULL(0x0E03000E), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_XSTOP3                                            , RULL(0x0F03000E), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PEC_XSTOP_INTERRUPT_REG                                 , RULL(0x0D0F001C), SH_UNT_PEC      , SH_ACS_SCOM      );
REG64( PEC_0_XSTOP_INTERRUPT_REG                               , RULL(0x0D0F001C), SH_UNT_PEC_0    , SH_ACS_SCOM      );
REG64( PEC_1_XSTOP_INTERRUPT_REG                               , RULL(0x0E0F001C), SH_UNT_PEC_1    , SH_ACS_SCOM      );
REG64( PEC_2_XSTOP_INTERRUPT_REG                               , RULL(0x0F0F001C), SH_UNT_PEC_2    , SH_ACS_SCOM      );

REG64( PU_NPU0_SM0_XTIMER_CONFIG                               , RULL(0x05011003), SH_UNT_PU_NPU0_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM1_XTIMER_CONFIG                               , RULL(0x05011023), SH_UNT_PU_NPU0_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM2_XTIMER_CONFIG                               , RULL(0x05011043), SH_UNT_PU_NPU0_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU0_SM3_XTIMER_CONFIG                               , RULL(0x05011063), SH_UNT_PU_NPU0_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM0_XTIMER_CONFIG                               , RULL(0x05011103), SH_UNT_PU_NPU1_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM1_XTIMER_CONFIG                               , RULL(0x05011123), SH_UNT_PU_NPU1_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM2_XTIMER_CONFIG                               , RULL(0x05011143), SH_UNT_PU_NPU1_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU1_SM3_XTIMER_CONFIG                               , RULL(0x05011163), SH_UNT_PU_NPU1_SM3,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM0_XTIMER_CONFIG                               , RULL(0x05011203), SH_UNT_PU_NPU2_SM0,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM1_XTIMER_CONFIG                               , RULL(0x05011223), SH_UNT_PU_NPU2_SM1,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM2_XTIMER_CONFIG                               , RULL(0x05011243), SH_UNT_PU_NPU2_SM2,
       SH_ACS_SCOM      );
REG64( PU_NPU2_SM3_XTIMER_CONFIG                               , RULL(0x05011263), SH_UNT_PU_NPU2_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP0                                , RULL(0x05011360), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP1                                , RULL(0x05011361), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP2                                , RULL(0x05011362), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP3                                , RULL(0x05011363), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP4                                , RULL(0x05011364), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP5                                , RULL(0x05011365), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP6                                , RULL(0x05011366), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM3_XTS_ATSD_HYP7                                , RULL(0x05011367), SH_UNT_PU_NPU_SM3,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM2_XTS_CONFIG                                   , RULL(0x05011344), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM2_XTS_CONFIG2                                  , RULL(0x05011345), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );

REG64( PU_NPU_SM2_XTS_PMU_CNT                                  , RULL(0x05011348), SH_UNT_PU_NPU_SM2,
       SH_ACS_SCOM      );
#endif


/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_obus_scom_addresses.H $            */
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
/// @file p9_obus_scom_addresses.H
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


#ifndef __P9_OBUS_SCOM_ADDRESSES_H
#define __P9_OBUS_SCOM_ADDRESSES_H


#include <p9_scom_template_consts.H>
#include <p9_obus_scom_addresses_fixes.H>


REG64( OBUS_CSAR                                               , RULL(0x09010C58), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_CSAR                                             , RULL(0x09010C58), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_CSAR                                             , RULL(0x0C010C58), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_CSCR                                               , RULL(0x09010C55), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_CSCR_CLEAR                                         , RULL(0x09010C01), SH_UNT_OBUS     ,
       SH_ACS_SCOM1_CLEAR );
REG64( OBUS_CSCR_OR                                            , RULL(0x09010C02), SH_UNT_OBUS     , SH_ACS_SCOM2_OR  );
REG64( OBUS_0_CSCR                                             , RULL(0x09010C55), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_0_CSCR_CLEAR                                       , RULL(0x09010C01), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM1_CLEAR );
REG64( OBUS_0_CSCR_OR                                          , RULL(0x09010C02), SH_UNT_OBUS_0   , SH_ACS_SCOM2_OR  );
REG64( OBUS_3_CSCR                                             , RULL(0x0C010C55), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_CSCR_CLEAR                                       , RULL(0x0C010C01), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM1_CLEAR );
REG64( OBUS_3_CSCR_OR                                          , RULL(0x0C010C02), SH_UNT_OBUS_3   , SH_ACS_SCOM2_OR  );

REG64( OBUS_CSDR                                               , RULL(0x09010C59), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_CSDR                                             , RULL(0x09010C59), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_CSDR                                             , RULL(0x0C010C59), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_LL0_IOOL_LINK0_ERROR_STATUS                        , RULL(0x09010816), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_LL0_IOOL_LINK0_ERROR_STATUS                      , RULL(0x09010816), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_LL0_IOOL_LINK1_ERROR_STATUS                        , RULL(0x09010817), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_LL0_IOOL_LINK1_ERROR_STATUS                      , RULL(0x09010817), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_LL0_IOOL_LINKX_ERROR_STATUS                        , RULL(0x09010829), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_LL0_IOOL_LINKX_ERROR_STATUS                      , RULL(0x09010829), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_LL0_PB_IOOL_FIR_ACTION0_REG                        , RULL(0x09010806), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_LL0_PB_IOOL_FIR_ACTION0_REG                      , RULL(0x09010806), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );

REG64( OBUS_LL0_PB_IOOL_FIR_ACTION1_REG                        , RULL(0x09010807), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_LL0_PB_IOOL_FIR_ACTION1_REG                      , RULL(0x09010807), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );

REG64( OBUS_LL0_PB_IOOL_FIR_MASK_REG                           , RULL(0x09010803), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_LL0_PB_IOOL_FIR_MASK_REG                         , RULL(0x09010803), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );

REG64( OBUS_LL0_PB_IOOL_FIR_REG                                , RULL(0x09010800), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_LL0_PB_IOOL_FIR_REG                              , RULL(0x09010800), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );

REG64( OBUS_3_LL3_IOOL_LINK0_ERROR_STATUS                      , RULL(0x0C010816), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_LL3_IOOL_LINK1_ERROR_STATUS                      , RULL(0x0C010817), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_LL3_IOOL_LINKX_ERROR_STATUS                      , RULL(0x0C010829), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_LL3_PB_IOOL_FIR_ACTION0_REG                      , RULL(0x0C010806), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_3_LL3_PB_IOOL_FIR_ACTION1_REG                      , RULL(0x0C010807), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_3_LL3_PB_IOOL_FIR_MASK_REG                         , RULL(0x0C010803), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_3_LL3_PB_IOOL_FIR_REG                              , RULL(0x0C010800), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_MIB_XIICAC                                         , RULL(0x09010C53), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XIICAC                                       , RULL(0x09010C53), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XIICAC                                       , RULL(0x0C010C53), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_MIB_XIMEM                                          , RULL(0x09010C51), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XIMEM                                        , RULL(0x09010C51), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XIMEM                                        , RULL(0x0C010C51), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_MIB_XISGB                                          , RULL(0x09010C52), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XISGB                                        , RULL(0x09010C52), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XISGB                                        , RULL(0x0C010C52), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_PPE_XIDBGPRO                                       , RULL(0x09010C4F), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_PPE_XIDBGPRO                                     , RULL(0x09010C4F), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_PPE_XIDBGPRO                                     , RULL(0x0C010C4F), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_PPE_XIRAMDBG                                       , RULL(0x09010C4D), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_PPE_XIRAMDBG                                     , RULL(0x09010C4D), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_PPE_XIRAMDBG                                     , RULL(0x0C010C4D), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_PPE_XIRAMEDR                                       , RULL(0x09010C4E), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_PPE_XIRAMEDR                                     , RULL(0x09010C4E), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_PPE_XIRAMEDR                                     , RULL(0x0C010C4E), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_PPE_XIRAMGA                                        , RULL(0x09010C4C), SH_UNT_OBUS     , SH_ACS_SCOM_WO   );
REG64( OBUS_0_PPE_XIRAMGA                                      , RULL(0x09010C4C), SH_UNT_OBUS_0   , SH_ACS_SCOM_WO   );
REG64( OBUS_3_PPE_XIRAMGA                                      , RULL(0x0C010C4C), SH_UNT_OBUS_3   , SH_ACS_SCOM_WO   );

REG64( OBUS_PPE_XIRAMRA                                        , RULL(0x09010C4B), SH_UNT_OBUS     , SH_ACS_SCOM_WO   );
REG64( OBUS_0_PPE_XIRAMRA                                      , RULL(0x09010C4B), SH_UNT_OBUS_0   , SH_ACS_SCOM_WO   );
REG64( OBUS_3_PPE_XIRAMRA                                      , RULL(0x0C010C4B), SH_UNT_OBUS_3   , SH_ACS_SCOM_WO   );

REG64( OBUS_PPE_XIXCR                                          , RULL(0x09010C4A), SH_UNT_OBUS     , SH_ACS_SCOM_WO   );
REG64( OBUS_0_PPE_XIXCR                                        , RULL(0x09010C4A), SH_UNT_OBUS_0   , SH_ACS_SCOM_WO   );
REG64( OBUS_3_PPE_XIXCR                                        , RULL(0x0C010C4A), SH_UNT_OBUS_3   , SH_ACS_SCOM_WO   );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL             , RULL(0x8002380009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002380009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x800238000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003180009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL             , RULL(0x8002800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x800280000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000880009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000900009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000980009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_PL                      , RULL(0x8002080009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x8002080009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x800208000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL             , RULL(0x8002380109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002380109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x800238010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003180109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL             , RULL(0x8002800109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002800109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x800280010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000800109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000880109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000900109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000980109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_PL                      , RULL(0x8002080109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x8002080109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x800208010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL             , RULL(0x8002380209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002380209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x800238020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003180209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL             , RULL(0x8002800209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002800209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x800280020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000800209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000880209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000900209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000980209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_PL                      , RULL(0x8002080209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x8002080209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x800208020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL             , RULL(0x8002380309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002380309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x800238030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003180309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL             , RULL(0x8002800309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002800309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x800280030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000800309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000880309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000900309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000980309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_PL                      , RULL(0x8002080309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x8002080309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL             , RULL(0x8002380409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002380409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x800238040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003180409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL             , RULL(0x8002800409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002800409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x800280040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000800409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000880409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000900409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000980409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_PL                      , RULL(0x8002080409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x8002080409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x800208040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL             , RULL(0x8002380509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002380509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x800238050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003180509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL             , RULL(0x8002800509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002800509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x800280050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000800509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000880509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000900509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000980509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_PL                      , RULL(0x8002080509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x8002080509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL             , RULL(0x8002380609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002380609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x800238060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003180609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL             , RULL(0x8002800609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002800609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x800280060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000800609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000880609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000900609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000980609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_PL                      , RULL(0x8002080609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x8002080609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x800208060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL             , RULL(0x8002380709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002380709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x800238070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003180709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL             , RULL(0x8002800709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002800709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x800280070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000800709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000880709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000900709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000980709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_PL                      , RULL(0x8002080709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x8002080709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x800208070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL             , RULL(0x8002380809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002380809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x800238080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003180809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL             , RULL(0x8002800809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002800809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x800280080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000800809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000880809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000900809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000980809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_PL                      , RULL(0x8002080809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x8002080809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL             , RULL(0x8002380909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002380909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x800238090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003180909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL             , RULL(0x8002800909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002800909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x800280090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000800909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000880909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000900909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000980909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_PL                      , RULL(0x8002080909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x8002080909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x800208090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL             , RULL(0x8002380A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002380A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002380A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003180A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL             , RULL(0x8002800A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002800A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002800A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000800A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000880A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000900A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000980A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_PL                      , RULL(0x8002080A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x8002080A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x8002080A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL             , RULL(0x8002380B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002380B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002380B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003180B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL             , RULL(0x8002800B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002800B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002800B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000800B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000880B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000900B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000980B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_PL                      , RULL(0x8002080B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x8002080B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x8002080B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL             , RULL(0x8002380C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002380C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002380C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003180C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL             , RULL(0x8002800C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002800C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002800C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000800C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000880C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000900C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000980C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_PL                      , RULL(0x8002080C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x8002080C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x8002080C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL             , RULL(0x8002380D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002380D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002380D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003180D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL             , RULL(0x8002800D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002800D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002800D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000800D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000880D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000900D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000980D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_PL                      , RULL(0x8002080D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x8002080D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x8002080D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL             , RULL(0x8002380E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002380E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002380E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003180E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL             , RULL(0x8002800E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002800E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002800E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000800E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000880E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000900E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000980E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_PL                      , RULL(0x8002080E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x8002080E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x8002080E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL             , RULL(0x8002380F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002380F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002380F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003180F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL             , RULL(0x8002800F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002800F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002800F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000800F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000880F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000900F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000980F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_PL                      , RULL(0x8002080F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x8002080F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x8002080F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002201009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002201009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002281009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002281009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002301009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002301009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL             , RULL(0x8002381009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002381009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x800238100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002681009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002681009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003181009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003181009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002701009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002701009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002781009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002781009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL             , RULL(0x8002801009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002801009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x800280100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000801009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000801009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000881009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000881009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000901009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000901009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000981009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000981009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002101009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002101009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_PL                      , RULL(0x8002081009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_FIR_PL                    , RULL(0x8002081009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_FIR_PL                    , RULL(0x800208100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002001009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002001009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002201109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002201109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002281109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002281109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002301109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002301109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL             , RULL(0x8002381109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002381109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x800238110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002681109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002681109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003181109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003181109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002701109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002701109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002781109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002781109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL             , RULL(0x8002801109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002801109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x800280110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000801109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000801109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000881109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000881109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000901109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000901109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000981109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000981109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002101109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002101109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_PL                      , RULL(0x8002081109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_FIR_PL                    , RULL(0x8002081109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_FIR_PL                    , RULL(0x800208110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002001109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002001109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002201209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002201209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002281209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002281209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002301209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002301209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL             , RULL(0x8002381209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002381209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x800238120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002681209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002681209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003181209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003181209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002701209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002701209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002781209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002781209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL             , RULL(0x8002801209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002801209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x800280120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000801209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000801209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000881209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000881209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000901209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000901209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000981209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000981209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002101209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002101209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_PL                      , RULL(0x8002081209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_FIR_PL                    , RULL(0x8002081209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_FIR_PL                    , RULL(0x800208120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002001209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002001209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002201309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002201309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002281309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002281309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002301309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002301309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL             , RULL(0x8002381309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002381309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x800238130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002681309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002681309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003181309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003181309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002701309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002701309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002781309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002781309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL             , RULL(0x8002801309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002801309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x800280130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000801309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000801309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000881309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000881309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000901309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000901309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000981309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000981309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002101309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002101309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_PL                      , RULL(0x8002081309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_FIR_PL                    , RULL(0x8002081309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_FIR_PL                    , RULL(0x800208130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002001309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002001309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002201409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002201409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002281409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002281409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002301409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002301409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL             , RULL(0x8002381409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x8002381409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE4_EO_PL           , RULL(0x800238140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002681409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002681409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003181409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003181409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002701409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002701409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002781409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002781409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL             , RULL(0x8002801409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x8002801409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT4_EO_PL           , RULL(0x800280140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000801409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000801409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000881409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000881409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000901409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000901409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000981409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000981409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002101409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002101409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_PL                      , RULL(0x8002081409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_FIR_PL                    , RULL(0x8002081409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_FIR_PL                    , RULL(0x800208140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002001409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002001409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002201509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002201509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002281509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002281509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002301509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002301509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL             , RULL(0x8002381509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x8002381509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE4_EO_PL           , RULL(0x800238150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002681509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002681509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003181509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003181509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002701509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002701509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002781509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002781509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL             , RULL(0x8002801509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x8002801509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT4_EO_PL           , RULL(0x800280150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000801509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000801509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000881509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000881509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000901509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000901509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000981509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000981509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002101509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002101509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_PL                      , RULL(0x8002081509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_FIR_PL                    , RULL(0x8002081509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_FIR_PL                    , RULL(0x800208150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002001509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002001509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002201609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002201609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002281609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002281609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002301609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002301609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL             , RULL(0x8002381609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x8002381609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE4_EO_PL           , RULL(0x800238160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002681609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002681609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003181609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003181609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002701609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002701609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002781609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002781609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL             , RULL(0x8002801609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x8002801609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT4_EO_PL           , RULL(0x800280160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000801609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000801609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000881609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000881609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000901609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000901609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000981609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000981609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002101609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002101609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_PL                      , RULL(0x8002081609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_FIR_PL                    , RULL(0x8002081609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_FIR_PL                    , RULL(0x800208160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002001609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002001609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002481709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002501709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002581709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002601709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002401709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002201709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002201709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002281709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002281709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002301709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002301709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL             , RULL(0x8002381709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x8002381709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE4_EO_PL           , RULL(0x800238170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002681709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002681709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003181709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003181709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002701709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002701709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002781709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002781709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL             , RULL(0x8002801709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x8002801709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT4_EO_PL           , RULL(0x800280170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C81709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C81709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000081709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000801709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000801709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000101709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000881709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000881709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000181709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000901709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000901709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000201709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000981709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000981709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000281709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A01709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A01709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000301709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A81709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A81709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000381709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B01709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B01709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000401709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B81709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B81709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C01709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C01709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000001709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002181709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002101709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002101709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_PL                      , RULL(0x8002081709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_FIR_PL                    , RULL(0x8002081709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_FIR_PL                    , RULL(0x800208170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002001709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002001709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL10_EO_PG                            , RULL(0x8009200009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL10_EO_PG                          , RULL(0x8009200009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL11_EO_PG                            , RULL(0x8009280009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL11_EO_PG                          , RULL(0x8009280009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL12_EO_PG                            , RULL(0x8009300009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL12_EO_PG                          , RULL(0x8009300009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL13_EO_PG                            , RULL(0x8009380009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL13_EO_PG                          , RULL(0x8009380009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL14_EO_PG                            , RULL(0x8009400009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL14_EO_PG                          , RULL(0x8009400009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL1_EO_PG                             , RULL(0x8008D80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL2_EO_PG                             , RULL(0x8008E00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL3_EO_PG                             , RULL(0x8008E80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL4_EO_PG                             , RULL(0x8008F00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL5_EO_PG                             , RULL(0x8008F80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL6_EO_PG                             , RULL(0x8009000009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL6_EO_PG                           , RULL(0x8009000009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL8_EO_PG                             , RULL(0x8009100009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL8_EO_PG                           , RULL(0x8009100009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL9_EO_PG                             , RULL(0x8009180009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL9_EO_PG                           , RULL(0x8009180009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTLX7_EO_PG                            , RULL(0x8009080009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTLX7_EO_PG                          , RULL(0x8009080009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE10_EO_PG                            , RULL(0x8008580009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE10_EO_PG                          , RULL(0x8008580009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE10_EO_PG                          , RULL(0x800858000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE11_EO_PG                            , RULL(0x8008600009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE11_EO_PG                          , RULL(0x8008600009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE11_EO_PG                          , RULL(0x800860000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE12_EO_PG                            , RULL(0x8008680009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE12_EO_PG                          , RULL(0x8008680009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE12_EO_PG                          , RULL(0x800868000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE13_EO_PG                            , RULL(0x8008700009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE13_EO_PG                          , RULL(0x8008700009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE13_EO_PG                          , RULL(0x800870000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE14_EO_PG                            , RULL(0x8008780009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE14_EO_PG                          , RULL(0x8008780009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE14_EO_PG                          , RULL(0x800878000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE15_EO_PG                            , RULL(0x8008800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE15_EO_PG                          , RULL(0x8008800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE15_EO_PG                          , RULL(0x800880000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE16_EO_PG                            , RULL(0x8008880009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE16_EO_PG                          , RULL(0x8008880009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE16_EO_PG                          , RULL(0x800888000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE17_EO_PG                            , RULL(0x8008900009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE17_EO_PG                          , RULL(0x8008900009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE17_EO_PG                          , RULL(0x800890000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE18_EO_PG                            , RULL(0x8008980009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE18_EO_PG                          , RULL(0x8008980009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE18_EO_PG                          , RULL(0x800898000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE19_EO_PG                            , RULL(0x8008A00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE1_EO_PG                             , RULL(0x8008100009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE1_EO_PG                           , RULL(0x8008100009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE1_EO_PG                           , RULL(0x800810000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE1_O_PG                              , RULL(0x8009B00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE1_O_PG                            , RULL(0x8009B00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE1_O_PG                            , RULL(0x8009B0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE20_EO_PG                            , RULL(0x8008A80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE21_EO_PG                            , RULL(0x8008B00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE22_EO_PG                            , RULL(0x8008B80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE23_EO_PG                            , RULL(0x8008C00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE24_EO_PG                            , RULL(0x8008C80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE26_EO_PG                            , RULL(0x8009680009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE26_EO_PG                          , RULL(0x8009680009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE26_EO_PG                          , RULL(0x800968000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE27_EO_PG                            , RULL(0x8009700009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE27_EO_PG                          , RULL(0x8009700009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE27_EO_PG                          , RULL(0x800970000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE28_EO_PG                            , RULL(0x8009780009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE28_EO_PG                          , RULL(0x8009780009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE28_EO_PG                          , RULL(0x800978000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE29_EO_PG                            , RULL(0x8008D00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE2_EO_PG                             , RULL(0x8008180009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE2_EO_PG                           , RULL(0x8008180009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE2_EO_PG                           , RULL(0x800818000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE5_EO_PG                             , RULL(0x8008300009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE5_EO_PG                           , RULL(0x8008300009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE5_EO_PG                           , RULL(0x800830000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE6_EO_PG                             , RULL(0x8008380009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE6_EO_PG                           , RULL(0x8008380009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE6_EO_PG                           , RULL(0x800838000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE7_EO_PG                             , RULL(0x8008400009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE7_EO_PG                           , RULL(0x8008400009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE7_EO_PG                           , RULL(0x800840000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE9_EO_PG                             , RULL(0x8008500009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE9_EO_PG                           , RULL(0x8008500009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE9_EO_PG                           , RULL(0x800850000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_STAT1_EO_PG                             , RULL(0x8009500009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_STAT1_EO_PG                           , RULL(0x8009500009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_STAT1_EO_PG                           , RULL(0x800950000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_STAT2_EO_PG                             , RULL(0x8009580009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_STAT2_EO_PG                           , RULL(0x8009580009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_STAT2_EO_PG                           , RULL(0x800958000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_CNTLX1_EO_PG                         , RULL(0x800B880009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B880009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_SPARE_MODE_PG                        , RULL(0x800B800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT10_EO_PG                         , RULL(0x800BD80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT11_EO_PG                         , RULL(0x800BE00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT1_EO_PG                          , RULL(0x800B900009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B900009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT2_EO_PG                          , RULL(0x800B980009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B980009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT3_EO_PG                          , RULL(0x800BA00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT4_EO_PG                          , RULL(0x800BA80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT5_EO_PG                          , RULL(0x800BB00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT6_EO_PG                          , RULL(0x800BB80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT7_EO_PG                          , RULL(0x800BC00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT8_EO_PG                          , RULL(0x800BC80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT9_EO_PG                          , RULL(0x800BD00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_FIR1_ERROR_INJECT_PG                        , RULL(0x800A980009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A980009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_FIR1_MASK_PG                                , RULL(0x800A900009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_FIR1_MASK_PG                              , RULL(0x800A900009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_FIR1_MASK_PG                              , RULL(0x800A90000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_FIR1_PG                                     , RULL(0x800A880009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_FIR1_PG                                   , RULL(0x800A880009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_FIR1_PG                                   , RULL(0x800A88000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_CNTL1_EO_PG                           , RULL(0x800AB00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_CNTL1_EO_PG                         , RULL(0x800AB00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_CNTL1_EO_PG                         , RULL(0x800AB0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_CNTL2_EO_PG                           , RULL(0x800AE00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_CNTL2_EO_PG                         , RULL(0x800AE00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_CNTL2_EO_PG                         , RULL(0x800AE0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_CNTL3_EO_PG                           , RULL(0x800AE80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_CNTL3_EO_PG                         , RULL(0x800AE80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_CNTL3_EO_PG                         , RULL(0x800AE8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_SPARE_MODE_PG                         , RULL(0x800A800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT1_EO_PG                           , RULL(0x800AB80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT2_EO_PG                           , RULL(0x800AC00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT3_EO_PG                           , RULL(0x800AC80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT4_EO_PG                           , RULL(0x800AD00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT4_EO_PG                         , RULL(0x800AD00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT4_EO_PG                         , RULL(0x800AD0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT5_EO_PG                           , RULL(0x800AD80009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT5_EO_PG                         , RULL(0x800AD80009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT5_EO_PG                         , RULL(0x800AD8000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_ID1_PG                                      , RULL(0x8008080009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_ID1_PG                                    , RULL(0x8008080009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_ID1_PG                                    , RULL(0x800808000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_SPARE_MODE_PG                               , RULL(0x8008000009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_SPARE_MODE_PG                             , RULL(0x8008000009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_SPARE_MODE_PG                             , RULL(0x800800000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x800388000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x800390000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x800398000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003300A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003300B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003300C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003300D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003300E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003300F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003300F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x800388100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x800390100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x800398100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x800388010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x800390010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x800398010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003801709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL                , RULL(0x8003301709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x8003301709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_GLBSM_PL_CNTL1X_O_PL              , RULL(0x800330170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003201709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003201709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003281709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003281709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x8003881709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x8003901709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x8003981709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A01709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A01709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x800388020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x800390020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x800398020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x800388040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x800390040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x800398040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x800388060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x800390060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x800398060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x800388070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x800390070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x800398070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL                 , RULL(0x8003300909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x8003300909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_GLBSM_PL_CNTL1X_O_PL               , RULL(0x800330090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x8003200909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x8003200909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x8003280909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x8003280909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x800388090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x800390090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x800398090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A00909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A00909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_ERROR_INJECT_PB                             , RULL(0x800F980009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_ERROR_INJECT_PB                           , RULL(0x800F980009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_ERROR_INJECT_PB                           , RULL(0x800F98000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_MASK_PB                                     , RULL(0x800F900009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_MASK_PB                                   , RULL(0x800F900009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_MASK_PB                                   , RULL(0x800F90000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_PB                                          , RULL(0x800F880009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_PB                                        , RULL(0x800F880009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_PB                                        , RULL(0x800F88000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_RESET_PB                                    , RULL(0x800F800009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_RESET_PB                                  , RULL(0x800F800009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_RESET_PB                                  , RULL(0x800F80000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_SCOM_MODE_PB                                       , RULL(0x09010C20), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_SCOM_MODE_PB                                     , RULL(0x09010C20), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_SCOM_MODE_PB                                     , RULL(0x0C010C20), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_SCOM_PPE_CNTL                                      , RULL(0x09010C60), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_SCOM_PPE_CNTL                                    , RULL(0x09010C60), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_SCOM_PPE_CNTL                                    , RULL(0x0C010C60), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_SCOM_PPE_FLAGS                                     , RULL(0x09010C63), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_SCOM_PPE_FLAGS_OR                                  , RULL(0x09010C64), SH_UNT_OBUS     , SH_ACS_SCOM1_OR  );
REG64( OBUS_SCOM_PPE_FLAGS_CLEAR                               , RULL(0x09010C65), SH_UNT_OBUS     ,
       SH_ACS_SCOM2_CLEAR );
REG64( OBUS_0_SCOM_PPE_FLAGS                                   , RULL(0x09010C63), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_0_SCOM_PPE_FLAGS_OR                                , RULL(0x09010C64), SH_UNT_OBUS_0   , SH_ACS_SCOM1_OR  );
REG64( OBUS_0_SCOM_PPE_FLAGS_CLEAR                             , RULL(0x09010C65), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM2_CLEAR );
REG64( OBUS_3_SCOM_PPE_FLAGS                                   , RULL(0x0C010C63), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_SCOM_PPE_FLAGS_OR                                , RULL(0x0C010C64), SH_UNT_OBUS_3   , SH_ACS_SCOM1_OR  );
REG64( OBUS_3_SCOM_PPE_FLAGS_CLEAR                             , RULL(0x0C010C65), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM2_CLEAR );

REG64( OBUS_SCOM_PPE_WORK_REG1                                 , RULL(0x09010C61), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_SCOM_PPE_WORK_REG1                               , RULL(0x09010C61), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_SCOM_PPE_WORK_REG1                               , RULL(0x0C010C61), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_SCOM_PPE_WORK_REG2                                 , RULL(0x09010C62), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_SCOM_PPE_WORK_REG2                               , RULL(0x09010C62), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_SCOM_PPE_WORK_REG2                               , RULL(0x0C010C62), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_SPARE_MODE_PB                                      , RULL(0x800F340009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_SPARE_MODE_PB                                    , RULL(0x800F340009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_SPARE_MODE_PB                                    , RULL(0x800F34000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TCOB0_ADDR_TRAP_REG                                , RULL(0x09010003), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_ADDR_TRAP_REG                              , RULL(0x09010003), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_ATOMIC_LOCK_MASK_LATCH_REG                   , RULL(0x09010007), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_ATOMIC_LOCK_MASK_LATCH_REG                 , RULL(0x09010007), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_INST1_COND_REG_1                         , RULL(0x090107C1), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_INST1_COND_REG_1                       , RULL(0x090107C1), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_INST1_COND_REG_2                         , RULL(0x090107C2), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_INST1_COND_REG_2                       , RULL(0x090107C2), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_INST1_COND_REG_3                         , RULL(0x090107C3), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_INST1_COND_REG_3                       , RULL(0x090107C3), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_INST2_COND_REG_1                         , RULL(0x090107C4), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_INST2_COND_REG_1                       , RULL(0x090107C4), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_INST2_COND_REG_2                         , RULL(0x090107C5), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_INST2_COND_REG_2                       , RULL(0x090107C5), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_INST2_COND_REG_3                         , RULL(0x090107C6), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_INST2_COND_REG_3                       , RULL(0x090107C6), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_MODE_REG                                 , RULL(0x090107C0), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_MODE_REG                               , RULL(0x090107C0), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_TRACE_MODE_REG_2                         , RULL(0x090107CB), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_TRACE_MODE_REG_2                       , RULL(0x090107CB), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_TRACE_REG_0                              , RULL(0x090107C9), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_TRACE_REG_0                            , RULL(0x090107C9), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_DBG_TRACE_REG_1                              , RULL(0x090107CA), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_DBG_TRACE_REG_1                            , RULL(0x090107CA), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_PSCOM_ERROR_MASK                             , RULL(0x09010002), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_PSCOM_ERROR_MASK                           , RULL(0x09010002), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_PSCOM_MODE_REG                               , RULL(0x09010000), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_PSCOM_MODE_REG                             , RULL(0x09010000), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_PSCOM_STATUS_ERROR_REG                       , RULL(0x09010001), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_PSCOM_STATUS_ERROR_REG                     , RULL(0x09010001), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_RING_FENCE_MASK_LATCH_REG                    , RULL(0x09010008), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_RING_FENCE_MASK_LATCH_REG                  , RULL(0x09010008), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_HI_DATA_REG                   , RULL(0x09010400), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_HI_DATA_REG                 , RULL(0x09010400), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG                   , RULL(0x09010401), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_LO_DATA_REG                 , RULL(0x09010401), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG                 , RULL(0x09010402), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRCTRL_CONFIG               , RULL(0x09010402), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_0               , RULL(0x09010403), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_0             , RULL(0x09010403), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_1               , RULL(0x09010404), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_1             , RULL(0x09010404), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_2               , RULL(0x09010405), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_2             , RULL(0x09010405), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_3               , RULL(0x09010406), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_3             , RULL(0x09010406), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_4               , RULL(0x09010407), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_4             , RULL(0x09010407), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_5               , RULL(0x09010408), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_5             , RULL(0x09010408), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9               , RULL(0x09010409), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_TRA0_TR0_TRACE_TRDATA_CONFIG_9             , RULL(0x09010409), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_WRITE_PROTECT_ENABLE_REG                     , RULL(0x09010005), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_WRITE_PROTECT_ENABLE_REG                   , RULL(0x09010005), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_TCOB0_WRITE_PROTECT_RINGS_REG                      , RULL(0x09010006), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_TCOB0_WRITE_PROTECT_RINGS_REG                    , RULL(0x09010006), SH_UNT_OBUS_0   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_ADDR_TRAP_REG                              , RULL(0x0C010003), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_ATOMIC_LOCK_MASK_LATCH_REG                 , RULL(0x0C010007), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_INST1_COND_REG_1                       , RULL(0x0C0107C1), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_INST1_COND_REG_2                       , RULL(0x0C0107C2), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_INST1_COND_REG_3                       , RULL(0x0C0107C3), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_INST2_COND_REG_1                       , RULL(0x0C0107C4), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_INST2_COND_REG_2                       , RULL(0x0C0107C5), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_INST2_COND_REG_3                       , RULL(0x0C0107C6), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_MODE_REG                               , RULL(0x0C0107C0), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_TRACE_MODE_REG_2                       , RULL(0x0C0107CB), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_TRACE_REG_0                            , RULL(0x0C0107C9), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_DBG_TRACE_REG_1                            , RULL(0x0C0107CA), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_PSCOM_ERROR_MASK                           , RULL(0x0C010002), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_PSCOM_MODE_REG                             , RULL(0x0C010000), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_PSCOM_STATUS_ERROR_REG                     , RULL(0x0C010001), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_RING_FENCE_MASK_LATCH_REG                  , RULL(0x0C010008), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_HI_DATA_REG                 , RULL(0x0C010400), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_LO_DATA_REG                 , RULL(0x0C010401), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRCTRL_CONFIG               , RULL(0x0C010402), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_0             , RULL(0x0C010403), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_1             , RULL(0x0C010404), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_2             , RULL(0x0C010405), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_3             , RULL(0x0C010406), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_4             , RULL(0x0C010407), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_5             , RULL(0x0C010408), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_TRA0_TR0_TRACE_TRDATA_CONFIG_9             , RULL(0x0C010409), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_WRITE_PROTECT_ENABLE_REG                   , RULL(0x0C010005), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_3_TCOB3_WRITE_PROTECT_RINGS_REG                    , RULL(0x0C010006), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_PL                      , RULL(0x8004240009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x8004240009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                    , RULL(0x8004040009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x8004040009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C0109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_PL                      , RULL(0x8004240109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x8004240109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                    , RULL(0x8004040109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x8004040109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C010C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C0209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_PL                      , RULL(0x8004240209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x8004240209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                    , RULL(0x8004040209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x8004040209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C020C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C0309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_PL                      , RULL(0x8004240309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x8004240309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                    , RULL(0x8004040309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x8004040309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C030C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C0409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_PL                      , RULL(0x8004240409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x8004240409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                    , RULL(0x8004040409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x8004040409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C040C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C0509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_PL                      , RULL(0x8004240509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x8004240509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                    , RULL(0x8004040509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x8004040509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C050C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C0609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_PL                      , RULL(0x8004240609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x8004240609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                    , RULL(0x8004040609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x8004040609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C060C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C0709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_PL                      , RULL(0x8004240709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x8004240709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                    , RULL(0x8004040709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x8004040709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C070C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C0809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_PL                      , RULL(0x8004240809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x8004240809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                    , RULL(0x8004040809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x8004040809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0809010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0809010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C080C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C0909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_PL                      , RULL(0x8004240909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x8004240909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                    , RULL(0x8004040909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x8004040909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0909010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0909010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C090C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C0A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_PL                      , RULL(0x8004240A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004240A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004240A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                    , RULL(0x8004040A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004040A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004040A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0A09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0A09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0A0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C0B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_PL                      , RULL(0x8004240B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004240B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004240B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                    , RULL(0x8004040B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004040B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004040B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0B09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0B09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0B0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C0C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_PL                      , RULL(0x8004240C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004240C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004240C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                    , RULL(0x8004040C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004040C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004040C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0C09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0C09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0C0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C0D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_PL                      , RULL(0x8004240D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004240D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004240D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                    , RULL(0x8004040D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004040D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004040D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0D09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0D09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0D0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C0E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_PL                      , RULL(0x8004240E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004240E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004240E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                    , RULL(0x8004040E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004040E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004040E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0E09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0E09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0E0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C0F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_PL                      , RULL(0x8004240F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004240F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004240F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                    , RULL(0x8004040F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004040F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004040F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0F09010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0F09010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0F0C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004141009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004141009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C1009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C1009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004541009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004541009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C1009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C1009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_PL                      , RULL(0x8004241009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_FIR_PL                    , RULL(0x8004241009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_FIR_PL                    , RULL(0x800424100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL                    , RULL(0x8004041009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_MODE1_PL                  , RULL(0x8004041009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_MODE1_PL                  , RULL(0x800404100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL                    , RULL(0x80040C1009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_MODE2_PL                  , RULL(0x80040C1009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_MODE2_PL                  , RULL(0x80040C100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL                    , RULL(0x80041C1009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_STAT1_PL                  , RULL(0x80041C1009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_STAT1_PL                  , RULL(0x80041C100C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004141109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004141109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C1109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C1109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004541109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004541109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C1109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C1109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_PL                      , RULL(0x8004241109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_FIR_PL                    , RULL(0x8004241109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_FIR_PL                    , RULL(0x800424110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL                    , RULL(0x8004041109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_MODE1_PL                  , RULL(0x8004041109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_MODE1_PL                  , RULL(0x800404110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL                    , RULL(0x80040C1109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_MODE2_PL                  , RULL(0x80040C1109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_MODE2_PL                  , RULL(0x80040C110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL                    , RULL(0x80041C1109010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_STAT1_PL                  , RULL(0x80041C1109010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_STAT1_PL                  , RULL(0x80041C110C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004141209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004141209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C1209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C1209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004541209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004541209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C1209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C1209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_PL                      , RULL(0x8004241209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_FIR_PL                    , RULL(0x8004241209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_FIR_PL                    , RULL(0x800424120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL                    , RULL(0x8004041209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_MODE1_PL                  , RULL(0x8004041209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_MODE1_PL                  , RULL(0x800404120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL                    , RULL(0x80040C1209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_MODE2_PL                  , RULL(0x80040C1209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_MODE2_PL                  , RULL(0x80040C120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL                    , RULL(0x80041C1209010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_STAT1_PL                  , RULL(0x80041C1209010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_STAT1_PL                  , RULL(0x80041C120C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004141309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004141309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C1309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C1309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004541309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004541309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C1309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C1309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_PL                      , RULL(0x8004241309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_FIR_PL                    , RULL(0x8004241309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_FIR_PL                    , RULL(0x800424130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL                    , RULL(0x8004041309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_MODE1_PL                  , RULL(0x8004041309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_MODE1_PL                  , RULL(0x800404130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL                    , RULL(0x80040C1309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_MODE2_PL                  , RULL(0x80040C1309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_MODE2_PL                  , RULL(0x80040C130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL                    , RULL(0x80041C1309010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_STAT1_PL                  , RULL(0x80041C1309010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_STAT1_PL                  , RULL(0x80041C130C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004141409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004141409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C1409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C1409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004541409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004541409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C1409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C1409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_PL                      , RULL(0x8004241409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_FIR_PL                    , RULL(0x8004241409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_FIR_PL                    , RULL(0x800424140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL                    , RULL(0x8004041409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_MODE1_PL                  , RULL(0x8004041409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_MODE1_PL                  , RULL(0x800404140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL                    , RULL(0x80040C1409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_MODE2_PL                  , RULL(0x80040C1409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_MODE2_PL                  , RULL(0x80040C140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL                    , RULL(0x80041C1409010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_STAT1_PL                  , RULL(0x80041C1409010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_STAT1_PL                  , RULL(0x80041C140C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004141509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004141509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C1509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C1509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004541509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004541509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C1509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C1509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_PL                      , RULL(0x8004241509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_FIR_PL                    , RULL(0x8004241509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_FIR_PL                    , RULL(0x800424150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL                    , RULL(0x8004041509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_MODE1_PL                  , RULL(0x8004041509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_MODE1_PL                  , RULL(0x800404150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL                    , RULL(0x80040C1509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_MODE2_PL                  , RULL(0x80040C1509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_MODE2_PL                  , RULL(0x80040C150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL                    , RULL(0x80041C1509010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_STAT1_PL                  , RULL(0x80041C1509010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_STAT1_PL                  , RULL(0x80041C150C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004141609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004141609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C1609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C1609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004541609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004541609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C1609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C1609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_PL                      , RULL(0x8004241609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_FIR_PL                    , RULL(0x8004241609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_FIR_PL                    , RULL(0x800424160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL                    , RULL(0x8004041609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_MODE1_PL                  , RULL(0x8004041609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_MODE1_PL                  , RULL(0x800404160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL                    , RULL(0x80040C1609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_MODE2_PL                  , RULL(0x80040C1609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_MODE2_PL                  , RULL(0x80040C160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL                    , RULL(0x80041C1609010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_STAT1_PL                  , RULL(0x80041C1609010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_STAT1_PL                  , RULL(0x80041C160C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004141709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004141709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C1709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C1709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004541709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004541709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004341709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C1709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C1709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_PL                      , RULL(0x8004241709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_FIR_PL                    , RULL(0x8004241709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_FIR_PL                    , RULL(0x800424170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL                    , RULL(0x8004041709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_MODE1_PL                  , RULL(0x8004041709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_MODE1_PL                  , RULL(0x800404170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL                    , RULL(0x80040C1709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_MODE2_PL                  , RULL(0x80040C1709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_MODE2_PL                  , RULL(0x80040C170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL                    , RULL(0x80041C1709010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_STAT1_PL                  , RULL(0x80041C1709010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_STAT1_PL                  , RULL(0x80041C170C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL1_EO_PG                           , RULL(0x800D340009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D340009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL1_O_PG                            , RULL(0x800D840009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL1_O_PG                          , RULL(0x800D840009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL1_O_PG                          , RULL(0x800D84000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL2_EO_PG                           , RULL(0x800D3C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL2_O_PG                            , RULL(0x800D8C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL2_O_PG                          , RULL(0x800D8C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL2_O_PG                          , RULL(0x800D8C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL3_EO_PG                           , RULL(0x800D440009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D440009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL4_EO_PG                           , RULL(0x800D4C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL5_EO_PG                           , RULL(0x800D540009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D540009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL6_EO_PG                           , RULL(0x800D5C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL7_EO_PG                           , RULL(0x800D640009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D640009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_MODE1_EO_PG                           , RULL(0x800D2C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_SPARE_MODE_PG                         , RULL(0x800D240009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D240009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_STAT1_EO_PG                           , RULL(0x800D6C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL10_EO_PG                            , RULL(0x800CDC0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL10_EO_PG                          , RULL(0x800CDC0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL10_EO_PG                          , RULL(0x800CDC000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL2_EO_PG                             , RULL(0x800C2C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL3_EO_PG                             , RULL(0x800C340009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C340009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL8_EO_PG                             , RULL(0x800CCC0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL8_EO_PG                           , RULL(0x800CCC0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL8_EO_PG                           , RULL(0x800CCC000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL9_EO_PG                             , RULL(0x800CD40009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL9_EO_PG                           , RULL(0x800CD40009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL9_EO_PG                           , RULL(0x800CD4000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTLG1_EO_PG                            , RULL(0x800C240009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C240009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_MODE1_EO_PG                             , RULL(0x800C140009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_MODE1_EO_PG                           , RULL(0x800C140009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_ERROR_INJECT_PG                         , RULL(0x800D1C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_MASK_PG                                 , RULL(0x800D0C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_MASK_PG                               , RULL(0x800D0C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_MASK_PG                               , RULL(0x800D0C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_PG                                      , RULL(0x800D040009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_PG                                    , RULL(0x800D040009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_PG                                    , RULL(0x800D04000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_RESET_PG                                , RULL(0x800D140009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_RESET_PG                              , RULL(0x800D140009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_RESET_PG                              , RULL(0x800D14000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_ID1_PG                                      , RULL(0x800C0C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_ID1_PG                                    , RULL(0x800C0C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_ID1_PG                                    , RULL(0x800C0C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_SPARE_MODE_PG                               , RULL(0x800C040009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_SPARE_MODE_PG                             , RULL(0x800C040009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_SPARE_MODE_PG                             , RULL(0x800C04000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL2_PB                                      , RULL(0x800F3C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL2_PB                                    , RULL(0x800F3C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL2_PB                                    , RULL(0x800F3C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_NVAL_PB                                  , RULL(0x800F0C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_NVAL_PB                                , RULL(0x800F0C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_NVAL_PB                                , RULL(0x800F0C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_PB                                       , RULL(0x800F040009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_PB                                     , RULL(0x800F040009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_PB                                     , RULL(0x800F04000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_PVAL_PB                                  , RULL(0x800F140009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_PVAL_PB                                , RULL(0x800F140009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_PVAL_PB                                , RULL(0x800F14000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_P_4X_PB                                  , RULL(0x800F1C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_P_4X_PB                                , RULL(0x800F1C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_P_4X_PB                                , RULL(0x800F1C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_SWO1_PB                                  , RULL(0x800F240009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_SWO1_PB                                , RULL(0x800F240009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_SWO1_PB                                , RULL(0x800F24000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_SWO2_PB                                  , RULL(0x800F2C0009010C3F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_SWO2_PB                                , RULL(0x800F2C0009010C3F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_SWO2_PB                                , RULL(0x800F2C000C010C3F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );
#endif


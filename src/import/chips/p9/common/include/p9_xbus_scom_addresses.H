/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_xbus_scom_addresses.H $            */
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
/// @file p9_xbus_scom_addresses.H
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


#ifndef __P9_XBUS_SCOM_ADDRESSES_H
#define __P9_XBUS_SCOM_ADDRESSES_H


#include <p9_scom_template_consts.H>
#include <p9_xbus_scom_addresses_fixes.H>


REG64( XBUS_IOPPE_CSAR                                         , RULL(0x06010858), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RW   );

REG64( XBUS_IOPPE_CSCR                                         , RULL(0x06010855), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RW   );
REG64( XBUS_IOPPE_CSCR_CLEAR                                   , RULL(0x06010801), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM1_CLEAR );
REG64( XBUS_IOPPE_CSCR_OR                                      , RULL(0x06010802), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM2_OR  );

REG64( XBUS_IOPPE_CSDR                                         , RULL(0x06010859), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RW   );

REG64( XBUS_PERV_DBG_INST1_COND_REG_1                          , RULL(0x060107C1), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_INST1_COND_REG_2                          , RULL(0x060107C2), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_INST1_COND_REG_3                          , RULL(0x060107C3), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_INST2_COND_REG_1                          , RULL(0x060107C4), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_INST2_COND_REG_2                          , RULL(0x060107C5), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_INST2_COND_REG_3                          , RULL(0x060107C6), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_MODE_REG                                  , RULL(0x060107C0), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_TRACE_MODE_REG_2                          , RULL(0x060107CF), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_TRACE_REG_0                               , RULL(0x060107CD), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DBG_TRACE_REG_1                               , RULL(0x060107CE), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_DEBUG_TRACE_CONTROL                           , RULL(0x060107D0), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_CONFIG                                    , RULL(0x0601180A), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_CONFIG                                  , RULL(0x0601180A), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_CONTROL                                   , RULL(0x0601180B), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_CONTROL                                 , RULL(0x0601180B), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_DLL_STATUS                                , RULL(0x06011828), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_DLL_STATUS                              , RULL(0x06011828), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_ERR_INJ_LFSR                              , RULL(0x0601181B), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_ERR_INJ_LFSR                            , RULL(0x0601181B), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_FIR_ACTION0_REG                           , RULL(0x06011806), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_FIR_ACTION0_REG                         , RULL(0x06011806), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_FIR_ACTION1_REG                           , RULL(0x06011807), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_FIR_ACTION1_REG                         , RULL(0x06011807), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_LAT_MEASURE                               , RULL(0x0601180E), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_LAT_MEASURE                             , RULL(0x0601180E), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_LINK0_EDPL_STATUS                         , RULL(0x06011824), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_LINK0_EDPL_STATUS                       , RULL(0x06011824), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_LINK0_ERROR_STATUS                        , RULL(0x06011816), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_LINK0_ERROR_STATUS                      , RULL(0x06011816), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_LINK0_INFO                                , RULL(0x06011814), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_LINK0_INFO                              , RULL(0x06011814), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_LINK0_QUALITY                             , RULL(0x06011826), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_LINK0_QUALITY                           , RULL(0x06011826), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_LINK0_SYN_CAPTURE                         , RULL(0x06011822), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_LINK0_SYN_CAPTURE                       , RULL(0x06011822), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_LINK1_EDPL_STATUS                         , RULL(0x06011825), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_LINK1_EDPL_STATUS                       , RULL(0x06011825), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_LINK1_ERROR_STATUS                        , RULL(0x06011817), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_LINK1_ERROR_STATUS                      , RULL(0x06011817), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_LINK1_INFO                                , RULL(0x06011815), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_LINK1_INFO                              , RULL(0x06011815), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_LINK1_QUALITY                             , RULL(0x06011827), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_LINK1_QUALITY                           , RULL(0x06011827), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_LINK1_SYN_CAPTURE                         , RULL(0x06011823), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_LINK1_SYN_CAPTURE                       , RULL(0x06011823), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_PERF_COUNTERS_0                           , RULL(0x0601181E), SH_UNT_XBUS     ,
       SH_ACS_SCOM_WCLRREG );
REG64( XBUS_0_LL0_IOEL_PERF_COUNTERS_0                         , RULL(0x0601181E), SH_UNT_XBUS_0   ,
       SH_ACS_SCOM_WCLRREG );

REG64( XBUS_LL0_IOEL_PERF_COUNTERS_1                           , RULL(0x0601181F), SH_UNT_XBUS     ,
       SH_ACS_SCOM_WCLRREG );
REG64( XBUS_0_LL0_IOEL_PERF_COUNTERS_1                         , RULL(0x0601181F), SH_UNT_XBUS_0   ,
       SH_ACS_SCOM_WCLRREG );

REG64( XBUS_LL0_IOEL_PERF_COUNT_LSB_0                          , RULL(0x06011820), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_PERF_COUNT_LSB_0                        , RULL(0x06011820), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_PERF_COUNT_LSB_1                          , RULL(0x06011821), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_0_LL0_IOEL_PERF_COUNT_LSB_1                        , RULL(0x06011821), SH_UNT_XBUS_0   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL0_IOEL_PERF_SEL_CONFIG                           , RULL(0x0601181D), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_PERF_SEL_CONFIG                         , RULL(0x0601181D), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_PERF_TRACE_CONFIG                         , RULL(0x0601181C), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_PERF_TRACE_CONFIG                       , RULL(0x0601181C), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_REPLAY_THRESHOLD                          , RULL(0x06011818), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_REPLAY_THRESHOLD                        , RULL(0x06011818), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_IOEL_SEC_CONFIG                                , RULL(0x0601180D), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_IOEL_SEC_CONFIG                              , RULL(0x0601180D), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL0_IOEL_SL_ECC_THRESHOLD                          , RULL(0x06011819), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_0_LL0_IOEL_SL_ECC_THRESHOLD                        , RULL(0x06011819), SH_UNT_XBUS_0   , SH_ACS_SCOM      );

REG64( XBUS_LL0_LL0_LL0_IOEL_FIR_MASK_REG                      , RULL(0x06011803), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_LL0_LL0_LL0_IOEL_FIR_MASK_REG_AND                  , RULL(0x06011804), SH_UNT_XBUS     , SH_ACS_SCOM1_AND );
REG64( XBUS_LL0_LL0_LL0_IOEL_FIR_MASK_REG_OR                   , RULL(0x06011805), SH_UNT_XBUS     , SH_ACS_SCOM2_OR  );
REG64( XBUS_0_LL0_LL0_LL0_IOEL_FIR_MASK_REG                    , RULL(0x06011803), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_LL0_LL0_IOEL_FIR_MASK_REG_AND                , RULL(0x06011804), SH_UNT_XBUS_0   , SH_ACS_SCOM1_AND );
REG64( XBUS_0_LL0_LL0_LL0_IOEL_FIR_MASK_REG_OR                 , RULL(0x06011805), SH_UNT_XBUS_0   , SH_ACS_SCOM2_OR  );

REG64( XBUS_LL0_LL0_LL0_IOEL_FIR_REG                           , RULL(0x06011800), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_LL0_LL0_LL0_IOEL_FIR_REG_AND                       , RULL(0x06011801), SH_UNT_XBUS     , SH_ACS_SCOM1_AND );
REG64( XBUS_LL0_LL0_LL0_IOEL_FIR_REG_OR                        , RULL(0x06011802), SH_UNT_XBUS     , SH_ACS_SCOM2_OR  );
REG64( XBUS_0_LL0_LL0_LL0_IOEL_FIR_REG                         , RULL(0x06011800), SH_UNT_XBUS_0   , SH_ACS_SCOM_RW   );
REG64( XBUS_0_LL0_LL0_LL0_IOEL_FIR_REG_AND                     , RULL(0x06011801), SH_UNT_XBUS_0   , SH_ACS_SCOM1_AND );
REG64( XBUS_0_LL0_LL0_LL0_IOEL_FIR_REG_OR                      , RULL(0x06011802), SH_UNT_XBUS_0   , SH_ACS_SCOM2_OR  );

REG64( XBUS_LL1_IOEL_CONFIG                                    , RULL(0x06010C0A), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_CONFIG                                  , RULL(0x06011C0A), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_CONTROL                                   , RULL(0x06010C0B), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_CONTROL                                 , RULL(0x06011C0B), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_DLL_STATUS                                , RULL(0x06010C28), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_DLL_STATUS                              , RULL(0x06011C28), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_ERR_INJ_LFSR                              , RULL(0x06010C1B), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_ERR_INJ_LFSR                            , RULL(0x06011C1B), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_FIR_ACTION0_REG                           , RULL(0x06010C06), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_FIR_ACTION0_REG                         , RULL(0x06011C06), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_FIR_ACTION1_REG                           , RULL(0x06010C07), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_FIR_ACTION1_REG                         , RULL(0x06011C07), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_LAT_MEASURE                               , RULL(0x06010C0E), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_LAT_MEASURE                             , RULL(0x06011C0E), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_LINK0_EDPL_STATUS                         , RULL(0x06010C24), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_LINK0_EDPL_STATUS                       , RULL(0x06011C24), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_LINK0_ERROR_STATUS                        , RULL(0x06010C16), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_LINK0_ERROR_STATUS                      , RULL(0x06011C16), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_LINK0_INFO                                , RULL(0x06010C14), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_LINK0_INFO                              , RULL(0x06011C14), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_LINK0_QUALITY                             , RULL(0x06010C26), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_LINK0_QUALITY                           , RULL(0x06011C26), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_LINK0_SYN_CAPTURE                         , RULL(0x06010C22), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_LINK0_SYN_CAPTURE                       , RULL(0x06011C22), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_LINK1_EDPL_STATUS                         , RULL(0x06010C25), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_LINK1_EDPL_STATUS                       , RULL(0x06011C25), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_LINK1_ERROR_STATUS                        , RULL(0x06010C17), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_LINK1_ERROR_STATUS                      , RULL(0x06011C17), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_LINK1_INFO                                , RULL(0x06010C15), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_LINK1_INFO                              , RULL(0x06011C15), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_LINK1_QUALITY                             , RULL(0x06010C27), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_LINK1_QUALITY                           , RULL(0x06011C27), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_LINK1_SYN_CAPTURE                         , RULL(0x06010C23), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_LINK1_SYN_CAPTURE                       , RULL(0x06011C23), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_PERF_COUNTERS_0                           , RULL(0x06010C1E), SH_UNT_XBUS     ,
       SH_ACS_SCOM_WCLRREG );
REG64( XBUS_1_LL1_IOEL_PERF_COUNTERS_0                         , RULL(0x06011C1E), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM_WCLRREG );

REG64( XBUS_LL1_IOEL_PERF_COUNTERS_1                           , RULL(0x06010C1F), SH_UNT_XBUS     ,
       SH_ACS_SCOM_WCLRREG );
REG64( XBUS_1_LL1_IOEL_PERF_COUNTERS_1                         , RULL(0x06011C1F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM_WCLRREG );

REG64( XBUS_LL1_IOEL_PERF_COUNT_LSB_0                          , RULL(0x06010C20), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_PERF_COUNT_LSB_0                        , RULL(0x06011C20), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_PERF_COUNT_LSB_1                          , RULL(0x06010C21), SH_UNT_XBUS     , SH_ACS_SCOM_RO   );
REG64( XBUS_1_LL1_IOEL_PERF_COUNT_LSB_1                        , RULL(0x06011C21), SH_UNT_XBUS_1   , SH_ACS_SCOM_RO   );

REG64( XBUS_LL1_IOEL_PERF_SEL_CONFIG                           , RULL(0x06010C1D), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_PERF_SEL_CONFIG                         , RULL(0x06011C1D), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_PERF_TRACE_CONFIG                         , RULL(0x06010C1C), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_PERF_TRACE_CONFIG                       , RULL(0x06011C1C), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_REPLAY_THRESHOLD                          , RULL(0x06010C18), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_REPLAY_THRESHOLD                        , RULL(0x06011C18), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_IOEL_SEC_CONFIG                                , RULL(0x06010C0D), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_IOEL_SEC_CONFIG                              , RULL(0x06011C0D), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );

REG64( XBUS_LL1_IOEL_SL_ECC_THRESHOLD                          , RULL(0x06010C19), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_LL1_IOEL_SL_ECC_THRESHOLD                        , RULL(0x06011C19), SH_UNT_XBUS_1   , SH_ACS_SCOM      );

REG64( XBUS_LL1_LL1_LL1_IOEL_FIR_MASK_REG                      , RULL(0x06010C03), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_LL1_LL1_IOEL_FIR_MASK_REG                    , RULL(0x06011C03), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );
REG64( XBUS_LL1_LL1_LL1_IOEL_FIR_MASK_REG_AND                  , RULL(0x06010C04), SH_UNT_XBUS     , SH_ACS_SCOM1_AND );
REG64( XBUS_1_LL1_LL1_LL1_IOEL_FIR_MASK_REG_AND                , RULL(0x06011C04), SH_UNT_XBUS_1   , SH_ACS_SCOM1_AND );
REG64( XBUS_LL1_LL1_LL1_IOEL_FIR_MASK_REG_OR                   , RULL(0x06010C05), SH_UNT_XBUS     , SH_ACS_SCOM2_OR  );
REG64( XBUS_1_LL1_LL1_LL1_IOEL_FIR_MASK_REG_OR                 , RULL(0x06011C05), SH_UNT_XBUS_1   , SH_ACS_SCOM2_OR  );

REG64( XBUS_LL1_LL1_LL1_IOEL_FIR_REG                           , RULL(0x06010C00), SH_UNT_XBUS     , SH_ACS_SCOM_RW   );
REG64( XBUS_1_LL1_LL1_LL1_IOEL_FIR_REG                         , RULL(0x06011C00), SH_UNT_XBUS_1   , SH_ACS_SCOM_RW   );
REG64( XBUS_LL1_LL1_LL1_IOEL_FIR_REG_AND                       , RULL(0x06010C01), SH_UNT_XBUS     , SH_ACS_SCOM1_AND );
REG64( XBUS_1_LL1_LL1_LL1_IOEL_FIR_REG_AND                     , RULL(0x06011C01), SH_UNT_XBUS_1   , SH_ACS_SCOM1_AND );
REG64( XBUS_LL1_LL1_LL1_IOEL_FIR_REG_OR                        , RULL(0x06010C02), SH_UNT_XBUS     , SH_ACS_SCOM2_OR  );
REG64( XBUS_1_LL1_LL1_LL1_IOEL_FIR_REG_OR                      , RULL(0x06011C02), SH_UNT_XBUS_1   , SH_ACS_SCOM2_OR  );

REG64( XBUS_2_LL2_IOEL_CONFIG                                  , RULL(0x0601200A), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_CONTROL                                 , RULL(0x0601200B), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_DLL_STATUS                              , RULL(0x06012028), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_ERR_INJ_LFSR                            , RULL(0x0601201B), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_FIR_ACTION0_REG                         , RULL(0x06012006), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_FIR_ACTION1_REG                         , RULL(0x06012007), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_LAT_MEASURE                             , RULL(0x0601200E), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_LINK0_EDPL_STATUS                       , RULL(0x06012024), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_LINK0_ERROR_STATUS                      , RULL(0x06012016), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_LINK0_INFO                              , RULL(0x06012014), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_LINK0_QUALITY                           , RULL(0x06012026), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_LINK0_SYN_CAPTURE                       , RULL(0x06012022), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_LINK1_EDPL_STATUS                       , RULL(0x06012025), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_LINK1_ERROR_STATUS                      , RULL(0x06012017), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_LINK1_INFO                              , RULL(0x06012015), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_LINK1_QUALITY                           , RULL(0x06012027), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_LINK1_SYN_CAPTURE                       , RULL(0x06012023), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_PERF_COUNTERS_0                         , RULL(0x0601201E), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM_WCLRREG );

REG64( XBUS_2_LL2_IOEL_PERF_COUNTERS_1                         , RULL(0x0601201F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM_WCLRREG );

REG64( XBUS_2_LL2_IOEL_PERF_COUNT_LSB_0                        , RULL(0x06012020), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_PERF_COUNT_LSB_1                        , RULL(0x06012021), SH_UNT_XBUS_2   , SH_ACS_SCOM_RO   );

REG64( XBUS_2_LL2_IOEL_PERF_SEL_CONFIG                         , RULL(0x0601201D), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_PERF_TRACE_CONFIG                       , RULL(0x0601201C), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_REPLAY_THRESHOLD                        , RULL(0x06012018), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_IOEL_SEC_CONFIG                              , RULL(0x0601200D), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );

REG64( XBUS_2_LL2_IOEL_SL_ECC_THRESHOLD                        , RULL(0x06012019), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_2_LL2_LL2_LL2_IOEL_FIR_MASK_REG                    , RULL(0x06012003), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );
REG64( XBUS_2_LL2_LL2_LL2_IOEL_FIR_MASK_REG_AND                , RULL(0x06012004), SH_UNT_XBUS_2   , SH_ACS_SCOM1_AND );
REG64( XBUS_2_LL2_LL2_LL2_IOEL_FIR_MASK_REG_OR                 , RULL(0x06012005), SH_UNT_XBUS_2   , SH_ACS_SCOM2_OR  );

REG64( XBUS_2_LL2_LL2_LL2_IOEL_FIR_REG                         , RULL(0x06012000), SH_UNT_XBUS_2   , SH_ACS_SCOM_RW   );
REG64( XBUS_2_LL2_LL2_LL2_IOEL_FIR_REG_AND                     , RULL(0x06012001), SH_UNT_XBUS_2   , SH_ACS_SCOM1_AND );
REG64( XBUS_2_LL2_LL2_LL2_IOEL_FIR_REG_OR                      , RULL(0x06012002), SH_UNT_XBUS_2   , SH_ACS_SCOM2_OR  );

REG64( XBUS_IOPPE_MIB_XIICAC                                   , RULL(0x06010853), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RO   );

REG64( XBUS_IOPPE_MIB_XIMEM                                    , RULL(0x06010851), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RO   );

REG64( XBUS_IOPPE_MIB_XISGB                                    , RULL(0x06010852), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RO   );

REG64( XBUS_IOPPE_PPE_XIDBGPRO                                 , RULL(0x0601084F), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM      );

REG64( XBUS_IOPPE_PPE_XIRAMDBG                                 , RULL(0x0601084D), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM      );

REG64( XBUS_IOPPE_PPE_XIRAMEDR                                 , RULL(0x0601084E), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM      );

REG64( XBUS_IOPPE_PPE_XIRAMGA                                  , RULL(0x0601084C), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_WO   );

REG64( XBUS_IOPPE_PPE_XIRAMRA                                  , RULL(0x0601084B), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_WO   );

REG64( XBUS_IOPPE_PPE_XIXCR                                    , RULL(0x0601084A), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_WO   );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003000D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x8003000D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x8003000D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003080D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x8003080D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x8003080D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003100D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x8003100D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x8003100D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C00D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C00D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C00D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C80D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C80D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C80D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000800D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x8000800D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x8000800D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000880D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x8000880D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x8000880D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000900D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x8000900D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x8000900D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000980D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x8000980D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x8000980D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_FIR_PL                      , RULL(0x8002080D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x8002080D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x8002080D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003000F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x8003000F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x8003000F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003080F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x8003080F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x8003080F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003100F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x8003100F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x8003100F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C00F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C00F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C00F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C80F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C80F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C80F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002680F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002700F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002780F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000800F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x8000800F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x8000800F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000880F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x8000880F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x8000880F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000900F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x8000900F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x8000900F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000980F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x8000980F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x8000980F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_FIR_PL                      , RULL(0x8002080F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x8002080F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x8002080F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003000E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x8003000E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x8003000E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003080E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x8003080E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x8003080E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003100E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x8003100E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x8003100E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C00E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C00E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C00E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C80E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C80E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C80E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000800E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x8000800E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x8000800E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000880E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x8000880E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x8000880E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000900E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x8000900E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x8000900E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000980E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x8000980E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x8000980E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_FIR_PL                      , RULL(0x8002080E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x8002080E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x8002080E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003001006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003081006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003101006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002201006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C01006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002281006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C81006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002301006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002681006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002701006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002781006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000801006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000881006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000901006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000981006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A01006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A81006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B01006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B81006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C01006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002101006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_FIR_PL                      , RULL(0x8002081006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002001006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003000B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x8003000B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x8003000B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003080B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x8003080B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x8003080B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003100B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x8003100B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x8003100B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C00B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C00B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C00B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C80B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C80B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C80B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002680B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002700B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002780B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000800B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x8000800B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x8000800B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000880B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x8000880B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x8000880B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000900B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x8000900B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x8000900B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000980B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x8000980B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x8000980B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_FIR_PL                      , RULL(0x8002080B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x8002080B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x8002080B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003000906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003080906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003100906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C00906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C80906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000800906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000880906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000900906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000980906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_FIR_PL                      , RULL(0x8002080906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003000C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x8003000C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x8003000C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003080C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x8003080C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x8003080C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003100C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x8003100C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x8003100C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C00C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C00C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C00C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C80C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C80C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C80C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002680C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002700C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002780C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000800C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x8000800C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x8000800C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000880C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x8000880C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x8000880C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000900C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x8000900C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x8000900C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000980C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x8000980C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x8000980C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_FIR_PL                      , RULL(0x8002080C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x8002080C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x8002080C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003000A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x8003000A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x8003000A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002480A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003080A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x8003080A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x8003080A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002500A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003100A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x8003100A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x8003100A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002580A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002600A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002400A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C00A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C00A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C00A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C80A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C80A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C80A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002680A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002700A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002780A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000800A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x8000800A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x8000800A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000880A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x8000880A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x8000880A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000900A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x8000900A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x8000900A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000980A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x8000980A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x8000980A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A00A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A80A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B00A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B80A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C00A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_FIR_PL                      , RULL(0x8002080A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x8002080A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x8002080A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003000706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003080706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003100706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C00706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C80706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000800706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000880706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000900706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000980706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_FIR_PL                      , RULL(0x8002080706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003001106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002481106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003081106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002501106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003101106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002581106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002601106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002401106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002201106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C01106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002281106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C81106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002301106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002681106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002701106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002781106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000081106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000801106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000101106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000881106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000181106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000901106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000201106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000981106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000281106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A01106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000301106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A81106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000381106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B01106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000401106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B81106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C01106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000001106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002181106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002101106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_FIR_PL                      , RULL(0x8002081106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x800208110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x800208110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002001106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003000606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003080606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003100606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C00606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C80606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000800606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000880606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000900606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000980606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_FIR_PL                      , RULL(0x8002080606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x800208060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x800208060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003000806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003080806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003100806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C00806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C80806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000800806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000880806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000900806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000980806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_FIR_PL                      , RULL(0x8002080806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x800208080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x800208080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003000406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003080406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003100406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C00406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C80406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002680406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002700406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002780406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000800406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000880406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000900406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000980406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_FIR_PL                      , RULL(0x8002080406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x800208040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x800208040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003000206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003080206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003100206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C00206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C80206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002680206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002700206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002780206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000800206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000880206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000900206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000980206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_FIR_PL                      , RULL(0x8002080206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x800208020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x800208020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003000506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003080506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003100506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C00506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C80506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002680506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002700506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002780506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000800506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000880506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000900506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000980506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_FIR_PL                      , RULL(0x8002080506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x800208050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x800208050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003000306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003080306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003100306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C00306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C80306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002680306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002700306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002780306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000800306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000880306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000900306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000980306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_FIR_PL                      , RULL(0x8002080306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x800208030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x800208030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL1_E_PL              , RULL(0x8003000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL1_E_PL            , RULL(0x800300000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL1_E_PL            , RULL(0x800300000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL2_EO_PL           , RULL(0x800248000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL2_EO_PL           , RULL(0x800248000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL2_E_PL              , RULL(0x8003080006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL2_E_PL            , RULL(0x800308000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL2_E_PL            , RULL(0x800308000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL3_EO_PL           , RULL(0x800250000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL3_EO_PL           , RULL(0x800250000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL3_E_PL              , RULL(0x8003100006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL3_E_PL            , RULL(0x800310000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL3_E_PL            , RULL(0x800310000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL4_EO_PL           , RULL(0x800258000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL4_EO_PL           , RULL(0x800258000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL5_EO_PL           , RULL(0x800260000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTL5_EO_PL           , RULL(0x800260000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_MODE1_EO_PL             , RULL(0x8002200006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_MODE1_EO_PL           , RULL(0x800220000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_MODE1_EO_PL           , RULL(0x800220000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_MODE1_E_PL              , RULL(0x8002C00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_MODE1_E_PL            , RULL(0x8002C0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_MODE1_E_PL            , RULL(0x8002C0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_MODE2_EO_PL             , RULL(0x8002280006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_MODE2_EO_PL           , RULL(0x800228000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_MODE2_EO_PL           , RULL(0x800228000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_MODE2_E_PL              , RULL(0x8002C80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_MODE2_E_PL            , RULL(0x8002C8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_MODE2_E_PL            , RULL(0x8002C8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_MODE3_EO_PL             , RULL(0x8002300006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_MODE3_EO_PL           , RULL(0x800230000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_MODE3_EO_PL           , RULL(0x800230000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_STAT1_EO_PL             , RULL(0x8002680006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_STAT1_EO_PL           , RULL(0x800268000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_STAT1_EO_PL           , RULL(0x800268000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_STAT2_EO_PL             , RULL(0x8002700006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_STAT2_EO_PL           , RULL(0x800270000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_STAT2_EO_PL           , RULL(0x800270000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_BIT_STAT3_EO_PL             , RULL(0x8002780006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_BIT_STAT3_EO_PL           , RULL(0x800278000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_BIT_STAT3_EO_PL           , RULL(0x800278000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL1_EO_PL           , RULL(0x800008000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL1_EO_PL           , RULL(0x800008000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL1_E_PL              , RULL(0x8000800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL1_E_PL            , RULL(0x800080000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL1_E_PL            , RULL(0x800080000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL2_EO_PL           , RULL(0x800010000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL2_EO_PL           , RULL(0x800010000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL2_E_PL              , RULL(0x8000880006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL2_E_PL            , RULL(0x800088000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL2_E_PL            , RULL(0x800088000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL3_EO_PL           , RULL(0x800018000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL3_EO_PL           , RULL(0x800018000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL3_E_PL              , RULL(0x8000900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL3_E_PL            , RULL(0x800090000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL3_E_PL            , RULL(0x800090000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL4_EO_PL           , RULL(0x800020000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL4_EO_PL           , RULL(0x800020000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL4_E_PL              , RULL(0x8000980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL4_E_PL            , RULL(0x800098000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL4_E_PL            , RULL(0x800098000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL5_EO_PL           , RULL(0x800028000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL5_EO_PL           , RULL(0x800028000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL6_EO_PL           , RULL(0x800030000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL6_EO_PL           , RULL(0x800030000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL7_EO_PL           , RULL(0x800038000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL7_EO_PL           , RULL(0x800038000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL8_EO_PL           , RULL(0x800040000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL8_EO_PL           , RULL(0x800040000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_FIR_MASK_PL                 , RULL(0x8002100006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_FIR_MASK_PL               , RULL(0x800210000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_FIR_MASK_PL               , RULL(0x800210000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_FIR_PL                      , RULL(0x8002080006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_FIR_PL                    , RULL(0x800208000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_FIR_PL                    , RULL(0x800208000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE4_RX_SPARE_MODE_PL               , RULL(0x8002000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE4_RX_SPARE_MODE_PL             , RULL(0x800200000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE4_RX_SPARE_MODE_PL             , RULL(0x800200000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL1_E_PL              , RULL(0x8003000106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL1_E_PL            , RULL(0x800300010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL1_E_PL            , RULL(0x800300010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL2_EO_PL             , RULL(0x8002480106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL2_EO_PL           , RULL(0x800248010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL2_EO_PL           , RULL(0x800248010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL2_E_PL              , RULL(0x8003080106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL2_E_PL            , RULL(0x800308010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL2_E_PL            , RULL(0x800308010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL3_EO_PL             , RULL(0x8002500106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL3_EO_PL           , RULL(0x800250010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL3_EO_PL           , RULL(0x800250010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL3_E_PL              , RULL(0x8003100106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL3_E_PL            , RULL(0x800310010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL3_E_PL            , RULL(0x800310010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL4_EO_PL             , RULL(0x8002580106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL4_EO_PL           , RULL(0x800258010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL4_EO_PL           , RULL(0x800258010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL5_EO_PL             , RULL(0x8002600106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL5_EO_PL           , RULL(0x800260010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTL5_EO_PL           , RULL(0x800260010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002400106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_MODE1_EO_PL             , RULL(0x8002200106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_MODE1_EO_PL           , RULL(0x800220010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_MODE1_EO_PL           , RULL(0x800220010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_MODE1_E_PL              , RULL(0x8002C00106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_MODE1_E_PL            , RULL(0x8002C0010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_MODE1_E_PL            , RULL(0x8002C0010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_MODE2_EO_PL             , RULL(0x8002280106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_MODE2_EO_PL           , RULL(0x800228010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_MODE2_EO_PL           , RULL(0x800228010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_MODE2_E_PL              , RULL(0x8002C80106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_MODE2_E_PL            , RULL(0x8002C8010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_MODE2_E_PL            , RULL(0x8002C8010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_MODE3_EO_PL             , RULL(0x8002300106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_MODE3_EO_PL           , RULL(0x800230010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_MODE3_EO_PL           , RULL(0x800230010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_STAT1_EO_PL             , RULL(0x8002680106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_STAT1_EO_PL           , RULL(0x800268010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_STAT1_EO_PL           , RULL(0x800268010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_STAT2_EO_PL             , RULL(0x8002700106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_STAT2_EO_PL           , RULL(0x800270010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_STAT2_EO_PL           , RULL(0x800270010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_BIT_STAT3_EO_PL             , RULL(0x8002780106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_BIT_STAT3_EO_PL           , RULL(0x800278010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_BIT_STAT3_EO_PL           , RULL(0x800278010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL1_EO_PL           , RULL(0x800008010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL1_EO_PL           , RULL(0x800008010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL1_E_PL              , RULL(0x8000800106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL1_E_PL            , RULL(0x800080010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL1_E_PL            , RULL(0x800080010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL2_EO_PL           , RULL(0x800010010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL2_EO_PL           , RULL(0x800010010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL2_E_PL              , RULL(0x8000880106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL2_E_PL            , RULL(0x800088010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL2_E_PL            , RULL(0x800088010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL3_EO_PL           , RULL(0x800018010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL3_EO_PL           , RULL(0x800018010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL3_E_PL              , RULL(0x8000900106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL3_E_PL            , RULL(0x800090010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL3_E_PL            , RULL(0x800090010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL4_EO_PL           , RULL(0x800020010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL4_EO_PL           , RULL(0x800020010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL4_E_PL              , RULL(0x8000980106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL4_E_PL            , RULL(0x800098010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL4_E_PL            , RULL(0x800098010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL5_EO_PL           , RULL(0x800028010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL5_EO_PL           , RULL(0x800028010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL5_E_PL              , RULL(0x8000A00106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL6_EO_PL           , RULL(0x800030010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL6_EO_PL           , RULL(0x800030010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL6_E_PL              , RULL(0x8000A80106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL7_EO_PL           , RULL(0x800038010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL7_EO_PL           , RULL(0x800038010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL7_E_PL              , RULL(0x8000B00106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL8_EO_PL           , RULL(0x800040010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL8_EO_PL           , RULL(0x800040010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL8_E_PL              , RULL(0x8000B80106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL9_E_PL              , RULL(0x8000C00106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_FIR_MASK_PL                 , RULL(0x8002100106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_FIR_MASK_PL               , RULL(0x800210010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_FIR_MASK_PL               , RULL(0x800210010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_FIR_PL                      , RULL(0x8002080106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_FIR_PL                    , RULL(0x800208010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_FIR_PL                    , RULL(0x800208010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RXPACKS3_SLICE5_RX_SPARE_MODE_PL               , RULL(0x8002000106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RXPACKS3_SLICE5_RX_SPARE_MODE_PL             , RULL(0x800200010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RXPACKS3_SLICE5_RX_SPARE_MODE_PL             , RULL(0x800200010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL10_EO_PG                            , RULL(0x8009200006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL11_EO_PG                            , RULL(0x8009280006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL12_EO_PG                            , RULL(0x8009300006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL13_EO_PG                            , RULL(0x8009380006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL14_EO_PG                            , RULL(0x8009400006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL15_EO_PG                            , RULL(0x8009480006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL15_EO_PG                          , RULL(0x800948000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL15_EO_PG                          , RULL(0x800948000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL1_EO_PG                             , RULL(0x8008D80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL1_E_PG                              , RULL(0x8009F00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL1_E_PG                            , RULL(0x8009F0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL1_E_PG                            , RULL(0x8009F0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL2_EO_PG                             , RULL(0x8008E00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL3_EO_PG                             , RULL(0x8008E80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL4_EO_PG                             , RULL(0x8008F00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL4_E_PG                              , RULL(0x8009F80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL4_E_PG                            , RULL(0x8009F8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL4_E_PG                            , RULL(0x8009F8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL5_EO_PG                             , RULL(0x8008F80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL6_EO_PG                             , RULL(0x8009000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL8_EO_PG                             , RULL(0x8009100006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTL9_EO_PG                             , RULL(0x8009180006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTLX10_E_PG                            , RULL(0x800A280006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTLX10_E_PG                          , RULL(0x800A28000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTLX10_E_PG                          , RULL(0x800A28000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTLX11_E_PG                            , RULL(0x800A300006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTLX11_E_PG                          , RULL(0x800A30000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTLX11_E_PG                          , RULL(0x800A30000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTLX5_E_PG                             , RULL(0x800A000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTLX5_E_PG                           , RULL(0x800A00000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTLX5_E_PG                           , RULL(0x800A00000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_CNTLX7_EO_PG                            , RULL(0x8009080006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE10_EO_PG                            , RULL(0x8008580006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE10_EO_PG                          , RULL(0x800858000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE10_EO_PG                          , RULL(0x800858000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE10_E_PG                             , RULL(0x8009D80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE10_E_PG                           , RULL(0x8009D8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE10_E_PG                           , RULL(0x8009D8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE11_EO_PG                            , RULL(0x8008600006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE11_EO_PG                          , RULL(0x800860000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE11_EO_PG                          , RULL(0x800860000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE11_E_PG                             , RULL(0x8009E00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE11_E_PG                           , RULL(0x8009E0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE11_E_PG                           , RULL(0x8009E0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE12_EO_PG                            , RULL(0x8008680006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE12_EO_PG                          , RULL(0x800868000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE12_EO_PG                          , RULL(0x800868000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE12_E_PG                             , RULL(0x8009E80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE12_E_PG                           , RULL(0x8009E8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE12_E_PG                           , RULL(0x8009E8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE13_EO_PG                            , RULL(0x8008700006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE13_EO_PG                          , RULL(0x800870000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE13_EO_PG                          , RULL(0x800870000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE14_EO_PG                            , RULL(0x8008780006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE14_EO_PG                          , RULL(0x800878000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE14_EO_PG                          , RULL(0x800878000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE15_EO_PG                            , RULL(0x8008800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE15_EO_PG                          , RULL(0x800880000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE15_EO_PG                          , RULL(0x800880000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE16_EO_PG                            , RULL(0x8008880006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE16_EO_PG                          , RULL(0x800888000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE16_EO_PG                          , RULL(0x800888000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE17_EO_PG                            , RULL(0x8008900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE17_EO_PG                          , RULL(0x800890000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE17_EO_PG                          , RULL(0x800890000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE18_EO_PG                            , RULL(0x8008980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE18_EO_PG                          , RULL(0x800898000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE18_EO_PG                          , RULL(0x800898000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE19_EO_PG                            , RULL(0x8008A00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE1_EO_PG                             , RULL(0x8008100006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE1_EO_PG                           , RULL(0x800810000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE1_EO_PG                           , RULL(0x800810000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE1_E_PG                              , RULL(0x8009900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE1_E_PG                            , RULL(0x800990000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE1_E_PG                            , RULL(0x800990000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE20_EO_PG                            , RULL(0x8008A80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE21_EO_PG                            , RULL(0x8008B00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE22_EO_PG                            , RULL(0x8008B80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE23_EO_PG                            , RULL(0x8008C00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE24_EO_PG                            , RULL(0x8008C80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE26_EO_PG                            , RULL(0x8009680006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE26_EO_PG                          , RULL(0x800968000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE26_EO_PG                          , RULL(0x800968000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE27_EO_PG                            , RULL(0x8009700006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE27_EO_PG                          , RULL(0x800970000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE27_EO_PG                          , RULL(0x800970000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE28_EO_PG                            , RULL(0x8009780006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE28_EO_PG                          , RULL(0x800978000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE28_EO_PG                          , RULL(0x800978000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE29_EO_PG                            , RULL(0x8008D00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE2_EO_PG                             , RULL(0x8008180006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE2_EO_PG                           , RULL(0x800818000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE2_EO_PG                           , RULL(0x800818000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE2_E_PG                              , RULL(0x8009980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE2_E_PG                            , RULL(0x800998000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE2_E_PG                            , RULL(0x800998000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE3_EO_PG                             , RULL(0x8008200006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE3_EO_PG                           , RULL(0x800820000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE3_EO_PG                           , RULL(0x800820000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE3_E_PG                              , RULL(0x8009A00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE3_E_PG                            , RULL(0x8009A0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE3_E_PG                            , RULL(0x8009A0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE4_EO_PG                             , RULL(0x8008280006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE4_EO_PG                           , RULL(0x800828000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE4_EO_PG                           , RULL(0x800828000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE4_E_PG                              , RULL(0x8009A80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE4_E_PG                            , RULL(0x8009A8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE4_E_PG                            , RULL(0x8009A8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE5_EO_PG                             , RULL(0x8008300006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE5_EO_PG                           , RULL(0x800830000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE5_EO_PG                           , RULL(0x800830000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE5_E_PG                              , RULL(0x8009B00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE5_E_PG                            , RULL(0x8009B0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE5_E_PG                            , RULL(0x8009B0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE6_EO_PG                             , RULL(0x8008380006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE6_EO_PG                           , RULL(0x800838000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE6_EO_PG                           , RULL(0x800838000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE6_E_PG                              , RULL(0x8009B80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE6_E_PG                            , RULL(0x8009B8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE6_E_PG                            , RULL(0x8009B8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE7_EO_PG                             , RULL(0x8008400006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE7_EO_PG                           , RULL(0x800840000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE7_EO_PG                           , RULL(0x800840000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE7_E_PG                              , RULL(0x8009C00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE7_E_PG                            , RULL(0x8009C0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE7_E_PG                            , RULL(0x8009C0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE8_EO_PG                             , RULL(0x8008480006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE8_EO_PG                           , RULL(0x800848000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE8_EO_PG                           , RULL(0x800848000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE8_E_PG                              , RULL(0x8009C80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE8_E_PG                            , RULL(0x8009C8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE8_E_PG                            , RULL(0x8009C8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE9_EO_PG                             , RULL(0x8008500006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE9_EO_PG                           , RULL(0x800850000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE9_EO_PG                           , RULL(0x800850000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_MODE9_E_PG                              , RULL(0x8009D00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_MODE9_E_PG                            , RULL(0x8009D0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_MODE9_E_PG                            , RULL(0x8009D0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT1_EO_PG                             , RULL(0x8009500006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT1_EO_PG                           , RULL(0x800950000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT1_EO_PG                           , RULL(0x800950000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT1_E_PG                              , RULL(0x800A380006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT1_E_PG                            , RULL(0x800A38000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT1_E_PG                            , RULL(0x800A38000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT2_EO_PG                             , RULL(0x8009580006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT2_EO_PG                           , RULL(0x800958000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT2_EO_PG                           , RULL(0x800958000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT2_E_PG                              , RULL(0x800A400006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT2_E_PG                            , RULL(0x800A40000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT2_E_PG                            , RULL(0x800A40000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT3_EO_PG                             , RULL(0x8009600006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT3_EO_PG                           , RULL(0x800960000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT3_EO_PG                           , RULL(0x800960000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT4_E_PG                              , RULL(0x800A500006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT4_E_PG                            , RULL(0x800A50000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT4_E_PG                            , RULL(0x800A50000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT5_E_PG                              , RULL(0x800A580006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT5_E_PG                            , RULL(0x800A58000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT5_E_PG                            , RULL(0x800A58000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STAT6_E_PG                              , RULL(0x800A600006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STAT6_E_PG                            , RULL(0x800A60000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STAT6_E_PG                            , RULL(0x800A60000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_CTL_STATX8_E_PG                             , RULL(0x800A680006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_CTL_STATX8_E_PG                           , RULL(0x800A68000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_CTL_STATX8_E_PG                           , RULL(0x800A68000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_CNTL1_E_PG                           , RULL(0x800BE80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_CNTL1_E_PG                         , RULL(0x800BE8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_CNTL1_E_PG                         , RULL(0x800BE8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_CNTLX1_EO_PG                         , RULL(0x800B880006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_SPARE_MODE_PG                        , RULL(0x800B800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT10_EO_PG                         , RULL(0x800BD80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT11_EO_PG                         , RULL(0x800BE00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT12_EO_PG                         , RULL(0x800BF00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT12_EO_PG                       , RULL(0x800BF0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT12_EO_PG                       , RULL(0x800BF0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT13_E_PG                          , RULL(0x800BF80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT13_E_PG                        , RULL(0x800BF8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT13_E_PG                        , RULL(0x800BF8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT1_EO_PG                          , RULL(0x800B900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT2_EO_PG                          , RULL(0x800B980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT3_EO_PG                          , RULL(0x800BA00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT4_EO_PG                          , RULL(0x800BA80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT5_EO_PG                          , RULL(0x800BB00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT6_EO_PG                          , RULL(0x800BB80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT7_EO_PG                          , RULL(0x800BC00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT8_EO_PG                          , RULL(0x800BC80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_DATASM_STAT9_EO_PG                          , RULL(0x800BD00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR1_ERROR_INJECT_PG                        , RULL(0x800A980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR1_MASK_PG                                , RULL(0x800A900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR1_MASK_PG                              , RULL(0x800A90000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR1_MASK_PG                              , RULL(0x800A90000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR1_PG                                     , RULL(0x800A880006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR1_PG                                   , RULL(0x800A88000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR1_PG                                   , RULL(0x800A88000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR2_ERROR_INJECT_PG                        , RULL(0x800B100006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR2_ERROR_INJECT_PG                      , RULL(0x800B10000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR2_ERROR_INJECT_PG                      , RULL(0x800B10000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR2_MASK_PG                                , RULL(0x800B080006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR2_MASK_PG                              , RULL(0x800B08000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR2_MASK_PG                              , RULL(0x800B08000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR2_PG                                     , RULL(0x800B000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR2_PG                                   , RULL(0x800B00000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR2_PG                                   , RULL(0x800B00000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR_TRAINING_MASK_PG                        , RULL(0x800AA80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR_TRAINING_MASK_PG                      , RULL(0x800AA8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR_TRAINING_MASK_PG                      , RULL(0x800AA8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_FIR_TRAINING_PG                             , RULL(0x800AA00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_FIR_TRAINING_PG                           , RULL(0x800AA0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_FIR_TRAINING_PG                           , RULL(0x800AA0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_CNTL2_EO_PG                           , RULL(0x800AE00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_CNTL2_EO_PG                         , RULL(0x800AE0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_CNTL2_EO_PG                         , RULL(0x800AE0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_CNTL3_EO_PG                           , RULL(0x800AE80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_CNTL3_EO_PG                         , RULL(0x800AE8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_CNTL3_EO_PG                         , RULL(0x800AE8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_CNTLX1_EO_PG                          , RULL(0x800AB00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_CNTLX1_EO_PG                        , RULL(0x800AB0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_CNTLX1_EO_PG                        , RULL(0x800AB0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_SPARE_MODE_PG                         , RULL(0x800A800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT10_E_PG                           , RULL(0x800B600006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT10_E_PG                         , RULL(0x800B60000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT10_E_PG                         , RULL(0x800B60000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT1_EO_PG                           , RULL(0x800AB80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT1_E_PG                            , RULL(0x800B180006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT1_E_PG                          , RULL(0x800B18000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT1_E_PG                          , RULL(0x800B18000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT2_EO_PG                           , RULL(0x800AC00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT2_E_PG                            , RULL(0x800B200006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT2_E_PG                          , RULL(0x800B20000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT2_E_PG                          , RULL(0x800B20000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT3_EO_PG                           , RULL(0x800AC80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT3_E_PG                            , RULL(0x800B280006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT3_E_PG                          , RULL(0x800B28000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT3_E_PG                          , RULL(0x800B28000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT4_EO_PG                           , RULL(0x800AD00006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT4_EO_PG                         , RULL(0x800AD0000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT4_EO_PG                         , RULL(0x800AD0000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT4_E_PG                            , RULL(0x800B300006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT4_E_PG                          , RULL(0x800B30000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT4_E_PG                          , RULL(0x800B30000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT5_EO_PG                           , RULL(0x800AD80006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT5_EO_PG                         , RULL(0x800AD8000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT5_EO_PG                         , RULL(0x800AD8000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT7_E_PG                            , RULL(0x800B480006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT7_E_PG                          , RULL(0x800B48000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT7_E_PG                          , RULL(0x800B48000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT8_E_PG                            , RULL(0x800B500006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT8_E_PG                          , RULL(0x800B50000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT8_E_PG                          , RULL(0x800B50000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_GLBSM_STAT9_E_PG                            , RULL(0x800B580006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_GLBSM_STAT9_E_PG                          , RULL(0x800B58000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_GLBSM_STAT9_E_PG                          , RULL(0x800B58000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_ID1_PG                                      , RULL(0x8008080006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_ID1_PG                                    , RULL(0x800808000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_ID1_PG                                    , RULL(0x800808000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_ID2_PG                                      , RULL(0x8009800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_ID2_PG                                    , RULL(0x800980000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_ID2_PG                                    , RULL(0x800980000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_RX_SPARE_MODE_PG                               , RULL(0x8008000006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_RX_SPARE_MODE_PG                             , RULL(0x800800000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_RX_SPARE_MODE_PG                             , RULL(0x800800000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE0_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE10_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x800388060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x800388060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x800390060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x800390060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x800398060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x800398060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE11_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x800388080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x800388080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x800390080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x800390080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x800398080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x800398080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE12_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x800388040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x800388040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x800390040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x800390040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x800398040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x800398040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE13_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x800388020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x800388020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x800390020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x800390020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x800398020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x800398020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE14_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x800388050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x800388050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x800390050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x800390050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x800398050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x800398050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE15_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x800388030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x800388030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x800390030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x800390030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x800398030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x800398030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE16_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x800388000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x800388000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x800390000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x800390000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x800398000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x800398000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE17_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380120601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380120601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE18_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388120601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388120601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390120601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390120601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398120601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398120601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380130601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380130601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE19_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388130601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388130601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390130601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390130601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398130601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398130601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE1_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380140601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380140601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE20_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388140601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388140601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390140601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390140601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398140601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398140601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380150601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380150601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE21_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388150601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388150601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390150601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390150601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398150601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398150601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380160601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380160601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE22_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388160601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388160601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390160601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390160601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398160601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398160601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003801706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380170601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380170601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE23_RX_WORK_STAT1_EO_PL                    , RULL(0x8003881706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388170601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388170601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL                    , RULL(0x8003901706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390170601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390170601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL                    , RULL(0x8003981706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398170601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398170601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE2_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003801006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE3_RX_WORK_STAT1_EO_PL                     , RULL(0x8003881006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL                     , RULL(0x8003901006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL                     , RULL(0x8003981006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE4_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE5_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE6_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003800A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE7_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x8003880A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x8003900A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x8003980A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003800706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE8_RX_WORK_STAT1_EO_PL                     , RULL(0x8003880706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL                     , RULL(0x8003900706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL                     , RULL(0x8003980706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003801106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE9_RX_WORK_STAT1_EO_PL                     , RULL(0x8003881106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x800388110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x800388110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL                     , RULL(0x8003901106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x800390110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x800390110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL                     , RULL(0x8003981106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX0_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x800398110601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX0_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x800398110601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003002106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003082106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003102106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002202106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C02106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002282106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C82106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002302106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002682106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002702106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002782106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000802106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000882106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000902106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000982106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002102106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_FIR_PL                      , RULL(0x8002082106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x800208210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x800208210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002002106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003002306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003082306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003102306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002202306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C02306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002282306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C82306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002302306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002682306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002702306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002782306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000802306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000882306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000902306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000982306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002102306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_FIR_PL                      , RULL(0x8002082306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x800208230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x800208230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002002306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003082006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003102006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002202006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002282006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002302006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002682006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002702006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002782006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000802006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000882006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000902006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000982006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002102006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_FIR_PL                      , RULL(0x8002082006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x800208200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x800208200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003002206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003082206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003102206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002202206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C02206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002282206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C82206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002302206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002682206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002702206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002782206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000802206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000882206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000902206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000982206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002102206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_FIR_PL                      , RULL(0x8002082206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS0_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002002206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003002706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003082706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003102706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002202706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C02706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002282706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C82706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002302706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002682706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002702706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002782706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000802706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000882706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000902706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000982706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002102706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_FIR_PL                      , RULL(0x8002082706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x800208270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x800208270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002002706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003002506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x800300250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800248250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003082506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x800308250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800250250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003102506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x800310250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800258250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x800260250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002202506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C02506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C0250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002282506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C82506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C8250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002302506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002682506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x800268250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002702506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800270250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002782506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800278250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000802506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x800080250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000882506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x800088250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000902506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x800090250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000982506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x800098250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002102506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_FIR_PL                      , RULL(0x8002082506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002002506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003002606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003082606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003102606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002202606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C02606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002282606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C82606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002302606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002682606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002702606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002782606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000802606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000882606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000902606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000982606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002102606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_FIR_PL                      , RULL(0x8002082606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x800208260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x800208260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002002606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003002406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003082406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003102406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002202406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C02406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002282406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C82406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002302406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002682406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002702406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002782406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000802406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000882406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000902406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000982406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002102406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_FIR_PL                      , RULL(0x8002082406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x800208240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x800208240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS1_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002002406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003002806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x800300280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800248280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003082806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x800308280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800250280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003102806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x800310280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800258280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x800260280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002202806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C02806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C0280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002282806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C82806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C8280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002302806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002682806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x800268280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002702806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800270280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002782806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800278280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000802806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x800080280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000882806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x800088280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000902806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x800090280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000982806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x800098280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002102806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_FIR_PL                      , RULL(0x8002082806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002002806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003002A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x8003002A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x8003002A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003082A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x8003082A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x8003082A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003102A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x8003102A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x8003102A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002202A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002202A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002202A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C02A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C02A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C02A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002282A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002282A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002282A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C82A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C82A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C82A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002302A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002302A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002302A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002682A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002682A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002682A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002702A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002702A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002702A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002782A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002782A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002782A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000802A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x8000802A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x8000802A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000882A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x8000882A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x8000882A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000902A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x8000902A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x8000902A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000982A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x8000982A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x8000982A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002102A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002102A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002102A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_FIR_PL                      , RULL(0x8002082A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x8002082A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x8002082A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002002A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002002A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002002A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003002906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x800300290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800248290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003082906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x800308290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800250290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003102906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x800310290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800258290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x800260290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002202906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C02906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C0290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002282906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C82906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C8290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002302906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002682906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x800268290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002702906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800270290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002782906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800278290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000802906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x800080290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000882906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x800088290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000902906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x800090290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000982906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x800098290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002102906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_FIR_PL                      , RULL(0x8002082906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x800208290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x800208290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002002906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003003106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x800300310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002483106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800248310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003083106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x800308310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002503106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800250310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003103106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x800310310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002583106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800258310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002603106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x800260310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002403106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002203106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C03106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C0310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002283106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C83106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C8310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002303106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002683106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x800268310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002703106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800270310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002783106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800278310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000083106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000803106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x800080310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000103106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000883106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x800088310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000183106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000903106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x800090310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000203106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000983106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x800098310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000283106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A03106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000303106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A83106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000383106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B03106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000403106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B83106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C03106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000003106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002183106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002103106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_FIR_PL                      , RULL(0x8002083106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x800208310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x800208310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS2_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002003106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL1_E_PL              , RULL(0x8003002E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x8003002E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL1_E_PL            , RULL(0x8003002E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL2_E_PL              , RULL(0x8003082E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x8003082E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL2_E_PL            , RULL(0x8003082E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL3_E_PL              , RULL(0x8003102E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x8003102E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL3_E_PL            , RULL(0x8003102E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002202E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002202E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002202E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_MODE1_E_PL              , RULL(0x8002C02E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C02E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_MODE1_E_PL            , RULL(0x8002C02E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002282E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002282E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002282E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_MODE2_E_PL              , RULL(0x8002C82E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C82E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_MODE2_E_PL            , RULL(0x8002C82E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002302E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002302E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002302E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL             , RULL(0x8002682E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002682E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_STAT1_EO_PL           , RULL(0x8002682E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002702E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002702E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002702E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002782E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002782E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002782E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL1_E_PL              , RULL(0x8000802E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x8000802E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL1_E_PL            , RULL(0x8000802E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL2_E_PL              , RULL(0x8000882E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x8000882E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL2_E_PL            , RULL(0x8000882E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL3_E_PL              , RULL(0x8000902E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x8000902E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL3_E_PL            , RULL(0x8000902E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL4_E_PL              , RULL(0x8000982E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x8000982E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL4_E_PL            , RULL(0x8000982E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002102E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002102E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002102E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_FIR_PL                      , RULL(0x8002082E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x8002082E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x8002082E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002002E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002002E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002002E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL1_E_PL              , RULL(0x8003002C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x8003002C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL1_E_PL            , RULL(0x8003002C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL2_E_PL              , RULL(0x8003082C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x8003082C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL2_E_PL            , RULL(0x8003082C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL3_E_PL              , RULL(0x8003102C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x8003102C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL3_E_PL            , RULL(0x8003102C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002202C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002202C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002202C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_MODE1_E_PL              , RULL(0x8002C02C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C02C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_MODE1_E_PL            , RULL(0x8002C02C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002282C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002282C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002282C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_MODE2_E_PL              , RULL(0x8002C82C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C82C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_MODE2_E_PL            , RULL(0x8002C82C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002302C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002302C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002302C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL             , RULL(0x8002682C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002682C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_STAT1_EO_PL           , RULL(0x8002682C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002702C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002702C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002702C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002782C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002782C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002782C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL1_E_PL              , RULL(0x8000802C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x8000802C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL1_E_PL            , RULL(0x8000802C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL2_E_PL              , RULL(0x8000882C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x8000882C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL2_E_PL            , RULL(0x8000882C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL3_E_PL              , RULL(0x8000902C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x8000902C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL3_E_PL            , RULL(0x8000902C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL4_E_PL              , RULL(0x8000982C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x8000982C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL4_E_PL            , RULL(0x8000982C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002102C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002102C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002102C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_FIR_PL                      , RULL(0x8002082C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x8002082C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x8002082C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002002C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002002C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002002C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL1_E_PL              , RULL(0x8003002D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x8003002D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL1_E_PL            , RULL(0x8003002D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL2_E_PL              , RULL(0x8003082D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x8003082D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL2_E_PL            , RULL(0x8003082D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL3_E_PL              , RULL(0x8003102D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x8003102D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL3_E_PL            , RULL(0x8003102D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002202D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002202D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002202D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_MODE1_E_PL              , RULL(0x8002C02D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C02D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_MODE1_E_PL            , RULL(0x8002C02D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002282D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002282D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002282D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_MODE2_E_PL              , RULL(0x8002C82D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C82D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_MODE2_E_PL            , RULL(0x8002C82D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002302D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002302D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002302D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL             , RULL(0x8002682D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002682D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_STAT1_EO_PL           , RULL(0x8002682D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002702D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002702D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002702D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002782D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002782D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002782D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL1_E_PL              , RULL(0x8000802D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x8000802D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL1_E_PL            , RULL(0x8000802D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL2_E_PL              , RULL(0x8000882D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x8000882D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL2_E_PL            , RULL(0x8000882D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL3_E_PL              , RULL(0x8000902D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x8000902D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL3_E_PL            , RULL(0x8000902D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL4_E_PL              , RULL(0x8000982D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x8000982D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL4_E_PL            , RULL(0x8000982D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002102D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002102D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002102D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_FIR_PL                      , RULL(0x8002082D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x8002082D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x8002082D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002002D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002002D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002002D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL1_E_PL              , RULL(0x8003002B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x8003002B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL1_E_PL            , RULL(0x8003002B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL2_E_PL              , RULL(0x8003082B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x8003082B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL2_E_PL            , RULL(0x8003082B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL3_E_PL              , RULL(0x8003102B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x8003102B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL3_E_PL            , RULL(0x8003102B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002202B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002202B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002202B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_MODE1_E_PL              , RULL(0x8002C02B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C02B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_MODE1_E_PL            , RULL(0x8002C02B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002282B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002282B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002282B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_MODE2_E_PL              , RULL(0x8002C82B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C82B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_MODE2_E_PL            , RULL(0x8002C82B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002302B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002302B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002302B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL             , RULL(0x8002682B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002682B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_STAT1_EO_PL           , RULL(0x8002682B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002702B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002702B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002702B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002782B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002782B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002782B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL1_E_PL              , RULL(0x8000802B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x8000802B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL1_E_PL            , RULL(0x8000802B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL2_E_PL              , RULL(0x8000882B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x8000882B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL2_E_PL            , RULL(0x8000882B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL3_E_PL              , RULL(0x8000902B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x8000902B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL3_E_PL            , RULL(0x8000902B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL4_E_PL              , RULL(0x8000982B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x8000982B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL4_E_PL            , RULL(0x8000982B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002102B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002102B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002102B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_FIR_PL                      , RULL(0x8002082B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x8002082B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x8002082B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002002B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002002B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002002B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL1_E_PL              , RULL(0x8003002F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL1_E_PL            , RULL(0x8003002F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL1_E_PL            , RULL(0x8003002F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL2_EO_PL             , RULL(0x8002482F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL2_EO_PL           , RULL(0x8002482F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL2_E_PL              , RULL(0x8003082F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL2_E_PL            , RULL(0x8003082F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL2_E_PL            , RULL(0x8003082F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL3_EO_PL             , RULL(0x8002502F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL3_EO_PL           , RULL(0x8002502F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL3_E_PL              , RULL(0x8003102F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL3_E_PL            , RULL(0x8003102F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL3_E_PL            , RULL(0x8003102F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL4_EO_PL             , RULL(0x8002582F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL4_EO_PL           , RULL(0x8002582F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL5_EO_PL             , RULL(0x8002602F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTL5_EO_PL           , RULL(0x8002602F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002402F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002402F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_MODE1_EO_PL             , RULL(0x8002202F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_MODE1_EO_PL           , RULL(0x8002202F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_MODE1_EO_PL           , RULL(0x8002202F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_MODE1_E_PL              , RULL(0x8002C02F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_MODE1_E_PL            , RULL(0x8002C02F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_MODE1_E_PL            , RULL(0x8002C02F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_MODE2_EO_PL             , RULL(0x8002282F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_MODE2_EO_PL           , RULL(0x8002282F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_MODE2_EO_PL           , RULL(0x8002282F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_MODE2_E_PL              , RULL(0x8002C82F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_MODE2_E_PL            , RULL(0x8002C82F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_MODE2_E_PL            , RULL(0x8002C82F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_MODE3_EO_PL             , RULL(0x8002302F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_MODE3_EO_PL           , RULL(0x8002302F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_MODE3_EO_PL           , RULL(0x8002302F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_STAT1_EO_PL             , RULL(0x8002682F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_STAT1_EO_PL           , RULL(0x8002682F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_STAT1_EO_PL           , RULL(0x8002682F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_STAT2_EO_PL             , RULL(0x8002702F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_STAT2_EO_PL           , RULL(0x8002702F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_STAT2_EO_PL           , RULL(0x8002702F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_BIT_STAT3_EO_PL             , RULL(0x8002782F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_BIT_STAT3_EO_PL           , RULL(0x8002782F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_BIT_STAT3_EO_PL           , RULL(0x8002782F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL1_EO_PL             , RULL(0x8000082F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL1_EO_PL           , RULL(0x8000082F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL1_E_PL              , RULL(0x8000802F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL1_E_PL            , RULL(0x8000802F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL1_E_PL            , RULL(0x8000802F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL2_EO_PL             , RULL(0x8000102F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL2_EO_PL           , RULL(0x8000102F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL2_E_PL              , RULL(0x8000882F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL2_E_PL            , RULL(0x8000882F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL2_E_PL            , RULL(0x8000882F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL3_EO_PL             , RULL(0x8000182F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL3_EO_PL           , RULL(0x8000182F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL3_E_PL              , RULL(0x8000902F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL3_E_PL            , RULL(0x8000902F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL3_E_PL            , RULL(0x8000902F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL4_EO_PL             , RULL(0x8000202F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL4_EO_PL           , RULL(0x8000202F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL4_E_PL              , RULL(0x8000982F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL4_E_PL            , RULL(0x8000982F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL4_E_PL            , RULL(0x8000982F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL5_EO_PL             , RULL(0x8000282F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL5_EO_PL           , RULL(0x8000282F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL5_E_PL              , RULL(0x8000A02F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL5_E_PL            , RULL(0x8000A02F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL6_EO_PL             , RULL(0x8000302F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL6_EO_PL           , RULL(0x8000302F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL6_E_PL              , RULL(0x8000A82F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL6_E_PL            , RULL(0x8000A82F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL7_EO_PL             , RULL(0x8000382F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL7_EO_PL           , RULL(0x8000382F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL7_E_PL              , RULL(0x8000B02F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL7_E_PL            , RULL(0x8000B02F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL8_EO_PL             , RULL(0x8000402F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL8_EO_PL           , RULL(0x8000402F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL8_E_PL              , RULL(0x8000B82F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL8_E_PL            , RULL(0x8000B82F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL9_E_PL              , RULL(0x8000C02F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DAC_CNTL9_E_PL            , RULL(0x8000C02F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000002F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000002F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002182F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002182F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_FIR_MASK_PL                 , RULL(0x8002102F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_FIR_MASK_PL               , RULL(0x8002102F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_FIR_MASK_PL               , RULL(0x8002102F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_FIR_PL                      , RULL(0x8002082F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_FIR_PL                    , RULL(0x8002082F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_FIR_PL                    , RULL(0x8002082F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE4_RX_SPARE_MODE_PL               , RULL(0x8002002F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE4_RX_SPARE_MODE_PL             , RULL(0x8002002F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE4_RX_SPARE_MODE_PL             , RULL(0x8002002F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL1_E_PL              , RULL(0x8003003006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL1_E_PL            , RULL(0x800300300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL1_E_PL            , RULL(0x800300300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL2_EO_PL             , RULL(0x8002483006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL2_EO_PL           , RULL(0x800248300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL2_EO_PL           , RULL(0x800248300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL2_E_PL              , RULL(0x8003083006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL2_E_PL            , RULL(0x800308300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL2_E_PL            , RULL(0x800308300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL3_EO_PL             , RULL(0x8002503006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL3_EO_PL           , RULL(0x800250300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL3_EO_PL           , RULL(0x800250300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL3_E_PL              , RULL(0x8003103006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL3_E_PL            , RULL(0x800310300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL3_E_PL            , RULL(0x800310300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL4_EO_PL             , RULL(0x8002583006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL4_EO_PL           , RULL(0x800258300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL4_EO_PL           , RULL(0x800258300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL5_EO_PL             , RULL(0x8002603006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL5_EO_PL           , RULL(0x800260300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTL5_EO_PL           , RULL(0x800260300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002403006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_CNTLX1_EO_PL          , RULL(0x800240300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_MODE1_EO_PL             , RULL(0x8002203006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_MODE1_EO_PL           , RULL(0x800220300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_MODE1_EO_PL           , RULL(0x800220300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_MODE1_E_PL              , RULL(0x8002C03006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_MODE1_E_PL            , RULL(0x8002C0300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_MODE1_E_PL            , RULL(0x8002C0300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_MODE2_EO_PL             , RULL(0x8002283006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_MODE2_EO_PL           , RULL(0x800228300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_MODE2_EO_PL           , RULL(0x800228300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_MODE2_E_PL              , RULL(0x8002C83006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_MODE2_E_PL            , RULL(0x8002C8300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_MODE2_E_PL            , RULL(0x8002C8300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_MODE3_EO_PL             , RULL(0x8002303006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_MODE3_EO_PL           , RULL(0x800230300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_MODE3_EO_PL           , RULL(0x800230300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_STAT1_EO_PL             , RULL(0x8002683006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_STAT1_EO_PL           , RULL(0x800268300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_STAT1_EO_PL           , RULL(0x800268300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_STAT2_EO_PL             , RULL(0x8002703006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_STAT2_EO_PL           , RULL(0x800270300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_STAT2_EO_PL           , RULL(0x800270300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_BIT_STAT3_EO_PL             , RULL(0x8002783006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_BIT_STAT3_EO_PL           , RULL(0x800278300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_BIT_STAT3_EO_PL           , RULL(0x800278300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL1_EO_PL             , RULL(0x8000083006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL1_EO_PL           , RULL(0x800008300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL1_EO_PL           , RULL(0x800008300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL1_E_PL              , RULL(0x8000803006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL1_E_PL            , RULL(0x800080300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL1_E_PL            , RULL(0x800080300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL2_EO_PL             , RULL(0x8000103006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL2_EO_PL           , RULL(0x800010300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL2_EO_PL           , RULL(0x800010300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL2_E_PL              , RULL(0x8000883006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL2_E_PL            , RULL(0x800088300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL2_E_PL            , RULL(0x800088300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL3_EO_PL             , RULL(0x8000183006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL3_EO_PL           , RULL(0x800018300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL3_EO_PL           , RULL(0x800018300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL3_E_PL              , RULL(0x8000903006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL3_E_PL            , RULL(0x800090300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL3_E_PL            , RULL(0x800090300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL4_EO_PL             , RULL(0x8000203006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL4_EO_PL           , RULL(0x800020300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL4_EO_PL           , RULL(0x800020300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL4_E_PL              , RULL(0x8000983006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL4_E_PL            , RULL(0x800098300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL4_E_PL            , RULL(0x800098300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL5_EO_PL             , RULL(0x8000283006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL5_EO_PL           , RULL(0x800028300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL5_EO_PL           , RULL(0x800028300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL5_E_PL              , RULL(0x8000A03006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL5_E_PL            , RULL(0x8000A0300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL6_EO_PL             , RULL(0x8000303006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL6_EO_PL           , RULL(0x800030300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL6_EO_PL           , RULL(0x800030300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL6_E_PL              , RULL(0x8000A83006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL6_E_PL            , RULL(0x8000A8300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL7_EO_PL             , RULL(0x8000383006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL7_EO_PL           , RULL(0x800038300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL7_EO_PL           , RULL(0x800038300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL7_E_PL              , RULL(0x8000B03006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL7_E_PL            , RULL(0x8000B0300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL8_EO_PL             , RULL(0x8000403006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL8_EO_PL           , RULL(0x800040300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL8_EO_PL           , RULL(0x800040300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL8_E_PL              , RULL(0x8000B83006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL8_E_PL            , RULL(0x8000B8300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL9_E_PL              , RULL(0x8000C03006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DAC_CNTL9_E_PL            , RULL(0x8000C0300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000003006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002183006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_FIR_MASK_PL                 , RULL(0x8002103006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_FIR_MASK_PL               , RULL(0x800210300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_FIR_MASK_PL               , RULL(0x800210300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_FIR_PL                      , RULL(0x8002083006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_FIR_PL                    , RULL(0x800208300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_FIR_PL                    , RULL(0x800208300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RXPACKS3_SLICE5_RX_SPARE_MODE_PL               , RULL(0x8002003006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RXPACKS3_SLICE5_RX_SPARE_MODE_PL             , RULL(0x800200300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RXPACKS3_SLICE5_RX_SPARE_MODE_PL             , RULL(0x800200300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL10_EO_PG                            , RULL(0x8009202006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL11_EO_PG                            , RULL(0x8009282006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL12_EO_PG                            , RULL(0x8009302006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL13_EO_PG                            , RULL(0x8009382006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL14_EO_PG                            , RULL(0x8009402006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL15_EO_PG                            , RULL(0x8009482006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL15_EO_PG                          , RULL(0x800948200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL15_EO_PG                          , RULL(0x800948200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL1_EO_PG                             , RULL(0x8008D82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL1_E_PG                              , RULL(0x8009F02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL1_E_PG                            , RULL(0x8009F0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL1_E_PG                            , RULL(0x8009F0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL2_EO_PG                             , RULL(0x8008E02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL3_EO_PG                             , RULL(0x8008E82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL4_EO_PG                             , RULL(0x8008F02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL4_E_PG                              , RULL(0x8009F82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL4_E_PG                            , RULL(0x8009F8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL4_E_PG                            , RULL(0x8009F8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL5_EO_PG                             , RULL(0x8008F82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL6_EO_PG                             , RULL(0x8009002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL8_EO_PG                             , RULL(0x8009102006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTL9_EO_PG                             , RULL(0x8009182006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTLX10_E_PG                            , RULL(0x800A282006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTLX10_E_PG                          , RULL(0x800A28200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTLX10_E_PG                          , RULL(0x800A28200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTLX11_E_PG                            , RULL(0x800A302006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTLX11_E_PG                          , RULL(0x800A30200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTLX11_E_PG                          , RULL(0x800A30200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTLX5_E_PG                             , RULL(0x800A002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTLX5_E_PG                           , RULL(0x800A00200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTLX5_E_PG                           , RULL(0x800A00200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_CNTLX7_EO_PG                            , RULL(0x8009082006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE10_EO_PG                            , RULL(0x8008582006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE10_EO_PG                          , RULL(0x800858200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE10_EO_PG                          , RULL(0x800858200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE10_E_PG                             , RULL(0x8009D82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE10_E_PG                           , RULL(0x8009D8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE10_E_PG                           , RULL(0x8009D8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE11_EO_PG                            , RULL(0x8008602006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE11_EO_PG                          , RULL(0x800860200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE11_EO_PG                          , RULL(0x800860200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE11_E_PG                             , RULL(0x8009E02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE11_E_PG                           , RULL(0x8009E0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE11_E_PG                           , RULL(0x8009E0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE12_EO_PG                            , RULL(0x8008682006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE12_EO_PG                          , RULL(0x800868200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE12_EO_PG                          , RULL(0x800868200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE12_E_PG                             , RULL(0x8009E82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE12_E_PG                           , RULL(0x8009E8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE12_E_PG                           , RULL(0x8009E8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE13_EO_PG                            , RULL(0x8008702006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE13_EO_PG                          , RULL(0x800870200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE13_EO_PG                          , RULL(0x800870200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE14_EO_PG                            , RULL(0x8008782006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE14_EO_PG                          , RULL(0x800878200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE14_EO_PG                          , RULL(0x800878200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE15_EO_PG                            , RULL(0x8008802006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE15_EO_PG                          , RULL(0x800880200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE15_EO_PG                          , RULL(0x800880200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE16_EO_PG                            , RULL(0x8008882006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE16_EO_PG                          , RULL(0x800888200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE16_EO_PG                          , RULL(0x800888200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE17_EO_PG                            , RULL(0x8008902006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE17_EO_PG                          , RULL(0x800890200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE17_EO_PG                          , RULL(0x800890200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE18_EO_PG                            , RULL(0x8008982006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE18_EO_PG                          , RULL(0x800898200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE18_EO_PG                          , RULL(0x800898200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE19_EO_PG                            , RULL(0x8008A02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE1_EO_PG                             , RULL(0x8008102006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE1_EO_PG                           , RULL(0x800810200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE1_EO_PG                           , RULL(0x800810200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE1_E_PG                              , RULL(0x8009902006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE1_E_PG                            , RULL(0x800990200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE1_E_PG                            , RULL(0x800990200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE20_EO_PG                            , RULL(0x8008A82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE21_EO_PG                            , RULL(0x8008B02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE22_EO_PG                            , RULL(0x8008B82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE23_EO_PG                            , RULL(0x8008C02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE24_EO_PG                            , RULL(0x8008C82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE26_EO_PG                            , RULL(0x8009682006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE26_EO_PG                          , RULL(0x800968200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE26_EO_PG                          , RULL(0x800968200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE27_EO_PG                            , RULL(0x8009702006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE27_EO_PG                          , RULL(0x800970200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE27_EO_PG                          , RULL(0x800970200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE28_EO_PG                            , RULL(0x8009782006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE28_EO_PG                          , RULL(0x800978200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE28_EO_PG                          , RULL(0x800978200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE29_EO_PG                            , RULL(0x8008D02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE2_EO_PG                             , RULL(0x8008182006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE2_EO_PG                           , RULL(0x800818200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE2_EO_PG                           , RULL(0x800818200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE2_E_PG                              , RULL(0x8009982006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE2_E_PG                            , RULL(0x800998200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE2_E_PG                            , RULL(0x800998200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE3_EO_PG                             , RULL(0x8008202006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE3_EO_PG                           , RULL(0x800820200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE3_EO_PG                           , RULL(0x800820200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE3_E_PG                              , RULL(0x8009A02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE3_E_PG                            , RULL(0x8009A0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE3_E_PG                            , RULL(0x8009A0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE4_EO_PG                             , RULL(0x8008282006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE4_EO_PG                           , RULL(0x800828200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE4_EO_PG                           , RULL(0x800828200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE4_E_PG                              , RULL(0x8009A82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE4_E_PG                            , RULL(0x8009A8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE4_E_PG                            , RULL(0x8009A8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE5_EO_PG                             , RULL(0x8008302006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE5_EO_PG                           , RULL(0x800830200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE5_EO_PG                           , RULL(0x800830200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE5_E_PG                              , RULL(0x8009B02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE5_E_PG                            , RULL(0x8009B0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE5_E_PG                            , RULL(0x8009B0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE6_EO_PG                             , RULL(0x8008382006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE6_EO_PG                           , RULL(0x800838200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE6_EO_PG                           , RULL(0x800838200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE6_E_PG                              , RULL(0x8009B82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE6_E_PG                            , RULL(0x8009B8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE6_E_PG                            , RULL(0x8009B8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE7_EO_PG                             , RULL(0x8008402006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE7_EO_PG                           , RULL(0x800840200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE7_EO_PG                           , RULL(0x800840200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE7_E_PG                              , RULL(0x8009C02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE7_E_PG                            , RULL(0x8009C0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE7_E_PG                            , RULL(0x8009C0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE8_EO_PG                             , RULL(0x8008482006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE8_EO_PG                           , RULL(0x800848200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE8_EO_PG                           , RULL(0x800848200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE8_E_PG                              , RULL(0x8009C82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE8_E_PG                            , RULL(0x8009C8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE8_E_PG                            , RULL(0x8009C8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE9_EO_PG                             , RULL(0x8008502006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE9_EO_PG                           , RULL(0x800850200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE9_EO_PG                           , RULL(0x800850200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_MODE9_E_PG                              , RULL(0x8009D02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_MODE9_E_PG                            , RULL(0x8009D0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_MODE9_E_PG                            , RULL(0x8009D0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT1_EO_PG                             , RULL(0x8009502006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT1_EO_PG                           , RULL(0x800950200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT1_EO_PG                           , RULL(0x800950200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT1_E_PG                              , RULL(0x800A382006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT1_E_PG                            , RULL(0x800A38200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT1_E_PG                            , RULL(0x800A38200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT2_EO_PG                             , RULL(0x8009582006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT2_EO_PG                           , RULL(0x800958200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT2_EO_PG                           , RULL(0x800958200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT2_E_PG                              , RULL(0x800A402006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT2_E_PG                            , RULL(0x800A40200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT2_E_PG                            , RULL(0x800A40200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT3_EO_PG                             , RULL(0x8009602006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT3_EO_PG                           , RULL(0x800960200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT3_EO_PG                           , RULL(0x800960200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT4_E_PG                              , RULL(0x800A502006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT4_E_PG                            , RULL(0x800A50200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT4_E_PG                            , RULL(0x800A50200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT5_E_PG                              , RULL(0x800A582006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT5_E_PG                            , RULL(0x800A58200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT5_E_PG                            , RULL(0x800A58200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STAT6_E_PG                              , RULL(0x800A602006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STAT6_E_PG                            , RULL(0x800A60200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STAT6_E_PG                            , RULL(0x800A60200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_CTL_STATX8_E_PG                             , RULL(0x800A682006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_CTL_STATX8_E_PG                           , RULL(0x800A68200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_CTL_STATX8_E_PG                           , RULL(0x800A68200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_CNTL1_E_PG                           , RULL(0x800BE82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_CNTL1_E_PG                         , RULL(0x800BE8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_CNTL1_E_PG                         , RULL(0x800BE8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_CNTLX1_EO_PG                         , RULL(0x800B882006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_SPARE_MODE_PG                        , RULL(0x800B802006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT10_EO_PG                         , RULL(0x800BD82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT11_EO_PG                         , RULL(0x800BE02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT12_EO_PG                         , RULL(0x800BF02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT12_EO_PG                       , RULL(0x800BF0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT12_EO_PG                       , RULL(0x800BF0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT13_E_PG                          , RULL(0x800BF82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT13_E_PG                        , RULL(0x800BF8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT13_E_PG                        , RULL(0x800BF8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT1_EO_PG                          , RULL(0x800B902006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT2_EO_PG                          , RULL(0x800B982006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT3_EO_PG                          , RULL(0x800BA02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT4_EO_PG                          , RULL(0x800BA82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT5_EO_PG                          , RULL(0x800BB02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT6_EO_PG                          , RULL(0x800BB82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT7_EO_PG                          , RULL(0x800BC02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT8_EO_PG                          , RULL(0x800BC82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_DATASM_STAT9_EO_PG                          , RULL(0x800BD02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR1_ERROR_INJECT_PG                        , RULL(0x800A982006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR1_MASK_PG                                , RULL(0x800A902006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR1_MASK_PG                              , RULL(0x800A90200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR1_MASK_PG                              , RULL(0x800A90200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR1_PG                                     , RULL(0x800A882006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR1_PG                                   , RULL(0x800A88200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR1_PG                                   , RULL(0x800A88200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR2_ERROR_INJECT_PG                        , RULL(0x800B102006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR2_ERROR_INJECT_PG                      , RULL(0x800B10200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR2_ERROR_INJECT_PG                      , RULL(0x800B10200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR2_MASK_PG                                , RULL(0x800B082006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR2_MASK_PG                              , RULL(0x800B08200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR2_MASK_PG                              , RULL(0x800B08200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR2_PG                                     , RULL(0x800B002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR2_PG                                   , RULL(0x800B00200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR2_PG                                   , RULL(0x800B00200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR_TRAINING_MASK_PG                        , RULL(0x800AA82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR_TRAINING_MASK_PG                      , RULL(0x800AA8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR_TRAINING_MASK_PG                      , RULL(0x800AA8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_FIR_TRAINING_PG                             , RULL(0x800AA02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_FIR_TRAINING_PG                           , RULL(0x800AA0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_FIR_TRAINING_PG                           , RULL(0x800AA0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_CNTL2_EO_PG                           , RULL(0x800AE02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_CNTL2_EO_PG                         , RULL(0x800AE0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_CNTL2_EO_PG                         , RULL(0x800AE0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_CNTL3_EO_PG                           , RULL(0x800AE82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_CNTL3_EO_PG                         , RULL(0x800AE8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_CNTL3_EO_PG                         , RULL(0x800AE8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_CNTLX1_EO_PG                          , RULL(0x800AB02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_CNTLX1_EO_PG                        , RULL(0x800AB0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_CNTLX1_EO_PG                        , RULL(0x800AB0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_SPARE_MODE_PG                         , RULL(0x800A802006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT10_E_PG                           , RULL(0x800B602006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT10_E_PG                         , RULL(0x800B60200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT10_E_PG                         , RULL(0x800B60200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT1_EO_PG                           , RULL(0x800AB82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT1_E_PG                            , RULL(0x800B182006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT1_E_PG                          , RULL(0x800B18200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT1_E_PG                          , RULL(0x800B18200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT2_EO_PG                           , RULL(0x800AC02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT2_E_PG                            , RULL(0x800B202006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT2_E_PG                          , RULL(0x800B20200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT2_E_PG                          , RULL(0x800B20200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT3_EO_PG                           , RULL(0x800AC82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT3_E_PG                            , RULL(0x800B282006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT3_E_PG                          , RULL(0x800B28200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT3_E_PG                          , RULL(0x800B28200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT4_EO_PG                           , RULL(0x800AD02006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT4_EO_PG                         , RULL(0x800AD0200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT4_EO_PG                         , RULL(0x800AD0200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT4_E_PG                            , RULL(0x800B302006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT4_E_PG                          , RULL(0x800B30200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT4_E_PG                          , RULL(0x800B30200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT5_EO_PG                           , RULL(0x800AD82006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT5_EO_PG                         , RULL(0x800AD8200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT5_EO_PG                         , RULL(0x800AD8200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT7_E_PG                            , RULL(0x800B482006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT7_E_PG                          , RULL(0x800B48200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT7_E_PG                          , RULL(0x800B48200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT8_E_PG                            , RULL(0x800B502006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT8_E_PG                          , RULL(0x800B50200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT8_E_PG                          , RULL(0x800B50200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_GLBSM_STAT9_E_PG                            , RULL(0x800B582006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_GLBSM_STAT9_E_PG                          , RULL(0x800B58200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_GLBSM_STAT9_E_PG                          , RULL(0x800B58200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_ID1_PG                                      , RULL(0x8008082006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_ID1_PG                                    , RULL(0x800808200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_ID1_PG                                    , RULL(0x800808200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_ID2_PG                                      , RULL(0x8009802006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_ID2_PG                                    , RULL(0x800980200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_ID2_PG                                    , RULL(0x800980200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_RX_SPARE_MODE_PG                               , RULL(0x8008002006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_RX_SPARE_MODE_PG                             , RULL(0x800800200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_RX_SPARE_MODE_PG                             , RULL(0x800800200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE0_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE0_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x800388210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x800388210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE0_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x800390210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x800390210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE0_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x800398210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x800398210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE10_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003802906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE10_RX_WORK_STAT1_EO_PL                    , RULL(0x8003882906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x800388290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x800388290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE10_RX_WORK_STAT2_EO_PL                    , RULL(0x8003902906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x800390290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x800390290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE10_RX_WORK_STAT3_EO_PL                    , RULL(0x8003982906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x800398290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x800398290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE11_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE11_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x800388310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x800388310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE11_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x800390310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x800390310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE11_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x800398310601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x800398310601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE12_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003802E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE12_RX_WORK_STAT1_EO_PL                    , RULL(0x8003882E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE12_RX_WORK_STAT2_EO_PL                    , RULL(0x8003902E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE12_RX_WORK_STAT3_EO_PL                    , RULL(0x8003982E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE13_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003802C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE13_RX_WORK_STAT1_EO_PL                    , RULL(0x8003882C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE13_RX_WORK_STAT2_EO_PL                    , RULL(0x8003902C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE13_RX_WORK_STAT3_EO_PL                    , RULL(0x8003982C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE14_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003802D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE14_RX_WORK_STAT1_EO_PL                    , RULL(0x8003882D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE14_RX_WORK_STAT2_EO_PL                    , RULL(0x8003902D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE14_RX_WORK_STAT3_EO_PL                    , RULL(0x8003982D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE15_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003802B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE15_RX_WORK_STAT1_EO_PL                    , RULL(0x8003882B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE15_RX_WORK_STAT2_EO_PL                    , RULL(0x8003902B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE15_RX_WORK_STAT3_EO_PL                    , RULL(0x8003982B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE16_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003802F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003802F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE16_RX_WORK_STAT1_EO_PL                    , RULL(0x8003882F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x8003882F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE16_RX_WORK_STAT2_EO_PL                    , RULL(0x8003902F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x8003902F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE16_RX_WORK_STAT3_EO_PL                    , RULL(0x8003982F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x8003982F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE17_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE17_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE17_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE17_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE18_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380320601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380320601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE18_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388320601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388320601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE18_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390320601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390320601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE18_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398320601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398320601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE19_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380330601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380330601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE19_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388330601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388330601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE19_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390330601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390330601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE19_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398330601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398330601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE1_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE1_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x800388230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x800388230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE1_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x800390230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x800390230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE1_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x800398230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x800398230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE20_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380340601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380340601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE20_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388340601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388340601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE20_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390340601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390340601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE20_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398340601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398340601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE21_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380350601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380350601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE21_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388350601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388350601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE21_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390350601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390350601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE21_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398350601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398350601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE22_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380360601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380360601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE22_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388360601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388360601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE22_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390360601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390360601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE22_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398360601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398360601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE23_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003803706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380370601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380370601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE23_RX_WORK_STAT1_EO_PL                    , RULL(0x8003883706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388370601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388370601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE23_RX_WORK_STAT2_EO_PL                    , RULL(0x8003903706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390370601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390370601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE23_RX_WORK_STAT3_EO_PL                    , RULL(0x8003983706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398370601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398370601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE2_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE2_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x800388200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x800388200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE2_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x800390200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x800390200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE2_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x800398200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x800398200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE3_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE3_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE3_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE3_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE4_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE4_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x800388270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x800388270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE4_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x800390270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x800390270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE4_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x800398270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x800398270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE5_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE5_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE5_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE5_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE6_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE6_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x800388260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x800388260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE6_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x800390260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x800390260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE6_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x800398260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x800398260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE7_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE7_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x800388240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x800388240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE7_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x800390240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x800390240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE7_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x800398240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x800398240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE8_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE8_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE8_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE8_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE9_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x8003802A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003802A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x8003802A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE9_RX_WORK_STAT1_EO_PL                     , RULL(0x8003882A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x8003882A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x8003882A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE9_RX_WORK_STAT2_EO_PL                     , RULL(0x8003902A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x8003902A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x8003902A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX1_SLICE9_RX_WORK_STAT3_EO_PL                     , RULL(0x8003982A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX1_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x8003982A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX1_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x8003982A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX_FIR_ERROR_INJECT_PB                             , RULL(0x800F980006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX_FIR_ERROR_INJECT_PB                           , RULL(0x800F98000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX_FIR_ERROR_INJECT_PB                           , RULL(0x800F98000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX_FIR_MASK_PB                                     , RULL(0x800F900006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX_FIR_MASK_PB                                   , RULL(0x800F90000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX_FIR_MASK_PB                                   , RULL(0x800F90000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX_FIR_PB                                          , RULL(0x800F880006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX_FIR_PB                                        , RULL(0x800F88000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX_FIR_PB                                        , RULL(0x800F88000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_RX_FIR_RESET_PB                                    , RULL(0x800F800006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_RX_FIR_RESET_PB                                  , RULL(0x800F80000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_RX_FIR_RESET_PB                                  , RULL(0x800F80000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_SCOM_MODE_PB                                       , RULL(0x06010C20), SH_UNT_XBUS     , SH_ACS_SCOM      );
REG64( XBUS_1_SCOM_MODE_PB                                     , RULL(0x06011020), SH_UNT_XBUS_1   , SH_ACS_SCOM      );
REG64( XBUS_2_SCOM_MODE_PB                                     , RULL(0x06011420), SH_UNT_XBUS_2   , SH_ACS_SCOM      );

REG64( XBUS_IOPPE_SCOM_PPE_CNTL                                , RULL(0x06010860), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM      );

REG64( XBUS_IOPPE_SCOM_PPE_FLAGS                               , RULL(0x06010863), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM_RW   );
REG64( XBUS_IOPPE_SCOM_PPE_FLAGS_OR                            , RULL(0x06010864), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM1_OR  );
REG64( XBUS_IOPPE_SCOM_PPE_FLAGS_CLEAR                         , RULL(0x06010865), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM2_CLEAR );

REG64( XBUS_IOPPE_SCOM_PPE_WORK_REG1                           , RULL(0x06010861), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM      );

REG64( XBUS_IOPPE_SCOM_PPE_WORK_REG2                           , RULL(0x06010862), SH_UNT_XBUS_IOPPE,
       SH_ACS_SCOM      );

REG64( XBUS_SPARE_MODE_PB                                      , RULL(0x800F340006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_SPARE_MODE_PB                                    , RULL(0x800F34000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_SPARE_MODE_PB                                    , RULL(0x800F34000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_HI_DATA_REG               , RULL(0x06010400), SH_UNT_XBUS_PERV, SH_ACS_SCOM_RO   );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_LO_DATA_REG               , RULL(0x06010401), SH_UNT_XBUS_PERV, SH_ACS_SCOM_RO   );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRCTRL_CONFIG             , RULL(0x06010402), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_0           , RULL(0x06010403), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_1           , RULL(0x06010404), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_2           , RULL(0x06010405), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_3           , RULL(0x06010406), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_4           , RULL(0x06010407), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_5           , RULL(0x06010408), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR0_TRACE_TRDATA_CONFIG_9           , RULL(0x06010409), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_HI_DATA_REG               , RULL(0x06010440), SH_UNT_XBUS_PERV, SH_ACS_SCOM_RO   );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_LO_DATA_REG               , RULL(0x06010441), SH_UNT_XBUS_PERV, SH_ACS_SCOM_RO   );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRCTRL_CONFIG             , RULL(0x06010442), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_0           , RULL(0x06010443), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_1           , RULL(0x06010444), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_2           , RULL(0x06010445), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_3           , RULL(0x06010446), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_4           , RULL(0x06010447), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_5           , RULL(0x06010448), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA0_TR1_TRACE_TRDATA_CONFIG_9           , RULL(0x06010449), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_HI_DATA_REG               , RULL(0x06010480), SH_UNT_XBUS_PERV, SH_ACS_SCOM_RO   );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_LO_DATA_REG               , RULL(0x06010481), SH_UNT_XBUS_PERV, SH_ACS_SCOM_RO   );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRCTRL_CONFIG             , RULL(0x06010482), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_0           , RULL(0x06010483), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_1           , RULL(0x06010484), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_2           , RULL(0x06010485), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_3           , RULL(0x06010486), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_4           , RULL(0x06010487), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_5           , RULL(0x06010488), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_PERV_TCXB_TRA1_TR0_TRACE_TRDATA_CONFIG_9           , RULL(0x06010489), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004440006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_FIR_PL                      , RULL(0x8004240006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                    , RULL(0x8004040006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C0106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004440106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_FIR_PL                      , RULL(0x8004240106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                    , RULL(0x8004040106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C010601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C010601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C0206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004440206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_FIR_PL                      , RULL(0x8004240206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                    , RULL(0x8004040206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C020601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C020601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C0306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004440306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_FIR_PL                      , RULL(0x8004240306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                    , RULL(0x8004040306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C030601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C030601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C0406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004440406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_FIR_PL                      , RULL(0x8004240406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                    , RULL(0x8004040406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C040601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C040601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C0506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004440506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_FIR_PL                      , RULL(0x8004240506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                    , RULL(0x8004040506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C050601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C050601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C0606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004440606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_FIR_PL                      , RULL(0x8004240606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                    , RULL(0x8004040606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C060601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C060601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C0706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004440706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_FIR_PL                      , RULL(0x8004240706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                    , RULL(0x8004040706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C070601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C070601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C0806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004440806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_FIR_PL                      , RULL(0x8004240806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                    , RULL(0x8004040806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C080601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C080601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C0906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004440906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_FIR_PL                      , RULL(0x8004240906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                    , RULL(0x8004040906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C090601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C090601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C0A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C0A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C0A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004440A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004440A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004440A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_FIR_PL                      , RULL(0x8004240A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004240A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004240A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                    , RULL(0x8004040A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004040A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004040A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C0B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C0B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C0B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004440B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004440B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004440B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_FIR_PL                      , RULL(0x8004240B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004240B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004240B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                    , RULL(0x8004040B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004040B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004040B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C0C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C0C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C0C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004440C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x8004440C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x8004440C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004540C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004540C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_FIR_PL                      , RULL(0x8004240C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004240C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004240C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                    , RULL(0x8004040C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004040C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004040C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C0D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C0D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C0D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004440D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x8004440D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x8004440D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004540D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004540D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_FIR_PL                      , RULL(0x8004240D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004240D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004240D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                    , RULL(0x8004040D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004040D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004040D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C0E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C0E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C0E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004440E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004440E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004440E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004540E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004540E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_FIR_PL                      , RULL(0x8004240E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004240E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004240E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                    , RULL(0x8004040E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004040E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004040E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C0F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C0F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C0F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004440F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004440F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004440F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004540F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004540F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_FIR_PL                      , RULL(0x8004240F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004240F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004240F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                    , RULL(0x8004040F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004040F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004040F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_BIT_MODE1_E_PL              , RULL(0x80043C1006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_BIT_MODE1_E_PL            , RULL(0x80043C100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_BIT_MODE1_E_PL            , RULL(0x80043C100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_BIT_MODE2_E_PL              , RULL(0x8004441006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_BIT_MODE2_E_PL            , RULL(0x800444100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_BIT_MODE2_E_PL            , RULL(0x800444100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_CNTL1G_PL                   , RULL(0x8004141006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_CNTL1G_PL                 , RULL(0x800414100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_CNTL1G_PL                 , RULL(0x800414100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_CNTL3_EO_PL                 , RULL(0x8004541006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_CNTL3_EO_PL               , RULL(0x800454100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_CNTL3_EO_PL               , RULL(0x800454100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004341006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_FIR_MASK_PL                 , RULL(0x80042C1006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_FIR_MASK_PL               , RULL(0x80042C100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_FIR_MASK_PL               , RULL(0x80042C100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_FIR_PL                      , RULL(0x8004241006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_FIR_PL                    , RULL(0x800424100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_FIR_PL                    , RULL(0x800424100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_MODE1_PL                    , RULL(0x8004041006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_MODE1_PL                  , RULL(0x800404100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_MODE1_PL                  , RULL(0x800404100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_MODE2_PL                    , RULL(0x80040C1006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_MODE2_PL                  , RULL(0x80040C100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_MODE2_PL                  , RULL(0x80040C100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TXPACKS3_SLICE4_TX_STAT1_PL                    , RULL(0x80041C1006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TXPACKS3_SLICE4_TX_STAT1_PL                  , RULL(0x80041C100601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TXPACKS3_SLICE4_TX_STAT1_PL                  , RULL(0x80041C100601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL1_EO_PG                           , RULL(0x800D340006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL2_EO_PG                           , RULL(0x800D3C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL3_EO_PG                           , RULL(0x800D440006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL4_EO_PG                           , RULL(0x800D4C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL5_EO_PG                           , RULL(0x800D540006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL6_EO_PG                           , RULL(0x800D5C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTL7_EO_PG                           , RULL(0x800D640006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_CNTLG1_E_PG                           , RULL(0x800D840006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_CNTLG1_E_PG                         , RULL(0x800D84000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_CNTLG1_E_PG                         , RULL(0x800D84000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_MODE1_EO_PG                           , RULL(0x800D2C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_SPARE_MODE_PG                         , RULL(0x800D240006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_STAT1_EO_PG                           , RULL(0x800D6C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTLSM_STAT1_E_PG                            , RULL(0x800D8C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTLSM_STAT1_E_PG                          , RULL(0x800D8C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTLSM_STAT1_E_PG                          , RULL(0x800D8C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTL10_EO_PG                            , RULL(0x800CDC0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTL10_EO_PG                          , RULL(0x800CDC000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTL10_EO_PG                          , RULL(0x800CDC000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTL2_EO_PG                             , RULL(0x800C2C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTL2_E_PG                              , RULL(0x800C9C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTL2_E_PG                            , RULL(0x800C9C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTL2_E_PG                            , RULL(0x800C9C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTL3_EO_PG                             , RULL(0x800C340006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTL8_EO_PG                             , RULL(0x800CCC0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTL8_EO_PG                           , RULL(0x800CCC000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTL8_EO_PG                           , RULL(0x800CCC000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTL9_EO_PG                             , RULL(0x800CD40006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTL9_EO_PG                           , RULL(0x800CD4000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTL9_EO_PG                           , RULL(0x800CD4000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTLG1_EO_PG                            , RULL(0x800C240006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTLG3_E_PG                             , RULL(0x800CA40006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTLG3_E_PG                           , RULL(0x800CA4000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTLG3_E_PG                           , RULL(0x800CA4000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTLG4_E_PG                             , RULL(0x800CAC0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTLG4_E_PG                           , RULL(0x800CAC000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTLG4_E_PG                           , RULL(0x800CAC000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTLG5_E_PG                             , RULL(0x800CB40006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTLG5_E_PG                           , RULL(0x800CB4000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTLG5_E_PG                           , RULL(0x800CB4000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTLG6_E_PG                             , RULL(0x800CBC0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTLG6_E_PG                           , RULL(0x800CBC000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTLG6_E_PG                           , RULL(0x800CBC000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_CNTLG7_E_PG                             , RULL(0x800CC40006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_CNTLG7_E_PG                           , RULL(0x800CC4000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_CNTLG7_E_PG                           , RULL(0x800CC4000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_MODE1_EO_PG                             , RULL(0x800C140006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_MODE1_E_PG                              , RULL(0x800C8C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_MODE1_E_PG                            , RULL(0x800C8C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_MODE1_E_PG                            , RULL(0x800C8C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_MODE2_EO_PG                             , RULL(0x800C1C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_MODE2_EO_PG                           , RULL(0x800C1C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_MODE2_EO_PG                           , RULL(0x800C1C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_MODE2_E_PG                              , RULL(0x800CEC0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_MODE2_E_PG                            , RULL(0x800CEC000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_MODE2_E_PG                            , RULL(0x800CEC000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_MODE3_E_PG                              , RULL(0x800CF40006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_MODE3_E_PG                            , RULL(0x800CF4000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_MODE3_E_PG                            , RULL(0x800CF4000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_CTL_STATG1_E_PG                             , RULL(0x800CE40006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_CTL_STATG1_E_PG                           , RULL(0x800CE4000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_CTL_STATG1_E_PG                           , RULL(0x800CE4000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_FIR_ERROR_INJECT_PG                         , RULL(0x800D1C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_FIR_MASK_PG                                 , RULL(0x800D0C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_FIR_MASK_PG                               , RULL(0x800D0C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_FIR_MASK_PG                               , RULL(0x800D0C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_FIR_PG                                      , RULL(0x800D040006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_FIR_PG                                    , RULL(0x800D04000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_FIR_PG                                    , RULL(0x800D04000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_FIR_RESET_PG                                , RULL(0x800D140006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_FIR_RESET_PG                              , RULL(0x800D14000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_FIR_RESET_PG                              , RULL(0x800D14000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_ID1_PG                                      , RULL(0x800C0C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_ID1_PG                                    , RULL(0x800C0C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_ID1_PG                                    , RULL(0x800C0C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_ID2_PG                                      , RULL(0x800C840006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_ID2_PG                                    , RULL(0x800C84000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_ID2_PG                                    , RULL(0x800C84000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX0_TX_SPARE_MODE_PG                               , RULL(0x800C040006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX0_TX_SPARE_MODE_PG                             , RULL(0x800C04000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX0_TX_SPARE_MODE_PG                             , RULL(0x800C04000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004442006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004142006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004542006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_FIR_PL                      , RULL(0x8004242006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_MODE1_PL                    , RULL(0x8004042006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_MODE2_PL                    , RULL(0x80040C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE0_TX_STAT1_PL                    , RULL(0x80041C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C2106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004442106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004142106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004542106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C2106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_FIR_PL                      , RULL(0x8004242106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_MODE1_PL                    , RULL(0x8004042106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_MODE2_PL                    , RULL(0x80040C2106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE1_TX_STAT1_PL                    , RULL(0x80041C2106010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C210601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C210601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C2206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004442206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004142206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004542206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C2206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_FIR_PL                      , RULL(0x8004242206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_MODE1_PL                    , RULL(0x8004042206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_MODE2_PL                    , RULL(0x80040C2206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE2_TX_STAT1_PL                    , RULL(0x80041C2206010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C220601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C220601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C2306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004442306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004142306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004542306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C2306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_FIR_PL                      , RULL(0x8004242306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_MODE1_PL                    , RULL(0x8004042306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_MODE2_PL                    , RULL(0x80040C2306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS0_SLICE3_TX_STAT1_PL                    , RULL(0x80041C2306010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C230601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C230601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C2406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004442406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004142406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004542406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C2406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_FIR_PL                      , RULL(0x8004242406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_MODE1_PL                    , RULL(0x8004042406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_MODE2_PL                    , RULL(0x80040C2406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE0_TX_STAT1_PL                    , RULL(0x80041C2406010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C240601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C240601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C2506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004442506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004142506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004542506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C2506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_FIR_PL                      , RULL(0x8004242506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_MODE1_PL                    , RULL(0x8004042506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_MODE2_PL                    , RULL(0x80040C2506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE1_TX_STAT1_PL                    , RULL(0x80041C2506010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C250601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C250601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C2606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004442606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x800444260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004142606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004542606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_CNTL3_EO_PL               , RULL(0x800454260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C2606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_FIR_PL                      , RULL(0x8004242606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_MODE1_PL                    , RULL(0x8004042606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_MODE2_PL                    , RULL(0x80040C2606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE2_TX_STAT1_PL                    , RULL(0x80041C2606010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C260601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C260601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C2706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004442706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x800444270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004142706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004542706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_CNTL3_EO_PL               , RULL(0x800454270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C2706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_FIR_PL                      , RULL(0x8004242706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_MODE1_PL                    , RULL(0x8004042706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_MODE2_PL                    , RULL(0x80040C2706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS1_SLICE3_TX_STAT1_PL                    , RULL(0x80041C2706010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C270601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C270601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C2806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004442806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x800444280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004142806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004542806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_CNTL3_EO_PL               , RULL(0x800454280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C2806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_FIR_PL                      , RULL(0x8004242806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_MODE1_PL                    , RULL(0x8004042806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_MODE2_PL                    , RULL(0x80040C2806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE0_TX_STAT1_PL                    , RULL(0x80041C2806010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C280601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C280601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C2906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004442906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x800444290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004142906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004542906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_CNTL3_EO_PL               , RULL(0x800454290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C2906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_FIR_PL                      , RULL(0x8004242906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_MODE1_PL                    , RULL(0x8004042906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_MODE2_PL                    , RULL(0x80040C2906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE1_TX_STAT1_PL                    , RULL(0x80041C2906010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C290601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C290601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C2A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C2A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C2A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004442A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004442A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004442A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004142A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004142A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004142A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004542A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004542A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004542A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C2A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C2A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C2A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_FIR_PL                      , RULL(0x8004242A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004242A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004242A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_MODE1_PL                    , RULL(0x8004042A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004042A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004042A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_MODE2_PL                    , RULL(0x80040C2A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C2A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C2A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE2_TX_STAT1_PL                    , RULL(0x80041C2A06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C2A0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C2A0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C2B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C2B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C2B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004442B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004442B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004442B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004142B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004142B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004142B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004542B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004542B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004542B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C2B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C2B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C2B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_FIR_PL                      , RULL(0x8004242B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004242B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004242B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_MODE1_PL                    , RULL(0x8004042B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004042B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004042B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_MODE2_PL                    , RULL(0x80040C2B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C2B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C2B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS2_SLICE3_TX_STAT1_PL                    , RULL(0x80041C2B06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C2B0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C2B0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_BIT_MODE1_E_PL              , RULL(0x80043C2C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C2C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_BIT_MODE1_E_PL            , RULL(0x80043C2C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_BIT_MODE2_E_PL              , RULL(0x8004442C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x8004442C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_BIT_MODE2_E_PL            , RULL(0x8004442C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004142C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004142C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004142C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_CNTL3_EO_PL                 , RULL(0x8004542C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004542C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_CNTL3_EO_PL               , RULL(0x8004542C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C2C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C2C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C2C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_FIR_PL                      , RULL(0x8004242C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004242C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004242C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_MODE1_PL                    , RULL(0x8004042C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004042C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004042C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_MODE2_PL                    , RULL(0x80040C2C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C2C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C2C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE0_TX_STAT1_PL                    , RULL(0x80041C2C06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C2C0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C2C0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_BIT_MODE1_E_PL              , RULL(0x80043C2D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C2D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_BIT_MODE1_E_PL            , RULL(0x80043C2D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_BIT_MODE2_E_PL              , RULL(0x8004442D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x8004442D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_BIT_MODE2_E_PL            , RULL(0x8004442D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004142D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004142D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004142D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_CNTL3_EO_PL                 , RULL(0x8004542D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004542D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_CNTL3_EO_PL               , RULL(0x8004542D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C2D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C2D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C2D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_FIR_PL                      , RULL(0x8004242D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004242D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004242D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_MODE1_PL                    , RULL(0x8004042D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004042D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004042D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_MODE2_PL                    , RULL(0x80040C2D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C2D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C2D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE1_TX_STAT1_PL                    , RULL(0x80041C2D06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C2D0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C2D0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_BIT_MODE1_E_PL              , RULL(0x80043C2E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C2E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_BIT_MODE1_E_PL            , RULL(0x80043C2E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_BIT_MODE2_E_PL              , RULL(0x8004442E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004442E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_BIT_MODE2_E_PL            , RULL(0x8004442E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004142E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004142E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004142E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_CNTL3_EO_PL                 , RULL(0x8004542E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004542E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_CNTL3_EO_PL               , RULL(0x8004542E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C2E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C2E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C2E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_FIR_PL                      , RULL(0x8004242E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004242E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004242E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_MODE1_PL                    , RULL(0x8004042E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004042E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004042E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_MODE2_PL                    , RULL(0x80040C2E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C2E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C2E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE2_TX_STAT1_PL                    , RULL(0x80041C2E06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C2E0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C2E0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_BIT_MODE1_E_PL              , RULL(0x80043C2F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C2F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_BIT_MODE1_E_PL            , RULL(0x80043C2F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_BIT_MODE2_E_PL              , RULL(0x8004442F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004442F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_BIT_MODE2_E_PL            , RULL(0x8004442F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004142F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004142F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004142F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_CNTL3_EO_PL                 , RULL(0x8004542F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004542F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_CNTL3_EO_PL               , RULL(0x8004542F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004342F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004342F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C2F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C2F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C2F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_FIR_PL                      , RULL(0x8004242F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004242F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004242F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_MODE1_PL                    , RULL(0x8004042F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004042F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004042F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_MODE2_PL                    , RULL(0x80040C2F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C2F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C2F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE3_TX_STAT1_PL                    , RULL(0x80041C2F06010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C2F0601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C2F0601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_BIT_MODE1_E_PL              , RULL(0x80043C3006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_BIT_MODE1_E_PL            , RULL(0x80043C300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_BIT_MODE1_E_PL            , RULL(0x80043C300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_BIT_MODE2_E_PL              , RULL(0x8004443006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_BIT_MODE2_E_PL            , RULL(0x800444300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_BIT_MODE2_E_PL            , RULL(0x800444300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_CNTL1G_PL                   , RULL(0x8004143006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_CNTL1G_PL                 , RULL(0x800414300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_CNTL1G_PL                 , RULL(0x800414300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_CNTL3_EO_PL                 , RULL(0x8004543006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_CNTL3_EO_PL               , RULL(0x800454300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_CNTL3_EO_PL               , RULL(0x800454300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004343006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_FIR_MASK_PL                 , RULL(0x80042C3006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_FIR_MASK_PL               , RULL(0x80042C300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_FIR_MASK_PL               , RULL(0x80042C300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_FIR_PL                      , RULL(0x8004243006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_FIR_PL                    , RULL(0x800424300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_FIR_PL                    , RULL(0x800424300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_MODE1_PL                    , RULL(0x8004043006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_MODE1_PL                  , RULL(0x800404300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_MODE1_PL                  , RULL(0x800404300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_MODE2_PL                    , RULL(0x80040C3006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_MODE2_PL                  , RULL(0x80040C300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_MODE2_PL                  , RULL(0x80040C300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TXPACKS3_SLICE4_TX_STAT1_PL                    , RULL(0x80041C3006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TXPACKS3_SLICE4_TX_STAT1_PL                  , RULL(0x80041C300601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TXPACKS3_SLICE4_TX_STAT1_PL                  , RULL(0x80041C300601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL1_EO_PG                           , RULL(0x800D342006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL2_EO_PG                           , RULL(0x800D3C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL3_EO_PG                           , RULL(0x800D442006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL4_EO_PG                           , RULL(0x800D4C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL5_EO_PG                           , RULL(0x800D542006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL6_EO_PG                           , RULL(0x800D5C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTL7_EO_PG                           , RULL(0x800D642006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_CNTLG1_E_PG                           , RULL(0x800D842006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_CNTLG1_E_PG                         , RULL(0x800D84200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_CNTLG1_E_PG                         , RULL(0x800D84200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_MODE1_EO_PG                           , RULL(0x800D2C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_SPARE_MODE_PG                         , RULL(0x800D242006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_STAT1_EO_PG                           , RULL(0x800D6C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTLSM_STAT1_E_PG                            , RULL(0x800D8C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTLSM_STAT1_E_PG                          , RULL(0x800D8C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTLSM_STAT1_E_PG                          , RULL(0x800D8C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTL10_EO_PG                            , RULL(0x800CDC2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTL10_EO_PG                          , RULL(0x800CDC200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTL10_EO_PG                          , RULL(0x800CDC200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTL2_EO_PG                             , RULL(0x800C2C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTL2_E_PG                              , RULL(0x800C9C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTL2_E_PG                            , RULL(0x800C9C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTL2_E_PG                            , RULL(0x800C9C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTL3_EO_PG                             , RULL(0x800C342006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTL8_EO_PG                             , RULL(0x800CCC2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTL8_EO_PG                           , RULL(0x800CCC200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTL8_EO_PG                           , RULL(0x800CCC200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTL9_EO_PG                             , RULL(0x800CD42006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTL9_EO_PG                           , RULL(0x800CD4200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTL9_EO_PG                           , RULL(0x800CD4200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTLG1_EO_PG                            , RULL(0x800C242006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTLG3_E_PG                             , RULL(0x800CA42006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTLG3_E_PG                           , RULL(0x800CA4200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTLG3_E_PG                           , RULL(0x800CA4200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTLG4_E_PG                             , RULL(0x800CAC2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTLG4_E_PG                           , RULL(0x800CAC200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTLG4_E_PG                           , RULL(0x800CAC200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTLG5_E_PG                             , RULL(0x800CB42006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTLG5_E_PG                           , RULL(0x800CB4200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTLG5_E_PG                           , RULL(0x800CB4200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTLG6_E_PG                             , RULL(0x800CBC2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTLG6_E_PG                           , RULL(0x800CBC200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTLG6_E_PG                           , RULL(0x800CBC200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_CNTLG7_E_PG                             , RULL(0x800CC42006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_CNTLG7_E_PG                           , RULL(0x800CC4200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_CNTLG7_E_PG                           , RULL(0x800CC4200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_MODE1_EO_PG                             , RULL(0x800C142006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_MODE1_E_PG                              , RULL(0x800C8C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_MODE1_E_PG                            , RULL(0x800C8C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_MODE1_E_PG                            , RULL(0x800C8C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_MODE2_EO_PG                             , RULL(0x800C1C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_MODE2_EO_PG                           , RULL(0x800C1C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_MODE2_EO_PG                           , RULL(0x800C1C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_MODE2_E_PG                              , RULL(0x800CEC2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_MODE2_E_PG                            , RULL(0x800CEC200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_MODE2_E_PG                            , RULL(0x800CEC200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_MODE3_E_PG                              , RULL(0x800CF42006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_MODE3_E_PG                            , RULL(0x800CF4200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_MODE3_E_PG                            , RULL(0x800CF4200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_CTL_STATG1_E_PG                             , RULL(0x800CE42006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_CTL_STATG1_E_PG                           , RULL(0x800CE4200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_CTL_STATG1_E_PG                           , RULL(0x800CE4200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_FIR_ERROR_INJECT_PG                         , RULL(0x800D1C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_FIR_MASK_PG                                 , RULL(0x800D0C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_FIR_MASK_PG                               , RULL(0x800D0C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_FIR_MASK_PG                               , RULL(0x800D0C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_FIR_PG                                      , RULL(0x800D042006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_FIR_PG                                    , RULL(0x800D04200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_FIR_PG                                    , RULL(0x800D04200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_FIR_RESET_PG                                , RULL(0x800D142006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_FIR_RESET_PG                              , RULL(0x800D14200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_FIR_RESET_PG                              , RULL(0x800D14200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_ID1_PG                                      , RULL(0x800C0C2006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_ID1_PG                                    , RULL(0x800C0C200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_ID1_PG                                    , RULL(0x800C0C200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_ID2_PG                                      , RULL(0x800C842006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_ID2_PG                                    , RULL(0x800C84200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_ID2_PG                                    , RULL(0x800C84200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX1_TX_SPARE_MODE_PG                               , RULL(0x800C042006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX1_TX_SPARE_MODE_PG                             , RULL(0x800C04200601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX1_TX_SPARE_MODE_PG                             , RULL(0x800C04200601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL2_PB                                      , RULL(0x800F3C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL2_PB                                    , RULL(0x800F3C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL2_PB                                    , RULL(0x800F3C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL_NVAL_PB                                  , RULL(0x800F0C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL_NVAL_PB                                , RULL(0x800F0C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL_NVAL_PB                                , RULL(0x800F0C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL_PB                                       , RULL(0x800F040006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL_PB                                     , RULL(0x800F04000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL_PB                                     , RULL(0x800F04000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL_PVAL_PB                                  , RULL(0x800F140006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL_PVAL_PB                                , RULL(0x800F14000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL_PVAL_PB                                , RULL(0x800F14000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL_P_4X_PB                                  , RULL(0x800F1C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL_P_4X_PB                                , RULL(0x800F1C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL_P_4X_PB                                , RULL(0x800F1C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL_SWO1_PB                                  , RULL(0x800F240006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL_SWO1_PB                                , RULL(0x800F24000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL_SWO1_PB                                , RULL(0x800F24000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_TX_IMPCAL_SWO2_PB                                  , RULL(0x800F2C0006010C3F), SH_UNT_XBUS     ,
       SH_ACS_SCOM      );
REG64( XBUS_1_TX_IMPCAL_SWO2_PB                                , RULL(0x800F2C000601103F), SH_UNT_XBUS_1   ,
       SH_ACS_SCOM      );
REG64( XBUS_2_TX_IMPCAL_SWO2_PB                                , RULL(0x800F2C000601143F), SH_UNT_XBUS_2   ,
       SH_ACS_SCOM      );

REG64( XBUS_PERV_XTRA_TRACE_MODE                               , RULL(0x060107D1), SH_UNT_XBUS_PERV, SH_ACS_SCOM      );
#endif


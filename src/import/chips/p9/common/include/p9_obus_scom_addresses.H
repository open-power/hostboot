/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/p9_obus_scom_addresses.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
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
 *    PEC Sat_id issue                  HW329652
 *    MC regs with same address.        HW323435 (matteo)
 *         Duplicate IOM registers.          HW320456 (designers)
 *    OSC/perv regs same address.       HW323437
 *    TOD reg same address.             HW323439
 *    PHB registers need fixed.         HW320416  ( all regs commented out now )
 *    IO0 registers need fixed.         HW320437
 *
 * Closed
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


REG64( OBUS_CSAR                                               , RULL(0x09011003), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_CSAR                                             , RULL(0x09011003), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_CSAR                                             , RULL(0x0C011003), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_CSCR                                               , RULL(0x09011000), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_CSCR_CLEAR                                         , RULL(0x09011001), SH_UNT_OBUS     ,
       SH_ACS_SCOM1_CLEAR );
REG64( OBUS_CSCR_OR                                            , RULL(0x09011002), SH_UNT_OBUS     , SH_ACS_SCOM2_OR  );
REG64( OBUS_0_CSCR                                             , RULL(0x09011000), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_0_CSCR_CLEAR                                       , RULL(0x09011001), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM1_CLEAR );
REG64( OBUS_0_CSCR_OR                                          , RULL(0x09011002), SH_UNT_OBUS_0   , SH_ACS_SCOM2_OR  );
REG64( OBUS_3_CSCR                                             , RULL(0x0C011000), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_CSCR_CLEAR                                       , RULL(0x0C011001), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM1_CLEAR );
REG64( OBUS_3_CSCR_OR                                          , RULL(0x0C011002), SH_UNT_OBUS_3   , SH_ACS_SCOM2_OR  );

REG64( OBUS_CSDR                                               , RULL(0x09011004), SH_UNT_OBUS     , SH_ACS_SCOM_RW   );
REG64( OBUS_0_CSDR                                             , RULL(0x09011004), SH_UNT_OBUS_0   , SH_ACS_SCOM_RW   );
REG64( OBUS_3_CSDR                                             , RULL(0x0C011004), SH_UNT_OBUS_3   , SH_ACS_SCOM_RW   );

REG64( OBUS_MIB_XIICAC                                         , RULL(0x19011009), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XIICAC                                       , RULL(0x19011009), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XIICAC                                       , RULL(0x1C011009), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_MIB_XIMEM                                          , RULL(0x19011007), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XIMEM                                        , RULL(0x19011007), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XIMEM                                        , RULL(0x1C011007), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_MIB_XISGB                                          , RULL(0x19011008), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XISGB                                        , RULL(0x19011008), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XISGB                                        , RULL(0x1C011008), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_MIB_XISIB                                          , RULL(0x19011006), SH_UNT_OBUS     , SH_ACS_SCOM_RO   );
REG64( OBUS_0_MIB_XISIB                                        , RULL(0x19011006), SH_UNT_OBUS_0   , SH_ACS_SCOM_RO   );
REG64( OBUS_3_MIB_XISIB                                        , RULL(0x1C011006), SH_UNT_OBUS_3   , SH_ACS_SCOM_RO   );

REG64( OBUS_PPE_XIDBGPRO                                       , RULL(0x19011005), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_PPE_XIDBGPRO                                     , RULL(0x19011005), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_PPE_XIDBGPRO                                     , RULL(0x1C011005), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_PPE_XIRAMDBG                                       , RULL(0x19011003), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_PPE_XIRAMDBG                                     , RULL(0x19011003), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_PPE_XIRAMDBG                                     , RULL(0x1C011003), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_PPE_XIRAMEDR                                       , RULL(0x19011004), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_PPE_XIRAMEDR                                     , RULL(0x19011004), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_PPE_XIRAMEDR                                     , RULL(0x1C011004), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_PPE_XIRAMGA                                        , RULL(0x19011002), SH_UNT_OBUS     , SH_ACS_SCOM_WO   );
REG64( OBUS_0_PPE_XIRAMGA                                      , RULL(0x19011002), SH_UNT_OBUS_0   , SH_ACS_SCOM_WO   );
REG64( OBUS_3_PPE_XIRAMGA                                      , RULL(0x1C011002), SH_UNT_OBUS_3   , SH_ACS_SCOM_WO   );

REG64( OBUS_PPE_XIRAMRA                                        , RULL(0x19011001), SH_UNT_OBUS     , SH_ACS_SCOM_WO   );
REG64( OBUS_0_PPE_XIRAMRA                                      , RULL(0x19011001), SH_UNT_OBUS_0   , SH_ACS_SCOM_WO   );
REG64( OBUS_3_PPE_XIRAMRA                                      , RULL(0x1C011001), SH_UNT_OBUS_3   , SH_ACS_SCOM_WO   );

REG64( OBUS_PPE_XIXCR                                          , RULL(0x19011000), SH_UNT_OBUS     , SH_ACS_SCOM_WO   );
REG64( OBUS_0_PPE_XIXCR                                        , RULL(0x19011000), SH_UNT_OBUS_0   , SH_ACS_SCOM_WO   );
REG64( OBUS_3_PPE_XIXCR                                        , RULL(0x1C011000), SH_UNT_OBUS_3   , SH_ACS_SCOM_WO   );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x800240000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x800248000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x800250000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x800220000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x800228000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x800230000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x800318000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x800260000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x800268000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x800008000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x800080000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x800010000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x800088000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x800018000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x800090000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x800020000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x800098000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x800028000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x800030000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x800038000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x800040000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL                 , RULL(0x800210000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_FIR_PL                      , RULL(0x800208000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x800208000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_FIR_PL                    , RULL(0x800208000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL               , RULL(0x800200000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x800240010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x800248010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x800250010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x800220010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x800228010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x800230010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x800318010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x800260010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x800268010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x800008010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x800080010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x800010010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x800088010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x800018010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x800090010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x800020010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x800098010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x800028010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x800030010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x800038010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x800040010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL                 , RULL(0x800210010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_FIR_PL                      , RULL(0x800208010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x800208010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_FIR_PL                    , RULL(0x800208010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL               , RULL(0x800200010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x800240020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x800248020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x800250020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x800220020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x800228020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x800230020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x800318020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x800260020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x800268020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x800008020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x800080020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x800010020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x800088020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x800018020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x800090020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x800020020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x800098020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x800028020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x800030020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x800038020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x800040020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL                 , RULL(0x800210020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_FIR_PL                      , RULL(0x800208020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x800208020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_FIR_PL                    , RULL(0x800208020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL               , RULL(0x800200020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x800240030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x800248030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x800250030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x800220030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x800228030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x800230030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x800318030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x800260030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x800268030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x800008030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x800080030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x800010030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x800088030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x800018030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x800090030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x800020030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x800098030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x800028030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x800030030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x800038030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x800040030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL                 , RULL(0x800210030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_FIR_PL                      , RULL(0x800208030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_FIR_PL                    , RULL(0x800208030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL               , RULL(0x800200030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS0_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x800240040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x800248040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x800250040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x800220040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x800228040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x800230040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x800318040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x800260040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x800268040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x800008040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x800080040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x800010040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x800088040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x800018040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x800090040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x800020040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x800098040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x800028040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x800030040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x800038040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x800040040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL                 , RULL(0x800210040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_FIR_PL                      , RULL(0x800208040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x800208040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_FIR_PL                    , RULL(0x800208040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL               , RULL(0x800200040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x800240050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x800248050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x800250050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x800220050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x800228050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x800230050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x800318050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x800260050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x800268050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x800008050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x800080050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x800010050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x800088050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x800018050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x800090050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x800020050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x800098050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x800028050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x800030050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x800038050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x800040050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL                 , RULL(0x800210050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_FIR_PL                      , RULL(0x800208050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_FIR_PL                    , RULL(0x800208050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL               , RULL(0x800200050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x800240060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x800248060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x800250060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x800220060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x800228060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x800230060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x800318060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x800260060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x800268060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x800008060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x800080060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x800010060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x800088060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x800018060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x800090060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x800020060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x800098060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x800028060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x800030060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x800038060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x800040060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL                 , RULL(0x800210060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_FIR_PL                      , RULL(0x800208060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x800208060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_FIR_PL                    , RULL(0x800208060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL               , RULL(0x800200060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x800240070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x800248070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x800250070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x800220070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x800228070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x800230070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x800318070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x800260070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x800268070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x800008070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x800080070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x800010070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x800088070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x800018070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x800090070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x800020070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x800098070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x800028070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x800030070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x800038070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x800040070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL                 , RULL(0x800210070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_FIR_PL                      , RULL(0x800208070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x800208070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_FIR_PL                    , RULL(0x800208070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL               , RULL(0x800200070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS1_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x800240080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x800248080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x800250080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x800220080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x800228080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x800230080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x800318080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x800260080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x800268080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x800008080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x800080080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x800010080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x800088080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x800018080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x800090080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x800020080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x800098080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x800028080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x800030080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x800038080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x800040080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL                 , RULL(0x800210080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_FIR_PL                      , RULL(0x800208080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_FIR_PL                    , RULL(0x800208080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL               , RULL(0x800200080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x800240090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x800248090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x800250090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x800220090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x800228090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x800230090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x800318090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x800260090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x800268090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x800008090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x800080090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x800010090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x800088090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x800018090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x800090090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x800020090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x800098090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x800028090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x800030090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x800038090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x800040090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL                 , RULL(0x800210090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_FIR_PL                      , RULL(0x800208090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x800208090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_FIR_PL                    , RULL(0x800208090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL               , RULL(0x800200090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002400A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002480A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002500A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002380A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003180A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002600A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002600A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002600A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002680A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002680A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002680A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000800A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000880A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000900A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000980A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_FIR_PL                      , RULL(0x8002080A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x8002080A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_FIR_PL                    , RULL(0x8002080A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002400B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002480B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002500B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002380B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003180B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002600B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002600B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002600B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002680B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002680B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002680B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000800B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000880B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000900B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000980B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_FIR_PL                      , RULL(0x8002080B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x8002080B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_FIR_PL                    , RULL(0x8002080B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS2_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x8002400C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x8002480C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x8002500C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002380C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x8002200C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x8002200C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x8002280C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x8002280C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x8002300C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x8002300C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x8003180C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x8003180C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x8002600C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002600C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x8002600C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x8002680C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002680C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x8002680C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x8000800C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x8000800C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x8000880C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x8000880C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x8000900C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x8000900C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x8000980C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x8000980C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL                 , RULL(0x8002100C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_FIR_MASK_PL               , RULL(0x8002100C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_FIR_PL                      , RULL(0x8002080C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x8002080C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_FIR_PL                    , RULL(0x8002080C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL               , RULL(0x8002000C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE0_RX_SPARE_MODE_PL             , RULL(0x8002000C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x8002400D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x8002480D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x8002500D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002380D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x8002200D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x8002200D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x8002280D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x8002280D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x8002300D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x8002300D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x8003180D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x8003180D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x8002600D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002600D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x8002600D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x8002680D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002680D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x8002680D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x8000800D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x8000800D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x8000880D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x8000880D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x8000900D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x8000900D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x8000980D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x8000980D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL                 , RULL(0x8002100D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_FIR_MASK_PL               , RULL(0x8002100D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_FIR_PL                      , RULL(0x8002080D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x8002080D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_FIR_PL                    , RULL(0x8002080D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL               , RULL(0x8002000D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE1_RX_SPARE_MODE_PL             , RULL(0x8002000D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x8002400E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x8002480E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x8002500E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002380E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x8002200E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x8002200E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x8002280E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x8002280E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x8002300E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x8002300E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x8003180E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x8003180E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x8002600E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002600E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x8002600E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x8002680E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002680E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x8002680E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x8000800E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x8000800E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x8000880E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x8000880E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x8000900E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x8000900E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x8000980E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x8000980E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL                 , RULL(0x8002100E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_FIR_MASK_PL               , RULL(0x8002100E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_FIR_PL                      , RULL(0x8002080E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x8002080E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_FIR_PL                    , RULL(0x8002080E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL               , RULL(0x8002000E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE2_RX_SPARE_MODE_PL             , RULL(0x8002000E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x8002400F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x8002400F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x8002480F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x8002480F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x8002500F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x8002500F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x8002380F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x8002380F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x8002200F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x8002200F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x8002280F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x8002280F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x8002300F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x8002300F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x8003180F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x8003180F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x8002600F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002600F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x8002600F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x8002680F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002680F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x8002680F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C80F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C80F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x8000080F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x8000080F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x8000800F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x8000800F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x8000100F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x8000100F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x8000880F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x8000880F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x8000180F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x8000180F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x8000900F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x8000900F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x8000200F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x8000200F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x8000980F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x8000980F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x8000280F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x8000280F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A00F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A00F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x8000300F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x8000300F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A80F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A80F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x8000380F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x8000380F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B00F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B00F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x8000400F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x8000400F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B80F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B80F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C00F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C00F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x8000000F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x8000000F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x8002180F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x8002180F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL                 , RULL(0x8002100F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_FIR_MASK_PL               , RULL(0x8002100F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_FIR_PL                      , RULL(0x8002080F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x8002080F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_FIR_PL                    , RULL(0x8002080F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL               , RULL(0x8002000F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS3_SLICE3_RX_SPARE_MODE_PL             , RULL(0x8002000F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x800240100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x800248100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x800250100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x800220100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x800228100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x800230100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x800318100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x800260100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x800268100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x800008100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x800080100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x800010100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x800088100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x800018100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x800090100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x800020100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x800098100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x800028100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x800030100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x800038100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x800040100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL                 , RULL(0x800210100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_FIR_PL                      , RULL(0x800208100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_FIR_PL                    , RULL(0x800208100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_FIR_PL                    , RULL(0x800208100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL               , RULL(0x800200100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x800240110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x800248110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x800250110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x800220110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x800228110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x800230110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x800318110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x800260110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x800268110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x800008110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x800080110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x800010110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x800088110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x800018110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x800090110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x800020110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x800098110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x800028110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x800030110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x800038110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x800040110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL                 , RULL(0x800210110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_FIR_PL                      , RULL(0x800208110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_FIR_PL                    , RULL(0x800208110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_FIR_PL                    , RULL(0x800208110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL               , RULL(0x800200110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x800240120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x800248120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x800250120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x800220120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x800228120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x800230120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x800318120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x800260120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x800268120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x800008120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x800080120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x800010120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x800088120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x800018120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x800090120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x800020120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x800098120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x800028120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x800030120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x800038120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x800040120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL                 , RULL(0x800210120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_FIR_PL                      , RULL(0x800208120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_FIR_PL                    , RULL(0x800208120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_FIR_PL                    , RULL(0x800208120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL               , RULL(0x800200120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x800240130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x800248130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x800250130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x800220130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x800228130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x800230130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x800318130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x800260130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x800268130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x800008130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x800080130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x800010130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x800088130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x800018130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x800090130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x800020130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x800098130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x800028130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x800030130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x800038130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x800040130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL                 , RULL(0x800210130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_FIR_PL                      , RULL(0x800208130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_FIR_PL                    , RULL(0x800208130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_FIR_PL                    , RULL(0x800208130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL               , RULL(0x800200130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS4_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL             , RULL(0x800240140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL2_EO_PL           , RULL(0x800240140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL             , RULL(0x800248140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL3_EO_PL           , RULL(0x800248140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL             , RULL(0x800250140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTL4_EO_PL           , RULL(0x800250140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL             , RULL(0x800220140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE1_EO_PL           , RULL(0x800220140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL             , RULL(0x800228140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE2_EO_PL           , RULL(0x800228140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL             , RULL(0x800230140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_MODE3_EO_PL           , RULL(0x800230140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL              , RULL(0x800318140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT1_O_PL            , RULL(0x800318140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL             , RULL(0x800260140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT2_EO_PL           , RULL(0x800260140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL             , RULL(0x800268140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_BIT_STAT3_EO_PL           , RULL(0x800268140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL             , RULL(0x800008140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_EO_PL           , RULL(0x800008140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL              , RULL(0x800080140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL1_O_PL            , RULL(0x800080140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL             , RULL(0x800010140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_EO_PL           , RULL(0x800010140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL              , RULL(0x800088140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL2_O_PL            , RULL(0x800088140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL             , RULL(0x800018140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_EO_PL           , RULL(0x800018140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL              , RULL(0x800090140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL3_O_PL            , RULL(0x800090140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL             , RULL(0x800020140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_EO_PL           , RULL(0x800020140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL              , RULL(0x800098140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL4_O_PL            , RULL(0x800098140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL             , RULL(0x800028140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_EO_PL           , RULL(0x800028140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL             , RULL(0x800030140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_EO_PL           , RULL(0x800030140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL             , RULL(0x800038140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_EO_PL           , RULL(0x800038140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL             , RULL(0x800040140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_EO_PL           , RULL(0x800040140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL                 , RULL(0x800210140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_FIR_MASK_PL               , RULL(0x800210140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_FIR_PL                      , RULL(0x800208140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_FIR_PL                    , RULL(0x800208140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_FIR_PL                    , RULL(0x800208140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL               , RULL(0x800200140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE0_RX_SPARE_MODE_PL             , RULL(0x800200140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL             , RULL(0x800240150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL2_EO_PL           , RULL(0x800240150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL             , RULL(0x800248150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL3_EO_PL           , RULL(0x800248150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL             , RULL(0x800250150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTL4_EO_PL           , RULL(0x800250150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL             , RULL(0x800220150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE1_EO_PL           , RULL(0x800220150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL             , RULL(0x800228150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE2_EO_PL           , RULL(0x800228150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL             , RULL(0x800230150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_MODE3_EO_PL           , RULL(0x800230150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL              , RULL(0x800318150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT1_O_PL            , RULL(0x800318150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL             , RULL(0x800260150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT2_EO_PL           , RULL(0x800260150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL             , RULL(0x800268150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_BIT_STAT3_EO_PL           , RULL(0x800268150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL             , RULL(0x800008150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_EO_PL           , RULL(0x800008150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL              , RULL(0x800080150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL1_O_PL            , RULL(0x800080150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL             , RULL(0x800010150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_EO_PL           , RULL(0x800010150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL              , RULL(0x800088150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL2_O_PL            , RULL(0x800088150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL             , RULL(0x800018150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_EO_PL           , RULL(0x800018150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL              , RULL(0x800090150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL3_O_PL            , RULL(0x800090150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL             , RULL(0x800020150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_EO_PL           , RULL(0x800020150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL              , RULL(0x800098150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL4_O_PL            , RULL(0x800098150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL             , RULL(0x800028150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_EO_PL           , RULL(0x800028150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL             , RULL(0x800030150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_EO_PL           , RULL(0x800030150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL             , RULL(0x800038150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_EO_PL           , RULL(0x800038150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL             , RULL(0x800040150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_EO_PL           , RULL(0x800040150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL                 , RULL(0x800210150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_FIR_MASK_PL               , RULL(0x800210150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_FIR_PL                      , RULL(0x800208150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_FIR_PL                    , RULL(0x800208150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_FIR_PL                    , RULL(0x800208150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL               , RULL(0x800200150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE1_RX_SPARE_MODE_PL             , RULL(0x800200150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL             , RULL(0x800240160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL2_EO_PL           , RULL(0x800240160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL             , RULL(0x800248160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL3_EO_PL           , RULL(0x800248160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL             , RULL(0x800250160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTL4_EO_PL           , RULL(0x800250160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL             , RULL(0x800220160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE1_EO_PL           , RULL(0x800220160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL             , RULL(0x800228160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE2_EO_PL           , RULL(0x800228160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL             , RULL(0x800230160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_MODE3_EO_PL           , RULL(0x800230160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL              , RULL(0x800318160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT1_O_PL            , RULL(0x800318160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL             , RULL(0x800260160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT2_EO_PL           , RULL(0x800260160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL             , RULL(0x800268160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_BIT_STAT3_EO_PL           , RULL(0x800268160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL             , RULL(0x800008160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_EO_PL           , RULL(0x800008160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL              , RULL(0x800080160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL1_O_PL            , RULL(0x800080160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL             , RULL(0x800010160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_EO_PL           , RULL(0x800010160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL              , RULL(0x800088160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL2_O_PL            , RULL(0x800088160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL             , RULL(0x800018160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_EO_PL           , RULL(0x800018160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL              , RULL(0x800090160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL3_O_PL            , RULL(0x800090160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL             , RULL(0x800020160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_EO_PL           , RULL(0x800020160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL              , RULL(0x800098160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL4_O_PL            , RULL(0x800098160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL             , RULL(0x800028160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_EO_PL           , RULL(0x800028160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL             , RULL(0x800030160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_EO_PL           , RULL(0x800030160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL             , RULL(0x800038160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_EO_PL           , RULL(0x800038160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL             , RULL(0x800040160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_EO_PL           , RULL(0x800040160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL                 , RULL(0x800210160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_FIR_MASK_PL               , RULL(0x800210160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_FIR_PL                      , RULL(0x800208160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_FIR_PL                    , RULL(0x800208160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_FIR_PL                    , RULL(0x800208160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL               , RULL(0x800200160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE2_RX_SPARE_MODE_PL             , RULL(0x800200160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL             , RULL(0x800240170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL2_EO_PL           , RULL(0x800240170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL             , RULL(0x800248170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL3_EO_PL           , RULL(0x800248170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL             , RULL(0x800250170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTL4_EO_PL           , RULL(0x800250170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL            , RULL(0x800238170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_CNTLX1_EO_PL          , RULL(0x800238170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL             , RULL(0x800220170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE1_EO_PL           , RULL(0x800220170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL             , RULL(0x800228170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE2_EO_PL           , RULL(0x800228170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL             , RULL(0x800230170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_MODE3_EO_PL           , RULL(0x800230170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL              , RULL(0x800318170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT1_O_PL            , RULL(0x800318170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL             , RULL(0x800260170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT2_EO_PL           , RULL(0x800260170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL             , RULL(0x800268170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_BIT_STAT3_EO_PL           , RULL(0x800268170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL             , RULL(0x8000C8170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL10_O_PL           , RULL(0x8000C8170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL             , RULL(0x800008170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_EO_PL           , RULL(0x800008170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL              , RULL(0x800080170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL1_O_PL            , RULL(0x800080170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL             , RULL(0x800010170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_EO_PL           , RULL(0x800010170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL              , RULL(0x800088170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL2_O_PL            , RULL(0x800088170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL             , RULL(0x800018170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_EO_PL           , RULL(0x800018170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL              , RULL(0x800090170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL3_O_PL            , RULL(0x800090170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL             , RULL(0x800020170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_EO_PL           , RULL(0x800020170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL              , RULL(0x800098170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL4_O_PL            , RULL(0x800098170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL             , RULL(0x800028170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_EO_PL           , RULL(0x800028170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL              , RULL(0x8000A0170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL5_O_PL            , RULL(0x8000A0170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL             , RULL(0x800030170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_EO_PL           , RULL(0x800030170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL              , RULL(0x8000A8170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL6_O_PL            , RULL(0x8000A8170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL             , RULL(0x800038170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_EO_PL           , RULL(0x800038170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL              , RULL(0x8000B0170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL7_O_PL            , RULL(0x8000B0170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL             , RULL(0x800040170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_EO_PL           , RULL(0x800040170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL              , RULL(0x8000B8170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL8_O_PL            , RULL(0x8000B8170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL              , RULL(0x8000C0170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DAC_CNTL9_O_PL            , RULL(0x8000C0170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL      , RULL(0x800000170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_DATA_DAC_SPARE_MODE_PL    , RULL(0x800000170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL         , RULL(0x800218170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_FIR_ERROR_INJECT_PL       , RULL(0x800218170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL                 , RULL(0x800210170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_FIR_MASK_PL               , RULL(0x800210170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_FIR_PL                      , RULL(0x800208170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_FIR_PL                    , RULL(0x800208170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_FIR_PL                    , RULL(0x800208170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL               , RULL(0x800200170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RXPACKS5_SLICE3_RX_SPARE_MODE_PL             , RULL(0x800200170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL10_EO_PG                            , RULL(0x800920000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL10_EO_PG                          , RULL(0x800920000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL11_EO_PG                            , RULL(0x800928000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL11_EO_PG                          , RULL(0x800928000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL12_EO_PG                            , RULL(0x800930000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL12_EO_PG                          , RULL(0x800930000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL13_EO_PG                            , RULL(0x800938000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL13_EO_PG                          , RULL(0x800938000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL14_EO_PG                            , RULL(0x800940000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL14_EO_PG                          , RULL(0x800940000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL1_EO_PG                             , RULL(0x8008D8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL1_EO_PG                           , RULL(0x8008D8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL2_EO_PG                             , RULL(0x8008E0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL2_EO_PG                           , RULL(0x8008E0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL3_EO_PG                             , RULL(0x8008E8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL3_EO_PG                           , RULL(0x8008E8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL4_EO_PG                             , RULL(0x8008F0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL4_EO_PG                           , RULL(0x8008F0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL5_EO_PG                             , RULL(0x8008F8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL5_EO_PG                           , RULL(0x8008F8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL6_EO_PG                             , RULL(0x800900000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL6_EO_PG                           , RULL(0x800900000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL8_EO_PG                             , RULL(0x800910000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL8_EO_PG                           , RULL(0x800910000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTL9_EO_PG                             , RULL(0x800918000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTL9_EO_PG                           , RULL(0x800918000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_CNTLX7_EO_PG                            , RULL(0x800908000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_CNTLX7_EO_PG                          , RULL(0x800908000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE10_EO_PG                            , RULL(0x800858000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE10_EO_PG                          , RULL(0x800858000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE10_EO_PG                          , RULL(0x800858000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE11_EO_PG                            , RULL(0x800860000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE11_EO_PG                          , RULL(0x800860000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE11_EO_PG                          , RULL(0x800860000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE12_EO_PG                            , RULL(0x800868000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE12_EO_PG                          , RULL(0x800868000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE12_EO_PG                          , RULL(0x800868000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE13_EO_PG                            , RULL(0x800870000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE13_EO_PG                          , RULL(0x800870000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE13_EO_PG                          , RULL(0x800870000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE14_EO_PG                            , RULL(0x800878000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE14_EO_PG                          , RULL(0x800878000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE14_EO_PG                          , RULL(0x800878000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE15_EO_PG                            , RULL(0x800880000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE15_EO_PG                          , RULL(0x800880000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE15_EO_PG                          , RULL(0x800880000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE16_EO_PG                            , RULL(0x800888000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE16_EO_PG                          , RULL(0x800888000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE16_EO_PG                          , RULL(0x800888000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE17_EO_PG                            , RULL(0x800890000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE17_EO_PG                          , RULL(0x800890000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE17_EO_PG                          , RULL(0x800890000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE18_EO_PG                            , RULL(0x800898000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE18_EO_PG                          , RULL(0x800898000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE18_EO_PG                          , RULL(0x800898000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE19_EO_PG                            , RULL(0x8008A0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE19_EO_PG                          , RULL(0x8008A0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE1_EO_PG                             , RULL(0x800810000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE1_EO_PG                           , RULL(0x800810000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE1_EO_PG                           , RULL(0x800810000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE1_O_PG                              , RULL(0x8009B0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE1_O_PG                            , RULL(0x8009B0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE1_O_PG                            , RULL(0x8009B0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE20_EO_PG                            , RULL(0x8008A8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE20_EO_PG                          , RULL(0x8008A8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE21_EO_PG                            , RULL(0x8008B0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE21_EO_PG                          , RULL(0x8008B0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE22_EO_PG                            , RULL(0x8008B8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE22_EO_PG                          , RULL(0x8008B8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE23_EO_PG                            , RULL(0x8008C0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE23_EO_PG                          , RULL(0x8008C0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE24_EO_PG                            , RULL(0x8008C8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE24_EO_PG                          , RULL(0x8008C8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE26_EO_PG                            , RULL(0x800968000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE26_EO_PG                          , RULL(0x800968000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE26_EO_PG                          , RULL(0x800968000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE27_EO_PG                            , RULL(0x800970000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE27_EO_PG                          , RULL(0x800970000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE27_EO_PG                          , RULL(0x800970000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE28_EO_PG                            , RULL(0x800978000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE28_EO_PG                          , RULL(0x800978000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE28_EO_PG                          , RULL(0x800978000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE29_EO_PG                            , RULL(0x8008D0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE29_EO_PG                          , RULL(0x8008D0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE2_EO_PG                             , RULL(0x800818000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE2_EO_PG                           , RULL(0x800818000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE2_EO_PG                           , RULL(0x800818000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE5_EO_PG                             , RULL(0x800830000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE5_EO_PG                           , RULL(0x800830000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE5_EO_PG                           , RULL(0x800830000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE6_EO_PG                             , RULL(0x800838000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE6_EO_PG                           , RULL(0x800838000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE6_EO_PG                           , RULL(0x800838000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE7_EO_PG                             , RULL(0x800840000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE7_EO_PG                           , RULL(0x800840000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE7_EO_PG                           , RULL(0x800840000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_MODE9_EO_PG                             , RULL(0x800850000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_MODE9_EO_PG                           , RULL(0x800850000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_MODE9_EO_PG                           , RULL(0x800850000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_STAT1_EO_PG                             , RULL(0x800950000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_STAT1_EO_PG                           , RULL(0x800950000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_STAT1_EO_PG                           , RULL(0x800950000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_CTL_STAT2_EO_PG                             , RULL(0x800958000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_CTL_STAT2_EO_PG                           , RULL(0x800958000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_CTL_STAT2_EO_PG                           , RULL(0x800958000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_CNTLX1_EO_PG                         , RULL(0x800B88000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_CNTLX1_EO_PG                       , RULL(0x800B88000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_SPARE_MODE_PG                        , RULL(0x800B80000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_SPARE_MODE_PG                      , RULL(0x800B80000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT10_EO_PG                         , RULL(0x800BD8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT10_EO_PG                       , RULL(0x800BD8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT11_EO_PG                         , RULL(0x800BE0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT11_EO_PG                       , RULL(0x800BE0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT1_EO_PG                          , RULL(0x800B90000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT1_EO_PG                        , RULL(0x800B90000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT2_EO_PG                          , RULL(0x800B98000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT2_EO_PG                        , RULL(0x800B98000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT3_EO_PG                          , RULL(0x800BA0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT3_EO_PG                        , RULL(0x800BA0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT4_EO_PG                          , RULL(0x800BA8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT4_EO_PG                        , RULL(0x800BA8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT5_EO_PG                          , RULL(0x800BB0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT5_EO_PG                        , RULL(0x800BB0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT6_EO_PG                          , RULL(0x800BB8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT6_EO_PG                        , RULL(0x800BB8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT7_EO_PG                          , RULL(0x800BC0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT7_EO_PG                        , RULL(0x800BC0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT8_EO_PG                          , RULL(0x800BC8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT8_EO_PG                        , RULL(0x800BC8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_DATASM_STAT9_EO_PG                          , RULL(0x800BD0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_DATASM_STAT9_EO_PG                        , RULL(0x800BD0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_FIR1_ERROR_INJECT_PG                        , RULL(0x800A98000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_FIR1_ERROR_INJECT_PG                      , RULL(0x800A98000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_FIR1_MASK_PG                                , RULL(0x800A90000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_FIR1_MASK_PG                              , RULL(0x800A90000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_FIR1_MASK_PG                              , RULL(0x800A90000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_FIR1_PG                                     , RULL(0x800A88000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_FIR1_PG                                   , RULL(0x800A88000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_FIR1_PG                                   , RULL(0x800A88000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_CNTL1_EO_PG                           , RULL(0x800AB0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_CNTL1_EO_PG                         , RULL(0x800AB0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_CNTL1_EO_PG                         , RULL(0x800AB0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_SPARE_MODE_PG                         , RULL(0x800A80000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_SPARE_MODE_PG                       , RULL(0x800A80000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT1_EO_PG                           , RULL(0x800AB8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT1_EO_PG                         , RULL(0x800AB8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT2_EO_PG                           , RULL(0x800AC0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT2_EO_PG                         , RULL(0x800AC0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_GLBSM_STAT3_EO_PG                           , RULL(0x800AC8000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_GLBSM_STAT3_EO_PG                         , RULL(0x800AC8000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_ID1_PG                                      , RULL(0x800808000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_ID1_PG                                    , RULL(0x800808000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_ID1_PG                                    , RULL(0x800808000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_RX_SPARE_MODE_PG                               , RULL(0x800800000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_RX_SPARE_MODE_PG                             , RULL(0x800800000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_RX_SPARE_MODE_PG                             , RULL(0x800800000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT1_EO_PL                     , RULL(0x800388000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x800388000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT1_EO_PL                   , RULL(0x800388000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT2_EO_PL                     , RULL(0x800390000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x800390000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT2_EO_PL                   , RULL(0x800390000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT3_EO_PL                     , RULL(0x800398000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x800398000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT3_EO_PL                   , RULL(0x800398000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE0_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE0_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE0_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE10_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE10_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE10_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE11_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE11_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE11_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE12_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE12_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE12_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE13_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE13_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE13_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE14_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE14_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE14_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x8003800F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x8003800F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x8003200F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x8003200F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x8003280F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x8003280F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT1_EO_PL                    , RULL(0x8003880F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT1_EO_PL                  , RULL(0x8003880F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT2_EO_PL                    , RULL(0x8003900F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT2_EO_PL                  , RULL(0x8003900F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT3_EO_PL                    , RULL(0x8003980F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT3_EO_PL                  , RULL(0x8003980F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE15_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A00F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE15_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE15_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A00F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT1_EO_PL                    , RULL(0x800388100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x800388100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT1_EO_PL                  , RULL(0x800388100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT2_EO_PL                    , RULL(0x800390100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x800390100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT2_EO_PL                  , RULL(0x800390100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT3_EO_PL                    , RULL(0x800398100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x800398100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT3_EO_PL                  , RULL(0x800398100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE16_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE16_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE16_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT1_EO_PL                    , RULL(0x800388110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT1_EO_PL                  , RULL(0x800388110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT2_EO_PL                    , RULL(0x800390110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT2_EO_PL                  , RULL(0x800390110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT3_EO_PL                    , RULL(0x800398110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT3_EO_PL                  , RULL(0x800398110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE17_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE17_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE17_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT1_EO_PL                    , RULL(0x800388120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT1_EO_PL                  , RULL(0x800388120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT2_EO_PL                    , RULL(0x800390120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT2_EO_PL                  , RULL(0x800390120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT3_EO_PL                    , RULL(0x800398120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT3_EO_PL                  , RULL(0x800398120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE18_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE18_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE18_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT1_EO_PL                    , RULL(0x800388130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT1_EO_PL                  , RULL(0x800388130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT2_EO_PL                    , RULL(0x800390130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT2_EO_PL                  , RULL(0x800390130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT3_EO_PL                    , RULL(0x800398130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT3_EO_PL                  , RULL(0x800398130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE19_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE19_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE19_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT1_EO_PL                     , RULL(0x800388010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x800388010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT1_EO_PL                   , RULL(0x800388010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT2_EO_PL                     , RULL(0x800390010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x800390010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT2_EO_PL                   , RULL(0x800390010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT3_EO_PL                     , RULL(0x800398010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x800398010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT3_EO_PL                   , RULL(0x800398010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE1_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE1_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE1_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT1_EO_PL                    , RULL(0x800388140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT1_EO_PL                  , RULL(0x800388140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT2_EO_PL                    , RULL(0x800390140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT2_EO_PL                  , RULL(0x800390140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT3_EO_PL                    , RULL(0x800398140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT3_EO_PL                  , RULL(0x800398140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE20_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE20_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE20_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT1_EO_PL                    , RULL(0x800388150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT1_EO_PL                  , RULL(0x800388150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT2_EO_PL                    , RULL(0x800390150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT2_EO_PL                  , RULL(0x800390150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT3_EO_PL                    , RULL(0x800398150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT3_EO_PL                  , RULL(0x800398150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE21_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE21_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE21_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT1_EO_PL                    , RULL(0x800388160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT1_EO_PL                  , RULL(0x800388160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT2_EO_PL                    , RULL(0x800390160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT2_EO_PL                  , RULL(0x800390160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT3_EO_PL                    , RULL(0x800398160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT3_EO_PL                  , RULL(0x800398160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE22_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE22_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE22_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL             , RULL(0x800380170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_DATA_WORK_SPARE_MODE_PL           , RULL(0x800380170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL                 , RULL(0x800320170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_GLBSM_PL_CNTL1_O_PL               , RULL(0x800320170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL                 , RULL(0x800328170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_GLBSM_PL_STAT1_O_PL               , RULL(0x800328170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT1_EO_PL                    , RULL(0x800388170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT1_EO_PL                  , RULL(0x800388170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT2_EO_PL                    , RULL(0x800390170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT2_EO_PL                  , RULL(0x800390170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT3_EO_PL                    , RULL(0x800398170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT3_EO_PL                  , RULL(0x800398170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE23_RX_WORK_STAT4_EO_PL                    , RULL(0x8003A0170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE23_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE23_RX_WORK_STAT4_EO_PL                  , RULL(0x8003A0170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT1_EO_PL                     , RULL(0x800388020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x800388020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT1_EO_PL                   , RULL(0x800388020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT2_EO_PL                     , RULL(0x800390020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x800390020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT2_EO_PL                   , RULL(0x800390020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT3_EO_PL                     , RULL(0x800398020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x800398020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT3_EO_PL                   , RULL(0x800398020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE2_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE2_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE2_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT1_EO_PL                     , RULL(0x800388030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT1_EO_PL                   , RULL(0x800388030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT2_EO_PL                     , RULL(0x800390030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT2_EO_PL                   , RULL(0x800390030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT3_EO_PL                     , RULL(0x800398030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT3_EO_PL                   , RULL(0x800398030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE3_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE3_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE3_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT1_EO_PL                     , RULL(0x800388040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x800388040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT1_EO_PL                   , RULL(0x800388040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT2_EO_PL                     , RULL(0x800390040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x800390040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT2_EO_PL                   , RULL(0x800390040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT3_EO_PL                     , RULL(0x800398040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x800398040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT3_EO_PL                   , RULL(0x800398040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE4_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE4_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE4_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT1_EO_PL                     , RULL(0x800388050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT1_EO_PL                   , RULL(0x800388050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT2_EO_PL                     , RULL(0x800390050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT2_EO_PL                   , RULL(0x800390050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT3_EO_PL                     , RULL(0x800398050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT3_EO_PL                   , RULL(0x800398050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE5_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE5_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE5_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT1_EO_PL                     , RULL(0x800388060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x800388060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT1_EO_PL                   , RULL(0x800388060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT2_EO_PL                     , RULL(0x800390060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x800390060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT2_EO_PL                   , RULL(0x800390060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT3_EO_PL                     , RULL(0x800398060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x800398060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT3_EO_PL                   , RULL(0x800398060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE6_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE6_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE6_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT1_EO_PL                     , RULL(0x800388070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x800388070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT1_EO_PL                   , RULL(0x800388070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT2_EO_PL                     , RULL(0x800390070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x800390070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT2_EO_PL                   , RULL(0x800390070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT3_EO_PL                     , RULL(0x800398070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x800398070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT3_EO_PL                   , RULL(0x800398070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE7_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE7_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE7_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT1_EO_PL                     , RULL(0x800388080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT1_EO_PL                   , RULL(0x800388080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT2_EO_PL                     , RULL(0x800390080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT2_EO_PL                   , RULL(0x800390080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT3_EO_PL                     , RULL(0x800398080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT3_EO_PL                   , RULL(0x800398080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE8_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE8_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE8_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL              , RULL(0x800380090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_DATA_WORK_SPARE_MODE_PL            , RULL(0x800380090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL                  , RULL(0x800320090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_GLBSM_PL_CNTL1_O_PL                , RULL(0x800320090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL                  , RULL(0x800328090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_GLBSM_PL_STAT1_O_PL                , RULL(0x800328090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT1_EO_PL                     , RULL(0x800388090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x800388090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT1_EO_PL                   , RULL(0x800388090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT2_EO_PL                     , RULL(0x800390090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x800390090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT2_EO_PL                   , RULL(0x800390090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT3_EO_PL                     , RULL(0x800398090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x800398090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT3_EO_PL                   , RULL(0x800398090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX0_SLICE9_RX_WORK_STAT4_EO_PL                     , RULL(0x8003A0090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX0_SLICE9_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX0_SLICE9_RX_WORK_STAT4_EO_PL                   , RULL(0x8003A0090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_ERROR_INJECT_PB                             , RULL(0x800F98000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_ERROR_INJECT_PB                           , RULL(0x800F98000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_ERROR_INJECT_PB                           , RULL(0x800F98000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_MASK_PB                                     , RULL(0x800F90000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_MASK_PB                                   , RULL(0x800F90000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_MASK_PB                                   , RULL(0x800F90000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_PB                                          , RULL(0x800F88000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_PB                                        , RULL(0x800F88000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_PB                                        , RULL(0x800F88000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_RX_FIR_RESET_PB                                    , RULL(0x800F80000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_RX_FIR_RESET_PB                                  , RULL(0x800F80000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_RX_FIR_RESET_PB                                  , RULL(0x800F80000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_SCOM_MODE_PB                                       , RULL(0x09011020), SH_UNT_OBUS     , SH_ACS_SCOM      );
REG64( OBUS_0_SCOM_MODE_PB                                     , RULL(0x09011020), SH_UNT_OBUS_0   , SH_ACS_SCOM      );
REG64( OBUS_3_SCOM_MODE_PB                                     , RULL(0x0C011020), SH_UNT_OBUS_3   , SH_ACS_SCOM      );

REG64( OBUS_SPARE_MODE_PB                                      , RULL(0x800F34000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_SPARE_MODE_PB                                    , RULL(0x800F34000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_SPARE_MODE_PB                                    , RULL(0x800F34000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                   , RULL(0x800414000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_FIR_PL                      , RULL(0x800424000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_FIR_PL                    , RULL(0x800424000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                    , RULL(0x800404000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_MODE1_PL                  , RULL(0x800404000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                    , RULL(0x80040C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_MODE2_PL                  , RULL(0x80040C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                    , RULL(0x80041C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE0_TX_STAT1_PL                  , RULL(0x80041C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                   , RULL(0x800414010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_FIR_PL                      , RULL(0x800424010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_FIR_PL                    , RULL(0x800424010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                    , RULL(0x800404010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_MODE1_PL                  , RULL(0x800404010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                    , RULL(0x80040C010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_MODE2_PL                  , RULL(0x80040C010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                    , RULL(0x80041C010901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C010901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE1_TX_STAT1_PL                  , RULL(0x80041C010C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                   , RULL(0x800414020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_FIR_PL                      , RULL(0x800424020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_FIR_PL                    , RULL(0x800424020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                    , RULL(0x800404020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_MODE1_PL                  , RULL(0x800404020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                    , RULL(0x80040C020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_MODE2_PL                  , RULL(0x80040C020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                    , RULL(0x80041C020901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C020901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE2_TX_STAT1_PL                  , RULL(0x80041C020C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                   , RULL(0x800414030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_FIR_PL                      , RULL(0x800424030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_FIR_PL                    , RULL(0x800424030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                    , RULL(0x800404030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_MODE1_PL                  , RULL(0x800404030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                    , RULL(0x80040C030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_MODE2_PL                  , RULL(0x80040C030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                    , RULL(0x80041C030901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C030901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS0_SLICE3_TX_STAT1_PL                  , RULL(0x80041C030C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                   , RULL(0x800414040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_FIR_PL                      , RULL(0x800424040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_FIR_PL                    , RULL(0x800424040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                    , RULL(0x800404040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_MODE1_PL                  , RULL(0x800404040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                    , RULL(0x80040C040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_MODE2_PL                  , RULL(0x80040C040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                    , RULL(0x80041C040901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C040901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE0_TX_STAT1_PL                  , RULL(0x80041C040C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                   , RULL(0x800414050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_FIR_PL                      , RULL(0x800424050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_FIR_PL                    , RULL(0x800424050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                    , RULL(0x800404050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_MODE1_PL                  , RULL(0x800404050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                    , RULL(0x80040C050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_MODE2_PL                  , RULL(0x80040C050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                    , RULL(0x80041C050901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C050901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE1_TX_STAT1_PL                  , RULL(0x80041C050C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                   , RULL(0x800414060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_FIR_PL                      , RULL(0x800424060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_FIR_PL                    , RULL(0x800424060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                    , RULL(0x800404060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_MODE1_PL                  , RULL(0x800404060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                    , RULL(0x80040C060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_MODE2_PL                  , RULL(0x80040C060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                    , RULL(0x80041C060901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C060901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE2_TX_STAT1_PL                  , RULL(0x80041C060C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                   , RULL(0x800414070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_FIR_PL                      , RULL(0x800424070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_FIR_PL                    , RULL(0x800424070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                    , RULL(0x800404070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_MODE1_PL                  , RULL(0x800404070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                    , RULL(0x80040C070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_MODE2_PL                  , RULL(0x80040C070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                    , RULL(0x80041C070901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C070901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS1_SLICE3_TX_STAT1_PL                  , RULL(0x80041C070C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                   , RULL(0x800414080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_FIR_PL                      , RULL(0x800424080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_FIR_PL                    , RULL(0x800424080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                    , RULL(0x800404080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_MODE1_PL                  , RULL(0x800404080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                    , RULL(0x80040C080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_MODE2_PL                  , RULL(0x80040C080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                    , RULL(0x80041C080901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C080901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE0_TX_STAT1_PL                  , RULL(0x80041C080C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                   , RULL(0x800414090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_FIR_PL                      , RULL(0x800424090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_FIR_PL                    , RULL(0x800424090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                    , RULL(0x800404090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_MODE1_PL                  , RULL(0x800404090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                    , RULL(0x80040C090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_MODE2_PL                  , RULL(0x80040C090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                    , RULL(0x80041C090901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C090901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE1_TX_STAT1_PL                  , RULL(0x80041C090C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C0A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_FIR_PL                      , RULL(0x8004240A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004240A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_FIR_PL                    , RULL(0x8004240A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                    , RULL(0x8004040A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004040A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_MODE1_PL                  , RULL(0x8004040A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0A0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0A0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0A0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C0B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_FIR_PL                      , RULL(0x8004240B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004240B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_FIR_PL                    , RULL(0x8004240B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                    , RULL(0x8004040B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004040B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_MODE1_PL                  , RULL(0x8004040B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0B0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0B0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS2_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0B0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                   , RULL(0x8004140C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_CNTL1G_PL                 , RULL(0x8004140C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C0C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C0C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C0C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C0C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_FIR_PL                      , RULL(0x8004240C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004240C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_FIR_PL                    , RULL(0x8004240C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                    , RULL(0x8004040C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004040C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_MODE1_PL                  , RULL(0x8004040C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                    , RULL(0x80040C0C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_MODE2_PL                  , RULL(0x80040C0C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                    , RULL(0x80041C0C0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0C0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE0_TX_STAT1_PL                  , RULL(0x80041C0C0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                   , RULL(0x8004140D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_CNTL1G_PL                 , RULL(0x8004140D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C0D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C0D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C0D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C0D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_FIR_PL                      , RULL(0x8004240D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004240D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_FIR_PL                    , RULL(0x8004240D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                    , RULL(0x8004040D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004040D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_MODE1_PL                  , RULL(0x8004040D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                    , RULL(0x80040C0D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_MODE2_PL                  , RULL(0x80040C0D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                    , RULL(0x80041C0D0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0D0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE1_TX_STAT1_PL                  , RULL(0x80041C0D0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                   , RULL(0x8004140E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_CNTL1G_PL                 , RULL(0x8004140E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C0E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C0E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C0E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C0E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_FIR_PL                      , RULL(0x8004240E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004240E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_FIR_PL                    , RULL(0x8004240E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                    , RULL(0x8004040E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004040E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_MODE1_PL                  , RULL(0x8004040E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                    , RULL(0x80040C0E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_MODE2_PL                  , RULL(0x80040C0E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                    , RULL(0x80041C0E0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0E0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE2_TX_STAT1_PL                  , RULL(0x80041C0E0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                   , RULL(0x8004140F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_CNTL1G_PL                 , RULL(0x8004140F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C0F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C0F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x8004340F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x8004340F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C0F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C0F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_FIR_PL                      , RULL(0x8004240F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004240F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_FIR_PL                    , RULL(0x8004240F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                    , RULL(0x8004040F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004040F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_MODE1_PL                  , RULL(0x8004040F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                    , RULL(0x80040C0F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_MODE2_PL                  , RULL(0x80040C0F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                    , RULL(0x80041C0F0901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0F0901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS3_SLICE3_TX_STAT1_PL                  , RULL(0x80041C0F0C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL                   , RULL(0x800414100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_FIR_PL                      , RULL(0x800424100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_FIR_PL                    , RULL(0x800424100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_FIR_PL                    , RULL(0x800424100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_MODE1_PL                    , RULL(0x800404100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_MODE1_PL                  , RULL(0x800404100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_MODE1_PL                  , RULL(0x800404100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_MODE2_PL                    , RULL(0x80040C100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_MODE2_PL                  , RULL(0x80040C100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_MODE2_PL                  , RULL(0x80040C100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE0_TX_STAT1_PL                    , RULL(0x80041C100901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE0_TX_STAT1_PL                  , RULL(0x80041C100901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE0_TX_STAT1_PL                  , RULL(0x80041C100C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL                   , RULL(0x800414110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_FIR_PL                      , RULL(0x800424110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_FIR_PL                    , RULL(0x800424110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_FIR_PL                    , RULL(0x800424110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_MODE1_PL                    , RULL(0x800404110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_MODE1_PL                  , RULL(0x800404110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_MODE1_PL                  , RULL(0x800404110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_MODE2_PL                    , RULL(0x80040C110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_MODE2_PL                  , RULL(0x80040C110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_MODE2_PL                  , RULL(0x80040C110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE1_TX_STAT1_PL                    , RULL(0x80041C110901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE1_TX_STAT1_PL                  , RULL(0x80041C110901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE1_TX_STAT1_PL                  , RULL(0x80041C110C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL                   , RULL(0x800414120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_FIR_PL                      , RULL(0x800424120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_FIR_PL                    , RULL(0x800424120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_FIR_PL                    , RULL(0x800424120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_MODE1_PL                    , RULL(0x800404120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_MODE1_PL                  , RULL(0x800404120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_MODE1_PL                  , RULL(0x800404120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_MODE2_PL                    , RULL(0x80040C120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_MODE2_PL                  , RULL(0x80040C120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_MODE2_PL                  , RULL(0x80040C120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE2_TX_STAT1_PL                    , RULL(0x80041C120901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE2_TX_STAT1_PL                  , RULL(0x80041C120901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE2_TX_STAT1_PL                  , RULL(0x80041C120C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL                   , RULL(0x800414130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_FIR_PL                      , RULL(0x800424130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_FIR_PL                    , RULL(0x800424130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_FIR_PL                    , RULL(0x800424130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_MODE1_PL                    , RULL(0x800404130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_MODE1_PL                  , RULL(0x800404130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_MODE1_PL                  , RULL(0x800404130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_MODE2_PL                    , RULL(0x80040C130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_MODE2_PL                  , RULL(0x80040C130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_MODE2_PL                  , RULL(0x80040C130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS4_SLICE3_TX_STAT1_PL                    , RULL(0x80041C130901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS4_SLICE3_TX_STAT1_PL                  , RULL(0x80041C130901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS4_SLICE3_TX_STAT1_PL                  , RULL(0x80041C130C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL                   , RULL(0x800414140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_CNTL1G_PL                 , RULL(0x800414140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL                  , RULL(0x80044C140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_CNTL2_O_PL                , RULL(0x80044C140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL                 , RULL(0x80042C140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_FIR_MASK_PL               , RULL(0x80042C140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_FIR_PL                      , RULL(0x800424140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_FIR_PL                    , RULL(0x800424140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_FIR_PL                    , RULL(0x800424140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_MODE1_PL                    , RULL(0x800404140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_MODE1_PL                  , RULL(0x800404140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_MODE1_PL                  , RULL(0x800404140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_MODE2_PL                    , RULL(0x80040C140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_MODE2_PL                  , RULL(0x80040C140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_MODE2_PL                  , RULL(0x80040C140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE0_TX_STAT1_PL                    , RULL(0x80041C140901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE0_TX_STAT1_PL                  , RULL(0x80041C140901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE0_TX_STAT1_PL                  , RULL(0x80041C140C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL                   , RULL(0x800414150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_CNTL1G_PL                 , RULL(0x800414150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL                  , RULL(0x80044C150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_CNTL2_O_PL                , RULL(0x80044C150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL                 , RULL(0x80042C150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_FIR_MASK_PL               , RULL(0x80042C150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_FIR_PL                      , RULL(0x800424150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_FIR_PL                    , RULL(0x800424150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_FIR_PL                    , RULL(0x800424150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_MODE1_PL                    , RULL(0x800404150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_MODE1_PL                  , RULL(0x800404150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_MODE1_PL                  , RULL(0x800404150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_MODE2_PL                    , RULL(0x80040C150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_MODE2_PL                  , RULL(0x80040C150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_MODE2_PL                  , RULL(0x80040C150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE1_TX_STAT1_PL                    , RULL(0x80041C150901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE1_TX_STAT1_PL                  , RULL(0x80041C150901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE1_TX_STAT1_PL                  , RULL(0x80041C150C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL                   , RULL(0x800414160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_CNTL1G_PL                 , RULL(0x800414160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL                  , RULL(0x80044C160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_CNTL2_O_PL                , RULL(0x80044C160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL                 , RULL(0x80042C160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_FIR_MASK_PL               , RULL(0x80042C160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_FIR_PL                      , RULL(0x800424160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_FIR_PL                    , RULL(0x800424160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_FIR_PL                    , RULL(0x800424160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_MODE1_PL                    , RULL(0x800404160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_MODE1_PL                  , RULL(0x800404160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_MODE1_PL                  , RULL(0x800404160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_MODE2_PL                    , RULL(0x80040C160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_MODE2_PL                  , RULL(0x80040C160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_MODE2_PL                  , RULL(0x80040C160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE2_TX_STAT1_PL                    , RULL(0x80041C160901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE2_TX_STAT1_PL                  , RULL(0x80041C160901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE2_TX_STAT1_PL                  , RULL(0x80041C160C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL                   , RULL(0x800414170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_CNTL1G_PL                 , RULL(0x800414170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL                  , RULL(0x80044C170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_CNTL2_O_PL                , RULL(0x80044C170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL         , RULL(0x800434170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_FIR_ERROR_INJECT_PL       , RULL(0x800434170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL                 , RULL(0x80042C170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_FIR_MASK_PL               , RULL(0x80042C170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_FIR_PL                      , RULL(0x800424170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_FIR_PL                    , RULL(0x800424170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_FIR_PL                    , RULL(0x800424170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_MODE1_PL                    , RULL(0x800404170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_MODE1_PL                  , RULL(0x800404170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_MODE1_PL                  , RULL(0x800404170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_MODE2_PL                    , RULL(0x80040C170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_MODE2_PL                  , RULL(0x80040C170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_MODE2_PL                  , RULL(0x80040C170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TXPACKS5_SLICE3_TX_STAT1_PL                    , RULL(0x80041C170901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TXPACKS5_SLICE3_TX_STAT1_PL                  , RULL(0x80041C170901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TXPACKS5_SLICE3_TX_STAT1_PL                  , RULL(0x80041C170C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL1_EO_PG                           , RULL(0x800D34000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL1_EO_PG                         , RULL(0x800D34000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL1_O_PG                            , RULL(0x800D84000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL1_O_PG                          , RULL(0x800D84000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL1_O_PG                          , RULL(0x800D84000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL2_EO_PG                           , RULL(0x800D3C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL2_EO_PG                         , RULL(0x800D3C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL2_O_PG                            , RULL(0x800D8C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL2_O_PG                          , RULL(0x800D8C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL2_O_PG                          , RULL(0x800D8C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL3_EO_PG                           , RULL(0x800D44000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL3_EO_PG                         , RULL(0x800D44000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL4_EO_PG                           , RULL(0x800D4C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL4_EO_PG                         , RULL(0x800D4C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL5_EO_PG                           , RULL(0x800D54000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL5_EO_PG                         , RULL(0x800D54000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL6_EO_PG                           , RULL(0x800D5C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL6_EO_PG                         , RULL(0x800D5C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_CNTL7_EO_PG                           , RULL(0x800D64000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_CNTL7_EO_PG                         , RULL(0x800D64000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_MODE1_EO_PG                           , RULL(0x800D2C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_MODE1_EO_PG                         , RULL(0x800D2C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_SPARE_MODE_PG                         , RULL(0x800D24000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_SPARE_MODE_PG                       , RULL(0x800D24000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTLSM_STAT1_EO_PG                           , RULL(0x800D6C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTLSM_STAT1_EO_PG                         , RULL(0x800D6C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL2_EO_PG                             , RULL(0x800C2C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL2_EO_PG                           , RULL(0x800C2C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTL3_EO_PG                             , RULL(0x800C34000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTL3_EO_PG                           , RULL(0x800C34000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_CNTLG1_EO_PG                            , RULL(0x800C24000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_CNTLG1_EO_PG                          , RULL(0x800C24000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_CTL_MODE1_EO_PG                             , RULL(0x800C14000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_CTL_MODE1_EO_PG                           , RULL(0x800C14000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_ERROR_INJECT_PG                         , RULL(0x800D1C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_ERROR_INJECT_PG                       , RULL(0x800D1C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_MASK_PG                                 , RULL(0x800D0C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_MASK_PG                               , RULL(0x800D0C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_MASK_PG                               , RULL(0x800D0C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_PG                                      , RULL(0x800D04000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_PG                                    , RULL(0x800D04000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_PG                                    , RULL(0x800D04000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_FIR_RESET_PG                                , RULL(0x800D14000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_FIR_RESET_PG                              , RULL(0x800D14000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_FIR_RESET_PG                              , RULL(0x800D14000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_ID1_PG                                      , RULL(0x800C0C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_ID1_PG                                    , RULL(0x800C0C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_ID1_PG                                    , RULL(0x800C0C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX0_TX_SPARE_MODE_PG                               , RULL(0x800C04000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX0_TX_SPARE_MODE_PG                             , RULL(0x800C04000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX0_TX_SPARE_MODE_PG                             , RULL(0x800C04000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL2_PB                                      , RULL(0x800F3C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL2_PB                                    , RULL(0x800F3C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL2_PB                                    , RULL(0x800F3C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_NVAL_PB                                  , RULL(0x800F0C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_NVAL_PB                                , RULL(0x800F0C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_NVAL_PB                                , RULL(0x800F0C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_PB                                       , RULL(0x800F04000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_PB                                     , RULL(0x800F04000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_PB                                     , RULL(0x800F04000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_PVAL_PB                                  , RULL(0x800F14000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_PVAL_PB                                , RULL(0x800F14000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_PVAL_PB                                , RULL(0x800F14000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_P_4X_PB                                  , RULL(0x800F1C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_P_4X_PB                                , RULL(0x800F1C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_P_4X_PB                                , RULL(0x800F1C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_SWO1_PB                                  , RULL(0x800F24000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_SWO1_PB                                , RULL(0x800F24000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_SWO1_PB                                , RULL(0x800F24000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );

REG64( OBUS_TX_IMPCAL_SWO2_PB                                  , RULL(0x800F2C000901103F), SH_UNT_OBUS     ,
       SH_ACS_SCOM      );
REG64( OBUS_0_TX_IMPCAL_SWO2_PB                                , RULL(0x800F2C000901103F), SH_UNT_OBUS_0   ,
       SH_ACS_SCOM      );
REG64( OBUS_3_TX_IMPCAL_SWO2_PB                                , RULL(0x800F2C000C01103F), SH_UNT_OBUS_3   ,
       SH_ACS_SCOM      );
#endif


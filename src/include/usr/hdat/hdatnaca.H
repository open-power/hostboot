/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hdat/hdatnaca.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef HDATNACA_H
#define HDATNACA_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include <hdat/hdat.H>
#include <errl/errlentry.H>
#include <hdat/hdat_reasoncodes.H>
//#include <../../../usr/hdat/hdatutil.H>

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
const uint32_t HDAT_NACA_OFFSET = 0x00004000;  // offset in primary LID and
                                               // mainstore where NACA starts.

/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

/** @brief Type definition defines for Node Address Communication Area (NACA).
 *
 * The NACA is a data structure used primarily by the host operating system.
 * The NACA is prebuilt as part of the primary host LID.  FipS uses several
 * fields in the NACA to determine where the LID table and the Service
 * Processor Interace Root Array (SPIRA) reside. Fields which are not used by
 * FipS are just defined as reserved so that we don't have to chase
 * uninteresting changes the host OS may make to things FipS does not care
 * about.
 *
 */
struct hdatNaca_t
{
    hdatMsAddr_t nacaOpalMasterThreadEntry; // 0x0000 Reserved for PHYP, Will
                                            // be kludge in for OPAL by HDAT.

    hdatMsAddr_t nacaOpalSecThreadEntry;    // 0x0008 Reserved for PHYP, Will
                                            // be kludge in for OPAL by HDAT.

    hdatMsAddr_t nacaOpalPrimLidLoadAddr;   // 0x0010 Reserved for PHYP, Will
                                            // be kludge in for OPAL by HDAT.

    hdatMsAddr_t nacaHypRelData;            // 0x0018 Hypervisor release data
                                            // structure pointer.

    hdatMsAddr_t nacaOpalCopyCodeAddr;      // 0x0020 Reserved for PHYP, Will
                                            // be kludge in for OPAL by HDAT.

    uint8_t      nacaReserved2[8];          // 0x0028 reserved space.

    hdatMsAddr_t nacaSpira;                 // 0x0030 Service Processor
                                            // Interface Root Array pointer
                                            // -- also used for OPAL.
                                            // The SPIRA may be in the primary
                                            // host LID or secondary host LID.
                                            // Since we do not know, it must be
                                            // DMA'd back from main memory ater
                                            // all LIDS are loaded.

    hdatMsAddr_t nacaLidTbl;                // 0x0038 LID table pointer.The LID
                                            // table is always contained within
                                            // the primary host LID.

    uint8_t     nacaReserved3[96];          // 0x0040 reserved space.

    uint32_t    nacaSpiraSize;              // 0x00A0 Actual SPIRA size bytes.

    uint8_t     nacaReserved4[28];          // 0x00A4 reserved space.

    hdatMsAddr_t nacaHypLoadMap;            // 0x00C0 Hypervisor resident
                                            // module load map pointer.

    uint8_t      nacaReserved5[228];        // 0x00C8 reserved space.

    uint8_t      nacaFlags[4];              // 0x01AC Flags to control FSP
                                            // function.  This is defined this
                                            // way rather than a uint32_t bit
                                            // field so that we avoid
                                            // little/big endian issues when
                                            // testing with an x86 simulator.

    uint8_t      nacaReserved6[5];          // 0x01B0 reserved space.

    uint8_t      nacaSftAttn;               // 0x01B5 Software attentions
                                            // enabled; used by CPU controls.
                                            // See constant NACA_ATTN_DISABLED
                                            // above for testing this field.

    uint8_t      nacaReserved7[1];          // 0x01B6 Reserved area.

    uint8_t      nacaPhypPciaSupport;       // 0x01B7 PHYP supports PCIA
                                            // format if non-zero
} __attribute__ ((packed));

/**
 * @brief This function maps the Node Address Communication Area (NACA)
 * structure from the main memory where LID file are alaready loaded from the
 * pnor PAYLOAD partition.
 *
 * Usage note:  The NACA structure is built as part of the host LIDs.
 *      These are big endian structures. If this structure is used on a little
 *      endian machine, the user is responsible for performing big endian to
 *      little endian conversions.
 *
 * @pre The current implementation depends upon the fact that the pnor PAYLOAD
 * is built with the LID file and pnor PAYLOAD partition is loaded into Host
 * memory
 *
 * @post The naca data is read from the host memory to o_naca object.
 *
 * @param o_naca - output parameter - The address of the NACA is returned.
 *
 * @return A null error log handle if successful, else errlHndl_t returned.
 *
 */
errlHndl_t hdatGetNacaFromMem(hdatNaca_t &o_naca);

/* @brief interface function to be called fromistep
 */
void *  call_hdat_steps( void *io_pArgs );


/*The following structures and functions are used for purely DISPLAY purpose
 */

const uint32_t HDAT_SVC_RTNS = 3;
const uint32_t HDAT_SVC_RTN_LAST = 4;

/** @brief Type definition for the Service Routines data area
 */
struct hdatSvcRoutines_t
{
    hdatMsAddr_t  hdatCompAddr; //mainstore address compare address
    uint16_t      hdatCompOp;   //mainstore address compare operation
    uint16_t      hdatCompLen;  //mainstore address compare length
    uint32_t      hdatCompData; //mainstore address compare data
    hdatMsAddr_t  hdatCompSR;   //mainstore address compare service routine
    hdatMsAddr_t  hdatDspAltSr; //mainstore display/alter service routine
    uint8_t       hdatRsvd1[8]; //reserved for future use
    hdatMsAddr_t  hdatMsDumpSR; //mainstore dump service routine
    hdatMsAddr_t  hdatRealValSR;//real address validation service routine
    hdatMsAddr_t  hdatEffAddr;  //effective address
    hdatMsAddr_t  hdatCpuSpinSR;//CPU spin service routine
    hdatMsAddr_t  hdatSpGlueSR; //service processor glue service routine
    uint8_t       hdatRsvd2[16];//reserved for future use
    uint8_t       hdatTimeBaseFlags[8]; // time base flags
    uint8_t       hdatRsvd3[8];         // reserved for future use
    hdatMsAddr_t  hdatTdeAddrParm;      // TDE address parameter
    hdatMsAddr_t  hdatShrProcSR;        // SDR1 shared processor service routine
    uint8_t       hdatRsvd4[20];        // reserved for future use
    uint16_t      hdatAddrType;         // address type for compare
    uint8_t       hdatRsvd5[10];        // reserved for future use
    hdatMsAddr_t  hdatCacheFlshSR;      // cache flush service routine
    uint8_t       hdatRsvd6[88];        // reserved for future use
} __attribute__ ((packed));

/** @brief The CPU Controls data area is composed of an array of structures
 * The structure contains the mainstore address of a service routine's
 * information as well as an 8 byte length of the information at that address
 */
struct hdatSRAddrLen_t
{
    hdatMsAddr_t  hdatSsrPtr;   // address of service routine info
    uint32_t      hdatSsrLenHi; // high order 4 bytes of routine info length
    uint32_t      hdatSsrLenLo; // low order 4 bytes of routine info length
}__attribute__ ((packed));

/** type definition for the cpu control area
 */
struct hdatCpuCtrlArea_t
{
    hdatHDIF_t         hdatHDIF;
    hdatHDIFDataHdr_t  hdatDataHdr;
    uint8_t            hdatRsvd1[8];
    hdatSRAddrLen_t    hdatSR[HDAT_SVC_RTN_LAST];
}__attribute__ ((packed));

/*
 * to display the cpu control area and service routine area in trace
 */
void hdatGetCpuCtrlFromMem(hdatMsAddr_t i_msAddr, uint32_t i_size);




} //namespace HDAT
#endif // HDATNACA_H

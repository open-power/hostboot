/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/bootconfigif.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __INITSERVICE_BOOTCONFIGIF_H
#define __INITSERVICE_BOOTCONFIGIF_H

#include <trace/interface.H>
#include <errl/errlentry.H>

extern trace_desc_t *g_trac_initsvc;
namespace INITSERVICE
{
namespace BOOTCONFIG
{
    /**
     * @brief  Identifier for the first version layout of the SIO register boot
     *         flags.
     */
    const uint8_t BOOT_FLAGS_VERSION_1 = 0x42;

    extern uint8_t CURRENT_CONFIG_VERSION;

    /* Protocol to use
     * Boot flags                               (SIO 0x29, or ATTR override)
     *  SIO bit 0 indicates istep mode when 0b1
     * Istep control                            (SIO 0x2a, CFAM 283B)
     *  bit 0 -- ready bit
     *  bit 1 -- go bit
     *  bit 2 -- running bit
     *  bit 3:7 -- key
     * Istep major Number                       (SIO 0x2b, CFAM 283B)
     * Istep minor Number                       (SIO 0x2c, CFAM 283B)
     * Istep status from Hostboot               (SIO 0x26, CFAM 283B)
     *  bit 0-7 -- return code after istep is done -- 0 is good
     * Istep control response from Hostboot     (SIO 0x27, CFAM 283B)
     *  bit 0 -- ready bit
     *  bit 1 -- go bit
     *  bit 2 -- running bit
     *  bit 3:7 -- key
     *
     *
     * NOTE: when using the CFAM mechanism all communication is done in 283B
     *       and the byte fields correspond:
     *          byte 0: SIO 0x2a(read), 0x26 (write)
     *          byte 1: SIO 0x27
     *          byte 2: SIO 0x2b
     *          byte 3: SIO 0x2c
     ***********************************************************************
     *Protocol definition -- it is a little odd since hostboot can't
     *write the normal control register (0x2a) so 0x27 acts as hostboot's
     *writable register
     *
     * 1) prior to powering on set the SIO registers into istep mode
     *ipmitool -H <BMC IP> -I lan -U ADMIN -P admin raw 0x3a 0x06 0x01
     *                                  0x28 0x42 0x29 0x80 0x2d 0x40
     * 2) Power on
     *ipmitool -H <BMC IP> -I lan -U admin -P admin chassis power on
     *
     * 3) Wait for Hostboot to turn on the ready bit and key -- SIO 0x27
     *bit 0 on, save away bits 3:7
     *ipmitool -H <BMC IP> -I lan -U ADMIN -P admin raw 0x3a 0x06 0x00 0x27
     *      bit 0 -> ready
     *      bit 3:7 -> key
     *
     * 4) Start istep where 0x2b is major, 0x2c is minor and 0x2a is
     *copy of 0x27 plus bit 1 is on.  It is CRITICAL that go bit and key
     *from 0x27 are set
     *ipmitool -H <BMC IP> -I lan -U ADMIN -P admin raw 0x3a 0x06 0x01
     *                            0x2b 0xMM 0x2c 0xmm 0x2a <0x40 | key> #6.2
     *
     * 5) Hostboot will set the running bit (bit 2) in 0x27 and clear the
     *   ready/go/key bits.  Poll until ready bit comes back on
     *
     *ipmitool -H <BMC IP> -I lan -U ADMIN -P admin raw 0x3a 0x06 0x00 0x27 0x26
     *       0x27:bit 2 -> indicates istep is running
     *       0x27:bit 0 -> ready indicates done
     *       0x27:bit 3:7 -> next key to use  (valid if ready bit is on)
     *       0x26:bit 0:7 -> status of last command (valid when ready bit is on
     *                                                   and running bit is off)
     *
     * 6) Repeat
     *
     */

    typedef struct istepCtl
    {
        uint8_t istepControl;
        uint8_t istepStatus;
        uint8_t istepMajorNumber;
        uint8_t istepMinorNumber;

        //  init struct to 0
        istepCtl() :istepControl(0), istepStatus(0),
                          istepMajorNumber(0), istepMinorNumber(0) {};
    }istepControl_t;

    // This function will call the actual config class created, or the base
    // class if non has been created.
    errlHndl_t readAndProcessBootConfig();

    // Calls the actual subclass or base class if no config class has been
    // created
    errlHndl_t readIstepControl( BOOTCONFIG::istepControl_t & o_info );

    // Calls the actual subclass or base class if no config class has been
    // created
    errlHndl_t writeIstepControl( BOOTCONFIG::istepControl_t   i_info );

};
};// end namespace
#endif



/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/settings.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include <secureboot/settings.H>
#include <p8_scom_addresses.H>
#include <errl/errlmanager.H>
#include <config.h>
#include <targeting/common/util.H>

// SECUREBOOT : General driver traces
extern trace_desc_t* g_trac_secure;

namespace SECUREBOOT
{

    using namespace TARGETING;
    using namespace ERRORLOG;

    #ifdef CONFIG_SECUREBOOT
    // array indexes for the bar value scom addresses
    enum {
             BAR_PBA_ADDR_IDX = 0,
             BAR_PBA_SIZE_IDX,
             BAR_PSI_ADDR0_IDX,
             BAR_PSI_ADDR1_IDX,
             BAR_PSI_SIZE0_IDX,
             BAR_PSI_SIZE1_IDX,
             BAR_ADU_ADDR_IDX,
             BAR_ADU_SIZE_IDX,
             NUM_BAR_VALUES,
    };

    enum {
        BAR_SCOM_INITIAL = PBA_BAR3_0x02013F03,
    };

    // use a table of deltas instead of absolutes to make the table smaller
    // allowing the use of uint16_t (instead of uint64_t) to use less pnor space
    const uint16_t g_barScomDeltas[] =
    {
        PBA_BARMSK3_0x02013F07 - PBA_BAR3_0x02013F03,
        PSI_NOTRUST_BAR0_0x02013F40 - PBA_BARMSK3_0x02013F07,
        PSI_NOTRUST_BAR1_0x02013F41 - PSI_NOTRUST_BAR0_0x02013F40,
        PSI_NOTRUST_BAR0_MASK_0x02013F42 - PSI_NOTRUST_BAR1_0x02013F41,
        PSI_NOTRUST_BAR1_MASK_0x02013F43 - PSI_NOTRUST_BAR0_MASK_0x02013F42,
        ADU_UNTRUSTED_BAR_0x02020015 - PSI_NOTRUST_BAR1_MASK_0x02013F43,
        ADU_UNTRUSTED_BAR_MASK_0x02020016 - ADU_UNTRUSTED_BAR_0x02020015,
        0, // padded with zero
    };

    // use a table to translate indexes into attribute ids
    // which will take less pnor space then a switch statement
    const uint32_t g_indexToAttrId[] =
    {
        ATTR_PROC_PBA_UNTRUSTED_BAR_BASE_ADDR,
        ATTR_PROC_PBA_UNTRUSTED_BAR_SIZE,
        ATTR_PROC_PSI_UNTRUSTED_BAR0_BASE_ADDR,
        ATTR_PROC_PSI_UNTRUSTED_BAR1_BASE_ADDR,
        ATTR_PROC_PSI_UNTRUSTED_BAR0_SIZE,
        ATTR_PROC_PSI_UNTRUSTED_BAR1_SIZE,
        ATTR_PROC_ADU_UNTRUSTED_BAR_BASE_ADDR,
        ATTR_PROC_ADU_UNTRUSTED_BAR_SIZE,
    };
    #endif

    void Settings::_init()
    {
        errlHndl_t l_errl = NULL;
        size_t size = sizeof(iv_regValue);

        // Read / cache security switch setting from processor.
        l_errl = deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            &iv_regValue, size,
                            DEVICE_SCOM_ADDRESS(PROC_SECURITY_SWITCH_REGISTER));

        // If this errors, we're in bad shape and shouldn't trust anything.
        assert(NULL == l_errl);

        #ifdef CONFIG_SECUREBOOT
        readProcBars(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
        #endif
    }

    #ifdef CONFIG_SECUREBOOT
    void Settings::readProcBars(TARGETING::Target* i_targ)
    {
        errlHndl_t l_errl = NULL;

        // assert that we have a valid target pointer
        assert(i_targ != NULL, "supplied target pointer is NULL");
        assert(i_targ == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL ||
            i_targ->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
            "supplied target is not a processor target");

        // Read / cache non-secure bar values

        // Obtain a reference to the array of bar values that
        // correspondes with the given target.
        // Since it is a reference, modifying it also modifies the
        // pointer where we got it from.
        uint64_t*& l_barValues = iv_barValues[i_targ];

        size_t size = sizeof(uint64_t);

        if (!l_barValues)
        {
            l_barValues = new uint64_t[NUM_BAR_VALUES]();
        }

        uint64_t l_scom = BAR_SCOM_INITIAL;

        for (int i=0; i < NUM_BAR_VALUES; i++)
        {
            l_errl = deviceRead(i_targ,
                            l_barValues + i, size,
                            DEVICE_SCOM_ADDRESS(l_scom));
            if (l_errl)
            {
                errlCommit(l_errl, SECURE_COMP_ID);
                assert(false, "readProcBars: deviceRead returned error log - "
                    "connot continue");
            }
            assert(size == sizeof(uint64_t), "scom returned bad size");
            l_scom += g_barScomDeltas[i];
        }
    }

    errlHndl_t Settings::procBarValuesMatch(TARGETING::Target* i_targ)
    {
        errlHndl_t l_errl = NULL;

        assert(i_targ != NULL,"supplied target pointer is NULL");
        assert(i_targ == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL ||
            i_targ->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
            "supplied target is not a processor target");

        TARGETING::Target* l_proc = NULL;
        l_errl = targetService().queryMasterProcChipTargetHandle(l_proc);
        if (l_errl)
        {
            errlCommit(l_errl, SECURE_COMP_ID);
            assert(false, "tS.queryMasterProcChipTargetHandle "
                "returned errl for masterProcChipTargetHandle");
        }
        // if the given target is the master
        if (i_targ == l_proc)
        {
            // always use the master processor chip sentinel
            // for accessing the map of bar values
            l_proc = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        }
        else
        {
            // otherwise use the given target for the lookup
            l_proc = i_targ;
        }

        // lookup the processor target in the map and obtain a pointer to the
        // array of bar values
        std::map<TARGETING::Target*,uint64_t*>::const_iterator
            l_iter = iv_barValues.find(l_proc);
        if (l_iter == iv_barValues.end())
        {
            assert(false, "readProcBars never called for target");
        }
        uint64_t* l_cachedBars = l_iter->second;

        uint64_t l_bars[NUM_BAR_VALUES]; // eight bar values total

        l_bars[BAR_PBA_ADDR_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_PBA_UNTRUSTED_BAR_BASE_ADDR>();
        l_bars[BAR_PBA_SIZE_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_PBA_UNTRUSTED_BAR_SIZE>();
        l_bars[BAR_PSI_ADDR0_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_PSI_UNTRUSTED_BAR0_BASE_ADDR>();
        l_bars[BAR_PSI_ADDR1_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_PSI_UNTRUSTED_BAR1_BASE_ADDR>();
        l_bars[BAR_PSI_SIZE0_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_PSI_UNTRUSTED_BAR0_SIZE>();
        l_bars[BAR_PSI_SIZE1_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_PSI_UNTRUSTED_BAR1_SIZE>();
        l_bars[BAR_ADU_ADDR_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_ADU_UNTRUSTED_BAR_BASE_ADDR>();
        l_bars[BAR_ADU_SIZE_IDX] = i_targ->getAttr<
                         TARGETING::ATTR_PROC_ADU_UNTRUSTED_BAR_SIZE>();

        // Check each attr bar value against its register bar value
        // for equivalency. Throw an error on mismatch.
        bool l_result = true;
        uint64_t* l_barStop = l_bars + NUM_BAR_VALUES;
        // use pointer arithmetic instead of array indexing which
        // will result in less multiplies
        uint64_t* l_regBar = l_cachedBars;
        uint64_t* l_attrBar = l_bars;
        for (;l_attrBar < l_barStop; l_regBar++, l_attrBar++)
        {
            if (*l_regBar != *l_attrBar)
            {
                l_result = false;
                break;
            }
        }

        if (!l_result)
        {
            // grab the index value from the loop iterators
            int index = l_regBar - l_cachedBars;
            // pull attribute id from static table
            uint64_t l_attrId = g_indexToAttrId[index];
            /*@
             * @errortype
             * @moduleid         SECUREBOOT::MOD_SECURE_SETTINGS
             * @reasoncode       SECUREBOOT::RC_SECURE_BAR_CHECK_FAIL
             * @userdata1[0:31]  Processor HUID with BAR mismatch
             * @userdata1[32:63] The attribute ID that was mismatched.
             * @userdata2[0:63]  Bad bar value
             * @devdesc          Failure to match the bar values with the
             *                   expected bar values.
             *
             * @custdesc         System security violation detected.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         SECUREBOOT::MOD_SECURE_SETTINGS,
                                         SECUREBOOT::RC_SECURE_BAR_CHECK_FAIL,
                                         TWO_UINT32_TO_UINT64(
                                            TARGETING::get_huid(i_targ),
                                            l_attrId),
                                         *l_regBar,
                                         true /* Add HB Software Callout */ );
            l_errl->collectTrace(SECURE_COMP_NAME,256);
        }
        return l_errl;
    }

    errlHndl_t Settings::lockProcUntrustedBars(
        const TARGETING::Target* const i_pProc)
    {
        errlHndl_t pError = NULL;

        assert(i_pProc != NULL,"Requested target handle is NULL");
        assert((   (i_pProc == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
                || (   i_pProc->getAttr<TARGETING::ATTR_TYPE>()
                    == TARGETING::TYPE_PROC)),
              "Requested target handle is of type 0x%08X, not of type PROC",
              i_pProc->getAttr<TARGETING::ATTR_TYPE>());

        const uint32_t untrustedBarSizeRegs[] =
        {
            PBA_BARMSK3_0x02013F07,
            PSI_NOTRUST_BAR0_MASK_0x02013F42,
            PSI_NOTRUST_BAR1_MASK_0x02013F43,
            ADU_UNTRUSTED_BAR_MASK_0x02020016,
        };

        if( is_sapphire_load())
        {
            const uint64_t scomData = 0;
            const size_t expSize = sizeof(scomData);
            size_t size = expSize;

            const uint32_t* const begin = untrustedBarSizeRegs;
            const uint32_t* const end = untrustedBarSizeRegs +
                (  sizeof(untrustedBarSizeRegs)
                 / sizeof(untrustedBarSizeRegs[0]));

            for (const uint32_t* pIt=begin; pIt<end; ++pIt)
            {
                pError = deviceWrite(const_cast<TARGETING::Target*>(i_pProc),
                             const_cast<uint64_t*>(&scomData), size,
                             DEVICE_SCOM_ADDRESS(*pIt));
                if (pError)
                {
                    break;
                }
                assert(size == expSize,
                       "SCOM deviceWrite returned unexpected size of %d",
                       size);
            }
        }

        return pError;
    }
    #endif

    bool Settings::getEnabled() const
    {
        return 0 != (getSecuritySwitch()
                     & PROC_SECURITY_SWITCH_TRUSTED_BOOT_MASK);
    }

    bool Settings::getJumperState() const
    {
        return 0 != (getSecuritySwitch()
                     & PROC_SECURITY_SWITCH_JUMPER_STATE_MASK);
    }

    uint64_t Settings::getSecuritySwitch() const
    {
        return iv_regValue;
    }
}

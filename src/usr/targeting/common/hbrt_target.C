/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/hbrt_target.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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


#include <targeting/common/hbrt_target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/trace.H>
#include <targeting/targplatutil.H>
#ifdef __HOSTBOOT_MODULE
#include <errl/errludtarget.H>
#include <limits.h>
#else
#define KILOBYTE  (1024ull)            /**< 1 KB */
#define MEGABYTE  (1024 * 1024ull)     /**< 1 MB */
#define GIGABYTE  (MEGABYTE * 1024ull) /**< 1 GB */
#define TERABYTE  (GIGABYTE * 1024ull) /**< 1 TB */
#endif


extern trace_desc_t* g_trac_hbrt;
using namespace TARGETING;

namespace TARGETING
{

errlHndl_t getRtTarget(
    const TARGETING::Target* i_pTarget,
          rtChipId_t&        o_rtTargetId)
{
    errlHndl_t pError = NULL;

    do
    {
        if(i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);
            i_pTarget = masterProcChip;
        }

        TARGETING::ATTR_HBRT_HYP_ID_type hbrtHypId = HBRT_HYP_ID_UNKNOWN;
        if(   (!i_pTarget->tryGetAttr<TARGETING::ATTR_HBRT_HYP_ID>(hbrtHypId))
           || (hbrtHypId == HBRT_HYP_ID_UNKNOWN))
        {
            TARGETING::ATTR_HUID_type huid = get_huid(i_pTarget);
            TARGETING::ATTR_TYPE_type targetingTargetType =
                i_pTarget->getAttr<TARGETING::ATTR_TYPE>();
            TARG_ERR("getRtTarget: Targeting target type of 0x%08X not supported. "
                     "HUID: 0x%08X",
                     targetingTargetType,
                     huid);
            /*@
             * @errortype
             * @moduleid    TARG_RT_GET_RT_TARGET
             * @reasoncode  TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1   Target's HUID
             * @userdata2   target's targeting type
             * @devdesc     Targeting target's type not supported by runtime
             *              code
             * @custdesc    Error occurred during system boot
             */
            UTIL::createTracingError(TARGETING::TARG_RT_GET_RT_TARGET,
                               TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                               huid,
                               targetingTargetType,
                               0,0,
                               pError);
#ifdef __HOSTBOOT_MODULE

            ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                addToLog(pError);
#endif
            break;
        }

        o_rtTargetId = hbrtHypId;

    } while(0);

    return pError;
}

errlHndl_t getMemTargetMmioInfo ( TARGETING::Target * i_memTarget,
                                  std::vector<TARGETING::ocmbMmioAddressRange_t>& o_ocmbMmioSpaces)
{
    errlHndl_t l_err;

    do{
        TARGETING::ocmbMmioAddressRange_t l_tmpRange;
        TARGETING::ATTR_TYPE_type l_targetType = i_memTarget->getAttr<TARGETING::ATTR_TYPE>();

        TARG_ASSERT(l_targetType == TARGETING::TYPE_OCMB_CHIP,
              "Target type % passed to getMemTargetMmioInfo."
              " Currently this function only supports TYPE_OCMB_CHIP",
               l_targetType);

        // We need to store in a local variable initially because we cannot
        // pass a ptr to the getRtTarget member of the packed ocmbMmioAddressRange_t struct
        rtChipId_t l_hbrtId;
        l_err = TARGETING::getRtTarget(i_memTarget, l_hbrtId);
        if(l_err)
        {
            break;
        }
        l_tmpRange.hbrtId = l_hbrtId;

        TARGETING::ATTR_MMIO_PHYS_ADDR_type l_ocmbBaseMmioPhysAddr =
                    i_memTarget->getAttr<TARGETING::ATTR_MMIO_PHYS_ADDR>();

        TARG_ASSERT(l_ocmbBaseMmioPhysAddr != 0,
               "0 returned for physical address of OCMB's MMIO space. MMIO map probably isn't set up yet.");

        // CONFIG space ( 2 GB )
        l_tmpRange.mmioBaseAddr = l_ocmbBaseMmioPhysAddr;
        l_tmpRange.mmioEndAddr = l_tmpRange.mmioBaseAddr + (2 * GIGABYTE) - 1;
        l_tmpRange.accessSize = 4;
        o_ocmbMmioSpaces.push_back(l_tmpRange);

        // Microchip Scom Access Space ( 128 MB )
        //   Scom addresses 0x00000000..0x07FFFFFF, no shifting
        l_tmpRange.mmioBaseAddr = l_ocmbBaseMmioPhysAddr + (4 * GIGABYTE);
        l_tmpRange.mmioEndAddr = l_tmpRange.mmioBaseAddr + (128 * MEGABYTE) - 1;
        l_tmpRange.accessSize = 4;
        o_ocmbMmioSpaces.push_back(l_tmpRange);

        // IBM Scom Access Space ( Remainder )
        //   Scom addresses 0x08000000..0x08FFFFFF, then shifted 3 bits left
        //   but we can just cheat and reserve the rest of the 4G..6G range
        l_tmpRange.mmioBaseAddr = l_ocmbBaseMmioPhysAddr + (4 * GIGABYTE) + (128 * MEGABYTE);
        l_tmpRange.mmioEndAddr = l_ocmbBaseMmioPhysAddr + (6 * GIGABYTE) - 1;
        l_tmpRange.accessSize = 8;
        o_ocmbMmioSpaces.push_back(l_tmpRange);

    }while(0);

    return l_err;
}

}

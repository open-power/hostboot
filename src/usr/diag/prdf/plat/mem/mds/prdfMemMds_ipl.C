/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMds_ipl.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include <prdfMemMds_ipl.H>

// Platform includes
#include <prdfMemExtraSig.H>
#include <prdfParserEnums.H>

using namespace TARGETING;

namespace PRDF
{

namespace MDS
{

//------------------------------------------------------------------------------

uint32_t checkMediaErrors_ipl( ExtensibleChip * i_chip,
    const MemAddr & i_addr, bool & o_errorsFound,
    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[checkMediaErrors_ipl] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    // Check for a media UE (as indicated by RDFFIR maint SUE)
    // TODO
    // Check if media UEs already logged on previous sranks for this pattern
    // TODO
    // Check if MFG MDS 2-symbol media screening flag is enabled and media
    // error log count for any mrank is above threshold
    // TODO
    // Check if MFG mode is enabled and media error log count is above threshold
    // TODO
    // Check if the media error log count for any mrank is 8 or more
    // TODO
    // Check if there is a media chip kill
    // TODO

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t checkReadPathInterfaceErrors_ipl( ExtensibleChip * i_chip,
    const MemAddr & i_addr, bool & o_errorsFound,
    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[checkReadPathInterfaceErrors_ipl] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    // Check for an interface maint UE
    // TODO
    // Check for a maint MPE
    // TODO
    // Check if MFG CE screening flag is enabled and maint total hard CE count
    // is non-zero
    // TODO

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t checkWritePathInterfaceErrors_ipl( ExtensibleChip * i_chip,
    const MemAddr & i_addr, bool & o_errorsFound,
    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[checkReadPathInterfaceErrors_ipl] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    // Check for write-path interface errors on the media controller
    // DBE (double bit error) count > 0
    // TODO
    // Poison count > 0
    // TODO
    // SBE (single bit error) count > 0
    // TODO

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace MDS

} // end namespace PRDF

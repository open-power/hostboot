/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_ffdc_package_parser.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#include <sbeio/sbe_ffdc_package_parser.H>
#include <hwp_return_codes.H>
#include <trace/interface.H>
#include <xscom/piberror.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio, "sbe ffdc: " printf_string,##args)

namespace SBEIO
{

//---------------------------------------------------------------------------
FfdcParsedPackage::ParsedType
FfdcParsedPackage::rcToParsedType(uint32_t fapiRc)
{
    ParsedType retval{ParsedType::NONE};

    switch(fapiRc)
    {
        case fapi2::RC_SBE_SCOM_FAILURE:
        case fapi2::RC_SBE_PIB_XSCOM_ERROR:
        case fapi2::RC_SBE_PIB_OFFLINE_ERROR:
        case fapi2::RC_SBE_PIB_PARTIAL_ERROR:
        case fapi2::RC_SBE_PIB_ADDRESS_ERROR:
        case fapi2::RC_SBE_PIB_CLOCK_ERROR:
        case fapi2::RC_SBE_PIB_PARITY_ERROR:
        case fapi2::RC_SBE_PIB_TIMEOUT_ERROR:
        {
            retval = ParsedType::SBE_SCOM_PIB_ERROR;
            break;
        }
    }

    return retval;
}

//---------------------------------------------------------------------------
void FfdcParsedPackage::doDefaultProcessing(
                                        const ffdc_package& i_ffdc_package,
                                        TARGETING::Target* i_target,
                                        errlHndl_t i_errl
                                           )
{
    ParsedType l_type = rcToParsedType(i_ffdc_package.rc);
    switch(l_type)
    {
        case ParsedType::SBE_SCOM_PIB_ERROR:
            {
                FfdcScomPibErrorPackage ffdcPackage{i_ffdc_package};
                ffdcPackage(i_target, i_errl);
                break;
            }
        case ParsedType::NONE:
            {
                //If the schema matches then we probably have a new rc
                //that has yet to be accounted for.
                if(0 != i_ffdc_package.rc)
                {
                    if(FfdcScomPibErrorPackage::doesPackageMatchSchema
                                                              (i_ffdc_package))
                    {
                        SBE_TRACF(WARN_MRK"Unknown RC matches "
                                 "SBE_SCOM_PIB_ERROR FFDC schema. RC: 0x%08X",
                                  i_ffdc_package.rc
                                  );
                        FfdcScomPibErrorPackage ffdcPackage{i_ffdc_package,
                                                            true
                                                           };
                        ffdcPackage(i_target, i_errl);
                    }
                }
                break;
            }
        default:
            {
                SBE_TRACF(INFO_MRK"Unknown FFDC schema type encountered. "
                          "Parsed Type: 0x%04X",
                           static_cast<uint16_t>(l_type)
                        );
                break;
            }
    }
}

//---------------------------------------------------------------------------
std::shared_ptr<const FfdcParsedPackage>
FfdcParsedPackage::getParsedPackage(const ffdc_package& i_ffdc_package)
{
    std::shared_ptr<const FfdcParsedPackage> retval;
    ParsedType l_type = rcToParsedType(i_ffdc_package.rc);

    switch(l_type)
    {
        case ParsedType::SBE_SCOM_PIB_ERROR:
            {
                FfdcParsedPackage* ptr =
                                  new FfdcScomPibErrorPackage(i_ffdc_package);
                retval.reset(ptr);
                break;
            }
        default:
            {
                SBE_TRACF(WARN_MRK"No FFDC schema found for RC 0x%08X",
                          i_ffdc_package.rc
                         );
                retval.reset(new FfdcParsedPackage());
                break;
            }
    }

    return retval;
}

//----------------------------------------------------------------------------
FfdcScomPibErrorPackage::FfdcScomPibErrorPackage(const ffdc_package& i_ffdc,
                                                 bool ignoreRC
                                                )
{
    validateFFDCPackage(i_ffdc, ignoreRC);
}

//----------------------------------------------------------------------------
bool FfdcScomPibErrorPackage::validateFFDCPackage(const ffdc_package& i_ffdc,
                                                  bool ignoreRC)
{
    //Schema
    //        u32            u64          u32        u64
    // | SCOM ADDR SIZE | SCOM ADDR | PIB RC SIZE | PIB RC |

    bool retval{false};

    do
    {
        if(nullptr == i_ffdc.ffdcPtr)
        {
            parsedType(ParsedType::NONE);
            break;
        }

        //if ignoreRC is true then schema validation has already been done.
        //Skip this step and parse the FFDC data.
        if(not ignoreRC)
        {
            if(ParsedType::SBE_SCOM_PIB_ERROR != rcToParsedType(i_ffdc.rc))
            {
                parsedType(ParsedType::NONE);
                break;
            }

            if(not doesPackageMatchSchema(i_ffdc))
            {
                parsedType(ParsedType::NONE);
                break;
            }
        }

        constexpr size_t scomAddressOffset = sizeof(uint32_t);  //size of Scom Addr

        constexpr size_t pibRcOffset =  sizeof(uint32_t) + //size of Scom Addr
                                        sizeof(uint64_t) + //Scom Address
                                        sizeof(uint32_t);  //size of PIB RC

        const char* l_buffer = reinterpret_cast<const char*>(i_ffdc.ffdcPtr);

        // the sizes for these casts come from the sizeof sbeFfdc_t.data defined in error_info_def.H
        iv_scomAddress = *(reinterpret_cast<const uint64_t*>
                                               (l_buffer + scomAddressOffset));

        iv_pibRc = *(reinterpret_cast<const uint64_t*>
                                               (l_buffer + pibRcOffset));

        //Make this instance valid by assigning a ParsedType other than none.
        parsedType(ParsedType::SBE_SCOM_PIB_ERROR);
        retval = true;
    }
    while(0);

    return retval;
}

//------------------------------------------------------------------------
bool FfdcScomPibErrorPackage::doesPackageMatchSchema(const ffdc_package&
                                                                       i_ffdc)
{
    //Schema
    //        u32           u64          u32         u64
    // | SCOM ADDR SIZE | SCOM ADDR | PIB RC SIZE | PIB RC |
    bool retval{false};
    bool isInvalidSize{false};

    do
    {
        if(nullptr == i_ffdc.ffdcPtr)
        {
            return retval;
        }

        constexpr uint32_t l_expectedPIBSize = sizeof(uint8_t);
        constexpr size_t l_expectedSize = sizeof(uint32_t) + //size of Scom Addr
                                        sizeof(uint64_t) + //Scom Address
                                        sizeof(uint32_t) + //size of PIB RC
                                        sizeof(uint64_t);  //PIB RC

        constexpr size_t l_pibSizeOffset = sizeof(uint32_t) + //size of Scom Addr
                                         sizeof(uint64_t);  //Scom Address


        if(l_expectedSize != i_ffdc.size)
        {
            SBE_TRACF(ERR_MRK "i_ffdc.size != l_expectedSize. i_ffdc.size = 0x%08X, "
                      "l_expectedSize = 0x%08X", i_ffdc.size, l_expectedSize);
            break;
        }

        const char* l_buffer = reinterpret_cast<const char*>(i_ffdc.ffdcPtr);
        uint32_t l_scomAddrSize = *(reinterpret_cast<const uint32_t*>(l_buffer));

        // the offset of the scom adress size should always be at the beginning of the buffer
        switch (l_scomAddrSize)
        {
            case 4:
            case 8:
                break;
            default:
                // if the size is not either 4 or 8 bytes then the size is invalid
                isInvalidSize = true;
        }

        if(isInvalidSize)
        {
            SBE_TRACF(ERR_MRK "scomAddrSize is of an unexpected size. scomAddrSize = %d, "
                      "expected sizes are 4 or 8", l_scomAddrSize);
            break;
        }

        uint32_t l_pibSize = *(reinterpret_cast<const uint32_t*>
                                                   (l_buffer + l_pibSizeOffset));
        if(l_expectedPIBSize != l_pibSize)
        {
            SBE_TRACF(ERR_MRK "l_pibSize != l_expectedPIBSize. l_pibSize = %d, "
                      "l_expectedPIBSize = %d", l_pibSize, l_expectedPIBSize);
            break;
        }

        retval = true;
    }
    while(0);

    return retval;
}


//--------------------------------------------------------------------------
void FfdcScomPibErrorPackage::addFruCallouts(TARGETING::Target* i_target,
                                             errlHndl_t i_errl
                                            ) const
{
    if(isValid())
    {
        if(PIB::PIB_NO_ERROR != iv_pibRc && INVALID_DATA != iv_pibRc)
        {
            PIB::addFruCallouts
                        (i_target, iv_pibRc, iv_scomAddress, i_errl);
        }
    }
}

//---------------------------------------------------------------------------
void FfdcScomPibErrorPackage::operator()(TARGETING::Target* i_target,
                                         errlHndl_t i_errl
                                        ) const
{
    if(isValid())
    {
        addFruCallouts(i_target, i_errl);
    }
}

}

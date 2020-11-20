/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_ffdc_package_parser.H $             */
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
#ifndef __SBEIO_SBE_FFDC_PACKAGE_PARSER_H
#define __SBEIO_SBE_FFDC_PACKAGE_PARSER_H

#include <stdint.h>
#include <memory>

#include <errl/errlentry.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <targeting/common/target.H>

namespace SBEIO
{

/**
 * @brief A class to support processing of parsed ffdc data.
 *
 * FFDC data schema is related to RC codes. There does not
 * exist a facility code to identify common types of FFDC data.
 * Instead, each RC code is given an FFDC schema based upon settings
 * in the error_info xml files. Although many error codes share the same
 * FFDC format, there is nothing to relate similar FFDC schemas to RC values,
 * The mapping is the other way around, individual fapi RC codes map to
 * FFDC formats. In addition, because of the use of template type deduction
 * in populating FFDC data, type information which may prove useful for parsing
 * is lost. To illustrate, the SBE uses a global variable to hold FFDC data for
 * a request. The global variable contains a field for storing the fapiRC code
 * and an array of up to 10 sbeFfdc_t structs used to hold the FFDC data. For a
 * Scom PIB error, the schema of the FFDC places the scom address and size in
 * first sbeFfdc_t struct and the pib rc in the second struct. Each sbeFfdc_t
 * struct is just a uint64_t for the data and a uint32_t for the size. There
 * is no type information stored. The uint64_t in some instances can hold
 * a pointer to a target, in other instances data such as the PIB RC code and
 * yet in other cases an address such as the scom address. The Scom PIB errors
 * from the SBE uses only two of the sbeFfdc_t slots. Other errors use 3,4 or
 * more sbeFfdc_t data.
 * Because of the lack of parsing support available, this base class and
 * derived classes are manually coded to group fapi RC values with similar FFDC
 * formats in order to aid parsing of FFDC data. Currently, we only parse the
 * format used for the scom pib memory errors returned from the SBE.
 *
 *
 */
class FfdcParsedPackage
{
public:

    /**
     * @brief Used to identify FFDC schema.
     *
     */
    enum class ParsedType{
                            NONE,
                            SBE_SCOM_PIB_ERROR
                         };

    virtual ~FfdcParsedPackage() = default;

    /**
     * @brief Determines if the FFDC package was successfully parsed.
     *
     * @return True if the ffdc package was parsed, false otherwise.
     */
    bool isValid() const {return iv_packageType != ParsedType::NONE;}

    /**
     * @brief Obtain the FFDC package type that was parsed.
     */
    ParsedType parsedType() const {return iv_packageType;}

    /**
     * @brief Perform the default action on the parsed
     *        ffdc data.
     *
     * @param[in] i_target, the target of the request.
     * @param[in] i_errl, error entry for processing.
     *
     */
    virtual void operator()(TARGETING::Target* i_target,
                            errlHndl_t i_errl
                           ) const {};

    /**
     * @brief bool operator for isValid.
     *
     */
    operator bool() const {return isValid();}

    /**
     * @brief Convert fapiRC to a ParsedType.
     *
     * @param[in] fapiRc, the rc to convert.
     *
     * @return The ParsedType corresponding to fapiRc
     *
     */
    static ParsedType rcToParsedType(uint32_t fapiRc);

    /**
     * @brief parse the FFDC package and perform the default
     *        operation if parsing was successful.
     *
     * @param[in] i_ffdc_package, the ffdc to parse and process.
     * @param[in] i_target, the target of the default processing.
     * @param[in] i_errl, the ErrlEntry to be used for default processing.
     *
     */
    static void doDefaultProcessing(const ffdc_package& i_ffdc_package,
                                    TARGETING::Target* i_target,
                                    errlHndl_t i_errl
                                    );

    /**
     * @brief Parse the given FFDC data.
     *
     * @param[in] i_ffdc_package to parse.
     *
     * @return a shared pointer to an object derived from FfdcParsedPackage.
     *         If the package could not be parsed a raw FfdcParsedPackage
     *         is returned.
     */
    static std::shared_ptr<const FfdcParsedPackage>
           getParsedPackage(const ffdc_package& i_ffdc_package);

protected:

    /**
     * @brief Set the parsed ffdc type.
     *
     * @param[in] The new Parsed FFDC Type value.
     *
     */
    void parsedType(const ParsedType& i_parsedType)
    {
        iv_packageType = i_parsedType;
    }

private:

    ParsedType iv_packageType{ParsedType::NONE}; /**< The FFDC type */
};



/**
 * @brief Processing for SBE scom pib FFDC.
 *
 * The FFDC schema parsed by this class is as follows:
 *
 *            u32           u64         u32          u64
 *     | Scom Addr Size | Scom Addr | PIB RC Size | PIB RC |
 *
 */
class FfdcScomPibErrorPackage: public FfdcParsedPackage
{
public:
    /**
     * @brief Contsructor
     *
     * @param[in] i_ffdc, the unparsed raw ffdc data.
     * @param[in] i_ignoreRC, if true then validation of the ffdc
     *            schema has already been performed by the
     *            static method doesPackageMatchSchema. In this
     *            case the rc of the ffdc does not match the list of
     *            known fapiRC values that correspond to the ffdc
     *            schema parsed by this class. However, if it is assumed
     *            that a new fapiRC is responsible for this condition
     *            then we may use this class to process the FFDC regardless
     *            of the corresponding fapiRC. This could prove useful as
     *            SBE errors in messaging currently only send Scom Pib errors
     *            as the first FFDC entry.
     */
    explicit FfdcScomPibErrorPackage(const ffdc_package& i_ffdc,
                                     bool i_ignoreRC = false);

    virtual ~FfdcScomPibErrorPackage() = default;

    /**
     * @brief Call operator for default processing. For this FFDC schema
     *        we call the addFruCallouts method.
     *
     * @param[in] i_target, the target of the default processing.
     * @param[in] i_errl, the ErrlEntry to be used for default processing.
     *
     */
    void operator() (TARGETING::Target* i_target,
                     errlHndl_t i_errl
                    ) const override;

    /**
     * @brief Use parsed data to add Fru Callouts. The method
     *        is virtual to facilitate a unit test seam.
     *
     * @param[in] i_target, the target for the callout.
     * @param[in] i_errl, the ErrlEntry to which to add the callout.
     *
     */
    virtual void addFruCallouts (TARGETING::Target* i_target,
                                 errlHndl_t i_errl
                                ) const;

    /**
     * @brief Accessor for the PIB RC parsed data.
     *
     * @return The PIB RC Code from the FFDC data.
     *
     */
    uint64_t getPibRc() const {return iv_pibRc;}

    /**
     * @brief Accessor for the PIB RC parsed data.
     *
     * @return The PIB RC Code from the FFDC data.
     *
     */
    uint64_t getScomAddress() const {return iv_scomAddress;}

    /**
     * @brief Check if the FFDC schema matches that expected by this class,
     *        with the exception of the RC code. This is intended for use
     *        when we are always expecting a certain FFDC schema from a
     *        function call but perhaps a new RC has been added that has not
     *        yet been added to those we know of.
     *
     * @param[in] i_ffdc: the ffdc data to validate.
     *
     * @return True if the FFDC schema matches what we are expecting, false
     *         otherwise.
     *
     */
    static bool doesPackageMatchSchema(const ffdc_package& i_ffdc);

    static const uint64_t INVALID_DATA = uint64_t(-1);

private:

    /**
     * @brief Validate that the passed in FFDC data has a schema consistent
     *        with what we are expecting.
     *
     * @param[in] i_ffdc, the FFDC data to validate.
     * @param[in] i_ignoreRC, Do not base validation on RC value. Setting
     *            this parameter to true indicates that the schema has already
     *            been checked by the doesPackageMatchSchema function and
     *            as such we just need to parse the data and not validate.
     *
     * @return True if the FFDC data was successfully validated and parsed,
     *         False otherwise.
     *
     */
    bool validateFFDCPackage(const ffdc_package& i_ffdc, bool i_ignoreRC);

    uint64_t iv_pibRc{INVALID_DATA}; /**< parsed pib rc code */
    uint64_t iv_scomAddress{INVALID_DATA}; /**< parsed scom address */
};


}

#endif

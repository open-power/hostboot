//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errludtarget.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef ERRL_UDTARGET_H
#define ERRL_UDTARGET_H

/**
 *  @file errludTarget.H
 *
 *  Defines the following classes:
 *
 *  ErrlUserDetailsTarget: Adds Target FFDC to an error log as user detail data
 *  ErrlUserDetailsParserTarget: Parses Target FFDC user detail in an error log
 */

#include <errl/errluserdetails.H>

#ifndef PARSER

// Forward reference
namespace TARGETING
{
    class Target;
}

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsTarget
 *
 * Adds Target FFDC to an error log as user detail data
*/
class ErrlUserDetailsTarget : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Captures the supplied Target's FFDC data internally
     *  
     *  @param i_pTarget Pointer to Target to capture as user detail data
     */
    ErrlUserDetailsTarget(const TARGETING::Target * i_pTarget);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsTarget();

private:
    // Disabled
    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);
    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);
};

}

#else // (if PARSER defined)

#include <string.h>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserTarget
 *
 * Parses Target FFDC user detail in an error log
 */
class ErrlUserDetailsParserTarget : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserTarget() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserTarget() {}

    /**
     *  @brief Parses Target user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        i_parser.PrintString("Target data", NULL);
        const char *attrData;
        uint32_t i = 0;

        // errlog data
        uint8_t *l_ptr = static_cast<uint8_t *>(i_pBuffer);

        // TODO: needs to be updated to handle merged records

        if (*l_ptr == 1) // special - master
        { 
            i_parser.PrintString(NULL, "MASTER_PROCESSOR_CHIP_TARGET_SENTINEL");
        }
        else
        {
            l_ptr += sizeof(uint8_t); // past the marker

            // first 4 are always the same
            if (i_buflen >= sizeof(uint32_t) + 3 * sizeof(uint8_t))
            {
                char sHuid[12];
                sprintf(sHuid, "0x%x",*((uint32_t *)l_ptr));
                i_parser.PrintString("ATTR_HUID", sHuid);
                i += sizeof(uint32_t);
                l_ptr += sizeof(uint32_t);

                // CLASS
                switch (*l_ptr) {
                    case 0x00: { attrData = "CLASS_NA"; break; }
                    case 0x01: { attrData = "CLASS_CARD"; break; }
                    case 0x02: { attrData = "CLASS_ENC"; break; }
                    case 0x03: { attrData = "CLASS_CHIP"; break; }
                    case 0x04: { attrData = "CLASS_UNIT"; break; }
                    case 0x05: { attrData = "CLASS_DEV"; break; }
                    case 0x06: { attrData = "CLASS_SYS"; break; }
                    case 0x07: { attrData = "CLASS_LOGICAL_CARD"; break; }
                    case 0x08: { attrData = "CLASS_MAX"; break; }
                    default:   { attrData = "UNKNOWN CLASS"; break; }
                } // switch
                i_parser.PrintString("ATTR_CLASS", attrData);
                i ++;
                l_ptr ++;

                // TYPE
                switch (*l_ptr) {
                    case 0x00: { attrData = "TYPE_NA"; break; }
                    case 0x01: { attrData = "TYPE_SYS"; break; }
                    case 0x02: { attrData = "TYPE_NODE"; break; }
                    case 0x03: { attrData = "TYPE_DIMM"; break; }
                    case 0x04: { attrData = "TYPE_SCM"; break; }
                    case 0x05: { attrData = "TYPE_DCM"; break; }
                    case 0x06: { attrData = "TYPE_MEMBUF"; break; }
                    case 0x07: { attrData = "TYPE_PROC"; break; }
                    case 0x08: { attrData = "TYPE_MEMVRM"; break; }
                    case 0x09: { attrData = "TYPE_PROCVRM"; break; }
                    case 0x0A: { attrData = "TYPE_EX"; break; }
                    case 0x0B: { attrData = "TYPE_CORE"; break; }
                    case 0x0C: { attrData = "TYPE_L2"; break; }
                    case 0x0D: { attrData = "TYPE_L3"; break; }
                    case 0x0E: { attrData = "TYPE_L4"; break; }
                    case 0x0F: { attrData = "TYPE_MCS"; break; }
                    case 0x10: { attrData = "TYPE_MBS"; break; }
                    case 0x11: { attrData = "TYPE_MBA"; break; }
                    case 0x12: { attrData = "TYPE_MEM_PORT"; break; }
                    case 0x13: { attrData = "TYPE_PERVASIVE"; break; }
                    case 0x14: { attrData = "TYPE_POWERBUS"; break; }
                    case 0x15: { attrData = "TYPE_XBUS"; break; }
                    case 0x16: { attrData = "TYPE_ABUS"; break; }
                    case 0x17: { attrData = "TYPE_PCI"; break; }
                    case 0x18: { attrData = "TYPE_TP"; break; }
                    case 0x19: { attrData = "TYPE_DMI"; break; }
                    case 0x1A: { attrData = "TYPE_DPSS"; break; }
                    case 0x1B: { attrData = "TYPE_APSS"; break; }
                    case 0x1C: { attrData = "TYPE_OCC"; break; }
                    case 0x1D: { attrData = "TYPE_LAST_IN_RANGE"; break; }
                    default:   { attrData = "UNKNOWN TYPE"; break; }
                } // switch
                i_parser.PrintString("ATTR_TYPE", attrData);
                i++;
                l_ptr++;

                // MODEL
                switch (*l_ptr) {
                    case 0x00: { attrData = "MODEL_NA"; break; }
                    case 0x10: { attrData = "MODEL_SALERNO"; break; }
                    case 0x11: { attrData = "MODEL_VENICE"; break; }
                    case 0x12: { attrData = "MODEL_MURANO"; break; }
                    case 0x30: { attrData = "MODEL_CENTAUR"; break; }
                    case 0x50: { attrData = "MODEL_JEDEC"; break; }
                    case 0x51: { attrData = "MODEL_CDIMM"; break; }
                    case 0x70: { attrData = "MODEL_POWER8"; break; }
                    default:   { attrData = "UNKNOWN MODEL"; break; }
                } // switch
                i_parser.PrintString("ATTR_MODEL", attrData);
                i++;
                l_ptr++;
            }

            for (; i < i_buflen; )
            {
                if ((*l_ptr == 0x15) || // ATTR_PHYS_PATH
                    (*l_ptr == 0x16))   // ATTR_AFFINITY_PATH
                {
                    l_ptr++;
                    const char *pathString;
                    char outString[128];
                    // from targeting/common/entitypath.[CH]
                    // entityPath is PATH_TYPE:4, NumberOfElements:4, 
                    //          [Element, Instance#]
                    // PATH_TYPE
                    const uint8_t pathTypeLength = *((uint8_t *)l_ptr);
                    l_ptr++;
                    const uint8_t pathType = (pathTypeLength & 0xF0) >> 4;
                    switch (pathType) {
                        case 0x01: pathString = "Logical:"; break;
                        case 0x02: pathString = "Physical:"; break;
                        case 0x03: pathString = "Device:"; break;
                        case 0x04: pathString = "Power:"; break;
                        default:   pathString = "Unknown:"; break;
                    }
                    uint32_t dataSize = sprintf(outString, "%s",pathString);
                    const uint8_t pathSize = (pathTypeLength & 0x0F);
                    uint8_t *lElementInstance = ((uint8_t *)l_ptr);
                    l_ptr += pathSize * sizeof(uint8_t);
                    for (uint32_t j=0;j<pathSize;j += 2) {
                        switch (lElementInstance[j]) {
                            case 0x01: pathString = "/Sys"; break;
                            case 0x02: pathString = "/Node"; break;
                            case 0x03: pathString = "/DIMM"; break;
                            case 0x04: pathString = "/SCM"; break;
                            case 0x05: pathString = "/DCM"; break;
                            case 0x06: pathString = "/Membuf"; break;
                            case 0x07: pathString = "/Proc"; break;
                            case 0x08: pathString = "/MemVRM"; break;
                            case 0x09: pathString = "/ProcVRM"; break;
                            case 0x0A: pathString = "/EX"; break;
                            case 0x0B: pathString = "/Core"; break;
                            case 0x0C: pathString = "/L2"; break;
                            case 0x0D: pathString = "/L3"; break;
                            case 0x0E: pathString = "/L4"; break;
                            case 0x0F: pathString = "/MCS"; break;
                            case 0x10: pathString = "/MBS"; break;
                            case 0x11: pathString = "/MBA"; break;
                            case 0x12: pathString = "/MemPort"; break;
                            case 0x13: pathString = "/Pervasive"; break;
                            case 0x14: pathString = "/Powerbus"; break;
                            case 0x15: pathString = "/XBUS"; break;
                            case 0x16: pathString = "/ABUS"; break;
                            case 0x17: pathString = "/PCI"; break;
                            case 0x18: pathString = "/TP"; break;
                            case 0x19: pathString = "/DMI"; break;
                            case 0x1A: pathString = "/DPSS"; break;
                            case 0x1B: pathString = "/APSS"; break;
                            case 0x1C: pathString = "/OCC"; break;
                            //case TYPE_FSI_LINK: pathString = "/FSI-link"; break;
                            //case TYPE_CFAM: pathString = "/CFAM"; break;
                            //case TYPE_ENGINE: pathString = "/Engine"; break;
                            default: pathString = "/Unknown"; break;
                        } // switch
                        // copy next part in, overwritting previous terminator
                        dataSize += sprintf(outString + dataSize, "%s%d",pathString,lElementInstance[j+1]);
                    } // for
                    if (*l_ptr == 0x15) // ATTR_PHYS_PATH
                    {
                      i_parser.PrintString("ATTR_PHYS_PATH", outString);
                    }
                    else
                    {
                      i_parser.PrintString("ATTR_AFFINITY_PATH", outString);
                    }
                }
            } // for
        }
    } // parse()

private:
    // Disabled
    ErrlUserDetailsParserTarget(const ErrlUserDetailsParserTarget &);
    ErrlUserDetailsParserTarget & operator=(
        const ErrlUserDetailsParserTarget &);
};

}

#endif
#endif


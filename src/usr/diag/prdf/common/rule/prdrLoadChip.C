/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrLoadChip.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <string.h>                // for memcmp
#include <prdrCommon.H>

#include <prdrLoadChip.H>
#include <errlentry.H>
#include <utilstream.H>
#include <UtilFunct.H>

#include <prdf_service_codes.H>
#include <prdfThresholdResolutions.H>
#include <prdfGlobal.H>
#include <UtilHash.H> // for Util::hashString
#include <prdfErrlUtil.H>
#include <algorithm> // for std::generate_n

namespace Prdr
{

// 'using namespace PRDF' added so that the Hostboot error log parser can find
// the moduleid and reasoncode in the error log tags. The alternative is to add
// 'PRDF::' before the moduleid and reasoncode in the error log tags
using namespace PRDF;

void ReadExpr(UtilStream & i_stream, Expr & o_expr);

// NOTE: caller must call delete[] to release the buffer
void ReadString(UtilStream & i_stream, char *& o_string)
{
    char  l_pBuf[100];
    memset(l_pBuf,'\0',100);
    char* l_pCursor = l_pBuf;

    char l_tmp;

    do
    {
        i_stream >> l_tmp;
        if ('\0' != l_tmp)
        {
            *l_pCursor = l_tmp;
            l_pCursor++;
        }
    } while ('\0' != l_tmp);

    o_string = new char[strlen(l_pBuf) + 1];
    strcpy(o_string, l_pBuf);
}

/**
 * @brief read bit string data out from the stream
 */
void prdrReadBitString(UtilStream & i_stream, std::vector<uint64_t> & o_vector)
{
    uint64_t l_tmp64;
    uint8_t l_tmp8;
    i_stream >> l_tmp8;

    int length = (l_tmp8 / 8) + ((l_tmp8 % 8) != 0 ? 1 : 0);

    for (int i = 0; i < (length/8); i++)
    {
        i_stream >> l_tmp64;
        o_vector.push_back(l_tmp64);
    }
}

errlHndl_t LoadChip(UtilStream & i_stream, Chip & o_chip)
{
    errlHndl_t l_errl = nullptr;

    do
    {
        char l_temp[8];

        // read header.
        i_stream >> l_temp;
        if (0 != memcmp(l_temp, "PRDRCHIP", 8))
        {
            PRDF_ERR("LoadChip() bad chip file - l_temp: %s ", l_temp);
            // Bad chip file.
            /*@
             * @errortype
             * @refcode    LIC_REFCODE
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode PRDF_CODE_FAIL
             *
             * @moduleid   PRDF_LOADCHIP
             * @userdata1  0x50524452 ("PRDR")
             * @userdata2  0x43484950 ("CHIP")
             * @devdesc    Attempted to load chip rule file that lacked
             *             the proper header "PRDRCHIP".
             * @custDesc   An Internal firmware fault, chip  diagnosis failed to
             *             initialize.
             */
            PRDF_CREATE_ERRL(l_errl,
                             ERRL_SEV_UNRECOVERABLE,
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_ERR_INFO,
                             SRCI_NO_ATTR,
                             PRDF::PRDF_LOADCHIP,
                             LIC_REFCODE,
                             PRDF::PRDF_CODE_FAIL,
                             0x50524452, // PRDR
                             0x43484950, // CHIP
                             0, 0);
            break;
        }

        // read chip info.
        i_stream >> o_chip.cv_chipId;
        i_stream >> o_chip.cv_targetType;
        i_stream >> o_chip.cv_signatureOffset;
        i_stream >> o_chip.cv_dumpType;        //@ecdf
        i_stream >> o_chip.cv_scomLen;

        // read registers.
        i_stream >> o_chip.cv_regCount;

        if (o_chip.cv_regCount != 0)
        {
            o_chip.cv_registers = new Register[o_chip.cv_regCount];
            for (uint32_t i = 0; i < o_chip.cv_regCount; i++)
            {
                i_stream >> o_chip.cv_registers[i].cv_name;
                i_stream >> o_chip.cv_registers[i].cv_flags;
                i_stream >> o_chip.cv_registers[i].cv_scomAddr;

                if (o_chip.cv_registers[i].cv_flags &
                        PRDR_REGISTER_SCOMLEN)
                {
                    i_stream >> o_chip.cv_registers[i].cv_scomLen;
                }
                else
                {
                    o_chip.cv_registers[i].cv_scomLen = o_chip.cv_scomLen;
                }

                if (o_chip.cv_registers[i].cv_flags &
                        PRDR_REGISTER_RESETS)
                {
                    // Read 'n' from stream.  Read that many reset structs out
                    // of the stream, insert into cv_resets for register.
                    std::generate_n(
                            std::back_inserter(
                                o_chip.cv_registers[i].cv_resets
                                ),
                            PRDF::Util::unary_input<uint16_t, UtilStream>(i_stream)(),
                            PRDF::Util::unary_input<Register::ResetOrMaskStruct,
                                              UtilStream> (i_stream)
                            );

                }

                if (o_chip.cv_registers[i].cv_flags &
                        PRDR_REGISTER_MASKS)
                {
                    // Read 'n' from stream.  Read that many mask structs out
                    // of the stream, insert into cv_masks for register.
                    std::generate_n(
                            std::back_inserter(
                                o_chip.cv_registers[i].cv_masks
                                ),
                            PRDF::Util::unary_input<uint16_t, UtilStream>(i_stream)(),
                            PRDF::Util::unary_input<Register::ResetOrMaskStruct,
                                              UtilStream> (i_stream)
                            );

                }

                if (o_chip.cv_registers[i].cv_flags &
                        PRDR_REGISTER_CAPTURE)
                {
                    // Read 'n' from stream.  Read that many mask structs out
                    // of the stream, insert into cv_masks for register.
                    std::generate_n(
                            std::back_inserter(
                                o_chip.cv_registers[i].cv_captures
                                ),
                            PRDF::Util::unary_input<uint16_t, UtilStream>(i_stream)(),
                            PRDF::Util::unary_input<Register::CaptureInfoStruct,
                                              UtilStream> (i_stream)
                            );
                }
            }
        }

        // read rules.
        i_stream >> o_chip.cv_ruleCount;
        if (o_chip.cv_ruleCount != 0)
        {
            o_chip.cv_rules = new Expr[o_chip.cv_ruleCount];
            for (uint32_t i = 0; i < o_chip.cv_ruleCount; i++)
            {
                i_stream >> l_temp[0]; // should be 'R'
                ReadExpr(i_stream, o_chip.cv_rules[i]);
            }
        }

        // read groups.
        i_stream >> o_chip.cv_groupCount;
        for (int i = 0; i < MAX_NUM_ATTN_TYPES; i++)
            i_stream >> o_chip.cv_groupAttn[i];
        if (o_chip.cv_groupCount != 0)
        {
            o_chip.cv_groups = new Expr * [o_chip.cv_groupCount];
            o_chip.cv_groupSize = new uint16_t[o_chip.cv_groupCount];
            o_chip.cv_groupFlags = new uint8_t[o_chip.cv_groupCount];
            o_chip.cv_groupPriorityBits = new Expr * [o_chip.cv_groupCount];
            o_chip.cv_groupCsRootCauseBits = new Expr * [o_chip.cv_groupCount];
            for (uint32_t i = 0; i < o_chip.cv_groupCount; i++)
            {
                i_stream >> l_temp[0]; // should be 'G'
                i_stream >> o_chip.cv_groupSize[i];
                i_stream >> o_chip.cv_groupFlags[i];

                //check if priority filter has been specified
                if ( PRDR_GROUP_FILTER_PRIORITY & o_chip.cv_groupFlags[i] )
                {
                    o_chip.cv_groupPriorityBits[i] = new Expr();
                    ReadExpr(i_stream, *o_chip.cv_groupPriorityBits[i]);
                }
                else
                {
                    o_chip.cv_groupPriorityBits[i] = nullptr;
                }

                //check if cs_root_cause filter has been specified
                if( PRDR_GROUP_FILTER_CS_ROOT_CAUSE & o_chip.cv_groupFlags[i] )
                {
                    o_chip.cv_groupCsRootCauseBits[i] = new Expr();
                    ReadExpr(i_stream, *o_chip.cv_groupCsRootCauseBits[i]);
                }
                else
                {
                    o_chip.cv_groupCsRootCauseBits[i] = nullptr;
                }

                if (0 != o_chip.cv_groupSize[i])
                {
                    o_chip.cv_groups[i] = new Expr[o_chip.cv_groupSize[i]];
                    for (uint32_t j = 0; j < o_chip.cv_groupSize[i]; j++)
                    {
                        ReadExpr(i_stream, o_chip.cv_groups[i][j]);
                        if (REF_RULE == o_chip.cv_groups[i][j].cv_op)
                        {
                            for (int k = 1; k <= 2; k++)
                            {
                                o_chip.cv_groups[i][j].cv_value[k].p =
                                        new Expr();
                                o_chip.cv_groups[i][j].cv_deletePtr[k] = true;

                                ReadExpr(i_stream,
                                        *o_chip.cv_groups[i][j].cv_value[k].p);
                            }
                        }
                    }
                }
                else
                {
                    o_chip.cv_groups[i] = new Expr[0]; /*accessing beyond memory*/
                                                          // False error BEAM.
                };
            }
        }

        // read actions.
        i_stream >> o_chip.cv_actionCount;
        if (o_chip.cv_actionCount != 0)
        {
            o_chip.cv_actions = new Expr * [o_chip.cv_actionCount];
            o_chip.cv_actionSize = new uint16_t[o_chip.cv_actionCount];
            for (uint32_t i = 0; i < o_chip.cv_actionCount; i++)
            {
                i_stream >> l_temp[0]; // should be 'A'
                i_stream >> o_chip.cv_actionSize[i];
                if (0 != o_chip.cv_actionSize[i])
                {
                    o_chip.cv_actions[i] =
                            new Expr[o_chip.cv_actionSize[i]];
                    for (uint32_t j = 0; j < o_chip.cv_actionSize[i]; j++)
                    {
                        ReadExpr(i_stream, o_chip.cv_actions[i][j]);
                    }
                }
                else //@pw01
                {
                    o_chip.cv_actions[i] = nullptr;
                }
            }
        }

    } while (false);

    if (nullptr == l_errl)
        l_errl = i_stream.getLastError();

    return l_errl;
}

void ReadExpr(UtilStream & i_stream, Expr & o_expr)
{
    unsigned char l_tmpChar;
    uint32_t l_tmp32;
    uint16_t l_tmp16;
    uint8_t l_tmp8;
    bool l_tmpBool;

    i_stream >> o_expr.cv_op;

    switch(o_expr.cv_op)
    {
        case AND:
        case OR:
        case XOR:
        case LSHIFT:
        case RSHIFT:
        case SUMMARY:
        case ACT_TRY:
            o_expr.cv_value[0].p = new Expr();
            o_expr.cv_deletePtr[0] = true;
            ReadExpr(i_stream, *o_expr.cv_value[0].p);

            o_expr.cv_value[1].p = new Expr();
            o_expr.cv_deletePtr[1] = true;
            ReadExpr(i_stream, *o_expr.cv_value[1].p);
            break;

        case NOT:
            o_expr.cv_value[0].p = new Expr();
            o_expr.cv_deletePtr[0] = true;
            ReadExpr(i_stream, *o_expr.cv_value[0].p);
            break;

        case INTEGER:
        case ACT_FLAG:
            i_stream >> o_expr.cv_value[0].i;
            break;

        case REF_RULE:
        case REF_REG:
        case REF_GRP:
        case REF_ACT:
        case INT_SHORT:
            i_stream >> l_tmp16;
            o_expr.cv_value[0].i = l_tmp16;
            break;

        case BIT_STR:
            o_expr.cv_bitStrVect.clear();
            prdrReadBitString(i_stream, o_expr.cv_bitStrVect);
            break;

        case ACT_THRES:

            // The values which different parameter will have
            // cv_value[0, 1]:  error frequency and time in sec for field
            //                  threshold
            // cv_value[4]:     true if mnfg threshols needs to be picked up
            //                  from mnfg file, false otherwise
            // cv_value [2, 3]: error frequency and time in sec for mnfg
            //                  threshold if cv_value[4] is false
            //                  otherwise cv_value[3] tells which threshold
            //                  needs to pick up from mnfg file
            // cv_value[5]      mask id if shared threshold

            //default values
            o_expr.cv_value[0].i = PRDF::ThresholdResolution::
                                                cv_fieldDefault.threshold;
            o_expr.cv_value[1].i = PRDF::ThresholdResolution::
                                                cv_fieldDefault.interval;
            o_expr.cv_value[2].i = PRDF::ThresholdResolution::
                                                cv_mnfgDefault.threshold;
            o_expr.cv_value[3].i = PRDF::ThresholdResolution::
                                                cv_mnfgDefault.interval;
            // The syntax of thresholds in rule file is
            // op field_threshold field_intervale
            // optional fields (mnfg_threshold, mnfg_interval }
            // | mnfg_ilr_threshold | maskid
            i_stream >> l_tmpChar;
            l_tmpBool = (0x40 == (0x40 & l_tmpChar));
            l_tmpChar &= (~0x40);
            o_expr.cv_value[4].i = (0x20 == (0x20 & l_tmpChar));
            l_tmpChar &= (~0x20);

            if (0 != l_tmpChar)
                for (uint8_t i = 0; i < l_tmpChar; i++)
                {
                    if ( (1 != i) || (0 == o_expr.cv_value[4].i) )
                    {
                        //entry has errorFrequency
                        i_stream >> l_tmp8;
                        o_expr.cv_value[2*i].i = l_tmp8;
                    }
                    i_stream >> o_expr.cv_value[2*i + 1].i;
                }
            if (l_tmpBool)
                i_stream >> o_expr.cv_value[5];
            break;

        case ACT_ANALY:
            i_stream >> o_expr.cv_value[0].i;
            i_stream >> o_expr.cv_value[1].i;
            break;

        case ACT_FUNC:
            o_expr.cv_actFunc = nullptr;
            ReadString(i_stream, o_expr.cv_actFunc);

            i_stream >> o_expr.cv_value[1].i;
            break;

        case ACT_CALL:
            i_stream >> l_tmpChar;
            o_expr.cv_value[0].i = l_tmpChar;
            i_stream >> o_expr.cv_value[1].i;

            if( Prdr::CALLOUT_GARD_SELF != o_expr.cv_value[0].i )
            {
                i_stream >> o_expr.cv_value[2].i;
                i_stream >> o_expr.cv_value[3].i;

                // Read ALT bool.
                i_stream >> l_tmpChar;
                if (0 != l_tmpChar)
                {
                    o_expr.cv_value[4].p = new Expr();
                    o_expr.cv_deletePtr[4] = true;
                    ReadExpr(i_stream, *o_expr.cv_value[4].p);
                }
                else
                    o_expr.cv_value[4].p = nullptr;

                // Read peer connection type
                i_stream >> o_expr.cv_value[5].i;
            }
            //Read gard state associated with callout
            i_stream >> l_tmp8;
            o_expr.cv_value[6].i = l_tmp8;


            break;

        case ACT_DUMP: //@ecdf
            i_stream >> o_expr.cv_value[0].i;
            break;

        case ATTNLINK:
            i_stream >> l_tmpChar; // get count
            l_tmp32 = l_tmpChar;
            for (size_t i = 0; i < l_tmp32; i++)
            {
                i_stream >> l_tmpChar; // get index
                o_expr.cv_value[l_tmpChar].p = new Expr();
                o_expr.cv_deletePtr[l_tmpChar] = true;
                ReadExpr(i_stream, *o_expr.cv_value[l_tmpChar].p);
            }
            break;

        case ACT_CAPT:
            i_stream >> o_expr.cv_value[0].i;

        default:
            break;
    }
}

Register::Register() : cv_name(0)
{}

Register::~Register()
{
    for(std::vector<CaptureInfoStruct>::iterator
        j = cv_captures.begin();
        j != cv_captures.end();
        ++j)
    {
        if (nullptr != (*j).func)
        {
            delete[] (*j).func;
            (*j).func = nullptr;
        }
    }
}

Expr::Expr()
{
    cv_op = 0;
    cv_actFunc = nullptr;
    // Clear out the pointers and 'delete' settings.
    for (uint32_t i = 0; i < MAX_VALUES; i++)
    {
        cv_deletePtr[i] = false;
        cv_value[i].p = nullptr;
    }
}

Expr::~Expr()
{
    // Special things for certain operator types...
    switch (cv_op)
    {
        // On function call operator and bit string,
        // cv_value[0].p points to a string.
        case ACT_FUNC:
            if(nullptr != cv_actFunc)
            {
                delete[] cv_actFunc;
                cv_actFunc = nullptr;
            }
            break;
        case BIT_STR:
            cv_bitStrVect.clear();
            break;

        // No other special cases yet.
        default:
            break;
    }

    // Delete all pointers.
    for (uint32_t i = 0; i < MAX_VALUES; i++)
        if (cv_deletePtr[i])
            delete (cv_value[i].p);
};

} // end namespace Prdr

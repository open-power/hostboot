/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrLoadChip.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include <iipglobl.h>
#include <UtilHash.H> // for Util::hashString

#include <algorithm> // for std::generate_n

namespace Prdr
{

void prdrReadExpr(UtilStream & i_stream, PrdrExpr & o_expr);

// NOTE: caller must call delete[] to release the buffer
void prdrReadString(UtilStream & i_stream, char *& o_string)
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

errlHndl_t prdrLoadChip(UtilStream & i_stream, PrdrChip & o_chip)
{
    errlHndl_t l_errl = NULL;

    do
    {
        char l_temp[8];

        // read header.
        i_stream >> l_temp;
        if (0 != memcmp(l_temp, "PRDRCHIP", 8))
        {
            PRDF_ERR("prdrLoadChip() bad chip file - l_temp: %s ", l_temp);
            // Bad chip file.
            /*@
             * @errortype
             * @refcode         LIC_REFCODE
             * @subsys                 EPUB_FIRMWARE_SP
             * @reasoncode         PRDF_CODE_FAIL
             *
             * @moduleid           PRDF_PRDRLOADCHIP
             * @userdata1          0x50524452 ("PRDR")
             * @userdata2          0x43484950 ("CHIP")
             * @devdesc                Attempted to load chip rule file that lacked
             *                         the proper header "PRDRCHIP".
             */
            PRDF_CREATE_ERRL(l_errl,
                             ERRL_SEV_UNRECOVERABLE,
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_ERR_INFO,
                             SRCI_NO_ATTR,
                             PRDF_PRDRLOADCHIP,
                             LIC_REFCODE,
                             PRDF_CODE_FAIL,
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
            o_chip.cv_registers = new PrdrRegister[o_chip.cv_regCount];
            for (uint32_t i = 0; i < o_chip.cv_regCount; i++)
            {
                i_stream >> o_chip.cv_registers[i].cv_name;
                i_stream >> o_chip.cv_registers[i].cv_flags;
                i_stream >> o_chip.cv_registers[i].cv_scomAddr;

                if (o_chip.cv_registers[i].cv_flags &
                        Prdr::PRDR_REGISTER_SCOMLEN)
                {
                    i_stream >> o_chip.cv_registers[i].cv_scomLen;
                }
                else
                {
                    o_chip.cv_registers[i].cv_scomLen = o_chip.cv_scomLen;
                }

                if (o_chip.cv_registers[i].cv_flags &
                        Prdr::PRDR_REGISTER_RESETS)
                {
                    // Read 'n' from stream.  Read that many reset structs out
                    // of the stream, insert into cv_resets for register.
                    std::generate_n(
                            std::back_inserter(
                                o_chip.cv_registers[i].cv_resets
                                ),
                            Util::unary_input<uint16_t, UtilStream>(i_stream)(),
                            Util::unary_input<PrdrRegister::ResetOrMaskStruct,
                                              UtilStream> (i_stream)
                            );

                }

                if (o_chip.cv_registers[i].cv_flags &
                        Prdr::PRDR_REGISTER_MASKS)
                {
                    // Read 'n' from stream.  Read that many mask structs out
                    // of the stream, insert into cv_masks for register.
                    std::generate_n(
                            std::back_inserter(
                                o_chip.cv_registers[i].cv_masks
                                ),
                            Util::unary_input<uint16_t, UtilStream>(i_stream)(),
                            Util::unary_input<PrdrRegister::ResetOrMaskStruct,
                                              UtilStream> (i_stream)
                            );

                }

                if (o_chip.cv_registers[i].cv_flags &
                        Prdr::PRDR_REGISTER_CAPTURE)
                {
                    // Read 'n' from stream.  Read that many mask structs out
                    // of the stream, insert into cv_masks for register.
                    std::generate_n(
                            std::back_inserter(
                                o_chip.cv_registers[i].cv_captures
                                ),
                            Util::unary_input<uint16_t, UtilStream>(i_stream)(),
                            Util::unary_input<PrdrRegister::CaptureInfoStruct,
                                              UtilStream> (i_stream)
                            );
                }
            }
        }

        // read rules.
        i_stream >> o_chip.cv_ruleCount;
        if (o_chip.cv_ruleCount != 0)
        {
            o_chip.cv_rules = new PrdrExpr[o_chip.cv_ruleCount];
            for (uint32_t i = 0; i < o_chip.cv_ruleCount; i++)
            {
                i_stream >> l_temp[0]; // should be 'R'
                prdrReadExpr(i_stream, o_chip.cv_rules[i]);
            }
        }

        // read groups.
        i_stream >> o_chip.cv_groupCount;
        for (int i = 0; i < NUM_GROUP_ATTN; i++) // @jl02 JL Added this enum type for the number of Attention types.
            i_stream >> o_chip.cv_groupAttn[i];
        if (o_chip.cv_groupCount != 0)
        {
            o_chip.cv_groups = new PrdrExpr * [o_chip.cv_groupCount];
            o_chip.cv_groupSize = new uint16_t[o_chip.cv_groupCount];
            o_chip.cv_groupFlags = new uint8_t[o_chip.cv_groupCount];
            o_chip.cv_groupPriorityBits = new PrdrExpr * [o_chip.cv_groupCount];
            for (uint32_t i = 0; i < o_chip.cv_groupCount; i++)
            {
                i_stream >> l_temp[0]; // should be 'G'
                i_stream >> o_chip.cv_groupSize[i];
                i_stream >> o_chip.cv_groupFlags[i];
                if (Prdr::PRDR_GROUP_FILTER_PRIORITY & o_chip.cv_groupFlags[i])
                {
                    o_chip.cv_groupPriorityBits[i] = new PrdrExpr();
                    prdrReadExpr(i_stream, *o_chip.cv_groupPriorityBits[i]);
                }
                else
                {
                    o_chip.cv_groupPriorityBits[i] = NULL;
                }
                if (0 != o_chip.cv_groupSize[i])
                {
                    o_chip.cv_groups[i] = new PrdrExpr[o_chip.cv_groupSize[i]];
                    for (uint32_t j = 0; j < o_chip.cv_groupSize[i]; j++)
                    {
                        prdrReadExpr(i_stream, o_chip.cv_groups[i][j]);
                        if (Prdr::REF_RULE == o_chip.cv_groups[i][j].cv_op)
                        {
                            for (int k = 1; k <= 2; k++)
                            {
                                o_chip.cv_groups[i][j].cv_value[k].p =
                                        new PrdrExpr();
                                o_chip.cv_groups[i][j].cv_deletePtr[k] = true;

                                prdrReadExpr(i_stream,
                                        *o_chip.cv_groups[i][j].cv_value[k].p);
                            }
                        }
                    }
                }
                else
                {
                    o_chip.cv_groups[i] = new PrdrExpr[0]; /*accessing beyond memory*/
                                                          // False error BEAM.
                };
            }
        }

        // read actions.
        i_stream >> o_chip.cv_actionCount;
        if (o_chip.cv_actionCount != 0)
        {
            o_chip.cv_actions = new PrdrExpr * [o_chip.cv_actionCount];
            o_chip.cv_actionSize = new uint16_t[o_chip.cv_actionCount];
            for (uint32_t i = 0; i < o_chip.cv_actionCount; i++)
            {
                i_stream >> l_temp[0]; // should be 'A'
                i_stream >> o_chip.cv_actionSize[i];
                if (0 != o_chip.cv_actionSize[i])
                {
                    o_chip.cv_actions[i] =
                            new PrdrExpr[o_chip.cv_actionSize[i]];
                    for (uint32_t j = 0; j < o_chip.cv_actionSize[i]; j++)
                    {
                        prdrReadExpr(i_stream, o_chip.cv_actions[i][j]);
                    }
                }
                else //@pw01
                {
                    o_chip.cv_actions[i] = NULL;
                }
            }
        }

    } while (false);

    if (NULL == l_errl)
        l_errl = i_stream.getLastError();

    return l_errl;
}

void prdrReadExpr(UtilStream & i_stream, PrdrExpr & o_expr)
{
    unsigned char l_tmpChar;
    uint32_t l_tmp32;
    uint16_t l_tmp16;
    uint8_t l_tmp8;
    bool l_tmpBool;

    i_stream >> o_expr.cv_op;

    switch(o_expr.cv_op)
    {
        case Prdr::AND:
        case Prdr::OR:
        case Prdr::XOR:
        case Prdr::LSHIFT:
        case Prdr::RSHIFT:
        case Prdr::ACT_TRY:
            o_expr.cv_value[0].p = new PrdrExpr();
            o_expr.cv_deletePtr[0] = true;
            prdrReadExpr(i_stream, *o_expr.cv_value[0].p);

            o_expr.cv_value[1].p = new PrdrExpr();
            o_expr.cv_deletePtr[1] = true;
            prdrReadExpr(i_stream, *o_expr.cv_value[1].p);
            break;

        case Prdr::NOT:
            o_expr.cv_value[0].p = new PrdrExpr();
            o_expr.cv_deletePtr[0] = true;
            prdrReadExpr(i_stream, *o_expr.cv_value[0].p);
            break;

        case Prdr::INTEGER:
        case Prdr::ACT_GARD:
        case Prdr::ACT_FLAG:
            i_stream >> o_expr.cv_value[0].i;
            break;

        case Prdr::REF_RULE:
        case Prdr::REF_REG:
        case Prdr::REF_GRP:
        case Prdr::REF_ACT:
        case Prdr::INT_SHORT:
            i_stream >> l_tmp16;
            o_expr.cv_value[0].i = l_tmp16;
            break;

        case Prdr::BIT_STR:
            o_expr.cv_bitStrVect.clear();
            prdrReadBitString(i_stream, o_expr.cv_bitStrVect);
            break;

        case Prdr::ACT_THRES:
            o_expr.cv_value[0].i = ThresholdResolution::cv_fieldDefault.interval;
            o_expr.cv_value[1].i = ThresholdResolution::cv_fieldDefault.threshold;
            o_expr.cv_value[2].i = ThresholdResolution::cv_mnfgDefault.interval;
            o_expr.cv_value[3].i = ThresholdResolution::cv_mnfgDefault.threshold;
            //The syntax of thresholds in rule file is
            // op field_threshold field_intervale
            //optional fields (mnfg_threshold, mnfg_interval } | mnfg_ilr_threshold | maskid
            i_stream >> l_tmpChar;
            l_tmpBool = (0x40 == (0x40 & l_tmpChar));
            l_tmpChar &= (~0x40);
            o_expr.cv_value[4].i = (0x20 == (0x20 & l_tmpChar));
            l_tmpChar &= (~0x20);
            // The values which different parameter will have
            // cv_value[0,1] error frequency and time in sec for field threshold
            //cv_value[4] true if mnfg threshols needs to be picked up from mnfg file, false otherwise
            // cv_value [2, 3]: error frequency and time in sec for mnfg threshold if cv_value[4] is false
            // otherwise cv_value[3] tells which threshold needs to pick up from mnfg file
            // cv_value[5] maski id if shared threshold
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

        case Prdr::ACT_ANALY:
            i_stream >> o_expr.cv_value[0].i;
            i_stream >> o_expr.cv_value[1].i;
            break;

        case Prdr::ACT_FUNC:
            o_expr.cv_actFunc = NULL;
            prdrReadString(i_stream, o_expr.cv_actFunc);

            i_stream >> o_expr.cv_value[1].i;
            break;

        case Prdr::ACT_CALL:
            i_stream >> l_tmpChar;
            o_expr.cv_value[0].i = l_tmpChar;
            i_stream >> o_expr.cv_value[1].i;
            if ('s' != o_expr.cv_value[0].i)
            {
                i_stream >> o_expr.cv_value[2].i;
                i_stream >> o_expr.cv_value[3].i;

                // Read ALT bool.
                i_stream >> l_tmpChar;
                if (0 != l_tmpChar)
                {
                    o_expr.cv_value[4].p = new PrdrExpr();
                    o_expr.cv_deletePtr[4] = true;
                    prdrReadExpr(i_stream, *o_expr.cv_value[4].p);
                }
                else
                    o_expr.cv_value[4].p = NULL;
            }
            break;

        case Prdr::ACT_DUMP: //@ecdf
            i_stream >> o_expr.cv_value[0].i;
            break;

        case Prdr::ATTNLINK:
            i_stream >> l_tmpChar; // get count
            l_tmp32 = l_tmpChar;
            for (size_t i = 0; i < l_tmp32; i++)
            {
                i_stream >> l_tmpChar; // get index
                o_expr.cv_value[l_tmpChar].p = new PrdrExpr();
                o_expr.cv_deletePtr[l_tmpChar] = true;
                prdrReadExpr(i_stream, *o_expr.cv_value[l_tmpChar].p);
            }
            break;

        case Prdr::ACT_CAPT:
            i_stream >> o_expr.cv_value[0].i;

        default:
            break;
    }
}

PrdrRegister::PrdrRegister() : cv_name(0)
{}

PrdrRegister::~PrdrRegister()
{
    for(std::vector<CaptureInfoStruct>::iterator
        j = cv_captures.begin();
        j != cv_captures.end();
        ++j)
    {
        if (NULL != (*j).func)
        {
            delete[] (*j).func;
            (*j).func = NULL;
        }
    }
}

PrdrExpr::PrdrExpr()
{
    cv_op = 0;
    cv_actFunc = NULL;
    // Clear out the pointers and 'delete' settings.
    for (uint32_t i = 0; i < MAX_VALUES; i++)
    {
        cv_deletePtr[i] = false;
        cv_value[i].p = NULL;
    }
}

PrdrExpr::~PrdrExpr()
{
    // Special things for certain operator types...
    switch (cv_op)
    {
        // On function call operator and bit string,
        // cv_value[0].p points to a string.
        case Prdr::ACT_FUNC:
            if(NULL != cv_actFunc)
            {
                delete[] cv_actFunc;
                cv_actFunc = NULL;
            }
            break;
        case Prdr::BIT_STR:
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

} // end namespace.

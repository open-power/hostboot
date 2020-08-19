/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrExpr.H $                    */
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

#ifndef __PRDREXPR_H
#define __PRDREXPR_H

#include <map>
#include <list>
#include <sstream>
#include <stdint.h>
#include <typeinfo>                // for typeid

#include <netinet/in.h>

#include <prdrCommon.H> // for enums.

using Prdr::SignatureOp;

extern void yyerror(const char *);

namespace PRDR_COMPILER
{

// -- Forward defs //
class Expr;
uint16_t prdrGetRefId(std::string *);
char prdrGetRefType(std::string *);
void prdrCheckReferences();
uint32_t prdrActionArgMap(const std::string &);
uint32_t prdrCaptureGroupMap(const std::string &);
uint32_t prdrCaptureTypeMap(const std::string &);
std::list<std::string> prdrParseDoxygen(std::string & i_string);
class Chip;
extern Chip * g_currentChip;
extern std::map<std::string, Expr *> g_rules;
extern uint32_t g_nextAndBit;
extern bool g_hadError;
// -- end Forward defs //

class Expr
{
    public:

        virtual int output(FILE *) = 0;

        virtual void setComment(std::string & i_comment)
                { cv_doxcomment = i_comment; };

        virtual void generateDoxygen(std::ostream & o_stream,
                                     std::string & o_trailing,
                                     std::ostream & o_errFile = std::cerr)
                { o_stream << "Using default."; };

        virtual uint16_t getSignature()
                {
                    std::cerr << "def sig: " << typeid(*this).name()
                              << std::endl;
                    return SignatureOp::DEFAULT_SIGNATURE;
                };


        Expr() : cv_doxcomment("") {};
        virtual ~Expr() {};

    protected:
        std::string cv_doxcomment;
};

class ExprRef : public Expr
{
    public:
        std::string *         cv_name;

        ExprRef(std::string * n) : cv_name(n) {};

        int output(FILE * i_file)
            {
                char l_op = prdrGetRefType(cv_name);
                uint16_t l_id = htons(prdrGetRefId(cv_name));

                PRDR_FWRITE(&l_op, 1, 1, i_file);
                PRDR_FWRITE(&l_id, sizeof(l_id), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "<A HREF=\"#" << *cv_name << "\">"
                     << *cv_name << "</A>";
        }

        virtual uint16_t getSignature()
        {
            if (Prdr::REF_REG == prdrGetRefType(cv_name))
            {
                return PRDF::Util::hashString(cv_name->c_str());
            }
            else
            {
                Expr * tmp = g_rules[*cv_name];
                if (nullptr == tmp)
                {
                    std::cerr << "NPE: " << *cv_name << std::endl;
                }
                return (nullptr == tmp ?
                        SignatureOp::DEFAULT_SIGNATURE
                        : tmp->getSignature()
                    );
            }
        };

};

class ExprInt : public Expr
{
    public:
        uint32_t        cv_value;
        char                cv_op;

        ExprInt() : cv_op(Prdr::INTEGER) {};
        ExprInt(uint32_t v, char o = Prdr::INTEGER) : cv_value(v),
                                                              cv_op(o) {};

        int output(FILE * i_file)
            {
                char tmp = cv_op;
                PRDR_FWRITE(&tmp, 1, 1, i_file);

                if (Prdr::INTEGER != cv_op)
                {
                    uint16_t temp = htons((uint16_t) cv_value);
                    PRDR_FWRITE(&temp, sizeof(temp), 1, i_file);
                }
                else
                {
                    uint32_t temp = htonl(cv_value);
                    PRDR_FWRITE(&temp, sizeof(temp), 1, i_file);
                }

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << cv_value;
            o_errFile << std::setfill('0') << std::setw(2) << std::hex
                      << cv_value;
        };

        uint16_t getSignature() { return SignatureOp::DEFAULT_SIGNATURE; };
};

class ExprTime : public Expr
{
  public:

    uint32_t            iv_units;
    Prdr::TimeBaseFlags iv_base;

    ExprTime() :
        iv_units(0xffffffff), iv_base(Prdr::PRDR_TIME_BASE_SEC)
    {}

    ExprTime( uint32_t units, Prdr::TimeBaseFlags base ) :
        iv_units(units), iv_base(base)
    {}

    int output( FILE * i_file )
    {
        uint32_t seconds = 0xffffffff;
        if ( (seconds / iv_base) > iv_units )
            seconds = iv_units * iv_base;

        seconds = htonl( seconds );
        PRDR_FWRITE( &seconds, sizeof(seconds), 1, i_file );

        return 0;
    }

    void generateDoxygen( std::ostream & o_stream,
                          std::string  & o_trailing,
                          std::ostream & o_errFile = std::cerr )
    {
        o_stream << iv_units << " ";
        switch ( iv_base )
        {
            case Prdr::PRDR_TIME_BASE_SEC:  o_stream << "sec";  break;
            case Prdr::PRDR_TIME_BASE_MIN:  o_stream << "min";  break;
            case Prdr::PRDR_TIME_BASE_HOUR: o_stream << "hour"; break;
            case Prdr::PRDR_TIME_BASE_DAY:  o_stream << "day";  break;
            default: ;
        }
    }
};

class ExprBitString : public Expr
{
    public:
        std::string        cv_value;
        char                cv_op;

        ExprBitString() : cv_value(), cv_op(Prdr::BIT_STR) {};
        ExprBitString(std::string v, char o = Prdr::BIT_STR) : cv_value(v),
                                                                   cv_op(o) {};

        int output(FILE * i_file)
            {
                char tmp = cv_op;
                PRDR_FWRITE(&tmp, 1, 1, i_file);

                // subtract 2 backticks.
                uint8_t len = (cv_value.length() - 2) * 4;
                PRDR_FWRITE(&len, sizeof(len), 1, i_file);

                uint8_t tmp8 = 0;

                len = len / 4;

                // Output binary data from hex.
                for (int i = 0; i < len; i++)
                {
                    if (isdigit(cv_value[i+1]))
                    {
                        tmp8 |= cv_value[i+1] - '0';
                    }
                    else
                    {
                        tmp8 |= toupper(cv_value[i+1]) - 'A' + 0xa;
                    }

                    if (i == (len - 1))
                    {
                        while ((i % 2) != 1)
                        {
                            tmp8 <<= 4;
                            i++;
                        }
                    }
                    if (i % 2 == 1)
                    {
                        PRDR_FWRITE(&tmp8, sizeof(tmp8), 1, i_file);
                        tmp8 = 0;
                    }

                    tmp8 <<= 4;
                }

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << cv_value;
            o_errFile << cv_value;
        };

        uint16_t getSignature() { return SignatureOp::DEFAULT_SIGNATURE; };
};


class ExprOp1 : public Expr
{
    public:
        char                   cv_op;
        Expr *         cv_arg;

        ExprOp1(char o) : cv_op(o) {};
        ExprOp1(char o, Expr * a) : cv_op(o), cv_arg(a) {};

        int output(FILE * i_file)
            {
                PRDR_FWRITE(&cv_op, 1, 1, i_file);
                if (nullptr != cv_arg)
                    cv_arg->output(i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << cv_op << " ";
            if (nullptr != cv_arg)
                cv_arg->generateDoxygen(o_stream, o_trailing, o_errFile);
        };

        uint16_t getSignature()
        {
            return (nullptr == cv_arg ?
                        SignatureOp::DEFAULT_SIGNATURE
                        : cv_arg->getSignature()
                   );
        }

};

class ExprOp2 : public Expr
{
    public:
        Expr *        cv_arg[2];
        char                cv_op;

        ExprOp2(char o) : cv_op(o) {};
        ExprOp2(char o, Expr * a1, Expr * a2) : cv_op(o)
            {
                cv_arg[0] = a1; cv_arg[1] = a2;
            };

        int output(FILE * i_file)
            {
                PRDR_FWRITE(&cv_op, 1, 1, i_file);
                if (nullptr != cv_arg[0])
                    cv_arg[0]->output(i_file);
                if (nullptr != cv_arg[1])
                    cv_arg[1]->output(i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            if (nullptr != cv_arg[0])
                cv_arg[0]->generateDoxygen(o_stream, o_trailing, o_errFile);
            o_stream << " " << cv_op << " ";

            if (nullptr != cv_arg[1])
                cv_arg[1]->generateDoxygen(o_stream, o_trailing, o_errFile);
        };

        uint16_t getSignature()
        {
            // To match the signature generation during IPL
            // time in RightShiftRegister/LeftShiftRegister,
            // We need to skip calling combineSig during
            // rule compile time.
            // The casting is needed since these are extend ascii codes
            if ((char(Prdr::RSHIFT) == cv_op) ||
                (char(Prdr::LSHIFT) == cv_op))
            {
                return cv_arg[0]->getSignature();
            }
            else
            {
                return SignatureOp::combineSig(
                                    (nullptr == cv_arg[0] ?
                                      SignatureOp::DEFAULT_SIGNATURE
                                      : cv_arg[0]->getSignature()
                                    ),
                                    (nullptr == cv_arg[1] ?
                                      SignatureOp::DEFAULT_SIGNATURE
                                      : cv_arg[1]->getSignature()
                                    ));
            }
        };

};

class ExprAttnLink : public Expr
{
    public:
        Expr * cv_arg[Prdr::MAX_NUM_ATTN_TYPES];

        ExprAttnLink(std::string * attn1, Expr * exp1,
                     std::string * attn2, Expr * exp2,
                     std::string * attn3, Expr * exp3,
                     std::string * attn4, Expr * exp4,
                     std::string * attn5, Expr * exp5)
        {
            for (int i = 0; i < Prdr::MAX_NUM_ATTN_TYPES; i++)
                cv_arg[i] = nullptr;

            cv_arg[decodeAttnType(attn1)] = exp1;
            if (nullptr != exp2)
                cv_arg[decodeAttnType(attn2)] = exp2;
            if (nullptr != exp3)
                cv_arg[decodeAttnType(attn3)] = exp3;
            if (nullptr != exp4)
                cv_arg[decodeAttnType(attn4)] = exp4;
            if (nullptr != exp5)
                cv_arg[decodeAttnType(attn5)] = exp5;
        };

        int output(FILE * i_file)
        {
            char cv_op = Prdr::ATTNLINK;
            PRDR_FWRITE(&cv_op, 1, 1, i_file);

            cv_op = 0;
            for (int i = 0; i < Prdr::MAX_NUM_ATTN_TYPES; i++)
                if (nullptr != cv_arg[i])
                    cv_op++;
            PRDR_FWRITE(&cv_op, 1, 1, i_file);

            for (int i = 0; i < Prdr::MAX_NUM_ATTN_TYPES; i++)
                if (nullptr != cv_arg[i])
                {
                    cv_op = i;
                    PRDR_FWRITE(&cv_op, 1, 1, i_file);
                    cv_arg[i]->output(i_file);
                }

            return 0;
        }

        uint16_t getSignature()
        {
            uint16_t l_val = SignatureOp::DEFAULT_SIGNATURE;
            for (int i = 0; i < Prdr::MAX_NUM_ATTN_TYPES; i++)
                if (nullptr != cv_arg[i])
                    l_val = SignatureOp::combineSig(l_val,
                                                    cv_arg[i]->getSignature());
                else
                    l_val = SignatureOp::combineSig(l_val,
                                            SignatureOp::DEFAULT_SIGNATURE);
            return l_val;
        };

    protected:
        int decodeAttnType(std::string * attn)
        {
            if (nullptr == attn)
            {
                yyerror("ICE - NPE.");
            }
            else if ("CHECK_STOP" == *attn)
            {
                return 0;
            }
            else if ("RECOVERABLE" == *attn)
            {
                return 1;
            }
            else if ("SPECIAL" == *attn)
            {
                return 2;
            }
            else if ("PROC_CS" == *attn)
            {
                return 3;
            }
            else if ("UNIT_CS" == *attn)
            {
                return 3;
            }
            else if ("HOST_ATTN" == *attn)
            {
                return 4;
            }
            else
            {
                char error[256];
                strcpy(error, "Invalid attention name: ");
                strncat(error, attn->c_str(), 255);

                yyerror(error);
            }
            return 0;
        };
};


class ExprRule : public Expr
{
    public:
        std::string *         cv_rulename;
        Expr *         cv_bits;
        std::string *         cv_actionname;

        ExprRule(std::string * r, Expr * b, std::string * a)
            : cv_rulename(r), cv_bits(b), cv_actionname(a) {};

        int output(FILE * i_file)
            {
                uint16_t l_ref;
                char l_op;

                l_op = Prdr::REF_RULE;
                PRDR_FWRITE(&l_op, 1, 1, i_file);
                l_ref = htons(prdrGetRefId(cv_rulename));
                PRDR_FWRITE(&l_ref, sizeof(l_ref), 1, i_file);

                cv_bits->output(i_file);

                l_op = prdrGetRefType(cv_actionname);
                PRDR_FWRITE(&l_op, 1, 1, i_file);
                l_ref = htons(prdrGetRefId(cv_actionname));
                PRDR_FWRITE(&l_ref, sizeof(l_ref), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            std::list<std::string> l_parsed = prdrParseDoxygen(cv_doxcomment);

            std::string l_name("N/A"), l_short("N/A"), l_long("");
            std::ostringstream l_errFront, l_errBits, l_errBack;

            l_errFront << "\tPRDR_ERROR_SIGNATURE ( 0x"
                       << std::setfill('0') << std::setw(4)
                       << std::hex
                       << ( (ExprRef(cv_rulename).getSignature()
                             + g_currentChip->cv_signatureOffset) & 0xffff )
                       << "00";

            o_stream << "<TD align=\"center\">";
            cv_bits->generateDoxygen(o_stream, o_trailing, l_errBits);

            if (std::string() != l_parsed.front())
            {
                l_name = l_parsed.front();
            }
            l_parsed.pop_front();

            if (std::string() != l_parsed.front())
            {
                l_short = l_parsed.front();
            }
            l_parsed.pop_front();

            if (std::string() != l_parsed.front())
            {
                l_long = l_parsed.front();
            }

            o_stream << "<TD align=\"center\">";
            if (std::string() != l_long)
            {
                o_stream << "<A HREF=\"#" << l_name << "\">";

                o_trailing += "<B><A NAME='" + l_name + "'>" ;
                o_trailing += l_name + ": </A></B>";

                o_trailing += l_short + "<BR>";
                o_trailing += l_long + "<BR><BR>\n";
            }
            o_stream << l_name;
            if (std::string() != l_long)
            {
                o_stream << "</A>";
                o_trailing += "</A>";
            }

            o_stream << "<TD>" << l_short;


            o_stream << "<TD><A HREF=\"#" << *cv_actionname << "\">"
                     << *cv_actionname << "</A>";

            l_errBack << ", \"" << l_name << "\", \"" << l_short << "\"";
            l_errBack << " )" << std::endl;

            for (size_t i = 0; i < (l_errBits.str().length()/2); i++)
            {
                o_errFile << l_errFront.str();

                if (typeid(*cv_bits).name() == typeid(ExprOp2).name())
                {
                    if (static_cast<ExprOp2 *>(cv_bits)->cv_op == Prdr::AND)
                    {
                        o_errFile << std::setfill('0') << std::setw(2)
                                  << std::hex;
                        o_errFile << g_nextAndBit;
                        g_nextAndBit++;

                        i = 256;
                    }
                    else
                    {
                        o_errFile << l_errBits.str()[2*i]
                                  << l_errBits.str()[2*i+1];
                    }
                }
                else
                {
                    o_errFile << l_errBits.str()[2*i]
                              << l_errBits.str()[2*i+1];
                }

                o_errFile << l_errBack.str();
            }
        };
};

class ExprAct_Try : public Expr
{
    public:
        Expr * cv_left, * cv_right;

        ExprAct_Try(Expr * l, Expr * r) : cv_left(l),
                                                      cv_right(r) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_TRY;
                PRDR_FWRITE(&l_op, 1, 1, i_file);
                cv_left->output(i_file);
                cv_right->output(i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "try { ";
            if (nullptr != cv_left)
                cv_left->generateDoxygen(o_stream, o_trailing, o_errFile);
            o_stream << ", ";
            if (nullptr != cv_right)
                cv_right->generateDoxygen(o_stream, o_trailing, o_errFile);
            o_stream << " } ";
        };

};

class ExprAct_Thresh : public Expr
{
    public:
        Expr* cv_thresholdTime[2];
        //Maximum threshold value supported is 255
        uint8_t cv_field;
        uint8_t cv_mfg;
        uint32_t cv_3;
        std::string * cv_mfg_file_thr;

        ExprAct_Thresh( uint8_t i_field = 0, Expr * i_fieldTime = nullptr,
                            uint8_t i_mfg   = 0, Expr * i_mfgTime   = nullptr,
                            std::string * i_mfg_file = nullptr ) :
            cv_field(i_field), cv_mfg(i_mfg), cv_mfg_file_thr(i_mfg_file)
        {
            cv_thresholdTime[0] = i_fieldTime;
            cv_thresholdTime[1] = i_mfgTime;
            cv_3 = 0;
        };

        int output(FILE * i_file)
            {
                char l_op;
                l_op = Prdr::ACT_THRES;
                PRDR_FWRITE(&l_op, 1, 1, i_file);

                if (nullptr == cv_thresholdTime[0])
                    l_op = 0;
                else if ( (nullptr == cv_thresholdTime[1]) &&
                          (nullptr == cv_mfg_file_thr))
                {
                    l_op = 1;
                }
                else
                    l_op = 2;

                if (0 != cv_3)
                    l_op |= 0x40;

                if (nullptr != cv_mfg_file_thr)
                    l_op |= 0x20;

                PRDR_FWRITE(&l_op, 1, 1, i_file);

                if (nullptr != cv_thresholdTime[0])
                {
                    PRDR_FWRITE(&cv_field, sizeof(cv_field), 1, i_file);
                    cv_thresholdTime[0]->output(i_file);
                    if (nullptr != cv_thresholdTime[1])
                    {
                        PRDR_FWRITE(&cv_mfg, sizeof(cv_mfg), 1, i_file);
                        cv_thresholdTime[1]->output(i_file);
                    }
                    else if (nullptr != cv_mfg_file_thr)
                    {
                        uint32_t l_tmp32 = prdrActionArgMap(*cv_mfg_file_thr);
                        l_tmp32 = htonl(l_tmp32);
                        PRDR_FWRITE(&l_tmp32, sizeof(l_tmp32), 1, i_file);
                    }
                }

                if (0 != cv_3)
                {
                    uint32_t l_tmp32 = htonl(cv_3);
                    PRDR_FWRITE(&l_tmp32, 4, 1, i_file);
                }

                return 0;
            }

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
            {
                o_stream << "threshold(";
                if (nullptr != cv_thresholdTime[0])
                {
                    uint32_t units = cv_field;
                    o_stream <<" field";
                    o_stream << "(";
                    o_stream << units;
                    o_stream << ",";
                    cv_thresholdTime[0]->generateDoxygen(o_stream, o_trailing, o_errFile);
                    o_stream << ")";
                    if (nullptr != cv_thresholdTime[1])
                    {
                        units = cv_mfg;
                        o_stream << ", mfg";
                        o_stream << "(";
                        o_stream << units;
                        o_stream << ",";
                        cv_thresholdTime[1]->generateDoxygen(o_stream, o_trailing, o_errFile);
                        o_stream << ")";
                    }
                    else if (nullptr != cv_mfg_file_thr)
                    {
                        o_stream << ", mfg_file";
                        o_stream << "(";
                        o_stream << *cv_mfg_file_thr;
                        o_stream << ")";
                    }
                }
                o_stream << ")";
                if (0 != cv_3)
                {
                    o_stream << " shared(" << cv_3 << ")";
                }
            };

};


class ExprAct_Dump : public Expr  //@ecdf
{
    public:
        std::string * cv_1;

        ExprAct_Dump(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_DUMP;
                PRDR_FWRITE(&l_op, 1, 1, i_file);

                uint32_t l_dType;

                if (nullptr == cv_1)
                    l_dType = prdrActionArgMap("DUMP_CONTENT_HW");
                else
                    l_dType = prdrActionArgMap(*cv_1);
                l_dType = htonl(l_dType);
                PRDR_FWRITE(&l_dType, sizeof(l_dType), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "dump( " << *cv_1 << " ) ";
        };

};

class ExprAct_Analyse : public Expr
{
    public:
        std::string * cv_1;
        uint32_t cv_2;

        ExprAct_Analyse( std::string * i_1, uint32_t i_2 = 0xffffffff ) :
            cv_1(i_1), cv_2(i_2)
        {}

        int output(FILE * i_file)
        {
            char l_op = Prdr::ACT_ANALY;
            PRDR_FWRITE(&l_op, 1, 1, i_file);

            uint32_t l_chipType = htonl(prdrActionArgMap(*cv_1));
            PRDR_FWRITE(&l_chipType, sizeof(l_chipType), 1, i_file);

            uint32_t l_chipIndx = htonl(cv_2);
            PRDR_FWRITE(&l_chipIndx, sizeof(l_chipIndx), 1, i_file);

            return 0;
        };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "analyze ( ";
            o_stream << "connected ( " << *cv_1 ;
            if ( 0xffffffff != cv_2 )
                o_stream << ", " << cv_2;
            o_stream << " ) ) ";
        }

};

class ExprAct_Callout : public Expr
{
    public:
        std::string * cv_1, * cv_2;
        uint32_t cv_3;

        Expr * cv_alt;

        Prdr::Callout_type cv_type;
        std::string * cv_4;

        ExprAct_Callout(std::string * i_1,
                        std::string * i_2 = nullptr,
                        Prdr::Callout_type  i_t = Prdr::CALLOUT_GARD_SELF,
                        uint32_t      i_3 = 0xffffffff,
                        Expr        * i_alt = nullptr,
                        std::string * i_4 = nullptr ):
                                            cv_1(i_1), cv_2(i_2),
                                            cv_3(i_3), cv_alt(i_alt),
                                            cv_type(i_t),
                                            cv_4( i_4 )
        {}

        int output(FILE * i_file)
        {
            char l_op;

            l_op = Prdr::ACT_CALL;
            PRDR_FWRITE(&l_op, 1, 1, i_file);

            l_op = cv_type;
            PRDR_FWRITE(&l_op, 1, 1, i_file);

            uint32_t l_priority = htonl(prdrActionArgMap(*cv_1));
            PRDR_FWRITE(&l_priority, sizeof(l_priority), 1, i_file);

            if ( Prdr::CALLOUT_GARD_SELF != cv_type )
            {
                uint32_t l_arg = htonl(prdrActionArgMap(*cv_2));
                PRDR_FWRITE(&l_arg, sizeof(l_arg), 1, i_file);

                l_arg = htonl(cv_3);
                PRDR_FWRITE(&l_arg, sizeof(l_arg), 1, i_file);
                // Write bool for ALT resolution.
                l_op = (nullptr == cv_alt ? 0 : 1);
                PRDR_FWRITE(&l_op, 1, 1, i_file);

                // Write ALT resolution.
                if (nullptr != cv_alt)
                    cv_alt->output(i_file);

                // Write peer connection type
                if(Prdr::CALLOUT_GARD_PEER == cv_type)
                    l_arg = htonl(prdrActionArgMap(*cv_2));
                else
                    l_arg = htonl(prdrActionArgMap("TYPE_NA"));

                PRDR_FWRITE(&l_arg, sizeof(l_arg), 1, i_file);
            }
            // Write gard state
            if( nullptr == cv_4 )
            {
                // if no policy for gard has been specified explicitly, assume
                // it to be NO GARD for procedure callout. But for self or
                // connected callout, assume it to be GARD.

                if( Prdr::CALLOUT_PROC == cv_type ) // is it a procedure callout
                {
                    l_op = prdrActionArgMap("NO_GARD");
                }
                else
                {
                    l_op = prdrActionArgMap("GARD");
                }
            }
            else
            {
                l_op = prdrActionArgMap(*cv_4);
            }

            PRDR_FWRITE(&l_op, 1, 1, i_file);
            return 0;

        };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "callout ( ";
            std::string tmpGard("GARD");
            if( nullptr != cv_4 )
            {
                tmpGard.assign( *cv_4 );
            }

            if ( Prdr::CALLOUT_GARD_SELF == cv_type )
            {
                o_stream << "SELF, " << *cv_1 << tmpGard << " )";
            }
            else if ( Prdr::CALLOUT_PROC == cv_type )
            {
                o_stream << "procedure ( " << *cv_2 << " ), " << *cv_1 << " ) ";
            }
            else
            {
                if(Prdr::CALLOUT_GARD_PEER == cv_type)
                {
                    o_stream << "connected_peer ( " << *cv_2 ;
                }
                else
                {
                    o_stream << "connected ( " << *cv_2 ;
                }
                if ( 0xffffffff != cv_3 )
                    o_stream << ", " << cv_3;

                o_stream << " ), " << *cv_1 <<  tmpGard << " ) ";
            }
        }
};

class ExprAct_Funccall : public Expr
{
    public:
        std::string * cv_1, * cv_2;

        ExprAct_Funccall(std::string * i_1, std::string * i_2 = nullptr) :
                cv_1(i_1), cv_2(i_2) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_FUNC;
                PRDR_FWRITE(&l_op, 1, 1, i_file);

                if ('"' == (*cv_1)[0])
                    (*cv_1) = cv_1->substr(1, cv_1->size() - 2);
                PRDR_FWRITE(cv_1->c_str(), cv_1->size() + 1, 1, i_file);

                uint32_t l_chip;
                if (nullptr != cv_2)
                    l_chip = htonl(prdrActionArgMap(*cv_2));
                else
                    l_chip = 0;
                PRDR_FWRITE(&l_chip, sizeof(l_chip), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "funccall( " << *cv_1;
            if (nullptr != cv_2)
                o_stream << ", " << *cv_2;
            o_stream << " ) ";
        };


};

class ExprAct_Flag : public Expr
{
    public:
        std::string * cv_1;

        ExprAct_Flag(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_FLAG;
                PRDR_FWRITE(&l_op, 1, 1, i_file);

                uint32_t l_flag = htonl(prdrActionArgMap(*cv_1));
                PRDR_FWRITE(&l_flag, sizeof(l_flag), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "flag( " << *cv_1 << " ) ";
        };


};

class ExprAct_Capture : public Expr
{
    public:
        std::string * cv_1;

        ExprAct_Capture(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_CAPT;
                PRDR_FWRITE(&l_op, 1, 1, i_file);

                uint32_t l_group = htonl(prdrCaptureGroupMap(*cv_1));
                PRDR_FWRITE(&l_group, sizeof(l_group), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "capture( " << *cv_1 << " ) ";
        };


};

extern std::map<std::string, Expr *> g_rules;

typedef std::pair<std::string, std::string> RefPair;
extern std::list<RefPair> g_references;

} // end namespace PRDR_COMPILER

#endif


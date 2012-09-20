/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdrExpr.H $                 */
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

#ifndef __PRDREXPR_H
#define __PRDREXPR_H

#include <map>
#include <list>
#include <sstream>
#include <stdint.h>
#include <typeinfo>                // for typeid

#include <netinet/in.h>

#include <prdrCommon.H> // for enums.

// -- Forward defs //
class PrdrExpr;
uint16_t prdrGetRefId(std::string *);
char prdrGetRefType(std::string *);
void prdrCheckReferences();
uint32_t prdrActionArgMap(const std::string &);
uint32_t prdrCaptureGroupMap(const std::string &);
uint32_t prdrCaptureTypeMap(const std::string &); // @jl04  Type for registers.
std::list<std::string> prdrParseDoxygen(std::string & i_string);
class PrdrChip;
extern PrdrChip * g_currentChip;
extern std::map<std::string, PrdrExpr *> g_rules;
extern void yyerror(const char *);
extern uint32_t g_nextAndBit;
extern bool g_hadError;
// -- end Forward defs //

using Prdr::PrdrSignatureOp;

class PrdrExpr
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
                    return PrdrSignatureOp::DEFAULT_SIGNATURE;
                };


        PrdrExpr() : cv_doxcomment("") {};
        virtual ~PrdrExpr() {};

    protected:
        std::string cv_doxcomment;
};

class PrdrExprRef : public PrdrExpr
{
    public:
        std::string *         cv_name;

        PrdrExprRef(std::string * n) : cv_name(n) {};

        int output(FILE * i_file)
            {
                char l_op = prdrGetRefType(cv_name);
                uint16_t l_id = htons(prdrGetRefId(cv_name));

                fwrite(&l_op, 1, 1, i_file);
                fwrite(&l_id, sizeof(l_id), 1, i_file);

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
                return Util::hashString(cv_name->c_str());
            }
            else
            {
                PrdrExpr * tmp = g_rules[*cv_name];
                if (NULL == tmp)
                {
                    std::cerr << "NPE: " << *cv_name << std::endl;
                }
                return (NULL == tmp ?
                        PrdrSignatureOp::DEFAULT_SIGNATURE
                        : tmp->getSignature()
                    );
            }
        };

};

class PrdrExprInt : public PrdrExpr
{
    public:
        uint32_t        cv_value;
        char                cv_op;

        PrdrExprInt() : cv_op(Prdr::INTEGER) {};
        PrdrExprInt(uint32_t v, char o = Prdr::INTEGER) : cv_value(v),
                                                              cv_op(o) {};

        int output(FILE * i_file)
            {
                char tmp = cv_op;
                fwrite(&tmp, 1, 1, i_file);

                if (Prdr::INTEGER != cv_op)
                {
                    uint16_t temp = htons((uint16_t) cv_value);
                    fwrite(&temp, sizeof(temp), 1, i_file);
                }
                else
                {
                    uint32_t temp = htonl(cv_value);
                    fwrite(&temp, sizeof(temp), 1, i_file);
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

        uint16_t getSignature() { return PrdrSignatureOp::DEFAULT_SIGNATURE; };
};

class PrdrExprTime : public PrdrExpr
{
  public:

    uint32_t                iv_units;
    Prdr::PrdrTimeBaseFlags iv_base;

    PrdrExprTime() :
        iv_units(0xffffffff), iv_base(Prdr::PRDR_TIME_BASE_SEC)
    {}

    PrdrExprTime( uint32_t units, Prdr::PrdrTimeBaseFlags base ) :
        iv_units(units), iv_base(base)
    {}

    int output( FILE * i_file )
    {
        uint32_t seconds = 0xffffffff;
        if ( (seconds / iv_base) > iv_units )
            seconds = iv_units * iv_base;

        seconds = htonl( seconds );
        fwrite( &seconds, sizeof(seconds), 1, i_file );

        return 0;
    }

    void generateDoxygen( std::ostream & o_stream,
                          std::string  & o_trailing,
                          std::ostream & o_errFile = std::cerr )
    {
        uint32_t seconds = iv_units * iv_base;

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

class PrdrExprBitString : public PrdrExpr
{
    public:
        std::string        cv_value;
        char                cv_op;

        PrdrExprBitString() : cv_value(), cv_op(Prdr::BIT_STR) {};
        PrdrExprBitString(std::string v, char o = Prdr::BIT_STR) : cv_value(v),
                                                                   cv_op(o) {};

        int output(FILE * i_file)
            {
                char tmp = cv_op;
                fwrite(&tmp, 1, 1, i_file);

                // subtract 2 backticks.
                uint8_t len = (cv_value.length() - 2) * 4;
                fwrite(&len, sizeof(len), 1, i_file);

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
                        fwrite(&tmp8, sizeof(tmp8), 1, i_file);
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

        uint16_t getSignature() { return PrdrSignatureOp::DEFAULT_SIGNATURE; };
};


class PrdrExprOp1 : public PrdrExpr
{
    public:
        char                   cv_op;
        PrdrExpr *         cv_arg;

        PrdrExprOp1(char o) : cv_op(o) {};
        PrdrExprOp1(char o, PrdrExpr * a) : cv_op(o), cv_arg(a) {};

        int output(FILE * i_file)
            {
                fwrite(&cv_op, 1, 1, i_file);
                cv_arg->output(i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << cv_op << " ";
            if (NULL != cv_arg)
                cv_arg->generateDoxygen(o_stream, o_trailing, o_errFile);
        };

        uint16_t getSignature()
        {
            return (NULL == cv_arg ?
                        PrdrSignatureOp::DEFAULT_SIGNATURE
                        : cv_arg->getSignature()
                   );
        }

};

class PrdrExprOp2 : public PrdrExpr
{
    public:
        PrdrExpr *        cv_arg[2];
        char                cv_op;

        PrdrExprOp2(char o) : cv_op(o) {};
        PrdrExprOp2(char o, PrdrExpr * a1, PrdrExpr * a2) : cv_op(o)
            {
                cv_arg[0] = a1; cv_arg[1] = a2;
            };

        int output(FILE * i_file)
            {
                fwrite(&cv_op, 1, 1, i_file);
                cv_arg[0]->output(i_file);
                cv_arg[1]->output(i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            if (NULL != cv_arg[0])
                cv_arg[0]->generateDoxygen(o_stream, o_trailing, o_errFile);
            o_stream << " " << cv_op << " ";

            if (NULL != cv_arg[1])
                cv_arg[1]->generateDoxygen(o_stream, o_trailing, o_errFile);
        };

        uint16_t getSignature()
        {
            return PrdrSignatureOp::combineSig(
                    (NULL == cv_arg[0] ?
                        PrdrSignatureOp::DEFAULT_SIGNATURE
                        : cv_arg[0]->getSignature()
                    ),
                    (NULL == cv_arg[1] ?
                        PrdrSignatureOp::DEFAULT_SIGNATURE
                        : cv_arg[1]->getSignature()
                    ));
        };

};

class PrdrExprAttnLink : public PrdrExpr
{
    public:
        static const int MAX_ATTNS = 4;
        PrdrExpr *        cv_arg[MAX_ATTNS];

        PrdrExprAttnLink(std::string * attn1, PrdrExpr * exp1,
                         std::string * attn2, PrdrExpr * exp2,
                         std::string * attn3, PrdrExpr * exp3,
                         std::string * attn4, PrdrExpr * exp4)
        {
            for (int i = 0; i < MAX_ATTNS; i++)
                cv_arg[i] = NULL;

            cv_arg[decodeAttnType(attn1)] = exp1;
            if (NULL != exp2)
                cv_arg[decodeAttnType(attn2)] = exp2;
            if (NULL != exp3)
                cv_arg[decodeAttnType(attn3)] = exp3;
            if (NULL != exp4)
                cv_arg[decodeAttnType(attn4)] = exp4;
        };

        int output(FILE * i_file)
        {
            char cv_op = Prdr::ATTNLINK;
            fwrite(&cv_op, 1, 1, i_file);

            cv_op = 0;
            for (int i = 0; i < MAX_ATTNS; i++)
                if (NULL != cv_arg[i])
                    cv_op++;
            fwrite(&cv_op, 1, 1, i_file);

            for (int i = 0; i < MAX_ATTNS; i++)
                if (NULL != cv_arg[i])
                {
                    cv_op = i;
                    fwrite(&cv_op, 1, 1, i_file);
                    cv_arg[i]->output(i_file);
                }

            return 0;
        }

        uint16_t getSignature()
        {
            uint16_t l_val = PrdrSignatureOp::DEFAULT_SIGNATURE;
            for (int i = 0; i < MAX_ATTNS; i++)
                if (NULL != cv_arg[i])
                    l_val = PrdrSignatureOp::combineSig(l_val,
                                                    cv_arg[i]->getSignature());
                else
                    l_val = PrdrSignatureOp::combineSig(l_val,
                                            PrdrSignatureOp::DEFAULT_SIGNATURE);
            return l_val;
        };

    protected:
        int decodeAttnType(std::string * attn)
        {
            if (NULL == attn)
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
            else if ("UNIT_CS" == *attn) // @jl02 Add UNIT_CS check.
            {
                return 3;                // @jl02
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


class PrdrExprRule : public PrdrExpr
{
    public:
        std::string *         cv_rulename;
        PrdrExpr *         cv_bits;
        std::string *         cv_actionname;

        PrdrExprRule(std::string * r, PrdrExpr * b, std::string * a)
            : cv_rulename(r), cv_bits(b), cv_actionname(a) {};

        int output(FILE * i_file)
            {
                uint16_t l_ref;
                char l_op;

                l_op = Prdr::REF_RULE;
                fwrite(&l_op, 1, 1, i_file);
                l_ref = htons(prdrGetRefId(cv_rulename));
                fwrite(&l_ref, sizeof(l_ref), 1, i_file);

                cv_bits->output(i_file);

                l_op = prdrGetRefType(cv_actionname);
                fwrite(&l_op, 1, 1, i_file);
                l_ref = htons(prdrGetRefId(cv_actionname));
                fwrite(&l_ref, sizeof(l_ref), 1, i_file);

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
                       << ( (PrdrExprRef(cv_rulename).getSignature()
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

                if (typeid(*cv_bits).name() == typeid(PrdrExprOp2).name())
                {
                    if (static_cast<PrdrExprOp2 *>(cv_bits)->cv_op == Prdr::AND)
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

class PrdrExprAct_Try : public PrdrExpr
{
    public:
        PrdrExpr * cv_left, * cv_right;

        PrdrExprAct_Try(PrdrExpr * l, PrdrExpr * r) : cv_left(l),
                                                      cv_right(r) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_TRY;
                fwrite(&l_op, 1, 1, i_file);
                cv_left->output(i_file);
                cv_right->output(i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "try { ";
            if (NULL != cv_left)
                cv_left->generateDoxygen(o_stream, o_trailing, o_errFile);
            o_stream << ", ";
            if (NULL != cv_right)
                cv_right->generateDoxygen(o_stream, o_trailing, o_errFile);
            o_stream << " } ";
        };

};

class PrdrExprAct_Thresh : public PrdrExpr
{
    public:
        PrdrExpr* cv_thresholdTime[2];
        //Maximum threshold value supported is 255
        uint8_t cv_field;
        uint8_t cv_mfg;
        uint32_t cv_3;
        std::string * cv_mfg_file_thr;

        PrdrExprAct_Thresh( uint8_t i_field = 0, PrdrExpr * i_fieldTime = NULL,
                            uint8_t i_mfg   = 0, PrdrExpr * i_mfgTime   = NULL,
                            std::string * i_mfg_file = NULL ) :
            cv_field(i_field), cv_mfg(i_mfg), cv_mfg_file_thr(i_mfg_file)
        {
            cv_thresholdTime[0] = i_fieldTime;
            cv_thresholdTime[1] = i_mfgTime;
        };

        int output(FILE * i_file)
            {
                char l_op;
                l_op = Prdr::ACT_THRES;
                fwrite(&l_op, 1, 1, i_file);

                if (NULL == cv_thresholdTime[0])
                    l_op = 0;
                else if ( (NULL == cv_thresholdTime[1]) &&
                          (NULL == cv_mfg_file_thr))
                {
                    l_op = 1;
                }
                else
                    l_op = 2;

                if (0 != cv_3)
                    l_op |= 0x40;

                if (NULL != cv_mfg_file_thr)
                    l_op |= 0x20;

                fwrite(&l_op, 1, 1, i_file);

                if (NULL != cv_thresholdTime[0])
                {
                    fwrite(&cv_field, sizeof(cv_field), 1, i_file);
                    cv_thresholdTime[0]->output(i_file);
                    if (NULL != cv_thresholdTime[1])
                    {
                        fwrite(&cv_mfg, sizeof(cv_mfg), 1, i_file);
                        cv_thresholdTime[1]->output(i_file);
                    }
                    else if (NULL != cv_mfg_file_thr)
                    {
                        uint32_t l_tmp32 = prdrActionArgMap(*cv_mfg_file_thr);
                        l_tmp32 = htonl(l_tmp32);
                        fwrite(&l_tmp32, sizeof(l_tmp32), 1, i_file);
                    }
                }

                if (0 != cv_3)
                {
                    uint32_t l_tmp32 = htonl(cv_3);
                    fwrite(&l_tmp32, 4, 1, i_file);
                }

                return 0;
            }

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
            {
                o_stream << "threshold(";
                if (NULL != cv_thresholdTime[0])
                {
                    uint32_t units = cv_field;
                    o_stream <<" field";
                    o_stream << "(";
                    o_stream << units;
                    o_stream << ",";
                    cv_thresholdTime[0]->generateDoxygen(o_stream, o_trailing, o_errFile);
                    o_stream << ")";
                    if (NULL != cv_thresholdTime[1])
                    {
                        units = cv_mfg;
                        o_stream << ", mfg";
                        o_stream << "(";
                        o_stream << units;
                        o_stream << ",";
                        cv_thresholdTime[1]->generateDoxygen(o_stream, o_trailing, o_errFile);
                        o_stream << ")";
                    }
                    else if (NULL != cv_mfg_file_thr)
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


class PrdrExprAct_Dump : public PrdrExpr  //@ecdf
{
    public:
        std::string * cv_1;

        PrdrExprAct_Dump(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_DUMP;
                fwrite(&l_op, 1, 1, i_file);

                uint32_t l_dType;

                if (NULL == cv_1)
                    l_dType = prdrActionArgMap("DUMP_CONTENT_HW");
                else
                    l_dType = prdrActionArgMap(*cv_1);
                l_dType = htonl(l_dType);
                fwrite(&l_dType, sizeof(l_dType), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "dump( " << *cv_1 << " ) ";
        };

};

class PrdrExprAct_Gard : public PrdrExpr
{
    public:
        std::string * cv_1;

        PrdrExprAct_Gard(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_GARD;
                fwrite(&l_op, 1, 1, i_file);

                uint32_t l_gType = htonl(prdrActionArgMap(*cv_1));
                fwrite(&l_gType, sizeof(l_gType), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "gard( " << *cv_1 << " ) ";
        };

};

class PrdrExprAct_Analyse : public PrdrExpr
{
    public:
        std::string * cv_1;
        uint32_t cv_2;

        PrdrExprAct_Analyse( std::string * i_1, uint32_t i_2 = 0xffffffff ) :
            cv_1(i_1), cv_2(i_2)
        {}

        int output(FILE * i_file)
        {
            char l_op = Prdr::ACT_ANALY;
            fwrite(&l_op, 1, 1, i_file);

            uint32_t l_chipType = htonl(prdrActionArgMap(*cv_1));
            fwrite(&l_chipType, sizeof(l_chipType), 1, i_file);

            uint32_t l_chipIndx = htonl(cv_2);
            fwrite(&l_chipIndx, sizeof(l_chipIndx), 1, i_file);

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

class PrdrExprAct_Callout : public PrdrExpr
{
    public:
        std::string * cv_1, * cv_2;
        uint32_t cv_3;

        PrdrExpr * cv_alt;

        enum Callout_type
        {
            CALLOUT_SELF = 's',
            CALLOUT_CHIP = 'c',
            CALLOUT_PROC = 'p',
        };

        Callout_type cv_type;

        PrdrExprAct_Callout(std::string * i_1,
                            std::string * i_2 = NULL,
                            Callout_type  i_t = CALLOUT_SELF,
                            uint32_t      i_3 = 0xffffffff,
                            PrdrExpr *    i_alt = NULL) :
            cv_1(i_1), cv_2(i_2), cv_3(i_3), cv_alt(i_alt), cv_type(i_t)
        {}

        int output(FILE * i_file)
        {
            char l_op;

            l_op = Prdr::ACT_CALL;
            fwrite(&l_op, 1, 1, i_file);

            l_op = cv_type;
            fwrite(&l_op, 1, 1, i_file);

            uint32_t l_priority = htonl(prdrActionArgMap(*cv_1));
            fwrite(&l_priority, sizeof(l_priority), 1, i_file);

            if (CALLOUT_SELF != cv_type)
            {
                uint32_t l_arg = htonl(prdrActionArgMap(*cv_2));
                fwrite(&l_arg, sizeof(l_arg), 1, i_file);

                l_arg = htonl(cv_3);
                fwrite(&l_arg, sizeof(l_arg), 1, i_file);
                // Write bool for ALT resolution.
                l_op = (NULL == cv_alt ? 0 : 1);
                fwrite(&l_op, 1, 1, i_file);

                // Write ALT resolution.
                if (NULL != cv_alt)
                    cv_alt->output(i_file);
            }

            return 0;
        };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "callout ( ";
            if (CALLOUT_SELF == cv_type)
            {
                o_stream << "SELF, " << *cv_1 << " )";
            }
            else if (CALLOUT_PROC == cv_type)
            {
                o_stream << "procedure ( " << *cv_2 << " ), " << *cv_1 << " ) ";
            }
            else
            {
                o_stream << "connected ( " << *cv_2 ;
                if ( 0xffffffff != cv_3 )
                    o_stream << ", " << cv_3;
                o_stream << " ), " << *cv_1 << " ) ";
            }
        }

};

class PrdrExprAct_Funccall : public PrdrExpr
{
    public:
        std::string * cv_1, * cv_2;

        PrdrExprAct_Funccall(std::string * i_1, std::string * i_2 = NULL) :
                cv_1(i_1), cv_2(i_2) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_FUNC;
                fwrite(&l_op, 1, 1, i_file);

                if ('"' == (*cv_1)[0])
                    (*cv_1) = cv_1->substr(1, cv_1->size() - 2);
                fwrite(cv_1->c_str(), cv_1->size() + 1, 1, i_file);

                uint32_t l_chip;
                if (NULL != cv_2)
                    l_chip = htonl(prdrActionArgMap(*cv_2));
                else
                    l_chip = 0;
                fwrite(&l_chip, sizeof(l_chip), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "funccall( " << *cv_1;
            if (NULL != cv_2)
                o_stream << ", " << *cv_2;
            o_stream << " ) ";
        };


};

class PrdrExprAct_Flag : public PrdrExpr
{
    public:
        std::string * cv_1;

        PrdrExprAct_Flag(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_FLAG;
                fwrite(&l_op, 1, 1, i_file);

                uint32_t l_flag = htonl(prdrActionArgMap(*cv_1));
                fwrite(&l_flag, sizeof(l_flag), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "flag( " << *cv_1 << " ) ";
        };


};

class PrdrExprAct_Capture : public PrdrExpr
{
    public:
        std::string * cv_1;

        PrdrExprAct_Capture(std::string * i_1) : cv_1(i_1) {};

        int output(FILE * i_file)
            {
                char l_op;

                l_op = Prdr::ACT_CAPT;
                fwrite(&l_op, 1, 1, i_file);

                uint32_t l_group = htonl(prdrCaptureGroupMap(*cv_1));
                fwrite(&l_group, sizeof(l_group), 1, i_file);

                return 0;
            };

        void generateDoxygen(std::ostream & o_stream,
                             std::string & o_trailing,
                             std::ostream & o_errFile = std::cerr)
        {
            o_stream << "capture( " << *cv_1 << " ) ";
        };


};


extern std::map<std::string, PrdrExpr *> g_rules;

typedef std::pair<std::string, std::string> PrdrRefPair;
extern std::list<PrdrRefPair> g_references;

#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F494911  f310 03/04/05 iawillia Initial File Creation
//         D515833  f300 09/19/05 iawillia Add capture support.
//         F526728  f300 10/25/05 iawillia Add >> and << registers.
//         F534311  f300 01/10/06 iawillia Add bit string expression.
//         F544848  f300 04/03/06 iawillia Add multi-bit support.
//         F549888  f300 05/01/06 iawillia Add Proc. CS attention.
//  ecdf F550548  f300 05/04/06 iawillia eClipz DUMP flags support.
//           D555348  f310 06/05/06 iawillia Update HTML generation.
//  jl02   F605874  f330 07/31/07 lukas    Add functions to PRD framework/Galaxy
//                                                   2 code for unit CS.
// @jl04   F630836  f330 09/17/07 lukas    Add error log Cap. type.
// End Change Log *****************************************************

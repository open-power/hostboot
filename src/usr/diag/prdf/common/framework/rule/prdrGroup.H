/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrGroup.H $         */
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

#ifndef __PRDRGROUP_H
#define __PRDRGROUP_H

#include <string>
#include <list>
#include <netinet/in.h>

#include <prdrExpr.H>
#include <prdrCommon.H>

class PrdrChip;
extern PrdrChip * g_currentChip;
extern uint32_t g_nextAndBit;
class PrdrGroup_Filter;

class PrdrGroup
{
    public:
        std::list<PrdrExpr *> cv_rules;
        PrdrExpr * cv_priorityList;

        char cv_op;
        uint8_t cv_flags;
        std::string cv_doxcomment;

        PrdrGroup() :
            cv_priorityList(NULL),
            cv_op(Prdr::GROUP),
            cv_flags(0),
            cv_doxcomment() {};
        PrdrGroup(char o) :
            cv_priorityList(NULL),
            cv_op(o),
            cv_flags(0),
            cv_doxcomment() {};

        static void merge(PrdrGroup * i_l, PrdrGroup * i_r)
        {
            // Copy over rules.
            i_l->cv_rules.insert(i_l->cv_rules.end(),
                                 i_r->cv_rules.begin(),
                                 i_r->cv_rules.end());

            // Merge flags.
            i_l->cv_flags |= i_r->cv_flags;

            // Set Priority list.
            if (NULL != i_l->cv_priorityList)
                i_r->cv_priorityList = i_l->cv_priorityList;

        };

        void setComment(std::string & i_comment)
            {
                if (Prdr::GROUP == cv_op)
                {
                    PrdrExpr * l_front = *(cv_rules.begin());
                    if (NULL == l_front)
                    {
                        // ICE.
                    }
                    else
                    {
                        l_front->setComment(i_comment);
                    }
                }
                else if (Prdr::ACTION == cv_op)
                {
                    cv_doxcomment = i_comment;
                }
            };


        void generateDoxygen(std::ostream & o_stream,
                             std::string i_name,
                             std::ostream & o_errFile = std::cerr)
            {
                std::string l_trailingInfo = "";

                if (Prdr::GROUP == cv_op)
                {
                    o_stream << "<H3><A NAME='" + i_name + "'>"
                             << i_name << "</A></H3>";

                    o_stream << "<TABLE><THEAD>"
                             << "<TR><TH colspan=\"4\" align=\"left\">"
                             << "Register Group: " << i_name
                             << "</TR>" << std::endl;

                    o_stream << "<TR><TH width=\"7%\">Bit(s)<TH width=\"25%\">"
                             << "Name<TH width=\"50%\">Short Description"
                             << "<TH width=\"18%\">Actions</TR>"
                             << "</THEAD><TBODY>"
                             << std::endl;

                    g_nextAndBit = 64;
                }
                else if (Prdr::ACTION == cv_op)
                {
                    o_stream << "<TR>";
                    o_stream << "<TD><P><A NAME='" << i_name << "'>"
                             << i_name << "</A></P></TD> ";
                    o_stream << "<TD>";
                    if (std::string() != cv_doxcomment)
                    {
                        o_stream << cv_doxcomment;
                    }
                    o_stream << "</TD>";

                    o_stream << "<TD>" << std::endl;
                }

                for (std::list<PrdrExpr *>::iterator i = cv_rules.begin();
                     i != cv_rules.end();
                     i++)
                {
                    if (Prdr::GROUP == cv_op)
                    {
                        o_stream << "<TR>";
                    }
                    else if (Prdr::ACTION == cv_op)
                    {
                        if (i != cv_rules.begin())
                            o_stream << "<BR>" << std::endl;

                    }
                    (*i)->generateDoxygen(o_stream, l_trailingInfo, o_errFile);
                    if (Prdr::GROUP == cv_op)
                    {
                        o_stream << "</TR>" << std::endl;
                    }

                }
                if (Prdr::GROUP == cv_op)
                {
                    o_stream << "</TBODY></TABLE><BR>" << std::endl;
                    o_stream << l_trailingInfo << std::endl;
                    o_stream << "</A>";
                }
                else if (Prdr::ACTION == cv_op)
                {
                    o_stream << "</TD></TR>" << std::endl;
                }
            };

        int output(FILE * i_file)
            {
                fwrite(&cv_op, 1, 1, i_file);

                uint16_t l_ruleCount = htons(cv_rules.size());
                fwrite(&l_ruleCount, sizeof(l_ruleCount), 1, i_file);

                // Write flags for GROUP op.
                if (Prdr::GROUP == cv_op)
                {
                    fwrite(&cv_flags, 1, 1, i_file);
                    if (Prdr::PRDR_GROUP_FILTER_PRIORITY & cv_flags)
                    {
                        cv_priorityList->output(i_file);
                    }
                }


                for (std::list<PrdrExpr *>::iterator i = cv_rules.begin();
                     i != cv_rules.end();
                     i++)
                {
                    (*i)->output(i_file);
                }

                return 0;
            };


};

extern std::map<std::string, PrdrGroup *> g_groups;
extern std::map<std::string, PrdrGroup *> g_actionclasses;
extern std::map<std::string, std::string> g_attentionStartGroup;

class PrdrGroup_Filter
{
    public:
        virtual ~PrdrGroup_Filter() { }  // zs01
        virtual void AddFilter(PrdrGroup *) = 0;
};

class PrdrGroup_Filter_SingleBit : public PrdrGroup_Filter
{
    public:
        void AddFilter(PrdrGroup * i_group)
            {
                i_group->cv_flags |= Prdr::PRDR_GROUP_FILTER_SINGLE_BIT;
            };
};

class PrdrGroup_Filter_Priority : public PrdrGroup_Filter
{
    public:
        PrdrGroup_Filter_Priority(PrdrExpr * i_list) : iv_list(i_list) {};

        void AddFilter(PrdrGroup * i_group)
            {
                i_group->cv_flags |= Prdr::PRDR_GROUP_FILTER_PRIORITY;
                i_group->cv_priorityList = iv_list;
            };

    private:
        PrdrExpr * iv_list;
};


#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F494911  f310 03/04/05 iawillia Initial File Creation
//         F544848  f300 04/03/06 iawillia Add multi-bit support.
//           D555348  f310 06/05/06 iawillia Update HTML generation.
//         F557408  f310 06/16/06 iawillia Add single-bit filter support.
//  zs01 D620028  f330 07/25/07 zshelle  Support for mcp5 compiler
// End Change Log *****************************************************

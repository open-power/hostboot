/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrGroup.H $                   */
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

#ifndef __PRDRGROUP_H
#define __PRDRGROUP_H

#include <string>
#include <list>
#include <netinet/in.h>

#include <prdrExpr.H>
#include <prdrCommon.H>

namespace PRDR_COMPILER
{

class Chip;
extern Chip * g_currentChip;
extern uint32_t g_nextAndBit;
class Group_Filter;

class Group
{
    public:
        std::list<Expr *> cv_rules;
        Expr * cv_priorityList;
        Expr * cv_csRootCauseList;

        char cv_op;
        uint8_t cv_flags;
        std::string cv_doxcomment;

        Group() :
            cv_priorityList(nullptr),
            cv_csRootCauseList(nullptr),
            cv_op(Prdr::GROUP),
            cv_flags(0),
            cv_doxcomment() {};
        Group(char o) :
            cv_priorityList(nullptr),
            cv_csRootCauseList(nullptr),
            cv_op(o),
            cv_flags(0),
            cv_doxcomment() {};

        static void merge(Group * i_l, Group * i_r)
        {
            // Copy over rules.
            i_l->cv_rules.insert(i_l->cv_rules.end(),
                                 i_r->cv_rules.begin(),
                                 i_r->cv_rules.end());

            // Merge flags.
            i_l->cv_flags |= i_r->cv_flags;

            // Set Priority list.
            if (nullptr != i_l->cv_priorityList)
                i_r->cv_priorityList = i_l->cv_priorityList;

            // Set CS root cause bit list
            if ( nullptr != i_l->cv_csRootCauseList )
            {
                i_r->cv_csRootCauseList = i_l->cv_csRootCauseList;
            }

        };

        void setComment(std::string & i_comment)
            {
                if (Prdr::GROUP == cv_op)
                {
                    Expr * l_front = *(cv_rules.begin());
                    if (nullptr == l_front)
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

                for (std::list<Expr *>::iterator i = cv_rules.begin();
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
                PRDR_FWRITE(&cv_op, 1, 1, i_file);

                uint16_t l_ruleCount = htons(cv_rules.size());
                PRDR_FWRITE(&l_ruleCount, sizeof(l_ruleCount), 1, i_file);

                // Write flags for GROUP op.
                if (Prdr::GROUP == cv_op)
                {
                    PRDR_FWRITE(&cv_flags, 1, 1, i_file);
                    if ( Prdr::PRDR_GROUP_FILTER_PRIORITY & cv_flags )
                    {
                        cv_priorityList->output( i_file );
                    }
                    if ( Prdr::PRDR_GROUP_FILTER_CS_ROOT_CAUSE & cv_flags)
                    {
                        if ( nullptr != cv_csRootCauseList )
                        {
                            cv_csRootCauseList->output( i_file );
                        }
                    }
                }

                for (std::list<Expr *>::iterator i = cv_rules.begin();
                     i != cv_rules.end();
                     i++)
                {
                    (*i)->output( i_file );
                }

                return 0;
            };


};

extern std::map<std::string, Group *> g_groups;
extern std::map<std::string, Group *> g_actionclasses;
extern std::map<std::string, std::string> g_attentionStartGroup;

class Group_Filter
{
    public:
        virtual ~Group_Filter() { }  // zs01
        virtual void AddFilter(Group *) = 0;
};

class Group_Filter_SingleBit : public Group_Filter
{
    public:
        void AddFilter(Group * i_group)
            {
                i_group->cv_flags |= Prdr::PRDR_GROUP_FILTER_SINGLE_BIT;
            };
};

class Group_Filter_Priority : public Group_Filter
{
    public:
        Group_Filter_Priority(Expr * i_list) : iv_list(i_list) {};

        void AddFilter(Group * i_group)
            {
                i_group->cv_flags |= Prdr::PRDR_GROUP_FILTER_PRIORITY;
                i_group->cv_priorityList = iv_list;
            };

    private:
        Expr * iv_list;
};

class Group_Filter_CS_Root_Cause : public Group_Filter
{
    public:
    Group_Filter_CS_Root_Cause() : iv_csCauseList(nullptr) {};

    Group_Filter_CS_Root_Cause( Expr * i_list ) : iv_csCauseList( i_list ) {};

    void AddFilter( Group * i_group )
    {
        i_group->cv_flags |= Prdr::PRDR_GROUP_FILTER_CS_ROOT_CAUSE;
        i_group->cv_csRootCauseList = iv_csCauseList;
    };

    private:
    Expr * iv_csCauseList;
};

class Group_Filter_CS_Root_Cause_Null : public Group_Filter
{
    public:
        void AddFilter(Group * i_group)
            {
                i_group->cv_flags |= Prdr::PRDR_GROUP_FILTER_CS_ROOT_CAUSE_NULL;
            };
};

} // end namespace PRDR_COMPILER

#endif


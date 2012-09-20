/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdrChip.H $                 */
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

#ifndef __PRDRCHIP_H
#define __PRDRCHIP_H

#include <string>
#include <stdint.h>

#include <netinet/in.h>

#include <prdrRegister.H>

class PrdrExtraSignature
{
    public:
        uint32_t iv_sig;
        std::string * iv_sname;
        std::string * iv_desc;

        PrdrExtraSignature(uint32_t i_sig,
                           std::string * i_sname,
                           std::string * i_desc) : iv_sig(i_sig),
                                                   iv_sname(i_sname),
                                                   iv_desc(i_desc) {};

        PrdrExtraSignature & operator=(const PrdrExtraSignature & l_rhs)
            {
                this->iv_sig = l_rhs.iv_sig;
                this->iv_sname = l_rhs.iv_sname;
                this->iv_desc = l_rhs.iv_desc;

                return *this;
            };
};

class PrdrChip
{
    public:
        std::string * cv_sname;
        std::string * cv_name;
        uint32_t cv_chipid;
        uint32_t cv_targetType;
        uint32_t cv_signatureOffset;
        uint32_t cv_dumptype;  //@ecdf
        PrdrRegisterList cv_reglist;
        std::list<PrdrExtraSignature> cv_sigExtras;

        uint16_t cv_scomlen; // Default Scom Address.

        std::string cv_name_default;

        PrdrChip() : cv_sname(NULL),
                     cv_name(&cv_name_default),
                     cv_chipid(0),
                     cv_targetType(0),
                     cv_signatureOffset(0),
                     cv_dumptype(0),  //@ecdf
                     cv_reglist(),
                     cv_sigExtras(),
                     cv_scomlen(0) {};

        static void merge(PrdrChip * i_l, PrdrChip * i_r)
        {
            if (NULL != i_r->cv_sname)
                i_l->cv_sname = i_r->cv_sname;
            if (&i_r->cv_name_default != i_r->cv_name)
                i_l->cv_name = i_r->cv_name;
            if (0 != i_r->cv_chipid)
                i_l->cv_chipid = i_r->cv_chipid;
            if (0 != i_r->cv_scomlen)
                i_l->cv_scomlen = i_r->cv_scomlen;
            if (0 != i_r->cv_targetType)
                i_l->cv_targetType = i_r->cv_targetType;
            if (0 != i_r->cv_signatureOffset)
                i_l->cv_signatureOffset = i_r->cv_signatureOffset;
            if (0 != i_r->cv_dumptype) //@ecdf
                i_l->cv_dumptype = i_r->cv_dumptype;

            i_l->cv_reglist.insert(i_l->cv_reglist.end(),
                                   i_r->cv_reglist.begin(),
                                   i_r->cv_reglist.end());

            i_l->cv_sigExtras.insert(i_l->cv_sigExtras.end(),
                                     i_r->cv_sigExtras.begin(),
                                     i_r->cv_sigExtras.end());
        };

        void print()
        {
            using namespace std;
            cout << "Chip " << *cv_sname << ":" << endl;
            cout << "\tLong Name: " << *cv_name << endl;
            cout << "\tChip ID:   " << cv_chipid << endl;
            cout << "\tTarget Type: "  << cv_targetType << endl;
            cout << "\tSignature Offset: " << cv_signatureOffset << endl;
            cout << "\tDefault Dumptype: " << cv_dumptype << endl;  //@ecdf
            cout << "\tDefault ScomLen: " << cv_scomlen << endl;
            cout << "\tRegisters: (" << cv_reglist.size() << ")" << endl;
            for (PrdrRegisterList::iterator i = cv_reglist.begin();
                 i != cv_reglist.end();
                 i++)
            {
                (*i)->print();
            }
        };


        int output(FILE * l_file)
        {
            uint32_t l_temp;
            uint16_t l_temp16;

            fwrite("PRDRCHIP", 8, 1, l_file);

            l_temp = htonl(cv_chipid);
            fwrite(&l_temp, sizeof(l_temp), 1, l_file);

            l_temp = htonl(cv_targetType);
            fwrite(&l_temp, sizeof(l_temp), 1, l_file);

            l_temp = htonl(cv_signatureOffset);
            fwrite(&l_temp, sizeof(l_temp), 1, l_file);

            // Write dumptype to file.  //@ecdf
            l_temp = htonl(cv_dumptype);
            fwrite(&l_temp, sizeof(l_temp), 1, l_file);

            l_temp16 = htons(cv_scomlen);
            fwrite(&l_temp16, sizeof(l_temp16), 1, l_file);

            l_temp16 = htons(cv_reglist.size());
            fwrite(&l_temp16, sizeof(l_temp16), 1, l_file);

            for (PrdrRegisterList::iterator i = cv_reglist.begin();
                 i != cv_reglist.end();
                 i++)
            {
                (*i)->output(l_file, cv_signatureOffset);
            }

            return 0;
        }

        void outputRegisterFile(std::ostream & o_file)
        {
            o_file << "( 0x" << std::hex << cv_targetType << ", 0x" << std::hex
                   << cv_signatureOffset << " )" << std::endl;

            for (PrdrRegisterList::iterator i = cv_reglist.begin();
                 i != cv_reglist.end();
                 i++)
            {
                (*i)->outputRegisterFile(o_file, cv_signatureOffset);
            }

        };
};

#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F494911  f310 03/04/05 iawillia Initial File Creation
//  ecdf F550548  f300 05/04/06 iawillia eClipz DUMP flags support.
//           D586213  f310 02/19/07 iawillia Add extra signature support.
// End Change Log *****************************************************

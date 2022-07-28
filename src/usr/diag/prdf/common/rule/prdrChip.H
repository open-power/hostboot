/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrChip.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

#ifndef __PRDRCHIP_H
#define __PRDRCHIP_H

#include <string>
#include <stdint.h>

#include <endian.h>

#include <prdrRegister.H>

namespace PRDR_COMPILER
{

class ExtraSignature
{
    public:
        uint32_t iv_sig;
        std::string * iv_sname;
        std::string * iv_desc;

        ExtraSignature(uint32_t i_sig,
                           std::string * i_sname,
                           std::string * i_desc) : iv_sig(i_sig),
                                                   iv_sname(i_sname),
                                                   iv_desc(i_desc) {};

        ExtraSignature & operator=(const ExtraSignature & l_rhs)
            {
                this->iv_sig = l_rhs.iv_sig;
                this->iv_sname = l_rhs.iv_sname;
                this->iv_desc = l_rhs.iv_desc;

                return *this;
            };
};

class Chip
{
    public:
        std::string * cv_sname;
        std::string * cv_name;
        uint32_t cv_chipid;
        uint32_t cv_targetType;
        uint32_t cv_signatureOffset;
        uint32_t cv_dumptype;  //@ecdf
        RegisterList cv_reglist;
        std::list<ExtraSignature> cv_sigExtras;

        uint16_t cv_scomlen; // Default Scom Address.

        std::string cv_name_default;

        Chip() : cv_sname(nullptr),
                     cv_name(&cv_name_default),
                     cv_chipid(0),
                     cv_targetType(0),
                     cv_signatureOffset(0),
                     cv_dumptype(0),  //@ecdf
                     cv_reglist(),
                     cv_sigExtras(),
                     cv_scomlen(0) {};

        static void merge(Chip * i_l, Chip * i_r)
        {
            if (nullptr != i_r->cv_sname)
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
            for (RegisterList::iterator i = cv_reglist.begin();
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

            PRDR_FWRITE("PRDRCHIP", 8, 1, l_file);

            l_temp = htobe32(cv_chipid);
            PRDR_FWRITE(&l_temp, sizeof(l_temp), 1, l_file);

            l_temp = htobe32(cv_targetType);
            PRDR_FWRITE(&l_temp, sizeof(l_temp), 1, l_file);

            l_temp = htobe32(cv_signatureOffset);
            PRDR_FWRITE(&l_temp, sizeof(l_temp), 1, l_file);

            // Write dumptype to file.  //@ecdf
            l_temp = htobe32(cv_dumptype);
            PRDR_FWRITE(&l_temp, sizeof(l_temp), 1, l_file);

            l_temp16 = htobe16(cv_scomlen);
            PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);

            l_temp16 = htobe16(cv_reglist.size());
            PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);

            for (RegisterList::iterator i = cv_reglist.begin();
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

            for (RegisterList::iterator i = cv_reglist.begin();
                 i != cv_reglist.end();
                 i++)
            {
                (*i)->outputRegisterFile(o_file, cv_signatureOffset);
            }

        };
};

} // end namespace PRDR_COMPILER

#endif


/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDB.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#include "prdfsimScrDB.H"
#include <iipMopRegisterAccess.h>
#include <prdfTrace.H>
#include <prdfPlatServices.H>
#include "prdfsimServices.H"

namespace PRDF
{

    using namespace TARGETING;
    using namespace PlatServices;

    /**
     *  @brief Returns a reference to the ScrDB singleton
     *
     *  @return Reference to the ScrDB
     */
    /*
       ScrDB& GetScrDB()
       {
       return PRDF_GET_SINGLETON(theScrDB);
       }
       */

    ScrDB::ScrDB()
    {
        PRDF_TRAC( "ScrDB::ScrDB()" );
    }

    void ScrDB::processCmd(TARGETING::TargetHandle_t i_ptargetHandle,
                           BIT_STRING_CLASS & bs,
                           uint64_t registerId,
                           SimOp i_op)
    {
        // set target state to functional if not already functional
        if(false == isFunctional(i_ptargetHandle))
        {
            getSimServices().setHwasState(i_ptargetHandle, true);
        }

        switch (i_op)
        {
            case WRITE:
                Write(i_ptargetHandle, bs, registerId);
                break;
            case READ:
                Read(i_ptargetHandle, bs, registerId);
                break;
            case EXPECT:
                Expect(i_ptargetHandle, bs, registerId);
                break;
            default:
                PRDF_ERR( "ScrDB::processCmd() unsupported operation: 0x%X", i_op );
                break;
        }

        return;
    }

    void ScrDB::Read(TARGETING::TargetHandle_t i_ptargetHandle,
                     BIT_STRING_CLASS & bs,
                     uint64_t registerId)
    {
        //PRDF_DENTER( "ScrDB::Read() huid: 0x%X, addr: 0x%016X",
        //            getHuid(i_ptargetHandle), registerId );
        DataList data;
        unsigned int dataWordSize = bs.GetLength()/32;
        dataWordSize += (bs.GetLength() % 32) ? 1 : 0;

        // if the register has a predetermined value than get it
        if(pChipset.find(i_ptargetHandle) != pChipset.end())
        {
            PreScrMap pscrmap = pChipset[i_ptargetHandle];
            if(pscrmap.find(registerId) != pscrmap.end())  // we must have a predetermined value
            {
                SimScrDataSet pValues = pscrmap[registerId];
                data = pValues.GetData(); // get next set of values
                // pValues has changed - copy it back
                pscrmap[registerId] = pValues;
                pChipset[i_ptargetHandle] = pscrmap;
            }
        }
        if(data.size() == 0) // use the last value written to this reg
        {
            // get a copy of the scrMap for this chip - if one does not exist it will be created
            ScrMap scrMap = chipset[i_ptargetHandle];
            // get a copy of the data for this address from the scrMap for this chip
            // if data structure does not exist, it will be created, but will be empty
            data = scrMap[registerId];
            if(data.size() == 0)  // This is the first time this register has been accessed
            {
                while(data.size() < dataWordSize) data.push_back(0); // zero fill
                scrMap[registerId] = data;
                chipset[i_ptargetHandle] = scrMap;     // update the persistent copy of the scrMap
            }
        }

        if(0 != data.size())
        {
            for(unsigned int i = 0; i < data.size(); ++i)
            {
                bs.SetFieldJustify((i*32), 32, data[i]);
            }
            PRDF_TRAC( "ScrDB::Read() huid: %X, addr: %016X, data: %08X %08X",
                           getHuid(i_ptargetHandle), registerId, data[0],
                           2 == data.size() ? data[1] : 0  );
        }
        //PRDF_DEXIT( "ScrDB::Read()" );

    }

    void ScrDB::Write(TARGETING::TargetHandle_t i_ptargetHandle,
                      BIT_STRING_CLASS & bs,
                      uint64_t registerId)
    {
        PRDF_TRAC( "ScrDB::Write() huid: %X, addr: %016X, data: %08X %08X",
                    getHuid(i_ptargetHandle), registerId,
                    bs.GetFieldJustify(0,32), bs.GetFieldJustify(32,32) );

        unsigned int dataWordSize = bs.GetLength()/32;
        //    PRDF_TRAC("dataWordSize1: %d", dataWordSize);
        dataWordSize += (bs.GetLength() % 32) ? 1 : 0;
        //    PRDF_TRAC("dataWordSize2: %d", dataWordSize);
        DataList data;

        // parse all data given
        data.push_back(bs.GetFieldJustify(0,32));
        data.push_back(bs.GetFieldJustify(32,32));
        //    PRDF_TRAC("parse all data given");
        // look for expected data
        DataList expectedData;
        if(eChipset.find(i_ptargetHandle) != eChipset.end())
        {
            PRDF_TRAC("found target");
            PreScrMap escrmap = eChipset[i_ptargetHandle];
            if(escrmap.find(registerId) != escrmap.end()) // we have expected data value
            {
                PRDF_TRAC("found scom reg");
                SimScrDataSet eValues = escrmap[registerId];
                expectedData = eValues.GetData(); // get next set of values
                escrmap[registerId] = eValues;
                eChipset[i_ptargetHandle] = escrmap;
            }
        }
        if(expectedData.size() > 0)
        {
            if((expectedData[0] != data[0]) || (expectedData[1] != data[1]))
            {
                PRDF_ERR("Verify SC register: %p", i_ptargetHandle);
                PRDF_ERR(" Address: 0x%016X", registerId);
                PRDF_ERR("SCR write Actual  : %08X %08X", data[0], data[1]);
                PRDF_ERR("SCR write Expected: %08X %08X", expectedData[0], expectedData[1]);
            }
            else
            {
                PRDF_TRAC("Verify SC register: %p", i_ptargetHandle);
                PRDF_TRAC(" Address: 0x%016X", registerId);
                PRDF_TRAC("SCR write Actual: %08X %08X", data[0], data[1]);
            }
        }

        //    PRDF_TRAC("get a copy");
        // get a copy of the scrMap for this chip - if one does not exist it will be created
        ScrMap scrMap = chipset[i_ptargetHandle];

        //    PRDF_TRAC("update register value");
        // update register value
        scrMap[registerId] = data; // copy the supplied value to the register

        //    PRDF_TRAC("update the master");
        chipset[i_ptargetHandle] = scrMap; // scrMap is only a copy so must update the master

        //PRDF_EXIT( "ScrDB::Write()" );

    }


    void ScrDB::Expect(TARGETING::TargetHandle_t i_ptargetHandle,
                       BIT_STRING_CLASS & bs,
                       uint64_t registerId)
    {
        PRDF_TRAC( "ScrDB::Expect() huid: %X, addr: %016X, data: %08X %08X",
                    getHuid(i_ptargetHandle), registerId,
                    bs.GetFieldJustify(0,32), bs.GetFieldJustify(32,32) );

        SimScrDataSet eValues;
        DataList data;
        // parse all data given
        data.push_back(bs.GetFieldJustify(0,32));
        data.push_back(bs.GetFieldJustify(32,32));

        eValues.AddData(data);

        //    PRDF_TRAC("get a copy");
        PreScrMap scrMap = eChipset[i_ptargetHandle]; // create/get copy of map

        //    PRDF_TRAC("update register value");
        scrMap[registerId] = eValues; // Add entree

        //    PRDF_TRAC("update the master");
        eChipset[i_ptargetHandle] = scrMap; // copy it back

        //PRDF_EXIT( "ScrDB::Expect()" );

    }

} // End namespace PRDF

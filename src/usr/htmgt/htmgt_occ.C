/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "htmgt_occcmd.H"
#include "htmgt_config.H"
#include "htmgt_occ.H"

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>


using namespace HTMGT;


namespace HTMGT
{

    Occ::Occ(const uint8_t   i_instance,
             const bool      i_masterCapable,
             uint8_t       * i_homer,
             TARGETING::TargetHandle_t i_target,
             const occRole   i_role)
        :instance(i_instance),
        masterCapable(i_masterCapable),
        role(i_role),
        state(OCC_STATE_UNKNOWN),
        commEstablished(false),
        needsReset(false),
        failed(false),
        seqNumber(0),
        homer(i_homer),
        target(i_target),
        lastPollValid(false),
        version(0x01)
    {
        // Probably not needed...
        huid = i_target->getAttr<TARGETING::ATTR_HUID>();
    }

    Occ::~Occ()
    {
    }


    OccManager::OccManager()
        :iv_occMaster(NULL),
        iv_state(OCC_STATE_UNKNOWN)
    {
    }


    OccManager::~OccManager()
    {
    }


    // Remove all OCC objects
    void OccManager::_removeAllOccs()
    {
        iv_occMaster = NULL;
        if (iv_occArray.size() > 0)
        {
            for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
                 pOcc < iv_occArray.end();
                 pOcc++)
            {
                TMGT_INF("removeAllOccs: Removing OCC%d",
                         (*pOcc)->getInstance());
                delete (*pOcc);
            }
            iv_occArray.clear();
        }
    }


    // Query the functional OCCs and build OCC objects
    uint32_t OccManager::_buildOccs()
    {
        TMGT_INF("buildOccs called");

        // Remove existing OCC objects
        _removeAllOccs();

        // Get all functional processors
        TARGETING::TargetHandleList pProcs;
        TARGETING::getChipResources(pProcs,
                                    TARGETING::TYPE_PROC,
                                    TARGETING::UTIL_FILTER_FUNCTIONAL);
        if (pProcs.size() > 0)
        {
            // for each functional processor
            for(TARGETING::TargetHandleList::iterator proc = pProcs.begin();
                proc != pProcs.end();
                ++proc)
            {
                // Instance number for this Processor/OCC
                const uint8_t instance =
                    (*proc)->getAttr<TARGETING::ATTR_POSITION>();
                TMGT_INF("buildOccs: PROC%d is functional", instance);
                // Get HOMER virtual address
                uint8_t * homer = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>());
                TMGT_INF("buildOccs: homer = 0x%08X (from proc 0)", homer);
#ifdef SIMICS_TESTING
                // Starting of OCCs is not supported in SIMICS, so fake out
                // HOMER memory area for testing
                if (NULL == homer)
                {
                    extern uint8_t * G_simicsHomerBuffer;

                    if (NULL == G_simicsHomerBuffer)
                    {
                        // Allocate a fake HOMER area
                        G_simicsHomerBuffer =
                            new uint8_t [HTMGT_OCC_CMD_ADDR+0x2000];
                    }
                    homer = G_simicsHomerBuffer;
                    TMGT_ERR("buildOccs: Using hardcoded HOMER of 0x%08lX",
                             homer);
                }
#endif

                // Get functional OCC (one per proc)
                TARGETING::TargetHandleList pOccs;
                getChildChiplets(pOccs, *proc, TARGETING::TYPE_OCC);
                if (pOccs.size() > 0)
                {
                    const unsigned long huid =
                        pOccs[0]->getAttr<TARGETING::ATTR_HUID>();
                    const bool masterCapable =
                        pOccs[0]->getAttr<TARGETING::ATTR_OCC_MASTER_CAPABLE>();

                    TMGT_INF("Found OCC %d - HUID: 0x%0lX, masterCapable: %c,"
                             " homer: 0x%0lX",
                             instance, huid, masterCapable?'Y':'N', homer);
                    _addOcc(instance, masterCapable, homer, pOccs[0]);
                }
                else
                {
                    // OCC must not be functional
                    TMGT_ERR("OCC%d not functional", instance);
                }
            }
        }
        else
        {
            TMGT_ERR("No functional processors found");
        }

        TMGT_INF("buildOccs: OCC Targets found = %d", _getNumOccs());

        return _getNumOccs();

    } // end OccManager::_buildOccs()



    /* Add a functional OCC to be monitored */
    void OccManager::_addOcc(const uint8_t   i_instance,
                             const bool      i_masterCapable,
                             uint8_t       * i_homer,
                             TARGETING::TargetHandle_t i_target)
    {
        TMGT_INF("addOcc(%d, masterCapable=%c)",
                 i_instance, i_masterCapable?'y':'n');

        occRole role = OCC_ROLE_SLAVE;
        if (true == i_masterCapable)
        {
            if (NULL == iv_occMaster)
            {
                // No master assigned yet, use this OCC
                TMGT_INF("addOcc: OCC%d will be the master", i_instance);
                role = OCC_ROLE_MASTER;
            }
            else
            {
                role = OCC_ROLE_BACKUP_MASTER;
            }
        }

        Occ * l_occ = new Occ(i_instance,
                              i_masterCapable,
                              i_homer,
                              i_target,
                              role);

        // Add OCC to the array
        iv_occArray.push_back(l_occ);

        if (OCC_ROLE_MASTER == role)
        {
            iv_occMaster = l_occ;
        }

    } // end OccManager::_addOcc()



    uint8_t  OccManager::getNumOccs()
    {
        return Singleton<OccManager>::instance()._getNumOccs();
    }


    std::vector<Occ*> OccManager::getOccArray()
    {
        return Singleton<OccManager>::instance()._getOccArray();
    }


    uint32_t OccManager::buildOccs()
    {
        return Singleton<OccManager>::instance()._buildOccs();
    }


    Occ * OccManager::getMasterOcc()
    {
        return Singleton<OccManager>::instance()._getMasterOcc();
    }



#if 0
    // TODO: RTC 109066
    void update_occ_data()
    {
        if (occMgr::instance().getNumOccs() > 0)
        {
            // TBD: define as one block of data or in each OCC target?

            uint32_t dataSize = occMgr::instance().getNumOccs() *
                sizeof(occInstance);
            if (dataSize > 256)
            {
                TMGT_ERR("update_occ_data: data exceeds attr size, truncating");
                dataSize = 256;
            }
            // Update OCC_CONTROL_DATA Attribute
            bool success = ->trySetAttr<ATTR_OCC_CONTROL_DATA>(dataSize, G_occ);
            if (false == success)
            {
                TMGT_ERR("update_occ_data: failed to update OCC_CONTROL_DATA");
            }
        }
        else
        {
            TMGT_INF("update_occ_data: No OCC data to update");
        }
    } // end update_occ_data()
#endif


} // end namespace




/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devicefw/associator.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include <algorithm>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>

#include <devicefw/devfwreasoncodes.H>
#include "associator.H"

using namespace ERRORLOG;
using namespace TARGETING;

namespace DeviceFW
{
    trace_desc_t* g_traceBuffer = NULL;
    TRAC_INIT(&g_traceBuffer, "DevFW", KILOBYTE, TRACE::BUFFER_SLOW);

    Associator::Associator() : iv_mutex()
    {
        TRACFCOMP(g_traceBuffer, ENTER_MRK "Associator::Associator");
        mutex_init(&iv_mutex);
        // Allocate first level of map (access types).
        iv_routeMap = iv_associations.allocate(LAST_DRIVER_ACCESS_TYPE);
    }

    Associator::~Associator()
    {

        TRACFCOMP(g_traceBuffer, EXIT_MRK "Associator::~Associator");
    }

    errlHndl_t Associator::registerRoute(int64_t i_opType,
                                         int64_t i_accType,
                                         int64_t i_targetType,
                                         deviceOp_t i_regRoute)
    {
        TRACFCOMP(g_traceBuffer, "Device route registered for (%d, %d, %d)",
                  i_opType, i_accType, i_targetType);

        // The ranges of the parameters should all be verified by the
        // compiler due to the template specializations in driverif.H.
        // No assert-checks will be done here.

        mutex_lock(&iv_mutex);

        // Make sure we aren't doing a double registration
        for( OperationType optype = FIRST_OP_TYPE;
             optype < LAST_OP_TYPE;
             optype = static_cast<OperationType>(optype+1) )
        {
            if( (WILDCARD == i_opType) || (optype == i_opType) )
            {
                deviceOp_t l_devRoute = findDeviceRoute( optype,
                                    static_cast<TARGETING::TYPE>(i_targetType),
                                    i_accType );
                if( l_devRoute != NULL )
                {
                    TRACFCOMP(g_traceBuffer, "Double registration attempted : i_opType=%d, i_accType=%d, i_targetType=0x%X, existing function=%p", i_opType, i_accType, i_targetType, l_devRoute );
                    /*@
                     *  @errortype
                     *  @moduleid         DEVFW_MOD_ASSOCIATOR
                     *  @reasoncode       DEVFW_RC_DOUBLE_REGISTRATION
                     *  @userdata1[0:31]  OpType
                     *  @userdata1[32:63] AccessType
                     *  @userdata2        TargetType
                     *
                     *  @devdesc         A double registration was attempted
                     *                   with the routing framework.
                     */
                    errlHndl_t l_errl =
                      new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                    DEVFW_MOD_ASSOCIATOR,
                                    DEVFW_RC_DOUBLE_REGISTRATION,
                                    TWO_UINT32_TO_UINT64(i_opType, i_accType),
                                    TO_UINT64(i_targetType)
                                    );
                    mutex_unlock(&iv_mutex);
                    return l_errl;
                }
            }
        }

        size_t ops = 0;
        AssociationData targets = AssociationData();

        // Look up second level of map (op-type) or allocate fresh block.
        ops = iv_associations[iv_routeMap][i_accType].offset;
        if (0 == ops)
        {
            // space for LAST_OP_TYPE plus WILDCARD(-1).
            ops = iv_associations.allocate(LAST_OP_TYPE + 1) + 1;
            iv_associations[iv_routeMap][i_accType].offset = ops;
        }

        // Look up third level of map (access-type) or allocate fresh block.
        targets = iv_associations[ops][i_opType];
        if (0 == targets.offset)
        {
            // To conserve space only allocate 1 block for WILDCARD.
            if (WILDCARD == i_targetType)
            {
                targets.offset = iv_associations.allocate(1);
                targets.flag = true; // True flag indicates WILDCARD.
            }
            else
            {
                // Allocate full number of spaces.
                targets.offset = iv_associations.allocate(TYPE_LAST_IN_RANGE+1);
            }
            iv_associations[ops][i_opType] = targets;
        }

        // Index offset to proper target type.  This is now lowest level of map.
        targets.offset += (i_targetType == WILDCARD ? 0 : i_targetType);


        // Search function vector for entry.
        opVector_t::iterator opLocation = std::find(iv_operations.begin(),
                                                    iv_operations.end(),
                                                    i_regRoute);
        // Insert function into vector if not found.
        if (iv_operations.end() == opLocation)
        {
            iv_operations.push_back(i_regRoute);
            opLocation = iv_operations.end() - 1;
        }

        size_t opLoc = std::distance(iv_operations.begin(), opLocation);

        // Set function offset into map.  True flag indicates valid.
        (*iv_associations[targets.offset]) = AssociationData(true, opLoc);

        mutex_unlock(&iv_mutex);

        return NULL;
    }

    errlHndl_t Associator::performOp(OperationType i_opType,
                                     Target* i_target,
                                     void* io_buffer, size_t& io_buflen,
                                     int64_t i_accessType, va_list i_addr)
    {
        errlHndl_t l_errl = NULL;

        if( NULL == i_target )
        {
            TRACFCOMP(g_traceBuffer, "associator.C: A device driver operation was"
                " attempted on a NULL target : i_opType=%d, i_accessType=%d",
                i_opType, i_accessType );
            /*@
             *  @errortype
             *  @moduleid       DEVFW_MOD_ASSOCIATOR
             *  @reasoncode     DEVFW_RC_NULL_TARGET
             *  @userdata1      OpType
             *  @userdata2      AccessType
             *
             *  @devdesc        A device driver operation on a NULL target.
             */
            l_errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                   DEVFW_MOD_ASSOCIATOR,
                                   DEVFW_RC_NULL_TARGET,
                                   i_opType,
                                   i_accessType);
            return l_errl;
        }


        TARGETING::TYPE l_devType =
            (i_target == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) ?
            TYPE_PROC : i_target->getAttr<ATTR_TYPE>();

        TRACDCOMP(g_traceBuffer, "Device op requested for (%d, %d, %d)",
                  i_opType, i_accessType, l_devType);

        mutex_lock(&iv_mutex);

        // Function pointer found for this route request.
        deviceOp_t l_devRoute = findDeviceRoute( i_opType,
                                                 l_devType,
                                                 i_accessType );

        mutex_unlock(&iv_mutex);

        // Call function if one was found, create error otherwise.
        if (NULL == l_devRoute)
        {
            TRACFCOMP(g_traceBuffer, "associator.C: A device driver operation"
                    " was attempted for which no driver has been registered : "
                    "i_opType=%d, i_accessType=%d, l_devType=%d",
                    i_opType, i_accessType, l_devType );

            uint64_t l_userdata2 = l_devType;

            // Dump the SCOM_SWITCHES attribute
            if( (i_accessType == DeviceFW::SCOM)
                || (i_accessType == DeviceFW::XSCOM)
                || (i_accessType == DeviceFW::FSISCOM)
                || (i_accessType == DeviceFW::IBSCOM)
                || (i_accessType == DeviceFW::SBESCOM)
                || (i_accessType == DeviceFW::I2CSCOM) )
            {
                ATTR_SCOM_SWITCHES_type l_switches;
                if( i_target->tryGetAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches) )
                {
                    memcpy( &l_userdata2, &l_switches,
                            std::min(sizeof(l_userdata2), sizeof(l_switches)) );
                }
            }

            /*@
             *  @errortype
             *  @moduleid       DEVFW_MOD_ASSOCIATOR
             *  @reasoncode     DEVFW_RC_NO_ROUTE_FOUND
             *  @userdata1      (OpType << 32) | (AccessType)
             *  @userdata2      (SCOM_SWITCHES << 32) | TargetType
             *
             *  @devdesc        A device driver operation was attempted for
             *                  which no driver has been registered.
             */
            l_errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                   DEVFW_MOD_ASSOCIATOR,
                                   DEVFW_RC_NO_ROUTE_FOUND,
                                   TWO_UINT32_TO_UINT64(i_opType, i_accessType),
                                   l_userdata2,
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        }
        else //This section is where the intended function is called
        {
            l_errl = (*l_devRoute)(i_opType, i_target,
                                   io_buffer, io_buflen,
                                   i_accessType, i_addr);
        }


        return l_errl;
    }


    deviceOp_t Associator::findDeviceRoute( OperationType i_opType,
                                            TARGETING::TYPE i_devType,
                                            int64_t i_accessType )
    {
        // The ranges of the parameters should all be verified by the
        // compiler due to the template specializations in driverif.H.
        // e.g. i_accessType can never be negative
        // No assert-checks will be done here.

        // Function pointer found for this route request.
        deviceOp_t l_devRoute = NULL;

        // Pointer to root of the map.
        const AssociationData* routeMap = iv_associations[iv_routeMap];

        do
        {
            // Follow first level (access type), verify.
            if (0 == routeMap[i_accessType].offset)
            {
                TRACDCOMP(g_traceBuffer, "findDeviceRoute did not verify first "
                          "level: i_accessType=%d", i_accessType );
                break;
            }

            const AssociationData* ops =
              iv_associations[routeMap[i_accessType].offset];

            // Check op type = WILDCARD registrations.
            if (0 != ops[WILDCARD].offset)
            {
                // Check access type = WILDCARD registrations.
                if (ops[WILDCARD].flag)
                {
                    l_devRoute =
                      iv_operations[
                            iv_associations[ops[WILDCARD].offset]->offset];
                    break;
                }

                // Check access type = i_target->type registrations.
                const AssociationData* targets =
                  iv_associations[ops[WILDCARD].offset];
                if (targets[i_devType].flag)
                {
                    l_devRoute =
                      iv_operations[
                                    targets[i_devType].offset];
                    break;
                }

                TRACDCOMP(g_traceBuffer, "findDeviceRoute did not find "
                          "wildcard registration match" );
            }

            // Check op type = i_opType registrations.
            if (0 != ops[i_opType].offset)
            {
                // Check access type = i_opType registrations.
                if(ops[i_opType].flag)
                {
                    l_devRoute =
                      iv_operations[
                            iv_associations[ops[i_opType].offset]->offset];
                    break;
                }

                // Check access type = i_target->type registrations.
                const AssociationData* targets =
                  iv_associations[ops[i_opType].offset];
                if (targets[i_devType].flag)
                {
                    l_devRoute =
                      iv_operations[
                                    targets[i_devType].offset];
                    break;
                }

                TRACDCOMP(g_traceBuffer, "findDeviceRoute did not find "
                          "i_opType=%d registration match", i_opType );
            }
            else
            {
                TRACDCOMP(g_traceBuffer, "findDeviceRoute, no op type %d "
                          "registrations, iv_routeMap=%d, routeMap=%p, "
                          "i_accessType=%d, offset=%d, ops=%p, "
                          "&ops[i_opType]=%p",
                          i_opType, iv_routeMap, routeMap, i_accessType,
                          routeMap[i_accessType].offset, ops, &ops[i_opType] );
            }
        } while(0);

        return l_devRoute;
    }
}



#include <algorithm>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>

#include <devicefw/devfwreasoncodes.H>
#include "associator.H"

using namespace ERRORLOG;

namespace DeviceFW
{
    trace_desc_t* g_traceBuffer = NULL;
    TRAC_INIT(&g_traceBuffer, "DevFW", 4096);

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

    void Associator::registerRoute(int64_t i_opType,
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
                targets.offset = iv_associations.allocate(LAST_TARGET_TYPE);
            }
            iv_associations[ops][i_opType] = targets;
        }
            // Ensure the right block size was allocated previously for this
            // target-type (wildcard vs non-wildcard).
        if(((targets.flag) && (i_targetType != WILDCARD)) ||
           ((!targets.flag) && (i_targetType == WILDCARD)))
        {
            /*@ 
             *  @errortype
             *  @moduleid       DEVFW_MOD_ASSOCIATOR
             *  @reasoncode     DEVFW_RC_INVALID_REGISTRATION
             *  @userdata1      (OpType << 32) | (AccessType)
             *  @userdata2      TargetType
             *
             *  @devdesc        An invalid registration type was given to 
             *                  register a device with the routing framework.
             */
            errlHndl_t l_errl = 
                new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              DEVFW_MOD_ASSOCIATOR,
                              DEVFW_RC_INVALID_REGISTRATION,
                              TWO_UINT32_TO_UINT64(i_opType, i_accType),
                              TO_UINT64(i_targetType)
                             );
            errlCommit(l_errl);
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

        // TODO: Implement std::distance algorithm and change to:
        //      std::distance(iv_operations.begin(), opLocation);
        size_t opLoc = opLocation - iv_operations.begin();

        // Set function offset into map.  True flag indicates valid.
        (*iv_associations[targets.offset]) = AssociationData(true, opLoc);

        mutex_unlock(&iv_mutex);
    }

    errlHndl_t Associator::performOp(OperationType i_opType,
                                     TargetHandle_t i_target,
                                     void* io_buffer, size_t& io_buflen,
                                     int64_t i_accessType, va_list i_addr) 
    {
        TRACDCOMP(g_traceBuffer, "Device op requested for (%d, %d, %d)",
                  i_opType, i_accessType, /*TODO: i_target->type*/PROCESSOR);

        // The ranges of the parameters should all be verified by the
        // compiler due to the template specializations in driverif.H.  
        // No assert-checks will be done here.
        
        errlHndl_t l_errl = NULL;
        
        mutex_lock(&iv_mutex);

            // Function pointer found for this route request.
        deviceOp_t l_devRoute = NULL;
            // Pointer to root of the map.
        const AssociationData* routeMap = iv_associations[iv_routeMap];

        do
        {
            // Follow first level (access type), verify.
            if (0 == routeMap[i_accessType].offset)
            {
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
                if (targets[/*TODO: i_target->type*/PROCESSOR].flag)
                {
                    l_devRoute =
                        iv_operations[
                            targets[/*TODO: i_target->type*/PROCESSOR].offset];
                    break;
                }
            }
            
            // Check op type = i_opType registrations.
            if (0 != ops[i_opType].offset)
            {
                // Check access type = WILDCARD registrations.
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
                if (targets[/*TODO: i_target->type*/PROCESSOR].flag)
                {
                    l_devRoute =
                        iv_operations[
                            targets[/*TODO: i_target->type*/PROCESSOR].offset];
                    break;
                }
            }
        } while(0);

        mutex_unlock(&iv_mutex);        
        
        // Call function if one was found, create error otherwise.
        if (NULL == l_devRoute)
        {
            /*@
             *  @errortype
             *  @moduleid       DEVFW_MOD_ASSOCIATOR
             *  @reasoncode     DEVFW_RC_NO_ROUTE_FOUND
             *  @userdata1      (OpType << 32) | (AccessType)
             *  @userdata1      TargetType
             *
             *  @devdesc        A device driver operation was attempted for
             *                  which no driver has been registered.
             */
            l_errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                   DEVFW_MOD_ASSOCIATOR,
                                   DEVFW_RC_NO_ROUTE_FOUND,
                                   TWO_UINT32_TO_UINT64(i_opType, i_accessType),
                                        /*TODO: i_target->type*/
                                   TO_UINT64(PROCESSOR)
                                  );
        }
        else
        {
            l_errl = (*l_devRoute)(i_opType, i_target, 
                                   io_buffer, io_buflen,
                                   i_accessType, i_addr);
        }

        return l_errl;
    }
}



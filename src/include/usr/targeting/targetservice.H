
#ifndef TARG_TARGETSERVICE_H
#define TARG_TARGETSERVICE_H

/**
 *  @file targetservice.H
 *
 *  @brief Interface for the target service
 *
 *  This header file contains the interface definition for the target service
 *  which is responsible for configuring and aggregating the pool of valid
 *  targets, and providing services to access targets based on various criteria
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>
#include <vector>

// Other components
#include <util/singleton.H>

// This component
#include <targeting/attributeenums.H>
#include <targeting/target.H>
#include <targeting/entitypath.H>
#include <targeting/iterators/targetiterator.H>
#include <targeting/predicates/predicatebase.H>

//******************************************************************************
// Interface Definitions
//******************************************************************************

//******************************************************************************
// Method to access the targeting service externally
//******************************************************************************

namespace TARGETING
{
    class TargetService;

    /**
     *  @brief Returns a reference to the targeting service singleton
     *
     *  @return Reference to the targeting service
     */
    TARGETING::TargetService& targetService();

/**
 *  @brief Sentinel representing the master processor chip target early in
 *      host boot prior to initialization of the target service.  Needed by the
 *      DD framework to bring PNOR device driver online.  Note this target
 *      cannot be used as input to any target service APIs.
 */
static Target* const MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    = reinterpret_cast<TARGETING::Target* const>(0xFFFFFFFFFFFFFFFFULL);

/**
 *  @brief TargetService class
 *
 *  This class manages the set of possible targets and provides facility to
 *  access specific targets, based on given criteria
 */
class TargetService
{
    public:

        /**
         *  @brief Enum specifying the recursion depth for target searching
         *
         *  Indicates whether to return only IMMEDIATE children/parent of a
         *  target, or ALL children/parents of a target
         */
        enum RECURSION_LEVEL
        {
            IMMEDIATE = 0x01, ///< Return immediate children/parent of a target
            ALL       = 0x02, ///< Return all children/parents of a target
        };

        /**
         *  @brief Enum specifying the type of association between targets
         *
         *  Indicates what relationship the result target should have to the
         *  target in question
         */
        enum ASSOCIATION_TYPE
        {
            PARENT,             ///< The result target(s) should be parents by
                                ///< containment
            CHILD,              ///< The result target(s) should be children by
                                ///< containment
            PARENT_BY_AFFINITY, ///< The result target(s) should be the parents
                                ///< by hardware affinity
            CHILD_BY_AFFINITY,  ///< The result target(s) should be children by
                                ///< Hardware affinity.  For example the child
                                ///< of a memory controller channel target might
                                ///< be a DIMM target
            VOLTAGE_SUPPLIER,   ///< The result target(s) should be the voltage
                                ///< supplier
            VOLTAGE_CONSUMER,   ///< The result target(s) should be the voltage
                                ///< consumer
        };

    public:

        /**
         *  @brief Construct the target service
         *
         *  Constructs the target service, but does not actually initialize the
         *  target pool
         *
         *  @post Target service instantiated, but target pool not initialized
         */
        TargetService();

        /**
         *  @brief Destroys the target service
         *
         *  Destroys the target service; it should never be run since it hides
         *  behind a singleton, but is included for completeness
         *
         *  @post Target service is destroyed, and all owned resources are
         *      reclaimed
         */
        ~TargetService();

        /**
         *  @brief Initializes the target service
         *
         *  Initializes the target service, including determining maximum number
         *  of targets, setting up the target pool, etc.  Should be called
         *  once PNOR is accessible can be mapped
         *
         *  @pre N/A
         *
         *  @post Target service fully initialized with all possible targets
         */
        void init();

        /**
         *  @brief Map iterator types to common aliases
         */
        typedef TargetIterator      iterator;
        typedef ConstTargetIterator const_iterator; 

        /**
         *  @brief Return iterator which points to first target service target
         *      (or end() if none)
         * 
         *  @return Iterator pointing to first target service target
         */
        iterator begin();
        
        /**
         *  @brief Return iterator to const which points to first target service
         *      target (or end() if none)
         * 
         *  @return Iterator to const pointing to first target service target
         */ 
        const_iterator begin() const;

        /**
         *  @brief Return iterator which points to the "past the end of the
         *      list" target maintained by the target service
         * 
         *  @return Iterator pointing to the "past the end of the list" target
         *      maintained by the target service
         */
        iterator end();
        
        /**
         *  @brief Return iterator to const which points to the "past the end of
         *      the list" target maintained by the target service
         * 
         *  @return Iterator to const pointing to the "past the end of the list"
         *      target maintained by the target service
         */
        const_iterator end() const;

        /**
         *  @brief Allow iterator access to the target service's target store
         */
        friend class _TargetIterator<Target*>;    
        friend class _TargetIterator<const Target*>; 

        /**
         *  @brief Returns the top level physical target
         *
         *  Returns the top level (usually system) target.  Caller must check
         *  for a NULL top level target
         *
         *  @param[out] o_targetHandle Top level target handle
         *
         *  @pre N/A
         *
         *  @post The returned handle is NULL if a top level target doesn't
         *      exist or service not initialized, otherwise it references a
         *      valid top level target
         */
        void getTopLevelTarget(
            Target*& o_targetHandle) const;

        /**
         *  @brief Returns whether specified entity path corresponds to a real
         *      target
         *
         *  Consults the specified entity path and searches through all
         *  available targets to find a matching entity path attribute.  If it
         *  finds a match, then the associated target exists, otherwise it does
         *  not exist
         *
         *  @param[in] i_entityPath Entity path to verify for existence
         *  @param[out] o_exists Whether the entity path corresponds to a
         *      target
         *
         *  @pre N/A
         *
         *  @post "true" returned to caller if specified entity path exists,
         *      "false" if not or service not initialized
         */
        void exists(
            const EntityPath& i_entityPath,
                  bool&       o_exists) const;

        /**
         *  @brief Returns a target handle which has an associated entity path
         *      matching the specified entity path
         *
         *  Returns a target handle which has an associated entity path
         *  matching the specified entity path.  Caller must check the
         *  returned handle for NULL.
         *
         *  @param[in] i_entityPath Entity path for which to find the matching
         *      target handle
         *
         *  @pre N/A
         *
         *  @post NULL returned to caller if no match was found or service
         *      not initialized, otherwise a valid handle returned
         *
         *  @return Target handle
         *
         *  @retval NULL No target match found
         *  @retval !NULL Handle to the corresponding target
         */
        Target* toTarget(
            const EntityPath& i_entityPath) const;

        /**
         *  @brief Returns the master processor chip target handle
         *
         *  Returns the master processor chip target handle.  On systems
         *  without an alternate master, it returns a handle to the only master,
         *  if found (NULL otherwise).  On systems with multiple potential
         *  masters, it returns a target handle to the acting master (NULL
         *  otherwise).  If targeting information is not yet accessible (very
         *  early in the host boot IPL), the returned target handle will be a
         *  sentinel value representing the master (whichever it may be)
         *
         *  @param[out] o_masterProcChipTarget Target handle referring to the
         *      current master processor chip (the one connected to PNOR)
         *
         *  @pre None
         *
         *  @post Master processor chip targets returned or a dummy value
         *      representing the acting master processor chip if the targeting
         *      information is not yet initialized
         */
        void masterProcChipTargetHandle(
            Target*& o_masterProcChipTargetHandle) const;

        /**
         *  @brief Returns whether the specified entity path attribute exists
         *      for a specified target, and if so, the value of that attribute
         *
         *  Returns whether the specified entity path attribute exists for a
         *  specified target, and if so, the value of that attribute.  If the
         *  target doesn't exist, or the attribute doesn't correspond to an
         *  entity path attribute, or the entity path attribute doesn't exist
         *  for the target, then the routine returns false and the entity path
         *  value is invalid.
         *
         *  @param[in] i_attr Entity path attribute to read
         *  @param[in] i_pTarget Target handle to read the attribute from
         *  @param[out] o_entityPath Value of the target's associated entity
         *      path value
         *
         *  @pre N/A
         *
         *  @post See "return"
         *
         *  @return bool indicating whether the specified attribute exists
         *      for the specified target and whether the returned entity path
         *      value is valid
         *
         *  @retval true Specified attribute exists, entity path is valid
         *  @retval false Specified attribute does not exist, entity path is
         *      invalid
         */
        bool tryGetPath(
                  ATTRIBUTE_ID i_attr,
            const Target*      i_pTarget,
                  EntityPath&  o_entityPath) const;

        /**
         *  @brief Returns entity paths of targets associated to the specified
         *      target in a specific way
         *
         *  Returns entity paths of targets associated to the specified target,
         *  as indicated by an association type.  Based on the specified
         *  recursion level, the routine will determine the immediate
         *  associations, or all possible associations.  For example, if caller
         *  supplies a processor chip target and asks for its children targets,
         *  the routine will return the next set of targets in the physical
         *  hierarchy.  Conversely if the caller asks for ALL children targets
         *  for said source target, the routine will return all targets
         *  contained within the processor chip.
         *
         *  @param[out] o_list List of target handles that match the specified
         *      criteria
         *  @param[in] i_pTarget Target from which to search for other targets
         *  @param[in] i_type Type of association linking the specified target
         *      to candidate result targets
         *  @param[in] i_recursionLevel Whether to return candidate targets
         *      immediately associated to the specified target or recursively
         *      associated to it.
         *  @param[in] i_pPredicate Pointer to a predicate to be evaluated 
         *      against each candidate target (as determined by the source
         *      target, type, and recursion level parameters).  If the predicate
         *      returns true, the target will be added to the result list.  A 
         *      value of NULL acts as a predicate that always returns true.
         *
         *  @pre N/A
         *
         *  @post Caller's list cleared; list of target handles matching the
         *      specified criteria returned
         */
         void getAssociated(
                  TargetHandleList& o_list,
            const Target* const     i_pTarget,
            const ASSOCIATION_TYPE  i_type = CHILD,
            const RECURSION_LEVEL   i_recursionLevel = IMMEDIATE,
            const PredicateBase*    i_pPredicate = NULL) const;

        /**
         *  @brief Dump the target service for debug only
         *
         *  @post Output written to buffer
         */
        void dump() const;

    private:

        /**
         *  @brief Enum specifying which direction to traverse associations
         *      between targets
         *
         *  Given a general class of association between targets, this enum
         *  tells the target service which direction to search along an entity
         *  path for the result targets
         */
        enum ASSOCIATION_DIRECTION
        {
            INWARDS,  ///< Search for associated targets of the specified target
                      ///< that happen to be closer to the top level target
            OUTWARDS, ///< Search for associated targets of the specified target
                      ///< that happen to be farther from the top level target
        };

        /**
         *  @brief Structure mapping an association type to an entity path
         *      attribute and entity path search direction
         *
         *  This map allows the target service to accept an association type
         *  from a caller and determine the appropriate entity path to search
         *  along for the result target, and in which direction along the path
         */
        struct AssociationAttrMap
        {
            ASSOCIATION_TYPE      associationType; ///< Specifies the type of
                                                   ///< association to traverse
            ASSOCIATION_DIRECTION associationDir;  ///< Specifies which
                                                   ///< direction along an
                                                   ///< entity path to search
            ATTRIBUTE_ID          attr;            ///< Specifies which entity
                                                   ///< path to search along
        };

        /**
         *  @brief Aliases a vector of association mappings
         */
        typedef std::vector< AssociationAttrMap > AssociationMappings_t;

        /**
         *  @brief Configures the pool of targets
         *
         *  This function computes the maximum number of targets possible based
         *  on the PNOR (or override) image, and updates the target service to
         *  point to the start of the target array, wherever it may reside
         *
         *  @pre Target service must not be initialized
         *
         *  @post Target service target pool configured for access
         */
        void _configureTargetPool();

        /**
         *  @brief Computes the maximum number of targets, caches the value
         *      and returns it to the caller
         *
         *  Computes the maximum number of targets possible based on the PNOR
         *  (or override) image and returns it to the caller
         *
         *  @pre Target service must not already be initialized
         *
         *  @post Target service updated with maximum target count.  Count also
         *      returned to caller
         *
         *  @return uint32_t indicating the maximum number of targets possible
         */
        uint32_t _maxTargets();

        /**
         *  @brief Returns handles to the targets associated to the
         *      target represented by the specified entity path such that the
         *      results are closer to the top level target than the source
         *
         *  Returns handles to the targets associated to the target represented
         *  by the specified entity path such that the results are closer to the
         *  top level target than the source.  An IMMEDIATE recursion level
         *  returns handles to targets that are one association away from the
         *  target referenced by the supplied entity path.  A recursion level of
         *  ALL recursively returns results.
         *
         *  @param[in] i_attr Entity path attribute that is used as the basis
         *      for lookups on candidate targets
         *  @param[in] i_recursionLevel Whether to provide immediate or
         *      recursive results
         *  @param[in] i_entityPath Entity path to start search from
         *  @param[in] i_pPredicate Pointer to a predicate to be evaluated 
         *      against each candidate target.  If the predicate returns true, 
         *      the target will be added to the result list.  A value of NULL 
         *      acts as a predicate that always returns true.
         *  @param[out] o_list List of returned target handles
         *
         *  @pre Target service must be initialized
         *
         *  @post List of target handles corresponding to targets closer to the
         *      top level target than the one referenced by the specified entity
         *      path returned
         */
        void _getInwards(
                  ATTRIBUTE_ID      i_attr,
                  RECURSION_LEVEL   i_recursionLevel,
                  EntityPath        i_entityPath,
            const PredicateBase*    i_pPredicate,
                  TargetHandleList& o_list) const;

        /**
         *  @brief Returns handles to the targets associated to the
         *      target represented by the specified entity path such that the
         *      results are farther from the top level target than the source
         *
         *  Returns handles to the targets associated to the target represented
         *  by the specified entity path such that the results are farther from
         *  the top level target than the source.  An IMMEDIATE recursion level
         *  returns handles to targets that are one association away from the
         *  target referenced by the supplied entity path.  A recursion level of
         *  ALL recursively returns results.
         *
         *  @param[in] i_attr Entity path attribute that is used as the basis
         *      for lookups on candidate targets
         *  @param[in] i_recursionLevel Whether to provide immediate or
         *      recursive results
         *  @param[in] i_entityPath Entity path to look from
         *  @param[in] i_pPredicate Pointer to a predicate to be evaluated 
         *      against each candidate target.  If the predicate returns true, 
         *      the target will be added to the result list.  A value of NULL 
         *      acts as a predicate that always returns true.
         *  @param[out] o_list List of returned target handles
         *
         *  @pre Target service must be initialized
         *
         *  @post List of target handles corresponding to targets farther from
         *      the top level target than the one referenced by the specified
         *      entity path returned.
         */
        void _getOutwards(
                  ATTRIBUTE_ID      i_attr,
                  RECURSION_LEVEL   i_recursionLevel,
                  EntityPath        i_entityPath,
            const PredicateBase*    i_pPredicate,
                  TargetHandleList& o_list ) const;

        // Instance variables
        bool        iv_initialized; ///< Is service initialized or not
        Target    (*iv_targets)[];  ///< Pointer to array of target objects
        uint32_t    iv_maxTargets;  ///< Maximum # target objects in the array
        const void* iv_pPnor;       ///< Pointer to the PNOR targeting section
        AssociationMappings_t iv_associationMappings; ///< Association map

        // Disable copy constructor / assignment operator

        TargetService(
            const TargetService& i_right);

        TargetService& operator=(
            const TargetService& i_right);
};

/**
 *  @brief Singleton to access the only TargetService; deemphasized
 *      intentionally
 */
class TargetService;
typedef Singleton<TARGETING::TargetService> theTargetService;

} // End namespace TARGETING

#endif // TARG_TARGETSERVICE_H

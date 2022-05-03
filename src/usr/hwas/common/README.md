# HWAS
## HWASDiscovery::discoverTargets
- Initializes the HWAS state of all targets
- Call platPresenceDetect for targets that need it
- Iterate each chip and apply partial-good information to children
  (isChipFunctional, checkPartialGoodForDescendants)
- De-configure parts that are marked as not-functional (a.k.a. "not-good") based
  on MVPD only
  - This will update that part's ATTR_PG attribute
- Call discoverPmicTargetsAndEnable
- Call validateProcessorEcLevels to ensure that each slave PROC chip has the
  same EC level as the master
- Call restrictECunits to deconfigure cores appropriately in fused-core mode
- Call invokePresentByAssoc to propagate parent/child functional status around
  the memory hierarchy
- Deconfigure NMMU1 based on its special rules

## invokePresentByAssoc

This function collects a list of targets in the memory targeting hierarchy and
calls presentByAssoc on the list.

## presentByAssoc

This function examines each target in the memory hierarchy (in order to update
HWAS functional state) and:
- propagates HWAS functional state from parents to children;
- deconfigures parents if they have no functional children of a given type;
- enforces special parent/child relationships not reflected in the normal
  hierarchy, such as that between OMIC and OMI targets.

## isChipFunctional

This function checks the partial-good data for always-good chiplets in each
processor to determine whether the processor is functional.

## checkPartialGoodForDescendants

This function checks the partial-good data for a target and all its children,
propagating deconfiguration as appropriate throughout the hierarchy based on PG
rules defined in pgLogic.C.

# DeconfigGard

## Deconfigure by association path
### _deconfigureByAssoc
###### Propagates the deconfigured target to its associated targets
- first deconfigures all functional children-by-containment
- checks if affinity deconfigure is allowed
  - allowed if not at runtime
  - always allowed for all speculative deconfigures
  - always allowed if EQ, EX or CORE target
- deconfigures target's affinity children (if allowed)
- deconfigures parent's affinity path via _deconfigParentAssoc (if allowed)

### _deconfigParentAssoc
###### Works the deconfig up the parent branch (handles special cases)
- handles special cases (FCO, PEER, etc) for select target types
- If no special case, then call _deconfigAffinityParent

### _deconfigAffinityParent
###### Deconfigure parent if is has no functional children
- Checks base attribute: ATTR_PARENT_DECONFIG_RULES
  - childRollupAllowed - Does this target allow its child's deconfiguration to rollup to it?
  - deconfigureParent - Is this child target allowed to rollup its deconfigure to parent?
  - valid - Are the previous two rules valid?
- checks if it is allowed to rollup deconfigure to parent (deconfigureParent)
- Grab parent target via new utility: getImmediateParentByAffinity(childTarget)
- Checks parent is functional
- Verifies parent is allowed to be deconfigured by child rollup(childRollupAllowed)
- Check if parent target has a functional AFFINITY child that is same type/class as the child.
- If no functional child found, then deconfigure the parent target and then call
  _deconfigureByAssoc passing the parent target.  Need to account for possible non-like
  children that need to be deconfigured under the parent target.

# [Field Core Override](fco-readme.md)

Field Core Override (FCO) is a core reduction algorithm that takes a given FCO value and applies it system wide such
that afterward there are only FCO value number of cores left functional for execution. See the readme of that file for
more detail.

# DeconfigGard

## Deconfigure by association path
### _deconfigByAssoc
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
- checks if it is allowed to rollup deconfigure to parent
- Checks base attribute: ATTR_PARENT_DECONFIG_DISABLED
  - 0 = allow parent deconfigure (default)
  - 1 = do not allow parent deconfigure
- Grab parent target via new utility: getImmediateParentByAffinity(childTarget)
- Checks parent is functional
- Check if parent target has a functional AFFINITY child.
- If no functional child found, then deconfigure the parent target and then call
  _deconfigParentAssoc passing the parent target.  We already know this parent
  target has no functional children, so we just continue the deconfigure
  rollup to the next level.

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


# 2.3 Compatibility RISK_LEVEL update

## updateProcCompatibilityRiskLevel()
- This function changes the RISK_LEVEL based on ECs installed,
  Input RISK_LEVEL, and PROC_COMPATIBILITY_REQ setting
- ATTR_RISK_LEVEL is being used to control what processor security/performance
is allowable
    - *Compatibility levels:*
      + 0 - P9N22_P9C12_RUGBY_FAVOR_SECURITY
      + 1 - P9N22_P9C12_RUGBY_FAVOR_PERFORMANCE
      + 2 - P9N22_NO_RUGBY_MITIGATIONS
      + 3 - P9N22_P9N23_JAVA_PERF
    - *Native levels: (DD2.3 supported)*
      + 4 - P9N23_P9C13_NATIVE_SMF_RUGBY_FAVOR_SECURITY
      + 5 - P9N23_P9C13_NATIVE_SMF_RUGBY_FAVOR_PERFORMANCE

- ATTR_RISK_LEVEL is either setup via MRW or USER (Firmware code).
  + ATTR_RISK_LEVEL_ORIGIN is defaulted to USER unless MRW is used.
  + ATTR_RISK_LEVEL_ORIGIN is used for error case of FORCED_COMPATIBIILITY

- ATTR_PROC_COMPATIBILITY_REQ is used to determine how to update the system's
risk level.
  + 0 - ALLOW_COMPATIBILITY = set RISK_LEVEL to best allowed (default)
  + 1 - FORCED_COMPATIBILITY = set RISK_LEVEL to a compatible level
  + 2 - FORCED_NATIVE = set RISK_LEVEL to ECs native setting
        (DD2.2 = compatible level, DD2.3 = Native)

### Compatibility Truth Tables

1. **ALLOW_COMPATIBILITY** (default)

| Input RISK_LEVEL | RISK_LEVEL_ORIGIN | Output RISK_LEVEL (All DD2.3)  | Output RISK_LEVEL (All DD2.2)   | Output RISK_LEVEL (Mixed)   |
|:---------- |:----------------- |:-----------------:|:-----------------:|:-----------------:|
| 0,1        | User              | 0,1               | 0,1               | 0,1               |
| 2          | User              | 2                 | 2                 | 2                 |
| 3          | User              | 3                 | 3                 | 3                 |
| 4          | User              | 4                 | `0`               | `0`               |
| 5          | User              | 5                 | `2`               | `2`               |
| 0,1        | MRW               | `4`               | 0,1               | 0,1               |
| 2          | MRW               | `5`               | 2                 | 2                 |
| 3          | MRW               | 3                 | 3                 | 3                 |
| 4          | MRW               | 4                 | `0`               | `0`               |
| 5          | MRW               | 5                 | `2`               | `2`               |

2. **FORCED_COMPATIBILITY**

| Input RISK_LEVEL | RISK_LEVEL_ORIGIN | Output RISK_LEVEL (All DD2.3)  | Output RISK_LEVEL (All DD2.2)   | Output RISK_LEVEL (Mixed)   |
|:---------- |:----------------- |:-----------------:|:-----------------:|:-----------------:|
| 0,1        | User              | 0,1               | 0,1               | 0,1               |
| 2          | User              | 2                 | 2                 | 2                 |
| 3          | User              | 3                 | 3                 | 3                 |
| 4          | User              | `0`               | `0`               | `0`               |
| 5          | User              | `2`               | `2`               | `2`               |
| 0,1        | MRW               | 0,1               | 0,1               | 0,1               |
| 2          | MRW               | 2                 | 2                 | 2                 |
| 3          | MRW               | 3                 | 3                 | 3                 |
| 4          | MRW               | **ERROR**         | **ERROR**         | **ERROR**         |
| 5          | MRW               | **ERROR**         | **ERROR**         | **ERROR**         |

3. **FORCE_NATIVE**

| Input RISK_LEVEL | RISK_LEVEL_ORIGIN | Output RISK_LEVEL (All DD2.3)  | Output RISK_LEVEL (All DD2.2)   | Output RISK_LEVEL (Mixed)   |
|:---------- |:----------------- |:-----------------:|:-----------------:|:-----------------:|
| 0,1        | User              | `4`               | 0,1               | **ERROR**         |
| 2          | User              | `5`               | 2                 | **ERROR**         |
| 3          | User              | **ERROR**         | 3                 | **ERROR**         |
| 4          | User              | 4                 | `0`               | **ERROR**         |
| 5          | User              | 5                 | `2`               | **ERROR**         |
| 0,1        | MRW               | `4`               | 0,1               | **ERROR**         |
| 2          | MRW               | `5`               | 2                 | **ERROR**         |
| 3          | MRW               | **ERROR**         | 3                 | **ERROR**         |
| 4          | MRW               | 4                 | `0`               | **ERROR**         |
| 5          | MRW               | 5                 | `2`               | **ERROR**         |

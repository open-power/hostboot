# Explorer Update
## Default way to update is through inband MMIO (istep 12.12)
- In this mode there is no extra flashloader required as the logic is baked into the FW image that is running. This is the fastest method so it is always preferred.

## Fail OMI training, update via i2c (end of istep 12.6)
- In this case we have a valid FW image active that includes a flashloader. We will use the same EXP_FW_BINARY_UPDATE command as in the inband path except we'll physically send the bytes over to Explorer via i2c instead of inband MMIOs.
- NOTE: update will fail before step 12.6 because the inbound doorbell register (along with many other parts of the scommable logic) in Explorer isn't clocked before we run the FW_BOOT_CONFIG0 command

### Design of how to handle i2c update of Explorer OCMB
**ATTR_OCMB_FW_UPDATE_STATUS**
Persistent system attribute (uint8)
Bit field name |  Description
-- | ----
updateRequired | istep 12.6 checks for any mismatched level on all OCMBs, sets to 1 if mismatch found
updateI2c | istep 12.7 to 12.11 will set to 1 if HWP fails and updateRequired is set
i2cUpdateAttempted | istep 12.6 will update to 1 when the i2c update is attempted
hardFailure | istep 12.7-12.11 will set if HWP fails and i2cUpdate was attempted
reserved | 4 bits (unused)

istep 12.6 (after exp_omi_setup)
- checks for mismatches and sets updateRequired. (Skip check and update if MPIPL)
- if no mismatch
  - clear out OCMB_FW_UPDATE_STATUS
- if mismatch and hardFailure
  - clear out OCMB_FW_UPDATE_STATUS except the updateRequired bit (User wants to try update again after hard failure)
- if mismatch and updateI2c but not i2cUpdateAttempted
  - set i2cUpdateAttempted and run the i2c update on all mismatched OCMBs

istep 12.7 - 12.11
- if HWP fails, call **captureErrorOcmbUpdateCheck()** on any target
  - If updateRequired = 0 (*No mismatched code levels to update*)
    - captureError() and exit
  - else (*mismatched code levels to update*)
    - if i2cUpdateAttempted
        -  captureError() and set hardFailure bit
        (allow IPL to stop, already tried to update via i2c)
    - else if updateI2c = 0
        - set updateI2c and commit HWP error as recovered
        - force reconfig loop (don't kill the IPL)

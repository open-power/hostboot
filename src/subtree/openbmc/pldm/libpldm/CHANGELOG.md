# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html).

Change categories:

- Added
- Changed
- Deprecated
- Removed
- Fixed
- Security

## [0.10.0] 2024-11-01

### Added

1. oem: meta: Add decode_oem_meta_file_io_write_req()
2. oem: meta: Add decode_oem_meta_file_io_read_req()
3. oem: meta: Add encode_oem_meta_file_io_read_resp()
4. pdr: Add pldm_entity_association_pdr_remove_contained_entity()
5. pdr: Add pldm_pdr_remove_fru_record_set_by_rsi()
6. pldm_entity_association_tree_copy_root_check()
7. oem: ibm: Add topology related state set and enum

8. base: Add size and buffer macros for struct pldm_msg

   Together these macros reduce the need for use of reinterpret_cast<>() in C++.

9. entity: Add new entity types from DSP0249 v1.3.0
10. stateset: Add new state sets from DSP0249 v1.3.0

### Changed

1. dsp: bios_table: Null check for pldm_bios_table_iter_is_end()

   pldm_bios_table_iter_is_end() now returns true if the provided argument is
   NULL.

2. Register assignment for parameters of a number of APIs changed with increased
   scrutiny on their implementations.

   - `decode_entity_auxiliary_names_pdr()`
   - `decode_get_state_sensor_readings_resp()`
   - `decode_oem_meta_file_io_req()`
   - `decode_platform_event_message_req()`
   - `decode_platform_event_message_resp()`
   - `decode_sensor_op_data()`
   - `encode_get_state_effecter_states_resp()`
   - `encode_state_effecter_pdr()`
   - `encode_state_sensor_pdr()`
   - `pldm_bios_table_append_pad_checksum()`
   - `pldm_bios_table_attr_value_entry_encode_enum()`
   - `pldm_bios_table_attr_value_entry_encode_string()`
   - `pldm_pdr_find_record()`
   - `pldm_pdr_get_next_record()`

3. platform: Support PLDM_CPER_EVENT in encode_platform_event_message_req()

4. dsp: firmware_update: Bounds check
   decode_downstream_device_parameter_table_entry_versions()

   The additional bounds-checking required the addition of further length
   parameters.

### Deprecated

1. oem: meta: Deprecate `decode_oem_meta_file_io_req()`

   Users should switch to `decode_oem_meta_file_io_write_req()`. Modify this
   function to make it safer.

   Modification:

   - The meaning of the returned result.
   - Change parameters from individual pointers to a struct.
   - Check the length provided in the message won't exceed the buffer.

2. pldm_entity_association_tree_copy_root()

   The implementation allocates, but gives no indication to the caller if an
   allocation (and hence the copy) has failed. Users should migrate to
   pldm_entity_association_tree_copy_root_check().

3. The following APIs are deprecated as unsafe due to various unfixable CWE
   violations:

   - [CWE-129: Improper Validation of Array Index](https://cwe.mitre.org/data/definitions/129.html)

     - `encode_get_bios_current_value_by_handle_resp()`
     - `encode_get_bios_table_resp()`
     - `encode_get_file_table_resp()`
     - `encode_get_version_resp()`
     - `pldm_bios_table_attr_entry_enum_decode_def_indices()`
     - `pldm_bios_table_attr_entry_enum_decode_def_num()`
     - `pldm_bios_table_attr_find_by_handle()`
     - `pldm_bios_table_attr_find_by_string_handle()`
     - `pldm_bios_table_attr_value_find_by_handle()`
     - `pldm_bios_table_iter_create()`
     - `pldm_bios_table_iter_is_end()`
     - `pldm_bios_table_string_find_by_handle()`
     - `pldm_bios_table_string_find_by_string()`

   - [CWE-617: Reachable Assertion](https://cwe.mitre.org/data/definitions/617.html)

     - `pldm_entity_association_tree_copy_root()`

   - [CWE-789: Memory Allocation with Excessive Size Value](https://cwe.mitre.org/data/definitions/789.html)

     - `decode_oem_meta_file_io_req()`

   - [CWE-823: Use of Out-of-range Pointer Offset](https://cwe.mitre.org/data/definitions/823.html)
     - `encode_fru_record()`
     - `encode_get_pdr_resp()`
     - `pldm_bios_table_attr_entry_enum_encode_length()`

### Removed

1. Deprecated functions with the `_check` suffix

   - `get_fru_record_by_option_check()`
   - `pldm_bios_table_append_pad_checksum_check()`
   - `pldm_bios_table_attr_entry_enum_decode_def_num_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_hdls_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_num_check()`
   - `pldm_bios_table_attr_entry_enum_encode_check()`
   - `pldm_bios_table_attr_entry_integer_encode_check()`
   - `pldm_bios_table_attr_entry_string_decode_def_string_length_check()`
   - `pldm_bios_table_attr_entry_string_encode_check()`
   - `pldm_bios_table_attr_value_entry_encode_enum_check()`
   - `pldm_bios_table_attr_value_entry_encode_integer_check()`
   - `pldm_bios_table_attr_value_entry_encode_string_check()`
   - `pldm_bios_table_string_entry_decode_string_check()`
   - `pldm_bios_table_string_entry_encode_check()`
   - `pldm_entity_association_pdr_add_check()`
   - `pldm_entity_association_pdr_add_from_node_check()`
   - `pldm_pdr_add_check()`
   - `pldm_pdr_add_fru_record_set_check()`

### Fixed

1. dsp: bios_table: Null check for pldm_bios_table_iter_is_end()

   Avoid a caller-controlled NULL pointer dereference in the library
   implementation.

2. platform: fix encode/decode_poll_for_platform_event_message_req

   Update checking of `TransferOperationFlag` and `eventIDToAcknowledge` to
   follow spec.

3. platform: Fix checking `eventIDToAcknowledge`

   As the event receiver sends `PollForPlatformEventMessage` with the
   `tranferFlag` is `AcknowledgementOnly`, the value `eventIDToAcknowledge`
   should be the previously retrieved eventID (from the PLDM terminus).

4. dsp: platform: Prevent overflow of arithmetic on event_data_length
5. dsp: platform: Bounds check encode_sensor_state_pdr()
6. dsp: platform: Bounds check encode_state_effecter_pdr()
7. dsp: pdr: Bounds check pldm_entity_association_pdr_extract()
8. dsp: bios_table: Bounds check pldm_bios_table_append_pad_checksum()
9. dsp: bios_table: Bounds check
   pldm_bios_table_attr_value_entry_encode_string()
10. dsp: bios_table: Bounds check pldm_bios_table_attr_value_entry_encode_enum()
11. dsp: firmware_update: Bounds check
    decode_downstream_device_parameter_table_entry_versions()
12. oem: ibm: platform: Bounds check encode_bios_attribute_update_event_req()
13. dsp: fru: Bounds check encode_get_fru_record_by_option_resp()
14. dsp: fru: Bounds check encode_fru_record()
15. dsp: bios: Bounds check encode_set_bios_table_req()
16. dsp: bios: Bounds check encode_set_bios_attribute_current_value_req()
17. dsp: bios_table: Bounds check pldm_bios_table_string_entry_encode()
18. dsp: pdr: Rework test in pldm_entity_association_pdr_extract()
19. dsp: platform: Fix decode_set_event_receiver_req()

## [0.9.1] - 2024-09-07

### Changed

1. Moved evolutions intended for v0.9.0 into place

   Evolutions for the release have been moved from `evolutions/current` to
   `evolutions/v0.9.1`. Library users can apply them to migrate off of
   deprecated APIs.

## [0.9.0] - 2024-09-07

### Added

1. base: Define macros for reserved TIDs
2. pdr: Add pldm_entity_association_pdr_add_contained_entity_to_remote_pdr()
3. pdr: Add pldm_entity_association_pdr_create_new()
4. platform: Define macros for the responded transferflags
5. pdr: Add pldm_pdr_get_terminus_handle() API
6. pdr: Add related decode_entity_auxiliary_names_pdr() APIs
7. fw_update: Add encode req & decode resp for get_downstream_fw_params
8. platform: Add decode_pldm_platform_cper_event() API
9. decode_get_pdr_repository_info_resp_safe()

   Replaces decode_get_pdr_repository_info_resp() as discussed in the
   `Deprecated` section below

10. decode_get_pdr_resp_safe()

    Replaces decode_get_pdr_resp() as discussed in the `Deprecated` section
    below

### Changed

1. pdr: Stabilise related decode_entity_auxiliary_names_pdr() APIs
2. platform: Rework decode/encode_pldm_message_poll_event_data() APIs
3. platform: Stabilise decode_pldm_message_poll_event_data() APIs
4. ABI break for decode_sensor_op_data()

   Applying LIBPLDM_CC_NONNULL to the internal msgbuf APIs caused
   abi-compliance-checker to flag a change in the register containing the
   parameter `previous_op_state`.

5. platform: Stabilise decode_pldm_platform_cper_event() API
6. oem: meta: Stabilise decode_oem_meta_file_io_write_req() API
7. oem: meta: Stabilise decode_oem_meta_file_io_read_req() API
8. oem: meta: Stabilise encode_oem_meta_file_io_read_resp() API

### Deprecated

1. Rename and deprecate functions with the `_check` suffix

   All library function return values always need to be checked. The `_check`
   suffix is redundant, so remove it. Migration to the non-deprecated
   equivalents without the `_check` suffix can be performed using
   `scripts/ apply-renames` and the [clang-rename][] configurations under
   `evolutions/`

   The deprecated functions:

   - `get_fru_record_by_option_check()`
   - `pldm_bios_table_append_pad_checksum_check()`
   - `pldm_bios_table_attr_entry_enum_decode_def_num_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_hdls_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_num_check()`
   - `pldm_bios_table_attr_entry_enum_encode_check()`
   - `pldm_bios_table_attr_entry_integer_encode_check()`
   - `pldm_bios_table_attr_entry_string_decode_def_string_length_check()`
   - `pldm_bios_table_attr_entry_string_encode_check()`
   - `pldm_bios_table_attr_value_entry_encode_enum_check()`
   - `pldm_bios_table_attr_value_entry_encode_integer_check()`
   - `pldm_bios_table_attr_value_entry_encode_string_check()`
   - `pldm_bios_table_string_entry_decode_string_check()`
   - `pldm_bios_table_string_entry_encode_check()`
   - `pldm_entity_association_pdr_add_check()`
   - `pldm_entity_association_pdr_add_from_node_check()`
   - `pldm_pdr_add_check()`
   - `pldm_pdr_add_fru_record_set_check()`

[clang-rename]: https://clang.llvm.org/extra/clang-rename.html

2. `decode_get_pdr_repository_info_resp()`

   Users should move to `decode_get_pdr_repository_info_resp_safe()` which
   eliminates the opportunity for buffer overruns when extracting objects from
   the message.

3. `decode_get_pdr_resp()`

   Users should move to `decode_get_pdr_resp_safe()` which reduces the
   invocation tedium and improves memory safety over `decode_get_pdr_resp()`.

### Removed

1. IBM OEM header compatibility symlinks.

   Anyone left using the deprecated paths can migrate using the coccinelle patch
   at `evolutions/current/oem-ibm-header-compat.cocci`.

### Fixed

1. requester: instance-id: Release read lock on conflict
2. pdr: Error propagation for
   pldm_entity_association_pdr_add_from_node_with_record_handle()

## [0.8.0] - 2024-05-23

### Added

1. base: Provide pldm_msg_hdr_correlate_response()
2. transport: af-mctp: Add pldm_transport_af_mctp_bind()
3. oem: ibm: Add chapdata file type support
4. base: Added PLDM_SMBIOS & PLDM_RDE message types
5. oem: meta: Add decode_oem_meta_file_io_req()
6. state-set: Add all state set values to system power state enum as per DSP0249
7. platform: Add alias members to the enum
   pldm_pdr_repository_chg_event_change_record_event_data_operation.

   enum constants with inconsistent names are deprecated with this change.
   remove old inconsistent enum members after backward compatibility cleanup is
   done

8. oem-ibm: Alias `pldm_oem_ibm_fru_field_type` members as `PLDM_OEM_IBM_*`
9. oem: ibm: Add Firmware Update Access Key(UAK) as a FRU field type
10. platform: Add 3 PDR type enum for Redfish Device Enablement per
    DSP0248_1.2.0
11. state_set: Add CONNECTED and DISCONNECTED enum for Link State set
12. entity: Add enum for Network Interface Connectors and Network Ports
    Connection Types
13. pdr: Add decode_numeric_effecter_pdr_data()
14. oem: ibm: Support for the Real SAI entity id
15. fw_update: Add encode req & decode resp for query_downstream_devices
16. fw_update: Add encode req & decode resp for query_downstream_identifiers
17. platform: Add support for GetStateEffecterStates command

### Changed

1. base: Stabilise pldm_msg_hdr_correlate_response()
2. transport: af-mctp: Stabilise pldm_transport_af_mctp_bind()
3. libpldm: Fix header use
4. libpldm: More fixes for header use
5. pdr: Stabilise pldm_pdr_find_last_in_range() API
6. pdr: Stabilise pldm_entity_association_pdr_add_from_node_with_record_handle()
7. oem: meta: stabilise decode_oem_meta_file_io_req()
8. pdr: pldm_entity_association_tree_copy_root(): Document preconditions

### Deprecated

1. Deprecate `pldm_oem_ibm_fru_field_type` members that that are not prefixed
   with `PLDM_OEM_IBM_`

### Fixed

1. libpldm: Rationalise the local and installed path of pldm.h
2. pdr: Assign record_handle in entity_association_pdr_add_children()
3. msgbuf: Require sensor data enum in pldm_msgbuf_extract_sensor_value()
4. pdr: Remove redundant constant for minimum numeric sensor PDR length
5. tests: oem: meta: Fix fileio use of msgbuf

## [0.7.0] - 2023-08-29

### Added

1. state-set: Add new enum for Operational Fault Status enum

### Changed

1. transport: Match specified metadata in pldm_transport_send_recv_msg()
2. transport: mctp-demux: Drop ABI annotation for internal symbols
3. transport: Stabilise core transport and implementation APIs

   This stabilisation covers the following headers and functions:

   - libpldm/transport.h

     - pldm_transport_poll()
     - pldm_transport_send_msg()
     - pldm_transport_recv_msg()
     - pldm_transport_send_recv_msg()

   - libpldm/transport/af-mctp.h

     - pldm_transport_af_mctp_init()
     - pldm_transport_af_mctp_destroy()
     - pldm_transport_af_mctp_core()
     - pldm_transport_af_mctp_init_pollfd()
     - pldm_transport_af_mctp_map_tid()
     - pldm_transport_af_mctp_unmap_tid()

   - libpldm/transport/mctp-demux.h
     - pldm_transport_mctp_demux_init()
     - pldm_transport_mctp_demux_destroy()
     - pldm_transport_mctp_demux_core()
     - pldm_transport_mctp_demux_init_pollfd()
     - pldm_transport_mctp_demux_map_tid()
     - pldm_transport_mctp_demux_unmap_tid()

### Deprecated

1. All the existing "requester" APIs from `libpldm/pldm.h` (also known as
   `libpldm/requester/pldm.h`):

   - pldm_open()
   - pldm_send_recv()
   - pldm_send()
   - pldm_recv()
   - pldm_recv_any()
   - pldm_close()

   Users should migrate to the newer "transport" APIs instead.

## Fixed

1. tests: Exclude transport tests when build excludes testing ABIs
2. abi: Capture deprecation of pldm_close()

## [0.6.0] - 2023-08-22

### Changed

1. pdr: Avoid ID overflow in pldm_entity_association_tree_add_entity()
2. meson: Apply `b_ndebug=if-release` by default
3. pdr : Stabilize pldm_entity_association_tree_add_entity()
4. pdr: Stabilise pldm_entity_association_tree_find_with_locality()
5. pdr: Stabilize pldm_entity_node_get_remote_container_id()
6. transport: af-mctp: Assign out-params on success in \*\_recv()
7. transport: Generalise the pldm_transport_recv_msg() API

### Removed

1. pdr: Remove pldm_entity_association_pdr_add()
2. state-set: Remove enum pldm_state_set_operational_fault_status_values

### Fixed

1. transport: register init_pollfd callback for af-mctp
2. transport: fix init_pollfd function parameter
3. transport: Fix doxygen and variables for send and recv functions
4. transport: af-mctp: Ensure malloc() succeeds in \*\_recv()

## [0.5.0] - 2023-08-09

### Added

1. oem: meta: Add decode_oem_meta_file_io_write_req()
2. oem: meta: Add decode_oem_meta_file_io_read_req()
3. oem: meta: Add encode_oem_meta_file_io_read_resp()
4. pdr: Add pldm_entity_association_pdr_remove_contained_entity()
5. pdr: Add pldm_pdr_remove_fru_record_set_by_rsi()
6. pldm_entity_association_tree_copy_root_check()
7. oem: ibm: Add topology related state set and enum

8. base: Add size and buffer macros for struct pldm_msg

   Together these macros reduce the need for use of reinterpret_cast<>() in C++.

### Changed

1. dsp: bios_table: Null check for pldm_bios_table_iter_is_end()

   pldm_bios_table_iter_is_end() now returns true if the provided argument is
   NULL.

2. Register assignment for parameters of a number of APIs changed with increased
   scrutiny on their implementations.

   - `decode_entity_auxiliary_names_pdr()`
   - `decode_get_state_sensor_readings_resp()`
   - `decode_oem_meta_file_io_req()`
   - `decode_platform_event_message_req()`
   - `decode_platform_event_message_resp()`
   - `decode_sensor_op_data()`
   - `encode_get_state_effecter_states_resp()`
   - `encode_state_effecter_pdr()`
   - `encode_state_sensor_pdr()`
   - `pldm_bios_table_append_pad_checksum()`
   - `pldm_bios_table_attr_value_entry_encode_enum()`
   - `pldm_bios_table_attr_value_entry_encode_string()`
   - `pldm_pdr_find_record()`
   - `pldm_pdr_get_next_record()`

3. platform: Support PLDM_CPER_EVENT in encode_platform_event_message_req()

4. dsp: firmware_update: Bounds check
   decode_downstream_device_parameter_table_entry_versions()

   The additional bounds-checking required the addition of further length
   parameters.

### Deprecated

1. oem: meta: Deprecate `decode_oem_meta_file_io_req()`

   Users should switch to `decode_oem_meta_file_io_write_req()`. Modify this
   function to make it safer.

   Modification:

   - The meaning of the returned result.
   - Change parameters from individual pointers to a struct.
   - Check the length provided in the message won't exceed the buffer.

2. pldm_entity_association_tree_copy_root()

   The implementation allocates, but gives no indication to the caller if an
   allocation (and hence the copy) has failed. Users should migrate to
   pldm_entity_association_tree_copy_root_check().

3. The following APIs are deprecated as unsafe due to various unfixable CWE
   violations:

   - [CWE-129: Improper Validation of Array Index](https://cwe.mitre.org/data/definitions/129.html)

     - `encode_get_bios_current_value_by_handle_resp()`
     - `encode_get_bios_table_resp()`
     - `encode_get_file_table_resp()`
     - `encode_get_version_resp()`
     - `pldm_bios_table_attr_entry_enum_decode_def_indices()`
     - `pldm_bios_table_attr_entry_enum_decode_def_num()`
     - `pldm_bios_table_attr_find_by_handle()`
     - `pldm_bios_table_attr_find_by_string_handle()`
     - `pldm_bios_table_attr_value_find_by_handle()`
     - `pldm_bios_table_iter_create()`
     - `pldm_bios_table_iter_is_end()`
     - `pldm_bios_table_string_find_by_handle()`
     - `pldm_bios_table_string_find_by_string()`

   - [CWE-617: Reachable Assertion](https://cwe.mitre.org/data/definitions/617.html)

     - `pldm_entity_association_tree_copy_root()`

   - [CWE-789: Memory Allocation with Excessive Size Value](https://cwe.mitre.org/data/definitions/789.html)

     - `decode_oem_meta_file_io_req()`

   - [CWE-823: Use of Out-of-range Pointer Offset](https://cwe.mitre.org/data/definitions/823.html)
     - `encode_fru_record()`
     - `encode_get_pdr_resp()`
     - `pldm_bios_table_attr_entry_enum_encode_length()`

### Removed

1. Deprecated functions with the `_check` suffix

   - `get_fru_record_by_option_check()`
   - `pldm_bios_table_append_pad_checksum_check()`
   - `pldm_bios_table_attr_entry_enum_decode_def_num_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_hdls_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_num_check()`
   - `pldm_bios_table_attr_entry_enum_encode_check()`
   - `pldm_bios_table_attr_entry_integer_encode_check()`
   - `pldm_bios_table_attr_entry_string_decode_def_string_length_check()`
   - `pldm_bios_table_attr_entry_string_encode_check()`
   - `pldm_bios_table_attr_value_entry_encode_enum_check()`
   - `pldm_bios_table_attr_value_entry_encode_integer_check()`
   - `pldm_bios_table_attr_value_entry_encode_string_check()`
   - `pldm_bios_table_string_entry_decode_string_check()`
   - `pldm_bios_table_string_entry_encode_check()`
   - `pldm_entity_association_pdr_add_check()`
   - `pldm_entity_association_pdr_add_from_node_check()`
   - `pldm_pdr_add()`
   - `pldm_pdr_add_fru_record_set_check()`

### Fixed

1. dsp: bios_table: Null check for pldm_bios_table_iter_is_end()

   Avoid a caller-controlled NULL pointer dereference in the library
   implementation.

2. platform: fix encode/decode_poll_for_platform_event_message_req

   Update checking of `TransferOperationFlag` and `eventIDToAcknowledge` to
   follow spec.

3. platform: Fix checking `eventIDToAcknowledge`

   As the event receiver sends `PollForPlatformEventMessage` with the
   `tranferFlag` is `AcknowledgementOnly`, the value `eventIDToAcknowledge`
   should be the previously retrieved eventID (from the PLDM terminus).

4. dsp: platform: Prevent overflow of arithmetic on event_data_length
5. dsp: platform: Bounds check encode_sensor_state_pdr()
6. dsp: platform: Bounds check encode_state_effecter_pdr()
7. dsp: pdr: Bounds check pldm_entity_association_pdr_extract()
8. dsp: bios_table: Bounds check pldm_bios_table_append_pad_checksum()
9. dsp: bios_table: Bounds check
   pldm_bios_table_attr_value_entry_encode_string()
10. dsp: bios_table: Bounds check pldm_bios_table_attr_value_entry_encode_enum()
11. dsp: firmware_update: Bounds check
    decode_downstream_device_parameter_table_entry_versions()
12. oem: ibm: platform: Bounds check encode_bios_attribute_update_event_req()
13. dsp: fru: Bounds check encode_get_fru_record_by_option_resp()
14. dsp: fru: Bounds check encode_fru_record()
15. dsp: bios: Bounds check encode_set_bios_table_req()
16. dsp: bios: Bounds check encode_set_bios_attribute_current_value_req()
17. dsp: bios_table: Bounds check pldm_bios_table_string_entry_encode()
18. dsp: pdr: Rework test in pldm_entity_association_pdr_extract()
19. dsp: platform: Fix decode_set_event_receiver_req()

## [0.9.1] - 2024-09-07

### Changed

1. Moved evolutions intended for v0.9.0 into place

   Evolutions for the release have been moved from `evolutions/current` to
   `evolutions/v0.9.1`. Library users can apply them to migrate off of
   deprecated APIs.

## [0.9.0] - 2024-09-07

### Added

1. base: Define macros for reserved TIDs
2. pdr: Add pldm_entity_association_pdr_add_contained_entity_to_remote_pdr()
3. pdr: Add pldm_entity_association_pdr_create_new()
4. platform: Define macros for the responded transferflags
5. pdr: Add pldm_pdr_get_terminus_handle() API
6. pdr: Add related decode_entity_auxiliary_names_pdr() APIs
7. fw_update: Add encode req & decode resp for get_downstream_fw_params
8. platform: Add decode_pldm_platform_cper_event() API
9. decode_get_pdr_repository_info_resp_safe()

   Replaces decode_get_pdr_repository_info_resp() as discussed in the
   `Deprecated` section below

10. decode_get_pdr_resp_safe()

    Replaces decode_get_pdr_resp() as discussed in the `Deprecated` section
    below

### Changed

1. pdr: Stabilise related decode_entity_auxiliary_names_pdr() APIs
2. platform: Rework decode/encode_pldm_message_poll_event_data() APIs
3. platform: Stabilise decode_pldm_message_poll_event_data() APIs
4. ABI break for decode_sensor_op_data()

   Applying LIBPLDM_CC_NONNULL to the internal msgbuf APIs caused
   abi-compliance-checker to flag a change in the register containing the
   parameter `previous_op_state`.

5. platform: Stabilise decode_pldm_platform_cper_event() API
6. oem: meta: Stabilise decode_oem_meta_file_io_write_req() API
7. oem: meta: Stabilise decode_oem_meta_file_io_read_req() API
8. oem: meta: Stabilise encode_oem_meta_file_io_read_resp() API

### Deprecated

1. Rename and deprecate functions with the `_check` suffix

   All library function return values always need to be checked. The `_check`
   suffix is redundant, so remove it. Migration to the non-deprecated
   equivalents without the `_check` suffix can be performed using
   `scripts/ apply-renames` and the [clang-rename][] configurations under
   `evolutions/`

   The deprecated functions:

   - `get_fru_record_by_option_check()`
   - `pldm_bios_table_append_pad_checksum_check()`
   - `pldm_bios_table_attr_entry_enum_decode_def_num_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_hdls_check()`
   - `pldm_bios_table_attr_entry_enum_decode_pv_num_check()`
   - `pldm_bios_table_attr_entry_enum_encode_check()`
   - `pldm_bios_table_attr_entry_integer_encode_check()`
   - `pldm_bios_table_attr_entry_string_decode_def_string_length_check()`
   - `pldm_bios_table_attr_entry_string_encode_check()`
   - `pldm_bios_table_attr_value_entry_encode_enum_check()`
   - `pldm_bios_table_attr_value_entry_encode_integer_check()`
   - `pldm_bios_table_attr_value_entry_encode_string_check()`
   - `pldm_bios_table_string_entry_decode_string_check()`
   - `pldm_bios_table_string_entry_encode_check()`
   - `pldm_entity_association_pdr_add_check()`
   - `pldm_entity_association_pdr_add_from_node_check()`
   - `pldm_pdr_add()`
   - `pldm_pdr_add_fru_record_set_check()`

[clang-rename]: https://clang.llvm.org/extra/clang-rename.html

2. `decode_get_pdr_repository_info_resp()`

   Users should move to `decode_get_pdr_repository_info_resp_safe()` which
   eliminates the opportunity for buffer overruns when extracting objects from
   the message.

3. `decode_get_pdr_resp()`

   Users should move to `decode_get_pdr_resp_safe()` which reduces the
   invocation tedium and improves memory safety over `decode_get_pdr_resp()`.

### Removed

1. IBM OEM header compatibility symlinks.

   Anyone left using the deprecated paths can migrate using the coccinelle patch
   at `evolutions/current/oem-ibm-header-compat.cocci`.

### Fixed

1. requester: instance-id: Release read lock on conflict
2. pdr: Error propagation for
   pldm_entity_association_pdr_add_from_node_with_record_handle()

## [0.8.0] - 2024-05-23

### Added

1. base: Provide pldm_msg_hdr_correlate_response()
2. transport: af-mctp: Add pldm_transport_af_mctp_bind()
3. oem: ibm: Add chapdata file type support
4. base: Added PLDM_SMBIOS & PLDM_RDE message types
5. oem: meta: Add decode_oem_meta_file_io_req()
6. state-set: Add all state set values to system power state enum as per DSP0249
7. platform: Add alias members to the enum
   pldm_pdr_repository_chg_event_change_record_event_data_operation.

   enum constants with inconsistent names are deprecated with this change.
   remove old inconsistent enum members after backward compatibility cleanup is
   done

8. oem-ibm: Alias `pldm_oem_ibm_fru_field_type` members as `PLDM_OEM_IBM_*`
9. oem: ibm: Add Firmware Update Access Key(UAK) as a FRU field type
10. platform: Add 3 PDR type enum for Redfish Device Enablement per
    DSP0248_1.2.0
11. state_set: Add CONNECTED and DISCONNECTED enum for Link State set
12. entity: Add enum for Network Interface Connectors and Network Ports
    Connection Types
13. pdr: Add decode_numeric_effecter_pdr_data()
14. oem: ibm: Support for the Real SAI entity id
15. fw_update: Add encode req & decode resp for query_downstream_devices
16. fw_update: Add encode req & decode resp for query_downstream_identifiers
17. platform: Add support for GetStateEffecterStates command

### Changed

1. base: Stabilise pldm_msg_hdr_correlate_response()
2. transport: af-mctp: Stabilise pldm_transport_af_mctp_bind()
3. libpldm: Fix header use
4. libpldm: More fixes for header use
5. pdr: Stabilise pldm_pdr_find_last_in_range() API
6. pdr: Stabilise pldm_entity_association_pdr_add_from_node_with_record_handle()
7. oem: meta: stabilise decode_oem_meta_file_io_req()
8. pdr: pldm_entity_association_tree_copy_root(): Document preconditions

### Deprecated

1. Deprecate `pldm_oem_ibm_fru_field_type` members that that are not prefixed
   with `PLDM_OEM_IBM_`

### Fixed

1. libpldm: Rationalise the local and installed path of pldm.h
2. pdr: Assign record_handle in entity_association_pdr_add_children()
3. msgbuf: Require sensor data enum in pldm_msgbuf_extract_sensor_value()
4. pdr: Remove redundant constant for minimum numeric sensor PDR length
5. tests: oem: meta: Fix fileio use of msgbuf

## [0.7.0] - 2023-08-29

### Added

1. state-set: Add new enum for Operational Fault Status enum

### Changed

1. transport: Match specified metadata in pldm_transport_send_recv_msg()
2. transport: mctp-demux: Drop ABI annotation for internal symbols
3. transport: Stabilise core transport and implementation APIs

   This stabilisation covers the following headers and functions:

   - libpldm/transport.h

     - pldm_transport_poll()
     - pldm_transport_send_msg()
     - pldm_transport_recv_msg()
     - pldm_transport_send_recv_msg()

   - libpldm/transport/af-mctp.h

     - pldm_transport_af_mctp_init()
     - pldm_transport_af_mctp_destroy()
     - pldm_transport_af_mctp_core()
     - pldm_transport_af_mctp_init_pollfd()
     - pldm_transport_af_mctp_map_tid()
     - pldm_transport_af_mctp_unmap_tid()

   - libpldm/transport/mctp-demux.h
     - pldm_transport_mctp_demux_init()
     - pldm_transport_mctp_demux_destroy()
     - pldm_transport_mctp_demux_core()
     - pldm_transport_mctp_demux_init_pollfd()
     - pldm_transport_mctp_demux_map_tid()
     - pldm_transport_mctp_demux_unmap_tid()

### Deprecated

1. All the existing "requester" APIs from `libpldm/pldm.h` (also known as
   `libpldm/requester/pldm.h`):

   - pldm_open()
   - pldm_send_recv()
   - pldm_send()
   - pldm_recv()
   - pldm_recv_any()
   - pldm_close()

   Users should migrate to the newer "transport" APIs instead.

## Fixed

1. tests: Exclude transport tests when build excludes testing ABIs
2. abi: Capture deprecation of pldm_close()

## [0.6.0] - 2023-08-22

### Changed

1. pdr: Avoid ID overflow in pldm_entity_association_tree_add_entity()
2. meson: Apply `b_ndebug=if-release` by default
3. pdr : Stabilize pldm_entity_association_tree_add_entity()
4. pdr: Stabilise pldm_entity_association_tree_find_with_locality()
5. pdr: Stabilize pldm_entity_node_get_remote_container_id()
6. transport: af-mctp: Assign out-params on success in \*\_recv()
7. transport: Generalise the pldm_transport_recv_msg() API

### Removed

1. pdr: Remove pldm_entity_association_pdr_add()
2. state-set: Remove enum pldm_state_set_operational_fault_status_values

### Fixed

1. transport: register init_pollfd callback for af-mctp
2. transport: fix init_pollfd function parameter
3. transport: Fix doxygen and variables for send and recv functions
4. transport: af-mctp: Ensure malloc() succeeds in \*\_recv()

## [0.5.0] - 2023-08-09

### Added

1. pdr: Introduce pldm_entity_association_pdr_add_check()

### Changed

1. pdr: Allow record_handle to be NULL for pldm_pdr_add()
2. transport: pldm_transport_poll(): Adjust return value semantics
3. transport: free un-wanted responses in pldm_transport_send_recv_msg()

### Deprecated

1. state-set: Enum pldm_state_set_operational_fault_status_values

   The enum operational_fault_status is defined with wrong members and will
   eventually be replaced with the correct members. Any uses of
   pldm_state_set_operational_fault_status_values members should move to
   equivalent pldm_state_set_operational_stress_status_values members if needed.

2. platform: Struct field name in fru_record_set PDR

   References to entity_instance_num should be changed to entity_instance

3. platform: Struct field name in numeric sensor value PDR

   References to entity_instance_num should be changed to entity_instance

### Removed

1. bios_table: Remove pldm_bios_table_attr_entry_integer_encode_length()
2. bios_table: Remove pldm_bios_table_attr_value_entry_encode_enum()
3. bios_table: Remove pldm_bios_table_attr_value_entry_encode_string()
4. bios_table: Remove pldm_bios_table_attr_value_entry_encode_integer()
5. bios_table: Remove pldm_bios_table_append_pad_checksum()
6. fru: Remove get_fru_record_by_option()
7. pdr: Make is_present() static
8. pdr: Remove pldm_pdr_add()
9. pdr: Remove pldm_pdr_add_fru_record_set()
10. pdr: Remove pldm_entity_association_pdr_add_from_node()
11. pdr: Make find_entity_ref_in_tree() static
12. pdr: Make entity_association_tree_find() static

### Fixed

1. requester: Fix response buffer cast in pldm_send_recv()
2. pdr: Hoist record handle overflow test to avoid memory leak
3. transport: Correct comparison in while loop condition

## [0.4.0] - 2023-07-14

### Added

1. bios_table: Introduce pldm_bios_table_append_pad_checksum_check()
2. fru: Introduce get_fru_record_by_option_check()
3. pdr: Introduce pldm_entity_association_pdr_add_from_node_check()
4. pdr: Introduce pldm_pdr_add()
5. pdr: Introduce pldm_pdr_add_fru_record_set_check()

### Changed

1. requester: Mark pldm_close() as LIBPLDM_ABI_TESTING
2. requester: Expose pldm_close() in header
3. bios_table: pldm_bios_table_string_entry_encode_check(): Handle overflow
4. bios_table: pldm_bios_table_iter_create(): Return NULL on failed alloc
5. bios_table: pldm_bios_table_iter_next(): Invalid entry halts iteration
6. pdr: pldm_pdr_init(): Return NULL on allocation failure
7. pdr: pldm_pdr_destroy(): Exit early if repo is NULL
8. pdr: Document preconditions for trivial accessor functions

   A trivial accessor function is one that exposes properties of an object in a
   way can't result in an error, beyond passing an invalid argument to the
   function. For APIs meeting this definition we define a precondition that
   struct pointers must point to valid objects to avoid polluting the function
   prototypes. The following APIs now have this precondition explicitly defined:

   - pldm_entity_extract()
   - pldm_entity_get_parent()
   - pldm_entity_is_exist_parent()
   - pldm_entity_is_node_parent()
   - pldm_is_current_parent_child
   - pldm_is_empty_entity_assoc_tree()
   - pldm_pdr_get_record_count()
   - pldm_pdr_get_record_handle()
   - pldm_pdr_get_repo_size()
   - pldm_pdr_record_is_remote()

9. pdr: pldm_entity_node_get_remote_container_id() is a trivial accessor
10. pdr: pldm_pdr_fru_record_set_find_by_rsi(): Exit early on NULL arguments
11. pdr: pldm_entity_association_tree_init(): Return NULL on failed alloc
12. pdr: pldm_entity_association_tree_visit(): Document preconditions
13. pdr: pldm_entity_association_tree_visit(): Exit early on failure
14. pdr: pldm_entity_association_tree_destroy(): Exit early on bad argument
15. pdr: pldm_entity_get_num_children(): Return zero for invalid arguments
16. pdr: pldm_is_current_parent_child(): Return false for invalid arguments
17. pdr: pldm_entity_association_pdr_add(): Exit early on bad arguments
18. pdr: pldm_find_entity_ref_in_tree(): Exit early on bad arguments
19. pdr: pldm_entity_association_tree_find(): Early exit on bad arguments
20. pdr: pldm_entity_association_tree_destroy_root(): Exit early on bad arg
21. pdr: pldm_entity_association_pdr_extract(): Early exit on bad arguments
22. pdr: pldm_entity_association_pdr_extract(): Assign out params at exit
23. pdr: pldm_entity_get_num_children(): Don't return invalid values
24. libpldm: Lift or remove asserts where a subsequent check exists

### Deprecated

1. pldm_bios_table_attr_entry_integer_encode()

   Migrate to pldm_bios_table_attr_entry_integer_encode_check()

2. bios_table: Deprecate pldm_bios_table_attr_value_entry_encode_enum()

   Migrate to pldm_bios_table_attr_value_entry_encode_enum_check()

3. bios_table: Deprecate pldm_bios_table_attr_value_entry_encode_string()

   Migrate to pldm_bios_table_attr_value_entry_encode_string_check()

4. bios_table: Deprecate pldm_bios_table_attr_value_entry_encode_integer()

   Migrate to pldm_bios_table_attr_value_entry_encode_integer_check()

5. pdr: Deprecate is_present()

   There should be no users of this symbol. If you are a user, you should figure
   out how to stop, or get in touch. This symbol will be marked static the
   release after deprecation.

6. pdr: Deprecate find_entity_ref_in_tree()

   There should be no users of this symbol. If you are a user, you should figure
   out how to stop, or get in touch. This symbol will be marked static the
   release after deprecation.

7. pdr: Deprecate entity_association_tree_find()

   There should be no users of this symbol. If you are a user, you should figure
   out how to stop, or get in touch. This symbol will be marked static the
   release after deprecation.

8. bios_table: Stabilise pldm_bios_table_append_pad_checksum_check()

   pldm_bios_table_append_pad_checksum() is deprecated by this change. Users of
   pldm_bios_table_append_pad_checksum() should migrate to
   pldm_bios_table_append_pad_checksum_check()

9. fru: Stabilise get_fru_record_by_option_check()

   get_fru_record_by_option() is deprecated by this change. Users of
   get_fru_record_by_option() should migrate to get_fru_record_by_option_check()

10. pdr: Stabilise pldm_entity_association_pdr_add_from_node_check()

    pldm_entity_association_pdr_add_from_node() is deprecated by this change.
    Users of pldm_entity_association_pdr_add_from_node() should migrate to
    pldm_entity_association_pdr_add_from_node_check()

11. pdr: Stabilise pldm_pdr_add()

    pldm_pdr_add() is deprecated by this change. Users of pldm_pdr_add() should
    migrate to pldm_pdr_add()

12. pdr: Stabilise pldm_pdr_add_fru_record_set_check()

    pldm_pdr_add_fru_record_set() is deprecated by this change. Users of
    pldm_pdr_add_fru_record_set() should migrate to
    pldm_pdr_add_fru_record_set_check()

### Removed

1. bios_table: Remove deprecated APIs sanitized by assert():

   - pldm_bios_table_string_entry_encode()
   - pldm_bios_table_string_entry_decode_string()
   - pldm_bios_table_attr_entry_enum_encode()
   - pldm_bios_table_attr_entry_enum_decode_pv_num()
   - pldm_bios_table_attr_entry_enum_decode_def_num()
   - pldm_bios_table_attr_entry_enum_decode_pv_hdls()
   - pldm_bios_table_attr_entry_string_encode()
   - pldm_bios_table_attr_entry_string_decode_def_string_length()

### Fixed

1. pdr: Return success for pldm_pdr_find_child_container_id_range_exclude() API
2. pdr: Rework pldm_pdr_find_container_id_range_exclude() API
3. transport: mctp-demux: Don't test socket for non-zero value
4. requester: Return PLDM_REQUESTER_OPEN_FAIL from pldm_open() on error
5. pdr: pldm_pdr_fru_record_set_find_by_rsi(): Document reality of return
6. transport: Fix possible NULL ptr deref in pldm_socket_sndbuf_init()
7. abi: Update to remove pldm_close() from reference dumps
8. bios_table: Annotate pldm_bios_table_attr_value_entry_encode_integer()

## [0.3.0] - 2023-06-23

### Added

1. Add encode/decode pldmMessagePollEvent data
2. README: Add a section on working with libpldm
3. pdr: Introduce remote_container_id and associated APIs
4. pdr: Add APIs for creating and locating remote PDRs
5. pdr: Add pldm_pdr_find_last_in_range()
6. pdr: Add pldm_entity_association_pdr_add_from_node_with_record_handle()
7. pdr: Add pldm_pdr_find_container_id_range_exclude()

### Changed

1. include: Move installed transport.h under libpldm/
2. libpldm: Explicit deprecated, stable and testing ABI classes
3. meson: Reduce strength of oem-ibm requirements from enabled to allowed

   The `oem-ibm` feature is now enabled by the default meson configuration, for
   CI purposes. `oem-ibm` is still disabled by default in the `libpldm` bitbake
   recipe:

   <https://github.com/openbmc/openbmc/blob/master/meta-phosphor/recipes-phosphor/libpldm/libpldm_git.bb#L10>

   To disable `oem-ibm` in your development builds, pass `-Doem-ibm=disabled`
   when invoking `meson setup`

4. bios_table: Relax pldm_bios_table_string_entry_decode_string_check()
5. bios_table: Relax pldm_bios_table_attr_entry_enum_decode_pv_hdls_check()

### Deprecated

1. bios_table: Deprecate APIs with arguments sanitized using assert()

   C provides enough foot-guns without us encoding them into library APIs.
   Specifically, deprecate the following in favour of their `*_check()` variants
   which ensure assertions won't fail or otherwise invoke UB:

   - pldm_bios_table_string_entry_encode()
   - pldm_bios_table_string_entry_decode_string()
   - pldm_bios_table_attr_entry_enum_encode()
   - pldm_bios_table_attr_entry_enum_decode_pv_num()
   - pldm_bios_table_attr_entry_enum_decode_def_num()
   - pldm_bios_table_attr_entry_enum_decode_pv_hdls()
   - pldm_bios_table_attr_entry_string_encode()
   - pldm_bios_table_attr_entry_string_decode_def_string_length()

### Removed

1. libpldm: Remove the requester-api option

### Fixed

1. requester: Make pldm_open() return existing fd
2. transport: Prevent sticking in waiting for response
3. transport: Match on response in pldm_transport_send_recv_msg()
4. requester: Add check before accessing hdr in pldm_recv()
5. bios_table: pldm_bios_table_attr_entry_string_info_check() NULL deref

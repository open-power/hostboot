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

## [Unreleased]

### Added

1. Add encode/decode pldmMessagePollEvent data
2. README: Add a section on working with libpldm

### Changed

1. include: Move installed transport.h under libpldm/
2. libpldm: Explicit deprecated, stable and testing ABI classes

### Fixed

1. requester: Make pldm_open() return existing fd
2. transport: Prevent sticking in waiting for response
3. transport: Match on response in pldm_transport_send_recv_msg()

### Removed

1. libpldm: Remove the requester-api option

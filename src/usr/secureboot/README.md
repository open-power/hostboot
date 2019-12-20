# Secureboot Services in Hostboot
Hostboot provides multiple services to help secure the system and
 ensure that only 'trusted' code is running on it. The multiple sub-directories
 implement the various interfaces defined in the
 [src/include/usr/secureboot/](../../include/usr/secureboot/) directory.

## Directories
* __base__
  * The modules here define the core secureboot support: **defining and
 implementing interfaces to retrieve the security state of the system**
  * The directory is called 'base' because its contents are included in the
 Hostboot Base Image (HBB) partition
  * See [base/README.md](base/README.md) for more details

* __common__
  * The modules here provide common support like tracing, error callouts,
 definitions of the secure "container" header, etc, that is used by the
 secureboot modules in the peer directories
  * See [common/README.md](common/README.md) for more details

* __ext__
  * The modules here provide some additional secureboot capabilities that are
 beyond the core secureboot functionality found in the "base" directory
  * This directory is called 'ext' because its contents are included in the
 Hostboot Extended Image (HBI)
  * Any module here can call into the Hostboot Base Image (ie the 'base' code
 in the HBB partition)), but Hostboot Base Image modules cannot call into
 these extended image modules
  * See [ext/README.md](ext/README.md) for more details

* __node_comm__
  * The modules here implement a node-to-node communication protocol that is
 used on multinode systems to share secureboot data between the nodes
  * See [node_comm/README.md](node_comm/README.md) for more details

* __runtime__
  * The modules here implement a small subset of secureboot code that is used by
 Hostboot runtime services.
  * See [runtime/README.md](runtime/README.md) for more details

* __smf__
  * The modules here distribute different amounts of Secure SMF memory between
 the available processors on the system based on a user-configurable petitboot
 setting
  * The SMF memory amount will be passed from the FSP to Hostboot using
 attributes for FSP-based systems
  * The SMF memory amount will be set with the PLDM BIOS attribute for
 eBMC-based systems
  * See [smf/README.md](smf/README.md) for more details

* __trusted__
  * The modules here define the trusted boot support which uses TPMs (Trusted
 Platform Modules) to track what code is running on the system
  * See [trusted/README.md](trusted/README.md) for more details

## Other Files
* __HBconfig__
  * Standard HBconfig file that defines secureboot- and trustedboot-related
 Hostboot compile variables

* __makefile__
  * Standard Hostboot makefile

* __[README.md](./README.md)__
  * This file


/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
#ifndef OEM_IBM_FRU_H
#define OEM_IBM_FRU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

enum pldm_oem_ibm_fru_field_type {
	PLDM_OEM_FRU_FIELD_TYPE_IANA = 0x01,
	PLDM_OEM_FRU_FIELD_TYPE_RT = 0x02,
	PLDM_OEM_FRU_FIELD_TYPE_PCIE_CONFIG_SPACE_DATA = 0xfd,
	PLDM_OEM_FRU_FIELD_TYPE_LOCATION_CODE = 0xfe,

	PLDM_OEM_IBM_FRU_FIELD_TYPE_IANA = 0x01,
	PLDM_OEM_IBM_FRU_FIELD_TYPE_RT = 0x02,
	PLDM_OEM_IBM_FRU_FIELD_TYPE_FIRMWARE_UAK = 0xfc,
	PLDM_OEM_IBM_FRU_FIELD_TYPE_PCIE_CONFIG_SPACE_DATA = 0xfd,
	PLDM_OEM_IBM_FRU_FIELD_TYPE_LOCATION_CODE = 0xfe,
};

#ifdef __cplusplus
}
#endif

#endif /* OEM_IBM_FRU_H */

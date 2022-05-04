# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/ebmc/hwasCallout.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2022
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

""" The following dictionaries are from values and enums in
"src/include/usr/hwas/common/hwasCallout.H"
Any changes made there should be made here too.

These dictionaries are used by parsers in b0100.py
"""

calloutType = {        "HW_CALLOUT":  0x01,
                "PROCEDURE_CALLOUT":  0x02,
                      "BUS_CALLOUT":  0x03,
                    "CLOCK_CALLOUT":  0x04,
                     "PART_CALLOUT":  0x05,
                   "SENSOR_CALLOUT":  0x06,
               "I2C_DEVICE_CALLOUT":  0x07,
                      "VRM_CALLOUT":  0x08 }

DeconfigEnum    = { 0: "NO_DECONFIG",
                    1: "DECONFIG",
                    2: "DELAYED_DECONFIG" }

GARD_ErrorType  = { 0x00: "GARD_NULL",
                    0xD2: "GARD_User_Manual",
                    0xE2: "GARD_Unrecoverable",
                    0xE3: "GARD_Fatal",
                    0xE6: "GARD_Predictive",
                    0xE9: "GARD_Power",
                    0xEA: "GARD_PHYP",
                    0xEB: "GARD_Reconfig",
                    0xEC: "GARD_Sticky_deconfig",
                    0xFF: "GARD_Void" }

epubProcedureID = { 0x00: "EPUB_PRC_NONE",
                    0x01: "EPUB_PRC_FIND_DECONFIGURED_PART",
                    0x04: "EPUB_PRC_SP_CODE",
                    0x05: "EPUB_PRC_PHYP_CODE",
                    0x08: "EPUB_PRC_ALL_PROCS",
                    0x09: "EPUB_PRC_ALL_MEMCRDS",
                    0x0A: "EPUB_PRC_INVALID_PART",
                    0x10: "EPUB_PRC_LVL_SUPP",
                    0x11: "EPUB_PRC_SUE_PREVERROR",
                    0x16: "EPUB_PRC_PROCPATH",
                    0x1C: "EPUB_PRC_NO_VPD_FOR_FRU",
                    0x22: "EPUB_PRC_MEMORY_PLUGGING_ERROR",
                    0x2D: "EPUB_PRC_FSI_PATH",
                    0x30: "EPUB_PRC_PROC_AB_BUS",
                    0x31: "EPUB_PRC_PROC_XYZ_BUS",
                    0x34: "EPUB_PRC_MEMBUS_ERROR",
                    0x37: "EPUB_PRC_EIBUS_ERROR",
                    0x3F: "EPUB_PRC_POWER_ERROR",
                    0x4D: "EPUB_PRC_PERFORMANCE_DEGRADED",
                    0x4F: "EPUB_PRC_MEMORY_UE",
                    0x55: "EPUB_PRC_HB_CODE",
                    0x56: "EPUB_PRC_TOD_CLOCK_ERR",
                    0x5C: "EPUB_PRC_COOLING_SYSTEM_ERR",
                    0x5D: "EPUB_PRC_FW_VERIFICATION_ERR",
                    0x5E: "EPUB_PRC_GPU_ISOLATION_PROCEDURE",
                    0x61: "EPUB_PRC_NVDIMM_ERR" }

callOutPriority = { 0: "SRCI_PRIORITY_NONE",
                    1: "SRCI_PRIORITY_LOW",
                    2: "SRCI_PRIORITY_MEDC",
                    3: "SRCI_PRIORITY_MEDB",
                    4: "SRCI_PRIORITY_MEDA",
                    5: "SRCI_PRIORITY_MED",
                    6: "SRCI_PRIORITY_HIGH" }

busTypeEnum     = { 1: "FSI_BUS_TYPE",
                    3: "A_BUS_TYPE",
                    4: "X_BUS_TYPE",
                    5: "I2C_BUS_TYPE",
                    6: "PSI_BUS_TYPE",
                    7: "O_BUS_TYPE",
                    8: "OMI_BUS_TYPE",
                    0xFF: "DMI_BUS_TYPE" }

clockTypeEnum   = { 1: "TODCLK_TYPE",
                    2: "MEMCLK_TYPE",
                    3: "OSCREFCLK_TYPE",
                    4: "OSCPCICLK_TYP",
                    8: "OSCREFCLK0_TYPE",
                    9: "OSCREFCLK1_TYPE",
                    10: "OSCPCICLK0_TYPE",
                    11: "OSCPCICLK1_TYPE" }

voltageTypeEnum = { 0: "VDD",
                    1: "VCS",
                    2: "VDN",
                    3: "VIO" }

partTypeEnum    = { 0: "NO_PART_TYPE",
                    1: "FLASH_CONTROLLER_PART_TYPE",
                    2: "PNOR_PART_TYPE",
                    3: "SBE_SEEPROM_PART_TYPE",
                    4: "VPD_PART_TYPE",
                    5: "LPC_SLAVE_PART_TYPE",
                    6: "GPIO_EXPANDER_PART_TYPE",
                    7: "SPIVID_SLAVE_PART_TYPE",
                    8: "TOD_CLOCK",
                    9: "MEM_REF_CLOCK",
                    10: "PROC_REF_CLOCK",
                    11: "PCI_REF_CLOCK",
                    12: "SMP_CABLE",
                    13: "BPM_CABLE_PART_TYPE",
                    14: "NV_CONTROLLER_PART_TYPE",
                    15: "BPM_PART_TYPE",
                    16: "SPI_DUMP_PART_TYPE" }

sensorTypeEnum  = { 0: "UNKNOWN_SENSOR",
                    1: "GPU_FUNC_SENSOR",
                    2: "GPU_TEMPERATURE_SENSOR",
                    3: "GPU_MEMORY_TEMP_SENSOR" }

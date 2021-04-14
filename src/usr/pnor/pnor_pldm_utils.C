/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_pldm_utils.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/* Local includes */
#include "pnor_pldm_utils.H"

/* Misc Userspace Module Includes */
#include <trace/interface.H>

/* PLDM Subtree Includes */
#include <openbmc/pldm/oem/ibm/libpldm/file_io.h>
extern trace_desc_t* g_trac_pnor;

/**
 * @file pnor_pldm_utils.C
 *
 * @brief File containing the source code for translating between
 *        PLDM-isms and legacy PNOR-isms. The initial inspiriation
 *        for this file was to have a home for the code translating
 *        virtual addresses to ipl-time lid is, but any other
 *        utilities for pnor/pldm interactions can be put in here.
 */

namespace PLDM_PNOR
{

    uint32_t vaddrToLidId(const uint64_t i_vaddr,
                              uint32_t &o_offset)
    {
        // i_vaddr is an offset into the PNOR_RP VMM space.
        // Ensure i_vaddr does not exceed the end of PNOR_RP VMM space.
        assert(i_vaddr <= VMM_VADDR_PNOR_RP_MAX_SIZE,
               "Address we are trying to lookup not in PNOR VMM range");
        // Set the offset output parameter
        o_offset = i_vaddr % VMM_SIZE_RESERVED_PER_SECTION;
        // Lookup the section ID by calculating the section offset,
        // VMM sections are allocated matching the
        // order of the SectionId enum defined in pnor_const.H
        return getipl_lid_ids()[static_cast<PNOR::SectionId>(i_vaddr / VMM_SIZE_RESERVED_PER_SECTION)];
    }

  errlHndl_t getFileTableLidsMockup(std::vector<uint8_t> & o_fileTable)
  {
      using namespace PLDM_PNOR;
      const size_t LID_COUNT = 25;
      const size_t LID_NAME_LEN = 8;
      errlHndl_t errl = nullptr;

      struct lid_nst {
        char     lid_name[LID_NAME_LEN];
        uint32_t lid_size;
        uint32_t lid_traits;
      } __attribute__((packed));

      const size_t lid_entry_size = sizeof(pldm_file_attr_table_entry) -
                              sizeof(pldm_file_attr_table_entry().file_attr_table_nst) +
                              sizeof(lid_nst);
      o_fileTable.clear();
      o_fileTable.resize(lid_entry_size * LID_COUNT);

      struct entry_data {
        uint32_t entry_lid_handle;
        lid_nst  entry_lid_nst;
      };
      auto ipltime_lid_ids = getipl_lid_ids ();

      const entry_data lid_entry_data[] = {
#ifndef BOOTLOADER
        {
            ipltime_lid_ids[PNOR::HB_EXT_CODE],
            {
                {'8', '1', 'E', '0', '0', '6', '5', 'D'},
                htole32(0xFFF000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
#endif
        {
            ipltime_lid_ids[PNOR::HB_BASE_CODE],
            {
                {'8', '1', 'E', '0', '0', '6', '5', 'A'},
                htole32(0x100000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
#ifndef BOOTLOADER
        {
            ipltime_lid_ids[PNOR::SBE_IPL],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '1'},
                htole32(0xBC000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::HCODE],
            {
                {'8', '1', 'E', '0', '0', '6', '9', '6'},
                htole32(0x120000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::PAYLOAD],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '0'},
                htole32(0x80000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::HB_RUNTIME],
            {
                {'8', '1', 'E', '0', '0', '6', '8', 'e'},
                htole32(0x800000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::HB_DATA],
            {
                {'8', '1', 'E', '0', '0', '6', '8', 'D'},
                htole32(0x200000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::GUARD_DATA],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '7'},
                htole32(0x5000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::HB_ERRLOGS],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '8'},
                htole32(0x20000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::NVRAM],
            {
                {'8', '1', 'E', '0', '0', '6', '6', 'B'},
                htole32(0x90000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::OCC],
            {
                {'8', '1', 'E', '0', '0', '6', '8', '8'},
                htole32(0x120000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::ATTR_TMP],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '4'},
                htole32(0x8000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::ATTR_PERM],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '3'},
                htole32(0x8000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::VERSION],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '2'},
                htole32(0x2000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::HB_BOOTLOADER],
            {
                {'8', '1', 'E', '0', '0', '6', '5', 'B'},
                htole32(0xB000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::RINGOVD],
            {
                {'8', '1', 'E', '0', '0', '6', '2', '0'},
                htole32(0x20000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::WOFDATA],
            {
                {'8', '1', 'E', '0', '0', '6', '9', '2'},
                htole32(0x300000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::SBKT],
            {
                {'8', '1', 'E', '0', '0', '6', '6', 'C'},
                htole32(0x4000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::HB_VOLATILE],
            {
                {'8', '1', 'E', '0', '0', '6', '6', 'F'},
                htole32(0x5000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
        {
            ipltime_lid_ids[PNOR::HDAT],
            {
                {'8', '1', 'E', '0', '0', '6', '6', '9'},
                htole32(0x8000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::EECACHE],
            {
                {'8', '1', 'E', '0', '0', '6', '7', '9'},
                htole32(0x2C0000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
#ifdef CONFIG_DEVTREE
        {
            ipltime_lid_ids[PNOR::DEVTREE],
            {
                {'8', '1', 'E', '0', '0', '6', '7', '2'},
                htole32(0x100000),
                htole32(TraitBitMap::READ_WRITE)
            }
        },
#endif
#ifdef CONFIG_LOAD_PHYP_FROM_BOOTKERNEL
        {
            ipltime_lid_ids[PNOR::BOOTKERNEL],
            {
                {'8', '1', 'E', '0', '0', '6', '5', '8'},
                htole32(0xFFF000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
#endif
        {
            ipltime_lid_ids[PNOR::HCODE_LID],
            {
                {'8', '1', 'E', '0', '0', '6', '7', '1'},
                htole32(0x120000),
                htole32(TraitBitMap::READ_ONLY)
            }
        },
        {
            ipltime_lid_ids[PNOR::OCMBFW],
            {
                {'8', '1', 'E', '0', '0', '6', '7', 'A'},
                htole32(0x123000),
                htole32(TraitBitMap::READ_ONLY)
            }
        }
#endif
      };

      // We will walk the byte vector in the loop below filling it as we go
      auto start_ptr = o_fileTable.data();

      for (size_t i = 0; i < sizeof(lid_entry_data)/sizeof(entry_data); i++)
      {
          auto file_table_entry =
            reinterpret_cast<pldm_file_attr_table_entry *>(start_ptr + (i*lid_entry_size));
          auto data_table_entry = lid_entry_data[i];
          file_table_entry->file_handle = htole32(data_table_entry.entry_lid_handle);
          file_table_entry->file_name_length = htole16(LID_NAME_LEN);
          memcpy(file_table_entry->file_attr_table_nst, &data_table_entry.entry_lid_nst, sizeof(lid_nst));
      }

      return errl;
  }
}

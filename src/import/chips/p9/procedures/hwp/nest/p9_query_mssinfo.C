/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_query_mssinfo.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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


//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi2.H>
#include <string>
#include <vector>
#include <p9_query_mssinfo.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
class cage_node
{
    public:
        uint32_t nodeNum;
        uint32_t cageNum;
        uint32_t slotNum;
};


fapi2::ReturnCode p9_query_mssinfo(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> i_vect_pu_targets,
                                   bool i_ignore_ready_check)
{
    fapi2::ReturnCode l_rc;
    uint32_t vect_idx;

    //vars for node and total system sizes
    cage_node curCageNode, puCageNode;
    std::vector<uint64_t> nodeMemSize;
    std::vector<cage_node> nodeNum;
    uint64_t totalSysMem = 0;
    curCageNode.cageNum = 999;
    curCageNode.nodeNum = 999;
    curCageNode.slotNum = 999;
    uint64_t curNodeSize = 0;

    //vars for attrs
    uint64_t sizes[8];
    uint64_t bases[8];
    uint64_t mirror_sizes[4] = {0, 0, 0, 0};
    uint64_t mirror_bases[4];
    uint32_t groupID[MBA_GROUP_SIZE][MBA_GROUP_DATA];
    uint64_t nhtm_base;
    uint64_t nhtm_size;
    uint64_t chtm_bases[24];
    uint64_t chtm_sizes[24];
    uint64_t occ_base;
    uint64_t occ_size;
    uint8_t  mirror_policy;
    uint8_t  l_mirrorEnabled;
    char     chipid[200];
    char l_target_string[fapi2::MAX_ECMD_STRING_LEN];


    const int ONE_GIG = 30;


    //loop over all elements in the vector
    for(uint32_t i = 0; i < i_vect_pu_targets.size(); i++)
    {
        if (!i_ignore_ready_check)
        {
            uint8_t l_mem_ipl_complete;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_IPL_COMPLETE, i_vect_pu_targets[i], l_mem_ipl_complete),
                     "Error from FAPI_ATTR_GET (ATTR_MSS_MEM_IPL_COMPLETE)");
            FAPI_ASSERT(l_mem_ipl_complete,
                        fapi2::P9_QUERY_MSSINFO_NOT_READY_ERR().set_TARGET(i_vect_pu_targets[i]),
                        "IPL IS NOT COMPLETE. Unable to determine final memory sizes and addreses!");
        }

        fapi2::toString(i_vect_pu_targets[i], l_target_string, fapi2::MAX_ECMD_STRING_LEN );   //change to ecmd string
        sprintf(chipid, "%s", l_target_string);
        int x = 0;
        puCageNode.cageNum = 0;
        puCageNode.nodeNum = 0;
        puCageNode.slotNum = 0;

        while(chipid[x] != 'k' && chipid[x] != '\0')
        {
            x++;
        }

        if(chipid[x] == 'k')
        {
            x++;
        }

        while(chipid[x] != '\0')
        {
            if(chipid[x] == ':')
            {
                break;
            }

            puCageNode.cageNum = puCageNode.cageNum * 10 + chipid[x] - '0';
            x++;
        }

        while(chipid[x] != 'n' && chipid[x] != '\0')
        {
            x++;
        }

        if(chipid[x] == 'n')
        {
            x++;
        }

        while(chipid[x] != '\0')
        {
            if(chipid[x] == ':')
            {
                break;
            }

            puCageNode.nodeNum = puCageNode.nodeNum * 10 + chipid[x] - '0';
            x++;
        }

        while(chipid[x] != 's' && chipid[x] != '\0')
        {
            x++;
        }

        if(chipid[x] == 's')
        {
            x++;
        }

        while(chipid[x] != '\0')
        {
            if(chipid[x] == ':')
            {
                break;
            }

            puCageNode.slotNum = puCageNode.slotNum * 10 + chipid[x] - '0';
            x++;
        }


        if( (curCageNode.cageNum != 999) && (curCageNode.cageNum != puCageNode.cageNum &&
                                             curCageNode.nodeNum != puCageNode.nodeNum ) )
        {
            nodeMemSize.push_back(curNodeSize);
            nodeNum.push_back(curCageNode);
            curNodeSize = 0;
        }

        //set current node
        curCageNode = puCageNode;

        //------------------------------------------------------------------------------------------------------------------------
        //  Here is where you use the targets to do some get attributes and print out whatever croquery msinfo need to
        //------------------------------------------------------------------------------------------------------------------------
        // ATTR_PROC_MEM_SIZES
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_SIZES, i_vect_pu_targets[i], sizes),
                 "Error reading ATTR_PROC_MEM_SIZES, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // ATTR_PROC_MEM_BASES
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_BASES, i_vect_pu_targets[i], bases),
                 "Error reading ATTR_PROC_MEM_BASES, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // ATTR_MSS_MCS_GROUP_32
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MCS_GROUP_32, i_vect_pu_targets[i], groupID),
                 "Error reading ATTR_MSS_MCS_GROUP_32, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        //Mirrored memory attributes read if enabled
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_HW_MIRRORING_ENABLE,
                               i_vect_pu_targets[i].getParent<fapi2::TARGET_TYPE_SYSTEM>(), l_mirrorEnabled),
                 "Error reading ATTR_MRW_HW_MIRRORING_ENABLE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_DBG("p9_query_mssinfo: Current l_mirrorEnabled=%u!\n", l_mirrorEnabled);

        if (l_mirrorEnabled == 1)
        {
            // ATTR_PROC_MIRROR_SIZES
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_SIZES, i_vect_pu_targets[i], mirror_sizes),
                     "Error reading ATTR_PROC_MIRROR_SIZES, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // retrieve mirroring placement policy attribute
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY,
                                   i_vect_pu_targets[i].getParent<fapi2::TARGET_TYPE_SYSTEM>(), mirror_policy),
                     "Error reading ATTR_MEM_MIRROR_PLACEMENT_POLICY, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            FAPI_DBG("p9_query_mssinfo: Current mirror_policy=%u!\n", mirror_policy);

            // ATTR_PROC_MIRROR_BASES
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_BASES, i_vect_pu_targets[i], mirror_bases),
                     "Error reading ATTR_PROC_MIRROR_BASES, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }


        bool any_mem = false;

        for (int j = 0; (j < 8) && !any_mem; j++)
        {
            if (groupID[j][2] != 0)
            {
                any_mem = true;
            }
        }

        for (int j = 0; (j < 4) && !any_mem; j++)
        {
            if (groupID[8 + j][2] != 0)
            {
                any_mem = true;
            }
        }


        //------------------------------------------------------------------------------------------------------------------------
        // Print out per group information
        //------------------------------------------------------------------------------------------------------------------------
        if (any_mem)
        {
            printf("\n%s\n", chipid);

            for(int j = 0; j < 8; j++)
            {
                if ((sizes[j] != 0) ||
                    ((j < 4) && (mirror_sizes[j] != 0)))
                {
                    printf("Group:%d (", j);

                    for(uint8_t jj = 4; jj < 4 + groupID[j][1]; jj++)
                    {
                        printf(" mcs%d", groupID[j][jj]);
                    }

                    printf(" )\n");
                }

                if (sizes[j] != 0)
                {
                    curNodeSize += (sizes[j] >> ONE_GIG);
#ifdef _LP64
                    printf("  Base Address = 0x%016lx  Size = %ld (GB)\n", bases[j], sizes[j] >> ONE_GIG);
#else
                    printf("  Base Address = 0x%016llx  Size = %lld (GB)\n", bases[j], sizes[j] >> ONE_GIG);
#endif
                }


                if ((j < 4) && (mirror_sizes[j] != 0))
                {
#ifdef _LP64
                    printf("  Mirror Base Address = 0x%016lx  Size = %ld (GB)\n", mirror_bases[j], mirror_sizes[j] >> ONE_GIG);
#else
                    printf("  Mirror Base Address = 0x%016llx  Size = %lld (GB)\n", mirror_bases[j], mirror_sizes[j] >> ONE_GIG);
#endif
                }

            }
        }

        //------------------------------------------------------------------------------------------------------------------------
        // Print out memory reservations
        //------------------------------------------------------------------------------------------------------------------------
        if(((mirror_policy == fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL ) ||
            (mirror_policy == fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)    ) && (l_mirrorEnabled == 1) )
        {
            // ATTR_PROC_NHTM_BAR_BASE_ADDR: Get Nest Hardware Trace Macro (NHTM) bar base addr
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NHTM_BAR_BASE_ADDR, i_vect_pu_targets[i], nhtm_base),
                     "Error reading ATTR_PROC_NHTM_BAR_BASE_ADDR, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ATTR_PROC_NHTM_BAR_SIZE: Get Nest Hardware Trace Macro (NHTM) bar size
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NHTM_BAR_SIZE, i_vect_pu_targets[i], nhtm_size),
                     "Error reading ATTR_PROC_NHTM_BAR_SIZE, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ATTR_PROC_CHTM_BAR_BASE_ADDR: Get Nest Hardware Trace Macro (CHTM) bar base addr array
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_CHTM_BAR_BASE_ADDR, i_vect_pu_targets[i], chtm_bases),
                     "Error reading ATTR_PROC_CHTM_BAR_BASE_ADDR, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ATTR_PROC_CHTM_BAR_SIZES: Get Core Hardware Trace Macro (CHTM) bar size array
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_CHTM_BAR_SIZES, i_vect_pu_targets[i], chtm_sizes),
                     "Error reading ATTR_PROC_CHTM_BAR_SIZES, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ATTR_PROC_OCC_SANDBOX_BASE_ADDR
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_OCC_SANDBOX_BASE_ADDR, i_vect_pu_targets[i], occ_base),
                     "Error reading ATTR_PROC_OCC_SANDBOX_BASE_ADDR, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ATTR_PROC_OCC_SANDBOX_SIZE
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_OCC_SANDBOX_SIZE, i_vect_pu_targets[i], occ_size),
                     "Error reading ATTR_PROC_OCC_SANDBOX_SIZE, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            uint64_t  chtm_total_size = 0;

            for (uint8_t i = 0; i < CHTM_REGIONS; i++)
            {
                chtm_total_size += chtm_sizes[i];
            }

            if ((nhtm_size != 0) ||
                (chtm_total_size != 0) ||
                (occ_size != 0))
            {
                printf("\n");
            }

            if (occ_size != 0)
            {
                std::string suffix = "B";

                if (occ_size >= (1024 * 1024 * 1024))
                {
                    suffix = "GB";
                    occ_size /= (1024 * 1024 * 1024);
                }
                else if (occ_size >= (1024 * 1024))
                {
                    suffix = "MB";
                    occ_size /= (1024 * 1024);
                }
                else if (occ_size >= (1024))
                {
                    suffix = "KB";
                    occ_size /= (1024);
                }

#ifdef _LP64
                printf("OCC Base Address = 0x%016lx  Size = %ld (%s)\n", occ_base, occ_size, suffix.c_str());
#else
                printf("OCC Base Address = 0x%016llx  Size = %lld (%s)\n", occ_base, occ_size, suffix.c_str());
#endif
            }

            if (nhtm_size != 0)
            {
                std::string suffix = "B";

                if (nhtm_size >= (1024 * 1024 * 1024))
                {
                    suffix = "GB";
                    nhtm_size /= (1024 * 1024 * 1024);
                }
                else if (nhtm_size >= (1024 * 1024))
                {
                    suffix = "MB";
                    nhtm_size /= (1024 * 1024);
                }
                else if (nhtm_size >= (1024))
                {
                    suffix = "KB";
                    nhtm_size /= (1024);
                }

#ifdef _LP64
                printf("NHTM Base Address = 0x%016lx  Size = %ld (%s)\n", nhtm_base, nhtm_size, suffix.c_str());
#else
                printf("NHTM Base Address = 0x%016llx  Size = %lld (%s)\n", nhtm_base, nhtm_size, suffix.c_str());
#endif
            }

            if (chtm_total_size != 0)
            {
                for (uint8_t i = 0; i < CHTM_REGIONS; i++)
                {
                    std::string suffix = "B";

                    if (chtm_sizes[i] >= (1024 * 1024 * 1024))
                    {
                        suffix = "GB";
                        chtm_sizes[i] /= (1024 * 1024 * 1024);
                    }
                    else if (chtm_sizes[i] >= (1024 * 1024))
                    {
                        suffix = "MB";
                        chtm_sizes[i] /= (1024 * 1024);
                    }
                    else if (chtm_sizes[i] >= (1024))
                    {
                        suffix = "KB";
                        chtm_sizes[i] /= (1024);
                    }

#ifdef _LP64
                    printf("CHTM Base Address = 0x%016lx  Size = %ld (%s)\n", chtm_bases[i], chtm_sizes[i], suffix.c_str());
#else
                    printf("CHTM Base Address = 0x%016llx  Size = %lld (%s)\n", chtm_bases[i], chtm_sizes[i], suffix.c_str());
#endif
                }
            }

        }

        //------------------------------------------------------------------------------------------------------------------------

    }//end for loop over target vector


    //need to push the last node onto the vector
    if(curCageNode.cageNum != 999)
    {
        nodeMemSize.push_back(curNodeSize);
        nodeNum.push_back(curCageNode);
    }



    //------------------------------------------------------------------------------------------------------------------
    // Print out node and total system memory
    //------------------------------------------------------------------------------------------------------------------
    printf("\n");

    for(vect_idx = 0; vect_idx < nodeNum.size(); vect_idx++)
    {
#ifdef _LP64
        printf("TOTAL NODE k%d:n%d MEMORY(GB): %ld\n", nodeNum[vect_idx].cageNum,
#else
        printf("TOTAL NODE k%d:n%d MEMORY(GB): %lld\n", nodeNum[vect_idx].cageNum,
#endif
               nodeNum[vect_idx].nodeNum, nodeMemSize[vect_idx]);
        totalSysMem = totalSysMem + nodeMemSize[vect_idx];
    }

    /* Print total system memory */
#ifdef _LP64
    printf("TOTAL SYSTEM MEMORY(GB): %ld\n\n", totalSysMem);
#else
    printf("TOTAL SYSTEM MEMORY(GB): %lld\n\n", totalSysMem);
#endif
    //------------------------------------------------------------------------------------------------------------------


fapi_try_exit:
    FAPI_DBG("Exiting p9_query_mssinfo");
    return fapi2::current_err;
}

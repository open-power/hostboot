/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/rtloader/loader.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
#ifndef __TESTCORE_RTLOADER_LOADER_H
#define __TESTCORE_RTLOADER_LOADER_H


#include <util/align.H>
#include <sys/mm.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/attrrp.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlmanager.H>
#include <util/utillidmgr.H>
#include <map>
#include <sys/time.h>
#include <runtime/interface.h>
#include <vpd/vpd_if.H>
#include <pnor/pnorif.H>
#include <string.h>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <pnor/ecc.H>
#include <ipmi/ipmiif.H>
#include <targeting/common/attributeTank.H>
#include <util/utilrsvdmem.H>
#include <sys/misc.h>
#include <errno.h>
#include <isteps/mem_utils.H>


trace_desc_t* g_trac_hbrt = NULL;
TRAC_INIT(&g_trac_hbrt, "HBRT_TEST", 12*KILOBYTE);


class RuntimeLoaderTest : public CxxTest::TestSuite
{
public:
        // =====================================================================
        // testLoader
        // =====================================================================
        void testLoader()
        {
            static const uint64_t HEADER_OFFSET = 0x2000;
            errlHndl_t l_errl = nullptr;

#ifdef CONFIG_SECUREBOOT
            l_errl = loadSecureSection(PNOR::HB_RUNTIME);
            if(l_errl)
            {
                TS_WARN("Could not securely load runtime section.");
                delete l_errl;
                l_errl = nullptr;
                return;
            }
#endif
            PNOR::SectionInfo_t runtimeSection;

            l_errl = PNOR::getSectionInfo(PNOR::HB_RUNTIME, runtimeSection);

            if (l_errl)
            {
                TS_WARN("Could not find runtime section.");
                delete l_errl;
                return;
            }

            if (runtimeSection.size < HEADER_OFFSET)
            {
                TS_FAIL("Runtime image is not big enough. %x",
                        runtimeSection.size);
                return;
            }

            uint64_t imageSize =
                *reinterpret_cast<uint64_t*>(runtimeSection.vaddr +
                                             HEADER_OFFSET);
            if (runtimeSection.size < imageSize + sizeof(uint64_t))
            {
                TS_FAIL("Image header has too big a size: %x, %x",
                        runtimeSection.size, imageSize);
                return;
            }

            uint64_t relocations =
                *reinterpret_cast<uint64_t*>(runtimeSection.vaddr + imageSize);
            imageSize += (relocations + 1) * sizeof(uint64_t);

            if (runtimeSection.size < imageSize)
            {
                TS_FAIL("Image header + relocations is too big: %x, %x, %d",
                        runtimeSection.size, imageSize, relocations);
                return;
            }

            void* imageArea = malloc(ALIGN_PAGE(imageSize));
            memcpy(imageArea, reinterpret_cast<void*>(runtimeSection.vaddr),
                   imageSize);
            mm_icache_invalidate(imageArea,
                   ALIGN_PAGE(imageSize) / sizeof(uint64_t));


            mm_set_permission(imageArea, HEADER_OFFSET, EXECUTABLE);

            TRACFCOMP(g_trac_hbrt, "Runtime image loaded @ %x", imageArea);

            do
            {
                hostInterfaces_t* intf = new hostInterfaces_t();
                intf->interfaceVersion = HOSTBOOT_RUNTIME_INTERFACE_VERSION;
                intf->puts = rt_puts;
                intf->set_page_execute = rt_setPageExecute;
                intf->malloc = malloc;
                intf->free = free;
                intf->realloc = realloc;
                intf->assert = rt_assert;
                intf->sendErrorLog = rt_logErr;
                intf->scom_read = rt_scom_read;
                intf->scom_write = rt_scom_write;
                intf->lid_load = rt_lid_load;
                intf->lid_unload = rt_lid_unload;
                intf->get_reserved_mem = rt_get_reserved_mem;
                intf->pnor_read = rt_pnor_read;
                intf->pnor_write= rt_pnor_write;
                intf->ipmi_msg= rt_ipmi_msg;
                intf->clock_gettime = clock_gettime;
                intf->hcode_scom_update = rt_hcode_update;
                intf->firmware_request = rt_firmware_request;

                // Call init.
                runtimeInterfaces_t* rtInterface =
                    reinterpret_cast<runtimeInterfaces_t*>(
                        callViaCtr(
                            reinterpret_cast<uint64_t>(imageArea) + 0x100,
                            intf, NULL)
                        );
                if (NULL == rtInterface)
                {
                    TS_FAIL("Failed to init runtime services.");
                    break;
                }

                {
                    using namespace CxxTest;

                    // Initialize statistics structure.
                    CxxTestStats cxxTestStats =
                        { &g_TotalTests, &g_TraceCalls, &g_Warnings,
                          &g_FailedTests, &g_ModulesStarted,
                          &g_ModulesCompleted };

                    // Call CxxTest entry.
                    (*rtInterface->cxxtestExecute)(&cxxTestStats);
                }

            } while(0);

            mm_set_permission(imageArea, imageSize, WRITABLE);
            free(imageArea);

#ifdef CONFIG_SECUREBOOT
            l_errl = unloadSecureSection(PNOR::HB_RUNTIME);
            if(l_errl)
            {
                TS_FAIL("Could not securely load runtime section.");
                delete l_errl;
                l_errl = nullptr;
                return;
            }
#endif

        }  // end testLoader

    private:
        // =====================================================================
        // tearDown
        // =====================================================================
        void tearDown()
        {
            if (cv_hb_data_addr != 0)
            {
                // unmap virtual memory
                TRACFCOMP(g_trac_hbrt,
                          "tearDown(): unmap hb_data virt addr %p",
                       reinterpret_cast<void*>(cv_hb_data_addr));

                int l_rc = mm_block_unmap(
                                reinterpret_cast<void*>(cv_hb_data_addr));
                if(l_rc)
                {
                    TRACFCOMP( g_trac_hbrt,
                       "tearDown(): failed to unmap virt addr %p",
                       reinterpret_cast<void*>(cv_hb_data_addr));
                }
                else
                {
                    cv_hb_data_addr = 0;
                }
            }
            else
            {
                TRACFCOMP( g_trac_hbrt,
                           "tearDown(): skipping unmap hb_data virt addr");
            }
        }  // end tearDown

        // =====================================================================
        // callViaCtr
        // =====================================================================
        uint64_t callViaCtr(uint64_t entry, void* param0, void* param1)
        {
            register uint64_t result = 0;

            asm volatile("mtctr %1; mr 3, %2 ; mr 4, %3; "
                         "std 2, 40(1); bctrl; ld 2, 40(1); "
                         "mr %0, 3" :
                "=r" (result) : "r" (entry), "r" (param0), "r" (param1) :
                "lr","ctr","cr0","r0","r3","r4","r5","r6","r7","r8","r9",
                "r10","r11"); // TODO: Need to double check the ABI here.

            return result;
        }  // end callViaCtr

        // =====================================================================
        // rt_puts
        // =====================================================================
        static void rt_puts(const char* str)
        {
            TRACFCOMP(g_trac_hbrt, "HBRT TRACE: %s", str);
        }

        // =====================================================================
        // rt_setPageExecute
        // =====================================================================
        static int rt_setPageExecute(void* addr)
        {
            return mm_set_permission(addr, PAGESIZE, EXECUTABLE);
        }

        // =====================================================================
        // rt_assert
        // =====================================================================
        static void rt_assert()
        {
            assert(false);
        }

        // =====================================================================
        // rt_scom_read
        // =====================================================================
        static int rt_scom_read(uint64_t chipid,
                                 uint64_t addr,
                                 void* data)
        {
            int rc = 0;

            TRACFCOMP(g_trac_hbrt,
                      "Scom read chipid: 0x%08x Address: 0x%08x",
                      chipid,
                      addr);

            uint64_t * data64 = static_cast<uint64_t *>(data);

            SCOM_KEY scomKey(chipid,addr);
            SCOM_MAP::iterator it = cv_scomMap.find(scomKey);

            if(it != cv_scomMap.end())
            {
                *data64 = it->second;
            }
            else
            {
                *data64 = 0;
            }

            // Fail on these addresses
            // On real HW they would cause an error
            // The test that sends these expects an error
            if( addr == 0x11223344 ||
                addr == 0x22334455 )
            {
                rc = HBRT_RC_PIBERR_100_INVALIDADDR;
            }

            return rc;
        }  // end rt_scom_read

        // =====================================================================
        // rt_scom_write
        // =====================================================================
        static int rt_scom_write(uint64_t chipid,
                                  uint64_t addr,
                                  void* data)
        {
            int rc = 0;

            uint64_t * data64 = static_cast<uint64_t *>(data);

            TRACFCOMP(g_trac_hbrt,
                      "Scom write chipid:0x%.8x Address:0x%08x Data:0x%16x",
                      chipid,
                      addr,
                      *data64);

            SCOM_KEY scomKey(chipid,addr);
            cv_scomMap[scomKey] = *data64;

            // Fail on these addresses
            // On real HW they would cause an error
            // The test that sends these expects an error
            if( addr == 0x11223344 ||
                addr == 0x22334455 )
            {
                rc = 1;
            }

            return rc;
        }  // end rt_scom_write

        // =====================================================================
        // rt_logErr
        // =====================================================================
        static int rt_logErr(uint32_t plid,
                             uint32_t data_len,
                             void * data)
        {
            uint64_t rc = 0;
            TRACFCOMP(g_trac_hbrt,
                      "Log error. Plid: %d  len: %d",
                      plid,
                      data_len);

            TRACDBIN(g_trac_hbrt, "RUNTIME ERROR LOG:",data,data_len);


            errlHndl_t err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        0,0);
            rc = err->unflatten(data, data_len);

            errlCommit(err,CXXTEST_COMP_ID);

            return rc;
        }  // end rt_logErr

        // =====================================================================
        // rt_lid_load
        // =====================================================================
        static int rt_lid_load(uint32_t lid, void** buffer, size_t* size)
        {
            errlHndl_t l_errl = NULL;
            UtilLidMgr* lidmgr = new UtilLidMgr(lid);

            do
            {
                l_errl = lidmgr->getLidSize(*size);
                if (l_errl) break;

                *buffer = malloc(*size);
                l_errl = lidmgr->getLid(*buffer, *size);
                if (l_errl) break;

            } while(0);

            if (l_errl)
            {
                free(*buffer);
                *buffer = NULL;
                *size = 0;

                delete l_errl;
                delete lidmgr;
                return -1;
            }
            else
            {
                cv_loadedLids[*buffer] = lidmgr;
                return 0;
            }
        }  // end rt_lid_load

        // =====================================================================
        // rt_lid_unload
        // =====================================================================
        static int rt_lid_unload(void* buffer)
        {
            UtilLidMgr* lidmgr = cv_loadedLids[buffer];
            if (NULL == lidmgr) return -1;

            cv_loadedLids.erase(buffer);
            free(buffer);
            delete lidmgr;
            return 0;
        }

        // =====================================================================
        // rt_get_reserved_mem
        // =====================================================================
        static uint64_t rt_get_reserved_mem(const char* i_region,
                                            uint32_t i_instance)
        {
            if (0 == strcmp(i_region, HBRT_RSVD_MEM__SBE_COMM))
                return rt_get_comm(i_instance);
            else if (0 == strcmp(i_region, HBRT_RSVD_MEM__DATA))
                return rt_get_hb_data(i_instance);
            else
                return 0;
        }

        // =====================================================================
        // rt_get_hb_data
        // =====================================================================
        static uint64_t rt_get_hb_data(uint32_t i_instance)
        {
            TRACFCOMP( g_trac_hbrt,
                       ENTER_MRK"rt_get_hb_data> i_instance=%d", i_instance );

            uint64_t l_totalSize = 0;
            uint64_t l_vAddr = 0;

            if (cv_hb_data_addr != 0)
            {
                TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_get_hb_data: "
                    "stored cv_hb_data_addr: 0x%.16llX",  cv_hb_data_addr);
                return cv_hb_data_addr;
            }

            uint64_t l_physical_addr = cpu_spr_value(CPU_SPR_HRMOR) +
                                        VMM_HB_DATA_TOC_START_OFFSET;

            TRACFCOMP(g_trac_hbrt, "rt_get_hb_data: "
                "mapping physical address:0x%.16llX", l_physical_addr);

            // Map to the virtual address to access data
            l_vAddr = reinterpret_cast<uint64_t>(mm_block_map(
                    reinterpret_cast<void*>(l_physical_addr),
                    sizeof(Util::hbrtTableOfContents_t)));

            TRACFCOMP(g_trac_hbrt, "rt_get_hb_data: mapped "
                "physical address 0x%.16llX -> virtual address 0x%.16llX",
                l_physical_addr, l_vAddr);

            // check that map worked
            assert(l_vAddr != 0,"rt_get_hb_data. Could not map HB DATA memory");

            // find the total size
            Util::hbrtTableOfContents_t * toc_ptr =
                    reinterpret_cast<Util::hbrtTableOfContents_t *>(l_vAddr);
            l_totalSize = toc_ptr->total_size;
            TRACFCOMP(g_trac_hbrt, "rt_get_hb_data: "
                          "total_size for HB Data = %lld", l_totalSize);

            // unmap
            int l_rc = mm_block_unmap(reinterpret_cast<void*>(l_vAddr));
            if(l_rc)
            {
                TRACFCOMP( g_trac_hbrt,
                   "rt_get_hb_data. fail to unmap virt addr %p",
                   reinterpret_cast<void*>(l_vAddr));
                assert(false, "rt_get_hb_data. failed to unmap virt addr");
            }

            // Map to the virtual address to access ALL data
            cv_hb_data_addr = reinterpret_cast<uint64_t>(mm_block_map(
                    reinterpret_cast<void*>(l_physical_addr), l_totalSize));

            TRACFCOMP(g_trac_hbrt, "rt_get_hb_data: "
              "mapped physical address:0x%.16llX -> virtual address 0x%.16llX",
              l_physical_addr, cv_hb_data_addr);

            // check that map worked
            assert(cv_hb_data_addr != 0,
                "rt_get_hb_data. Could not map entire HB DATA memory");

            TRACFCOMP( g_trac_hbrt,
                       EXIT_MRK"rt_get_hb_data> i_instance=%d, addr: 0x%.16llX",
                       i_instance, cv_hb_data_addr);

            return cv_hb_data_addr;
        } // end rt_get_hb_data

        // =====================================================================
        // find_sectionId
        // =====================================================================
        static PNOR::SectionId find_sectionId (const char* i_partitionName)
        {
            PNOR::SectionId l_id = PNOR::INVALID_SECTION;
            for (size_t i=PNOR::FIRST_SECTION; i<=PNOR::NUM_SECTIONS;
                    ++i)
            {
                if (0 == strcmp(PNOR::SectionIdToString(i), i_partitionName))
                {
                    l_id = (PNOR::SectionId)i;
                    break;
                }
            }
            return l_id;
        }  // end find_sectionId

        // =====================================================================
        // rt_pnor_read
        // =====================================================================
        static int rt_pnor_read (uint32_t i_proc, const char* i_partitionName,
                   uint64_t i_offset, void* o_data, size_t i_sizeBytes)
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK"rt_pnor_read: proc:%d, part:%s,"
                    " offset:0x%X, dataPtr:0x%X, size:0x%X",i_proc,
                    i_partitionName, i_offset, o_data, i_sizeBytes);

            PNOR::SectionId l_id = PNOR::INVALID_SECTION;
            PNOR::SectionInfo_t l_info;
            errlHndl_t l_err = NULL;

            do
            {
                TARGETING::Target* pnor_target =
                    TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

                //search cv_EYECATCHER for partitionname
                l_id = find_sectionId(i_partitionName);
                if (l_id == PNOR::INVALID_SECTION)
                {
                    TRACFCOMP(g_trac_hbrt, "rt_pnor_read: Invalid Section");
                    break;
                }

                //getSectionInfo -- this is PnorRP::getSectionInfo
                l_err = PNOR::getSectionInfo(l_id, l_info);
                if (l_err)
                {
                    TRACFCOMP(g_trac_hbrt,
                              "rt_pnor_read: getSectionInfo errored");
                    break;
                }

                // read far enough in the section so it doesn't collide
                // with other test cases
                size_t l_bytes_to_read = i_sizeBytes;
                if (l_id == PNOR::TEST)
                {
                    //adjust the size of data if we are reading the entire sec
                    l_bytes_to_read = (i_offset == 0)? (((l_info.size -
                             PNOR::pnorTestSec_rt_readwrite_offset)*9)/8) :
                             i_sizeBytes;
                    i_offset = ((PNOR::pnorTestSec_rt_readwrite_offset*9)/8);
                }

                uint32_t l_flashAddr= l_info.flashAddr + i_offset;

                TRACFCOMP(g_trac_hbrt,"rt_pnor_read: calling"
                        " deviceRead: offset:0x%X, flashAddr:0x%X, size:0x%X",
                        i_offset, l_flashAddr, l_bytes_to_read);

                l_err = DeviceFW::deviceRead (pnor_target, o_data,
                                     l_bytes_to_read,
                                     DEVICE_PNOR_ADDRESS(i_proc, l_flashAddr));
                if (l_err)
                {
                    TRACFCOMP(g_trac_hbrt, "rt_pnor_read: deviceRead errored");
                    break;
                }
            } while (0);

            //by default tell the caller we read everything they asked for
            int rc = i_sizeBytes;

            //commit the error
            if (l_err)
            {
                errlCommit(l_err,CXXTEST_COMP_ID);
                rc = -1;
            }
            TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_pnor_read");
            return rc;
        } // end rt_pnor_read

        // =====================================================================
        // rt_pnor_write
        // =====================================================================
        static int rt_pnor_write(uint32_t i_proc, const char* i_partitionName,
                   uint64_t i_offset, void* i_data, size_t i_sizeBytes)
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK"rt_pnor_write: proc:%d, part:%s,"
                    " offset:0x%X, dataPtr:0x%X, size:0x%X",i_proc,
                    i_partitionName, i_offset, i_data, i_sizeBytes);

            PNOR::SectionId     l_id = PNOR::INVALID_SECTION;
            PNOR::SectionInfo_t l_info;
            errlHndl_t          l_err = NULL;
            do {

                TARGETING::Target* pnor_target =
                    TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

                //search cv_EYECATCHER for partitionname
                l_id = find_sectionId(i_partitionName);
                if (l_id == PNOR::INVALID_SECTION)
                {
                    TRACFCOMP(g_trac_hbrt, "rt_pnor_write: Invalid section");
                    break;
                }

                //getSectionInfo - this is PnorRP::getSectionInfo
                l_err = PNOR::getSectionInfo(l_id, l_info);
                if (l_err)
                {
                    TRACFCOMP(g_trac_hbrt,
                              "rt_pnor_write: getSectionInfo errored");
                    break;
                }

                //fix the offset for the TEST section so that the testcases
                //don't collide
                i_offset = (l_id==PNOR::TEST) ? (i_offset+
                       ((PNOR::pnorTestSec_rt_readwrite_offset*9)/8)):i_offset;

                uint32_t l_flashAddr = l_info.flashAddr + i_offset;

                TRACFCOMP(g_trac_hbrt,"rt_pnor_write: calling"
                        " deviceWrite: offset:0x%X, flashAddr:0x%X, size:0x%X",
                        i_offset, l_flashAddr, i_sizeBytes);

                l_err = DeviceFW::deviceWrite (pnor_target, i_data, i_sizeBytes,
                                      DEVICE_PNOR_ADDRESS(i_proc, l_flashAddr));
                if (l_err)
                {
                    TRACFCOMP(g_trac_hbrt,
                              "rt_pnor_write: deviceWrite errored");
                    break;
                }
            } while (0);

            //commit the error
            int rc = i_sizeBytes;
            if (l_err)
            {
                errlCommit (l_err, CXXTEST_COMP_ID);
                rc = -1;
            }
            TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_pnor_write");
            return rc;
        } // end rt_pnor_write

        // =====================================================================
        // rt_get_comm
        // =====================================================================
        static uint64_t rt_get_comm(uint32_t i_instance)
        {
            if (cv_comm_addr != 0)
            {
                TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_get_comm: "
                          "stored cv_comm_addr:%lld",
                          cv_comm_addr);
                return cv_comm_addr;
            }

            TARGETING::TargetHandleList procChips;
            getAllChips(procChips, TARGETING::TYPE_PROC, true);
            for (const auto & l_procChip: procChips)
            {
                uint64_t l_instance =
                    l_procChip->getAttr<TARGETING::ATTR_HBRT_HYP_ID>();
                if(l_instance == i_instance)
                {
                    cv_comm_addr =
                        l_procChip->getAttr<TARGETING::ATTR_SBE_COMM_ADDR>();
                    if (cv_comm_addr != 0)
                    {
                        TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_get_comm: "
                                  "retrieved attribute cv_comm_addr:%lld",
                                  cv_comm_addr);
                        return cv_comm_addr;
                    }
                }
            }

            cv_comm_phys_addr = ISTEP::get_top_mem_addr();

            assert (cv_comm_phys_addr != 0,
                    "rt_get_comm: Top of memory was 0!");

            // Just picking 64K inside VMM_ATTR_DATA as it is available for HDAT
            cv_comm_phys_addr -= (VMM_ALL_HOMER_OCC_MEMORY_SIZE + 64*KILOBYTE);

            uint8_t *comm_ptr = reinterpret_cast<uint8_t *>(cv_comm_phys_addr);

            void *cptr = mm_block_map(comm_ptr, PAGESIZE);

            assert(cptr != NULL,"rt_get_comm. Could not map SBE Comm memory");

            cv_comm_addr = reinterpret_cast<uint64_t>(cptr);

            TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_get_comm: "
                      "calculated cv_comm_addr:%lld",
                      cv_comm_addr);
            return cv_comm_addr;
        } // end rt_get_comm

        // =====================================================================
        // rt_ipmi_msg
        // =====================================================================
        static int rt_ipmi_msg(uint8_t netfn, uint8_t cmd,
                    void *tx_buf, size_t tx_size,
                    void *rx_buf, size_t *rx_size)
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK
                "rt_ipmi_msg: tx_buf:%x/%x, size:%d, rx_buf:%p, size:%d",
                    netfn, cmd, tx_size,
                    rx_buf, *rx_size);

            errlHndl_t l_err = NULL;
            do {
                ((uint8_t*)rx_buf)[0] = IPMI::CC_OK;
                rx_size = 0;
            } while (0);

            //commit the error
            uint32_t  l_plid = 0;
            if (l_err)
            {
                l_plid = l_err->plid();
                errlCommit (l_err, CXXTEST_COMP_ID);
            }
            TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_ipmi_msg");
            return l_plid;
        } // end rt_ipmi_msg

        // =====================================================================
        // rt_hcode_update
        // =====================================================================
        static int rt_hcode_update( uint64_t i_chipId,
                                    uint32_t i_section,
                                    uint32_t i_operation,
                                    uint64_t i_scomAddr,
                                    uint64_t i_scomData )
        {
            TRACFCOMP(g_trac_hbrt,
                      "Loading runtime hcode_update: "
                      "target 0x%llX chipId 0x%llX section 0x%X "
                      "operation 0x%X scomAddr 0x%llX scomData 0x%llX",
                      i_chipId, i_section, i_operation, i_scomAddr, i_scomData);
            return 0;
        }

        // =====================================================================
        // rt_firmware_request
        // =====================================================================
        static int rt_firmware_request(uint64_t  i_reqLen,  void *i_req,
                                       uint64_t* o_respLen, void *o_resp  )
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK"rt_firmware_request: "
                      "request length:%d, request ptr:%p, "
                      "response length:%d, response ptr:%p",
                      i_reqLen, i_req, *o_respLen, o_resp );

            if ( (i_req == nullptr)     ||
                 (o_respLen == nullptr) ||
                 (o_resp == nullptr) )
            {
                TS_FAIL("rt_firmware_request: FAILED: Received bad input - "
                        "either request message, response length "
                        "or response message is NULL")

                return -EINVAL;
            }

            if ( (*o_respLen != i_reqLen)  &&
                 (*o_respLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                              sizeof(hostInterfaces::hbrt_fw_msg)))  )
            {
                TS_FAIL("rt_firmware_request: FAILED: Response length(%d) "
                        "needs to be at a minimum(%d), or equal to "
                        "request length(%d)",
                        *o_respLen,
                        (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                              sizeof(hostInterfaces::hbrt_fw_msg)),
                        i_reqLen);

                return -EINVAL;
            }

            size_t retVal = 0;

            do
            {
                // Cast the input to the type of data that it is
                hostInterfaces::hbrt_fw_msg* l_req_fw_msg =
                         reinterpret_cast<hostInterfaces::hbrt_fw_msg*>(i_req);
                hostInterfaces::hbrt_fw_msg* l_resp_fw_msg =
                         reinterpret_cast<hostInterfaces::hbrt_fw_msg*>(o_resp);

                if (hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE
                                              == l_req_fw_msg->io_type)
                {
                    retVal = testFirmwareRequestHcodeUpdate(i_reqLen,
                                                            l_req_fw_msg,
                                                            *o_respLen,
                                                            l_resp_fw_msg );
                }
                else if (hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG
                                              == l_req_fw_msg->io_type)
                {
                    retVal = testFirmwareRequestErrLogToFsp(i_reqLen,
                                                         l_req_fw_msg,
                                                         *o_respLen,
                                                         l_resp_fw_msg );
                }
                else if (hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ
                                                   == l_req_fw_msg->io_type)
                {
                    if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                    sizeof(l_req_fw_msg->generic_msg)))
                    {
                        TS_FAIL("rt_firmware_request: FAILED: Generic FSP "
                                "Message' response length(%d) needs to be "
                                "at a minimum(%d)",
                                *o_respLen,
                                (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                 sizeof(l_req_fw_msg->generic_msg)) );

                        retVal = -EINVAL;
                        break;
                    }

                    TRACDCOMP(g_trac_hbrt,
                              "rt_firmware_request: Generic FSP Message' "
                              "Request data set 1/2: "
                              "type:%d, magic:0x%.8X, dataSize:%d, "
                              "structVer:0x%.8X, seqnum:%d, msgq:0x%.8X",
                              l_req_fw_msg->io_type,
                              l_req_fw_msg->generic_msg.magic,
                              l_req_fw_msg->generic_msg.dataSize,
                              l_req_fw_msg->generic_msg.structVer,
                              l_req_fw_msg->generic_msg.seqnum,
                              l_req_fw_msg->generic_msg.msgq);

                    TRACDCOMP(g_trac_hbrt,
                              "rt_firmware_request: Generic FSP Message' "
                              "Request data set 2/2: "
                              "msgType:0x%.8X, __req:%d, "
                              "__onlyError:%d, data:0x%.8X",
                              l_req_fw_msg->generic_msg.msgType,
                              l_req_fw_msg->generic_msg.__req,
                              l_req_fw_msg->generic_msg.__onlyError,
                              l_req_fw_msg->generic_msg.data);

                    // Simulate response message from FSP
                    l_resp_fw_msg->io_type =
                                     hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP;
                    l_resp_fw_msg->generic_msg.magic =
                                         GenericFspMboxMessage_t::MAGIC_NUMBER;
                    l_resp_fw_msg->generic_msg.structVer =
                                           l_req_fw_msg->generic_msg.structVer;
                    l_resp_fw_msg->generic_msg.seqnum =
                                          l_req_fw_msg->generic_msg.seqnum + 1;
                    l_resp_fw_msg->generic_msg.msgq =
                                                l_req_fw_msg->generic_msg.msgq;
                    l_resp_fw_msg->generic_msg.msgType =
                                             l_req_fw_msg->generic_msg.msgType;
                    l_resp_fw_msg->generic_msg.__req =
                                             GenericFspMboxMessage_t::RESPONSE;
                    l_resp_fw_msg->generic_msg.__onlyError =
                                       GenericFspMboxMessage_t::NOT_ERROR_ONLY;

                    // Check the individual message types
                    switch (l_req_fw_msg->generic_msg.msgType)
                    {
                        case GenericFspMboxMessage_t::MSG_SINGLE_SCOM_OP:
                        {
                            testFirmwareRequestSingleScomOperation(i_reqLen,
                                                             l_req_fw_msg,
                                                             *o_respLen,
                                                             l_resp_fw_msg);
                            break;
                        }
                        case GenericFspMboxMessage_t::MSG_MULTI_SCOM_OP:
                        {
                            testFirmwareRequestMultipleScomOperation(i_reqLen,
                                                             l_req_fw_msg,
                                                             *o_respLen,
                                                             l_resp_fw_msg);
                            break;
                        }
                        case GenericFspMboxMessage_t::MSG_ATTR_WRITE_OP:
                        {
                            testFirmwareRequestSendAttributes(i_reqLen,
                                                             l_req_fw_msg,
                                                             *o_respLen,
                                                             l_resp_fw_msg);
                            break;
                        }
                        case GenericFspMboxMessage_t::MSG_SBE_ERROR:
                        {
                            retVal = testFirmwareRequestSbeRetry(i_reqLen,
                                                             l_req_fw_msg,
                                                             *o_respLen,
                                                             l_resp_fw_msg);
                             break;
                        }

                        default:
                        {
                            TS_FAIL("rt_firmware_request: FAILED: Generic FSP "
                                    "unrecognized test request, type(0x%X). "
                                    "Need to add a test case for this "
                                    "generic FSP firmware request type",
                                    l_req_fw_msg->generic_msg.msgType);
                            break;
                        }
                    }  // end switch (l_req_fw_msg->generic_msg.msgType)

                    TRACDCOMP(g_trac_hbrt,
                              "rt_firmware_request: Generic FSP Message' "
                              "Response data set 1/2: "
                              "type:%d, magic:0x%.8X, dataSize:%d, "
                              "structVer:0x%.8X, seqnum:%d, msgq:0x%.8X",
                              l_resp_fw_msg->io_type,
                              l_resp_fw_msg->generic_msg.magic,
                              l_resp_fw_msg->generic_msg.dataSize,
                              l_resp_fw_msg->generic_msg.structVer,
                              l_resp_fw_msg->generic_msg.seqnum,
                              l_resp_fw_msg->generic_msg.msgq);

                    TRACDCOMP(g_trac_hbrt,
                              "rt_firmware_request: Generic FSP Message' "
                              "Response data set 2/2: "
                              "msgType:0x%.8X, __req:%d, __onlyError:%d, "
                              "data:0x%.8X",
                              l_resp_fw_msg->generic_msg.msgType,
                              l_resp_fw_msg->generic_msg.__req,
                              l_resp_fw_msg->generic_msg.__onlyError,
                              l_resp_fw_msg->generic_msg.data);

                }  // end else if (hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ
                else
                {
                    TS_FAIL("rt_firmware_request: FAILED: "
                            "unrecognized test request, type(0x%X).  Need to "
                            "add a test case for this firmware request type",
                            l_req_fw_msg->io_type);
               }
            } while (0) ;

            TRACFCOMP(g_trac_hbrt, EXIT_MRK"rt_firmware_request: returning %d",
                      retVal );

            return retVal;
        }  // end static int rt_firmware_request ...

        /// Firmware Request Test Helper Functions
        // =====================================================================
        // testFirmwareRequestSbeRetry
        // =====================================================================
        static size_t testFirmwareRequestSbeRetry(
                                   uint64_t i_reqLen,
                                   hostInterfaces::hbrt_fw_msg* i_req_fw_msg,
                                   uint64_t i_respLen,
                                   hostInterfaces::hbrt_fw_msg* i_resp_fw_msg )
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK
                 "rt_firmware_request::testFirmwareRequestSbeRetry");

            struct
            {
                uint32_t plid;
                uint32_t huid;
            } l_resp_data;

            i_resp_fw_msg->generic_msg.dataSize =
                        sizeof(i_resp_fw_msg->generic_msg);

            l_resp_data.plid = 0x60;
            l_resp_data.huid = 0x70;
            memcpy(&(i_resp_fw_msg->generic_msg.data),
                   &(l_resp_data),
                   sizeof(i_resp_fw_msg->generic_msg.data));

            TRACFCOMP(g_trac_hbrt, EXIT_MRK
                 "rt_firmware_request::testFirmwareRequestSbeRetry");

            return 5;
        } // end testFirmwareRequestSbeRetry

        // =====================================================================
        // testFirmwareRequestSingleScomOperation
        // =====================================================================
        static void testFirmwareRequestSingleScomOperation(
                                   uint64_t i_reqLen,
                                   hostInterfaces::hbrt_fw_msg* i_req_fw_msg,
                                   uint64_t i_respLen,
                                   hostInterfaces::hbrt_fw_msg* i_resp_fw_msg )
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK
                 "rt_firmware_request::testFirmwareRequestSingleScomOperation");

            // Simple map of SCOM addresses to values, this ignores
            // the target (or huid).
            static std::map<uint64_t, uint64_t> l_scomCache;

            // Used to give unique, spoofed SCOM values
            static uint64_t l_fakeVal = 0x11;

            SingleScomOpHbrtFspData_t* l_req_fspData =
                   reinterpret_cast<SingleScomOpHbrtFspData_t*>
                          (&(i_req_fw_msg->generic_msg.data));

            SingleScomOpHbrtFspData_t* l_resp_fspData =
                   reinterpret_cast<SingleScomOpHbrtFspData_t*>
                          (&(i_resp_fw_msg->generic_msg.data));

            i_resp_fw_msg->generic_msg.dataSize =
                           GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE +
                           sizeof(SingleScomOpHbrtFspData_t);

            auto l_scomAddr = l_req_fspData->scom_addr;
            auto targ = l_scomCache.find(l_scomAddr);
            if (targ == l_scomCache.end()) // need to create
            {                              // a cache entry
                l_scomCache[l_scomAddr] = l_fakeVal++;
            }

            l_resp_fspData->scom_op   = l_req_fspData->scom_op;
            l_resp_fspData->huid      = l_req_fspData->huid;
            l_resp_fspData->scom_addr = l_req_fspData->scom_addr;

            if (l_resp_fspData->scom_op == DeviceFW::WRITE)
            {
              l_scomCache[l_scomAddr] =
                                      l_req_fspData->scom_data;
            }
            l_resp_fspData->scom_data = l_scomCache[l_scomAddr];

            TRACFCOMP(g_trac_hbrt, EXIT_MRK
                 "rt_firmware_request::testFirmwareRequestSingleScomOperation");
        }  // end testFirmwareRequestSingleScomOperation

        // =====================================================================
        // testFirmwareRequestMultipleScomOperation
        // =====================================================================
        static void testFirmwareRequestMultipleScomOperation(
                                   uint64_t i_reqLen,
                                   hostInterfaces::hbrt_fw_msg* i_req_fw_msg,
                                   uint64_t i_respLen,
                                   hostInterfaces::hbrt_fw_msg* i_resp_fw_msg )
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK
              "rt_firmware_request::testFirmwareRequestMultipleScomOperation");

            // Simple map of SCOM addresses to values, this ignores
            // the target (or huid).
            static std::map<uint64_t, uint64_t> l_scomCache;

            // Used to give unique, spoofed SCOM values
            static uint64_t l_fakeVal = 0x11;

            MultiScomReadHbrtFspData_t* l_req_fspData =
                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                          (&(i_req_fw_msg->generic_msg.data));
            MultiScomReadHbrtFspData_t* l_resp_fspData =
                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                          (&(i_resp_fw_msg->generic_msg.data));

            i_resp_fw_msg->generic_msg.dataSize =
                   GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE +
                   sizeof(MultiScomReadHbrtFspData_t) +
            ((l_req_fspData->scom_num - 1) * sizeof(uint64_t));

            auto l_scomAddrs =
                    static_cast<uint64_t *>
                                 (&l_req_fspData->scom_data);
            auto l_scomData =
                    static_cast<uint64_t *>
                                 (&l_resp_fspData->scom_data);

            l_resp_fspData->huid      = l_req_fspData->huid;
            l_resp_fspData->scom_num  = l_req_fspData->scom_num;
            for (int i = 0;i < l_resp_fspData->scom_num;++i)
            {
                auto targ = l_scomCache.find(l_scomAddrs[i]);
                if (targ == l_scomCache.end()) // need to create
                {                              // a cache entry
                    l_scomCache[l_scomAddrs[i]] = l_fakeVal++;
                }
                l_scomData[i] = l_scomCache[l_scomAddrs[i]];
            }

            TRACFCOMP(g_trac_hbrt, EXIT_MRK
              "rt_firmware_request::testFirmwareRequestMultipleScomOperation");
        }  // end testFirmwareRequestMultipleScomOperation

        // =====================================================================
        // testFirmwareRequestSendAttributes
        // =====================================================================
        static void testFirmwareRequestSendAttributes(
                                   uint64_t i_reqLen,
                                   hostInterfaces::hbrt_fw_msg* i_req_fw_msg,
                                   uint64_t i_respLen,
                                   hostInterfaces::hbrt_fw_msg* i_resp_fw_msg )
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK
                     "rt_firmware_request::testFirmwareRequestSendAttributes");

            uint32_t l_dataSize = i_reqLen -
                                  ( hostInterfaces::HBRT_FW_MSG_BASE_SIZE   +
                                    sizeof(i_req_fw_msg->generic_msg.data)  +
                                    sizeof(AttributeSetter_t) );

            if (l_dataSize < 0)
            {
                TS_FAIL("rt_firmware_request::"
                        "testFirmwareRequestSendAttributes: FAILED: "
                        "Size of the AttributeSetter_t data is "
                        "negative(%d)", l_dataSize);
                return;
            }

            // Get a handle to the AttributeSetter_t
            AttributeSetter_t* l_attributeSetter =
                               reinterpret_cast<AttributeSetter_t*>
                                            (&(i_req_fw_msg->generic_msg.data));

            // Get a handle to the Attributes Data
            uint8_t* l_attributeData = reinterpret_cast<uint8_t*>
                                              (l_attributeSetter->iv_attrData);

            // Create some Attributes to populate with serialized data and
            // compare to expected values
            TARGETING::AttributeTank::Attribute l_sentAttribute,
                                                l_expectedAttribute;
            uint32_t l_deserializedDataSize(0);

            // Create a buffer to be used to test against
            uint32_t l_bufferSize(3);
            uint8_t l_buffer[l_bufferSize];

            // Populate buffer with known values
            l_buffer[0] = 0xAA;
            l_buffer[1] = 0xBB;
            l_buffer[2] = 0xCC;

            // Iterate thru the attributes and compare to expected values
            for (uint16_t i = 0; i < l_attributeSetter->iv_numAttributes; ++i)
            {
                // Deserialize the data, if possible
                l_deserializedDataSize = l_sentAttribute.deserialize
                                                  (l_attributeData, l_dataSize);

                if (!l_deserializedDataSize)
                {
                    TS_FAIL("rt_firmware_request::"
                            "testFirmwareRequestSendAttributes: FAILED: "
                            "deserialization of attribute failed")
                    return;
                }

                if (0 == i)
                {
                    // Verify first deserialized Attribute
                    if (!compareAttributeHeader(&l_sentAttribute,
                                                &l_expectedAttribute))
                    {
                        TS_FAIL("rt_firmware_request::"
                                "testFirmwareRequestSendAttributes: "
                                "Test 1 FAILED: sent Attribute does not match "
                                "expected Values");
                    }

                    // Prep for next test
                    l_expectedAttribute.setId(0x1001);
                    l_expectedAttribute.setTargetType(0x2002);
                    l_expectedAttribute.setPosition(0x3003);
                    l_expectedAttribute.setUnitPosition(0x4);
                    l_expectedAttribute.setNode(0x5);
                    l_expectedAttribute.setFlags(0x6);
                }  // end if (0 == i)
                else if (1 == i)
                {
                    // Verify second deserialized Attribute
                    if (!compareAttributeHeader(&l_sentAttribute,
                                                &l_expectedAttribute))
                    {
                        TS_FAIL("rt_firmware_request::"
                                "testFirmwareRequestSendAttributes: "
                                "Test 2 FAILED: sent Attribute does not match "
                                "expected Values");
                    }

                    // Prep for next test
                    l_expectedAttribute.setValue(l_buffer, 1);
                } // end else if (1 == i)
                else if (2 == i)
                {
                    // Verify third deserialized Attribute
                    if (!compareAttributeHeader(&l_sentAttribute,
                                                &l_expectedAttribute))
                    {
                        TS_FAIL("rt_firmware_request::"
                                "testFirmwareRequestSendAttributes: "
                                "Test 3 FAILED: sent Attribute does not match "
                                "expected Values");
                    }

                    if (!compareAttributeValues(&l_sentAttribute,
                                                &l_expectedAttribute))
                    {
                        TS_FAIL("rt_firmware_request::"
                                "testFirmwareRequestSendAttributes: "
                                "Test 3 FAILED: sent Attribute Values does not "
                                "match expected Values");
                    }

                    // Prep for next test
                    l_buffer[0] = 0xDD;
                    l_expectedAttribute.setValue(l_buffer, l_bufferSize);
                } // end else if (2 == i)
                else if (3 == i)
                {
                    // Verify fourth deserialized Attribute
                    if (!compareAttributeHeader(&l_sentAttribute,
                                                &l_expectedAttribute))
                    {
                        TS_FAIL("rt_firmware_request::"
                                "testFirmwareRequestSendAttributes: "
                                "Test 4 FAILED: sent Attribute does not match "
                                "expected Values");
                    }

                    if (!compareAttributeValues(&l_sentAttribute,
                                                &l_expectedAttribute))
                    {
                        TS_FAIL("rt_firmware_request::"
                                "testFirmwareRequestSendAttributes: "
                                "Test 4 FAILED: sent Attribute Values does not "
                                "match expected Values");
                    }
                } // end else if (3 == i)

                // Decrement/increment our counters/pointers
                l_dataSize -= l_deserializedDataSize;
                l_attributeData += l_deserializedDataSize;

            }  // end for (uint16_t i = 0; ...

            TRACFCOMP(g_trac_hbrt, EXIT_MRK
                     "rt_firmware_request::testFirmwareRequestSendAttributes");
        } // end testFirmwareRequestSendAttributes

        // =====================================================================
        // testFirmwareRequestErrLogToFsp
        // =====================================================================
        static size_t testFirmwareRequestErrLogToFsp(
                                   uint64_t i_reqLen,
                                   hostInterfaces::hbrt_fw_msg* i_req_fw_msg,
                                   uint64_t i_respLen,
                                   hostInterfaces::hbrt_fw_msg* i_resp_fw_msg )

        {

            TRACFCOMP(g_trac_hbrt, ENTER_MRK
                      "rt_firmware_request::testFirmwareRequestErrLogToFsp");

            if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                            sizeof(i_req_fw_msg->error_log)))
            {
                TS_FAIL("rt_firmware_request::testFirmwareRequestErrLogToFsp: "
                        "FAILED: Request length(%d) needs to be at a "
                        "minimum(%d)",
                        i_reqLen,
                        (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                          sizeof(i_req_fw_msg->error_log)) );
                return -EINVAL;
            }

            if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                    sizeof(i_req_fw_msg->error_log) +
                    i_req_fw_msg->error_log.i_errlSize - 1))
            {
                TS_FAIL("rt_firmware_request::testFirmwareRequestErrLogToFsp: "
                        "FAILED: Request length(%d) needs to be at a "
                        "minimum(%d)",
                         i_reqLen,
                         (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                          sizeof(i_req_fw_msg->error_log) +
                          i_req_fw_msg->error_log.i_errlSize - 1) );
                return -EINVAL;
            }

            if ( (0x300 != i_req_fw_msg->error_log.i_plid)     ||
                 (    1 != i_req_fw_msg->error_log.i_errlSize) ||
                 ( 0xAA != i_req_fw_msg->error_log.i_data) )
            {
                TS_FAIL("rt_firmware_request::testFirmwareRequestErrLogToFsp: "
                        "FAILED: Loader received incorrect data: type:%d, "
                        "plid:0x%08x, size:%d, data:0x%02x",
                        i_req_fw_msg->io_type,
                        i_req_fw_msg->error_log.i_plid,
                        i_req_fw_msg->error_log.i_errlSize,
                        i_req_fw_msg->error_log.i_data);
            }

            i_resp_fw_msg->io_type =
                                 hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC;

            // dummy return value for testing
            i_resp_fw_msg->resp_generic.o_status = 20;

            TRACFCOMP(g_trac_hbrt, EXIT_MRK
                      "rt_firmware_request::testFirmwareRequestErrLogToFsp");

            // just return 0 for testing
            return 0;
        } // end testFirmwareRequestErrLogToFsp

        // =====================================================================
        // testFirmwareRequestHcodeUpdate
        // =====================================================================
        static size_t testFirmwareRequestHcodeUpdate(
                                   uint64_t i_reqLen,
                                   hostInterfaces::hbrt_fw_msg* i_req_fw_msg,
                                   uint64_t i_respLen,
                                   hostInterfaces::hbrt_fw_msg* i_resp_fw_msg )
        {
            TRACFCOMP(g_trac_hbrt, ENTER_MRK
                      "rt_firmware_request::testFirmwareRequestHcodeUpdate");

            if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                            sizeof(i_req_fw_msg->req_hcode_update)))
            {
                TRACFCOMP(g_trac_hbrt, ENTER_MRK"rt_firmware_request::"
                          "testFirmwareRequestHcodeUpdate: FAILED: Request "
                          "length(%d) needs to be at a minimum(%d)",
                          i_reqLen,
                          (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                           sizeof(i_req_fw_msg->req_hcode_update)) );
                return -EINVAL;
            }

            if ( (0x100 != i_req_fw_msg->req_hcode_update.i_chipId)     ||
                 (   20 != i_req_fw_msg->req_hcode_update.i_section)    ||
                 (   30 != i_req_fw_msg->req_hcode_update.i_operation)  ||
                 (0x400 != i_req_fw_msg->req_hcode_update.i_scomAddr)   ||
                 (0x500 != i_req_fw_msg->req_hcode_update.i_scomData) )
            {
                TS_FAIL("rt_firmware_request::testFirmwareRequestHcodeUpdate: "
                        "FAILED: Loader received incorrect data: chipId:0x%X, "
                       "section:%d, operation:%d, scomAddr:0x%X, scomData:0x%X",
                        i_req_fw_msg->req_hcode_update.i_chipId,
                        i_req_fw_msg->req_hcode_update.i_section,
                        i_req_fw_msg->req_hcode_update.i_operation,
                        i_req_fw_msg->req_hcode_update.i_scomAddr,
                        i_req_fw_msg->req_hcode_update.i_scomData);
            }

            i_resp_fw_msg->io_type =
                                  hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC;

            // dummy return value for testing
            i_resp_fw_msg->resp_generic.o_status = 264;


            TRACFCOMP(g_trac_hbrt, EXIT_MRK
                      "rt_firmware_request::testFirmwareRequestHcodeUpdate");

            // just return 1 for testing
            return 1;
        } // end firmwareRequestHcodeUpdateTest

        // =====================================================================
        // compareAttributeHeader
        // =====================================================================
        static bool compareAttributeHeader(
               const TARGETING::AttributeTank::Attribute* const l_attribute1,
               const TARGETING::AttributeTank::Attribute* const l_attribute2)
        {
            bool retVal(true);

            // Make sure the Attribute Header matches original data
            if (0 != memcmp(&(l_attribute1->getHeader()),
                            &(l_attribute2->getHeader()),
                            sizeof(TARGETING::AttributeTank::AttributeHeader)))
            {
                retVal = false;
            }

            return retVal;
        } // end compareAttributeHeader

        // =====================================================================
        // compareAttributeValues
        // =====================================================================
        static bool compareAttributeValues(
               const TARGETING::AttributeTank::Attribute* const l_attribute1,
               const TARGETING::AttributeTank::Attribute* const l_attribute2)
        {
            bool retVal(true);

            // Compare the Attribute Values for a match
            if (0 != memcmp(l_attribute1->getValue(),
                            l_attribute2->getValue(),
                            l_attribute2->getHeader().iv_valSize))
            {
                retVal = false;
            }

            return retVal;
        } // end compareAttributeValues
        /// end Firmware Request Test Helper Functions

        // =====================================================================
        // Some needed definitions
        // =====================================================================
        typedef std::pair<uint64_t,uint64_t> SCOM_KEY;
        typedef std::map<SCOM_KEY,uint64_t> SCOM_MAP;
        static SCOM_MAP cv_scomMap;
        static std::map<void*, UtilLidMgr*> cv_loadedLids;
        static uint64_t cv_hb_data_addr;
        static uint64_t cv_comm_addr;
        static uint64_t cv_comm_phys_addr;
};


RuntimeLoaderTest::SCOM_MAP RuntimeLoaderTest::cv_scomMap;
std::map<void*, UtilLidMgr*> RuntimeLoaderTest::cv_loadedLids;

// Initialize static member variables
uint64_t RuntimeLoaderTest::cv_hb_data_addr = 0;
uint64_t RuntimeLoaderTest::cv_comm_addr = 0;
uint64_t RuntimeLoaderTest::cv_comm_phys_addr = 0;

#endif

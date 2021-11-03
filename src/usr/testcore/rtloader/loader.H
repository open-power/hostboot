/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/rtloader/loader.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <targeting/common/attributeTank.H>
#include <util/utilrsvdmem.H>
#include <sys/misc.h>
#include <errno.h>
#include <isteps/mem_utils.H>
#include <targeting/translateTarget.H>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <sbeio/sbe_psudd.H>

trace_desc_t* g_trac_hbrt = NULL;
TRAC_INIT(&g_trac_hbrt, "HBRT_TEST", 12*KILOBYTE);


class RuntimeLoaderTest : public CxxTest::TestSuite
{
    public:
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
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
                // In order to test the runtime PSU operations, we need to
                //  short-circuit the interrupt handling of the IPL code
                //  that is still resident.
                SBEIO::SbePsu::getTheInstance().ignoreInterrupts(true);
#endif //#ifdef CONFIG_COMPILE_CXXTEST_HOOKS


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
                intf->ipmi_msg= nullptr;
                intf->clock_gettime = clock_gettime;
                intf->hcode_scom_update = rt_hcode_update;
                intf->firmware_request = rt_firmware_request;
                intf->get_pm_complex_addresses = rt_get_pm_complex_addresses;
                intf->unmap_phys_mem = rt_unmap_phys_mem;
                intf->map_phys_mem = rt_map_phys_mem;
                intf->nanosleep = rt_nanosleep;
                intf->i2c_read = rt_i2c_read;
                intf->i2c_write = rt_i2c_write;
                intf->get_reserved_mem_phys = rt_get_reserved_mem_phys;

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

                    #ifdef PROFILE_CODE
                    // When code coverage is active, unload all the runtime
                    // modules to recover the code coverage data
                    (*rtInterface->unload)();
                    #endif
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

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
            // Re-enable SBE PSU interrupts
            SBEIO::SbePsu::getTheInstance().ignoreInterrupts(false);
#endif //#ifdef CONFIG_COMPILE_CXXTEST_HOOKS

        }

    private:
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

            for(auto &proc : cv_homerAddr)
            {
                if(proc.second)
                {
                    const auto rc = mm_block_unmap(
                        reinterpret_cast<void*>(proc.second));
                    assert(!rc,"mm_block_unmap failed for 0x%016llX",
                        proc.second);
                    proc.second = 0;
                }
            }
        }

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
        }

        // Get the target for the given rt chipid
        static TARGETING::Target* get_target_for_hbrt_id( uint32_t i_hbrtid )
        {
            TARGETING::TargetHandleList procChips;
            getAllChips(procChips, TARGETING::TYPE_PROC, false);
            for (const auto & l_procChip: procChips)
            {
                uint64_t l_instance =
                    l_procChip->getAttr<TARGETING::ATTR_HBRT_HYP_ID>();
                if(l_instance == i_hbrtid)
                {
                    return l_procChip;
                }
            }
            TRACFCOMP( g_trac_hbrt, "No target found for id=%.8X", i_hbrtid );
            return nullptr;
        }

        static int rt_get_pm_complex_addresses(uint64_t i_chipId,
                                               uint64_t& o_homerAddr,
                                               uint64_t& o_occCommonAddr)
        {
            TARGETING::Target* l_sys = nullptr;
            TARGETING::Target* l_proc = nullptr;
            errlHndl_t l_errl = nullptr;

            int l_rc = 0;

            do {

            TARGETING::targetService().getTopLevelTarget(l_sys);
            l_errl =
             TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
            if(l_errl)
            {
                TS_FAIL("rt_get_pm_complex_addresses: could not fetch proc target");
                errlCommit(l_errl, CXXTEST_COMP_ID);
                l_rc = -1;
                break;
            }

            assert(l_sys, "rt_get_pm_complex_addresses:could not get top level target!");

            o_homerAddr = l_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
            o_occCommonAddr =
                    l_sys->getAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>();

            }while(0);

            return l_rc;
        }

        static void* rt_map_phys_mem(uint64_t i_addr, size_t i_size)
        {
            return mm_block_map(reinterpret_cast<void*>(i_addr), i_size);
        }

        static int rt_unmap_phys_mem(void* i_addr)
        {
            return mm_block_unmap(i_addr);
        }

        static void rt_puts(const char* str)
        {
            TRACFCOMP(g_trac_hbrt, "HBRT TRACE: %s", str);
        }

        static int rt_setPageExecute(void* addr)
        {
            return mm_set_permission(addr, PAGESIZE, EXECUTABLE);
        }

        static void rt_assert()
        {
            TRACFCOMP(g_trac_hbrt, "rt_assert");
            TS_FAIL("rt_assert should never be called");
            assert(false);
        }

        static void rt_nanosleep(uint64_t i_sec, uint64_t i_nsec)
        {
            nanosleep(i_sec, i_nsec);
        }

        static int rt_scom_read(uint64_t chipid,
                                 uint64_t addr,
                                 void* data)
        {
            int rc = 0;

            TRACFCOMP(g_trac_hbrt,
                      "Scom read chipid: 0x%08x Address: 0x%08x",
                      chipid,
                      addr);

            errlHndl_t l_errl = nullptr;
            TARGETING::Target* l_target = get_target_for_hbrt_id(chipid);

            // First attempt a real SCOM read
            size_t l_size = sizeof(uint64_t);
            l_errl = DeviceFW::deviceRead(l_target,
                                          data,
                                          l_size,
                                          DEVICE_SCOM_ADDRESS(addr));
            if(l_errl)
            {
                delete l_errl;
                l_errl = nullptr;

                // Use cache in the case of an error
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
            }

            return rc;
        }

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

            errlHndl_t l_errl = nullptr;
            TARGETING::Target* l_target = get_target_for_hbrt_id(chipid);

            // First attempt a real SCOM write
            size_t l_size = sizeof(uint64_t);
            l_errl = DeviceFW::deviceWrite(l_target,
                                           data,
                                           l_size,
                                           DEVICE_SCOM_ADDRESS(addr));
            if(l_errl)
            {
                delete l_errl;
                l_errl = nullptr;

                // Use cache on error
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
            }

            return rc;
        }

        typedef std::pair<uint64_t,uint64_t> SCOM_KEY;
        typedef std::map<SCOM_KEY,uint64_t> SCOM_MAP;
        static SCOM_MAP cv_scomMap;

        static int rt_logErr(uint32_t plid,
                             uint32_t data_len,
                             void * data)
        {
            uint64_t rc = 0;
            TRACFCOMP(g_trac_hbrt,
                      "Log error. Plid: 0x%X  len: %d",
                      plid,
                      data_len);

            TRACDBIN(g_trac_hbrt, "RUNTIME ERROR LOG:",data,data_len);


            errlHndl_t err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        0,0);
            rc = err->unflatten(data, data_len);

            errlCommit(err,CXXTEST_COMP_ID);

            return rc;
        }

        static std::map<void*, UtilLidMgr*> cv_loadedLids;

        static int rt_lid_load(uint32_t lid, void** buffer, size_t* size)
        {
            errlHndl_t l_errl = NULL;
            UtilLidMgr* lidmgr = nullptr;

            do
            {
                lidmgr = new UtilLidMgr(lid,&l_errl);
                if (l_errl) break;

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

        }

        static int rt_lid_unload(void* buffer)
        {
            UtilLidMgr* lidmgr = cv_loadedLids[buffer];
            if (NULL == lidmgr) return -1;

            cv_loadedLids.erase(buffer);
            free(buffer);
            delete lidmgr;
            return 0;
        }

        //--------------------------------------------------------------------
        static int rt_get_reserved_mem_phys(const char* i_region,
                                            uint32_t i_instance,
                                            void** o_vAddr,
                                            uint64_t* o_pAddr)
        {
            int rc = 0;
            *o_vAddr = nullptr;
            *o_pAddr = 0;

            if (0 == strcmp(i_region, HBRT_RSVD_MEM__SBE_COMM))
            {
                static std::vector<uint64_t> s_virt_SBE_COMM_ADDR(10);
                auto l_procChip = get_target_for_hbrt_id(i_instance);
                if( l_procChip != nullptr )
                {
                    *o_pAddr = l_procChip->getAttr<TARGETING::ATTR_SBE_COMM_ADDR>();
                    if( s_virt_SBE_COMM_ADDR[i_instance] == 0 )
                    {
                        *o_vAddr = mm_block_map(reinterpret_cast<void*>(*o_pAddr),
                                                  SBE_MSG::SBE_COMM_BUFFER_SIZE);
                        if( *o_vAddr == 0 )
                        {
                            TS_FAIL("mm_block_map failed to map physical address 0x%016llX for SBE_COMM_ADDR",  *o_pAddr);
                        }
                    }
                    TRACFCOMP(g_trac_hbrt,"ATTR_SBE_COMM_ADDR for %.8X = %X @ %X",
                              TARGETING::get_huid(l_procChip),
                              *o_pAddr,
                              *o_vAddr);
                }
            }
            else if (0 == strcmp(i_region, HBRT_RSVD_MEM__DATA))
            {
                *o_vAddr = rt_get_hb_data(i_instance);
                rc = -1; //no support for physical address yet
            }
            else if (0 == strcmp(i_region,HBRT_RSVD_MEM__HOMER))
            {
                *o_vAddr = rt_get_homer_addr(i_instance);
                rc = -1; //no support for physical address yet
            }
            else if (0 == strcmp(i_region,HBRT_RSVD_MEM__SBE_FFDC))
            {
                static std::vector<uint64_t> s_virt_SBE_FFDC_ADDR(10);
                auto l_procChip = get_target_for_hbrt_id(i_instance);
                if( l_procChip != nullptr )
                {
                    *o_pAddr = l_procChip->getAttr<TARGETING::ATTR_SBE_FFDC_ADDR>();
                    if( s_virt_SBE_FFDC_ADDR[i_instance] == 0 )
                    {
                        *o_vAddr = mm_block_map(reinterpret_cast<void*>(*o_pAddr),
                                                  SBEIO::SbePsu::getTheInstance().getSbeFFDCBufferSize());
                        if( *o_vAddr == nullptr )
                        {
                            TS_FAIL("mm_block_map failed to map physical address 0x%016llX for SBE_FFDC_ADDR",  *o_pAddr);
                        }
                    }
                    TRACFCOMP(g_trac_hbrt,"ATTR_SBE_COMM_ADDR for %.8X = %X @ %X",
                              TARGETING::get_huid(l_procChip),
                              *o_pAddr,
                              *o_vAddr);
                }
            }
            else if (0 == strcmp(i_region,HBRT_RSVD_MEM__SBE_PSU))
            {
                static void* s_virt_SBE_PSU = nullptr;
                if( s_virt_SBE_PSU == nullptr )
                {
                    *o_pAddr = TARGETING::UTIL::assertGetToplevelTarget()
                      ->getAttr<ATTR_SBE_HBRT_PSU_PHYS_ADDR>();
                    *o_vAddr = mm_block_map(reinterpret_cast<void*>(*o_pAddr),
                                              SBEIO::SbePsu::MAX_HBRT_PSU_OP_SIZE_BYTES);
                    if( *o_vAddr == nullptr )
                    {
                        TS_FAIL("mm_block_map failed to map physical address 0x%016llX for SBE_HBRT_PSU_PHYS_ADDR",
                                *o_pAddr);
                    }
                    TRACFCOMP(g_trac_hbrt,"ATTR_SBE_HBRT_PSU_PHYS_ADDR = %X @ %X",
                              *o_pAddr,
                              *o_vAddr);
                }
            }
            else
            {
                TS_FAIL("rt_get_reserved_mem_phys> Unsupported reserved memory: %s",
                        i_region);
            }

            TRACFCOMP(g_trac_hbrt,
                      INFO_MRK"rt_get_reserved_mem_phys> returning virt=%p,phys=0x%016llX for region %s, instance 0x%08X",
                      *o_vAddr,*o_pAddr,
                      i_region,i_instance);

            return rc;
        }

        //--------------------------------------------------------------------
        static uint64_t rt_get_reserved_mem(const char* i_region,
                                            uint32_t i_instance)
        {
            uint64_t l_physAddr = 0;
            void* l_virtAddr = nullptr;
            rt_get_reserved_mem_phys( i_region,
                                      i_instance,
                                      &l_virtAddr,
                                      &l_physAddr );
            return reinterpret_cast<uint64_t>(l_virtAddr);
        }

        /**
         *  @brief Returns the HOMER address for a given runtime processor
         *      instance
         *
         *  @param[in] i_instance Runtime processor instance
         *
         *  @return uint64_t HOMER address
         */
        static void* rt_get_homer_addr(const uint32_t i_instance)
        {
            TRACFCOMP(g_trac_hbrt,ENTER_MRK
                      "rt_get_homer_addr> i_instance=%d", i_instance);

            void* vAddr = 0;
            TARGETING::TargetHandle_t pTarget = nullptr;
            auto pError = RT_TARG::getHbTarget(i_instance,pTarget);
            if(pError)
            {
                // API does not allow for surfacing an error back so commit
                // the error and return 0 back to the caller.
                errlCommit(pError,CXXTEST_COMP_ID);
            }
            else if(   (pTarget)
                    && (   pTarget->getAttr<TARGETING::ATTR_TYPE>()
                        == TARGETING::TYPE_PROC))
            {
                const auto procOrdinalId =
                    pTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();

                auto procItr = cv_homerAddr.find(procOrdinalId);
                if(   (procItr == cv_homerAddr.end())
                   || (!procItr->second))
                {
                    const auto physAddr =
                        pTarget->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
                    vAddr = mm_block_map(reinterpret_cast<void*>(physAddr),
                                         VMM_HOMER_INSTANCE_SIZE);

                    assert(vAddr,"mm_block_map failed to map physical address "
                        "0x%016llX",physAddr)

                    cv_homerAddr[procOrdinalId] = vAddr;
                }
                else
                {
                    vAddr = cv_homerAddr[procOrdinalId];
                }
            }

            return vAddr;
        }

        static void* rt_get_hb_data(uint32_t i_instance)
        {
            TRACFCOMP( g_trac_hbrt,
                       ENTER_MRK"rt_get_hb_data> i_instance=%d", i_instance );

            uint64_t l_totalSize = 0;
            void* l_vAddr = 0;

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
            l_vAddr = mm_block_map(reinterpret_cast<void*>(l_physical_addr),
                                   sizeof(Util::hbrtTableOfContents_t));

            TRACFCOMP(g_trac_hbrt, "rt_get_hb_data: mapped "
                "physical address 0x%.16llX -> virtual address %p",
                l_physical_addr, l_vAddr);

            // check that map worked
            assert(l_vAddr != nullptr,"rt_get_hb_data. Could not map HB DATA memory");

            // find the total size
            Util::hbrtTableOfContents_t * toc_ptr =
                    reinterpret_cast<Util::hbrtTableOfContents_t *>(l_vAddr);
            l_totalSize = toc_ptr->total_size;
            TRACFCOMP(g_trac_hbrt, "rt_get_hb_data: "
                          "total_size for HB Data = %lld", l_totalSize);

            // unmap
            int l_rc = mm_block_unmap(l_vAddr);
            if(l_rc)
            {
                TRACFCOMP( g_trac_hbrt,
                           "rt_get_hb_data. fail to unmap virt addr %p",
                           l_vAddr);
                assert(false, "rt_get_hb_data. failed to unmap virt addr");
            }

            // Map to the virtual address to access ALL data
            cv_hb_data_addr = mm_block_map(reinterpret_cast<void*>(l_physical_addr),
                                           l_totalSize);

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
        }


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
        }

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
        }


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
        }

        //--------------------------------------------------------------------
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

        //--------------------------------------------------------------------
        static int rt_firmware_request(uint64_t i_reqLen, void *i_req,
                             uint64_t* io_respLen, void *o_resp  )
        {
            size_t retVal = 0;
            do
            {
               if (i_req == nullptr ||
                   io_respLen == nullptr ||
                   o_resp == nullptr)
               {
                  retVal = -EINVAL;
                  break;
               }

               hostInterfaces::hbrt_fw_msg* l_req_fw_msg =
                                (hostInterfaces::hbrt_fw_msg*) i_req;
               hostInterfaces::hbrt_fw_msg* l_resp_fw_msg =
                                (hostInterfaces::hbrt_fw_msg*) o_resp;

               if (hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE
                                              == l_req_fw_msg->io_type)
               {
                  if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                sizeof(l_req_fw_msg->req_hcode_update)))
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  if (*io_respLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                   sizeof(l_resp_fw_msg->resp_generic)))
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  TRACFCOMP(g_trac_hbrt,
                      "rt_firmware_request for HCODE SCOM update: "
                      "type:%d, chipId:0x%X, section:%d, "
                      "operation:%d, scomAddr:0x%X scomData:0x%X",
                      l_req_fw_msg->io_type,
                      l_req_fw_msg->req_hcode_update.i_chipId,
                      l_req_fw_msg->req_hcode_update.i_section,
                      l_req_fw_msg->req_hcode_update.i_operation,
                      l_req_fw_msg->req_hcode_update.i_scomAddr,
                      l_req_fw_msg->req_hcode_update.i_scomData);

                  l_resp_fw_msg->io_type =
                          hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC;

                  // dummy return value for testing
                  l_resp_fw_msg->resp_generic.o_status = 264;

                  retVal = 1;  // just return 1 for testing
               }
               else if (hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG
                                              == l_req_fw_msg->io_type)
               {
                  if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                sizeof(l_req_fw_msg->error_log)))
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                sizeof(l_req_fw_msg->error_log) +
                                l_req_fw_msg->error_log.i_errlSize - 1))
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  if (*io_respLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                   sizeof(l_resp_fw_msg->resp_generic)))
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  TRACFCOMP(g_trac_hbrt,
                      "rt_firmware_request for error log: "
                      "type:%d, plid:0x%08x, size:%d, data:0x%02x",
                      l_req_fw_msg->io_type,
                      l_req_fw_msg->error_log.i_plid,
                      l_req_fw_msg->error_log.i_errlSize,
                      l_req_fw_msg->error_log.i_data);

                  l_resp_fw_msg->io_type =
                                 hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC;

                  // dummy return value for testing
                  l_resp_fw_msg->resp_generic.o_status = 20;

                  retVal = 0;  // just return 0 for testing
               }
               else if (hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ
                                                   == l_req_fw_msg->io_type)
               {
                  if (i_reqLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                             sizeof(l_req_fw_msg->generic_msg)))
                  {
                      retVal = -EINVAL;
                      break;
                  }

                  if (*io_respLen < (hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                   sizeof(l_resp_fw_msg->generic_msg)))
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  if (i_reqLen != *io_respLen)
                  {
                     retVal = -EINVAL;
                     break;
                  }

                  uint32_t* l_data =
                         (uint32_t*) &(l_req_fw_msg->generic_msg.data);
                  TRACFCOMP(g_trac_hbrt,
                      "rt_firmware_request request: "
                      "type:%d, magic:0x%.8X, dataSize:%d, "
                      "structVer:0x%.8X, seqnum:%d, msgq:0x%.8X, ",
                      l_req_fw_msg->io_type,
                      l_req_fw_msg->generic_msg.magic,
                      l_req_fw_msg->generic_msg.dataSize,
                      l_req_fw_msg->generic_msg.structVer,
                      l_req_fw_msg->generic_msg.seqnum,
                      l_req_fw_msg->generic_msg.msgq);

                  TRACFCOMP(g_trac_hbrt,
                      "msgType:0x%.8X, __req:%d, __onlyError:%d, "
                      "data:0x%.8X, plid:0x%.8X, huid:0x%.8X",
                      l_req_fw_msg->generic_msg.msgType,
                      l_req_fw_msg->generic_msg.__req,
                      l_req_fw_msg->generic_msg.__onlyError,
                      l_req_fw_msg->generic_msg.data,
                      l_data[0],
                      l_data[1]);

                  // Simple map of SCOM addresses to values, this ignores
                  // the target (or huid).
                  static std::map<uint64_t, uint64_t> l_scomCache;

                  // Used to give unique, spoofed SCOM values
                  static uint64_t l_fakeVal = 0x11;

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
                  switch (l_req_fw_msg->generic_msg.msgType)
                  {
                      case GenericFspMboxMessage_t::MSG_SINGLE_SCOM_OP:
                      {
                          SingleScomOpHbrtFspData_t* l_req_fspData =
                                   reinterpret_cast<SingleScomOpHbrtFspData_t*>
                                          (&(l_req_fw_msg->generic_msg.data));
                          SingleScomOpHbrtFspData_t* l_resp_fspData =
                                   reinterpret_cast<SingleScomOpHbrtFspData_t*>
                                          (&(l_resp_fw_msg->generic_msg.data));

                          l_resp_fw_msg->generic_msg.dataSize =
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
                          retVal = 0;
                          break;
                      }
                      case GenericFspMboxMessage_t::MSG_MULTI_SCOM_OP:
                      {
                          MultiScomReadHbrtFspData_t* l_req_fspData =
                                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                                          (&(l_req_fw_msg->generic_msg.data));
                          MultiScomReadHbrtFspData_t* l_resp_fspData =
                                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                                          (&(l_resp_fw_msg->generic_msg.data));

                          l_resp_fw_msg->generic_msg.dataSize =
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
                          retVal = 0;
                          break;
                      }
                      default:
                          // random testing data
                          struct
                          {
                             uint32_t plid;
                             uint32_t huid;
                          } l_resp_data;

                          l_resp_fw_msg->generic_msg.dataSize =
                                            sizeof(l_resp_fw_msg->generic_msg);

                          l_resp_data.plid = 0x60;
                          l_resp_data.huid = 0x70;
                          memcpy(&(l_resp_fw_msg->generic_msg.data),
                                 &(l_resp_data),
                                 sizeof(l_resp_fw_msg->generic_msg.data));
                          retVal = 5;
                          break;
                  }

                  TRACFCOMP(g_trac_hbrt,
                      "rt_firmware_request response: "
                      "type:%d, magic:0x%.8X, dataSize:%d, structVer:0x%.8X, "
                      "seqnum:%d, msgq:0x%.8X, msgType:0x%.8X, __req:%d, ",
                      l_resp_fw_msg->io_type,
                      l_resp_fw_msg->generic_msg.magic,
                      l_resp_fw_msg->generic_msg.dataSize,
                      l_resp_fw_msg->generic_msg.structVer,
                      l_resp_fw_msg->generic_msg.seqnum,
                      l_resp_fw_msg->generic_msg.msgq,
                      l_resp_fw_msg->generic_msg.msgType,
                      l_resp_fw_msg->generic_msg.__req);

                  TRACFCOMP(g_trac_hbrt,
                      "__onlyError:%d, data:0x%.8X, plid:0x%.8X, huid:0x%.8X, "
                      "retVal=%d",
                      l_resp_fw_msg->generic_msg.__onlyError,
                      l_resp_fw_msg->generic_msg.data,
                      l_resp_fw_msg->generic_msg.data >> 32,
                      0x0000FFFF & l_resp_fw_msg->generic_msg.data,
                      retVal);
               }
               else if (hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_SEND
                                                   == l_req_fw_msg->io_type)
               {

                  TRACFBIN(g_trac_hbrt,
                      "rt_firmware_request (test) for  MCTP Send: ",
                      l_req_fw_msg->mctp_send.send_data,
                      i_reqLen);

                  l_resp_fw_msg->io_type =
                                 hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC;

                  // dummy return value for testing
                  l_resp_fw_msg->resp_generic.o_status = 0;

                  retVal = 0;  // just return 0 for testing
               }
               else if (hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_RECEIVE
                                                   == l_req_fw_msg->io_type)
               {
                  l_resp_fw_msg->io_type =
                                 hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_AVAILABLE;

                  l_resp_fw_msg->mctp_receive.receive_data[0] = 0xFF;

                  retVal = 0;  // just return 0 for testing
               }
               else if (hostInterfaces::HBRT_FW_MSG_TYPE_PM_RESET_ALERT
                                                   == l_req_fw_msg->io_type)
               {
                  l_resp_fw_msg->io_type =
                                 hostInterfaces::HBRT_FW_MSG_TYPE_PM_RESET_ALERT;
                  TRACFCOMP(g_trac_hbrt,
                            "rt_firmware_request:HBRT_FW_MSG_TYPE_PM_RESET_ALERT(%d)",
                            l_req_fw_msg->pmreset_alert.procId);
                  retVal = 0;  // just return 0 for testing
               }
               else
               {
                  TRACFCOMP(g_trac_hbrt,
                      "rt_firmware_request: unrecognized request, type=%d",
                      l_req_fw_msg->io_type);
               }
            } while (0) ;

            return retVal;
        }

        //--------------------------------------------------------------------
        static int rt_i2c_read( uint64_t i_master, uint16_t i_devAddr,
                                uint32_t i_offsetSize, uint32_t i_offset,
                                uint32_t i_length, void* o_data )
        {
            int l_rc = 0;

            // just pass the operation down into the base HB code

            /* pull apart the proc/engine/port
             *  @param[in] i_master     chip, engine and port packed into
             *                          a single 64-bit argument
             *                          chip includes ID type, see defines at top
             *    ---------------------------------------------------
             *    |         chip         |  reserved  |  eng | port |
             *    |         (32)         |    (16)    |  (8) | (8)  |
             *    ---------------------------------------------------
             */
            uint32_t l_chip = (HBRT_I2C_MASTER_CHIP_MASK & i_master) >> 32;
            uint32_t l_engine = (HBRT_I2C_MASTER_ENGINE_MASK & i_master) >> 8;
            uint32_t l_port = (HBRT_I2C_MASTER_PORT_MASK & i_master);
            TARGETING::Target* l_chipTarg = get_target_for_hbrt_id(l_chip);
            uint32_t l_offset = i_offset << (sizeof(i_offset)-i_offsetSize);
            size_t l_length = i_length;
            // PHYP/OPAL expet the 7-bits to be left-justified,
            //  HB input is right-justified
            uint16_t l_devAddr = i_devAddr << 1;

            TRACFCOMP(g_trac_hbrt,
                      "rt_i2c_read: l_chip=%d(%.8X), l_engine=%d, l_port=%d, l_offset=%d, l_devAddr=%.2X",
                      l_chip, TARGETING::get_huid(l_chipTarg),
                      l_engine, l_port, l_offset, l_devAddr);

            errlHndl_t l_err = deviceOp( DeviceFW::READ,
                                  l_chipTarg,
                                  o_data,
                                  l_length,
                                  DEVICE_I2C_ADDRESS_OFFSET(l_port,
                                     l_engine,
                                     l_devAddr,
                                     i_offsetSize,
                                     reinterpret_cast<uint8_t*>(&l_offset),
                                     I2C_MUX::NOT_APPLICABLE,
                                     nullptr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_hbrt,
                          "rt_i2c_read: error from DeviceFW::READ");
                errlCommit (l_err, CXXTEST_COMP_ID);
                l_rc = -999;
            }

            return l_rc;
        }

        //--------------------------------------------------------------------
        static int rt_i2c_write( uint64_t i_master, uint16_t i_devAddr,
                                 uint32_t i_offsetSize, uint32_t i_offset,
                                 uint32_t i_length, void* i_data )
        {
            int l_rc = 0;

            // just pass the operation down into the base HB code

            /* pull apart the proc/engine/port
             *  @param[in] i_master     chip, engine and port packed into
             *                          a single 64-bit argument
             *                          chip includes ID type, see defines at top
             *    ---------------------------------------------------
             *    |         chip         |  reserved  |  eng | port |
             *    |         (32)         |    (16)    |  (8) | (8)  |
             *    ---------------------------------------------------
             */
            uint32_t l_chip = (HBRT_I2C_MASTER_CHIP_MASK & i_master) >> 32;
            uint32_t l_engine = (HBRT_I2C_MASTER_ENGINE_MASK & i_master) >> 8;
            uint32_t l_port = (HBRT_I2C_MASTER_PORT_MASK & i_master);
            TARGETING::Target* l_chipTarg = get_target_for_hbrt_id(l_chip);
            uint32_t l_offset = i_offset << (sizeof(i_offset)-i_offsetSize);
            size_t l_length = i_length;
            // PHYP/OPAL expet the 7-bits to be left-justified,
            //  HB input is right-justified
            uint16_t l_devAddr = i_devAddr << 1;

            TRACFCOMP(g_trac_hbrt,
                      "rt_i2c_write: l_chip=%d(%.8X), l_engine=%d, l_port=%d, l_offset=%d, l_devAddr=%.2X",
                      l_chip, TARGETING::get_huid(l_chipTarg),
                      l_engine, l_port, l_offset, l_devAddr);

            // Look for special parms to test i2c lock path
            if( i_offset == 1234 )
            {
                TRACFCOMP(g_trac_hbrt,
                          "rt_i2c_write: Forcing Lock Path");
                return HBRT_RC_I2C_LOCKED;
            }


            errlHndl_t l_err = deviceOp( DeviceFW::WRITE,
                                  l_chipTarg,
                                  i_data,
                                  l_length,
                                  DEVICE_I2C_ADDRESS_OFFSET( l_port,
                                     l_engine,
                                     l_devAddr,
                                     i_offsetSize,
                                     reinterpret_cast<uint8_t*>(&l_offset),
                                     I2C_MUX::NOT_APPLICABLE,
                                     nullptr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_hbrt,
                          "rt_i2c_write: error from DeviceFW::WRITE");
                errlCommit (l_err, CXXTEST_COMP_ID);
                l_rc = -999;
            }

            return l_rc;
        }


        //--------------------------------------------------------------------
        //--------------------------------------------------------------------
        static void* cv_hb_data_addr;

        // Map which looks up a proc's HOMER address using a proc's ordinal ID
        static std::map<uint32_t,void*> cv_homerAddr;
};


RuntimeLoaderTest::SCOM_MAP RuntimeLoaderTest::cv_scomMap;
std::map<void*, UtilLidMgr*> RuntimeLoaderTest::cv_loadedLids;
std::map<uint32_t,void*> RuntimeLoaderTest::cv_homerAddr;

void* RuntimeLoaderTest::cv_hb_data_addr = 0;

#endif

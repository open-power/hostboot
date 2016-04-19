/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/rtloader/loader.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <pnor/ecc.H>
#include <ipmi/ipmiif.H>
trace_desc_t* g_trac_hbrt = NULL;
TRAC_INIT(&g_trac_hbrt, "HBRT_TEST", 2*KILOBYTE);

extern const char* cv_EYECATCHER[];

class RuntimeLoaderTest : public CxxTest::TestSuite
{
    public:
        void testLoader()
        {
            static const uint64_t HEADER_OFFSET = 0x2000;

            PNOR::SectionInfo_t runtimeSection;

            errlHndl_t l_errl =
                PNOR::getSectionInfo(PNOR::HB_RUNTIME, runtimeSection);

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
        }

    private:
        uint64_t callViaCtr(uint64_t entry, void* param0, void* param1)
        {
            register uint64_t result = 0;

            asm volatile("mtctr %1; mr 3, %2 ; mr 4, %3; "
                         "std 2, 40(1); bctrl; ld 2, 40(1); "
                         "mr %0, 3" :
                "=r" (result) : "r" (entry), "r" (param0), "r" (param1) :
                "lr","ctr","r0","r3","r4","r5","r6","r7","r8","r9",
                "r10","r11"); // TODO: Need to double check the ABI here.

            return result;
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
            assert(false);
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
                rc = 1;
            }

            return rc;
        }

        static int rt_scom_write(uint64_t chipid,
                                  uint64_t addr,
                                  void* data)
        {
            int rc = 0;

            TRACFCOMP(g_trac_hbrt,
                      "Scom write chipid: 0x%08x Address: 0x%08x",
                      chipid,
                      addr);

            uint64_t * data64 = static_cast<uint64_t *>(data);

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
        }

        static std::map<void*, UtilLidMgr*> cv_loadedLids;

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
        static uint64_t rt_get_reserved_mem(const char* i_region,
                                            uint32_t i_instance)
        {
            if (0 == strcmp(i_region, "ibm,hbrt-vpd-image"))
                return rt_get_vpd();
            else if (0 == strcmp(i_region, "ibm,hbrt-target-image"))
                return rt_get_targ();
            else
                return 0;
        }


        static PNOR::SectionId find_sectionId (const char* i_partitionName)
        {
            PNOR::SectionId l_id = PNOR::INVALID_SECTION;
            for (size_t i=PNOR::FIRST_SECTION; i<=PNOR::NUM_SECTIONS;
                    ++i)
            {
                if (0 == strcmp(cv_EYECATCHER[i], i_partitionName))
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

                //search cv_EYECATHCER for partitionname
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
                    TRACFCOMP(g_trac_hbrt, "rt_pnor_read: getSectionInfo errored");
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

                l_err = DeviceFW::deviceRead (pnor_target, o_data, l_bytes_to_read,
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

                //search cv_EYECATHCER for partitionname
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
                    TRACFCOMP(g_trac_hbrt, "rt_pnor_write: getSectionInfo errored");
                    break;
                }

                //fix the offset for the TEST section so that the testcases
                //don't collide
                i_offset = (PNOR::TEST) ? (i_offset+
                       ((PNOR::pnorTestSec_rt_readwrite_offset*9)/8)):i_offset;

                uint32_t l_flashAddr = l_info.flashAddr + i_offset;

                TRACFCOMP(g_trac_hbrt,"rt_pnor_write: calling"
                        " deviceWrite: offset:0x%X, flashAddr:0x%X, size:0x%X",
                        i_offset, l_flashAddr, i_sizeBytes);

                l_err = DeviceFW::deviceWrite (pnor_target, i_data, i_sizeBytes,
                                      DEVICE_PNOR_ADDRESS(i_proc, l_flashAddr));
                if (l_err)
                {
                    TRACFCOMP(g_trac_hbrt, "rt_pnor_write: deviceWrite errored");
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
        static uint64_t rt_get_vpd()
        {
            if(cv_vpd_addr != 0)
            {
                return cv_vpd_addr;
            }

            // runtime VPD area not setup yet.
            // Need to map the area into virtual memory
            errlHndl_t err = VPD::vpd_load_rt_image(cv_vpd_phys_addr);

            if(!err)
            {

                uint8_t * vpd_ptr =
                    reinterpret_cast<uint8_t *>(cv_vpd_phys_addr);

                void * vptr = mm_block_map(vpd_ptr, VMM_RT_VPD_SIZE);

                assert(vptr != NULL,"rt_get_vpd. Could not map VPD memory");


                // Store the address in a class variable so we only
                // need to load vpd once.
                cv_vpd_addr = reinterpret_cast<uint64_t>(vptr);
            }
            else
            {
                errlCommit(err,CXXTEST_COMP_ID);
            }

            return cv_vpd_addr;

        }

        static uint64_t rt_get_targ()
        {
            if (cv_targ_addr != 0)
            {
                return cv_targ_addr;
            }

            // Ensure cv_vpd_phys_addr is primed.
            rt_get_vpd();

            cv_targ_phys_addr = cv_vpd_phys_addr;
            cv_targ_addr = reinterpret_cast<uint64_t>(
                    TARGETING::AttrRP::save(cv_targ_phys_addr));

            return cv_targ_addr;
        }

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
        }


        static uint64_t cv_vpd_addr;
        static uint64_t cv_vpd_phys_addr;
        static uint64_t cv_targ_addr;
        static uint64_t cv_targ_phys_addr;
};


RuntimeLoaderTest::SCOM_MAP RuntimeLoaderTest::cv_scomMap;
std::map<void*, UtilLidMgr*> RuntimeLoaderTest::cv_loadedLids;
uint64_t RuntimeLoaderTest::cv_vpd_addr = 0;
uint64_t RuntimeLoaderTest::cv_vpd_phys_addr = 0;
uint64_t RuntimeLoaderTest::cv_targ_addr = 0;
uint64_t RuntimeLoaderTest::cv_targ_phys_addr = 0;




#endif

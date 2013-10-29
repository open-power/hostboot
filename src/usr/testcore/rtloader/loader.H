/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/rtloader/loader.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __TESTCORE_RTLOADER_LOADER_H
#define __TESTCORE_RTLOADER_LOADER_H

#include <pnor/pnorif.H>
#include <util/align.H>
#include <sys/mm.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlmanager.H>
#include <util/utillidmgr.H>
#include <map>

#include <runtime/interface.h>

class RuntimeLoaderTest : public CxxTest::TestSuite
{
    public:
        void testLoader()
        {
            static const uint64_t HEADER_OFFSET = 0x2000;

            PNOR::SectionInfo_t runtimeSection;

            errlHndl_t l_errl =
                PNOR::getSectionInfo(PNOR::HB_RUNTIME, PNOR::CURRENT_SIDE,
                                     runtimeSection);

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

            TRACFCOMP(g_trac_test, "Runtime image loaded @ %x", imageArea);

            do
            {
                hostInterfaces_t* intf = new hostInterfaces_t();
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
            TRACFCOMP(g_trac_test, "RUNTIME MSG: %s", str);
        }

        static int rt_setPageExecute(void* addr)
        {
            return mm_set_permission(addr, PAGESIZE, EXECUTABLE);
        }

        static void rt_assert()
        {
            assert(false);
        }

        static int rt_scom_read(uint32_t chipid,
                                 uint32_t addr,
                                 void* data)
        {
            int rc = 0;

            TRACFCOMP(g_trac_test,
                      "RUNTIME MSG: Scom read chipid: 0x%08x Address: 0x%08x",
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

            return rc;
        }

        static int rt_scom_write(uint32_t chipid,
                                  uint32_t addr,
                                  void* data)
        {
            int rc = 0;

            TRACFCOMP(g_trac_test,
                      "RUNTIME MSG: Scom write chipid: 0x%08x Address: 0x%08x",
                      chipid,
                      addr);

            uint64_t * data64 = static_cast<uint64_t *>(data);

            SCOM_KEY scomKey(chipid,addr);
            cv_scomMap[scomKey] = *data64;

            return rc;
        }

        typedef std::pair<uint32_t,uint32_t> SCOM_KEY;
        typedef std::map<SCOM_KEY,uint64_t> SCOM_MAP;
        static SCOM_MAP cv_scomMap;

        static int rt_logErr(uint32_t plid,
                             uint32_t data_len,
                             void * data)
        {
            uint64_t rc = 0;
            TRACFCOMP(g_trac_test,
                      "RUNTIME MSG: Log error. Plid: %d  len: %d",
                      plid,
                      data_len);

            TRACDBIN(g_trac_test, "RUNTIME ERROR LOG:",data,data_len);


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

};


RuntimeLoaderTest::SCOM_MAP RuntimeLoaderTest::cv_scomMap;
std::map<void*, UtilLidMgr*> RuntimeLoaderTest::cv_loadedLids;


#endif

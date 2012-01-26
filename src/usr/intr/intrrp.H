//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/intr/intrrp.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef INTRRP_H
#define INTRRP_H

#include <stdint.h>
#include <builtins.h>
#include <limits.h>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <intr/interrupt.H>
#include <map>

struct msg_t;

namespace INTR
{
    class IntrRp
    {
        public:

            /**
             * Prepare HW and system to recieve external interrupts
             * @param[in] task args
             */
            static void init(void * i_taskArgs);

        protected:

            /**
             * Constructor
             */
            IntrRp() : 
                iv_msgQ(NULL),
                iv_baseAddr(0),
                iv_masterCpu(0),
                iv_isVBU(false)   {}

            /**
             * Destructor
             */
            ~IntrRp() {}

            /**
             * Start message handler
             */
            static void msg_handler(void * unused);

        private:        //Data

            enum
            {
                CPPR_OFFSET = 4,                //!< offset to CPPR (1 byte)
                XIRR_OFFSET = 4,                //!< offset to XIRR (4 bytes)
                LINKA_OFFSET = 16,              //!< offset to LINKA register
                LINKB_OFFSET = 20,              //!< offset to LINKB register
                LINKC_OFFSET = 24,              //!< offset to LINKC register
            };

            // If the interrupt can't be handled by the current chip there are
            // three link registers used provide targets to forward the
            // interrupt to.
            struct LinkReg_t
            {
                union
                {
                    uint32_t word;
                    struct
                    {
                        uint32_t        last:1;     //!< RO, 0 means last reg
                        uint32_t        loopTrip:1; //!< Stop forwarding
                        uint32_t        reserved:17;//!< Not implemented
                        uint32_t        pchip:6;    //!< Target chip
                        uint32_t        pcore:3;    //!< Target core
                        uint32_t        tspec:2;    //!< Target tread
                        uint32_t        lspec:2;    //!< Target link register
                    } PACKED;
                };
            };

            /**
             * cpu PIR register
             * @note TODO P7 bits - thread 2, core 3, chip 2, node 3, 
             *            P8 will be different. Need P8 book IV
             */
            struct PIR_t
            {
                union
                {
                    uint32_t word;
                    struct
                    {
                        uint32_t        reserved:22;    //!< zeros
                        uint32_t        nodeId:3;       //!< node (4)
                        uint32_t        chipId:2;       //!< chip pos on node (8)
                        uint32_t        coreId:3;       //!< Core number (12)
                        uint32_t        threadId:2;     //!< thread number (8)
                    } PACKED;
                };
                PIR_t(uint32_t i_word) : word(i_word) {}
            };


            typedef std::map<ext_intr_t,msg_q_t> Registry_t;


            msg_q_t     iv_msgQ;        //!< Kernel Interrupt message queue
            Registry_t  iv_registry;    //!< registered interrupt type
            uint64_t    iv_baseAddr;    //!< Base address of hw INTR regs
            PIR_t       iv_masterCpu;   //!< Master cpu PIR
            bool        iv_isVBU;       //!< TODO Don't run on VBU for now


        private:        //functions

            errlHndl_t _init();

            /**
             * Message handler 
             */
            void msgHandler();

            /**
             * Register a message queue for an interrupt type
             * @param[in] i_msgQ The message queue
             * @param[in] i_type the interrupt type
             */
            errlHndl_t registerInterrupt(msg_q_t i_msgQ, ext_intr_t i_type);

            /**
             * Enable hardware to reporting external interrupts
             */
            errlHndl_t enableInterrupts();

            /**
             * Disable hardware from reporting external interupts
             */
            errlHndl_t disableInterrupts();

            /**
             * Initialize the interrupt presenter registers
             * @param[in] i_pir  PIR value for the presenter
             */
            void initInterruptPresenter(const PIR_t i_pir) const;

            /**
             * Calculate the adress offset for the given cpu
             * @param[in] i_pir PIR value for the presenter
             * @return the offset
             */
            ALWAYS_INLINE
                uint64_t cpuOffsetAddr(const PIR_t i_pir) const
                {
                    uint64_t offset = (i_pir.nodeId  * 8) + i_pir.chipId;
                    offset <<= 20;
                    offset |= static_cast<uint64_t>(i_pir.coreId) << 14;
                    offset |= static_cast<uint64_t>(i_pir.threadId) << 12;
                    return offset;
                }

            /**
             * Validity check for an I/O address
             * @param[in] i_addr the address
             * @return error log if not valid
             */
            static errlHndl_t checkAddress(uint64_t i_addr);

    };
}; // INTR namespace

#endif

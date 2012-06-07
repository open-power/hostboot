/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/intr/intrrp.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef INTRRP_H
#define INTRRP_H

#include <stdint.h>
#include <builtins.h>
#include <limits.h>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <sys/misc.h>
#include <intr/interrupt.H>
#include <map>

struct msg_t;

namespace TARGETING
{
    class Target;
};

namespace INTR
{
    class IntrRp
    {
        public:

            /**
             * Prepare HW and system to recieve external interrupts
             * @param[in] ref to errlHndl_t
             */
            static void init( errlHndl_t &io_rtaskRetErrl );

            /**
             * Get the CPU id of the master cpu.
             */
            ALWAYS_INLINE
            uint32_t intrDestCpuId(uint32_t i_xisr) const { return iv_masterCpu.word; }

        protected:

            /**
             * Constructor
             */
            IntrRp() :
                iv_msgQ(NULL),
                iv_baseAddr(0),
                iv_masterCpu(0) {}

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
                XIRR_RO_OFFSET = 0,             //!< offset to XIRR (poll)
                CPPR_OFFSET = 4,                //!< offset to CPPR (1 byte)
                XIRR_OFFSET = 4,                //!< offset to XIRR (4 bytes)
                LINKA_OFFSET = 16,              //!< offset to LINKA register
                LINKB_OFFSET = 20,              //!< offset to LINKB register
                LINKC_OFFSET = 24,              //!< offset to LINKC register
                XISR_MASK    = 0x00FFFFFF,      //!< XISR MASK in XIRR register
            };

            // If the interrupt can't be handled by the current chip there are
            // three link registers used provide targets to forward the
            // interrupt to.
            // P7:
            // [0] last
            // [1] LoopTrip
            // [2:18] Reserved
            // [19:24] PChip
            // [25:27] PCore
            // [28:29] TSpec
            // [30:31] LSpec
            //
            // P8:
            // [0] last
            // [1] LoopTrip
            // [2:18] Reserved
            // [19:21] NodeId
            // [22:24] ChipId
            // [25:28] PCore
            // [29:31] TSpec
            struct LinkReg_t
            {
                union
                {
                    uint32_t word;
                    struct
                    {
                        uint32_t        last:1;       //!< RO, 0 means last reg
                        uint32_t        loopTrip:1;   //!< Stop forwarding
                        uint32_t        reserved:17;  //!< Not implemented
                        uint32_t        node:3;       //!< Target node
                        uint32_t        pchip:3;      //!< Target chip
                        uint32_t        pcore:4;      //!<  core(1-6,9-14)
                        uint32_t        tspec:3;      //!< Target Thread
                    } PACKED;
                };
            };

            /**
             * cpu PIR register
             */
            struct PIR_t
            {
                union
                {
                    uint32_t word;
                    struct
                    {
                        //P8:
                        uint32_t        reserved:19;    //!< zeros
                        uint32_t        nodeId:3;       //!< node (0-3)
                        uint32_t        chipId:3;       //!< chip pos on node (0-5)
                        uint32_t        coreId:4;       //!< Core number (1-6,9-14)?
                        uint32_t        threadId:3;     //!< Thread number (0-7)
                    } PACKED;
                };
                PIR_t(uint32_t i_word) : word(i_word) {}

                PIR_t operator = (uint32_t i_word)
                {
                    word = i_word;
                    return word;
                }
            };

            struct intr_response_t
            {
                msg_q_t msgQ;
                uint32_t msgType;

                /**
                 * Default Constructor
                 */
                intr_response_t(): msgQ(NULL), msgType(0) {}

                /**
                 * Constructor
                 * @param[in] i_msgQ, The message queue
                 * @param[in] i_msgType, The message type
                 */
                intr_response_t(msg_q_t i_msgQ, uint32_t i_msgType) :
                    msgQ(i_msgQ), msgType(i_msgType) {}
            };


            typedef std::map<ext_intr_t,intr_response_t> Registry_t;
            typedef std::vector<PIR_t> CpuList_t;


            msg_q_t     iv_msgQ;        //!< Kernel Interrupt message queue
            Registry_t  iv_registry;    //!< registered interrupt type
            uint64_t    iv_baseAddr;    //!< Base address of hw INTR regs
            PIR_t       iv_masterCpu;   //!< Master cpu PIR
            CpuList_t   iv_cpuList;     //!< Other CPU chips


        private:        //functions

            errlHndl_t _init();

            /**
             * Message handler
             */
            void msgHandler();

            /**
             * Register a message queue for an interrupt type
             * @param[in] i_msgQ The message queue
             * @param[in] i_msg_type, The message type of the message to send
             *                        to i_msgQ when an interrupt of
             *                        i_intr_type occurrs.
             * @param[in] i_intr_type, The interrupt type to register.
             *
             * @note the interrupt type is currently the XISR value in the XIRR
             *       register and consists of the chipid, buid, and level
             *       @see src/include/usr/intr/interrupt.H i_intr_type for
             *       enumerations.
             *
             * @note when an interrupt of type i_msg_type occurrs, the
             * interrupt presenter sends a message with type i_msg_type to
             * i_msgQ with i_intr_type in message data word 0 and then waits
             * for a response.
             */
            errlHndl_t registerInterrupt(msg_q_t i_msgQ, 
                                         uint32_t i_msg_type,
                                         ext_intr_t i_intr_type);

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
             * Deconfigure the interrupt presenter registers
             * @param[in] i_pir, the PIR value for the presenter
             */
            void deconfigureInterruptPresenter(const PIR_t i_pir) const;

            /**
             * Set the IPCBAR scom register
             * @param[in] i_target, the Target.
             * @param[in] i_pir, The pir for this processor
             */
            errlHndl_t setBAR(TARGETING::Target * i_target,
                              const PIR_t i_pir);

            /**
             * Shutdown procedure
             */
            void shutDown();

            /**
             * Calculate the adress offset for the given cpu
             * @param[in] i_pir PIR value for the presenter
             * @return the offset
             */
                ALWAYS_INLINE
                uint64_t cpuOffsetAddr(const PIR_t i_pir) const
                {
                    // TODO when P7 support is removed then change this 
                    // to use InterruptMsgHdlr::mmio_offset()
                    uint64_t offset = (i_pir.nodeId  * 8) + i_pir.chipId;
                    offset <<= 20;
                    switch (cpu_core_type())
                    {
                        case CORE_POWER7:
                        case CORE_POWER7_PLUS:
                            offset |= static_cast<uint64_t>(i_pir.coreId) << 14;
                            break;

                        case CORE_POWER8_MURANO:
                        case CORE_POWER8_VENICE:
                        default:
                            offset |= static_cast<uint64_t>(i_pir.coreId) << 15;
                            break;
                    }
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

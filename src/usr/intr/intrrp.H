/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef INTRRP_H
#define INTRRP_H

#include <stdint.h>
#include <builtins.h>
#include <limits.h>
#include <errl/errlentry.H>
#include <kernel/intmsghandler.H>
#include <sys/msg.h>
#include <sys/misc.h>
#include <sys/time.h>
#include <sys/sync.h>
#include <sys/internode.h>
#include <intr/interrupt.H>
#include <map>
#include <list>
#include <algorithm>
#include <arch/pirformat.H>

struct msg_t;

namespace TARGETING
{
    class Target;
};

namespace INTR
{
    /**
     * @brief Utility function to get the list of enabled threads
     * @return Bitstring of enabled threads
     */
    uint64_t get_enabled_threads( void );

    class IntrRp
    {
        public:

            /**
             * Prepare HW and system to receive external interrupts
             * @param[in] ref to errlHndl_t
             */
            static void init( errlHndl_t &io_rtaskRetErrl );

            /**
             * Get the CPU id of the master cpu.
             * @return cpu id of the master cpu
             */
            ALWAYS_INLINE
            PIR_t intrDestCpuId() const { return iv_masterCpu; }

            /**
             * @brief Returns a boolean indicating whether the shutDown
             *        has been initiated for IntrRp
             * @return true IntrRp is shut down
             *         false IntrRp is running
             */
            bool isIntrRpShutdown() const;

        protected:

            /**
             * Constructor
             */
            IntrRp() :
                iv_msgQ(NULL),
                iv_baseAddr(0),
                iv_masterCpu(0),
                iv_IntrRpShutdownRequested(false) {}

            /**
             * Destructor
             */
            ~IntrRp() {}

            /**
             * Start message handler
             */
            static void* msg_handler(void * unused);

        private:        //Data

            enum
            {
                XIRR_RO_OFFSET = 0,            //!< offset to XIRR (poll)
                CPPR_OFFSET = 4,               //!< offset to CPPR (1 byte)
                XIRR_OFFSET = 4,               //!< offset to XIRR (4 bytes)
                MFRR_OFFSET = 12,              //!< offset to MFRR (12 bytes)
                LINKA_OFFSET = 16,             //!< offset to LINKA register
                LINKB_OFFSET = 20,             //!< offset to LINKB register
                LINKC_OFFSET = 24,             //!< offset to LINKC register
                XISR_MASK    = 0x00FFFFFF,     //!< XISR MASK in XIRR register
                CPPR_MASK    = 0xFF000000,     //!< CPPR MASK in XIRR register
                CPPR_ENABLE_ALL = 0xFF,        //!< All interrupt priorities

                ICPBAR_EN    = 30,              //!< BAR enable bit pos
                ICPBAR_SCOM_ADDR = 0x020109ca,  //!< ICP BAR scom address

                // MASK base ICP address
                ICPBAR_BASE_ADDRESS_MASK = 0xFFFFFFFFFC000000ULL,


                // The interrupt resource number ctr regs
                // Used to enable/disable and control interrupt routing
                NX_BUID_SCOM_ADDR       = 0x0201308E, //INTR CTRL for NX
                NX_BUID_ENABLE          = 0,          //INTR Enable bit for NX
                IRSN_COMP_MASK          = 0x7FFFF,
                NX_IRSN_MASK_MASK       = 0x1FFF,
                NX_IRSN_UPPER_MASK      = 0x7E000,
                NX_IRSN_COMP_SHIFT      = 44,
                NX_IRSN_MASK_SHIFT      = 31,

                PE0_IRSN_COMP_SCOM_ADDR = 0x0201201A, //INTR IRSN compare
                PE0_IRSN_MASK_SCOM_ADDR = 0x0201201B, //INTR IRSN mask
                PE0_BAREN_SCOM_ADDR     = 0x02012045, //INTR enable/disable

                PE1_IRSN_COMP_SCOM_ADDR = 0x0201241A, //INTR IRSN compare
                PE1_IRSN_MASK_SCOM_ADDR = 0x0201241B, //INTR IRSN mask
                PE1_BAREN_SCOM_ADDR     = 0x02012445, //INTR enable/disable

                PE2_IRSN_COMP_SCOM_ADDR = 0x0201281A, //INTR IRSN compare
                PE2_IRSN_MASK_SCOM_ADDR = 0x0201281B, //INTR IRSN mask
                PE2_BAREN_SCOM_ADDR     = 0x02012845, //INTR enable/disable

                // Bit pos in PEx_BAREN_SCOM register
                PE_IRSN_DOWNSTREAM = 3,         // downstream (PE RX enable)
                PE_IRSN_UPSTREAM = 4,           // upstream   (PE TX enable)
                PE_IRSN_SHIFT           = 45,
                MAX_PE_IRSN_SN          = 2048,


                PSI_FSP_INT_ENABLE      = 0x1000000000000000ULL,
                PSI_HBCR_AND_SCOM_ADDR  = 0x02010913,

                IPI_USR_PRIO        = 0x2,   //<! IPI priority from USR space

                SOURCE_MASK     = 0xFFFF,
                LSI_INTERRUPT   = 0xC000,

                //PSI Host Bridge Constants
                PSI_BRIDGE_BAR_SCOM_ADDR =          0x03011D0A,
                PSI_BRIDGE_BAR_ENABLE =             0x0000000000000001ULL,
                PSI_BRIDGE_ENABLE_CEC_INTERRUPT =   0x1000000000000000ULL,
                PSI_BRIDGE_ENABLE_LSI_INTR_REMOTE = 0x0000000000000000ULL,
                PSI_BRIDGE_FSP_BAR_SCOM_ADDR =      0x03011D0B,

                //PSI Host Bridge ESB Constants
                PSI_BRIDGE_ESB_BAR_SCOM_ADDR =      0x03011D16,
                PSI_BRIDGE_ESB_BAR_VALID =          0x0000000000000001ULL,
                PSI_BRIDGE_ESB_NOTIFY_VALID =       0x0000000000000001ULL,

                //XIVE Interrupt Controller Constants
                XIVE_IC_BAR_SCOM_ADDR =                 0x02010808,
                XIVE_IC_BAR_VALID =                     0x8000000000000000ULL,
                XIVE_IC_PHYSICAL_THREAD_ENABLE_OFFSET = 0x3000,
                XIVE_IC_BAR_INT_PC_MMIO_REG_OFFSET =
                         XIVE_IC_PHYSICAL_THREAD_ENABLE_OFFSET/sizeof(uint64_t),
                XIVE_IC_THREAD0_ENABLE =                0x8000000000000000ULL,
                XIVE_IC_ESB_LSI_TRIGGER_PAGE_OFFSET =   0x8000,
                XIVE_IC_ESB_EOI_OFFSET =                0x9000,
                XIVE_IC_LSI_EOI_OFFSET =
                                        XIVE_IC_ESB_EOI_OFFSET/sizeof(uint64_t),
                XIVE_IC_VPC_PULL_ERR =                  0x0000000200000000,
                XIVE_IC_PC_VSD_TABLE_ADDR_OFFSET =      0x488 / sizeof(uint64_t),
                XIVE_IC_PC_VSD_TABLE_DATA_OFFSET =      0x490 / sizeof(uint64_t),
                XIVE_IC_PC_VPD_BLOCK_MODE_OFFSET =      0x4A8 / sizeof(uint64_t),

                //XIVE IVPE (Presentation Engine) Constants
                INT_CQ_TM_BAR_SCOM_ADDR =  0x02010809,
                INT_CQ_TM_BAR_VALIDATE =   0x8000000000000000ULL,
                XIVE_IVPE_QW3_NSR_OFFSET = 0x30,
                XIVE_IVPE_QW3_VT_OFFSET =  0x38,
                XIVE_IVPE_QW3_LSI_ENABLE = 0x81,  //bit 0 is VT, bit 7 is le

                INT_TCTXT_CFG_SCOM_ADDR =    0x02010B28,
                INT_TCTXT_CFG_FUSE_CORE_EN = 0x0800000000000000,
                INT_TCTXT_CFG_HB_MODE      = 0x0000080000000000,

                PSI_BRIDGE_INTP_STATUS_CTL_CLR_SCOM_ADDR = 0x03011D13,
                PSI_BRIDGE_INTP_STATUS_CTL_ENABLE =        0x8000000000000000ULL,
                PSI_BRIDGE_INTP_STATUS_CTL_RESET =         0x4000000000000000ULL,
                PSI_BRIDGE_INTP_STATUS_CTL_DISABLE_PSI =   0x1000000000000000ULL,

                XIVE_RESET_INT_CQ_RST_CTL_SCOM_ADDR = 0x02010812,
                XIVE_RESET_POWERBUS_QUIESCE_ENABLE =  0x4000000000000000,
                XIVE_RESET_POWERBUS_QUIESCE_TIMEOUT = 1000000, //1 millisecond
                XIVE_RESET_UNIT_ENABLE =              0x8000000000000000,

                //For SMF use Hype offset as common between non SMF/SMF
                ACK_HYPERVISOR_INT_REG_OFFSET = 0x1830/sizeof(uint16_t),
                PULL_THREAD_CONTEXT_OFFSET =    0x1838/sizeof(uint8_t),

                POWERBUS_STATE_QUIESCE =   0xC000000000000000,
                MAX_PSU_LONG_TIMEOUT_NS  = 5000*NS_PER_MSEC, //5 seconds

                // ESB Page offsets -- This page format is used both in the
                //   PSIHB + LSI SBE EOI pages
                ESB_QUERY_OFFSET = 0x800,
                ESB_OFF_OFFSET   = 0xD00,
                ESB_RESET_OFFSET = 0XC00,

                //FIR REG Addrs
                INT_PC_ERR0_WOF   = 0x02010AC2,
                INT_PC_ERR0_FATAL = 0x02010AC4,
                INT_PC_ERR0_RECOV = 0x02010AC5,
                INT_PC_ERR0_INFO  = 0x02010AC6,
                INT_PC_ERR1_WOF   = 0x02010ACA,
                INT_PC_ERR1_FATAL = 0x02010ACC,
                INT_PC_ERR1_RECOV = 0x02010ACD,
                INT_PC_ERR1_INFO  = 0x02010ACE,

                INT_VC_WOF_ERR_G0   = 0x020109C2,
                INT_VC_WOF_ERR_G1   = 0x020109CA,
                INT_VC_FATAL_ERR_G0 = 0x020109C4,
                INT_VC_FATAL_ERR_G1 = 0x020109CC,
                INT_VC_RECOV_ERR_G0 = 0x020109C5,
                INT_VC_RECOV_ERR_G1 = 0x020109CD,
                INT_VC_INFO_ERR_G0  = 0x020109C6,
                INT_VC_INFO_ERR_G1  = 0x020109CE,

                INT_CQ_WOF          = 0x02010838,
                INT_CQ_FIR          = 0x02010832,
            };

            enum INTR_ROUTING_t
            {
                INTR_UPSTREAM,
                INTR_DOWNSTREAM,
            };

            // If the interrupt can't be handled by the current chip there are
            // three link registers used provide targets to forward the
            // interrupt to.
            //
            // P8:
            // [0] last
            // [1] LoopTrip
            // [2:18] Reserved
            // [19:21] GroupId
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

            //Found in the PC Register Specification Document
            struct XIVE_IC_THREAD_CONTEXT_t
            {
                uint64_t phys_thread_enable0;       //0x000
                uint64_t unused0;                   //0x008
                uint64_t phys_thread_enable0_set;   //0x010
                uint64_t phys_thread_enable0_reset; //0x018
                uint64_t phys_thread_enable1;       //0x020
                uint64_t unused1;                   //0x028
                uint64_t phys_thread_enable1_set;   //0x030
                uint64_t phys_thread_enable1_reset; //0x038
            };

            //Found in External Interrupt Virtualization Engine (XIVE) Document
            // in Chapter 4.4 - Per Thread Interrupt Management Area
            struct XIVE_IVPE_THREAD_CONTEXT_t
            {
                uint64_t qw0_0;
                uint64_t qw0_1;
                uint64_t qw1_0;
                uint64_t qw1_1;
                uint64_t qw2_0;
                uint64_t qw2_1;
                uint8_t nsr; //Notification Source Register    - 0x0
                uint8_t cppr; //Current processor priority register - 0x1
                uint8_t ipb; //Interrupt pending buffer - 0x2
                uint8_t lsmfb; //logical server most favored backlog - 0x3
                uint8_t ack; //O/S Interrupt Acknowledge Counter - 0x4
                uint8_t inc; //Age increment - 0x5
                uint8_t age; //Thread age since last selected - 0x6
                uint8_t pipr; //Pending Interrupt Priority Register - 0x7
                uint8_t cams_vt;   //qw0/1/2/3 - 0x8
                uint8_t cams_rsv;  //qw0/1/2/3 - 0x9
                uint8_t cams_rsv1; //qw0/1/2/3 - 0xA
                uint8_t cams_prio; //qw0/1/2/3 - 0xB
            };

            #define PSIHB_SW_INTERFACES_SIZE (sizeof(PSIHB_SW_INTERFACES_t))
            #define XIVE_IVPE_THREAD_CONTEXT_SIZE (sizeof(XIVE_IVPE_THREAD_CONTEXT_t))
            /**
             * This is the Interrupt Requester Source Compare Register.
             * See Book IV, PSI chapter.
             */
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

            struct intr_hdlr_t
            {
                TARGETING::Target     *proc;
                PSIHB_SW_INTERFACES_t *psiHbBaseAddr;
                uint64_t              *psiHbEsbBaseAddr;
                uint64_t              *xiveIcBarAddr;

                intr_hdlr_t():  proc(NULL), psiHbBaseAddr(NULL),
                                   psiHbEsbBaseAddr(NULL) {}
                intr_hdlr_t(TARGETING::Target *i_target)  :
                                   proc(i_target), psiHbBaseAddr(NULL),
                                   psiHbEsbBaseAddr(NULL) {}
            };

            enum
            {
                CPU_WAKEUP_SECONDS = 1,
                CPU_WAKEUP_INTERVAL_COUNT = 10,
                CPU_WAKEUP_INTERVAL_NS = (NS_PER_SEC * CPU_WAKEUP_SECONDS) /
                                         CPU_WAKEUP_INTERVAL_COUNT,
            };

            typedef std::map<ext_intr_t,intr_response_t> Registry_t;
            typedef std::vector<PIR_t> CpuList_t;
            typedef std::vector<intr_hdlr_t *> ChipList_t;
            typedef std::vector<ISNvalue_t> ISNList_t;
            typedef std::list<ext_intr_t> UnregisteredSourceList_t;
            typedef std::vector< std::pair<PIR_t,ext_intr_t> >PendingIntrList_t;

            msg_q_t     iv_msgQ;        //!< Kernel Interrupt message queue
            Registry_t  iv_registry;    //!< registered interrupt type
            uint64_t    iv_baseAddr;    //!< Base address of hw INTR regs
            PIR_t       iv_masterCpu;   //!< Master cpu PIR

            intr_hdlr_t *iv_masterHdlr; //!< Master cpu interrupt handler
            uint64_t    *iv_xiveIcBarAddress; //XIVE Controller regs base addr
            uint64_t    *iv_intCqTmBarAddress; //Xive Thread mgmt bar reg 1 addr
            CpuList_t   iv_cpuList;     //!< Other CPU chips
            ChipList_t  iv_chipList;    //!< Proc chips with PSI intr enabled
            ISNList_t   iv_isnList;     //!< List of ISN's to clear on shutdown
            PendingIntrList_t iv_pendingIntr; //!< List of pending interrupts
                                              // That haven't been EOI'ed
            UnregisteredSourceList_t iv_unregisterdLsiSources;

            typedef std::pair<uint64_t, msg_t*> IPI_Info_t;
            typedef std::map<PIR_t, IPI_Info_t> IPI_Pending_t;
            IPI_Pending_t iv_ipisPending;  //!< Pending IPIs.
            bool iv_IntrRpShutdownRequested; //!< Whether the shutdown of IntrRp
                                             // has been requested.

            // PE regs
            static const uint32_t cv_PE_IRSN_COMP_SCOM_LIST[]; //IRSN comp regs
            static const uint32_t cv_PE_IRSN_MASK_SCOM_LIST[]; //IRSN mask regs
            static const uint32_t cv_PE_BAR_SCOM_LIST[];       //IRSN enable

            // Mutex to prevent potential race conditions in IntRp shutdown and
            // complete interrupt processing paths.
            mutex_t iv_intrRpMutex;

        private:        //functions

            errlHndl_t _init();

            /**
             * Do a read from LSI ESB EOI page to enable presentation of LSI
             * interrupt to Hostboot
             */
            void enableLsiInterrupts();

            /**
             * Do a read from LSI ESB EOI page to disable presentation of LSI
             * interrupt to Hostboot
             */
            void disableLsiInterrupts();

            /**
             * Clear INT_PC registers that didn't get cleared by the HW reset
             * during the SBE steps of the MPIPL
             */
            void clearIntPcRegs();

            /**
             * Clear bit 3 of the PSIHB Control/Status register to disable
               PSI interrupts from interrupting the CEC.
             */
            void disablePsiInterrupts(intr_hdlr_t* i_proc);

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
             * @note the interrupt type is currently the ISN value in the XIVR
             *       register.   and consists of the chipid, buid, and level
             *       @see src/include/usr/intr/interrupt.H i_intr_type for
             *       enumerations.
             *
             * @note when an interrupt of type i_msg_type occurrs, the
             * interrupt presenter sends a message with type i_msg_type to
             * i_msgQ with i_intr_type in message data word 0 and then waits
             * for a response.
             */
            errlHndl_t registerInterruptISN(msg_q_t i_msgQ,
                                         uint32_t i_msg_type,
                                         ext_intr_t i_intr_type);
            /* Same as above, but operates directly on XISR*/
            errlHndl_t registerInterruptXISR(msg_q_t i_msgQ,
                                         uint32_t i_msg_type,
                                         ext_intr_t i_xisr);

            /**
             * Unregister for a given interrupt type
             * @param[in] i_isn_type The type of interrupt to unregister
             *
             * @note the interrupt type is currently the ISN value in the PSIHB
             *       XIVR register
             *       @see  i_intr_type for enumerations.
             *
             * @return The message queue that was unregistered with i_type
             *         | NULL if no queue was not found for i_type
             */
            msg_q_t unregisterInterruptISN(ISNvalue_t i_intr_type);
            /*Same as above, but operates on XISR*/
            msg_q_t unregisterInterruptXISR(ext_intr_t i_xisr);

            /**
             * Enable hardware to reporting external interrupts
             * @param[in] i_proc Proc handler for processor to enable
             *                   interrupts for
             */
            errlHndl_t enableInterrupts(intr_hdlr_t *i_proc);

            /**
             * Disable hardware from reporting external interupts
             * @param[in] i_proc Proc handler for processor to enable
             *                   interrupts for
             */
            errlHndl_t disableInterrupts(intr_hdlr_t *i_proc);

            /**
             * Initialize the interrupt presenter registers
             * @param[in] i_pir  PIR value for the presenter
             */
            void initInterruptPresenter(const PIR_t i_pir) const;

            /**
             * Disable the interrupt presenter
             * @param[in] i_pir, the PIR value for the presenter
             */
            void disableInterruptPresenter(const PIR_t i_pir) const;

            /**
             * Issue IPI to a thread.
             * @param[in] i_pir - The PIR value of the core to send IPI to.
             */
            void sendIPI(const PIR_t i_pir) const;

            /**
             * Mask all PSIHB Interrupt Sources which will block any
             * interrupts from the PSIHB to be sent to the HB kernel.
             * @return Errorlog from masking the sources
             */
            errlHndl_t maskAllInterruptSources();

            /**
             * Mask specific PSIHB Interrupt source
             * @param[in] i_intr_source, The interrupt source to be masked
             * @param[in] i_proc, The proc interrupt handler
             * @return Errorlog from masking the source
             */
            errlHndl_t maskInterruptSource(uint8_t i_intr_source,
                                           intr_hdlr_t *i_proc);

            /**
             * Mask specific PSIHB Interrupt source
             * @param[in] i_intr_source, The interrupt source to be masked
             * @return Errorlog from masking the source
             */
            errlHndl_t maskInterruptSource(uint8_t i_intr_source);

            /**
             * Unmask (enable) specific PSIHB Interrupt source
             * @param[in] i_intr_source, The interrupt source to be unmasked
             * @param[in] i_proc, The proc interrupt handler to unmask the
             *                   given interrupt source for
             * @return Errorlog from unmasking the source
             */
            errlHndl_t unmaskInterruptSource(uint8_t i_intr_source,
                                             intr_hdlr_t *i_proc,
                                             bool i_force_unmask=false);

            /**
             * Set all of the Interrupt BAR scom registers specific
             *   to the master chip.
             * @param[in] i_target, the Target.
             * @param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setMasterInterruptBARs(TARGETING::Target * i_target,
                                              bool i_enable=true);

            /**
             * Set all of the Interrupt BAR scom registers common
             *   to all the chips (procs)
             * @param[in] i_proc, the interrupt handler for one chip
             * @param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setCommonInterruptBARs(intr_hdlr_t * i_proc,
                                              bool i_enable=true);

            /**
             * Perform HW Functions to set Hostboot (HB) mode
             * on the INT_TCTXT Register for all functional procs
             * @param[in] i_procIntrHdlr the interrupt handler for one chip
             *            (must not be nullptr)
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setHbModeOnTctxtCfgReg(intr_hdlr_t * i_procIntrHdlr);

            /**
             * Perform HW Functions to acknowledge Interrupt which will
             * stop the interrupt from being re-presented by HW
             */
            void acknowledgeInterrupt(void);

            /**
             * Send EOI (End of Interrupt) sequence
             * @param[in] i_intSource, interrupt source to perform EOI for
             * @param[in] i_pir, The PIR value for the proc where the
             *      interrupt condtion occurred
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t sendEOI(uint64_t& i_intSource, PIR_t& i_pir);

            /**
             * Send the XIVE portion of the EOI (End of Interrupt) sequence
             * @param[in] i_intSource, interrupt source to perform EOI for
             * @param[in] i_pir, The PIR value for the proc where the
             *     interrupt condtion occurred
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t sendXiveEOI(uint64_t& i_intSource, PIR_t& i_pir);

            /**
             * Send the PSI Host Bridge portion of the EOI (End of Interrupt)
             *      sequence
             * @param[in] i_proc, the proc intrp handler
             * @param[in] i_intSource, interrupt source to perform EOI for
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t sendPsiHbEOI(intr_hdlr_t* i_proc, uint64_t& i_intSource);

            /**
             * Function completes interrupt processing
             *   - Unmasks interrupt source
             *   - Sends XIVE EOI
             * @param[in] i_intSource, interrupt source to perform EOI for
             * @param[in] i_pir, The PIR value for the proc where the
             *     interrupt condtion occurred
             **/
            void completeInterruptProcessing(uint64_t& i_intSource,
                                             PIR_t& i_pir);

            /**
             * Route Interrupt to correct listener
             * @param[in] i_proc, the proc intrp handler
             * @param[in] i_type, the interrupt type
             * @param[in] i_pir, the pir value for the proc the interrupt
             *                   was seen on
             */
            void routeInterrupt(intr_hdlr_t* i_proc,
                                ext_intr_t i_type,
                                PIR_t& i_pir);

            /**
             * Read External PSIHB Interrupt conditions and handle
             *    appropriately. Routing interrupts to the registered
             *    listeners. Also, handles PSU interrupts as INTRP is
             *    the PSU interrupt listener
             */
            void handleExternalInterrupt();

            /**
             * Handle Interrupt from PSU Source
             *   - Acknowledge Interrupt
             *   - Clear Interrupt Condition
             *   - Issue EOI
             * @param[in] i_type, interrupt type encountered
             * @param[in] i_proc, The proc interrupt handler for the proc
             *                    the interrupt occurred on
             * param[in]  i_pir, The PIR value for the proc the interrupt
             *                    was seen on
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t handlePsuInterrupt(ext_intr_t i_type,
                                          intr_hdlr_t* i_proc,
                                          PIR_t& i_pir);
            /**
             *  @brief Set the FSP BAR
             *
             *  @param[in] i_pProcIntrHdlr Pointer to processor interrupt
             *      handler structure; must not be nullptr or function will
             *      assert.  Referenced proc target must also not be nullptr, or
             *      same consequence.
             *  @param[in] i_enable Whether to enable/disable the BAR (disable
             *      request is no-op for this BAR)
             *
             *  @return errlHndl_t Error log handle on failure, nullptr on
             *      success
             */
            errlHndl_t setFspBAR(
                const intr_hdlr_t* i_pProcIntrHdlr,
                      bool         i_enable);

            /**
             * Set the PSI Host Bridge BAR scom register
             * @param[in] i_proc, the proc intrp handler
             * param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setPsiHbBAR(intr_hdlr_t* i_proc,
                                   bool i_enable);

            /**
             * Set the PSI Host Bridge ESB BAR scom register
             * @param[in] i_proc, the proc intrp handler.
             * @param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setPsiHbEsbBAR(intr_hdlr_t* i_proc,
                                                bool i_enable);

            /**
             * Set the INT CQ TM BAR scom register
             * @param[in] i_target, the Target
             * @param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setIntCqTmBAR(TARGETING::Target * i_target,
                                         bool i_enable);

            /**
             * Set the XIVE Interrupt Controller (IC) BAR scom register
             * @param[in] i_proc, the proc intrp handler
             * @param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setXiveIcBAR(intr_hdlr_t* i_proc,
                                    bool i_enable);

            /**
             * Reset Interrupt Unit (both the XIVE and PSIHB Interrupt Units)
             * @param[in] i_proc, the proc intrp handler
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t resetIntUnit(intr_hdlr_t* i_proc);

            /**
             * Setup structures, BAR Regs, Mask interrupts, and enable interrupt
             * routing on non-master proc chip
             * @param[in] i_target, the proc Target to enable
             * @return Errorlog from enablement steps
             */
            errlHndl_t enableSlaveProcInterrupts(TARGETING::Target * i_target);

            /**
             * Set correct PSIHB Regs to route + enable LSI interrupts from
             * any proc to correct address on master proc.
             *
             * This is used on the master proc as a workaround for a HW bug
             * involving lsi triggers on the local wire. This forces the lsi
             * trigger over the PSIHB working around the HW issue
             * @param[in] i_proc, the proc intrp handler
             * @return void
             */
            void routeLSIInterrupts(intr_hdlr_t* i_proc);

            /**
             * Initialize the IRSCReg to enable PSI to present interrupts
             * @param[in] i_target  The target processor
             * @return error log handle on error
             */
            errlHndl_t initIRSCReg(TARGETING::Target * i_target);

            /**
             * Initialize the PSIHB XIVR Reg to generate interrupts
             * on all processors for given ISN
             * @param[in] i_isn      XIVR to enable/disable
             * @param[in] i_enable   enable (true), disable(false)
             * @return error log handle on error
             */
            errlHndl_t initXIVR(enum ISNvalue_t i_isn, bool i_enable);

            /**
             * Setup XIVR with intr masked and isn & destination set for
             * xivr/isn that hostboot uses.
             * @param i_target : The target processor chip
             * @return error handle
             */
            errlHndl_t maskXIVR(TARGETING::Target * i_target);

            /*
             * Disable HW from receiving interrupts
             * @param i_proc  The processor chip target to disable
             * @param i_rx_tx [INTR_UPSTREAM | INTR_DOWNSTREAM]
             * @return an error handle on error
             */
            errlHndl_t hw_disableRouting(TARGETING::Target * i_proc,
                                         INTR_ROUTING_t i_rx_tx);

            /*
             * During MPIPL issue EOIs (blind) to all ISNs
             * @param i_proc  The processor chip target to issue EOIs for
             * @return an error handle on error
             */
            errlHndl_t blindIssueEOIs(TARGETING::Target * i_proc);


            /**
             * Reset ISRN value in hardware regs
             * @param i_proc  The target processor
             * @return an error handle on error
             */
            errlHndl_t hw_resetIRSNregs(TARGETING::Target * i_proc);

            /**
             * Build a list of "functional" processors.  This needs to be
             * done without targeting support (just blueprint) since
             * on MPIPL the targeting information is obtained in
             * discover_targets -- much later in the IPL.
             *

             * @param o_proc  List of "functional" processors on SMP
             * @param o_cores List of cores under functional processors
             * @return an error handle on error
             */
            errlHndl_t findProcs_Cores(TARGETING::TargetHandleList & o_procs,
                                       TARGETING::TargetHandleList& o_cores);

            /**
             * disableHwMpIpl
             */
            errlHndl_t hw_disableIntrMpIpl();


            /**
             * Read the NX interrupt source number out of the HW
             *
             * @param i_target  Processor target to read value from
             * @param o_irsn    IRSN of the NX unit for the processor
             * @param o_num     Number of interrupts behind IRSN
             * @return an error handle on error
             */
            errlHndl_t getNxIRSN(TARGETING::Target * i_target,
                                 uint32_t& o_irsn,
                                 uint32_t& o_num);


            /**
             * Drain all outstanding interrupts during MPIPL
             * @param i_cores  List of all existing cores on functional procs
             */
            void drainMpIplInterrupts(TARGETING::TargetHandleList & i_cores);

            /**
             * Disable all interrupts on passed in core
             * @param i_core  Core to disable interrupts on
             */
            void disableAllInterrupts(TARGETING::Target* i_core);

            /**
             * Allow all interrupts on passed in core
             * @param i_core  Core to enable interrupts on
             */
            void allowAllInterrupts(TARGETING::Target* i_core);

            /**
             * Shutdown procedure
             * @param[in] shutdown status.
             *            Set to SHUTDOWN_STATUS_GOOD on a clean shutdown,
             *            Otherwise is plid or other ShutdownStatus enum.
             *            @see ShutdownStatus enums in sys/misc.h
             */
            void shutDown(uint64_t i_status);

            /**
             * Wait for all nodes to disable interrupts on MPIPL
             * @param[in] i_sync_type, the type of event to sync on
             *            @see src/include/sys/internode.h
             * @return err log handle
             */
            errlHndl_t syncNodes(intr_mpipl_sync_t i_sync_type);

            /**
             * Initailize the mpipl node sync data area for this HB instance
             * @return err log handle
             */
            errlHndl_t  initializeMpiplSyncArea();

            /**
             * Add the existence of another HB instance to this instance
             * mpipl sync data area.
             * @param[in] The instance number of the HB instance to add
             * @return error log handle
             */
            errlHndl_t  addHbNodeToMpiplSyncArea(uint64_t i_hbNode);

            /**
             * Calculate the address offset for the given cpu
             * @param[in] i_pir PIR value for the presenter
             * @return the offset
             */
            ALWAYS_INLINE
                uint64_t cpuOffsetAddr(const PIR_t i_pir) const
                {
                    return InterruptMsgHdlr::mmio_offset(i_pir.word);
                }

            /**
             * Validity check for an I/O address
             * @param[in] i_addr the address
             * @return error log if not valid
             */
            static errlHndl_t checkAddress(uint64_t i_addr);

            /**
             * Background thread to handle if a core doesn't wake up.
             * @param[in] _pir - The PIR value (as void*) to check for.
             */
            static void* handleCpuTimeout(void* _pir);

            /**
             * Reset the INTP components to prepare for MPIPL
             * @return error log handle
             */
            errlHndl_t resetIntpForMpipl(void);

            /**
            * Print out the ESB state for every source on all processors
            * that the Interrp is aware of
            *
            * @return void
            */
            void printEsbStates() const;

            /**
            * Print out the PSIHB info for all processors
            * that the Interrp is aware of
            *
            * @return void
            */
            void printPSIHBInfo() const;

            /**
            * Print out the LSI info for all processors
            * that the Interrp is aware of
            *
            * @return void
            */
            void printLSIInfo() const;

             /**
             * Clear all interrupt related firs
             * This is needed because in multi-node systems nodes
             * are not inconcert during the MPIPL steps so outstanding
             * traffic from one node might cause FIRs to pop on another
             * because they were at different points of the MPIPL. This function
             * clears any firs that might have occured to allow us to start fresh
             *
             * @return error log handle
             */
            errlHndl_t clearAllIntFirs();
    };
}; // INTR namespace

#endif

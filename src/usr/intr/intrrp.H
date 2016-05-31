/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#include <sys/internode.h>
#include <intr/interrupt.H>
#include <map>
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
     * Make an XISR value
     * @param[in] i_node  The PIR node id (0-7)
     * @param[in] i_chip  The PIR chip id (0-7)
     * @param[in] i_isn   The Interrupt Source Number (0-7)
     * @return the XISR value
     */
    inline
      uint32_t makeXISR(PIR_t i_pir, uint32_t i_isn)
    {
        XISR_t r;
        r.u32 = 0;
        r.isn = i_isn;
        r.chip = i_pir.chipId;
        r.node = i_pir.groupId;
        r.intrproc = 1;  // not interproc intr
        return r.u32;
    }

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

        protected:

            /**
             * Constructor
             */
            IntrRp() :
                iv_msgQ(NULL),
                iv_baseAddr(0),
                iv_masterCpu(0),
                iv_psiHbBaseAddr(NULL),
                iv_psiHbEsbBaseAddr(NULL) {}

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

                LSI_SOURCE_MASK = 0xFFFF,
                LSI_INTERRUPT   = 0xC000,

                //PSI Host Bridge Constants
                PSI_BRIDGE_BAR_SCOM_ADDR = 0x0501290A,
                PSI_BRIDGE_BAR_ENABLE = 0x0000000000000001ULL,
                PSI_BRIDGE_ENABLE_CEC_INTERRUPT = 0x1000000000000000ULL,
                PSI_BRIDGE_ESB_BAR_SCOM_ADDR = 0x05012916,

                //PSI Host Bridge ESB Constants
                PSI_BRIDGE_ESB_BAR_VALID = 0x0000000000000001ULL,
                PSI_BRIDGE_ESB_OFF_OFFSET = 0xD00,
                PSI_BRIDGE_ESB_RESET_OFFSET = 0XC00,
                PSI_BRIDGE_PSU_DOORBELL_REG = 0x000D0063,
                PSI_BRIDGE_PSU_HOST_DOORBELL = 0x8000000000000000,

                //XIVE Interrupt Controller Constants
                XIVE_IC_BAR_SCOM_ADDR = 0x05013010,
                XIVE_IC_BAR_VALID = 0x8000000000000000ULL,
                XIVE_IC_PHYSICAL_THREAD_ENABLE_OFFSET = 0x400,
                XIVE_IC_BAR_INT_PC_MMIO_REG_OFFSET =
                         XIVE_IC_PHYSICAL_THREAD_ENABLE_OFFSET/sizeof(uint64_t),
                XIVE_IC_THREAD0_ENABLE = 0x8000000000000000ULL,
                XIVE_IC_ESB_EOI_OFFSET = 0x3000,
                XIVE_IC_LSI_EOI_OFFSET =
                                        XIVE_IC_ESB_EOI_OFFSET/sizeof(uint64_t),
                XIVE_IC_VPC_PULL_ERR = 0x0000000200000000,

                //XIVE IVPE (Presentation Engine) Constants
                XIVE_IVPE_TM_BAR1_SCOM_ADDR = 0x05013012,
                XIVE_IVPE_TM_BAR1_MMIO_OFFSET = 0x0006020000000000ULL,
                XIVE_IVPE_TM_BAR1_VALIDATE = 0x8000000000000000ULL,
                XIVE_IVPE_QW3_OFFSET = 0x38,
                XIVE_IVPE_QW3_LSI_ENABLE = 0x81,

                PSI_BRIDGE_INTP_STATUS_CTL_SCOM_ADDR = 0x0501290E,
                PSI_BRIDGE_INTP_STATUS_CTL_CLR_SCOM_ADDR = 0x05012913,
                PSI_BRIDGE_INTP_STATUS_CTL_ENABLE = 0x8000000000000000ULL,
                PSI_BRIDGE_INTP_STATUS_CTL_RESET = 0x4000000000000000ULL,
                PSI_BRIDGE_INTP_STATUS_CTL_DISABLE_PSI = 0x1000000000000000ULL,

                XIVE_RESET_INT_CQ_RST_CTL_SCOM_ADDR = 0x05013023,
                XIVE_RESET_POWERBUS_QUIESCE_ENABLE = 0x4000000000000000,
                XIVE_RESET_POWERBUS_QUIESCE_TIMEOUT = 1000000, //1 millisecond
                XIVE_RESET_UNIT_ENABLE = 0x8000000000000000,
                ACK_HYPERVISOR_INT_REG_OFFSET = 0x830/sizeof(uint16_t),
                POWERBUS_STATE_QUIESCE = 0xC000000000000000,
                MAX_PSU_LONG_TIMEOUT_NS  = 100000*NS_PER_MSEC,

                ESB_STATE_RESET   = 0,
                ESB_STATE_OFF     = 1,
                ESB_STATE_PENDING = 2,
                ESB_STATE_QUEUED  = 3,
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

            //Derived from 15.8 PSIHB Software Interfaces of the
            //  P9 Pervasive Workbook
            struct PSIHB_SW_INTERFACES_t
            {
                uint64_t psihbbar; //Host Bridge Base Address Register    - 0x0
                uint64_t fspbar;   //FSP Base Address Register            - 0x8
                uint64_t fspmmr;   //FSP Memory Mask Register             - 0x10
                uint64_t reserved1; //Unused / Reserved
                uint64_t psihbcr;  //PSI Host Bridge Ctrl/Status Register - 0x20
                uint64_t psisemr;  //PSIHB Status / Error Mask Register   - 0x28
                uint64_t reserved2; //Unused / Reserved
                uint64_t phbdsr;   //PSIHB Debug Setting register         - 0x38
                uint64_t phbscr;   //PSI Host Bridge Ctrl/Status Register - 0x40
                uint64_t phbccr;   //PSI Host Bridge clear ctl/status reg - 0x48
                uint64_t dmaupaddr; //DMA Upper Address Register          - 0x50
                uint64_t icr;      //Interrupt Control Register           - 0x58
                uint64_t esbciaddr; //ESB CI Base Address                 - 0x60
                uint64_t esbnotifaddr; //ESB Notification Address         - 0x68
                uint64_t ivtofforig; //IVT Offset Origin Register         - 0x70
                uint64_t lsiintlevel; //LSI Int Level Register (lab use)  - 0x78
                uint64_t lsiintstatus; //LSI Interrupt Status register    - 0x80
            };

            //Found in the PC Register Specification Document
            struct XIVE_IC_THREAD_CONTEXT_t
            {
                uint64_t tctxt_cfg;   // 0x00
                uint64_t tctxt_track; // 0x08
                uint64_t unused0;     // 0x10
                uint64_t unused1;     // 0x18
                uint64_t ind_thread_context_access0; //0x20
                uint64_t ind_thread_context_access1; //0x28
                uint64_t ind_thread_context_access2; //0x30
                uint64_t ind_thread_context_access3; //0x38
                uint64_t phys_thread_enable0; //0x40
                uint64_t phys_thread_enable0_set; //0x48
                uint64_t phys_thread_enable0_reset; //0x50
                uint64_t unused3;    //0x58
                uint64_t phys_thread_enable1; //0x60
                uint64_t phys_thread_enable1_set; //0x68
                uint64_t phys_thread_enable1_reset; //0x70
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

            enum
            {
                CPU_WAKEUP_SECONDS = 1,
                CPU_WAKEUP_INTERVAL_COUNT = 10,
                CPU_WAKEUP_INTERVAL_NS = (NS_PER_SEC * CPU_WAKEUP_SECONDS) /
                                         CPU_WAKEUP_INTERVAL_COUNT,
            };

            typedef std::map<ext_intr_t,intr_response_t> Registry_t;
            typedef std::vector<PIR_t> CpuList_t;
            typedef std::vector<TARGETING::Target *> ChipList_t;
            typedef  std::vector<ISNvalue_t> ISNList_t;

            msg_q_t     iv_msgQ;        //!< Kernel Interrupt message queue
            Registry_t  iv_registry;    //!< registered interrupt type
            uint64_t    iv_baseAddr;    //!< Base address of hw INTR regs
            PIR_t       iv_masterCpu;   //!< Master cpu PIR

            PSIHB_SW_INTERFACES_t *iv_psiHbBaseAddr; //INTR PSIHB regs base addr
            uint64_t    *iv_psiHbEsbBaseAddr; //INTR PSIHB ESB regs base addr
            uint64_t    *iv_xiveIcBarAddress; //XIVE Controller regs base addr
            uint64_t    *iv_xiveTmBar1Address; //Xive Thread mgmt bar reg 1 addr
            CpuList_t   iv_cpuList;     //!< Other CPU chips
            ChipList_t  iv_chipList;    //!< Proc chips with PSI intr enabled
            ISNList_t   iv_isnList;     //!< List of ISN's to clear on shutdown

            typedef std::pair<uint64_t, msg_t*> IPI_Info_t;
            typedef std::map<PIR_t, IPI_Info_t> IPI_Pending_t;
            IPI_Pending_t iv_ipisPending;  //!< Pending IPIs.

            // PE regs
            static const uint32_t cv_PE_IRSN_COMP_SCOM_LIST[]; //IRSN comp regs
            static const uint32_t cv_PE_IRSN_MASK_SCOM_LIST[]; //IRSN mask regs
            static const uint32_t cv_PE_BAR_SCOM_LIST[];       //IRSN enable

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
            errlHndl_t maskAllInterruptSources(void);

            /**
             * Mask specific PSIHB Interrupt source
             * @param[in] i_intr_source, The interrupt source to be masked
             * @return Errorlog from masking the source
             */
            errlHndl_t maskInterruptSource(uint8_t i_intr_source);

            /**
             * Unmask (enable) specific PSIHB Interrupt source
             * @param[in] i_intr_source, The interrupt source to be unmasked
             * @return Errorlog from unmasking the source
             */
            errlHndl_t unmaskInterruptSource(uint8_t i_intr_source);

            /**
             * Set all of the Interrupt BAR scom registers
             * @param[in] i_target, the Target.
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setInterruptBARs(TARGETING::Target * i_target);

            /**
             * Perform HW Functions to acknowledge Interrupt which will
             * stop the interrupt from being re-presented by HW
             */
            void acknowledgeInterrupt(void);

            /**
             * Send EOI (End of Interrupt) sequence
             * @param[in] i_intSource, interrupt source to perform EOI for
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t sendEOI(uint64_t& i_intSource);

            /**
             * Handle Interrupt from PSU Source
             *   - Acknowledge Interrupt
             *   - Clear Interrupt Condition
             *   - Issue EOI
             * @param[in] i_type, interrupt type encountered
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t handlePsuInterrupt(ext_intr_t i_type);

            /**
             * Set the PSI Host Bridge BAR scom register
             * @param[in] i_target, the Target.
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setPsiHbBAR(TARGETING::Target * i_target);

            /**
             * Set the PSI Host Bridge ESB BAR scom register
             * @param[in] i_target, the Target.
             * @param[in] i_enable, indicator to enable/disable the BAR
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setPsiHbEsbBAR(TARGETING::Target * i_target,
                                                bool i_enable);

            /**
             * Set the XIVE Thread Management (TM) BAR1 scom register
             * @param[in] i_target, the Target.
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setXiveIvpeTmBAR1(TARGETING::Target * i_target);

            /**
             * Set the XIVE Interrupt Controller (IC) BAR scom register
             * @param[in] i_target, the Target.
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t setXiveIcBAR(TARGETING::Target * i_target);

            /**
             * When in LSI mode the IC VPC flags and error, thus we
             * need to disable while we use, and enable after we clean
             * up
             * @param[in] i_target, the Target.
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t disableVPCPullErr(TARGETING::Target * i_target);

            /**
             * When in LSI mode the IC VPC flags and error, thus we
             * need to disable while we use, and enable after we clean
             * up
             * @param[in] i_target, the Target.
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t enableVPCPullErr(TARGETING::Target * i_target);

            /**
             * Reset Interrupt Unit (both the XIVE and PSIHB Interrupt Units)
             * @return Errorlog from DeviceWrite
             */
            errlHndl_t resetIntUnit();

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
             * Read the Psi interrupt source number out of the HW
             *
             * @param i_target  Processor target to read value from
             * @param o_irsn    IRSN of the PSI unit for the processor
             * @param o_num     Number of interrupts behind IRSN
             * @return an error handle on error
             */
            errlHndl_t getPsiIRSN(TARGETING::Target * i_target,
                                  uint32_t& o_irsn, uint32_t& o_num);

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
             * Extract node information stored away and restore into
             * ATTR for MPIPL
             * @return error log handle
             */
            errlHndl_t  extractHbNodeInfo(void);

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

    };
}; // INTR namespace

#endif

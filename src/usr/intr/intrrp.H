/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/intrrp.H $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <intr/interrupt.H>
#include <map>
#include <algorithm>

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
        r.node = i_pir.nodeId;
        r.intrproc = 1;  // not interproc intr
        return r.u32;
    }

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
                iv_masterCpu(0) {}

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
             * This is the Interrupt Requestoer Source Compare Register.
             * See Book IV, PSI chapter.
             */
            struct PSIHB_ISRN_REG_t
            {
                enum
                {
                    //PSIHB_ISRN_REG_t values. See book IV & P8 scom reg defn.
                    DISABLE                 = 0,
                    ENABLE                  = 1,
                    IRSN_MASK               = 0x7FFF8,    //!< IRSN bits
                    PSIHB_ISRN_REG          = 0x0201091b, //!< ISRN SCOM Address
                };

                union
                {
                    uint64_t    d64;

                    struct
                    {
                        uint64_t irsn:19;       //!< IRSN compare reg
                        uint64_t res1:10;       //!< zeros
                        uint64_t reset:1;       //!< ICS Reset
                        uint64_t die:1;         //!< Downstream Interrupt Enable
                        uint64_t uie:1;         //!< Upstream Interrupt Enable
                        uint64_t mask:19;       //!< IRSN Compare Mask
                        uint64_t res2:13;       //!< zeros
                    } PACKED;
                };

                /**
                 * Default Contructor
                 */
                PSIHB_ISRN_REG_t() : d64(0) {}
            };

            /**
             * @brief PsiHbXivr Layout for XIVR registers.
             */
            struct PsiHbXivr
            {
                enum
                {
                    PRIO_DISABLED           = 0xff,

                    OCC_PRIO            = 0x30,
                    FSI_PRIO            = 0x20,
                    LPC_PRIO            = 0x40,
                    LCL_ERR_PRIO        = 0x10,
                    HOST_PRIO           = 0x50,
                    PSI_PRIO            = 0x60,

                    PSI_XIVR_ADRR           = 0x02010910,
                    OCC_XIVR_ADRR           = 0x02010916,
                    FSI_XIVR_ADRR           = 0x02010917,
                    LPC_XIVR_ADRR           = 0x02010918,
                    LCL_ERR_XIVR_ADDR       = 0x02010919,
                    HOST_XIVR_ADRR          = 0x0201091A,
                };


                union
                {
                    uint64_t u64;

                    struct
                    {
                        uint64_t res1:8;       // zeros
                        uint64_t pir:14;       // interrupt destination (server)
                        uint64_t linkptr:2;    // which link reg in intr presenter
                        uint64_t priority:8;   // intr priority level
                        uint64_t source:3;     // source number
                        uint64_t res2:4;       // zeros
                        uint64_t intr_pend:25; // interrupt is pending
                    } PACKED;
                };

                PsiHbXivr() : u64(0) {}
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
             * Set the IPCBAR scom register
             * @param[in] i_target, the Target.
             * @param[in] i_pir, The pir for this processor
             */
            errlHndl_t setBAR(TARGETING::Target * i_target,
                              const PIR_t i_pir);

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
             * Disable HW from recieving interrupts
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
             * done without targetting support (just blueprint) since
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
             * Read the PCIE interrupt source numbers out of the HW
             *
             * @param i_target  Processor target to read value from
             * @param o_irsn    List of IRSN for the PCIE units
             * @param o_num     Number of interrupts behind IRSN
             * @return an error handle on error
             */
            errlHndl_t getPcieIRSNs(TARGETING::Target * i_target,
                                    std::vector<uint32_t> &o_irsn,
                                    std::vector<uint32_t> &o_num);

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

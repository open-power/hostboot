/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_msg_timeout.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/**
 * @file pldm_msg_timeout.H
 * @brief Header for class that handles timeouts for pldm msgs.
 *        During pldm_base_init a singleton of the pldmMsgTimeout class has its
 *        init() function called which launches a task which will loop on the
 *        iv_timeoutMsgList.  This class allows a timeout check to multiple
 *        queues but only one timeout check per queue at a time.
 */

#include <memory>
#include <list>
#include <sys/sync.h> // mutex_t & sync_cond_t
#include <sys/msg.h> // msg_q_t

enum TIMEOUT_STATE
{
    TIMEOUT_STATE_RUNNING,
    TIMEOUT_STATE_REAL_TIMEOUT
};

struct TimerMsgData_t
{
    // unique queue to monitor for timeout
    msg_q_t queue = { };

    // how long before timeout in msec
    uint64_t waitTimeLeft_msec = 0;

    // this msg will be created in pldm_wait_timeout()
    // It is passed to this queue by the message_timeout_monitor_thread when waitTimeLeft_msec drops to 0
    msg_t * waiter_done_msg = nullptr;

    // state of this queue's timer (still running or real timeout hit)
    TIMEOUT_STATE state = TIMEOUT_STATE_RUNNING;
};

class pldmMsgTimeout
{
    public:
      /**
       * @brief Launches a task to handle PLDM msg timeout timing
       */
      void init(void);

      // Constructor
      pldmMsgTimeout(void);

      /**
       * @brief Main way to wait for either a response or timeout on a msgq
       *        Note: this can return earlier than the timeout value if a msg is found on queue
       * @param[in]     i_msgq msg queue
       * @param[in/out] io_milliseconds  in: Time in milliseconds to wait
       *                                out: Time left to wait
       * @return messages found during wait time (no timeout msg)
       */
       static std::vector<msg_t*> pldm_wait_timeout(const msg_q_t i_msgq, uint64_t & io_milliseconds);

      /**
       * @brief Main thread used for checking for timeouts
       */
      void message_timeout_monitor_thread();

    protected:

      /**
       * @brief Internal function for pldm_wait_timeout
       * @param[in]     i_msgq msg queue
       * @param[in/out] io_milliseconds  in: Time in milliseconds to wait
       *                                out: Time left to wait
       * @return messages found during wait time (no timeout msg)
       */
      std::vector<msg_t*> _pldm_wait_timeout(const msg_q_t i_msgq, uint64_t & io_milliseconds);

      /**
       * @brief Start the timer for this particular msg
       *        Note: cannot start multiple messages on same queue without stopping first
       * @param[in]  i_queue  msg queue
       * @param[in]  i_timeout_ms  Timer timeout value in milliseconds
       * @param[in]  i_timeout_msg Message sent to the queue if timeout occurs
       *
       * @return true if timer started on this queue, else false
       */
      bool start_pldm_timer(msg_q_t i_queue, uint64_t i_timeout_ms, msg_t * i_timeout_msg);

      /**
       * @brief Stop the timer for this msg queue
       * @param[in] i_queue msg queue
       * @return timer state for this queue at the time of stop
       */
      TIMEOUT_STATE stop_pldm_timer(const msg_q_t i_queue);

    private:

      // List of messages being checked for timeout
      std::list<TimerMsgData_t> iv_timeoutMsgList;

      // Protects the list during accesses
      mutex_t     iv_mutex;

      // used for no messages waiting condition
      sync_cond_t iv_cv;

      // Disallow copying this class.
      pldmMsgTimeout& operator=(const pldmMsgTimeout&);
      pldmMsgTimeout(const pldmMsgTimeout&);
};

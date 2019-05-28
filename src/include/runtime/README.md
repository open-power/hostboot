# interface.h::hostInterfaces::hbrt_fw_msg
How to create an HBRT to FW request message interface
    0) If passing an HBRT to FSP via MBOX or receiving a firmware notify message,
       then use instruction 'generic_hbrt_fsp_message.H::GenericFspMboxMessage_t'
       below.
    1) The biggest part will be defining the interface.  Inspect the current
       interfaces (req_hcode_update, error_log, etc) for inspiration.
    2) Once an interface has been designed, add it to the anonymous
       hbrt_fw_msg::union, among the other interfaces.
    3) Append a new hbrt_fw_msg::io_type, that will be used to
       identify the interface.
    4) How to use the new interface to pass a message
       a) Make sure 'g_hostInterfaces' and 'g_hostInterfaces->firmware_request'
          are not NULL.
       b) Create the firmware_request request struct (hostInterfaces::hbrt_fw_msg)
          to send data.
       c) Populate the firmware_request request struct with data.
       b) Create the firmware_request response struct (hostInterfaces::hbrt_fw_msg)
          to retrieve data. 'Zero' it out.  Currently, this appears to be not
          used, but is needed for the firmware request call.
       d) Make the firmware_request call via method 'firmware_request_helper'
       Examples:
            ~/src/usr/sbeio/runtime/sbeio_vital_attn.C::vital_attn_inform_opal
            ~/src/usr/isteps/nvdimm/runtime/nvdimm_rt.C::notifyNvdimmProtectionChange
            ~/src/usr/isteps/pm/runtime/rt_pm.C::hcode_update
            ~/src/usr/errl/runtime/rt_errlmanager.C::sendMboxMsg
    5) Update /hostboot/src/usr/util/runtime/rt_fwreq_helper.C::firmware_request_helper,
       to capture data from the request if an error occurs.  Capture data in the
       TWO switch statements 'switch (l_req_fw_msg->io_type)'.  Look at others
       for examples.

generic_hbrt_fsp_message.H::GenericFspMboxMessage_t
    Firm Ware request:
        1) The biggest part will be defining the interface.  Inspect the current
           interfaces (AttributeSetter_t, SingleScomOpHbrtFspData_t,
           TargetDeconfigHbrtFspData_t, etc) for inspiration.
        2) Once an interface has been designed, add the structure to this file
           with the other interfaces.
        3) Create an MBOX message queue enum for the interface and add to:
           /hostboot/src/include/usr/mbox/mbox_queues.H::queue_id_t
           see current message queues for example
        4) Add a new message type for the interface to:
           enum generic_hbrt_fsp_message.H::GENERIC_FSP_MBOX_MESSAGE_MSG_TYPE.
        5) How to use the new interface to pass a message
           a) Make sure g_hostInterfaces and g_hostInterfaces->firmware_request
              are not NULL.
           b) Determine size of data.  It could be as simple as the size of the
              structure itself.
           c) Use createGenericFspMsg to create the messages for you.
           c) Populate the firmware_request request struct with data.
           d) Make the firmware_request call via method
              firmware_request_helper
           Examples:
                ~/src/usr/hwas/hwasPlatDeconfigGard.C::platPostDeconfigureTarget
                ~/src/usr/fsiscom/runtime/rt_fsiscom.C::sendScomOpToFsp
                ~/src/usr/fsiscom/runtime/rt_fsiscom.C::sendMultiScomReadToFsp
                ~/src/usr/hwas/hwasPlatDeconfigGard.C::DeconfigGard::platPostDeconfigureTarget

    Firm Ware notify:
        1) The biggest part will be defining the interface.  Inspect the current
           interfaces (sbeRetryReqData_t, HbrtAttrSyncData_t, etc) for inspiration.
        2) Once an interface has been designed, add the structure to this file
           with the other interfaces.
        3) Since this is a message sent from the HWSV team, you will need for
           them to provide the message queue and message type, once you have
           this info
           a) Add the message queue to:
              /hostboot/src/include/usr/mbox/mbox_queues.H::queue_id_t
           b) Add the message type to:
              enum generic_hbrt_fsp_message.H::GENERIC_FSP_MBOX_MESSAGE_MSG_TYPE
        4) Create a method to process the notify call in file:
           ~/src/usr/util/runtime/rt_fwnotify.C.  This method is where the
           interface in step 1 will be used.
           Examples:
                ~/src/usr/util/runtime/rt_fwnotify.C::sbeAttemptRecovery
                ~/src/usr/util/runtime/rt_fwnotify.C::occActiveNotification
                ~/src/usr/util/runtime/rt_fwnotify.C::attrSyncRequest
        5) Update the case statement 'switch (l_hbrt_fw_msg->io_type)' found in
           method ~/src/usr/util/runtime/rt_fwnotify.C::firmware_notify to
           call method created in step 4.


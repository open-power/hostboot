# PLDM Readme

Platform Level Data Model (PLDM) is used by Hostboot to exchange information
with the BMC, such as FRU VPD records.

Below is information regarding the hostboot modules created to support all
of the PLDM functionality hostboot is responsible for during both the IPL
as well as at system runtime. It also includes some information  about the
other supporting libraries included in [src/usr/pldm](./)  and
[src/include/usr/pldm](../../include/usr/pldm) and about how they relate to
the modules.

## Modules

### pldm_base module [src/usr/pldm/base/makefile](base/makefile)
**Overview:** The pldm_base module contains the pldm-related code that lives
in HBB (Hostboot Base Image PNOR partition) and therefore can never be paged
out of memory. This also means it gets loaded early in the IPL by initservice.
(see [src/usr/initservice/baseinitsvc/initsvctasks.H](../initservice/baseinitsvc/initsvctasks.H)
for more information)
- pldm_base contains [pldm_base_init.C](base/pldm_base_init.C) which defines the
  function base_init()
  - This function is called as soon as module is loaded and performs the following:
    - Registers all PLDM message queues, including messages queues that the
      extended image module will use
    - Initializes the PLDM requester task
    - Initiates MCTP traffic at the MCTP layer via mctpif.H interfaces
- pldm_base contains pldmRequester class with function
  handle_outbound_req_messages() in [src/usr/pldm/base/pldm_requester.H](base/pldm_requester.H)
  - This class is intended to be a singleton; there should never be two
    instances of this class
  - handle_outbound_req_messages is launched as a detached task when the
    init function is called on the singleton object
      - This occurs in pldm_base_init when the pldm_base module is loaded
- pldm_base will contain code for requesting PNOR pages from the BMC
  (code not written yet)
    - This is why this code must be in the base image that never gets paged out
      of memory. We do not want to end up in the situation where hostboot
      requests pages of the code that then requires PNOR page requests from
      the BMC!
- pldm_base contains all of the PLDM message queue management and routing logic
  - pldm_msg_queues.H/C creates global message queues g_outboundPldmReqMsgQ,
    g_inboundPldmRspMsgQ, g_inboundPldmReqMsgQ
    - These message queues get registered in registerPldmMsgQs which is called in
      task init function for pldm_base
  - [pldm_msg_router.C](base/pldm_msg_router.C) defines routeInboundMsg which is called by the MCTP layer
    when it needs to route a PLDM message.
    - This code performs a memcpy on the msg->extra_data as this buffer is
      reclaimed by the MCTP core logic immediately following this function
    - This code looks looks at the 'request' bit in PLDM msg header to determine
      if it needs to go to g_inboundPldmReqMsgQ or g_inboundPldmRspMsgQ

### pldm_extended module [src/usr/pldm/extended/makefile](extended/makefile)
**Overview:** The pldm_extended module contains all of the other IPL-time PLDM
support that is not in the pldm_base module.  It lives in HBI (Hostboot Extended
Image PNOR Partition). It will be loaded by the extended initservice.
(see [src/usr/initservice/extinitsvc/extinitsvctasks.H](../initservice/extinitsvc/extinitsvctasks.H)
for more information).
- pldm_extended contains [pldm_extended_init.C](extended/pldm_extended_init.C)
  with function extended_init().
  - This function is called as soon as the module is loaded and does the following:
    - initializes PLDM responder task
- pldm_extended contains pldmResponder class with function
  handle_inbound_req_messages (src/usr/pldm/extended/pldm_responder.*)
  - This class is intended to be a singleton; there should never be two
    instances of this class
  - handle_inbound_req_messages is launched as a detached task when the
    init function is called on the singleton
    - This occurs during extended_init when the pldm_extended module is loaded

### pldm_runtime module [src/usr/pldm/runtime/makefile](runtime/makefile)
**Overview:** The pldm_runtime module contains all code to support PLDM for
Hostboot during runtime. HBRT is single threaded and doesn't have access to
internal msgQs so the logic for issuing and handling requests is different
than IPL time.
- [pldmrp_rt](runtime/pldmrp_rt.H)
  - Contains the Singleton class, PldmRP, that manages the next_pldm_request
    and next_pldm_response buffers. There should only be at most a single
    request and a single response from the BMC at a time. Once the MCTP core
    logic has received a complete message of type PLDM it will attempt to cache
    that message with this class. If the message is a request and this
    singleton already has a request cached, an error is returned to the MCTP
    layer. The same goes for the case when the MCTP layer attempts to cache a
    response when the singleton already has a cached response.
- issuing requests to the BMC
  - sendrecv_pldm_request function will detect if we are in HBRT and if so
    will call MCTP::send_message and then perform a MCTP::get_next_packet until
    we get a PLDM response.
- responding to request from the BMC
  - When the BMC issues Hostboot a PLDM request it will come over MCTP. During
    HBRT, Hostboot does not have access to the LPC bus that MCTP traffic flows
    on so the hypervisor must bridge the messages to us. When the hypervisor
    sees a MCTP message addressed to EID 10 (HBRT's eid) then they will call
    fw_notify with a MCTP_AVAILABLE message. HBRT will handle this message by
    checking if we have a cached request and fufilling that request, or by
    performing MCTP::get_next_packet calls until we get a request.
  - One thing to note, there are many times where we expect the hypervisor to
    send us more MCTP_AVAILABLE notifications than we need to process all of
    the packets, so if we receive a notification, and we don't have a request
    cached, and the first MCTP::get_next_packet returns NO_PACKET_AVAILABLE,
    then we return immediately, assuming that this is an "extra" MCTP_AVAILABLE
    notification.

## Supporting Libraries

### Common Files  [src/usr/pldm/common/](common)
**Overview:** Anything that will be used in at least two of the modules
described above.
- [common.mk](common/common.mk)
  - Contains anything that gets duplicated between src/usr/pldm/base/makefile,
    src/usr/pldm/extended/makefile and src/usr/pldm/runtime/makefile.
    - The items defined only need to be common between at least 2 of the modules
      (ie. PLDM_COMMON_BASE_OBJS is only for runtime/base and not extended)
- pldm_trace.H/C
  - [pldm_trace.C](common/pldm_trace.C) declares/initializes g_trac_pldm,
    which is the 4 KB non-blocking trace buffer
    - It must be non-blocking because this is part of PNOR page request code
  - [pldm_trace.H](src/include/usr/pldm/pldm_trace.H) declares all of the PLDM_ trace macros
    and an extern to g_trac_pldm

### External github imports [src/usr/pldm/extern/](extern/)
**Overview:** Everything that is ported from github.com/openbmc/pldm/tree/master/libpldm
- This external repository contains most of the files shared by the Hostboot
  and BMC code bases.
  - They involve packing and unpacking the various PLDM message structs
  - The BMC team has also implemented the various encoding and decoding functions
    required for their end of the communication
  - Implementation of the encode/decode APIs is not 100% complete yet and it is Hostboot's
    responsibility to implement functions we need that do not exist yet and upstream them
    to the openbmc/pldm github repository.
- NOTE: Eventually this might be pulled in as submodule or something to that effect,
  but for now we are just manually managing the files here

### PLDM Requests [src/include/usr/pldm/requests](../../include/usr/pldm/requests)
[src/usr/pldm/requests](pldm/requests)
**Overview:** This code contains the functions called by other userspace modules,
such as istep code, to make PLDM requests and get the responses back.
- pldm_fru_requests:
  - all code required for requesting FRU Table Record information from the BMC
- pldm_pdr_requests
  - TBD

### PLDM Userspace Interface [src/include/usr/pldm/pldmif.H](../../include/usr/pldm/pldmif.H)
**Overview:** The header that defines interfaces for core pldm functionality that
needs to be called from non-pldm modules.
- pldmif.H contains
  - PLDM::routeInboundMsg called my MCTP to route incoming PLDM messages

### PLDM Response Handlers (incomplete)
**Overview:** Functions which will be called to respond to the different PLDM
request messages from the BMC.
(Code does not exist yet - TBD)

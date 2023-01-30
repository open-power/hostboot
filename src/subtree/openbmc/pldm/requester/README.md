## Overview

PLDM requester infrastructure enables the requester code in PLDM daemon to meet
the requirements of PLDM requesters. It provides the following features:

- Register a PLDM request and the response handler to be invoked on receiving
  the response.
- The handling of the request and response is asynchronous. This means the PLDM
  daemon is not blocked till the response is received for a request.
- Multiple outstanding requests are supported.
- Request retries based on the time-out waiting for a response.
- Instance ID expiration and marking the instance ID free after expiration.

Future enhancements:

- A mechanism to queue multiple outstanding requests to the same responder.
- Handle ERROR_NOT_READY completion code and retry the PLDM request after 250ms
  interval.

The requester code needs to use the `registerRequest` API to register the PLDM
request. The destination endpoint ID, instance ID, PLDM type, PLDM command code,
PLDM request message (PLDM header and payload) and response function handler are
passed as parameters to the registerRequest API.

```
    int registerRequest(mctp_eid_t eid, uint8_t instanceId, uint8_t type,
                        uint8_t command, pldm::Request&& requestMsg,
                        ResponseHandler&& responseHandler)
```

The signature of the response function handler:

```
void handler(mctp_eid_t eid, const pldm_msg* response, size_t respMsgLen)
```

- If the response is received before instance ID expiration:
  - If the response matches with an outstanding request then the response
    handler is invoked.
  - If the response does not match with the PLDM instance ID, PLDM type and PLDM
    command code of an outstanding request, then no action is taken on the
    response.
- Once the instance ID is expired, then the response handler is invoked with
  empty response, so that further action can be taken.

/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/extern/core.c $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef pr_fmt
#define pr_fmt(fmt) "core: " fmt

#include "libmctp.h"
#include "libmctp-alloc.h"
#include "libmctp-log.h"



/* Internal data structures */

struct mctp_bus {
  mctp_eid_t    eid;
  struct mctp_binding  *binding;
  bool      tx_enabled;

  struct mctp_pktbuf  *tx_queue_head;
  struct mctp_pktbuf  *tx_queue_tail;

  /* todo: routing */
};

struct mctp_msg_ctx {
  uint8_t    src;
  uint8_t    dest;
  uint8_t    tag;
  uint8_t    last_seq;
  void    *buf;
  size_t    buf_size;
  size_t    buf_alloc_size;
};

struct mctp {
  int      n_busses;
  struct mctp_bus    *busses;

  /* Message RX callback */
  mctp_rx_fn    message_rx;
  void      *message_rx_data;

  /* Message reassembly.
   * @todo: flexible context count
   */
  struct mctp_msg_ctx  msg_ctxs[16];

  enum {
    ROUTE_ENDPOINT,
    ROUTE_BRIDGE,
  }      route_policy;
};

#ifndef BUILD_ASSERT
#define BUILD_ASSERT(x) \
  do { (void)sizeof(char[0-(!(x))]); } while (0)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#endif

static int mctp_message_tx_on_bus(struct mctp *mctp, struct mctp_bus *bus,
    mctp_eid_t src, mctp_eid_t dest, void *msg, size_t msg_len);

struct mctp_pktbuf *mctp_pktbuf_alloc(struct mctp_binding *binding, size_t len)
{
  struct mctp_pktbuf *buf;
  size_t size;

  size = binding->pkt_size + binding->pkt_pad;

  /* todo: pools */
  buf = __mctp_alloc(sizeof(*buf) + size);

  buf->size = size;
  buf->start = binding->pkt_pad;
  buf->end = buf->start + len;
  buf->mctp_hdr_off = buf->start;
  buf->next = NULL;

  return buf;
}

void mctp_pktbuf_free(struct mctp_pktbuf *pkt)
{
  __mctp_free(pkt);
}

struct mctp_hdr *mctp_pktbuf_hdr(struct mctp_pktbuf *pkt)
{
  return (void *)pkt->data + pkt->mctp_hdr_off;
}

void *mctp_pktbuf_data(struct mctp_pktbuf *pkt)
{
  return (void *)pkt->data + pkt->mctp_hdr_off + sizeof(struct mctp_hdr);
}

size_t mctp_pktbuf_size(struct mctp_pktbuf *pkt)
{
  return pkt->end - pkt->start;
}

void *mctp_pktbuf_alloc_start(struct mctp_pktbuf *pkt, size_t size)
{
  assert(size <= pkt->start);
  pkt->start -= size;
  return pkt->data + pkt->start;
}

void *mctp_pktbuf_alloc_end(struct mctp_pktbuf *pkt, size_t size)
{
  void *buf;

  assert(size < (pkt->size - pkt->end));
  buf = pkt->data + pkt->end;
  pkt->end += size;
  return buf;
}

int mctp_pktbuf_push(struct mctp_pktbuf *pkt, void *data, size_t len)
{
  void *p;

  if (pkt->end + len > pkt->size)
    return -1;

  p = pkt->data + pkt->end;

  pkt->end += len;
  memcpy(p, data, len);

  return 0;
}

/* Message reassembly */
static struct mctp_msg_ctx *mctp_msg_ctx_lookup(struct mctp *mctp,
    uint8_t src, uint8_t dest, uint8_t tag)
{
  unsigned int i;

  /* @todo: better lookup, if we add support for more outstanding
   * message contexts */
  for (i = 0; i < ARRAY_SIZE(mctp->msg_ctxs); i++) {
    struct mctp_msg_ctx *ctx = &mctp->msg_ctxs[i];
    if (ctx->src == src && ctx->dest == dest && ctx->tag == tag)
      return ctx;
  }

  return NULL;
}

static struct mctp_msg_ctx *mctp_msg_ctx_create(struct mctp *mctp,
    uint8_t src, uint8_t dest, uint8_t tag)
{
  struct mctp_msg_ctx *ctx = NULL;
  unsigned int i;

  for (i = 0; i < ARRAY_SIZE(mctp->msg_ctxs); i++) {
    struct mctp_msg_ctx *tmp = &mctp->msg_ctxs[i];
    if (!tmp->src) {
      ctx = tmp;
      break;
    }
  }

  if (!ctx)
    return NULL;

  ctx->src = src;
  ctx->dest = dest;
  ctx->tag = tag;
  ctx->buf_size = 0;

  return ctx;
}

static void mctp_msg_ctx_drop(struct mctp_msg_ctx *ctx)
{
  ctx->src = 0;
}

static void mctp_msg_ctx_reset(struct mctp_msg_ctx *ctx)
{
  ctx->buf_size = 0;
}

static int mctp_msg_ctx_add_pkt(struct mctp_msg_ctx *ctx,
    struct mctp_pktbuf *pkt)
{
  size_t len;

  len = mctp_pktbuf_size(pkt) - sizeof(struct mctp_hdr);

  if (ctx->buf_size + len > ctx->buf_alloc_size) {
    size_t new_alloc_size;

    /* @todo: finer-grained allocation, size limits */
    if (!ctx->buf_alloc_size) {
      new_alloc_size = 32768;
    } else {
      new_alloc_size = ctx->buf_alloc_size * 2;
    }
    ctx->buf = __mctp_realloc(ctx->buf, new_alloc_size);
    ctx->buf_alloc_size = new_alloc_size;
  }

  memcpy(ctx->buf + ctx->buf_size, mctp_pktbuf_data(pkt), len);
  ctx->buf_size += len;

  return 0;
}

/* Core API functions */
struct mctp *mctp_init(void)
{
  struct mctp *mctp;

  mctp = __mctp_alloc(sizeof(*mctp));
  memset(mctp, 0, sizeof(*mctp));

  return mctp;
}

void mctp_destroy(struct mctp *mctp)
{
        int i;

        /* Cleanup message assembly contexts */
        for (i = 0; i < ARRAY_SIZE(mctp->msg_ctxs); i++) {
                struct mctp_msg_ctx *tmp = &mctp->msg_ctxs[i];
                if (tmp->buf)
                        __mctp_free(tmp->buf);
        }

        __mctp_free(mctp->busses);
        __mctp_free(mctp);
}

int mctp_set_rx_all(struct mctp *mctp, mctp_rx_fn fn, void *data)
{
  mctp->message_rx = fn;
  mctp->message_rx_data = data;
  return 0;
}

static struct mctp_bus *find_bus_for_eid(struct mctp *mctp,
    mctp_eid_t dest __attribute__((unused)))
{
  /* for now, just use the first bus. For full routing support,
   * we will need a table of neighbours */
  return &mctp->busses[0];
}

int mctp_register_bus(struct mctp *mctp,
    struct mctp_binding *binding,
    mctp_eid_t eid)
{
  /* todo: multiple busses */
  assert(mctp->n_busses == 0);
  mctp->n_busses = 1;
  mctp->busses = __mctp_alloc(sizeof(struct mctp_bus));
  memset(mctp->busses, 0, sizeof(struct mctp_bus));
  mctp->busses[0].binding = binding;
  mctp->busses[0].eid = eid;
  binding->bus = &mctp->busses[0];
  binding->mctp = mctp;
  mctp->route_policy = ROUTE_ENDPOINT;

  if (binding->start)
    binding->start(binding);

  return 0;
}

int mctp_bridge_busses(struct mctp *mctp,
    struct mctp_binding *b1, struct mctp_binding *b2)
{
  assert(mctp->n_busses == 0);
  mctp->busses = __mctp_alloc(2 * sizeof(struct mctp_bus));
  memset(mctp->busses, 0, 2 * sizeof(struct mctp_bus));
  mctp->n_busses = 2;
  mctp->busses[0].binding = b1;
  b1->bus = &mctp->busses[0];
  b1->mctp = mctp;
  mctp->busses[1].binding = b2;
  b2->bus = &mctp->busses[1];
  b2->mctp = mctp;

  mctp->route_policy = ROUTE_BRIDGE;

  if (b1->start)
    b1->start(b1);

  if (b2->start)
    b2->start(b2);

  return 0;
}

static void mctp_rx(struct mctp *mctp, struct mctp_bus *bus,
    mctp_eid_t src, mctp_eid_t dest, void *buf, size_t len)
{
  if (mctp->route_policy == ROUTE_ENDPOINT &&
      dest == bus->eid && mctp->message_rx)
    mctp->message_rx(src, mctp->message_rx_data, buf, len);

  if (mctp->route_policy == ROUTE_BRIDGE) {
    int i;

    for (i = 0; i < mctp->n_busses; i++) {
      struct mctp_bus *dest_bus = &mctp->busses[i];
      if (dest_bus == bus)
        continue;

      mctp_message_tx_on_bus(mctp, dest_bus,
          src, dest, buf, len);
    }

  }
}

void mctp_bus_rx(struct mctp_binding *binding, struct mctp_pktbuf *pkt)
{
  struct mctp_bus *bus = binding->bus;
  struct mctp *mctp = binding->mctp;
  uint8_t flags, exp_seq, seq, tag;
  struct mctp_msg_ctx *ctx;
  struct mctp_hdr *hdr;
  size_t len;
  void *p;
  int rc;

  assert(bus);

  hdr = mctp_pktbuf_hdr(pkt);

  /* small optimisation: don't bother reassembly if we're going to
   * drop the packet in mctp_rx anyway */
  if (mctp->route_policy == ROUTE_ENDPOINT && hdr->dest != bus->eid)
    goto out;

  flags = hdr->flags_seq_tag & (MCTP_HDR_FLAG_SOM | MCTP_HDR_FLAG_EOM);
  tag = (hdr->flags_seq_tag >> MCTP_HDR_TAG_SHIFT) & MCTP_HDR_TAG_MASK;
  seq = (hdr->flags_seq_tag >> MCTP_HDR_SEQ_SHIFT) & MCTP_HDR_SEQ_MASK;

  switch (flags) {
  case MCTP_HDR_FLAG_SOM | MCTP_HDR_FLAG_EOM:
    /* single-packet message - send straight up to rx function,
     * no need to create a message context */
    len = pkt->end - pkt->mctp_hdr_off - sizeof(struct mctp_hdr);
    p = pkt->data + pkt->mctp_hdr_off + sizeof(struct mctp_hdr),
    mctp_rx(mctp, bus, hdr->src, hdr->dest, p, len);
    break;

  case MCTP_HDR_FLAG_SOM:
    /* start of a new message - start the new context for
     * future message reception. If an existing context is
     * already present, drop it. */
    ctx = mctp_msg_ctx_lookup(mctp, hdr->src, hdr->dest, tag);
    if (ctx) {
      mctp_msg_ctx_reset(ctx);
    } else {
      ctx = mctp_msg_ctx_create(mctp,
          hdr->src, hdr->dest, tag);
    }

    rc = mctp_msg_ctx_add_pkt(ctx, pkt);
    if (rc) {
      mctp_msg_ctx_drop(ctx);
    } else {
      ctx->last_seq = seq;
    }

    break;

  case MCTP_HDR_FLAG_EOM:
    ctx = mctp_msg_ctx_lookup(mctp, hdr->src, hdr->dest, tag);
    if (!ctx)
      goto out;

    exp_seq = (ctx->last_seq + 1) % 4;

    if (exp_seq != seq) {
      mctp_prdebug(
        "Sequence number %d does not match expected %d",
        seq, exp_seq);
      mctp_msg_ctx_drop(ctx);
      goto out;
    }

    rc = mctp_msg_ctx_add_pkt(ctx, pkt);
    if (!rc)
      mctp_rx(mctp, bus, ctx->src, ctx->dest,
          ctx->buf, ctx->buf_size);

    mctp_msg_ctx_drop(ctx);
    break;

  case 0:
    /* Neither SOM nor EOM */
    ctx = mctp_msg_ctx_lookup(mctp, hdr->src,hdr->dest, tag);
    if (!ctx)
      goto out;

    exp_seq = (ctx->last_seq + 1) % 4;
    if (exp_seq != seq) {
      mctp_prdebug(
        "Sequence number %d does not match expected %d",
        seq, exp_seq);
      mctp_msg_ctx_drop(ctx);
      goto out;
    }

    rc = mctp_msg_ctx_add_pkt(ctx, pkt);
    if (rc) {
      mctp_msg_ctx_drop(ctx);
      goto out;
    }
    ctx->last_seq = seq;

    break;
  }
out:
  mctp_pktbuf_free(pkt);
}

static int mctp_packet_tx(struct mctp_bus *bus,
    struct mctp_pktbuf *pkt)
{
  if (!bus->tx_enabled)
    return -1;

  return bus->binding->tx(bus->binding, pkt);
}

static void mctp_send_tx_queue(struct mctp_bus *bus)
{
  struct mctp_pktbuf *pkt;

  while ((pkt = bus->tx_queue_head)) {
    int rc;

    rc = mctp_packet_tx(bus, pkt);
    if (rc)
      break;

    bus->tx_queue_head = pkt->next;
    mctp_pktbuf_free(pkt);
  }

  if (!bus->tx_queue_head)
    bus->tx_queue_tail = NULL;

}

void mctp_binding_set_tx_enabled(struct mctp_binding *binding, bool enable)
{
  struct mctp_bus *bus = binding->bus;
  bus->tx_enabled = enable;
  if (enable)
    mctp_send_tx_queue(bus);
}

static int mctp_message_tx_on_bus(struct mctp *mctp, struct mctp_bus *bus,
    mctp_eid_t src, mctp_eid_t dest, void *msg, size_t msg_len)
{
  size_t max_payload_len, payload_len, p;
  struct mctp_pktbuf *pkt;
  struct mctp_hdr *hdr;
  int i;

  max_payload_len = bus->binding->pkt_size - sizeof(*hdr);

  /* queue up packets, each of max MCTP_MTU size */
  for (p = 0, i = 0; p < msg_len; i++) {
    payload_len = msg_len - p;
    if (payload_len > max_payload_len)
      payload_len = max_payload_len;

    pkt = mctp_pktbuf_alloc(bus->binding,
        payload_len + sizeof(*hdr));
    hdr = mctp_pktbuf_hdr(pkt);

    /* todo: tags */
    hdr->ver = bus->binding->version & 0xf;
    hdr->dest = dest;
    hdr->src = src;
    hdr->flags_seq_tag = MCTP_HDR_FLAG_TO |
      (0 << MCTP_HDR_TAG_SHIFT);

    if (i == 0)
      hdr->flags_seq_tag |= MCTP_HDR_FLAG_SOM;
    if (p + payload_len >= msg_len)
      hdr->flags_seq_tag |= MCTP_HDR_FLAG_EOM;
    hdr->flags_seq_tag |=
      (i & MCTP_HDR_SEQ_MASK) << MCTP_HDR_SEQ_SHIFT;

    memcpy(mctp_pktbuf_data(pkt), msg + p, payload_len);

    /* add to tx queue */
    if (bus->tx_queue_tail)
      bus->tx_queue_tail->next = pkt;
    else
      bus->tx_queue_head = pkt;
    bus->tx_queue_tail = pkt;

    p += payload_len;
  }

  mctp_send_tx_queue(bus);

  return 0;
}

int mctp_message_tx(struct mctp *mctp, mctp_eid_t eid,
    void *msg, size_t msg_len)
{
  struct mctp_bus *bus;

  bus = find_bus_for_eid(mctp, eid);
  return mctp_message_tx_on_bus(mctp, bus, bus->eid, eid, msg, msg_len);
}

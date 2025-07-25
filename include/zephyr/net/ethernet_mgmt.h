/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Ethernet Management interface public header
 */

#ifndef ZEPHYR_INCLUDE_NET_ETHERNET_MGMT_H_
#define ZEPHYR_INCLUDE_NET_ETHERNET_MGMT_H_

#include <zephyr/net/ethernet.h>
#include <zephyr/net/net_mgmt.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Ethernet library
 * @defgroup ethernet_mgmt Ethernet Library
 * @since 1.12
 * @version 0.8.0
 * @ingroup networking
 * @{
 */

/** @cond INTERNAL_HIDDEN */

#define NET_ETHERNET_LAYER	NET_MGMT_LAYER_L2
#define NET_ETHERNET_CODE	NET_MGMT_LAYER_CODE_ETHERNET
#define NET_ETHERNET_BASE	(NET_MGMT_IFACE_BIT |			\
				 NET_MGMT_LAYER(NET_ETHERNET_LAYER) |	\
				 NET_MGMT_LAYER_CODE(NET_ETHERNET_CODE))
#define NET_ETHERNET_EVENT	(NET_ETHERNET_BASE | NET_MGMT_EVENT_BIT)

enum net_request_ethernet_cmd {
	NET_REQUEST_ETHERNET_CMD_SET_MAC_ADDRESS = 1,
	NET_REQUEST_ETHERNET_CMD_SET_QAV_PARAM,
	NET_REQUEST_ETHERNET_CMD_SET_QBV_PARAM,
	NET_REQUEST_ETHERNET_CMD_SET_QBU_PARAM,
	NET_REQUEST_ETHERNET_CMD_SET_TXTIME_PARAM,
	NET_REQUEST_ETHERNET_CMD_SET_PROMISC_MODE,
	NET_REQUEST_ETHERNET_CMD_GET_PRIORITY_QUEUES_NUM,
	NET_REQUEST_ETHERNET_CMD_GET_QAV_PARAM,
	NET_REQUEST_ETHERNET_CMD_GET_PORTS_NUM,
	NET_REQUEST_ETHERNET_CMD_GET_QBV_PARAM,
	NET_REQUEST_ETHERNET_CMD_GET_QBU_PARAM,
	NET_REQUEST_ETHERNET_CMD_GET_TXTIME_PARAM,
	NET_REQUEST_ETHERNET_CMD_SET_T1S_PARAM,
	NET_REQUEST_ETHERNET_CMD_SET_TXINJECTION_MODE,
	NET_REQUEST_ETHERNET_CMD_GET_TXINJECTION_MODE,
	NET_REQUEST_ETHERNET_CMD_SET_MAC_FILTER,
};

#define NET_REQUEST_ETHERNET_SET_MAC_ADDRESS				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_MAC_ADDRESS)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_MAC_ADDRESS);

#define NET_REQUEST_ETHERNET_SET_QAV_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_QAV_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_QAV_PARAM);

#define NET_REQUEST_ETHERNET_GET_PORTS_NUM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_PORTS_NUM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_PORTS_NUM);

#define NET_REQUEST_ETHERNET_SET_QBV_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_QBV_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_QBV_PARAM);

#define NET_REQUEST_ETHERNET_SET_QBU_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_QBU_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_QBU_PARAM);

#define NET_REQUEST_ETHERNET_SET_TXTIME_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_TXTIME_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_TXTIME_PARAM);

#define NET_REQUEST_ETHERNET_SET_PROMISC_MODE				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_PROMISC_MODE)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_PROMISC_MODE);

#define NET_REQUEST_ETHERNET_GET_PRIORITY_QUEUES_NUM			\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_PRIORITY_QUEUES_NUM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_PRIORITY_QUEUES_NUM);

#define NET_REQUEST_ETHERNET_GET_QAV_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_QAV_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_QAV_PARAM);

#define NET_REQUEST_ETHERNET_GET_QBV_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_QBV_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_QBV_PARAM);

#define NET_REQUEST_ETHERNET_GET_QBU_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_QBU_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_QBU_PARAM);

#define NET_REQUEST_ETHERNET_GET_TXTIME_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_TXTIME_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_TXTIME_PARAM);

#define NET_REQUEST_ETHERNET_SET_T1S_PARAM				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_T1S_PARAM)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_T1S_PARAM);

#define NET_REQUEST_ETHERNET_SET_TXINJECTION_MODE				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_TXINJECTION_MODE)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_TXINJECTION_MODE);

#define NET_REQUEST_ETHERNET_GET_TXINJECTION_MODE				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_GET_TXINJECTION_MODE)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_GET_TXINJECTION_MODE);

#define NET_REQUEST_ETHERNET_SET_MAC_FILTER				\
	(NET_ETHERNET_BASE | NET_REQUEST_ETHERNET_CMD_SET_MAC_FILTER)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_ETHERNET_SET_MAC_FILTER);

struct net_eth_addr;
struct ethernet_qav_param;
struct ethernet_qbv_param;
struct ethernet_qbu_param;
struct ethernet_txtime_param;

struct ethernet_req_params {
	union {
		bool promisc_mode;
		bool txinjection_mode;

		struct net_eth_addr mac_address;

		struct ethernet_qav_param qav_param;
		struct ethernet_qbv_param qbv_param;
		struct ethernet_qbu_param qbu_param;
		struct ethernet_txtime_param txtime_param;
		struct ethernet_t1s_param t1s_param;

		struct ethernet_filter filter;

		int priority_queues_num;
		int ports_num;
	};
};

enum {
	NET_EVENT_ETHERNET_CMD_CARRIER_ON_VAL,
	NET_EVENT_ETHERNET_CMD_CARRIER_OFF_VAL,
	NET_EVENT_ETHERNET_CMD_VLAN_TAG_ENABLED_VAL,
	NET_EVENT_ETHERNET_CMD_VLAN_TAG_DISABLED_VAL,

	NET_EVENT_ETHERNET_CMD_MAX
};

BUILD_ASSERT(NET_EVENT_ETHERNET_CMD_MAX <= NET_MGMT_MAX_COMMANDS,
	     "Number of events in net_event_ethernet_cmd exceeds the limit");

enum net_event_ethernet_cmd {
	NET_MGMT_CMD(NET_EVENT_ETHERNET_CMD_CARRIER_ON),
	NET_MGMT_CMD(NET_EVENT_ETHERNET_CMD_CARRIER_OFF),
	NET_MGMT_CMD(NET_EVENT_ETHERNET_CMD_VLAN_TAG_ENABLED),
	NET_MGMT_CMD(NET_EVENT_ETHERNET_CMD_VLAN_TAG_DISABLED),
};

#define NET_EVENT_ETHERNET_CARRIER_ON					\
	(NET_ETHERNET_EVENT | NET_EVENT_ETHERNET_CMD_CARRIER_ON)

#define NET_EVENT_ETHERNET_CARRIER_OFF					\
	(NET_ETHERNET_EVENT | NET_EVENT_ETHERNET_CMD_CARRIER_OFF)

#define NET_EVENT_ETHERNET_VLAN_TAG_ENABLED				\
	(NET_ETHERNET_EVENT | NET_EVENT_ETHERNET_CMD_VLAN_TAG_ENABLED)

#define NET_EVENT_ETHERNET_VLAN_TAG_DISABLED				\
	(NET_ETHERNET_EVENT | NET_EVENT_ETHERNET_CMD_VLAN_TAG_DISABLED)

struct net_if;

/** @endcond */

/**
 * @brief Raise CARRIER_ON event when Ethernet is connected.
 *
 * @param iface Ethernet network interface.
 */
#if defined(CONFIG_NET_L2_ETHERNET_MGMT)
void ethernet_mgmt_raise_carrier_on_event(struct net_if *iface);
#else
static inline void ethernet_mgmt_raise_carrier_on_event(struct net_if *iface)
{
	ARG_UNUSED(iface);
}
#endif

/**
 * @brief Raise CARRIER_OFF event when Ethernet is disconnected.
 *
 * @param iface Ethernet network interface.
 */
#if defined(CONFIG_NET_L2_ETHERNET_MGMT)
void ethernet_mgmt_raise_carrier_off_event(struct net_if *iface);
#else
static inline void ethernet_mgmt_raise_carrier_off_event(struct net_if *iface)
{
	ARG_UNUSED(iface);
}
#endif

/**
 * @brief Raise VLAN_ENABLED event when VLAN is enabled.
 *
 * @param iface Ethernet network interface.
 * @param tag VLAN tag which is enabled.
 */
#if defined(CONFIG_NET_L2_ETHERNET_MGMT)
void ethernet_mgmt_raise_vlan_enabled_event(struct net_if *iface, uint16_t tag);
#else
static inline void ethernet_mgmt_raise_vlan_enabled_event(struct net_if *iface,
							  uint16_t tag)
{
	ARG_UNUSED(iface);
	ARG_UNUSED(tag);
}
#endif

/**
 * @brief Raise VLAN_DISABLED event when VLAN is disabled.
 *
 * @param iface Ethernet network interface.
 * @param tag VLAN tag which is disabled.
 */
#if defined(CONFIG_NET_L2_ETHERNET_MGMT)
void ethernet_mgmt_raise_vlan_disabled_event(struct net_if *iface,
					     uint16_t tag);
#else
static inline void ethernet_mgmt_raise_vlan_disabled_event(struct net_if *iface,
							   uint16_t tag)
{
	ARG_UNUSED(iface);
	ARG_UNUSED(tag);
}
#endif

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_NET_ETHERNET_MGMT_H_ */

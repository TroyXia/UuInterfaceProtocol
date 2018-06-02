#include "../include/ProtocolType.h"
#include "../include/Protocol.h"
#include "../include/Interface.h"
#include <gtest/gtest.h>

TEST(ProtocolTest, protocol_PDCP_FullData)
{
	Payload payload = {4, 5, 6, 7};
	PDCP pdcp;
	PDU pdu = pdcp.encodeCommand(payload);
	Payload encodePayload = pdu.getFullData();
	Payload actualEncodePayload = {static_cast<BYTE>(ProtocolType::PDCP), 4, 5, 6, 7};
	EXPECT_EQ(actualEncodePayload, encodePayload);

	Payload decodePayload = pdcp.decodeCommand(pdu);
	Payload actualDecodePayload = {4, 5, 6, 7};
	EXPECT_EQ(actualDecodePayload, decodePayload);
}

TEST(ProtocolTest, protocol_PDCP_EmptyData)
{
	Payload payload;
	PDCP pdcp;
	PDU pdu = pdcp.encodeCommand(payload);
	Payload encodePayload = pdu.getFullData();
	Payload actualEncodePayload = {static_cast<BYTE>(ProtocolType::PDCP)};
	EXPECT_EQ(actualEncodePayload, encodePayload);

	Payload decodePayload = pdcp.decodeCommand(pdu);
	Payload actualDecodePayload;
	EXPECT_EQ(actualDecodePayload, decodePayload);
}

TEST(ProtocolTest, protocol_RLC)
{
	Payload payload = {4, 5, 6, 7};
	RLC rlc;
	PDU pdu = rlc.encodeCommand(payload);
	Payload encodePayload = pdu.getFullData();
	Payload actualEncodePayload = {static_cast<BYTE>(ProtocolType::RLC), 4, 5, 6, 7};
	EXPECT_EQ(actualEncodePayload, encodePayload);

	Payload decodePayload = rlc.decodeCommand(pdu);
	Payload actualDecodePayload = {4, 5, 6, 7};
	EXPECT_EQ(actualDecodePayload, decodePayload);
}

TEST(ProtocolTest, protocol_MAC)
{
	Payload payload = {4, 5, 6, 7};
	MAC mac;
	PDU pdu = mac.encodeCommand(payload);
	Payload encodePayload = pdu.getFullData();
	Payload actualEncodePayload = {static_cast<BYTE>(ProtocolType::MAC), 4, 5, 6, 7};
	EXPECT_EQ(actualEncodePayload, encodePayload);

	Payload decodePayload = mac.decodeCommand(pdu);
	Payload actualDecodePayload = {4, 5, 6, 7};
	EXPECT_EQ(actualDecodePayload, decodePayload);
}

TEST(ProtocolTest, protocol_PHY)
{
	Payload payload = {4, 5, 6, 7};
	PHY phy;
	PDU pdu = phy.encodeCommand(payload);
	Payload encodePayload = pdu.getFullData();
	Payload actualEncodePayload = {static_cast<BYTE>(ProtocolType::PHY), 4, 5, 6, 7};
	EXPECT_EQ(actualEncodePayload, encodePayload);

	Payload decodePayload = phy.decodeCommand(pdu);
	Payload actualDecodePayload = {4, 5, 6, 7};
	EXPECT_EQ(actualDecodePayload, decodePayload);
}

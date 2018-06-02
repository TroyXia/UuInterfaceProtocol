#include "../include/ProtocolType.h"
#include "../include/Protocol.h"
#include "../include/Interface.h"
#include <gtest/gtest.h>

TEST(ProtocolTypeTest, PDU_FullData)
{
	Payload payload = {4, 5, 6, 7};
	BYTE byte = static_cast<BYTE>(ProtocolType::PDCP);

	PDU pdu(byte, payload);
	Payload testPushPayload = pdu.getFullData();
	Payload actualPushPayload = {static_cast<BYTE>(ProtocolType::PDCP), 4, 5, 6, 7};
	EXPECT_EQ(actualPushPayload, testPushPayload);

	Payload testPopPayload = pdu.getPayload();
	Payload actualPopPayload = {4, 5, 6, 7};
	EXPECT_EQ(actualPopPayload, testPopPayload);
}

TEST(ProtocolTypeTest, PDU_EmptyData)
{
	Payload payload;
	BYTE byte = static_cast<BYTE>(ProtocolType::PDCP);

	PDU pdu(byte, payload);
	Payload testPushPayload = pdu.getFullData();
	Payload actualPushPayload = {static_cast<BYTE>(ProtocolType::PDCP)};
	EXPECT_EQ(actualPushPayload, testPushPayload);

	Payload testPopPayload = pdu.getPayload();
	Payload actualPopPayload;
	EXPECT_EQ(actualPopPayload, testPopPayload);
}

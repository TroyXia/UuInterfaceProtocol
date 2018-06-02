#include "../include/ProtocolType.h"
#include "../include/Protocol.h"
#include "../include/Interface.h"
#include <gtest/gtest.h>

TEST(InterfaceTest, test_UuInterface)
{
	Payload userData1 = {1};
	shared_ptr<Interface> uuInterface1 = make_shared<UuInterface>();

	PDU pduTest1 = uuInterface1->sendData(userData1);
	Payload encodeData1 = pduTest1.getFullData();
	Payload actualEncodeData1 = {1, 2, 3, 4, 1};
	EXPECT_EQ(actualEncodeData1, encodeData1);

	Payload decodeData1 = uuInterface1->receiveData(pduTest1);
	Payload actualDecodeData1 = {1};
	EXPECT_EQ(actualDecodeData1, decodeData1);

	Payload userData2 = {5, 6, 7, 8};
	shared_ptr<Interface> uuInterface2 = make_shared<UuInterface>();
	PDU pduTest2 = uuInterface2->sendData(userData2);
	Payload encodeData2 = pduTest2.getFullData();
	Payload actualEncodeData2 = {1, 2, 3, 4, 5, 6, 7, 8};
	EXPECT_EQ(actualEncodeData2, encodeData2);

	Payload decodeData2 = uuInterface2->receiveData(pduTest2);
	Payload actualDecodeData2 = {5, 6, 7, 8};
	EXPECT_EQ(actualDecodeData2, decodeData2);
}
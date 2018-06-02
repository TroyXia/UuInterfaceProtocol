#include "../include/ProtocolType.h"
#include "../include/Protocol.h"

PDU Protocol::encodeCommand(Payload &payload)
{
	BYTE byte = static_cast<BYTE>(getType());
	PDU pdu(byte, payload);

	return pdu;
}

Payload Protocol::decodeCommand(PDU &pdu)
{
	catchExcept(pdu);

	Payload payload = pdu.getPayload();
	return payload;
}

void Protocol::catchExcept(PDU &pdu)
{
	try
	{
		BYTE byte = static_cast<BYTE>(getType());
		if(pdu.throwHeader() != byte)
			throw runtime_error("wrong head");
	}
	catch(runtime_error err)
	{
		cout << "The exception is because of = " << err.what() << endl;
	}
}

ProtocolType PDCP::getType()
{
	return ProtocolType::PDCP;
}

ProtocolType RLC::getType()
{
	return ProtocolType::RLC;
}

ProtocolType MAC::getType()
{
	return ProtocolType::MAC;
}

ProtocolType PHY::getType()
{
	return ProtocolType::PHY;
}

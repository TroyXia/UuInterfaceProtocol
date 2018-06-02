#include "../include/ProtocolType.h"
#include "../include/Protocol.h"
#include "../include/Interface.h"

PDU Interface::sendData(Payload &userData)
{
	Payload &payload = userData;
	PDU pdu;

	addProtocolStack();

	for(auto it = protocolStack.begin(); it != protocolStack.end(); ++it)
	{
		pdu = (*it)->encodeCommand(payload);
	}

	return pdu;
}

void Interface::addProtocolStack()
{
	shared_ptr<Protocol> pdcp = make_shared<PDCP>();
	protocolStack.push_back(pdcp);

	shared_ptr<Protocol> rlc = make_shared<RLC>();
	protocolStack.push_back(rlc);

	shared_ptr<Protocol> mac = make_shared<MAC>();
	protocolStack.push_back(mac);

	shared_ptr<Protocol> phy = make_shared<PHY>();
	protocolStack.push_back(phy);
}

Payload Interface::receiveData(PDU &pdu)
{
	Payload payload;
	for(auto it = protocolStack.end()-1; it != protocolStack.begin()-1; --it)
	{
		payload = (*it)->decodeCommand(pdu);
	}

	return payload;
}

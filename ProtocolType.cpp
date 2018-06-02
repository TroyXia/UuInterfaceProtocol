#include "../include/ProtocolType.h"

PDU::PDU(BYTE byte, Payload &payload)
{
	payload.insert(payload.begin(), byte);
	data = payload;
}

Payload PDU::getPayload()
{
	data.erase(data.begin());
	return data;
}

void PDU::test() const
{
	for(auto it = data.begin(); it != data.end(); ++it)
		cout << (*it) << " ";
	cout << endl;
}

Payload PDU::getFullData() const
{
	return data;
}

BYTE PDU::throwHeader()
{
	auto it = data.begin();
	return *it;
}

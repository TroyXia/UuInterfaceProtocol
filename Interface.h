#pragma once
#include "../include/ProtocolType.h"
#include "../include/Protocol.h"

using SharedPtrType = shared_ptr<Protocol>;

class Interface
{
public:
	PDU sendData(Payload &userData);
	void addProtocolStack();

	Payload receiveData(PDU &pdu);
protected:
	vector<SharedPtrType> protocolStack;
};

class UuInterface: public Interface
{
public:
	UuInterface() = default;
	~UuInterface() = default;
};

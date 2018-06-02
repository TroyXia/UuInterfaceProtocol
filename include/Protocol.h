#pragma once
#include "ProtocolType.h"
#include <stdexcept>
using std::runtime_error;

class Protocol
{
public:
	Protocol() = default;
	virtual ~Protocol() = default;
	PDU encodeCommand(Payload &payload);
	Payload decodeCommand(PDU &pdu);
	void catchExcept(PDU &pdu);

	virtual ProtocolType getType() = 0;
};

class PDCP: public Protocol
{
public:
	PDCP() = default;
	virtual ~PDCP() = default;
	virtual ProtocolType getType() override;
};

class RLC: public Protocol
{
public:
	RLC() = default;
	virtual ~RLC() = default;
	virtual ProtocolType getType() override;
};

class MAC: public Protocol
{
public:
	MAC() = default;
	virtual ~MAC() = default;
	virtual ProtocolType getType() override;
};

class PHY: public Protocol
{
public:
	PHY() = default;
	virtual ~PHY() = default;
	virtual ProtocolType getType() override;
};

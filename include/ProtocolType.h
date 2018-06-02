#pragma once

#include <iostream>
#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

using BYTE = unsigned int;
using Payload = vector<BYTE>;

enum class ProtocolType {PHY=1, MAC=2, RLC=3, PDCP=4};

class PDU
{
public:
	PDU() = default;
	PDU(Payload &payload):data(payload) {}
	PDU(BYTE byte, Payload &payload);
	Payload getPayload();
	BYTE throwHeader();
	Payload getFullData() const;

	void test() const;
protected:
	Payload data;
};

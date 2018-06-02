#include "../include/ProtocolType.h"
#include "../include/Protocol.h"
#include "../include/Interface.h"

int main()
{
	Payload userData = {1, 2, 3, 4, 5};
	shared_ptr<Interface> uuInterface = make_shared<UuInterface>();
	PDU pdu = uuInterface->sendData(userData);
	pdu.test();

	Payload payload = uuInterface->receiveData(pdu);
	for(auto it = payload.begin(); it != payload.end(); ++it)
	{
		cout << *it << " ";
	}

	return 0;
}

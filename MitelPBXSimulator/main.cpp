#include "stdafx.h"

using namespace OAI_Networking;

int main() {
	// Initialise the incoming connections listening thread
	std::thread m_Running(start);

	// Let this process run indefinately
	for (;;) {
		// Iterations 1 every day to ensure minimal CPU usage
		std::this_thread::sleep_for(std::chrono::hours(24));

		// TODO: TERMINATION CLAUSE
	}

	// TODO: TERMINATE ALL THREADS

	return 0;
}

void start()
{
	// Boot up the server
	Server instance;
	
	// Hope all works >.<
	if (Server::CONNECT_SUCCESSFUL == instance.Connect())
	{
		instance.Run();
	}
}

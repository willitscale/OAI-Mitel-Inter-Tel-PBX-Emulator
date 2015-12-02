#include "stdafx.h"

int main() {

	// Boot up the server
	new OAI_Networking::Server();

	// Let this process run indefinately
	for (;;) {
		// Iterations 1 every day to ensure minimal CPU usage
		std::this_thread::sleep_for(std::chrono::hours(24));

		// TODO: TERMINATION CLAUSE
	}

	// TODO: TERMINATE ALL THREADS

	return 0;
}
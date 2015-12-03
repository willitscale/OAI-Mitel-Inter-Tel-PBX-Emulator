#include "stdafx.h"

namespace OAI_Networking
{
	Server::Server()
	{
	}

	Server::~Server()
	{

	}

	int Server::InitWSA()
	{
		// Windows Sockets API cheese
#ifdef _WIN32
		WSADATA wsaData;
		return WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
		// No issues
		return 0;
	}

	int Server::InitSocket()
	{
		// Initialise an socket stream over TCP/IPv4
		// consider AF_INET6 + IPPROTO_ICMPV6
		return (this->m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
	}

	int Server::InitNonBlocking()
	{
		// set this son bitch non-blocking
		return ioctlsocket(this->m_Socket, FIONBIO, &this->m_Mode);
	}

	int Server::InitBind()
	{
		// Initialise the listening server address struct
		bzero((char *)&this->m_Server, sizeof(this->m_Server));
		this->m_Server.sin_family = AF_INET;
		// Don't limit the incoming connections by IP/Host
		this->m_Server.sin_addr.s_addr = INADDR_ANY;
		this->m_Server.sin_port = htons(this->m_Port);

		// Bind Failed
		return bind(this->m_Socket, (struct sockaddr *)
			&this->m_Server, sizeof(this->m_Server));
	}

	int Server::InitListen()
	{
		// Let's start listening with a maximum of 5 pending connections
		return listen(this->m_Socket, this->m_Pending);
	}

	int Server::Connect()
	{
		if (0 != this->InitWSA()) {
			this->Error("InitWSA");
			return INIT_WSA_ERROR;
		}

		if (0 > this->InitSocket()) {
			this->Error("InitSocket");
			return INIT_SOCKET_ERROR;
		}

		if (0 != this->InitNonBlocking()) {
			this->Error("InitNonBlocking");
			return INIT_NON_BLOCKING_ERROR;
		}

		if (0 != this->InitBind()) {
			this->Error("InitBind");
			return INIT_BIND_ERROR;
		}

		if (0 != this->InitListen()) {
			this->Error("InitListen");
			return INIT_LISTEN_ERROR;
		}

		return CONNECT_SUCCESSFUL;
	}

	void Server::Run()
	{
		int client;
		struct sockaddr_in clientAddr;

		int clientLength = sizeof(clientAddr);

		for (;;){

			OAI_Common::Console("Waiting for connection");

			client = accept(this->m_Socket, (struct sockaddr *)
				&clientAddr, &clientLength);

			if (0 > client) {
				this->Error("accept");
			} else {
				std::thread cli(&Server::Accepted, client);
				cli.detach();
			}
		}

		x__close(this->m_Socket);
	}

	void Server::Accepted(int client)
	{
		Client cli(client);
	}

	void Server::Error(std::string error)
	{

#ifdef _WIN32
		error += ": " + std::to_string(WSAGetLastError());
#endif

		OAI_Common::Console(error);
	}
}